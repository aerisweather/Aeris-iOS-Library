//
//  ThreatsViewController.m
//  AerisDemo
//
//  Created by Nicholas Shipes on 11/10/15.
//  Copyright © 2015 HAMweather, LLC. All rights reserved.
//

#import "ThreatsViewController.h"

@interface ThreatsViewController ()
@property (strong, nonatomic) AWFThreats *endpoint;
@end

static NSString *phraseCellIdentifier = @"PhraseTableViewCell";

@implementation ThreatsViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.endpoint = [[AWFThreats alloc] init];
	}
	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];
	
	self.title = NSLocalizedString(@"Threats", nil);
	
	[self.tableView registerClass:[MultilineTextTableViewCell class] forCellReuseIdentifier:phraseCellIdentifier];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	[self loadDataForPlace:place options:nil];
}

#pragma mark - ListingViewController

- (NSString *)cellIdentifierForIndexPath:(NSIndexPath *)indexPath {
	if (indexPath.section == 0) {
		return phraseCellIdentifier;
	}
	return [super cellIdentifierForIndexPath:indexPath];
}

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	AWFStormThreat *threat = [self stormThreat];
	
	if ([cell isKindOfClass:[MultilineTextTableViewCell class]]) {
		MultilineTextTableViewCell *phraseCell = (MultilineTextTableViewCell *)cell;
		phraseCell.textLabel.text = threat.phraseLong;
		return;
	}
	
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	NSString *label;
	NSString *value;
	
	switch (indexPath.section) {
		case 1: {
			switch (indexPath.row) {
				case 0: {
					label = NSLocalizedString(@"Approaching", nil);
					value = (threat.approaching) ? @"Yes" : @"No";
					break;
				}
				case 1: {
					label = NSLocalizedString(@"Tornadic", nil);
					value = (threat.tornadic) ? @"Yes" : @"No";
					break;
				}
				case 2: {
					label = NSLocalizedString(@"Rotation", nil);
					value = (threat.hasRotation) ? @"Yes" : @"No";
					break;
				}
				case 3: {
					label = NSLocalizedString(@"Hail", nil);
					value = (threat.hasHail) ? @"Yes" : @"No";
					break;
				}
				case 4: {
					label = NSLocalizedString(@"Intensity (DBZ)", nil);
					value = [NSString stringWithFormat:@"%.0f", threat.avgDbz];
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case 2: {
			switch (indexPath.row) {
				case 0: {
					label = NSLocalizedString(@"Distance", nil);
					value = [NSString stringWithFormat:@"%.2f mi", threat.avgDistanceMI];
					break;
				}
				case 1: {
					label = NSLocalizedString(@"Moving To", nil);
					value = [NSString stringWithFormat:@"%@ (%.0f%@)", threat.directionTo, threat.directionToDEG, AWFDegree];
					break;
				}
				case 2: {
					label = NSLocalizedString(@"Approaching From", nil);
					value = [NSString stringWithFormat:@"%@ (%.0f%@)", threat.directionFrom, threat.directionFromDEG, AWFDegree];
					break;
				}
				case 3: {
					label = NSLocalizedString(@"Moving Speed", nil);
					value = [NSString stringWithFormat:@"%.1f mph", threat.avgSpeedMPH];
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case 3: {
			switch (indexPath.row) {
				case 0: {
					label = NSLocalizedString(@"Probability", nil);
					value = [NSString stringWithFormat:@"%.0f%%", threat.hailProbability];
					break;
				}
				case 1: {
					label = NSLocalizedString(@"Prob Severe", nil);
					value = [NSString stringWithFormat:@"%.0f%%", threat.hailSevereProbability];
					break;
				}
				case 2: {
					label = NSLocalizedString(@"Max Size", nil);
					value = [NSString stringWithFormat:@"%.2f in", threat.hailMaxSizeIN];
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case 4: {
			switch (indexPath.row) {
				case 0: {
					label = NSLocalizedString(@"Nearby Strikes", nil);
					value = [NSString stringWithFormat:@"%li", threat.lightningCountNearby];
					break;
				}
				case 1: {
					label = NSLocalizedString(@"Approaching Strikes", nil);
					value = [NSString stringWithFormat:@"%li", threat.lightningCountApproaching];
					break;
				}
				default: {
					break;
				}
			}

		}
		default:
			break;
	}
	
	groupedCell.titleLabel.text = label;
	groupedCell.valueLabel.text = value;
}

- (void)dataDidFinishLoading {
	if ([self stormThreat]) {
		[self.eventView hide];
	} else {
		[self.eventView showNoResultsMessage];
	}
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return ([self stormThreat]) ? 5 : 0;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	NSInteger rows = 0;
	
	switch (section) {
		case 0:
			rows = 1;
			break;
		case 1:
			rows = 5;
			break;
		case 2:
			rows = 4;
			break;
		case 3:
			rows = 3;
			break;
		case 4:
			rows = 2;
		default:
			break;
	}
	
	return rows;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	NSString *title = nil;
	
	switch (section) {
		case 1:
			title = NSLocalizedString(@"Threats", nil);
			break;
		case 2:
			title = NSLocalizedString(@"Storm", nil);
			break;
		case 3:
			title = NSLocalizedString(@"Hail", nil);
			break;
		case 4:
			title = NSLocalizedString(@"Lightning", nil);
		default:
			break;
	}
	
	return title;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
	if (indexPath.section == 0) {
		AWFStormThreat *threat = [self stormThreat];
		NSDictionary *attributes = @{NSFontAttributeName: [UIFont systemFontOfSize:14.0]};
		CGRect textRect = [threat.phraseLong boundingRectWithSize:CGSizeMake(CGRectGetWidth(self.view.frame) - 20, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin attributes:attributes context:nil];
		
		return CGRectGetHeight(textRect) + 20.0;
	}
	return tableView.rowHeight;
}
							 
#pragma mark - Private
							 
- (AWFStormThreat *)stormThreat {
	if ([self.results count] > 0) {
		AWFThreat *threat = (AWFThreat *)[self.results firstObject];
		if ([threat.periods count] > 0) {
			AWFThreatPeriod *period = (AWFThreatPeriod *)[threat.periods firstObject];
			return period.stormThreat;
		}
	}
	return nil;
}

@end
