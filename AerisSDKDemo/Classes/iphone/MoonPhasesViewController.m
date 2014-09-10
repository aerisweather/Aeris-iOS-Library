//
//  MoonPhasesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "MoonPhasesViewController.h"
#import "ListingEventView.h"
#import "GroupedTableViewCell.h"

@interface MoonPhasesViewController ()
@property (nonatomic, strong) AWFMoonPhasesLoader *loader;
@end

@implementation MoonPhasesViewController

@synthesize loader;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.loader = [[AWFMoonPhasesLoader alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = NSLocalizedString(@"Moon Phases", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.limit = 4;
	
	[self loadDataForPlace:place options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	AWFMoonPhase *report = (AWFMoonPhase *)[self.results objectAtIndex:indexPath.section];
	
	// set global NSDateFormatter timezone to local time
	[NSDate awf_setDefaultTimezone:report.timeZone];
	
	switch (indexPath.row) {
		case 0:
			groupedCell.descriptionLabel.text = @"Date";
			groupedCell.valueLabel.text = [report.timestamp awf_stringWithFormat:@"M/d/y"];
			break;
		case 1:
			groupedCell.descriptionLabel.text = @"Phase";
			groupedCell.valueLabel.text = [report.name capitalizedString];
			break;
	}
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 2;
}

@end
