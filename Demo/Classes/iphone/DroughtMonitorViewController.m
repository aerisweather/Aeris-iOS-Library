//
//  DroughtMonitorViewController.m
//  AerisDemo
//
//  Created by Nicholas Shipes on 11/11/15.
//  Copyright © 2015 HAMweather, LLC. All rights reserved.
//

#import "DroughtMonitorViewController.h"
#import "GroupedTableViewCell.h"

@interface DroughtMonitorViewController ()
@property (strong, nonatomic) AWFDroughtIndicesLoader *loader;
@end

@implementation DroughtMonitorViewController

@synthesize loader;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.loader = [[AWFDroughtIndicesLoader alloc] init];
	}
	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];
	
	self.title = NSLocalizedString(@"Drought Monitor", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.filterString = AWFDroughtIndexFilterAll;
	
	[self loadDataForPlace:place options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	AWFDroughtIndex *index = [self.results objectAtIndex:indexPath.section];
	
	NSString *label;
	NSString *value;
	
	switch (indexPath.row) {
		case 0: {
			label = NSLocalizedString(@"Date Range", nil);
			value = [NSString stringWithFormat:@"%@-%@", [index.startDate awf_stringWithFormat:@"M/d/y"], [index.endDate awf_stringWithFormat:@"M/d/y"]];
			break;
		}
		case 1: {
			label = NSLocalizedString(@"Index Name", nil);
			value = index.riskName;
			break;
		}
		case 2: {
			label = NSLocalizedString(@"Index Code", nil);
			value = [NSString stringWithFormat:@"%@", index.riskCode];
			break;
		}
		default: {
			break;
		}
	}
	
	groupedCell.descriptionLabel.text = label;
	groupedCell.valueLabel.text = value;
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return [self.results count];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 3;
}

@end
