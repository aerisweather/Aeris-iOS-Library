//
//  ForecastViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/28/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "ForecastViewController.h"

@interface ForecastViewController () <UITableViewDataSource>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) AWFForecasts *forecasts;
@property (nonatomic, strong) NSArray *periods;
@property (nonatomic, strong) ListingEventView *eventView;
@end

static NSString *forecastCellIdentifier = @"ForecastCell";

@implementation ForecastViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.forecasts = [[AWFForecasts alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	UITableView *tableView = [UITableView new];
	tableView.translatesAutoresizingMaskIntoConstraints = NO;
	tableView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	tableView.dataSource = self;
	tableView.rowHeight = 60.0;
	tableView.separatorInset = UIEdgeInsetsZero;
	tableView.allowsSelection = NO;
	[tableView registerClass:[AWFTableViewForecastRowCell class] forCellReuseIdentifier:forecastCellIdentifier];
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
	self.tableView.backgroundColor = style.viewControllerBackgroundColor;
	
	self.eventView.backgroundColor = style.viewControllerBackgroundColor;
	self.eventView.messageLabel.textColor = style.defaultTextStyle.textColor;
	self.eventView.detailedMessageLabel.textColor = style.detailTextStyle.textColor;
	
	[self.tableView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	__weak typeof(self) weakSelf = self;
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	// load forecast
	AWFWeatherRequestOptions *forecastOptions = [[AWFWeatherRequestOptions alloc] init];
	forecastOptions.limit = 15;
	
	// only show loader if we haven't already populated the view once
	if ([self.periods count] == 0) {
		[self.eventView showLoading];
	}
	
	[self.forecasts getForPlace:place options:forecastOptions completion:^(AWFWeatherEndpointResult * _Nullable result) {
		if (result.error) {
			[self.eventView showMessage:NSLocalizedString(@"An error occurred while requesting the weather data.", nil)];
			NSLog(@"Forecast data failed to load! %@", result.error.localizedDescription);
			return;
		}
		
		[self.eventView hide];
		
		NSArray *objects = result.results;
		if ([objects count] > 0) {
			AWFForecast *forecast = (AWFForecast *)[objects objectAtIndex:0];
			weakSelf.periods = forecast.periods;
			[weakSelf.tableView reloadData];
		}
	}];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInCollectionView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return [self.periods count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:forecastCellIdentifier];
	
	if ([cell isKindOfClass:[AWFTableViewForecastRowCell class]]) {
		AWFTableViewForecastRowCell *forecastCell = (AWFTableViewForecastRowCell *)cell;
		[forecastCell applyStyle:[[Preferences sharedInstance] preferredStyle]];
		
		AWFForecastPeriod *period = (AWFForecastPeriod *)[self.periods objectAtIndex:indexPath.row];
		forecastCell.hightemp = [NSString stringWithFormat:@"%.0f", period.maxTempF];
		forecastCell.lowtemp = [NSString stringWithFormat:@"%.0f", period.minTempF];
		forecastCell.weather = period.weatherFull;
		forecastCell.icon = [UIImage imageNamed:period.icon];
		forecastCell.day = [period.timestamp awf_formattedDateWithFormat:@"eee" timeZone:period.timeZone];
		forecastCell.date = [period.timestamp awf_formattedDateWithFormat:@"MMM d" timeZone:period.timeZone];
	}
	
	return cell;
}

@end
