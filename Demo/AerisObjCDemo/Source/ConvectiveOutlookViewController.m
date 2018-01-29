//
//  ConvectiveOutlookViewController.m
//  AerisDemo
//
//  Created by Nicholas Shipes on 11/9/15.
//  Copyright © 2015 HAMweather, LLC. All rights reserved.
//

#import "ConvectiveOutlookViewController.h"

@interface ConvectiveOutlookViewController ()
@property (strong, nonatomic) AWFConvectiveOutlooks *endpoint;
@end

@implementation ConvectiveOutlookViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.endpoint = [[AWFConvectiveOutlooks alloc] init];
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
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.filterString = AWFConvectiveOutlookFilterAllHazards;
	options.fromDateString = @"today";
	options.toDateString = @"+7days";
	options.sort = @"day";
	self.place = place;
	
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
			value = [outlook.startDate awf_formattedDateWithFormat:@"M/d/y" timeZone:self.place.timeZone];
			break;
		}
		case 1: {
			label = NSLocalizedString(@"Risk Name", nil);
			value = [outlook.riskName capitalizedString];
			break;
		}
		case 2: {
			label = NSLocalizedString(@"Risk Code", nil);
			value = [NSString stringWithFormat:@"%li", outlook.riskCode];
			break;
		}
		default: {
			break;
		}
	}
	
	groupedCell.titleLabel.text = label;
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
