//
//  GroupedListingViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "GroupedListingViewController.h"
#import "GroupedTableViewCell.h"
#import "ListingEventView.h"

@interface GroupedListingViewController ()

@end

static NSString *cellIdentifier = @"GroupedListingCellIdentifier";

@implementation GroupedListingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	if (self.tableView) {
		[self.tableView removeFromSuperview];
	}
	
	UITableView *tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
	tableView.autoresizingMask = UIViewAutoresizingFlexibleHeight;
	tableView.dataSource = self;
	tableView.delegate = self;
	tableView.rowHeight = 40.0;
	[self.view insertSubview:tableView belowSubview:self.eventView];
	
	[tableView registerClass:[GroupedTableViewCell class] forCellReuseIdentifier:cellIdentifier];
	
	self.tableView = tableView;
}

#pragma mark - Public

- (void)loadDataForPlace:(AWFPlace *)place options:(AWFRequestOptions *)options {
	if (self.loader) {
		[self.eventView showLoading];
		
		__weak typeof(self) weakSelf = self;
		[self.loader getForPlace:place options:options completion:^(NSArray *objects, NSError *error) {
			if (error) {
				NSLog(@"Listing data failed to load! %@", error);
				[weakSelf.eventView showMessage:NSLocalizedString(@"An error occurred during the request.", nil)];
				return;
			}
			
			if ([objects count] > 0) {
				// reduce results down if first object contains a `periods` property
				AWFObject *object = objects[0];
				if ([object isKindOfClass:[AWFNormal class]]) {
					objects = ((AWFNormal *)object).periods;
				}
				
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

- (NSString *)cellIdentifierForIndexPath:(NSIndexPath *)indexPath {
	return cellIdentifier;
}

#pragma mark - UITableViewDataSource 

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return [self.results count];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	NSString *identifier = [self cellIdentifierForIndexPath:indexPath];
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier forIndexPath:indexPath];
	[self handleConfigurationOfCell:cell forIndexPath:indexPath];
	
	return cell;
}

@end
