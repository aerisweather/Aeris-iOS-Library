//
//  GroupedListingViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "GroupedListingViewController.h"

@interface GroupedListingViewController ()

@end

static NSString *cellIdentifier = @"GroupedListingCellIdentifier";

@implementation GroupedListingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	if (self.tableView) {
		[self.tableView removeFromSuperview];
	}
	if (self.eventView) {
		[self.eventView removeFromSuperview];
	}
	
	UITableView *tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
	tableView.translatesAutoresizingMaskIntoConstraints = NO;
	tableView.dataSource = self;
	tableView.delegate = self;
	tableView.rowHeight = 40.0;
	[tableView registerClass:[GroupedTableViewCell class] forCellReuseIdentifier:cellIdentifier];
	[self.view addSubview:tableView];
	self.tableView = tableView;
	
	[self.view addSubview:self.eventView];
	
	[NSLayoutConstraint activateConstraints:@[[tableView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
											  [tableView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [tableView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [tableView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
											  [self.eventView.topAnchor constraintEqualToAnchor:tableView.topAnchor],
											  [self.eventView.leftAnchor constraintEqualToAnchor:tableView.leftAnchor],
											  [self.eventView.rightAnchor constraintEqualToAnchor:tableView.rightAnchor],
											  [self.eventView.bottomAnchor constraintEqualToAnchor:tableView.bottomAnchor]]];
}

#pragma mark - Public

- (void)loadDataForPlace:(AWFPlace *)place options:(AWFWeatherRequestOptions *)options {
	if (self.endpoint) {
		[self.eventView showLoading];
		
		__weak typeof(self) weakSelf = self;
		[self.endpoint getForPlace:place options:options completion:^(AWFWeatherEndpointResult * _Nullable result) {
			if (result.error) {
				NSLog(@"Listing data failed to load! %@", result.error);
				[weakSelf.eventView showMessage:NSLocalizedString(@"An error occurred during the request.", nil)];
				return;
			}
			
			if ([result.results count] > 0) {
				NSArray *objects = result.results;
				
				// reduce results down if first object contains a `periods` property
				AWFWeatherObject *object = objects[0];
				if ([object isKindOfClass:[AWFNormal class]]) {
					objects = ((AWFNormal *)object).periods;
				}
				
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
