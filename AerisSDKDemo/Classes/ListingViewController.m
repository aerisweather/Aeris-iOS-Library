//
//  CommonTableViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "ListingViewController.h"
#import "ListingEventView.h"
#import "ListingTableViewCell.h"

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
	
	UITableView *tableView = [[UITableView alloc] initWithFrame:self.view.bounds];
	tableView.autoresizingMask = UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleWidth;
	tableView.dataSource = self;
	tableView.delegate = self;
	tableView.rowHeight = 56.0;
	[self.view addSubview:tableView];
	
	[tableView registerClass:[ListingTableViewCell class] forCellReuseIdentifier:cellIdentifier];
	
	ListingEventView *eventView = [[ListingEventView alloc] initWithFrame:tableView.frame];
	eventView.alpha = 0;
	[self.view addSubview:eventView];
	
	
	self.tableView = tableView;
	self.eventView = eventView;
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	[self.eventView showLoading];
}

#pragma mark - Public

- (void)loadDataClosestToPlace:(AWFPlace *)place radius:(NSString *)radius options:(AWFRequestOptions *)options {
	if (self.loader) {
		[self.eventView showLoading];
		
		__weak typeof(self) weakSelf = self;
		[self.loader getClosestToPlace:place radius:radius options:options completion:^(NSArray *objects, NSError *error) {
			if (error) {
				NSLog(@"Listing data failed to load! %@", error);
				[weakSelf.eventView showMessage:NSLocalizedString(@"An error occurred during the request.", nil)];
				return;
			}
			
			if ([objects count] > 0) {
				weakSelf.results = objects;
				[weakSelf.tableView reloadData];
				[weakSelf.eventView hide];
			}
			else {
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
