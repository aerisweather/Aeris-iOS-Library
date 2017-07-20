//
//  RecordsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "RecordsViewController.h"
#import "ListingEventView.h"

@interface RecordsViewController ()
@property (nonatomic, strong) AWFRecordsLoader *loader;
@end

@implementation RecordsViewController

@synthesize loader;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.loader = [[AWFRecordsLoader alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = NSLocalizedString(@"Nearby Records", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.limit = 50;
	options.fromDateString = @"-72 hours";
	
	[self loadDataClosestToPlace:place radius:@"150mi" options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	AWFRecord *report = (AWFRecord *)[self.results objectAtIndex:indexPath.row];
	
	// set global NSDateFormatter timezone to local time
	[NSDate awf_setDefaultTimezone:report.place.timeZone];
	
	NSString *reportType = @"";
	NSString *val = @"";
	NSString *typeIcon = @"";
	
	if ([report.type isEqualToString:@"prcp"]) {
		reportType = @"Rain";
		val = [NSString stringWithFormat:@"%.2f %@", [report.rainIN floatValue], @"in"];
		typeIcon = @"report_rain.png";
	}
	else if ([report.type isEqualToString:@"snow"]) {
		reportType = @"Snow";
		val = [NSString stringWithFormat:@"%.2f %@", [report.snowIN floatValue], @"in"];
		typeIcon = @"report_snow.png";
	}
	else if ([report.type isEqualToString:@"maxt"]) {
		reportType = @"High Temperature";
		val = [NSString stringWithFormat:@"%i%@", [report.tempF intValue], AWFDegree];
		typeIcon = @"report_hightemp.png";
	}
	else if ([report.type isEqualToString:@"mint"]) {
		reportType = @"Low Temperature";
		val = [NSString stringWithFormat:@"%i%@", [report.tempF intValue], AWFDegree];
		typeIcon = @"report_lowtemp.png";
	}
	else if ([report.type isEqualToString:@"himn"]) {
		reportType = @"Warm Min Temp";
		val = [NSString stringWithFormat:@"%i%@", [report.tempF intValue], AWFDegree];
		typeIcon = @"report_highmintemp.png";
	}
	else if ([report.type isEqualToString:@"lomx"]) {
		reportType = @"Cool Max Temp";
		val = [NSString stringWithFormat:@"%i%@", [report.tempF intValue], AWFDegree];
		typeIcon = @"report_lowmaxtemp.png";
	}
	
	NSString *date = [report.timestamp awf_stringWithFormat:@"M/d/y"];
	cell.textLabel.text = [NSString stringWithFormat:@"%@ - %@%@", [reportType capitalizedString], val, ((report.isTied == YES) ? @"*" : @"")];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"%@ - %@, %@", date, [report.place.name capitalizedString], [report.place.state uppercaseString]];
	
	if (AWFIsNonEmptyString(typeIcon)) {
		//cell.imageView.image = AF_IMAGE(typeIcon);
	}
}

@end
