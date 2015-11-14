//
//  WeekendWeatherViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "WeekendWeatherViewController.h"
#import "ListingEventView.h"

@interface WeekendWeatherViewController ()
@property (nonatomic, strong) UICollectionView *collectionView;
@property (nonatomic, strong) AWFForecastsLoader *forecastsLoader;
@property (nonatomic, strong) NSDictionary *periods;
@property (nonatomic, strong) ListingEventView *eventView;
- (void)updateForecastView:(AWFForecastDetailView *)forecastView withPeriod:(AWFForecastPeriod *)period;
@end

static NSString *forecastCellIdentifier = @"WeekendCellIdentifier";
static CGFloat cellHeight = 139.0f;

@implementation WeekendWeatherViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.forecastsLoader = [[AWFForecastsLoader alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	
	UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
	layout.scrollDirection = UICollectionViewScrollDirectionVertical;
	layout.minimumInteritemSpacing = 0;
	layout.minimumLineSpacing = 0;
	layout.itemSize = CGSizeMake(CGRectGetWidth(self.view.frame), 139.0);
	
	UICollectionView *collectionView = [[UICollectionView alloc] initWithFrame:self.view.bounds collectionViewLayout:layout];
	collectionView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	collectionView.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
	collectionView.dataSource = self;
	collectionView.delegate = self;
	[self.view addSubview:collectionView];
	self.collectionView = collectionView;
	
	// register the appropriate forecast view to use for our hourly forecast collection view cells
	[collectionView registerClass:[AWFCollectionViewForecast24HourCell class] forCellWithReuseIdentifier:forecastCellIdentifier];
	
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
	
	if ([self.periods count] == 0) {
		[self.eventView showLoading];
	}
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	__weak typeof(self) weakSelf = self;
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	NSDate *now = [NSDate date];
	
	// load forecast
	AWFRequestOptions *forecastOptions = [[AWFRequestOptions alloc] init];
	forecastOptions.limit = 6;
	forecastOptions.filterString = @"daynight";
	forecastOptions.fromDateString = @"friday";
	forecastOptions.toDateString = @"+3 days";
	
	if (now.weekday >= 6) {
		forecastOptions.fromDateString = @"today";
		forecastOptions.toDateString = @"midnight monday";
	}
	
	[self.forecastsLoader getForecastForPlace:place options:forecastOptions completion:^(NSArray *objects, NSError *error) {
		if (error) {
			[self.eventView showMessage:NSLocalizedString(@"An error occurred while requesting the weather data.", nil)];
			NSLog(@"Forecast data failed to load! %@", error);
			return;
		}
		
		[self.eventView hide];
		
		if ([objects count] > 0) {
			AWFForecast *forecast = (AWFForecast *)[objects objectAtIndex:0];
			NSArray *periods = forecast.periods;
			
			// pair up the day/night periods with their day for the collection view
			NSMutableDictionary *periodsByDay = [[NSMutableDictionary alloc] initWithCapacity:3];
			[periodsByDay setValue:@{} forKeyPath:@"fri"];
			[periodsByDay setValue:@{} forKeyPath:@"sat"];
			[periodsByDay setValue:@{} forKeyPath:@"sun"];
			
			[periods enumerateObjectsUsingBlock:^(AWFForecastPeriod *period, NSUInteger idx, BOOL *stop) {
				NSString *daynightKey = (period.isDay) ? @"day" : @"night";
				NSString *dayKey;
				if (period.timestamp.weekday == 6) {
					dayKey = @"fri";
				}
				else if (period.timestamp.weekday == 7) {
					dayKey = @"sat";
				}
				else if (period.timestamp.weekday == 1) {
					dayKey = @"sun";
				}
				
				if (dayKey) {
					NSMutableDictionary *dayPeriods = [[periodsByDay objectForKey:dayKey] mutableCopy];
					[dayPeriods setObject:period forKey:daynightKey];
					[periodsByDay setValue:dayPeriods forKey:dayKey];
				}
			}];
			
			weakSelf.periods = periodsByDay;
			[weakSelf.collectionView reloadData];
		}
	}];
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
	return 3;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:forecastCellIdentifier forIndexPath:indexPath];
	
	if ([cell isKindOfClass:[AWFCollectionViewForecast24HourCell class]]) {
		AWFCollectionViewForecast24HourCell *forecastCell = (AWFCollectionViewForecast24HourCell *)cell;
		[forecastCell.weatherView applyStyle:[[Preferences sharedInstance] preferredStyle]];
		
		// determine day key for loaded forecast periods
		NSString *dayKey = @"fri";
		if (indexPath.row == 1) dayKey = @"sat";
		else if (indexPath.row == 2) dayKey = @"sun";
		
		if ([self.periods objectForKey:dayKey]) {
			NSDictionary *periods = [self.periods objectForKey:dayKey];
			if ([periods objectForKey:@"day"]) {
				AWFForecastPeriod *dayPeriod = (AWFForecastPeriod *)[periods objectForKey:@"day"];
				forecastCell.weatherView.periodLabel.text = [dayPeriod.timestamp awf_stringWithFormat:@"eeee"];
				forecastCell.weatherView.dateLabel.text = [dayPeriod.timestamp awf_stringWithFormat:@"MMM d"];
				
				[self updateForecastView:forecastCell.weatherView.firstPeriodView withPeriod:dayPeriod];
			}
			if ([periods objectForKey:@"night"]) {
				AWFForecastPeriod *nightPeriod = (AWFForecastPeriod *)[periods objectForKey:@"night"];
				forecastCell.weatherView.periodLabel.text = [nightPeriod.timestamp awf_stringWithFormat:@"eeee"];
				forecastCell.weatherView.dateLabel.text = [nightPeriod.timestamp awf_stringWithFormat:@"MMM d"];
				
				[self updateForecastView:forecastCell.weatherView.secondPeriodView withPeriod:nightPeriod];
			}
		}
		[forecastCell setNeedsLayout];
	}
	
	return cell;
}

#pragma mark - Private

- (void)updateForecastView:(AWFForecastDetailView *)forecastView withPeriod:(AWFForecastPeriod *)period {
	NSNumber *temp = (period.isDay) ? period.maxTempF : period.minTempF;
		
	forecastView.tempTextLabel.text = [NSString stringWithFormat:@"%li", (long)[temp integerValue]];
	forecastView.weatherTextLabel.text = period.weather;
	forecastView.iconImageView.image = [AWFImage weatherIconNamed:period.icon];
	forecastView.windsTextLabel.text = [NSString stringWithFormat:@"%@ %li mph", period.windDirection, (long)[period.windSpeedMPH integerValue]];
	
	// show snow instead of precip if predicted
	if ([[period.weather lowercaseString] rangeOfString:@"snow"].location != NSNotFound) {
		forecastView.precipTypeTextLabel.text = NSLocalizedString(@"Snow", nil);
		forecastView.precipTextLabel.text = [NSString stringWithFormat:@"%.2f in", [period.snowIN floatValue]];
	}
	else {
		forecastView.precipTypeTextLabel.text = NSLocalizedString(@"Precip", nil);
		forecastView.precipTextLabel.text = [NSString stringWithFormat:@"%.2f in", [period.precipIN floatValue]];
	}
}

@end
