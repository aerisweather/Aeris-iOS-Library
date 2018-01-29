//
//  TidesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "TidesViewController.h"

@interface TidesViewController ()
@property (nonatomic, strong) AWFTides *endpoint;
@end

@implementation TidesViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.endpoint = [[AWFTides alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = NSLocalizedString(@"Tides", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	//[TestFlight passCheckpoint:TFCheckpointTides];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	
	[self loadDataForPlace:place options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	AWFTide *report = nil;
	AWFTidePeriod *period;
	
	NSString *label;
	NSString *value;
	
	if ([self.results count] > 0) {
		report = (AWFTide *)[self.results objectAtIndex:0];
	}
	
	switch (indexPath.section) {
		// location
		case 0: {
			switch (indexPath.row) {
				case 0:
					label = NSLocalizedString(@"Latitude", nil);
					value = [NSString stringWithFormat:@"%f", report.place.coordinate.latitude];
					break;
				case 1:
					label = NSLocalizedString(@"Longitude", nil);
					value = [NSString stringWithFormat:@"%f", report.place.coordinate.longitude];
					break;
			}
			break;
		}
		// station
		case 1: {
			switch (indexPath.row) {
				case 0:
					label = NSLocalizedString(@"Name", nil);
					value = [report.place.name capitalizedString];
					break;
			}
			break;
		}
		// tide
		default: {
			period = (AWFTidePeriod *)[report.periods objectAtIndex:(indexPath.section - 2)];
			
			if ([report.periods count] == 0) {
				label = NSLocalizedString(@"No tidal information.", nil);
			}
			else {
				switch (indexPath.row) {
					case 0:
						label = NSLocalizedString(@"Date", nil);
						value = [period.timestamp awf_formattedDateWithFormat:@"M/d/y h:mm a" timeZone:period.timeZone];
						break;
					case 1:
						label = NSLocalizedString(@"Type", nil);
						value = ([period.type isEqualToString:@"h"]) ? NSLocalizedString(@"High Tide", nil) : NSLocalizedString(@"Low Tide", nil);
						break;
					case 2:
						label = NSLocalizedString(@"Height", nil);
						value = [NSString stringWithFormat:@"%.2f feet", period.heightFT];
						break;
				}
			}
			break;
		}
	}
	
	groupedCell.titleLabel.text = label;
	groupedCell.valueLabel.text = value;
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	NSInteger total = 2;
	
	if ([self.results count] > 0) {
		AWFTide *report = (AWFTide *)[self.results objectAtIndex:0];
		total += [report.periods count];
	}
	
	return total;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	NSInteger rows = 3;
	
	if (section == 0) {
		rows = 2;
	}
	else if (section == 1) {
		rows = 1;
	}
	
	return rows;
}

@end
