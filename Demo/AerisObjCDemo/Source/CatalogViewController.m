//
//  CatalogViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "CatalogViewController.h"
#import "SettingsViewController.h"
#import "LocationSearchViewController.h"
#import "DetailedWeatherViewController.h"
#import "ForecastViewController.h"
#import "RecentObservationsViewController.h"
#import "NearbyObservationsViewController.h"
#import "WeekendWeatherViewController.h"
#import "ForecastLineGraphsViewController.h"
#import "LineGraphsViewController_iPad.h"
#import "BarGraphsViewController.h"
#import "BarGraphsViewController_iPad.h"
#import "RecentObsGraphViewController.h"
#import "ModelGraphsViewController.h"
#import "ModelGraphsViewController_iPad.h"
#import "DailySummaryGraphsViewController.h"
#import "AdvisoriesViewController.h"
#import "DailySummariesViewController.h"
#import "SunMoonViewController.h"
#import "MoonPhasesViewController.h"
#import "NormalsViewController.h"
#import "TidesViewController.h"
#import "IndicesViewController.h"
#import "StormReportsViewController.h"
#import "RecordsViewController.h"
#import "StormCellsViewController.h"
#import "EarthquakesViewController.h"
#import "ConvectiveOutlookViewController.h"
#import "ThreatsViewController.h"
#import "DroughtMonitorViewController.h"
#import "LightningSummaryViewController.h"
#import "LightningThreatsViewController.h"
#import "LightningFlashesViewController.h"
#import "LightningStrikesViewController.h"
#import "AppleMapViewController.h"
#if !TARGET_OS_UIKITFORMAC
#import "GoogleMapViewController.h"
#import "MapboxMapViewController.h"
#endif
#import "DetailedWeatherViewController_iPad.h"

@interface CatalogViewController ()
@property (nonatomic, strong) NSArray *categories;
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSCache *controllerCache;
@property (nonatomic, strong) UINavigationController *settingsController;
@property (nonatomic, strong) LocationSearchViewController *searchController;
@end

static NSString *cellIdentifier = @"AFCatalogCell";

