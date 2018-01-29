//
//  DailySummariesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "DailySummariesViewController.h"

@interface DailySummariesViewController () <UITableViewDataSource>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) AWFObservationsSummaries *obs;
@property (nonatomic, strong) AWFObservationSummary *summary;
@property (nonatomic, strong) ListingEventView *eventView;
@end

static NSString *obsCellIdentifier = @"ObsCellIdentifier";
static CGFloat cellHeight = 222.0f;

@implementation DailySummariesViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.obs = [AWFObservationsSummaries new];
	}
	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];

	UICollectionViewFlowLayout *layout = [UICollectionViewFlowLayout new];
	layout.scrollDirection = UICollectionViewScrollDirectionVertical;
	layout.minimumInteritemSpacing = 0;
	layout.minimumLineSpacing = 0;
	layout.itemSize = CGSizeMake(CGRectGetWidth(self.view.bounds), cellHeight);

	UITableView *tableView = [UITableView new];
	tableView.translatesAutoresizingMaskIntoConstraints = NO;
	tableView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	tableView.rowHeight = cellHeight;
	tableView.separatorInset = UIEdgeInsetsZero;
	tableView.allowsSelection = NO;
	tableView.dataSource = self;
	[tableView registerClass:[AWFTableViewDailySummaryCell class] forCellReuseIdentifier:obsCellIdentifier];
	[self.view addSubview:tableView];
	self.tableView = tableView;

	ListingEventView *eventView = [[ListingEventView alloc] initWithFrame:self.view.bounds];
	eventView.translatesAutoresizingMaskIntoConstraints = NO;
	eventView.alpha = 0;
	[self.view addSubview:eventView];
	self.eventView = eventView;
	
	[NSLayoutConstraint activateConstraints:@[[tableView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
											  [tableView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [tableView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [tableView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
											  [eventView.topAnchor constraintEqualToAnchor:tableView.topAnchor],
											  [eventView.leftAnchor constraintEqualToAnchor:tableView.leftAnchor],
											  [eventView.rightAnchor constraintEqualToAnchor:tableView.rightAnchor],
											  [eventView.bottomAnchor constraintEqualToAnchor:tableView.bottomAnchor]]];
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];

	// refresh styles if it's different than the user's preference
	AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
	self.view.backgroundColor = style.viewControllerBackgroundColor;
	self.tableView.backgroundColor = style.viewControllerBackgroundColor;

	self.eventView.backgroundColor = style.viewControllerBackgroundColor;
	self.eventView.messageLabel.textColor = style.defaultTextStyle.textColor;
	self.eventView.detailedMessageLabel.textColor = style.detailTextStyle.textColor;

	[self.tableView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	[self loadDataForDefaultPlace];
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return [self.summary.periods count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:obsCellIdentifier];

	if ([cell isKindOfClass:[AWFTableViewDailySummaryCell class]]) {
		AWFTableViewDailySummaryCell *summaryCell = (AWFTableViewDailySummaryCell *)cell;
		[summaryCell.weatherView applyStyle:[[Preferences sharedInstance] preferredStyle]];

		AWFObservationSummaryPeriod *period = (AWFObservationSummaryPeriod *)self.summary.periods[indexPath.row];

		NSString *dateFormat = [NSString stringWithFormat:@"%@, %@ %@", AWFDateFormatDayName, AWFDateFormatMonthName, AWFDateFormatDate];
		summaryCell.weatherView.headerView.textLabel.text = [period.timestamp awf_formattedDateWithFormat:dateFormat timeZone:self.summary.place.timeZone];

		summaryCell.weatherView.weatherTextLabel.text = [period.weather capitalizedString];
		summaryCell.weatherView.iconImageView.image = [UIImage imageNamed:period.icon];
		summaryCell.weatherView.hightempLabel.text = [NSString stringWithFormat:@"%.0f", period.maxTempF];
		summaryCell.weatherView.lowtempLabel.text = [NSString stringWithFormat:@"%.0f", period.minTempF];

		[summaryCell.weatherView setMinValue:[NSString stringWithFormat:@"%.0fmph", period.minWindSpeedMPH] forWeatherType:AWFWeatherDataTypeWindSpeed];
		[summaryCell.weatherView setMaxValue:[NSString stringWithFormat:@"%.0fmph", period.maxWindSpeedMPH] forWeatherType:AWFWeatherDataTypeWindSpeed];
		[summaryCell.weatherView setAverageValue:[NSString stringWithFormat:@"%.0fmph", period.avgWindSpeedMPH] forWeatherType:AWFWeatherDataTypeWindSpeed];

		[summaryCell.weatherView setMinValue:[NSString stringWithFormat:@"%.0f%%", period.minHumidity] forWeatherType:AWFWeatherDataTypeHumidity];
		[summaryCell.weatherView setMaxValue:[NSString stringWithFormat:@"%.0f%%", period.maxHumidity] forWeatherType:AWFWeatherDataTypeHumidity];
		[summaryCell.weatherView setAverageValue:[NSString stringWithFormat:@"%.0f%%", period.avgHumidity] forWeatherType:AWFWeatherDataTypeHumidity];

		[summaryCell.weatherView setMinValue:[NSString stringWithFormat:@"%.0f%@", period.minDewpointF, AWFDegree] forWeatherType:AWFWeatherDataTypeDewPoint];
		[summaryCell.weatherView setMaxValue:[NSString stringWithFormat:@"%.0f%@", period.maxDewpointF, AWFDegree] forWeatherType:AWFWeatherDataTypeDewPoint];
		[summaryCell.weatherView setAverageValue:[NSString stringWithFormat:@"%.0f%@", period.avgDewpointF, AWFDegree] forWeatherType:AWFWeatherDataTypeDewPoint];

		[summaryCell.weatherView setMinValue:[NSString stringWithFormat:@"%.2fin", period.minPressureIN] forWeatherType:AWFWeatherDataTypePressure];
		[summaryCell.weatherView setMaxValue:[NSString stringWithFormat:@"%.2fin", period.maxPressureIN] forWeatherType:AWFWeatherDataTypePressure];
		[summaryCell.weatherView setAverageValue:[NSString stringWithFormat:@"%.2fin", period.avgPressureIN] forWeatherType:AWFWeatherDataTypePressure];

		[summaryCell.weatherView setMinValue:[NSString stringWithFormat:@"%.0f%%", period.minSkyCoverPercentage] forWeatherType:AWFWeatherDataTypeSkyCover];
		[summaryCell.weatherView setMaxValue:[NSString stringWithFormat:@"%.0f%%", period.maxSkyCoverPercentage] forWeatherType:AWFWeatherDataTypeSkyCover];
		[summaryCell.weatherView setAverageValue:[NSString stringWithFormat:@"%.0f%%", period.avgSkyCoverPercentage] forWeatherType:AWFWeatherDataTypeSkyCover];

		[summaryCell setNeedsLayout];
	}

	return cell;
}

#pragma mark - Private Methods

- (void)loadDataForDefaultPlace {
	__weak typeof(self) weakSelf = self;

	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];

	// load forecast
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.periodLimit = 7;
	options.periodSort = [NSString stringWithFormat:@"dt:%li", (long)AWFRequestSortDescending];

	// only show loader if we haven't already populated the view once
	if (self.summary) {
		[self.eventView showLoading];
	}

	NSDate *fromDate = [[NSDate date] awf_dateByIgnoringTime];
	fromDate = [fromDate awf_dateBySubtractingDays:7];
	
	[self.obs getForPlace:place fromDate:fromDate toDate:nil options:options completion:^(AWFWeatherEndpointResult * _Nullable result) {
	    if (result.error) {
	        [self.eventView showMessage:NSLocalizedString(@"An error occurred while requesting the weather data.", nil)];
	        NSLog(@"Daily summaries failed to load! %@", result.error.localizedDescription);
	        return;
		}

	    [self.eventView hide];

	    NSArray *objects = result.results;
		if ([objects count] > 0) {
	        weakSelf.summary = objects[0];
	        [weakSelf.tableView reloadData];
		}
	}];
}

@end
