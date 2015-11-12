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
@property (nonatomic, strong) AWFPlacesLoader *placesLoader;
@property (nonatomic, strong) AWFObservationsLoader *obsLoader;
@property (nonatomic, strong) AWFForecastsLoader *forecastsLoader;
@property (nonatomic, strong) AWFAdvisoriesLoader *advisoriesLoader;
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
		self.obsLoader = [[AWFObservationsLoader alloc] init];
		self.forecastsLoader = [[AWFForecastsLoader alloc] init];
		self.advisoriesLoader = [[AWFAdvisoriesLoader alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	
	// observations view
	AWFObservationView *obsView = [[AWFObservationView alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(self.view.frame), 200.0)];
	obsView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
	[self.view addSubview:obsView];
	self.obsView = obsView;
	
	AWFObservationAdvisoriesView *advisoriesView = [[AWFObservationAdvisoriesView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(obsView.frame) - 56.0, CGRectGetWidth(self.view.frame), 56.0)];
	advisoriesView.alpha = 0;
	advisoriesView.headerView.textLabel.text = NSLocalizedString(@"Active Advisories", nil);
	[self.view addSubview:advisoriesView];
	self.advisoriesView = advisoriesView;
	
	// tap gesture on advisories view
	UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(showAdvisories)];
	[advisoriesView addGestureRecognizer:tapRecognizer];
	
	UIView *obsKeyline = [[UIView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(obsView.frame), CGRectGetWidth(self.view.frame), 2.0)];
	obsKeyline.backgroundColor = [UIColor colorWithWhite:0.8 alpha:1.0];
	[self.view addSubview:obsKeyline];
	
	// 24-hour outlook views
	CGRect todayViewFrame = CGRectMake(0, CGRectGetMaxY(obsKeyline.frame), CGRectGetWidth(self.view.frame) / 2.0, 110.0);
	AWFForecastDetailView *todayView = [[AWFForecastDetailView alloc] initWithFrame:todayViewFrame];
	todayView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
	todayView.periodTextLabel.text = @"--";
	[self.view addSubview:todayView];
	self.todayView = todayView;
	
	CGRect tonightViewFrame = CGRectMake(CGRectGetMaxX(todayView.frame), CGRectGetMinY(todayView.frame),
										 CGRectGetWidth(self.view.frame) - CGRectGetWidth(todayView.frame), 110.0);
	AWFForecastDetailView *tonightView = [[AWFForecastDetailView alloc] initWithFrame:tonightViewFrame];
	tonightView.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleLeftMargin;
	tonightView.periodTextLabel.text = @"--";
	[self.view addSubview:tonightView];
	self.tonightView = tonightView;
	
	UIView *forecastKeyline = [[UIView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(todayView.frame), CGRectGetWidth(self.view.frame), 2.0)];
	forecastKeyline.backgroundColor = [UIColor colorWithWhite:0.8 alpha:1.0];
	[self.view addSubview:forecastKeyline];
	
	// hourly row collection view
	CGRect hourlyViewFrame = CGRectMake(0, CGRectGetMaxY(forecastKeyline.frame), CGRectGetWidth(self.view.frame),
										CGRectGetHeight(self.view.frame) - CGRectGetMaxY(forecastKeyline.frame));
	
	UICollectionViewFlowLayout *hourlyLayout = [[UICollectionViewFlowLayout alloc] init];
	hourlyLayout.scrollDirection = UICollectionViewScrollDirectionHorizontal;
	hourlyLayout.minimumInteritemSpacing = 0;
	hourlyLayout.minimumLineSpacing = 0;
	hourlyLayout.itemSize = CGSizeMake(80.0, CGRectGetHeight(hourlyViewFrame));
	
	UICollectionView *hourlyCollectionView = [[UICollectionView alloc] initWithFrame:hourlyViewFrame collectionViewLayout:hourlyLayout];
	hourlyCollectionView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	hourlyCollectionView.dataSource = self;
	hourlyCollectionView.delegate = self;
	[self.view addSubview:hourlyCollectionView];
	self.hourlyCollectionView = hourlyCollectionView;
	
	// register the appropriate forecast view to use for our hourly forecast collection view cells
	[hourlyCollectionView registerClass:[AWFCollectionViewHourlyBasicCell class] forCellWithReuseIdentifier:hourlyCellIdentifier];
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
		[NSDate awf_setDefaultTimezone:period.timeZone];
		hourlyCell.weatherView.period = [period.timestamp awf_stringWithFormat:@"h a"];
		
		hourlyCell.weatherView.temp = [NSString stringWithFormat:@"%i", [period.tempF intValue]];
		hourlyCell.weatherView.pop = [NSString stringWithFormat:@"%li%%", (long)[period.pop integerValue]];
		hourlyCell.weatherView.winds = [NSString stringWithFormat:@"%@ %@", period.windDirection, period.windSpeedRangeMPH];
		hourlyCell.weatherView.icon = [AWFImage weatherIconNamed:period.icon];
		
		// show snow instead of precip if snow is forecasted
		CGFloat precipVal = [period.precipIN floatValue];
		//NSString *precipLabel = NSLocalizedString(@"Precip", nil);
		if ([[period.weather lowercaseString] rangeOfString:@"snow"].location != NSNotFound) {
			precipVal = [period.snowIN floatValue];
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
	[self.obsLoader getObservationForPlace:place options:nil completion:^(NSArray *objects, NSError *error) {
		if (error) {
			NSLog(@"Observation data failed to load! %@", error);
			return;
		}
		
		if ([objects count] > 0) {
			AWFObservation *obs = (AWFObservation *)[objects objectAtIndex:0];
			
			// determine winds string
			NSInteger windSpeed = [obs.windSpeedMPH intValue];
			NSString *windStr = [NSString stringWithFormat:@"%@ %i mph", obs.windDirection, [obs.windSpeedMPH intValue]];
			if (windSpeed == 0) {
				windStr = @"Calm";
			}
			
			weakObsView.tempTextLabel.text = [NSString stringWithFormat:@"%li%@", (long)[obs.tempF integerValue], AWFDegree];
			weakObsView.weatherTextLabel.text = obs.weather;
			weakObsView.iconImageView.image = [AWFImage weatherIconNamed:obs.icon];
			weakObsView.feelslikeTextLabel.text = [NSString stringWithFormat:@"Feels Like %li%@", (long)[obs.feelslikeF integerValue], AWFDegree];
			weakObsView.windsTextLabel.text = windStr;
			weakObsView.dewpointTextLabel.text = [NSString stringWithFormat:@"%i%@", [obs.dewpointF intValue], AWFDegree];
			weakObsView.humidityTextLabel.text = [NSString stringWithFormat:@"%i%%", [obs.humidity intValue]];
			weakObsView.pressureTextLabel.text = [NSString stringWithFormat:@"%.2f in", [obs.pressureIN floatValue]];
		}
	}];
	
	// load 24-hour forecast
	AWFRequestOptions *forecastOptions = [[AWFRequestOptions alloc] init];
	forecastOptions.limit = 2;
	forecastOptions.filterString = @"daynight";
	
	[self.forecastsLoader getForecastForPlace:place options:forecastOptions completion:^(NSArray *objects, NSError *error) {
		if (error) {
			NSLog(@"24-hour forecast data failed to load! %@", error);
			return;
		}
		
		if ([objects count] > 0) {
			
			AWFForecast *forecast = (AWFForecast *)[objects objectAtIndex:0];
			
			[forecast.periods enumerateObjectsUsingBlock:^(AWFForecastPeriod *period, NSUInteger idx, BOOL *stop) {
				// determine which view to set the data on
				AWFForecastDetailView *forecastView = (idx == 1) ? weakSelf.tonightView : weakSelf.todayView;
				
				NSString *temp = (period.isDay) ? [NSString stringWithFormat:@"%i", [period.maxTempF intValue]] : [NSString stringWithFormat:@"%i", [period.minTempF intValue]];
				
				forecastView.tempTextLabel.text = temp;
				forecastView.weatherTextLabel.text = period.weather;
				forecastView.iconImageView.image = [AWFImage weatherIconNamed:period.icon];
				//forecastView.winds = [NSString stringWithFormat:@"%@ %i mph", period.windDirection, [period.windSpeedMPH intValue]];
				forecastView.windsTextLabel.text = [NSString stringWithFormat:@"%@ %@ mph", period.windDirection, period.windSpeedRangeMPH];
				
				// need to set the proper default timezone to use when formatting this location's date/time/day
				[NSDate awf_setDefaultTimezone:period.timeZone];
				forecastView.periodTextLabel.text = [period.timestamp awf_dayRelativeToNow];
				
				// show snow instead of precip if snow is forecasted
				if ([[period.weather lowercaseString] rangeOfString:@"snow"].location != NSNotFound) {
					forecastView.precipTypeTextLabel.text = NSLocalizedString(@"Snow", nil);
					forecastView.precipTextLabel.text = [NSString stringWithFormat:@"%.2f in", [period.snowIN floatValue]];
				}
				else {
					forecastView.precipTypeTextLabel.text = NSLocalizedString(@"Precip", nil);
					forecastView.precipTextLabel.text = [NSString stringWithFormat:@"%.2f in", [period.precipIN floatValue]];
				}
			}];
		}
	}];
	
	// load hourly forecast
	AWFRequestOptions *hourlyOptions = [[AWFRequestOptions alloc] init];
	hourlyOptions.limit = 9;
	hourlyOptions.filterString = @"3hr";
	
	[self.forecastsLoader getForecastForPlace:place options:hourlyOptions completion:^(NSArray *objects, NSError *error) {
		if (error) {
			NSLog(@"Hourly forecast data failed to load!: %@", error);
			return;
		}
		
		if ([objects count] > 0) {
			AWFForecast *forecast = (AWFForecast *)[objects objectAtIndex:0];
			weakSelf.hourlyPeriods = [forecast.periods copy];
			[weakSelf.hourlyCollectionView reloadData];
		}
	}];
	
	// load advisories
	[self.advisoriesLoader getAdvisoriesForPlace:place options:nil completion:^(NSArray *objects, NSError *error) {
		if (error) {
			NSLog(@"Advisories data failed to load! %@", error);
			return;
		}
		
		if ([objects count] > 0) {
			weakSelf.advisoriesView.advisories = objects;
			
			[UIView animateWithDuration:0.2 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
				weakSelf.advisoriesView.alpha = 1;
			} completion:nil];
		}
		else {
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
