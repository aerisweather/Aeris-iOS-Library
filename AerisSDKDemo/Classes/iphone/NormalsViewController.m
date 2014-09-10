//
//  NormalsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "NormalsViewController.h"
#import "ListingEventView.h"
#import "GroupedTableViewCell.h"

@interface NormalsViewController ()
@property (nonatomic, strong) AWFNormalsLoader *loader;
@end

@implementation NormalsViewController

@synthesize loader;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.loader = [[AWFNormalsLoader alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = NSLocalizedString(@"Climate Normals", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.periodLimit = 2;
	options.toDateString = @"+1 day";
	
	[self loadDataForPlace:place options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	AWFNormalPeriod *period = (AWFNormalPeriod *)[self.results objectAtIndex:indexPath.section];
	
	NSString *label = @"";
	NSString *value = @"";
	
	switch (indexPath.row) {
		case 0:
			label = @"Date";
			value = [NSString stringWithFormat:@"%i/%i", [period.month intValue], [period.date intValue]];
			break;
		case 1:
			label = @"High Temp";
			value = [NSString stringWithFormat:@"%i%@", [period.tempMaxF intValue], AWFDegree];
			break;
		case 2:
			label = @"Low Temp";
			value = [NSString stringWithFormat:@"%i%@", [period.tempMinF intValue], AWFDegree];
			break;
		case 3:
			label = @"Average Temp";
			value = [NSString stringWithFormat:@"%i%@", [period.tempAvgF intValue], AWFDegree];
			break;
		case 4:
			label = @"Precip MTD";
			value = [NSString stringWithFormat:@"%.2f inches", [period.precipMonthToDateIN floatValue]];
			break;
		case 5:
			label = @"Precip YTD";
			value = [NSString stringWithFormat:@"%.2f inches", [period.precipYearToDateIN floatValue]];
			break;
		case 6:
			label = @"Snow MTD";
			value = [NSString stringWithFormat:@"%.2f inches", [period.snowMonthToDateIN floatValue]];
			break;
		case 7:
			label = @"Snow YTD";
			value = [NSString stringWithFormat:@"%.2f inches", [period.snowYearToDateIN floatValue]];
			break;
		case 8:
			label = @"HDD";
			value = [NSString stringWithFormat:@"%.1f", [period.heatingDegreeDays floatValue]];
			break;
		case 9:
			label = @"CDD";
			value = [NSString stringWithFormat:@"%.1f", [period.coolingDegreeDays floatValue]];
			break;
	}
	
	groupedCell.descriptionLabel.text = label;
	groupedCell.valueLabel.text = value;
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 10;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	NSString *title;
	
	if (section == 0) {
		title = NSLocalizedString(@"Today", nil);
	}
	else if (section == 1) {
		title = NSLocalizedString(@"Tomorrow", nil);
	}
	
	return title;
}

@end
