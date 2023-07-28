//
//  LightningFlashesViewController.m
//  AerisDemo
//
//  Created by Slipp Douglas Thompson on 5/23/23.
//  Copyright © 2023 AerisWeather. All rights reserved.
//

#import "LightningFlashesViewController.h"
#import <AerisWeatherKit/AWFLightningFlashes.h>

@interface LightningFlashesViewController ()
@property (nonatomic, strong) AWFLightningFlashes *endpoint;
@end

static NSString *lightningFlashCellIdentifier = @"LightningFlashCellIdentifier";

@implementation LightningFlashesViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.endpoint = [[AWFLightningFlashes alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];
	
	self.tableView.separatorInset = UIEdgeInsetsZero;
	[self.tableView registerClass:AWFTableViewLightningFlashRowCell.class forCellReuseIdentifier:lightningFlashCellIdentifier];
	
	self.title = NSLocalizedString(@"Nearby Lightning Flashes", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.limit = 50;
	options.sort = [NSString stringWithFormat:@"%@:%ld", AWFLightningFlashFieldDateTime, NSOrderedAscending];
	
	[self loadDataClosestToPlace:place radius:nil options:options];
}

#pragma mark - ListingViewController

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	AWFTableViewLightningFlashRowCell *cell = [tableView dequeueReusableCellWithIdentifier:lightningFlashCellIdentifier];
	if (![cell isKindOfClass:AWFTableViewLightningFlashRowCell.class]) {
		return cell;
	}
	[cell applyStyle:Preferences.sharedInstance.preferredStyle];
	
	AWFLightningFlash *flash = (AWFLightningFlash *)[self.results objectAtIndex:indexPath.row];
	
	cell.headerView.textLabel.text = [NSString stringWithFormat:NSLocalizedString(@"%.0f s ago", nil), flash.age];
	cell.headerView.detailTextLabel.text = [flash.timestamp awf_formattedDateWithFormat:@"h:mm:ss a" timeZone:flash.place.timeZone];
	
	cell.locationDetailLabel.text = [NSString stringWithFormat:NSLocalizedString(@"(%.4f, %.4f)", nil), flash.place.coordinate.latitude, flash.place.coordinate.longitude];
	cell.locationLabel.text = [NSString stringWithFormat:NSLocalizedString(@"%.2f mi %@", nil), flash.place.relativeTo.distanceMI, flash.place.relativeTo.bearingENG];
	
	return cell;
}

@end
