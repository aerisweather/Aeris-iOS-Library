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

@interface DetailedWeatherViewController_iPad ()
@property (nonatomic, strong) AWFObservationView *obsView;
@property (nonatomic, strong) UICollectionView *forecastCollectionView;
@property (nonatomic, strong) UILabel *locationTextLabel;
@property (nonatomic, strong) AWFObservationsLoader *obsLoader;
@property (nonatomic, strong) AWFForecastsLoader *forecastsLoader;
@property (nonatomic, strong) AWFAdvisoriesLoader *advisoriesLoader;
@property (nonatomic, strong) NSArray *forecastPeriods;
@property (nonatomic, strong) UIPopoverController *splitViewPopover;
- (void)updateForecastView:(AWFForecastDetailView *)forecastView withPeriod:(AWFForecastPeriod *)period;
@end

static NSString *forecastCellIdentifier = @"ForecastCellIdentifier";
static CGFloat cellHeight = 122.0f;

@implementation DetailedWeatherViewController_iPad

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
		
        // create object loaders
		self.obsLoader = [[AWFObservationsLoader alloc] init];
		self.forecastsLoader = [[AWFForecastsLoader alloc] init];
		self.advisoriesLoader = [[AWFAdvisoriesLoader alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [[AWFCascadingStyle style].viewControllerBackgroundColor awf_adjustBrightness:1.2];
	
	CGRect leftFrame = CGRectMake(0, 0, 300.0, CGRectGetHeight(self.view.frame));
	CGRect rightFrame = CGRectMake(CGRectGetMaxX(leftFrame), 0, CGRectGetWidth(self.view.frame) - CGRectGetWidth(leftFrame), CGRectGetHeight(self.view.frame));
	CGRect leftContentFrame = CGRectInset(leftFrame, 10.0, 10.0);
	
	UILabel *locationLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMinX(leftContentFrame), CGRectGetMinY(leftContentFrame), 600.0, 60.0)];
	locationLabel.minimumScaleFactor = 0.8;
	locationLabel.text = @"";
	[[AWFCascadingStyle style].defaultTextStyle applyToLabel:locationLabel withFontSize:28.0];
	[self.view addSubview:locationLabel];
	
	// forecast column
	UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
	layout.scrollDirection = UICollectionViewScrollDirectionVertical;
	layout.minimumInteritemSpacing = 0;
	layout.minimumLineSpacing = 0;
	layout.itemSize = CGSizeMake(CGRectGetWidth(rightFrame), cellHeight);
	
	CGRect forecastFrame = CGRectMake(CGRectGetMinX(rightFrame), 75.0, CGRectGetWidth(rightFrame), CGRectGetHeight(rightFrame) - 75.0);
	UICollectionView *forecastCollectionView = [[UICollectionView alloc] initWithFrame:forecastFrame collectionViewLayout:layout];
	forecastCollectionView.backgroundColor = self.view.backgroundColor;
	forecastCollectionView.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
	forecastCollectionView.dataSource = self;
	forecastCollectionView.delegate = self;
	[self.view addSubview:forecastCollectionView];
	
	[forecastCollectionView registerClass:[AWFCollectionViewForecast24HourCell class] forCellWithReuseIdentifier:forecastCellIdentifier];
	
	// left column
	AWFObservationView *obsView = [[AWFObservationView alloc] initWithFrame:CGRectMake(CGRectGetMinX(leftContentFrame), CGRectGetMinY(forecastCollectionView.frame),
																					 CGRectGetWidth(leftContentFrame), 260.0)];
	obsView.numberOfDetailColumns = 1;
	obsView.backgroundColor = [UIColor clearColor];
	obsView.locationTextLabel.hidden = YES;
	[self.view addSubview:obsView];
	
	self.locationTextLabel = locationLabel;
	self.forecastCollectionView = forecastCollectionView;
	self.obsView = obsView;
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

- (void)viewDidLayoutSubviews {
	[super viewDidLayoutSubviews];
	
	CGFloat height = (UIInterfaceOrientationIsPortrait([UIApplication sharedApplication].statusBarOrientation)) ? cellHeight : cellHeight - 25.0;
	((UICollectionViewFlowLayout *)self.forecastCollectionView.collectionViewLayout).itemSize = CGSizeMake(CGRectGetWidth(self.forecastCollectionView.bounds), height);
	[self.forecastCollectionView.collectionViewLayout invalidateLayout];
	//[self.forecastCollectionView reloadData];
}

