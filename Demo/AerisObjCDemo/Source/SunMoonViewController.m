//
//  SunMoonViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "SunMoonViewController.h"

@interface SunMoonViewController ()
@property (nonatomic, strong) AWFSunMoon *endpoint;
@end

@implementation SunMoonViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.endpoint = [[AWFSunMoon alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = NSLocalizedString(@"Sun & Moon", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	self.place = place;
	
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.toDateString = @"+1 day";
	
	[self loadDataForPlace:place options:options];
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	AWFSunMoonPeriod *report = (AWFSunMoonPeriod *)[self.results objectAtIndex:indexPath.section];
	
	switch (indexPath.row) {
		case 0: {
			groupedCell.titleLabel.text = NSLocalizedString(@"Sunrise", nil);
			groupedCell.valueLabel.text = [report.sunrise awf_formattedDateWithFormat:@"h:mm a" timeZone:report.place.timeZone];
			break;
		}
		case 1: {
			groupedCell.titleLabel.text = NSLocalizedString(@"Sunset", nil);
			groupedCell.valueLabel.text = [report.sunset awf_formattedDateWithFormat:@"h:mm a" timeZone:report.place.timeZone];
			break;
		}
		case 2: {
			NSUInteger diff = [report.sunset timeIntervalSinceDate:report.sunrise] / 60;
			NSUInteger hr = floor(diff / 60);
			NSUInteger min = diff - (hr * 60);
			
			groupedCell.titleLabel.text = NSLocalizedString(@"Total Daylight", nil);
			groupedCell.valueLabel.text = [NSString stringWithFormat:@"%lu hr, %lu min", (unsigned long)hr, (unsigned long)min];
			break;
		}
		case 3: {
			groupedCell.titleLabel.text = NSLocalizedString(@"Moon Phase", nil);
			groupedCell.valueLabel.text = [report.moonPhaseName capitalizedString];
			break;
		}
		case 4: {
			groupedCell.titleLabel.text = NSLocalizedString(@"Moon Illum", nil);
			groupedCell.valueLabel.text = [NSString stringWithFormat:@"%.1f%%", report.moonIllumination];
			break;
		}
	}
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 4;
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
