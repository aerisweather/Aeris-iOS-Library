//
//  CommonTableViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "ListingViewController.h"

@interface ListingViewController ()

@end

static NSString *cellIdentifier = @"ListingCellIdentifier";

@implementation ListingViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.results = [[NSArray alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	UITableView *tableView = [UITableView new];
	tableView.translatesAutoresizingMaskIntoConstraints = NO;
	tableView.dataSource = self;
	tableView.delegate = self;
	tableView.rowHeight = 56.0;
	[tableView registerClass:[ListingTableViewCell class] forCellReuseIdentifier:cellIdentifier];
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
	[self.eventView showLoading];
}

#pragma mark - Public

- (void)loadDataClosestToPlace:(AWFPlace *)place radius:(NSString *)radius options:(AWFWeatherRequestOptions *)options {
	if (self.endpoint) {
		[self.eventView showLoading];
		
		__weak typeof(self) weakSelf = self;
		[self.endpoint getClosestToPlace:place radius:radius options:options completion:^(AWFWeatherEndpointResult * _Nullable result) {
			if (result.error) {
				NSLog(@"Listing data failed to load! %@", result.error);
				[weakSelf.eventView showMessage:NSLocalizedString(@"An error occurred during the request.", nil)];
				return;
			}
			
			NSArray *objects = result.results;
			if ([objects count] > 0) {
				weakSelf.results = objects;
				[weakSelf.tableView reloadData];
				[weakSelf.eventView hide];
			} else {
				weakSelf.results = @[];
				[weakSelf.eventView showNoResultsMessage];
			}
			
			[weakSelf dataDidFinishLoading];
		}];
	}
}

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	// subclassing controllers should override to provide necessary functionality
}

- (void)handleCellSelectionForIndexPath:(NSIndexPath *)indexPath {
	// subclassing controllers should override to provide necessary functionality
}

- (void)dataDidFinishLoading {
	// subclassing controllers should override to provide necessary functionality
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return [self.results count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	ListingTableViewCell *cell = (ListingTableViewCell *)[tableView dequeueReusableCellWithIdentifier:cellIdentifier forIndexPath:indexPath];
	[self handleConfigurationOfCell:cell forIndexPath:indexPath];
	
	return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	[self handleCellSelectionForIndexPath:indexPath];
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
}

@end
