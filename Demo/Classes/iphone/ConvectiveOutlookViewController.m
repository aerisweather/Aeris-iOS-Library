//
//  ConvectiveOutlookViewController.m
//  AerisDemo
//
//  Created by Nicholas Shipes on 11/9/15.
//  Copyright © 2015 HAMweather, LLC. All rights reserved.
//

#import "ConvectiveOutlookViewController.h"
#import "GroupedTableViewCell.h"

@interface ConvectiveOutlookViewController ()
@property (strong, nonatomic) AWFConvectiveOutlooksLoader *loader;
@end

@implementation ConvectiveOutlookViewController

@synthesize loader;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.loader = [[AWFConvectiveOutlooksLoader alloc] init];
	}
	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];
	
	self.title = NSLocalizedString(@"Convective Outlook", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.filterString = AWFConvectiveOutlookFilterAllHazards;
	options.fromDateString = @"today";
	options.toDateString = @"+7days";
	options.sort = @"day";
	
	[self loadDataForPlace:place options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	AWFConvectiveOutlook *outlook = [self.results objectAtIndex:indexPath.section];
	
	NSString *label;
	NSString *value;
	
	switch (indexPath.row) {
		case 0: {
			label = NSLocalizedString(@"Date", nil);
			value = [outlook.startDate awf_stringWithFormat:@"M/d/y"];
			break;
		}
		case 1: {
			label = NSLocalizedString(@"Risk Name", nil);
			value = [outlook.riskName capitalizedString];
			break;
		}
		case 2: {
			label = NSLocalizedString(@"Risk Code", nil);
			value = [NSString stringWithFormat:@"%@", outlook.riskCode];
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
