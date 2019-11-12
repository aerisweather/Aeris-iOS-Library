//
//  LocationSearchViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "LocationSearchViewController.h"

NSString * const kAWFDemoDefaultPlaceChanged = @"AWFDemoDefaultPlaceChanged";

@interface LocationSearchViewController () <UISearchResultsUpdating>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) AWFPlaces *places;
@property (nonatomic, strong) NSArray *results;
@property (nonatomic, strong) NSArray *geoResults;
@property (nonatomic, strong) NSMutableArray *searchResults;
@property (nonatomic, strong) UISearchController *searchController;
@property (nonatomic, strong) UITableViewController *searchResultsController;
@end

static NSString *cellIdentifier = @"LocationCellIdentifier";

@implementation LocationSearchViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.places = [[AWFPlaces alloc] init];
		self.searchResults = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.extendedLayoutIncludesOpaqueBars = YES;
	self.definesPresentationContext = YES;
	
	// button to allow seaching for locations based on current geolocation of user
	self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"Locate", nil)
																			  style:UIBarButtonItemStylePlain
																			 target:self action:@selector(searchUsingCurrentLocation:)];
	
	UITableView *tableView = [UITableView new];
	tableView.translatesAutoresizingMaskIntoConstraints = NO;
	tableView.dataSource = self;
	tableView.delegate = self;
	[self.view addSubview:tableView];
	self.tableView = tableView;
	
	UITableViewController *searchResultsController = [[UITableViewController alloc] initWithStyle:UITableViewStylePlain];
	searchResultsController.tableView.dataSource = self;
	searchResultsController.tableView.delegate = self;
	if (@available(iOS 11.0, *)) {
		searchResultsController.tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
	}
	
	UISearchController *searchController = [[UISearchController alloc] initWithSearchResultsController:searchResultsController];
	searchController.searchResultsUpdater = self;
	searchController.hidesNavigationBarDuringPresentation = NO;
	[searchResultsController.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:cellIdentifier];
	tableView.tableHeaderView = searchController.searchBar;
	self.searchController = searchController;
	self.searchResultsController = searchResultsController;
	
	[NSLayoutConstraint activateConstraints:@[[tableView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
											  [tableView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [tableView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [tableView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor]]];
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	// populate results with previously saved locations from NSUserDefaults via UserLocationsManager
	self.results = [UserLocationsManager sharedManager].locations;
	[self.tableView reloadData];
}

#pragma mark - Private

- (BOOL)isSearching {
	return self.searchController.isActive && [self.searchController.searchBar.text awf_isEmpty];
}

- (void)searchUsingCurrentLocation:(id)sender {
	__weak typeof(self) weakSelf = self;
	[AWFPlace getCurrentLocationWithCompletion:^(AWFPlace *place, NSError *error) {
		if (error) {
			NSLog(@"Failed to get current location! %@", error);
			return;
		}
		
		AWFWeatherRequestOptions *options = [AWFWeatherRequestOptions options];
		options.limit = 25;
		//options.filter = @"poi";
		
		[weakSelf.places getClosestToPlace:place radius:@"10mi" options:options completion:^(AWFWeatherEndpointResult * _Nullable result) {
			if (result.error) {
				NSLog(@"Failed to get place from current location! %@", error);
				return;
			}
			
			weakSelf.geoResults = result.results;
			[weakSelf.tableView reloadData];
		}];
	}];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return (([self.geoResults count] > 0) ? 2 : 1);
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	if (tableView != self.searchResultsController.tableView) {
		if (section == 0) {
			return NSLocalizedString(@"Saved Locations", nil);
		} else if (section == 1) {
			return NSLocalizedString(@"Nearby Locations", nil);
		}
	}
	return nil;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	if (tableView == self.searchResultsController.tableView) {
		return [self.searchResults count];
	} else {
		if (section == 0) {
			return [self.results count];
		} else if (section == 1) {
			return [self.geoResults count];
		}
	}
	
	return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	static NSString *geoCellIdentifier = @"GeoCellIdentifier";
	NSString *identifier = (indexPath.section == 1) ? geoCellIdentifier : cellIdentifier;

	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
	if (!cell) {
		if (tableView == self.tableView && indexPath.section == 1) {
			cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:identifier];
		} else {
			cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
		}
	}
	
	AWFPlace *place;
	if (tableView == self.searchResultsController.tableView) {
		place = (AWFPlace *)self.searchResults[indexPath.row];
	} else {
		if (indexPath.section == 0) {
			// places stored in `results` are dictionarys from NSUserDefaults, so convert back to AWFPlace instances
			place = (AWFPlace *)self.results[indexPath.row];
		} else {
			place = (AWFPlace *)self.geoResults[indexPath.row];
		}
	}
	
	NSString *country = ([place.country isEqualToString:@"US"] == NO && place.countryFull != nil) ? place.countryFull : place.country;
	NSString *state = (AWFIsNonEmptyString(place.state)) ? place.state : country;
	//NSString* country = (AWFIsNonEmptyString(place.state)) ? [NSString stringWithFormat:@", %@", place.country] : @"";
	country = (AWFIsNonEmptyString(place.state)) ? [NSString stringWithFormat:@", %@", country] : @"";
	
	cell.textLabel.text = [NSString stringWithFormat:@"%@, %@%@", place.name, state, country];
	
	if (indexPath.section == 1) {
		cell.detailTextLabel.text = [NSString stringWithFormat:@"%.2f mi away", place.relativeTo.distanceMI];
	}
	
	// show accessory mark if this location is the user's default one
	if ([[UserLocationsManager sharedManager] defaultLocation]) {
		AWFPlace *defaultPlace = [[UserLocationsManager sharedManager] defaultLocation];
		if ([defaultPlace.name isEqualToString:place.name]
			&& [defaultPlace.state isEqualToString:place.state]
			&& [defaultPlace.country isEqualToString:place.country])
		{
			cell.accessoryType = UITableViewCellAccessoryCheckmark;
		} else {
			cell.accessoryType = UITableViewCellAccessoryNone;
		}
	}
	
	return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	// store this location as the active one for all weather views
	AWFPlace *place;
	if (tableView == self.searchResultsController.tableView) {
		place = (AWFPlace *)self.searchResults[indexPath.row];
		
		// only add this place if it doesn't already exist in user prefs
		if (![[UserLocationsManager sharedManager] containsLocation:place]) {
			[[UserLocationsManager sharedManager] saveLocation:place];
			// update the locations array for the table view
			self.results = [UserLocationsManager sharedManager].locations;
			
			// end searching
			self.searchController.active = NO;
		}
	} else {
		if (indexPath.section == 0) {
			place = (AWFPlace *)self.results[indexPath.row];
		} else if (indexPath.section == 1) {
			place = (AWFPlace *)self.geoResults[indexPath.row];
		}
	}
	
	// set location as their current default location
	[[UserLocationsManager sharedManager] setDefaultLocation:place];
	[self.tableView reloadData];
	
	// trigger notification that our default location changed (mainly to force iPad view to update)
	NSDictionary *userInfo = (place) ? @{@"pinlace": place} : nil;
	[[NSNotificationCenter defaultCenter] postNotificationName:kAWFDemoDefaultPlaceChanged object:self userInfo:userInfo];
	
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
	// return to previous view now that the location has been set
	//[self.navigationController popViewControllerAnimated:YES];
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
	return (tableView != self.searchResultsController.tableView && indexPath.section == 0);
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
	if (tableView != self.searchResultsController.tableView) {
		if (editingStyle == UITableViewCellEditingStyleDelete) {
			AWFPlace *placeToDelete = (AWFPlace *)[self.results objectAtIndex:indexPath.row];
			[[UserLocationsManager sharedManager] removeLocation:placeToDelete];
			
			// update local locations array
			self.results = [UserLocationsManager sharedManager].locations;
			[tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
			[tableView reloadData];
		}
	}
}

#pragma mark - UISearchResultsUpdating

typedef void (^AWFDebounceFunction)(void);
AWFDebounceFunction AWFDebounce(double delay, dispatch_queue_t queue, dispatch_block_t block) {
//	dispatch_source_t timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue);
//
//	if (timer) {
//		dispatch_source_set_timer(timer, dispatch_time(DISPATCH_TIME_NOW, delay * NSEC_PER_SEC), DISPATCH_TIME_FOREVER, (1ull * NSEC_PER_SEC) / 10);
//		dispatch_source_set_event_handler(timer, block);
//		dispatch_resume(timer);
//	}
//
//	return timer;
	
	__block dispatch_time_t lastFireTime = 0;
	__block int64_t dispatchDelay = (int64_t)delay * NSEC_PER_SEC;
	
	void (^debounceTrigger)(void) = ^{
		lastFireTime = dispatch_time(DISPATCH_TIME_NOW, 0);
		dispatch_after(dispatch_time(DISPATCH_TIME_NOW, dispatchDelay), queue, ^{
			int64_t now = dispatch_time(DISPATCH_TIME_NOW, 0);
			int64_t when = dispatch_time(lastFireTime, dispatchDelay);
			if (now >= when) {
				block();
			}
		});
	};
	
	return debounceTrigger;
}

- (void)updateSearchResultsForSearchController:(UISearchController *)searchController {
	if (searchController.searchBar.text.length >= 3) {
		[self.places cancel];
		
		static AWFDebounceFunction _debounce = nil;
		if (!_debounce) {
			__weak typeof(self) weakSelf = self;
			dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
			_debounce = AWFDebounce(1.0, queue, ^{
				dispatch_async(dispatch_get_main_queue(), ^{
					NSString *query = searchController.searchBar.text;
					[weakSelf.places searchUsingString:query options:nil completion:^(AWFWeatherEndpointResult * _Nullable result) {
						if (result.error) {
							NSLog(@"Location search failed - %@", result.error);
							return;
						}
						
						NSArray *objects = (result.results) ? result.results : @[];
						weakSelf.searchResults = [NSMutableArray arrayWithArray:objects];
						[weakSelf.searchResultsController.tableView reloadData];
					}];
				});
			});
		}
		
		_debounce();

	} else {
		[self.searchResults removeAllObjects];
		[self.searchResultsController.tableView reloadData];
	}
}

@end
