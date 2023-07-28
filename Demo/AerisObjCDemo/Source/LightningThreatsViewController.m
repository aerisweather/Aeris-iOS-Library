//
//  LightningThreatsViewController.m
//  AerisDemo
//
//  Created by Slipp Douglas Thompson on 5/25/23.
//  Copyright © 2023 AerisWeather. All rights reserved.
//

#import "LightningThreatsViewController.h"
#import <AerisWeatherKit/AWFLightningThreats.h>

typedef NS_ENUM(NSInteger, LightningThreatsViewControllerThreatRow) {
	LightningThreatsViewControllerThreatRowDataSource,
	LightningThreatsViewControllerThreatRowIssued,
	LightningThreatsViewControllerThreatRowDuration,
	LightningThreatsViewControllerThreatRowSevere,
	LightningThreatsViewControllerThreatRowMovementDirection,
	LightningThreatsViewControllerThreatRowMovementSpeed,
	LightningThreatsViewControllerThreatRowMovementReliability,
	LightningThreatsViewControllerThreatRowPeriodsSeparator,
	LightningThreatsViewControllerThreatRow_Count,
};

static NSString *periodsSeparatorCellIdentifier = @"PeriodsSeparaterTableViewCell";
static CGFloat periodsSeparatorCellHeight = 10;

@interface LightningThreatsViewController ()
@property (nonatomic, strong) AWFLightningThreats *endpoint;
@end

@implementation LightningThreatsViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.endpoint = [[AWFLightningThreats alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];
	
	[self.tableView registerClass:UITableViewCell.class forCellReuseIdentifier:periodsSeparatorCellIdentifier];
	
	self.title = NSLocalizedString(@"Nearby Lightning Threats", nil);
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.limit = 50;
	options.sort = [NSString stringWithFormat:@"%@:%ld", AWFLightningFlashFieldDateTime, NSOrderedAscending];
	
	[self loadDataClosestToPlace:place radius:nil options:options];
}

#pragma mark ListingViewController Conformance

- (NSString *)cellIdentifierForIndexPath:(NSIndexPath *)indexPath {
	if (indexPath.item == LightningThreatsViewControllerThreatRowPeriodsSeparator) {
		return periodsSeparatorCellIdentifier;
	} else {
		return [super cellIdentifierForIndexPath:indexPath];
	}
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
	if (indexPath.item == LightningThreatsViewControllerThreatRowPeriodsSeparator) {
		return periodsSeparatorCellHeight;
	} else {
		return tableView.rowHeight;
	}
}

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	
	AWFLightningThreat *threat = self.results[indexPath.section];
	NSUInteger threatPeriodCount = threat.periods.count;
	NSUInteger threatPeriodIndex = indexPath.row - LightningThreatsViewControllerThreatRow_Count;
	
	NSString *label;
	NSString *value;
	BOOL valueEnabled = YES;
	
	switch (indexPath.row) {
		case LightningThreatsViewControllerThreatRowDataSource: {
			label = NSLocalizedString(@"Data Source", nil);
			NSString *dataSource = threat.dataSource;
			if ([dataSource isEqualToString:@"vaisala-lightning"]) {
				value = @"Vaisala Lightning";
			} else {
				value = dataSource;
			}
			break;
		}
		case LightningThreatsViewControllerThreatRowIssued:
			label = NSLocalizedString(@"Issued", nil);
			value = [threat.issued awf_formattedDateWithFormat:@"h:mm a" timeZone:threat.timeZone];
			break;
		case LightningThreatsViewControllerThreatRowDuration:
			label = NSLocalizedString(@"Duration", nil);
			value = [NSString stringWithFormat:@"%@ - %@",
				[threat.startDate awf_formattedDateWithFormat:@"h:mm a" timeZone:threat.timeZone],
				[threat.endDate awf_formattedDateWithFormat:@"h:mm a" timeZone:threat.timeZone]
			];
			break;
		case LightningThreatsViewControllerThreatRowSevere:
			label = NSLocalizedString(@"Severe", nil);
			value = (threat.isSevere) ? NSLocalizedString(@"Yes", nil) : NSLocalizedString(@"No", nil);
			break;
		case LightningThreatsViewControllerThreatRowMovementDirection:
			label = NSLocalizedString(@"Movement Direction", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%@ (%.0f%@)", nil), threat.movement.directionENG, threat.movement.direction, AWFDegree];
			break;
		case LightningThreatsViewControllerThreatRowMovementSpeed:
			label = NSLocalizedString(@"Movement Speed", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f mph", nil), threat.movement.speedMPH];
			break;
		case LightningThreatsViewControllerThreatRowMovementReliability: {
			label = NSLocalizedString(@"Movement Reliability", nil);
			AWFLightningThreatMovementReliability reliability = threat.movement.reliability;
			if ([reliability isEqual:AWFLightningThreatMovementReliabilityUnphysical]) {
				value = NSLocalizedString(@"Unphysical", nil);
			} else if ([reliability isEqual:AWFLightningThreatMovementReliabilityLow]) {
				value = NSLocalizedString(@"Low", nil);
			} else if ([reliability isEqual:AWFLightningThreatMovementReliabilityMedium]) {
				value = NSLocalizedString(@"Medium", nil);
			} else if ([reliability isEqual:AWFLightningThreatMovementReliabilityHigh]) {
				value = NSLocalizedString(@"High", nil);
			} else {
				value = NSLocalizedString(@"not available", nil);
				valueEnabled = NO;
			}
			break;
		}
		case LightningThreatsViewControllerThreatRowPeriodsSeparator:
			groupedCell = nil; // The `UITableViewCell` isn't actually a `GroupedTableViewCell`, nil'ing local for clarity/safety.
			cell.contentView.hidden = YES;
			cell.backgroundColor = UIColor.clearColor;
			break;
		default:
			if (threatPeriodIndex >= 0 && threatPeriodIndex < threatPeriodCount) {
				AWFLightningThreatPeriod *threatPeriod = threat.periods[threatPeriodIndex];
				
				label = [NSString stringWithFormat:@"%@ - %@",
					[threatPeriod.startDate awf_formattedDateWithFormat:@"h:mm a" timeZone:threat.timeZone],
					[threatPeriod.endDate awf_formattedDateWithFormat:@"h:mm a" timeZone:threat.timeZone]
				];
				value = [NSString stringWithFormat:NSLocalizedString(@"(%.4f, %.4f)", nil), threatPeriod.polygon.centroid.latitude, threatPeriod.polygon.centroid.longitude];
			}
			break;
	}
	
	if (indexPath.row == LightningThreatsViewControllerThreatRowPeriodsSeparator ||
		indexPath.row == (LightningThreatsViewControllerThreatRowPeriodsSeparator - 1)) {
		cell.separatorInset = UIEdgeInsetsZero;
	} else {
		cell.separatorInset = self.tableView.separatorInset;
	}
	
	if (threat.movement == nil) {
		if (indexPath.row >= LightningThreatsViewControllerThreatRowMovementDirection &&
			indexPath.row <= LightningThreatsViewControllerThreatRowMovementReliability) {
			value = NSLocalizedString(@"not available", nil);
			valueEnabled = NO;
		}
	}
	
	groupedCell.titleLabel.text = label;
	groupedCell.valueLabel.text = value;
	groupedCell.valueLabel.textColor = valueEnabled ? UIColor.blackColor : UIColor.grayColor;
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return self.results.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	AWFLightningThreat *threat = self.results[section];
	NSUInteger periodCount = threat.periods.count;
	return LightningThreatsViewControllerThreatRow_Count + periodCount;
}

@end
