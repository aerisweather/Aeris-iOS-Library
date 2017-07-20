//
//  DailySummariesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "DailySummariesViewController.h"
#import "ListingEventView.h"

@interface DailySummariesViewController ()
@property (nonatomic, strong) UICollectionView *collectionView;
@property (nonatomic, strong) AWFObservationsLoader *obsLoader;
@property (nonatomic, strong) AWFObservationSummary *summary;
@property (nonatomic, strong) ListingEventView *eventView;
@end

static NSString *obsCellIdentifier = @"ObsCellIdentifier";
static CGFloat cellHeight = 217.0f;

@implementation DailySummariesViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.obsLoader = [[AWFObservationsLoader alloc] init];
	}

	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];

	UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
	layout.scrollDirection = UICollectionViewScrollDirectionVertical;
	layout.minimumInteritemSpacing = 0;
	layout.minimumLineSpacing = 0;
	layout.itemSize = CGSizeMake(CGRectGetWidth(self.view.bounds), cellHeight);

	UICollectionView *collectionView = [[UICollectionView alloc] initWithFrame:self.view.bounds collectionViewLayout:layout];
	collectionView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	collectionView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
	collectionView.dataSource = self;
	collectionView.delegate = self;
	[self.view addSubview:collectionView];
	self.collectionView = collectionView;

	// register the appropriate forecast view to use for our hourly forecast collection view cells
	[collectionView registerClass:[AWFCollectionViewDailySummaryCell class] forCellWithReuseIdentifier:obsCellIdentifier];

	ListingEventView *eventView = [[ListingEventView alloc] initWithFrame:self.view.bounds];
	eventView.alpha = 0;
	[self.view addSubview:eventView];
	self.eventView = eventView;
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];

	// refresh styles if it's different than the user's preference
	AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
	self.view.backgroundColor = style.viewControllerBackgroundColor;
	self.collectionView.backgroundColor = style.viewControllerBackgroundColor;

	self.eventView.backgroundColor = style.viewControllerBackgroundColor;
	self.eventView.messageLabel.textColor = style.defaultTextStyle.textColor;
	self.eventView.detailedMessageLabel.textColor = style.detailTextStyle.textColor;

	[self.collectionView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];

	[self loadDataForDefaultPlace];
}

