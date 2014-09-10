//
//  EarthquakesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "EarthquakesViewController.h"
#import "ListingEventView.h"
#import "ListingTableViewCell.h"

@interface EarthquakesViewController ()
@property (nonatomic, strong) AWFEarthquakesLoader *loader;
@end

@implementation EarthquakesViewController

@synthesize loader;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.loader = [[AWFEarthquakesLoader alloc] init];
	}
	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];

	self.title = NSLocalizedString(@"Nearby Earthquakes", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];

	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];

	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.limit = 30;
	options.fromDateString = @"-24 hours";
	options.sort = [NSString stringWithFormat:@"mag:%li", (long)AWFRequestSortDescending];

	[self loadDataClosestToPlace:place radius:@"150mi" options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	AWFEarthquake *report = (AWFEarthquake *)[self.results objectAtIndex:indexPath.row];

	// set global NSDateFormatter timezone to local time
	[NSDate awf_setDefaultTimezone:report.place.timeZone];

	NSString *reportType = @"";
	NSString *typeIcon = @"";
	if ([report.type isEqualToString:@"mini"]) {
		reportType = @"Mini";
		typeIcon = @"quake_minor.png";
	}
	else if ([report.type isEqualToString:@"minor"]) {
		reportType = @"Minor";
		typeIcon = @"quake_minor.png";
	}
	else if ([report.type isEqualToString:@"light"]) {
		reportType = @"Light";
		typeIcon = @"quake_light.png";
	}
	else if ([report.type isEqualToString:@"moderate"]) {
		reportType = @"Moderate";
		typeIcon = @"quake_moderate.png";
	}
	else if ([report.type isEqualToString:@"strong"]) {
		reportType = @"Strong";
		typeIcon = @"quake_strong.png";
	}
	else if ([report.type isEqualToString:@"major"]) {
		reportType = @"Major";
		typeIcon = @"quake_major.png";
	}
	else if ([report.type isEqualToString:@"great"]) {
		reportType = @"Major";
		typeIcon = @"quake_major.png";
	}

	NSString *date = [report.timestamp awf_stringWithFormat:@"M/d/y h:mm a"];
	cell.textLabel.text = [NSString stringWithFormat:@"%.2f (%@)", [report.magnitude floatValue], reportType];
	cell.detailTextLabel.text = [NSString stringWithFormat:@"%@ - %@, %@", date, [report.place.name capitalizedString], (([[report.place.country lowercaseString] isEqualToString:@"us"]) ? [report.place.state uppercaseString] : [report.place.country uppercaseString])];

	if (AWFIsNonEmptyString(typeIcon)) {
		//cell.imageView.image = AF_IMAGE(typeIcon);
	}
}

@end
