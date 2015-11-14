//
//  LocationSearchViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "LocationSearchViewController.h"

NSString * const kAWFDemoDefaultPlaceChanged = @"AWFDemoDefaultPlaceChanged";

@interface LocationSearchViewController ()
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) AWFPlacesLoader *placesLoader;
@property (nonatomic, strong) NSArray *results;
@property (nonatomic, strong) NSArray *geoResults;
@property (nonatomic, strong) NSMutableArray *searchResults;
@property (nonatomic, strong) UISearchDisplayController *searchController;
- (void)searchUsingCurrentLocation:(id)sender;
- (void)searchWithString:(NSString *)searchValue;
@end

static NSString *cellIdentifier = @"LocationCellIdentifier";

@implementation LocationSearchViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.placesLoader = [[AWFPlacesLoader alloc] init];
		self.searchResults = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	// button to allow seaching for locations based on current geolocation of user
	self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"Locate", nil)
																			  style:UIBarButtonItemStyleBordered
																			 target:self action:@selector(searchUsingCurrentLocation:)];
	
	UITableView *tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
	tableView.autoresizingMask = UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleWidth;
	tableView.dataSource = self;
	tableView.delegate = self;
	[self.view addSubview:tableView];
	
	UISearchBar *searchBar = [[UISearchBar alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(self.view.frame), 0)];
	searchBar.autoresizingMask = UIViewAutoresizingFlexibleWidth;
	searchBar.delegate = self;
	[searchBar sizeToFit];
	tableView.tableHeaderView = searchBar;
	
	UISearchDisplayController *searchController = [[UISearchDisplayController alloc] initWithSearchBar:searchBar contentsController:self];
	searchController.delegate = self;
	searchController.searchResultsDataSource = self;
	searchController.searchResultsDelegate = self;
	[searchController.searchResultsTableView registerClass:[UITableViewCell class] forCellReuseIdentifier:cellIdentifier];
	
	self.tableView = tableView;
	self.searchController = searchController;
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	// populate results with previously saved locations from NSUserDefaults via UserLocationsManager
	self.results = [UserLocationsManager sharedManager].locations;
	[self.tableView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
}

#pragma mark - Private

- (void)searchUsingCurrentLocation:(id)sender {
	__weak typeof(self) weakSelf = self;
	[AWFPlace getCurrentLocationWithCompletion:^(AWFPlace *place, NSError *error) {
		if (error) {
			NSLog(@"Failed to get current location! %@", error);
			return;
		}
		
		AWFRequestOptions *options = [AWFRequestOptions options];
		options.limit = 25;
		//options.filter = @"poi";
		
		[weakSelf.placesLoader getClosestToPlace:place radius:@"10mi" options:options completion:^(NSArray *objects, NSError *error) {
			if (error) {
				NSLog(@"Failed to get place from current location! %@", error);
				return;
			}
			
			weakSelf.geoResults = objects;
			[weakSelf.tableView reloadData];
		}];
	}];
}

