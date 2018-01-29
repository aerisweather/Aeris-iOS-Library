//
//  StormCellsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "StormCellsViewController.h"

@interface StormCellsViewController ()
@property (nonatomic, strong) AWFStormCells *endpoint;
@end

@implementation StormCellsViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.endpoint = [[AWFStormCells alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = NSLocalizedString(@"Nearby Storm Cells", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.limit = 50;
	options.fromDateString = @"-24 hours";
	
	[self loadDataClosestToPlace:place radius:@"150mi" options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	AWFStormCell *report = (AWFStormCell *)[self.results objectAtIndex:indexPath.row];	
	NSString *moving = (report.movingDirection != nil) ? [NSString stringWithFormat:@", moving %@ at %.0f mph", report.movingDirection, report.movingSpeedMPH] : @"";
	
	// determine which icon to display based on type of storm
	NSString *typeIcon = @"stormcell_basic.png";
	if (report.tvs == 1 || report.mda >= 10) {
		typeIcon = @"stormcell_tornadic.png";
	} else if (report.hailProbability >= 70) {
		typeIcon = @"stormcell_hail.png";
	}
	
	cell.textLabel.text = report.code;
	cell.detailTextLabel.text = [NSString stringWithFormat:@"%.0f mi %@%@", report.distanceMI, report.bearing, moving];
	
	if (AWFIsNonEmptyString(typeIcon)) {
		//cell.imageView.image = AF_IMAGE(typeIcon);
	}
}

@end
