//
//  LightningStrikesViewController.m
//  AerisObjCDemo
//
//  Created by Slipp Douglas Thompson on 5/26/23.
//  Copyright © 2023 AerisWeather. All rights reserved.
//

#import "LightningStrikesViewController.h"
#import <AerisWeatherKit/AWFLightningStrikes.h>

@interface LightningStrikesViewController ()
@property (nonatomic, strong) AWFLightningStrikes *endpoint;
@property (nonatomic, strong) NSDate *requestTimestamp;
@property (nonatomic, strong) NSNumberFormatter *peakAmperageNumberFormatter;
@end

static NSString *lightningStrikeCellIdentifier = @"LightningStrikeCellIdentifier";

@implementation LightningStrikesViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.endpoint = [[AWFLightningStrikes alloc] init];
		
		NSNumberFormatter *peakAmperageNumberFormatter = [NSNumberFormatter new];
		peakAmperageNumberFormatter.numberStyle = NSNumberFormatterDecimalStyle;
		peakAmperageNumberFormatter.positivePrefix = peakAmperageNumberFormatter.plusSign;
		self.peakAmperageNumberFormatter = peakAmperageNumberFormatter;
	}
	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];
	
	self.tableView.separatorInset = UIEdgeInsetsZero;
	[self.tableView registerClass:AWFTableViewLightningStrikeRowCell.class forCellReuseIdentifier:lightningStrikeCellIdentifier];
	
	self.title = NSLocalizedString(@"Nearby Lightning Strikes", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.limit = 50;
	options.sort = [NSString stringWithFormat:@"%@:%ld", AWFLightningStrikeFieldDateTime, NSOrderedAscending];
	
	[self loadDataClosestToPlace:place radius:nil options:options];
	self.requestTimestamp = NSDate.date;
}

#pragma mark - ListingViewController

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	AWFTableViewLightningStrikeRowCell *cell = [tableView dequeueReusableCellWithIdentifier:lightningStrikeCellIdentifier];
	if (![cell isKindOfClass:AWFTableViewLightningStrikeRowCell.class]) {
		return cell;
	}
	[cell applyStyle:Preferences.sharedInstance.preferredStyle];
	
	AWFLightningStrike *strike = (AWFLightningStrike *)[self.results objectAtIndex:indexPath.row];
	
	NSTimeInterval age = [self.requestTimestamp timeIntervalSinceDate:strike.timestamp];
	cell.headerView.textLabel.text = [NSString stringWithFormat:NSLocalizedString(@"%.0f s ago", nil), age];
	cell.headerView.detailTextLabel.text = [strike.timestamp awf_formattedDateWithFormat:@"h:mm:ss a" timeZone:strike.place.timeZone];
	
	cell.locationDetailLabel.text = [NSString stringWithFormat:NSLocalizedString(@"(%.4f, %.4f)", nil), strike.place.coordinate.latitude, strike.place.coordinate.longitude];
	cell.locationLabel.text = [NSString stringWithFormat:NSLocalizedString(@"%.2f mi %@", nil), strike.place.relativeTo.distanceMI, strike.place.relativeTo.bearingENG];
	
	cell.peakAmperageLabel.text = [NSString stringWithFormat:NSLocalizedString(@"%@ kA", nil),
		isnan(strike.peakAmperage) ? @"--" : [self.peakAmperageNumberFormatter stringFromNumber:@(AWFConvert(strike.peakAmperage, AWFUnitAmps, AWFUnitKiloamps))]
	];
	
	NSString *pulseTypeText = strike.pulseType.uppercaseString;
	if ([pulseTypeText.lowercaseString isEqualToString:@"IC"]) {
		pulseTypeText = NSLocalizedString(@"Intracloud", nil);
	} else if ([pulseTypeText isEqualToString:@"CG"]) {
		pulseTypeText = NSLocalizedString(@"Cloud-to-Ground", nil);
	}
	cell.pulseTypeLabel.text = pulseTypeText;
	
	NSString *sensorCountText;
	if (strike.sensorCount == NSNotFound) {
		sensorCountText = NSLocalizedString(@"-- sensors", nil);
	} else {
		sensorCountText = [NSString stringWithFormat:NSLocalizedString(@"%ld sensors", nil), (long)strike.sensorCount];
	}
	cell.sensorCountLabel.text = sensorCountText;
	
	return cell;
}

@end
