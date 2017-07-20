//
//  ForecastViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/28/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "ForecastViewController.h"
#import "ListingEventView.h"

@interface ForecastViewController ()
@property (nonatomic, strong) UICollectionView *collectionView;
@property (nonatomic, strong) AWFForecastsLoader *forecastsLoader;
@property (nonatomic, strong) NSArray *periods;
@property (nonatomic, strong) ListingEventView *eventView;
@end

static NSString *forecastCellIdentifier = @"ForecastCell";

@implementation ForecastViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.forecastsLoader = [[AWFForecastsLoader alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
		
	UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
	layout.scrollDirection = UICollectionViewScrollDirectionVertical;
	layout.minimumInteritemSpacing = 0;
	layout.minimumLineSpacing = 0;
	layout.itemSize = CGSizeMake(CGRectGetWidth(self.view.frame), 60.0);
	
	UICollectionView *collectionView = [[UICollectionView alloc] initWithFrame:self.view.bounds collectionViewLayout:layout];
	collectionView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	collectionView.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
	collectionView.dataSource = self;
	collectionView.delegate = self;
	[self.view addSubview:collectionView];
	self.collectionView = collectionView;
	
	// register the appropriate forecast view to use for our hourly forecast collection view cells
	[collectionView registerClass:[AWFCollectionViewForecastRowCell class] forCellWithReuseIdentifier:forecastCellIdentifier];
	
	ListingEventView *eventView = [[ListingEventView alloc] initWithFrame:self.view.bounds];
	eventView.alpha = 0;
	[self.view addSubview:eventView];
	self.eventView = eventView;
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	// refresh styles if it's different than the user's preference
	AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
	self.collectionView.backgroundColor = style.viewControllerBackgroundColor;
	
	self.eventView.backgroundColor = style.viewControllerBackgroundColor;
	self.eventView.messageLabel.textColor = style.defaultTextStyle.textColor;
	self.eventView.detailedMessageLabel.textColor = style.detailTextStyle.textColor;
	
	[self.collectionView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	__weak typeof(self) weakSelf = self;
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	// load forecast
	AWFRequestOptions *forecastOptions = [[AWFRequestOptions alloc] init];
	forecastOptions.limit = 15;
	
	// only show loader if we haven't already populated the view once
	if ([self.periods count] == 0) {
		[self.eventView showLoading];
	}
	
	[self.forecastsLoader getForecastForPlace:place options:forecastOptions completion:^(NSArray *objects, NSError *error) {
		if (error) {
			[self.eventView showMessage:NSLocalizedString(@"An error occurred while requesting the weather data.", nil)];
			NSLog(@"Forecast data failed to load! %@", error.localizedDescription);
			return;
		}
		
		[self.eventView hide];
		if ([objects count] > 0) {
			AWFForecast *forecast = (AWFForecast *)[objects objectAtIndex:0];
			weakSelf.periods = forecast.periods;
			[weakSelf.collectionView reloadData];
		}
	}];
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
	return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
	return [self.periods count];
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:forecastCellIdentifier forIndexPath:indexPath];
	
	if ([cell isKindOfClass:[AWFCollectionViewForecastRowCell class]]) {
		AWFCollectionViewForecastRowCell *forecastCell = (AWFCollectionViewForecastRowCell *)cell;
		[forecastCell.weatherView applyStyle:[[Preferences sharedInstance] preferredStyle]];
		
		AWFForecastPeriod *period = (AWFForecastPeriod *)[self.periods objectAtIndex:indexPath.row];
		
		forecastCell.weatherView.hightemp = [NSString stringWithFormat:@"%i", [period.maxTempF intValue]];
		forecastCell.weatherView.lowtemp = [NSString stringWithFormat:@"%i", [period.minTempF intValue]];
		forecastCell.weatherView.weather = period.weatherFull;
		forecastCell.weatherView.icon = [AWFImage weatherIconNamed:period.icon];
		forecastCell.weatherView.day = [period.timestamp awf_stringWithFormat:@"eee"];
		forecastCell.weatherView.date = [period.timestamp awf_stringWithFormat:@"MMM d"];
	}
	
	return cell;
}

@end
