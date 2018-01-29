//
//  MoonPhasesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "MoonPhasesViewController.h"

@interface MoonPhasesViewController ()
@property (nonatomic, strong) AWFMoonPhases *endpoint;
@end

@implementation MoonPhasesViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.endpoint = [[AWFMoonPhases alloc] init];
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
	
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.limit = 4;
	
	[self loadDataForPlace:place options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	AWFMoonPhase *report = (AWFMoonPhase *)[self.results objectAtIndex:indexPath.section];
	
	switch (indexPath.row) {
		case 0:
			groupedCell.titleLabel.text = @"Date";
			groupedCell.valueLabel.text = [report.timestamp awf_formattedDateWithFormat:@"M/d/y" timeZone:report.timeZone];
			break;
		case 1:
			groupedCell.titleLabel.text = @"Phase";
			groupedCell.valueLabel.text = [report.name capitalizedString];
			break;
	}
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 2;
}

@end