- (void)viewWillLayoutSubviews {
	[super viewWillLayoutSubviews];

	((UICollectionViewFlowLayout *)self.collectionView.collectionViewLayout).itemSize = CGSizeMake(CGRectGetWidth(self.view.bounds), cellHeight);
	[self.collectionView.collectionViewLayout invalidateLayout];
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
	return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
	return [self.summary.periods count];
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:obsCellIdentifier forIndexPath:indexPath];

	if ([cell isKindOfClass:[AWFCollectionViewDailySummaryCell class]]) {
		AWFCollectionViewDailySummaryCell *summaryCell = (AWFCollectionViewDailySummaryCell *)cell;
		[summaryCell.weatherView applyStyle:[[Preferences sharedInstance] preferredStyle]];

		AWFObservationSummaryPeriod *period = (AWFObservationSummaryPeriod *)self.summary.periods[indexPath.row];

		[NSDate awf_setDefaultTimezone:self.summary.place.timeZone];

		NSString *dateFormat = [NSString stringWithFormat:@"%@, %@ %@", AWFDateFormatDayName, AWFDateFormatMonthName, AWFDateFormatDate];
		summaryCell.weatherView.headerView.textLabel.text = [period.timestamp awf_stringWithFormat:dateFormat];

		summaryCell.weatherView.weatherTextLabel.text = [period.weather capitalizedString];
		summaryCell.weatherView.iconImageView.image = [AWFImage weatherIconNamed:period.icon];
		summaryCell.weatherView.hightempLabel.text = [NSString stringWithFormat:@"%i", [period.maxTempF intValue]];
		summaryCell.weatherView.lowtempLabel.text = [NSString stringWithFormat:@"%i", [period.minTempF intValue]];

		[summaryCell.weatherView setMinValue:[NSString stringWithFormat:@"%.0fmph", [period.minWindSpeedMPH floatValue]] forWeatherType:AWFWeatherDataTypeWindSpeed];
		[summaryCell.weatherView setMaxValue:[NSString stringWithFormat:@"%.0fmph", [period.maxWindSpeedMPH floatValue]] forWeatherType:AWFWeatherDataTypeWindSpeed];
		[summaryCell.weatherView setAverageValue:[NSString stringWithFormat:@"%.0fmph", [period.avgWindSpeedMPH floatValue]] forWeatherType:AWFWeatherDataTypeWindSpeed];

		[summaryCell.weatherView setMinValue:[NSString stringWithFormat:@"%.0f%%", [period.minHumidity floatValue]] forWeatherType:AWFWeatherDataTypeHumidity];
		[summaryCell.weatherView setMaxValue:[NSString stringWithFormat:@"%.0f%%", [period.maxHumidity floatValue]] forWeatherType:AWFWeatherDataTypeHumidity];
		[summaryCell.weatherView setAverageValue:[NSString stringWithFormat:@"%.0f%%", [period.avgHumidity floatValue]] forWeatherType:AWFWeatherDataTypeHumidity];

		[summaryCell.weatherView setMinValue:[NSString stringWithFormat:@"%.0f%@", [period.minDewpointF floatValue], AWFDegree] forWeatherType:AWFWeatherDataTypeDewPoint];
		[summaryCell.weatherView setMaxValue:[NSString stringWithFormat:@"%.0f%@", [period.maxDewpointF floatValue], AWFDegree] forWeatherType:AWFWeatherDataTypeDewPoint];
		[summaryCell.weatherView setAverageValue:[NSString stringWithFormat:@"%.0f%@", [period.avgDewpointF floatValue], AWFDegree] forWeatherType:AWFWeatherDataTypeDewPoint];

		[summaryCell.weatherView setMinValue:[NSString stringWithFormat:@"%.2fin", [period.minPressureIN floatValue]] forWeatherType:AWFWeatherDataTypePressure];
		[summaryCell.weatherView setMaxValue:[NSString stringWithFormat:@"%.2fin", [period.maxPressureIN floatValue]] forWeatherType:AWFWeatherDataTypePressure];
		[summaryCell.weatherView setAverageValue:[NSString stringWithFormat:@"%.2fin", [period.avgPressureIN floatValue]] forWeatherType:AWFWeatherDataTypePressure];

		[summaryCell.weatherView setMinValue:[NSString stringWithFormat:@"%.0f%%", [period.minSkyCoverPercentage floatValue]] forWeatherType:AWFWeatherDataTypeSkyCover];
		[summaryCell.weatherView setMaxValue:[NSString stringWithFormat:@"%.0f%%", [period.maxSkyCoverPercentage floatValue]] forWeatherType:AWFWeatherDataTypeSkyCover];
		[summaryCell.weatherView setAverageValue:[NSString stringWithFormat:@"%.0f%%", [period.avgSkyCoverPercentage floatValue]] forWeatherType:AWFWeatherDataTypeSkyCover];

		[summaryCell setNeedsLayout];
	}

	return cell;
}

#pragma mark - Private Methods

- (void)loadDataForDefaultPlace {
	__weak typeof(self) weakSelf = self;

	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];

	// load forecast
	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.periodLimit = 7;
	options.periodSort = [NSString stringWithFormat:@"dt:%li", (long)AWFRequestSortDescending];

	// only show loader if we haven't already populated the view once
	if (self.summary) {
		[self.eventView showLoading];
	}

	NSDate *fromDate = [[NSDate date] awf_dateByAddingDays:-7 ignoringTime:YES];
	[self.obsLoader getObservationSummaryForPlace:place fromDate:fromDate toDate:nil options:options completion:^(NSArray *objects, NSError *error) {
	    if (error) {
	        [self.eventView showMessage:NSLocalizedString(@"An error occurred while requesting the weather data.", nil)];
	        NSLog(@"Daily summaries failed to load! %@", error.localizedDescription);

	        return;
		}

	    [self.eventView hide];

	    if ([objects count] > 0) {
	        weakSelf.summary = objects[0];
	        [weakSelf.collectionView reloadData];
		}
	}];
}

@end
