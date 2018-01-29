//
//  DetailedWeatherViewController_iPad.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "DetailedWeatherViewController_iPad.h"
#import "LocationSearchViewController.h"
#import "CatalogViewController.h"

@interface DetailedWeatherViewController_iPad () <UITableViewDataSource>
@property (nonatomic, strong) AWFObservationView *obsView;
@property (nonatomic, strong) AWFObservationAdvisoriesView *advisoriesView;
@property (nonatomic, strong) UITableView *forecastTableView;
@property (nonatomic, strong) UILabel *locationTextLabel;
@property (nonatomic, strong) AWFObservations *obs;
@property (nonatomic, strong) AWFForecasts *forecasts;
@property (nonatomic, strong) AWFAdvisories *advisories;
@property (nonatomic, strong) NSArray *forecastPeriods;
@property (nonatomic, assign) BOOL hasSetItemSize;
@end

static NSString *forecastCellIdentifier = @"ForecastCellIdentifier";
static CGFloat cellHeight = 135.0f;

@implementation DetailedWeatherViewController_iPad

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // create object loaders
		self.obs = [[AWFObservations alloc] init];
		self.forecasts = [[AWFForecasts alloc] init];
		self.advisories = [[AWFAdvisories alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [[AWFCascadingStyle style].viewControllerBackgroundColor awf_adjustBrightness:1.2];
	
	if (self.splitViewController) {
		self.navigationItem.leftBarButtonItem = [self.splitViewController displayModeButtonItem];
		self.navigationItem.leftItemsSupplementBackButton = YES;
	}
	
	UILabel *locationLabel = [UILabel new];
	locationLabel.translatesAutoresizingMaskIntoConstraints = NO;
	locationLabel.minimumScaleFactor = 0.8;
	locationLabel.text = @"";
	[[AWFCascadingStyle style].defaultTextStyle applyToLabel:locationLabel withFontSize:28.0];
	[self.view addSubview:locationLabel];
	self.locationTextLabel = locationLabel;
	
	// forecast column
	UITableView *forecastTableView = [UITableView new];
	forecastTableView.translatesAutoresizingMaskIntoConstraints = NO;
	forecastTableView.backgroundColor = self.view.backgroundColor;
	forecastTableView.estimatedRowHeight = cellHeight;
	forecastTableView.separatorColor = [UIColor clearColor];
	forecastTableView.separatorInset = UIEdgeInsetsZero;
	forecastTableView.dataSource = self;
	forecastTableView.allowsSelection = NO;
	[forecastTableView registerClass:[AWFTableViewForecast24HourCell class] forCellReuseIdentifier:forecastCellIdentifier];
	[self.view addSubview:forecastTableView];
	self.forecastTableView = forecastTableView;
	
	// left column
	AWFObservationView *obsView = [AWFObservationView new];
	obsView.translatesAutoresizingMaskIntoConstraints = NO;
	obsView.layoutMargins = UIEdgeInsetsZero;
	obsView.numberOfDetailColumns = 1;
	obsView.locationTextLabel.hidden = YES;
	[self.view addSubview:obsView];
	self.obsView = obsView;
	
	AWFObservationAdvisoriesView *advisoriesView = [AWFObservationAdvisoriesView new];
	advisoriesView.translatesAutoresizingMaskIntoConstraints = NO;
	advisoriesView.alpha = 0;
	advisoriesView.headerView.textLabel.text = NSLocalizedString(@"Active Advisories", nil);
	[self.view addSubview:advisoriesView];
	self.advisoriesView = advisoriesView;
	
	// layout
	UILayoutGuide *layoutGuide = self.view.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[[locationLabel.topAnchor constraintEqualToAnchor:layoutGuide.topAnchor constant:10.0],
											  [locationLabel.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
											  
											  [forecastTableView.topAnchor constraintEqualToAnchor:layoutGuide.topAnchor constant:75.0],
											  [forecastTableView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [forecastTableView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
											  [forecastTableView.widthAnchor constraintEqualToAnchor:self.view.widthAnchor multiplier:0.66],
											  
											  [obsView.topAnchor constraintEqualToAnchor:forecastTableView.topAnchor],
											  [obsView.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
											  [obsView.rightAnchor constraintEqualToAnchor:forecastTableView.leftAnchor constant:-20.0],
											  
											  [advisoriesView.topAnchor constraintEqualToAnchor:obsView.bottomAnchor constant:20.0],
											  [advisoriesView.leftAnchor constraintEqualToAnchor:obsView.leftAnchor],
											  [advisoriesView.rightAnchor constraintEqualToAnchor:obsView.rightAnchor],
											  [advisoriesView.heightAnchor constraintEqualToConstant:57.0]]];
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	[self updateStyle];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(applicationDidBecomeActive:) name:UIApplicationDidBecomeActiveNotification object:nil];
	// listen for changes to the default place from the search controller
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(loadDataForDefaultPlace) name:kAWFDemoDefaultPlaceChanged object:nil];
	// listen for style changes
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(updateStyle) name:kAWFDemoDefaultStyleChanged object:nil];
	
	[self loadDataForDefaultPlace];
}

- (void)viewWillDisappear:(BOOL)animated {
	[super viewWillDisappear:animated];
	
	[[NSNotificationCenter defaultCenter] removeObserver:self name:kAWFDemoDefaultPlaceChanged object:nil];
	[[NSNotificationCenter defaultCenter] removeObserver:self name:kAWFDemoDefaultStyleChanged object:nil];
	[[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationDidBecomeActiveNotification object:nil];
}

- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
	[self.forecastTableView reloadData];
}

- (void)showMenu {
	NSArray<UIViewController *> *viewControllers = self.splitViewController.viewControllers;
	if ([viewControllers count] == 2) {
		[self presentViewController:viewControllers[0] animated:YES completion:nil];
	}
}

- (void)loadDataForDefaultPlace {
	__weak typeof(self) weakSelf = self;
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	self.locationTextLabel.text = place.formattedNameFull;
	
	// load latest observation data for place
	__weak typeof(self.obsView) weakObsView = self.obsView;
	[self.obs getForPlace:place options:nil completion:^(AWFWeatherEndpointResult * _Nullable result) {
		if (result.error) {
			NSLog(@"Observation data failed to load! %@", result.error);
			return;
		}
		
		NSArray *objects = result.results;
		if ([objects count] > 0) {
			AWFObservation *obs = (AWFObservation *)[objects objectAtIndex:0];
			
			// determine winds string
			CGFloat windSpeed = obs.windSpeedMPH;
			NSString *windStr = [NSString stringWithFormat:@"%@ %.0f mph", obs.windDirection, windSpeed];
			if (windSpeed == 0) {
				windStr = @"Calm";
			}
			
			weakObsView.tempTextLabel.text = [NSString stringWithFormat:@"%.0f%@", obs.tempF, AWFDegree];
			weakObsView.weatherTextLabel.text = obs.weather;
			weakObsView.iconImageView.image = [UIImage imageNamed:obs.icon];
			weakObsView.feelslikeTextLabel.text = [NSString stringWithFormat:@"Feels Like %.0f%@", obs.feelslikeF, AWFDegree];
			weakObsView.windsTextLabel.text = windStr;
			weakObsView.dewpointTextLabel.text = [NSString stringWithFormat:@"%.0f%@", obs.dewpointF, AWFDegree];
			weakObsView.humidityTextLabel.text = [NSString stringWithFormat:@"%.0f%%", obs.humidity];
			weakObsView.pressureTextLabel.text = [NSString stringWithFormat:@"%.2f in", obs.pressureIN];
		}
	}];
	
	// load 24-hour forecast
	AWFWeatherRequestOptions *forecastOptions = [[AWFWeatherRequestOptions alloc] init];
	forecastOptions.limit = 28;
	forecastOptions.filterString = @"daynight";
	
	[self.forecasts getForPlace:place options:forecastOptions completion:^(AWFWeatherEndpointResult * _Nullable result) {
		if (result.error) {
			NSLog(@"Forecast data failed to load!: %@", result.error);
			return;
		}
		
		NSArray *objects = result.results;
		if ([objects count] > 0) {
			AWFForecast *forecast = (AWFForecast *)[objects objectAtIndex:0];
			weakSelf.forecastPeriods = forecast.periods;
			[weakSelf.forecastTableView reloadData];
		}
	}];
	
	// load advisories
	[self.advisories getForPlace:place options:nil completion:^(AWFWeatherEndpointResult * _Nullable result) {
		if (result.error) {
			NSLog(@"Advisories data failed to load! %@", result.error);
			return;
		}
		
		NSArray *objects = result.results;
		if ([objects count] > 0) {
			weakSelf.advisoriesView.advisories = objects;
			[UIView animateWithDuration:0.2 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
				weakSelf.advisoriesView.alpha = 1;
			} completion:nil];
		} else {
			[UIView animateWithDuration:0.2 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
				weakSelf.advisoriesView.alpha = 0;
			} completion:nil];
		}
	}];
}
#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return roundf([self.forecastPeriods count] / 2);
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	AWFTableViewForecast24HourCell *cell = (AWFTableViewForecast24HourCell *)[tableView dequeueReusableCellWithIdentifier:forecastCellIdentifier];
	
	AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
	cell.backgroundColor = style.backgroundColor;
	[cell applyStyle:style];
	
	NSInteger dayIndex = indexPath.row * 2;
	NSInteger nightIndex = indexPath.row * 2 + 1;
	AWFForecastPeriod *dayPeriod = (AWFForecastPeriod *)[self.forecastPeriods objectAtIndex:dayIndex];
	AWFForecastPeriod *nightPeriod = (AWFForecastPeriod *)[self.forecastPeriods objectAtIndex:nightIndex];
	
	if (![dayPeriod.timestamp awf_isDay]) {
		dayPeriod = (AWFForecastPeriod *)[self.forecastPeriods objectAtIndex:nightIndex];
		nightPeriod = (AWFForecastPeriod *)[self.forecastPeriods objectAtIndex:dayIndex];
	}
	
	cell.periodLabel.text = [dayPeriod.timestamp awf_formattedDateWithFormat:@"eeee" timeZone:dayPeriod.timeZone];
	cell.dateLabel.text = [dayPeriod.timestamp awf_formattedDateWithFormat:@"MMM d" timeZone:dayPeriod.timeZone];
	[self updateForecastView:cell.firstPeriodView withPeriod:dayPeriod];
	[self updateForecastView:cell.secondPeriodView withPeriod:nightPeriod];
	
	return cell;
}

