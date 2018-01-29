//
//  EarthquakesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "EarthquakesViewController.h"

@interface EarthquakesViewController ()
@property (nonatomic, strong) AWFEarthquakes *endpoint;
@end

@implementation EarthquakesViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.endpoint = [[AWFEarthquakes alloc] init];
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

	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.limit = 30;
	options.fromDateString = @"-24 hours";
	options.sort = [NSString stringWithFormat:@"mag:%li", (long)AWFRequestSortDescending];

	[self loadDataClosestToPlace:place radius:@"150mi" options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	AWFEarthquake *report = (AWFEarthquake *)[self.results objectAtIndex:indexPath.row];

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

	NSString *date = [report.timestamp awf_formattedDateWithFormat:@"M/d/y h:mm a" timeZone:report.place.timeZone];
	cell.textLabel.text = [NSString stringWithFormat:@"%.2f (%@)", report.magnitude, reportType];
	cell.detailTextLabel.text = [NSString stringWithFormat:@"%@ - %@, %@", date, [report.place.name capitalizedString], (([[report.place.country lowercaseString] isEqualToString:@"us"]) ? [report.place.state uppercaseString] : [report.place.country uppercaseString])];

	if (AWFIsNonEmptyString(typeIcon)) {
		//cell.imageView.image = AF_IMAGE(typeIcon);
	}
}

@end
