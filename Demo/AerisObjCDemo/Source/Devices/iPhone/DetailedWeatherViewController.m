//
//  DetailedWeatherViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "DetailedWeatherViewController.h"
#import "AdvisoriesViewController.h"

@interface DetailedWeatherViewController ()
@property (nonatomic, strong) AWFObservationView *obsView;
@property (nonatomic, strong) AWFObservationAdvisoriesView *advisoriesView;
@property (nonatomic, strong) AWFForecastDetailView *todayView;
@property (nonatomic, strong) AWFForecastDetailView *tonightView;
@property (nonatomic, strong) UICollectionView *hourlyCollectionView;
@property (nonatomic, strong) AWFPlaces *places;
@property (nonatomic, strong) AWFObservations *obs;
@property (nonatomic, strong) AWFForecasts *forecasts;
@property (nonatomic, strong) AWFAdvisories *advisories;
@property (nonatomic, strong) NSArray *hourlyPeriods;
@property (nonatomic, strong) AdvisoriesViewController *advisoriesController;
@end

static NSString *hourlyCellIdentifier = @"HourlyForecastCell";

@implementation DetailedWeatherViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
		
		// handle the translucent status bar in iOS 7
		if (AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
			self.edgesForExtendedLayout = UIRectEdgeNone;
		}
		
        // create object loaders
		self.obs = [[AWFObservations alloc] init];
		self.forecasts = [[AWFForecasts alloc] init];
		self.advisories = [[AWFAdvisories alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	
	// observations view
	AWFObservationView *obsView = [AWFObservationView new];
	obsView.translatesAutoresizingMaskIntoConstraints = NO;
	[self.view addSubview:obsView];
	self.obsView = obsView;
	
	AWFObservationAdvisoriesView *advisoriesView = [AWFObservationAdvisoriesView new];
	advisoriesView.translatesAutoresizingMaskIntoConstraints = NO;
	advisoriesView.alpha = 0;
	advisoriesView.headerView.textLabel.text = NSLocalizedString(@"Active Advisories", nil);
	[self.view addSubview:advisoriesView];
	self.advisoriesView = advisoriesView;
	
	UIView *obsKeyline = [UIView new];
	obsKeyline.translatesAutoresizingMaskIntoConstraints = NO;
	obsKeyline.backgroundColor = [UIColor colorWithWhite:0.8 alpha:1.0];
	[self.view addSubview:obsKeyline];
	
	// 24-hour outlook views
	AWFForecastDetailView *todayView = [AWFForecastDetailView new];
	todayView.translatesAutoresizingMaskIntoConstraints = NO;
	todayView.periodTextLabel.text = @"--";
	[self.view addSubview:todayView];
	self.todayView = todayView;
	
	AWFForecastDetailView *tonightView = [AWFForecastDetailView new];
	tonightView.translatesAutoresizingMaskIntoConstraints = NO;
	tonightView.periodTextLabel.text = @"--";
	[self.view addSubview:tonightView];
	self.tonightView = tonightView;
	
	UIView *forecastKeyline = [UIView new];
	forecastKeyline.translatesAutoresizingMaskIntoConstraints = NO;
	forecastKeyline.backgroundColor = [UIColor colorWithWhite:0.8 alpha:1.0];
	[self.view addSubview:forecastKeyline];
	
	// hourly row collection view
	UICollectionViewFlowLayout *hourlyLayout = [[UICollectionViewFlowLayout alloc] init];
	hourlyLayout.scrollDirection = UICollectionViewScrollDirectionHorizontal;
	hourlyLayout.minimumInteritemSpacing = 0;
	hourlyLayout.minimumLineSpacing = 0;
	hourlyLayout.itemSize = CGSizeMake(80.0, 50.0);
	
	UICollectionView *hourlyCollectionView = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:hourlyLayout];
	hourlyCollectionView.translatesAutoresizingMaskIntoConstraints = NO;
	hourlyCollectionView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	hourlyCollectionView.dataSource = self;
	hourlyCollectionView.delegate = self;
	[hourlyCollectionView registerClass:[AWFCollectionViewHourlyBasicCell class] forCellWithReuseIdentifier:hourlyCellIdentifier];
	[self.view addSubview:hourlyCollectionView];
	self.hourlyCollectionView = hourlyCollectionView;
	
	// layout
	[NSLayoutConstraint activateConstraints:@[[obsView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
											  [obsView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [obsView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  
											  [advisoriesView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [advisoriesView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [advisoriesView.bottomAnchor constraintEqualToAnchor:obsView.bottomAnchor],
											  [advisoriesView.heightAnchor constraintEqualToConstant:57.0],
											  
											  [obsKeyline.topAnchor constraintEqualToAnchor:obsView.bottomAnchor],
											  [obsKeyline.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [obsKeyline.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [obsKeyline.heightAnchor constraintEqualToConstant: 2.0],
											  
											  [todayView.topAnchor constraintEqualToAnchor:obsKeyline.bottomAnchor],
											  [todayView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [todayView.rightAnchor constraintEqualToAnchor:self.view.centerXAnchor],
											  
											  [tonightView.topAnchor constraintEqualToAnchor:todayView.topAnchor],
											  [tonightView.leftAnchor constraintEqualToAnchor:self.view.centerXAnchor],
											  [tonightView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  
											  [forecastKeyline.topAnchor constraintEqualToAnchor:todayView.bottomAnchor],
											  [forecastKeyline.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [forecastKeyline.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [forecastKeyline.heightAnchor constraintEqualToConstant: 2.0],
											  
											  [hourlyCollectionView.topAnchor constraintEqualToAnchor:forecastKeyline.bottomAnchor],
											  [hourlyCollectionView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [hourlyCollectionView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [hourlyCollectionView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor]]];
	
	// tap gesture on advisories view
	UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(showAdvisories)];
	[advisoriesView addGestureRecognizer:tapRecognizer];
}

- (void)viewDidLayoutSubviews {
	[super viewDidLayoutSubviews];
	
	UICollectionViewFlowLayout *hourlyCollectionLayout = (UICollectionViewFlowLayout *)self.hourlyCollectionView.collectionViewLayout;
	hourlyCollectionLayout.itemSize = CGSizeMake(80.0, CGRectGetHeight(self.view.frame) - CGRectGetMinY(self.hourlyCollectionView.frame));
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	// refresh styles if it's different than the user's preference
	AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
	self.view.backgroundColor = style.viewControllerBackgroundColor;
	self.hourlyCollectionView.backgroundColor = style.viewControllerBackgroundColor;
	
	[self.obsView applyStyle:style];
	[self.todayView applyStyle:style];
	[self.tonightView applyStyle:style];
	[self.hourlyCollectionView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];

	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(applicationDidBecomeActive:) name:UIApplicationDidBecomeActiveNotification object:nil];
	[self loadDataForDefaultPlace];
}

- (void)viewWillDisappear:(BOOL)animated {
	[super viewWillDisappear:animated];
	
	[[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationDidBecomeActiveNotification object:nil];
}

- (void)showAdvisories {
	if (!self.advisoriesController) {
		self.advisoriesController = [[AdvisoriesViewController alloc] initWithNibName:nil bundle:nil];
	}
	[self.navigationController pushViewController:self.advisoriesController animated:YES];
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
	return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
	return [self.hourlyPeriods count];
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:hourlyCellIdentifier forIndexPath:indexPath];
	
	if ([cell isKindOfClass:[AWFCollectionViewHourlyBasicCell class]]) {
		AWFCollectionViewHourlyBasicCell *hourlyCell = (AWFCollectionViewHourlyBasicCell *)cell;
		[hourlyCell.weatherView applyStyle:[[Preferences sharedInstance] preferredStyle]];
		
		AWFForecastPeriod *period = (AWFForecastPeriod *)[self.hourlyPeriods objectAtIndex:indexPath.row];
		
		// need to set the proper default timezone to use when formatting this location's date/time/day
		hourlyCell.weatherView.period = [period.timestamp awf_formattedDateWithFormat:@"h a" timeZone:period.timeZone];
		
		hourlyCell.weatherView.temp = [NSString stringWithFormat:@"%.0f", period.tempF];
		hourlyCell.weatherView.pop = [NSString stringWithFormat:@"%.0f%%", period.pop];
		hourlyCell.weatherView.winds = [NSString stringWithFormat:@"%@ %@", period.windDirection, period.windSpeedRangeMPH];
		hourlyCell.weatherView.icon = [UIImage imageNamed:period.icon];
		
		// show snow instead of precip if snow is forecasted
		CGFloat precipVal = period.precipIN;
		//NSString *precipLabel = NSLocalizedString(@"Precip", nil);
		if ([[period.weather lowercaseString] rangeOfString:@"snow"].location != NSNotFound) {
			precipVal = period.snowIN;
			//precipLabel = NSLocalizedString(@"Snow", nil);
		}
		hourlyCell.weatherView.precip = [NSString stringWithFormat:@"%.2f\"", precipVal];
	}
	
	return cell;
}

#pragma mark - Private Methods

- (void)loadDataForDefaultPlace {
	__weak typeof(self) weakSelf = self;
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	self.obsView.locationTextLabel.text = place.formattedNameFull;
	
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
			NSInteger windSpeed = obs.windSpeedMPH;
			NSString *windStr = [NSString stringWithFormat:@"%@ %.0f mph", obs.windDirection, obs.windSpeedMPH];
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
	forecastOptions.limit = 2;
	forecastOptions.filterString = @"daynight";
	
	[self.forecasts getForPlace:place options:forecastOptions completion:^(AWFWeatherEndpointResult * _Nullable result) {
		if (result.error) {
			NSLog(@"24-hour forecast data failed to load! %@", result.error);
			return;
		}
		
		NSArray *objects = result.results;
		if ([objects count] > 0) {
			
			AWFForecast *forecast = (AWFForecast *)[objects objectAtIndex:0];
			
			[forecast.periods enumerateObjectsUsingBlock:^(AWFForecastPeriod *period, NSUInteger idx, BOOL *stop) {
				// determine which view to set the data on
				AWFForecastDetailView *forecastView = (idx == 1) ? weakSelf.tonightView : weakSelf.todayView;
				
				NSString *temp = (period.isDay) ? [NSString stringWithFormat:@"%.0f", period.maxTempF] : [NSString stringWithFormat:@"%.0f", period.minTempF];
				
				forecastView.tempTextLabel.text = temp;
				forecastView.weatherTextLabel.text = period.weather;
				forecastView.iconImageView.image = [UIImage imageNamed:period.icon];
				//forecastView.winds = [NSString stringWithFormat:@"%@ %i mph", period.windDirection, [period.windSpeedMPH intValue]];
				forecastView.windsTextLabel.text = [NSString stringWithFormat:@"%@ %@ mph", period.windDirection, period.windSpeedRangeMPH];
				
				// need to set the proper default timezone to use when formatting this location's date/time/day
				forecastView.periodTextLabel.text = [period.timestamp awf_dayNameRelativeToNow:YES timeZone:period.timeZone];
				
				// show snow instead of precip if snow is forecasted
				if ([[period.weather lowercaseString] rangeOfString:@"snow"].location != NSNotFound) {
					forecastView.precipTypeTextLabel.text = NSLocalizedString(@"Snow", nil);
					forecastView.precipTextLabel.text = [NSString stringWithFormat:@"%.2f in", period.snowIN];
				} else {
					forecastView.precipTypeTextLabel.text = NSLocalizedString(@"Precip", nil);
					forecastView.precipTextLabel.text = [NSString stringWithFormat:@"%.2f in", period.precipIN];
				}
			}];
		}
	}];
	
	// load hourly forecast
	AWFWeatherRequestOptions *hourlyOptions = [[AWFWeatherRequestOptions alloc] init];
	hourlyOptions.limit = 9;
	hourlyOptions.filterString = @"3hr";
	
	[self.forecasts getForPlace:place options:hourlyOptions completion:^(AWFWeatherEndpointResult * _Nullable result) {
		if (result.error) {
			NSLog(@"Hourly forecast data failed to load!: %@", result.error);
			return;
		}
		
		NSArray *objects = result.results;
		if ([objects count] > 0) {
			AWFForecast *forecast = (AWFForecast *)[objects objectAtIndex:0];
			weakSelf.hourlyPeriods = [forecast.periods copy];
			[weakSelf.hourlyCollectionView reloadData];
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

- (void)applicationDidBecomeActive:(NSNotification *)notification {
	[self loadDataForDefaultPlace];
}

@end