#pragma mark - UISplitViewControllerDelegate

- (BOOL)splitViewController:(UISplitViewController *)svc shouldHideViewController:(UIViewController *)vc inOrientation:(UIInterfaceOrientation)orientation {
	return YES;
}

- (void)splitViewController:(UISplitViewController *)svc willChangeToDisplayMode:(UISplitViewControllerDisplayMode)displayMode {
	if (displayMode == UISplitViewControllerDisplayModePrimaryHidden) {
		
	} else if (displayMode == UISplitViewControllerDisplayModePrimaryOverlay) {
		
	}
}

#pragma mark - CatalogViewController

- (void)catalogViewControllerDidSelectDetailItem:(CatalogViewController *)cvc {
	NSArray<UIViewController *> *viewControllers = self.splitViewController.viewControllers;
	if ([viewControllers count] == 2) {
		[viewControllers[0] dismissViewControllerAnimated:YES completion:nil];
	}
}

#pragma mark - Private

- (void)updateForecastView:(AWFForecastDetailView *)forecastView withPeriod:(AWFForecastPeriod *)period {
	CGFloat temp = (period.isDay) ? period.maxTempF : period.minTempF;
	
	forecastView.showsPeriod = NO;
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

- (void)updateStyle {
	// refresh styles if it's different than the user's preference
	AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
	self.view.backgroundColor = style.viewControllerBackgroundColor;
	self.forecastTableView.backgroundColor = style.viewControllerBackgroundColor;
	
	[self.obsView applyStyle:style];
	self.obsView.backgroundColor = [UIColor clearColor];
	self.locationTextLabel.textColor = style.defaultTextStyle.textColor;
	[self.forecastTableView reloadData];
}

- (void)applicationDidBecomeActive:(NSNotification *)notification {
	[self loadDataForDefaultPlace];
}

@end
