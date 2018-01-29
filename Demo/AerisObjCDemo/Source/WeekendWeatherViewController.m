//
//  WeekendWeatherViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "WeekendWeatherViewController.h"

@interface WeekendWeatherViewController () <UITableViewDataSource>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) AWFForecasts *forecasts;
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
        self.forecasts = [[AWFForecasts alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	
	UITableView *tableView = [UITableView new];
	tableView.translatesAutoresizingMaskIntoConstraints = NO;
	tableView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	tableView.dataSource = self;
	tableView.estimatedRowHeight = cellHeight;
	tableView.separatorColor = [UIColor clearColor];
	tableView.separatorInset = UIEdgeInsetsZero;
	tableView.allowsSelection = NO;
	[tableView registerClass:[AWFTableViewForecast24HourCell class] forCellReuseIdentifier:forecastCellIdentifier];
	[self.view addSubview:tableView];
	self.tableView = tableView;
	
	ListingEventView *eventView = [ListingEventView new];
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
	
	if ([self.periods count] == 0) {
		[self.eventView showLoading];
	}
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	//[TestFlight passCheckpoint:TFCheckpointWeekend];
	
	__weak typeof(self) weakSelf = self;
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	NSDate *now = [NSDate date];
	
	// load forecast
	AWFWeatherRequestOptions *forecastOptions = [[AWFWeatherRequestOptions alloc] init];
	forecastOptions.limit = 6;
	forecastOptions.filterString = @"daynight";
	forecastOptions.fromDateString = @"friday";
	forecastOptions.toDateString = @"+3 days";
	
	if (now.awf_weekday >= 6) {
		forecastOptions.fromDateString = @"today";
		forecastOptions.toDateString = @"midnight monday";
	}
	
	[self.forecasts getForPlace:place options:forecastOptions completion:^(AWFWeatherEndpointResult * _Nullable result) {
		if (result.error) {
			[self.eventView showMessage:NSLocalizedString(@"An error occurred while requesting the weather data.", nil)];
			NSLog(@"Forecast data failed to load! %@", result.error);
			return;
		}
		
		[self.eventView hide];
		
		NSArray *objects = result.results;
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
				if (period.timestamp.awf_weekday == 6) {
					dayKey = @"fri";
				} else if (period.timestamp.awf_weekday == 7) {
					dayKey = @"sat";
				} else if (period.timestamp.awf_weekday == 1) {
					dayKey = @"sun";
				}
				
				if (dayKey) {
					NSMutableDictionary *dayPeriods = [[periodsByDay objectForKey:dayKey] mutableCopy];
					[dayPeriods setObject:period forKey:daynightKey];
					[periodsByDay setValue:dayPeriods forKey:dayKey];
				}
			}];
			
			weakSelf.periods = periodsByDay;
			[weakSelf.tableView reloadData];
		}
	}];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 3;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:forecastCellIdentifier];
	
	if ([cell isKindOfClass:[AWFTableViewForecast24HourCell class]]) {
		AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
		AWFTableViewForecast24HourCell *forecastCell = (AWFTableViewForecast24HourCell *)cell;
		[forecastCell applyStyle:style];
		forecastCell.backgroundColor = style.backgroundColor;
		forecastCell.contentView.layoutMargins = UIEdgeInsetsMake(8.0, 8.0, 8.0, 8.0);
		
		// determine day key for loaded forecast periods
		NSString *dayKey = @"fri";
		if (indexPath.row == 1) dayKey = @"sat";
		else if (indexPath.row == 2) dayKey = @"sun";
		
		if ([self.periods objectForKey:dayKey]) {
			NSDictionary *periods = [self.periods objectForKey:dayKey];
			
			if ([periods objectForKey:@"day"]) {
				AWFForecastPeriod *dayPeriod = (AWFForecastPeriod *)[periods objectForKey:@"day"];
				forecastCell.periodLabel.text = [dayPeriod.timestamp awf_formattedDateWithFormat:@"eeee" timeZone:dayPeriod.timeZone];
				forecastCell.dateLabel.text = [dayPeriod.timestamp awf_formattedDateWithFormat:@"MMM d" timeZone:dayPeriod.timeZone];
				
				[self updateForecastView:forecastCell.firstPeriodView withPeriod:dayPeriod];
			}
			
			if ([periods objectForKey:@"night"]) {
				AWFForecastPeriod *nightPeriod = (AWFForecastPeriod *)[periods objectForKey:@"night"];
				forecastCell.periodLabel.text = [nightPeriod.timestamp awf_formattedDateWithFormat:@"eeee" timeZone:nightPeriod.timeZone];
				forecastCell.dateLabel.text = [nightPeriod.timestamp awf_formattedDateWithFormat:@"MMM d" timeZone:nightPeriod.timeZone];
				
				[self updateForecastView:forecastCell.secondPeriodView withPeriod:nightPeriod];
			}
		}
		[forecastCell setNeedsLayout];
	}
	
	return cell;
}

#pragma mark - Private

- (void)updateForecastView:(AWFForecastDetailView *)forecastView withPeriod:(AWFForecastPeriod *)period {
	CGFloat temp = (period.isDay) ? period.maxTempF : period.minTempF;
		
	forecastView.tempTextLabel.text = [NSString stringWithFormat:@"%.0f", temp];
	forecastView.weatherTextLabel.text = period.weather;
	forecastView.iconImageView.image = [UIImage imageNamed:period.icon];
	forecastView.windsTextLabel.text = [NSString stringWithFormat:@"%@ %.0f mph", period.windDirection, period.windSpeedMPH];
	
	// show snow instead of precip if predicted
	if ([[period.weather lowercaseString] rangeOfString:@"snow"].location != NSNotFound) {
		forecastView.precipTypeTextLabel.text = NSLocalizedString(@"Snow", nil);
		forecastView.precipTextLabel.text = [NSString stringWithFormat:@"%.2f in", period.snowIN];
	} else {
		forecastView.precipTypeTextLabel.text = NSLocalizedString(@"Precip", nil);
		forecastView.precipTextLabel.text = [NSString stringWithFormat:@"%.2f in", period.precipIN];
	}
}

@end
