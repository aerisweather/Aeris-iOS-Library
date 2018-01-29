//
//  RecordsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "RecordsViewController.h"

@interface RecordsViewController ()
@property (nonatomic, strong) AWFRecords *endpoint;
@end

@implementation RecordsViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.endpoint = [[AWFRecords alloc] init];
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
	
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.limit = 50;
	options.fromDateString = @"-72 hours";
	
	[self loadDataClosestToPlace:place radius:@"150mi" options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	AWFRecord *report = (AWFRecord *)[self.results objectAtIndex:indexPath.row];
	
	NSString *reportType = @"";
	NSString *val = @"";
	NSString *typeIcon = @"";
	
	if ([report.type isEqualToString:@"prcp"]) {
		reportType = @"Rain";
		val = [NSString stringWithFormat:@"%.2f %@", report.rainIN, @"in"];
		typeIcon = @"report_rain.png";
	}
	else if ([report.type isEqualToString:@"snow"]) {
		reportType = @"Snow";
		val = [NSString stringWithFormat:@"%.2f %@", report.snowIN, @"in"];
		typeIcon = @"report_snow.png";
	}
	else if ([report.type isEqualToString:@"maxt"]) {
		reportType = @"High Temperature";
		val = [NSString stringWithFormat:@"%.0f%@", report.tempF, AWFDegree];
		typeIcon = @"report_hightemp.png";
	}
	else if ([report.type isEqualToString:@"mint"]) {
		reportType = @"Low Temperature";
		val = [NSString stringWithFormat:@"%.0f%@", report.tempF, AWFDegree];
		typeIcon = @"report_lowtemp.png";
	}
	else if ([report.type isEqualToString:@"himn"]) {
		reportType = @"Warm Min Temp";
		val = [NSString stringWithFormat:@"%.0f%@", report.tempF, AWFDegree];
		typeIcon = @"report_highmintemp.png";
	}
	else if ([report.type isEqualToString:@"lomx"]) {
		reportType = @"Cool Max Temp";
		val = [NSString stringWithFormat:@"%.0f%@", report.tempF, AWFDegree];
		typeIcon = @"report_lowmaxtemp.png";
	}
	
	NSString *date = [report.timestamp awf_formattedDateWithFormat:@"M/d/y" timeZone:report.place.timeZone];
	cell.textLabel.text = [NSString stringWithFormat:@"%@ - %@%@", [reportType capitalizedString], val, ((report.isTied == YES) ? @"*" : @"")];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"%@ - %@, %@", date, [report.place.name capitalizedString], [report.place.state uppercaseString]];
	
	if (AWFIsNonEmptyString(typeIcon)) {
		//cell.imageView.image = AF_IMAGE(typeIcon);
	}
}

@end
