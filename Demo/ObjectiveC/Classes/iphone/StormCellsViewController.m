//
//  StormCellsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "StormCellsViewController.h"
#import "ListingEventView.h"

@interface StormCellsViewController ()
@property (nonatomic, strong) AWFStormCellsLoader *loader;
@end

@implementation StormCellsViewController

@synthesize loader;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.loader = [[AWFStormCellsLoader alloc] init];
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
	
	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.limit = 50;
	options.fromDateString = @"-24 hours";
	
	[self loadDataClosestToPlace:place radius:@"150mi" options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	AWFStormCell *report = (AWFStormCell *)[self.results objectAtIndex:indexPath.row];
	
	// set global NSDateFormatter timezone to local time
	[NSDate awf_setDefaultTimezone:report.place.timeZone];
	
	NSString *moving = (report.movingDirection != nil) ? [NSString stringWithFormat:@", moving %@ at %@ mph", report.movingDirection, report.movingSpeedMPH] : @"";
	
	// determine which icon to display based on type of storm
	NSString *typeIcon = @"stormcell_basic.png";
	if ([report.tvs intValue] == 1 || [report.mda intValue] >= 10) {
		typeIcon = @"stormcell_tornadic.png";
	}
	else if ([report.hailProbability intValue] >= 70) {
		typeIcon = @"stormcell_hail.png";
	}
	
	cell.textLabel.text = report.code;
	cell.detailTextLabel.text = [NSString stringWithFormat:@"%i mi %@%@", [report.distanceMI intValue], report.bearing, moving];
	
	if (AWFIsNonEmptyString(typeIcon)) {
		//cell.imageView.image = AF_IMAGE(typeIcon);
	}
}

@end