@implementation CatalogViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.edgesForExtendedLayout = UIRectEdgeNone;
		self.navigationController.navigationBar.translucent = NO;
		self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"Settings", nil)
		                                                                         style:UIBarButtonItemStylePlain target:self action:@selector(showSettings)];

		self.controllerCache = [[NSCache alloc] init];

		NSArray *locationItems = @[@{ @"title": NSLocalizedString(@"Location Search", nil), @"class": [LocationSearchViewController class] }];

		NSArray *generalItems, *graphItems;
		if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
			generalItems = @[@{ @"title": NSLocalizedString(@"Detailed Weather", nil), @"class": [DetailedWeatherViewController_iPad class] },
							 @{ @"title": NSLocalizedString(@"Recent Observations", nil), @"class": [RecentObservationsViewController class] },
			                 @{ @"title": NSLocalizedString(@"Nearby Observations", nil), @"class": [NearbyObservationsViewController class] },
			                 @{ @"title": NSLocalizedString(@"Daily Summaries", nil), @"class": [DailySummariesViewController class] },
			                 @{ @"title": NSLocalizedString(@"Weekend Forecast", nil), @"class": [WeekendWeatherViewController class] },
			                 @{ @"title": NSLocalizedString(@"Sun & Moon", nil), @"class": [SunMoonViewController class] },
			                 @{ @"title": NSLocalizedString(@"Moon Phases", nil), @"class": [MoonPhasesViewController class] },
			                 @{ @"title": NSLocalizedString(@"Climate Normals", nil), @"class": [NormalsViewController class] },
			                 @{ @"title": NSLocalizedString(@"Today's Tides", nil), @"class": [TidesViewController class] },
			                 @{ @"title": NSLocalizedString(@"Indices", nil), @"class": [IndicesViewController class] },
							 @{ @"title": NSLocalizedString(@"Drought Monitor", nil), @"class": [DroughtMonitorViewController class] }
			];

			graphItems = @[@{ @"title": NSLocalizedString(@"Forecast (Line)", nil), @"class": [LineGraphsViewController_iPad class] },
			               @{ @"title": NSLocalizedString(@"Forecast (Bar)", nil), @"class": [BarGraphsViewController_iPad class] },
			               @{ @"title": NSLocalizedString(@"Forecast Models (Line)", nil), @"class": [ModelGraphsViewController_iPad class] }];
		} else {
			generalItems = @[@{ @"title": NSLocalizedString(@"Detailed Weather", nil), @"class": [DetailedWeatherViewController class] },
			                 @{ @"title": NSLocalizedString(@"Extended Forecast", nil), @"class": [ForecastViewController class] },
			                 @{ @"title": NSLocalizedString(@"Recent Observations", nil), @"class": [RecentObservationsViewController class] },
			                 @{ @"title": NSLocalizedString(@"Nearby Observations", nil), @"class": [NearbyObservationsViewController class] },
			                 @{ @"title": NSLocalizedString(@"Weekend Forecast", nil), @"class": [WeekendWeatherViewController class] },
			                 @{ @"title": NSLocalizedString(@"Daily Summaries", nil), @"class": [DailySummariesViewController class] },
			                 @{ @"title": NSLocalizedString(@"Sun & Moon", nil), @"class": [SunMoonViewController class] },
			                 @{ @"title": NSLocalizedString(@"Moon Phases", nil), @"class": [MoonPhasesViewController class] },
			                 @{ @"title": NSLocalizedString(@"Climate Normals", nil), @"class": [NormalsViewController class] },
			                 @{ @"title": NSLocalizedString(@"Today's Tides", nil), @"class": [TidesViewController class] },
			                 @{ @"title": NSLocalizedString(@"Indices", nil), @"class": [IndicesViewController class] },
							 @{ @"title": NSLocalizedString(@"Drought Monitor", nil), @"class": [DroughtMonitorViewController class] }
			];

			graphItems = @[@{ @"title": NSLocalizedString(@"Forecast (Line)", nil), @"class": [ForecastLineGraphsViewController class] },
			               @{ @"title": NSLocalizedString(@"Forecast (Bar)", nil), @"class": [ForecastBarGraphsViewController class] },
			               @{ @"title": NSLocalizedString(@"Recent Obs (Line)", nil), @"class": [RecentObsGraphViewController class] },
			               @{ @"title": NSLocalizedString(@"Daily Summary (Bar)", nil), @"class": [DailySummaryGraphsViewController class] },
			               @{ @"title": NSLocalizedString(@"Forecast Models (Line)", nil), @"class": [ModelGraphsViewController class] }];
		}

		NSArray *severeItems = @[@{ @"title": NSLocalizedString(@"Active Advisories", nil), @"class": [AdvisoriesViewController class] },
		                         @{ @"title": NSLocalizedString(@"Nearby Storm Cells", nil), @"class": [StormCellsViewController class] },
		                         @{ @"title": NSLocalizedString(@"Nearby Storm Reports", nil), @"class": [StormReportsViewController class] },
		                         @{ @"title": NSLocalizedString(@"Nearby Records", nil), @"class": [RecordsViewController class] },
		                         @{ @"title": NSLocalizedString(@"Nearby Earthquakes", nil), @"class": [EarthquakesViewController class] },
								 @{ @"title": NSLocalizedString(@"Nearby Threats", nil), @"class": [ThreatsViewController class] },
								 @{ @"title": NSLocalizedString(@"Convective Outlook", nil), @"class": [ConvectiveOutlookViewController class] },
								 @{ @"title": NSLocalizedString(@"Lightning Summary", nil), @"class": [LightningSummaryViewController class] },
								 @{ @"title": NSLocalizedString(@"Nearby Lightning Threats", nil), @"class": [LightningThreatsViewController class] },
								 @{ @"title": NSLocalizedString(@"Nearby Lightning Flashes", nil), @"class": [LightningFlashesViewController class] },
								 @{ @"title": NSLocalizedString(@"Nearby Lightning Strikes", nil), @"class": [LightningStrikesViewController class] },
		];

#if TARGET_OS_UIKITFORMAC
		NSArray *imageItems = @[
			@{ @"title": NSLocalizedString(@"Apple Map", nil), @"class": [AppleMapViewController class] }
		];
#else
		NSArray *imageItems = @[ //@{@"title": NSLocalizedString(@"Static Map Viewer", nil), @"class": [NSObject class]},
		    @{ @"title": NSLocalizedString(@"Apple Map", nil), @"class": [AppleMapViewController class] },
		    @{ @"title": NSLocalizedString(@"Google Map", nil), @"class": [GoogleMapViewController class] },
		    @{ @"title": NSLocalizedString(@"Mapbox Map", nil), @"class": [MapboxMapViewController class] }
		];