- (void)loadDataForDefaultPlace {
	__weak typeof(self) weakSelf = self;
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	self.locationTextLabel.text = place.formattedNameFull;
	
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
	forecastOptions.limit = 28;
	forecastOptions.filterString = @"daynight";
	
	[self.forecastsLoader getForecastForPlace:place options:forecastOptions completion:^(NSArray *objects, NSError *error) {
		if (error) {
			NSLog(@"Forecast data failed to load!: %@", error);
			return;
		}
		
		if ([objects count] > 0) {
			AWFForecast *forecast = (AWFForecast *)[objects objectAtIndex:0];
			weakSelf.forecastPeriods = forecast.periods;
			[weakSelf.forecastCollectionView reloadData];
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
//			AWFForecast *forecast = (AWFForecast *)[objects objectAtIndex:0];
//			weakSelf.hourlyPeriods = [forecast.periods copy];
//			[weakSelf.hourlyCollectionView reloadData];
		}
	}];
	
	// load advisories
	[self.advisoriesLoader getAdvisoriesForPlace:place options:nil completion:^(NSArray *objects, NSError *error) {
		if (error) {
			NSLog(@"Advisories data failed to load! %@", error);
			return;
		}
		
//		if ([objects count] > 0) {
//			weakSelf.advisoriesView.advisories = objects;
//			
//			[UIView animateWithDuration:0.2 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
//				weakSelf.advisoriesView.alpha = 1;
//			} completion:nil];
//		}
//		else {
//			[UIView animateWithDuration:0.2 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
//				weakSelf.advisoriesView.alpha = 0;
//			} completion:nil];
//		}
	}];
}

#pragma mark - UICollectionViewDelegate

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
	return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
	return [self.forecastPeriods count] / 2;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	AWFCollectionViewForecast24HourCell *cell = (AWFCollectionViewForecast24HourCell *)[collectionView dequeueReusableCellWithReuseIdentifier:forecastCellIdentifier forIndexPath:indexPath];
	[cell.weatherView applyStyle:[[Preferences sharedInstance] preferredStyle]];
	
	NSInteger dayIndex = indexPath.row * 2;
	NSInteger nightIndex = indexPath.row * 2 + 1;
	AWFForecastPeriod *dayPeriod = (AWFForecastPeriod *)[self.forecastPeriods objectAtIndex:dayIndex];
	AWFForecastPeriod *nightPeriod = (AWFForecastPeriod *)[self.forecastPeriods objectAtIndex:nightIndex];
	
	if (![dayPeriod.timestamp awf_isDay]) {
		dayPeriod = (AWFForecastPeriod *)[self.forecastPeriods objectAtIndex:nightIndex];
		nightPeriod = (AWFForecastPeriod *)[self.forecastPeriods objectAtIndex:dayIndex];
	}
	
	cell.weatherView.periodLabel.text = [dayPeriod.timestamp awf_stringWithFormat:@"eeee"];
	cell.weatherView.dateLabel.text = [dayPeriod.timestamp awf_stringWithFormat:@"MMM d"];
	[self updateForecastView:cell.weatherView.firstPeriodView withPeriod:dayPeriod];
	[self updateForecastView:cell.weatherView.secondPeriodView withPeriod:nightPeriod];
	
	return cell;
}

#pragma mark - UISplitViewControllerDelegate

- (BOOL)splitViewController:(UISplitViewController *)svc shouldHideViewController:(UIViewController *)vc inOrientation:(UIInterfaceOrientation)orientation {
	return YES;
}

- (void)splitViewController:(UISplitViewController *)svc willHideViewController:(UIViewController *)aViewController withBarButtonItem:(UIBarButtonItem *)barButtonItem forPopoverController:(UIPopoverController *)pc {
	self.splitViewPopover = pc;
	barButtonItem.title = NSLocalizedString(@"Catalog", nil);
	[self.navigationItem setLeftBarButtonItem:barButtonItem animated:YES];
}

- (void)splitViewController:(UISplitViewController *)svc willShowViewController:(UIViewController *)aViewController invalidatingBarButtonItem:(UIBarButtonItem *)barButtonItem {
	self.splitViewPopover = nil;
	[self.navigationItem setLeftBarButtonItem:nil animated:YES];
}

#pragma mark - CatalogViewController

- (void)catalogViewControllerDidSelectDetailItem:(CatalogViewController *)cvc {
	if (self.splitViewPopover) {
		[self.splitViewPopover dismissPopoverAnimated:YES];
	}
}

#pragma mark - Private

- (void)updateForecastView:(AWFForecastDetailView *)forecastView withPeriod:(AWFForecastPeriod *)period {
	NSNumber *temp = (period.isDay) ? period.maxTempF : period.minTempF;
	
	forecastView.showsPeriod = NO;
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

- (void)updateStyle {
	// refresh styles if it's different than the user's preference
	AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
	self.view.backgroundColor = style.viewControllerBackgroundColor;
	self.forecastCollectionView.backgroundColor = style.viewControllerBackgroundColor;
	
	[self.obsView applyStyle:style];
	self.obsView.backgroundColor = [UIColor clearColor];
	self.locationTextLabel.textColor = style.defaultTextStyle.textColor;
	[self.forecastCollectionView reloadData];
}

- (void)applicationDidBecomeActive:(NSNotification *)notification {
	[self loadDataForDefaultPlace];
}

@end