- (void)searchWithString:(NSString *)searchValue {
	NSArray *parts = [searchValue componentsSeparatedByString:@","];
	
	__weak typeof(self) weakSelf = self;
	AWFPlace *place;
	AWFRequestOptions *options = [AWFRequestOptions options];
	options.limit = 1;
	
	if (AWFIsValidCoordinateString(searchValue)) {
		CGFloat lat = [[[parts objectAtIndex:0] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] floatValue];
		CGFloat lon = [[[parts objectAtIndex:1] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] floatValue];
		place = [AWFPlace placeWithLatitude:lat longitude:lon];
		
		[self.placesLoader getClosestToPlace:place radius:@"50mi" options:options completion:^(NSArray *objects, NSError *error) {
			if (error) {
				NSLog(@"Places search based on coordinate failed! %@", error);
				return;
			}
			
			weakSelf.searchResults = [NSMutableArray arrayWithArray:objects];
			[weakSelf.searchController.searchResultsTableView reloadData];
		}];
	}
	else if (AWFIsValidZipcodeString(searchValue)) {
		NSString *zipcode = [searchValue stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
		[self.placesLoader searchForPlaceWithZipcode:zipcode options:options completion:^(NSArray *objects, NSError *error) {
			if (error) {
				NSLog(@"Places search based on zip code failed! %@", error);
				return;
			}
			
			weakSelf.searchResults = [NSMutableArray arrayWithArray:objects];
			[weakSelf.searchController.searchResultsTableView reloadData];
		}];
	}
	else if (!AWFIsNumber(searchValue) && AWFIsValidPlaceString(searchValue)) {
		
		options.limit = 50;
		options.filterString = @"poi";
		options.sort = [NSString stringWithFormat:@"pop:%li", (long)AWFRequestSortDescending];
		
		if ([parts count] == 1) {
			// do a "starts with" search since it's just a name
			[self.placesLoader searchForPlaceWithNameStartingWith:[searchValue lowercaseString] options:options completion:^(NSArray *objects, NSError *error) {
				if (error) {
					NSLog(@"Places search based on name starts with failed! %@", error);
					return;
				}
				
				weakSelf.searchResults = [NSMutableArray arrayWithArray:objects];
				[weakSelf.searchController.searchResultsTableView reloadData];
			}];
		}
		else {
			NSString *name = [[parts objectAtIndex:0] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
			NSString *state = ([parts count] > 1) ? [[parts objectAtIndex:1] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] : nil;
			NSString *country = ([parts count] > 2) ? [[parts objectAtIndex:2] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] : nil;
			
			// if state or country are only one letter, do a "starts with" query for those
			if (state.length == 1) {
				state = [NSString stringWithFormat:@"^%@", state];
			}
			if (country.length == 1) {
				country = [NSString stringWithFormat:@"^%@", country];
			}
			
			[self.placesLoader searchForPlaceWithName:[name lowercaseString] state:[state lowercaseString] country:[country lowercaseString]
											  options:options completion:^(NSArray *objects, NSError *error)
			{
				if (error) {
					NSLog(@"Places search based on name failed! %@", error);
					return;
				}
				
				weakSelf.searchResults = [NSMutableArray arrayWithArray:objects];
				[weakSelf.searchController.searchResultsTableView reloadData];
			}];
		}
	}
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return (([self.geoResults count] > 0) ? 2 : 1);
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	if (tableView != self.searchController.searchResultsTableView) {
		if (section == 0) {
			return NSLocalizedString(@"Saved Locations", nil);
		}
		else if (section == 1) {
			return NSLocalizedString(@"Nearby Locations", nil);
		}
	}
	return nil;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	if (tableView == self.searchController.searchResultsTableView) {
		return [self.searchResults count];
	}
	else {
		if (section == 0) {
			return [self.results count];
		}
		else if (section == 1) {
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
		}
		else {
			cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
		}
	}
	
	AWFPlace *place;
	if (tableView == self.searchController.searchResultsTableView) {
		place = (AWFPlace *)self.searchResults[indexPath.row];
	}
	else {
		if (indexPath.section == 0) {
			// places stored in `results` are dictionarys from NSUserDefaults, so convert back to AWFPlace instances
			place = (AWFPlace *)self.results[indexPath.row];
		}
		else {
			place = (AWFPlace *)self.geoResults[indexPath.row];
		}
	}
	
	NSString *country = ([place.country isEqualToString:@"US"] == NO && place.countryFull != nil) ? place.countryFull : place.country;
	NSString *state = (AWFIsNonEmptyString(place.state)) ? place.state : country;
	//NSString* country = (AWFIsNonEmptyString(place.state)) ? [NSString stringWithFormat:@", %@", place.country] : @"";
	country = (AWFIsNonEmptyString(place.state)) ? [NSString stringWithFormat:@", %@", country] : @"";
	
	cell.textLabel.text = [NSString stringWithFormat:@"%@, %@%@", place.name, state, country];
	
	if (indexPath.section == 1) {
		cell.detailTextLabel.text = [NSString stringWithFormat:@"%.2f mi away", [place.relativeTo.distanceMI floatValue]];
	}
	
	// show accessory mark if this location is the user's default one
	if ([[UserLocationsManager sharedManager] defaultLocation]) {
		AWFPlace *defaultPlace = [[UserLocationsManager sharedManager] defaultLocation];
		if ([defaultPlace.name isEqualToString:place.name]
			&& [defaultPlace.state isEqualToString:place.state]
			&& [defaultPlace.country isEqualToString:place.country])
		{
			cell.accessoryType = UITableViewCellAccessoryCheckmark;
		}
		else {
			cell.accessoryType = UITableViewCellAccessoryNone;
		}
	}
	
	return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	// store this location as the active one for all weather views
	AWFPlace *place;
	if (tableView == self.searchDisplayController.searchResultsTableView) {
		place = (AWFPlace *)self.searchResults[indexPath.row];
		
		// only add this place if it doesn't already exist in user prefs
		if (![[UserLocationsManager sharedManager] containsLocation:place]) {
			[[UserLocationsManager sharedManager] saveLocation:place];
			// update the locations array for the table view
			self.results = [UserLocationsManager sharedManager].locations;
			
			// end searching
			self.searchController.active = NO;
		}
	}
	else {
		if (indexPath.section == 0) {
			place = (AWFPlace *)self.results[indexPath.row];
		}
		else if (indexPath.section == 1) {
			place = (AWFPlace *)self.geoResults[indexPath.row];
		}
	}
	
	// set location as their current default location
	[[UserLocationsManager sharedManager] setDefaultLocation:place];
	[self.tableView reloadData];
	
	// trigger notification that our default location changed (mainly to force iPad view to update)
	NSDictionary *userInfo = (place) ? @{@"place": place} : nil;
	[[NSNotificationCenter defaultCenter] postNotificationName:kAWFDemoDefaultPlaceChanged object:self userInfo:userInfo];
	
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
	// return to previous view now that the location has been set
	//[self.navigationController popViewControllerAnimated:YES];
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
	return (tableView != self.searchController.searchResultsTableView && indexPath.section == 0);
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
	if (tableView != self.searchController.searchResultsTableView) {
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

#pragma mark - UISearchBarDelegate

- (void)searchBarTextDidBeginEditing:(UISearchBar *)searchBar {
	[self.searchResults removeAllObjects];
	[self.searchController.searchResultsTableView reloadData];
}

- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText {
	if (searchText.length >= 3) {
		[self.placesLoader cancel];
		[self searchWithString:searchText];
	}
	else {
		[self.searchResults removeAllObjects];
		[self.searchController.searchResultsTableView reloadData];
	}
}

- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar {
	[self searchWithString:searchBar.text];
}

@end
