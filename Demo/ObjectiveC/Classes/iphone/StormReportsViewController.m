//
//  StormReportsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "StormReportsViewController.h"
#import "ListingEventView.h"

@interface StormReportsViewController ()
@property (nonatomic, strong) AWFStormReportsLoader *loader;
@end

@implementation StormReportsViewController

@synthesize loader;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.loader = [[AWFStormReportsLoader alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = NSLocalizedString(@"Storm Reports", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.limit = 30;
	options.fromDateString = @"-24 hours";
	
	[self loadDataClosestToPlace:place radius:@"150mi" options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	AWFStormReport *report = (AWFStormReport *)[self.results objectAtIndex:indexPath.row];
	
	// set global NSDateFormatter timezone to local time
	[NSDate awf_setDefaultTimezone:report.place.timeZone];
	
	// get report value if exists
	NSString *val = @"";
	NSString *reportType = [[report.type lowercaseString] stringByReplacingOccurrencesOfString:@"thunderstorm" withString:@"t-storm"];
	
	if ([reportType rangeOfString:@"wind"].location != NSNotFound && [reportType rangeOfString:@"damage"].location == NSNotFound) {
		val = [NSString stringWithFormat:@"%.0f mph", [report.windSpeedMPH floatValue]];
	}
	else if ([reportType rangeOfString:@"rain"].location != NSNotFound) {
		val = [NSString stringWithFormat:@"%.2f in", [report.rainIN floatValue]];
	}
	else if ([reportType rangeOfString:@"snow"].location != NSNotFound) {
		val = [NSString stringWithFormat:@"%.1f in", [report.snowIN floatValue]];
	}
	else if ([reportType rangeOfString:@"hail"].location != NSNotFound) {
		val = [NSString stringWithFormat:@"%.2f in", [report.hailIN floatValue]];
	}
	if (AWFIsNonEmptyString(val)) {
		val = [NSString stringWithFormat:@" - %@", val];
	}
	
	// determine which icon to display based on type of report
	NSString *typeIcon = @"";
	if ([report.code isEqualToString:@"H"]) {
		typeIcon = @"report_hail.png";
	}
	else if ([report.code isEqualToString:@"O"] || [report.code isEqualToString:@"D"] || [report.code isEqualToString:@"N"] || [report.code isEqualToString:@"G"]) {
		typeIcon = @"report_wind.png";
	}
	else if ([report.code isEqualToString:@"T"] || [report.code isEqualToString:@"C"] || [report.code isEqualToString:@"W"]) {
		typeIcon = @"report_tornado.png";
	}
	else if ([report.code isEqualToString:@"E"] || [report.code isEqualToString:@"F"] || [report.code isEqualToString:@"R"]) {
		typeIcon = @"report_rain.png";
	}
	else if ([report.code isEqualToString:@"B"] || [report.code isEqualToString:@"S"]) {
		typeIcon = @"report_snow.png";
	}
	else if ([report.code isEqualToString:@"s"] || [report.code isEqualToString:@"5"]) {
		typeIcon = @"report_ice.png";
	}
	else if ([report.code isEqualToString:@"L"]) {
		typeIcon = @"report_tstorm.png";
	}
	else if ([report.code isEqualToString:@"E"]) {
		typeIcon = @"report_fog.png";
	}
	else if ([report.code isEqualToString:@"4"] || [report.code isEqualToString:@"v"]) {
		typeIcon = @"report_wave.png";
	}
	else if ([report.code isEqualToString:@"A"]) {
		typeIcon = @"report_avalanche.png";
	}
	
	cell.textLabel.text = [NSString stringWithFormat:@"%@%@", [reportType capitalizedString], val];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"%@, %@", [[report.place.name capitalizedString] awf_stringByFormattingCardinalAbbreviations], [report.place.state uppercaseString]];
	
	if (AWFIsNonEmptyString(typeIcon)) {
		//cell.imageView.image = AF_IMAGE(typeIcon);
	}
}

@end