#endif

		self.categories = @[@{ @"title": NSLocalizedString(@"Locations", nil), @"items": locationItems },
		                    @{ @"title": NSLocalizedString(@"General Weather", nil), @"items": generalItems },
		                    @{ @"title": NSLocalizedString(@"Graphs", nil), @"items": graphItems },
		                    @{ @"title": NSLocalizedString(@"Severe Weather", nil), @"items": severeItems },
		                    @{ @"title": NSLocalizedString(@"Maps", nil), @"items": imageItems }
		];
	}

	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];

	self.title = NSLocalizedString(@"Catalog", nil);

	UITableView *tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
	tableView.translatesAutoresizingMaskIntoConstraints = NO;
	tableView.dataSource = self;
	tableView.delegate = self;
	[tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:cellIdentifier];
	[self.view addSubview:tableView];
	self.tableView = tableView;
	
	[NSLayoutConstraint activateConstraints:@[[tableView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
											  [tableView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [tableView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [tableView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor]]];
	
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];

	// if no default location set yet, just use the user's current location
	if (![[UserLocationsManager sharedManager] defaultLocation]) {
		__weak typeof(self) weakSelf = self;
		[AWFPlace getCurrentLocationWithCompletion:^(AWFPlace *place, NSError *error) {
		    if (error) {
		        NSLog(@"Failed to get current location! %@", error);
				[weakSelf showLocationSearch];
		        return;
			}

		    AWFWeatherRequestOptions *options = [AWFWeatherRequestOptions options];
		    options.limit = 1;
		    //options.filter = @"poi";

		    AWFPlaces *places = [[AWFPlaces alloc] init];
		    [places getClosestToPlace:place radius:@"10mi" options:options completion:^(AWFWeatherEndpointResult * _Nullable result) {
		        if (result.error) {
		            NSLog(@"Failed to get place from current location! %@", error);
					[weakSelf showLocationSearch];
		            return;
				}

		        NSArray *objects = result.results;
				if ([objects count] > 0) {
		            AWFPlace *place = (AWFPlace *)objects[0];
		            [[UserLocationsManager sharedManager] setDefaultLocation:place];
				}
			}];
		}];
	}
}

- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
}

- (void)showSettings {
	if (!self.settingsController) {
		SettingsViewController *settingsController = [[SettingsViewController alloc] initWithNibName:nil bundle:nil];
		self.settingsController = [[UINavigationController alloc] initWithRootViewController:settingsController];
		self.settingsController.modalPresentationStyle = UIModalPresentationFormSheet;
	}
	[self.navigationController presentViewController:self.settingsController animated:YES completion:nil];
}

- (void)showLocationSearch {
	if (!self.searchController) {
		self.searchController = [[LocationSearchViewController alloc] initWithNibName:nil bundle:nil];
	}
	[self.navigationController pushViewController:self.searchController animated:YES];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return [self.categories count];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return [(NSArray *)self.categories[section][@"items"] count];
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	return self.categories[section][@"title"];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier forIndexPath:indexPath];

	NSDictionary *rowItem = self.categories[indexPath.section][@"items"][indexPath.row];
	NSString *title = [rowItem objectForKey:@"title"];

	cell.textLabel.text = title;
	cell.textLabel.backgroundColor = [UIColor clearColor];
	cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;

	return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	NSDictionary *rowItem = self.categories[indexPath.section][@"items"][indexPath.row];
	Class rowClass = [rowItem objectForKey:@"class"];
	NSString *title = [rowItem objectForKey:@"title"];

	if (rowClass) {
		NSString *classKey = NSStringFromClass(rowClass);
		UIViewController *controller;

		// cache the controllers so they don't have to be recreated each time
		if ([self.controllerCache objectForKey:classKey]) {
			controller = [self.controllerCache objectForKey:classKey];
		} else {
			controller = [[rowClass alloc] initWithNibName:nil bundle:nil];
			controller.title = title;
			[self.controllerCache setObject:controller forKey:classKey];
		}

		// if presenting WeatherMapViewController on iPad, push it into the split view controller's master controller instead
		if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad && ([[rowClass class] isSubclassOfClass:[DetailedWeatherViewController_iPad class]] ||
																	 [[rowClass class] isSubclassOfClass:[MapViewController class]] ||
		                                                             [[rowClass class] isSubclassOfClass:[LineGraphsViewController_iPad class]] ||
		                                                             [[rowClass class] isSubclassOfClass:[BarGraphsViewController_iPad class]] ||
		                                                             [[rowClass class] isSubclassOfClass:[ModelGraphsViewController_iPad class]])) {
			if (self.splitViewController) {
				[self.splitViewController showDetailViewController:[[UINavigationController alloc] initWithRootViewController:controller] sender:nil];
				self.splitViewController.preferredDisplayMode = UISplitViewControllerDisplayModePrimaryHidden;
			}

			if ([self.delegate respondsToSelector:@selector(catalogViewControllerDidSelectDetailItem:)]) {
				[self.delegate catalogViewControllerDidSelectDetailItem:self];
			}
		} else {
			[self.navigationController pushViewController:controller animated:YES];
		}
	}
	
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
}

@end
