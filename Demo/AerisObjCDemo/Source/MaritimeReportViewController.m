//
//  MaritimeReportViewController.m
//  AerisDemo
//
//  Created by Slipp Douglas Thompson on 6/30/23.
//  Copyright © 2023 AerisWeather. All rights reserved.
//

#import "MaritimeReportViewController.h"
#import <AerisWeatherKit/AWFMaritime.h>

typedef NS_ENUM(NSInteger, MaritimeReportViewControllerReportRow) {
	MaritimeReportViewControllerReportRowInterval,
	MaritimeReportViewControllerReportRow_Count,
};

typedef NS_ENUM(NSInteger, MaritimeReportViewControllerPeriodRow) {
	MaritimeReportViewControllerPeriodRowSeaSurfaceSubheader,
	MaritimeReportViewControllerPeriodRowSeaSurfaceTemperature,
	MaritimeReportViewControllerPeriodRowSeaCurrentSubheader,
	MaritimeReportViewControllerPeriodRowSeaCurrentSpeed,
	MaritimeReportViewControllerPeriodRowSeaCurrentDirection,
	MaritimeReportViewControllerPeriodRowSignificantWaveSubheader,
	MaritimeReportViewControllerPeriodRowSignificantWaveHeight,
	MaritimeReportViewControllerPeriodRowPrimaryWaveSubheader,
	MaritimeReportViewControllerPeriodRowPrimaryWaveDirection,
	MaritimeReportViewControllerPeriodRowPrimaryWavePeriod,
	MaritimeReportViewControllerPeriodRowWindWaveSubheader,
	MaritimeReportViewControllerPeriodRowWindWaveDirection,
	MaritimeReportViewControllerPeriodRowWindWavePeriod,
	MaritimeReportViewControllerPeriodRowPrimarySwellSubheader,
	MaritimeReportViewControllerPeriodRowPrimarySwellHeight,
	MaritimeReportViewControllerPeriodRowPrimarySwellDirection,
	MaritimeReportViewControllerPeriodRowPrimarySwellPeriod,
	MaritimeReportViewControllerPeriodRowSecondarySwellSubheader,
	MaritimeReportViewControllerPeriodRowSecondarySwellHeight,
	MaritimeReportViewControllerPeriodRowSecondarySwellDirection,
	MaritimeReportViewControllerPeriodRowSecondarySwellPeriod,
	MaritimeReportViewControllerPeriodRowTertiarySwellSubheader,
	MaritimeReportViewControllerPeriodRowTertiarySwellHeight,
	MaritimeReportViewControllerPeriodRowTertiarySwellDirection,
	MaritimeReportViewControllerPeriodRowTertiarySwellPeriod,
	MaritimeReportViewControllerPeriodRowTideSubheader,
	MaritimeReportViewControllerPeriodRowTideLevel,
	MaritimeReportViewControllerPeriodRowSurgeSubheader,
	MaritimeReportViewControllerPeriodRowSurgeLevel,
	MaritimeReportViewControllerPeriodRow_Count,
};

BOOL MaritimeReportViewControllerPeriodRowIsSubheader(MaritimeReportViewControllerPeriodRow rowIndex) {
	switch (rowIndex) {
		case MaritimeReportViewControllerPeriodRowSeaSurfaceSubheader:
		case MaritimeReportViewControllerPeriodRowSeaCurrentSubheader:
		case MaritimeReportViewControllerPeriodRowSignificantWaveSubheader:
		case MaritimeReportViewControllerPeriodRowPrimaryWaveSubheader:
		case MaritimeReportViewControllerPeriodRowWindWaveSubheader:
		case MaritimeReportViewControllerPeriodRowPrimarySwellSubheader:
		case MaritimeReportViewControllerPeriodRowSecondarySwellSubheader:
		case MaritimeReportViewControllerPeriodRowTertiarySwellSubheader:
		case MaritimeReportViewControllerPeriodRowTideSubheader:
		case MaritimeReportViewControllerPeriodRowSurgeSubheader:
			return YES;
		default:
			return NO;
	}
}

static NSString *subheaderCellIdentifier = @"SubheaderTableViewCell";
static CGFloat subheaderCellHeight = 30;

// Polyfill for iOS <13.0
static UIColor *secondaryLabelColor;

@interface MaritimeReportViewController ()
@property (nonatomic, strong) AWFMaritime *endpoint;
@property (nonatomic, strong, nullable, readonly) AWFMaritimeReport *report;
- (void)handleConfigurationOfCellInReportSection:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath;
- (void)handleConfigurationOfCellInPeriodSection:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath;
- (void)handleConfigurationOfSubheaderCellInPeriodSection:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath;
- (void)handleConfigurationOfGroupedCellInPeriodSection:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath;
@end

@implementation MaritimeReportViewController

+ (void)initialize {
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		if (@available(iOS 13.0, tvOS 13.0, macCatalyst 13.1, *)) {
			secondaryLabelColor = UIColor.secondaryLabelColor;
		} else {
			secondaryLabelColor = [UIColor colorWithRed:0.24 green:0.24 blue:0.26 alpha:0.6];
		}
	});
}

@synthesize endpoint;

- (AWFMaritimeReport *)report {
	return self.results.firstObject;
}

#pragma mark Initialization & Setup

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.endpoint = [[AWFMaritime alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];
	
	[self.tableView registerClass:UITableViewCell.class forCellReuseIdentifier:subheaderCellIdentifier];
	
	self.title = NSLocalizedString(@"Maritime Report", nil);
	
	self.tableView.rowHeight = 30;
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	
	[self loadDataForPlace:place options:options];
}

#pragma mark ListingViewController Conformance

- (NSString *)cellIdentifierForIndexPath:(NSIndexPath *)indexPath {
	if (indexPath.section == 0) {
		return [super cellIdentifierForIndexPath:indexPath];
	} else if (indexPath.section >= 1) {
		if (MaritimeReportViewControllerPeriodRowIsSubheader(indexPath.row)) {
			return subheaderCellIdentifier;
		} else {
			return [super cellIdentifierForIndexPath:indexPath];
		}
	} else {
		return nil;
	}
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
	if (indexPath.section == 0) {
		return tableView.rowHeight;
	} else if (indexPath.section >= 1) {
		if (MaritimeReportViewControllerPeriodRowIsSubheader(indexPath.row)) {
			return subheaderCellHeight;
		} else {
			return tableView.rowHeight;
		}
	} else {
		return 0;
	}
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	if (section == 0) {
		return nil;
	} else if (section >= 1) {
		AWFMaritimePeriod *period = self.report.periods[section - 1];
		NSString *value = [period.timestamp awf_formattedDateWithFormat:@"h:mm a zzz" timeZone:period.timeZone];
		return value;
	} else {
		return nil;
	}
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return self.report.periods.count + 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	if (section == 0) {
		return MaritimeReportViewControllerReportRow_Count;
	} else if (section >= 1) {
		return MaritimeReportViewControllerPeriodRow_Count;
	} else {
		return 0;
	}
}

#pragma mark ListingViewController Conformance

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	if (indexPath.section == 0) {
		[self handleConfigurationOfCellInReportSection:cell forIndexPath:indexPath];
	} else if (indexPath.section >= 1) {
		[self handleConfigurationOfCellInPeriodSection:cell forIndexPath:indexPath];
	}
}

- (void)handleConfigurationOfCellInReportSection:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	
	AWFMaritimeReport *report = self.report;
	
	NSString *label;
	NSString *value;
	
	switch (indexPath.row) {
		case MaritimeReportViewControllerReportRowInterval:
			label = NSLocalizedString(@"Interval", nil);
			value = [NSString stringWithFormat:@"%@", report.interval];
			break;
	}
		
	groupedCell.titleLabel.text = label;
	groupedCell.valueLabel.text = value;
}

- (void)handleConfigurationOfCellInPeriodSection:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	if (MaritimeReportViewControllerPeriodRowIsSubheader(indexPath.row)) {
		return [self handleConfigurationOfSubheaderCellInPeriodSection:cell forIndexPath:indexPath];
	} else {
		return [self handleConfigurationOfGroupedCellInPeriodSection:cell forIndexPath:indexPath];
	}
}

- (void)handleConfigurationOfSubheaderCellInPeriodSection:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	NSString *label;
	
	switch (indexPath.row) {
		case MaritimeReportViewControllerPeriodRowSeaSurfaceSubheader:
			label = @"Sea Surface";
			break;
		case MaritimeReportViewControllerPeriodRowSeaCurrentSubheader:
			label = @"Sea Current";
			break;
		case MaritimeReportViewControllerPeriodRowSignificantWaveSubheader:
			label = @"Significant Wave";
			break;
		case MaritimeReportViewControllerPeriodRowPrimaryWaveSubheader:
			label = @"Primary Wave";
			break;
		case MaritimeReportViewControllerPeriodRowWindWaveSubheader:
			label = @"Wind Wave";
			break;
		case MaritimeReportViewControllerPeriodRowPrimarySwellSubheader:
			label = @"Primary Swell";
			break;
		case MaritimeReportViewControllerPeriodRowSecondarySwellSubheader:
			label = @"Secondary Swell";
			break;
		case MaritimeReportViewControllerPeriodRowTertiarySwellSubheader:
			label = @"Tertiary Swell";
			break;
		case MaritimeReportViewControllerPeriodRowTideSubheader:
			label = @"Tide";
			break;
		case MaritimeReportViewControllerPeriodRowSurgeSubheader:
			label = @"Surge";
			break;

	}
	
	CGRect contentBounds = cell.contentView.bounds;
	contentBounds.origin = CGPointMake(contentBounds.origin.x, -5);
	cell.contentView.bounds = contentBounds;
	
	cell.textLabel.font = [UIFont boldSystemFontOfSize:11.0];
	cell.textLabel.textColor = secondaryLabelColor;
	cell.textLabel.text = label.uppercaseString;
	
	cell.separatorInset = self.tableView.separatorInset;
}

- (void)handleConfigurationOfGroupedCellInPeriodSection:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	
	AWFMaritimePeriod *period = self.report.periods[indexPath.section - 1];
	
	groupedCell.valueLabel.numberOfLines = 1;
	
	NSString *label;
	NSString *value;
	double doubleValue = NAN; // used just to determine if the row should be drawn disabled (when NAN)
	
	switch (indexPath.row) {
		case MaritimeReportViewControllerPeriodRowSeaSurfaceTemperature:
			label = NSLocalizedString(@"Temperature", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1fºF", nil), period.seaSurfaceTemperatureF];
			doubleValue = period.seaSurfaceTemperatureC;
			break;
		case MaritimeReportViewControllerPeriodRowSeaCurrentSpeed:
			label = NSLocalizedString(@"Speed", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%@ / %@", nil),
				[NSString stringWithFormat:NSLocalizedString(@"%.1f MPH", nil), period.seaCurrentSpeedMPH],
				[NSString stringWithFormat:NSLocalizedString(@"%.1f knots", nil), period.seaCurrentSpeedKTS]
			];
			doubleValue = period.seaCurrentSpeedMPS;
			break;
		case MaritimeReportViewControllerPeriodRowSeaCurrentDirection:
			label = NSLocalizedString(@"Direction", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%@ (%.0f%@)", nil), period.seaCurrentDirectionENG, period.seaCurrentDirection, AWFDegree];
			doubleValue = period.seaCurrentDirection;
			break;
		case MaritimeReportViewControllerPeriodRowSignificantWaveHeight:
			label = NSLocalizedString(@"Height", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f feet", nil), period.significantWaveHeightFT];
			doubleValue = period.significantWaveHeightM;
			break;
		case MaritimeReportViewControllerPeriodRowPrimaryWaveDirection:
			label = NSLocalizedString(@"Direction", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%@ (%.0f%@)", nil), period.primaryWaveDirectionENG, period.primaryWaveDirection, AWFDegree];
			doubleValue = period.primaryWaveDirection;
			break;
		case MaritimeReportViewControllerPeriodRowPrimaryWavePeriod:
			label = NSLocalizedString(@"Period", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f seconds", nil), period.primaryWavePeriod];
			doubleValue = period.primaryWavePeriod;
			break;
		case MaritimeReportViewControllerPeriodRowWindWaveDirection:
			label = NSLocalizedString(@"Direction", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%@ (%.0f%@)", nil), period.windWaveDirectionENG, period.windWaveDirection, AWFDegree];
			doubleValue = period.windWaveDirection;
			break;
		case MaritimeReportViewControllerPeriodRowWindWavePeriod:
			label = NSLocalizedString(@"Period", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f seconds", nil), period.windWavePeriod];
			doubleValue = period.windWavePeriod;
			break;
		case MaritimeReportViewControllerPeriodRowPrimarySwellHeight:
			label = NSLocalizedString(@"Height", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f feet", nil), period.primarySwellHeightFT];
			doubleValue = period.primarySwellHeightM;
			break;
		case MaritimeReportViewControllerPeriodRowPrimarySwellDirection:
			label = NSLocalizedString(@"Direction", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%@ (%.0f%@)", nil), period.primarySwellDirectionENG, period.primarySwellDirection, AWFDegree];
			doubleValue = period.primarySwellDirection;
			break;
		case MaritimeReportViewControllerPeriodRowPrimarySwellPeriod:
			label = NSLocalizedString(@"Period", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f seconds", nil), period.primarySwellPeriod];
			doubleValue = period.primarySwellPeriod;
			break;
		case MaritimeReportViewControllerPeriodRowSecondarySwellHeight:
			label = NSLocalizedString(@"Height", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f feet", nil), period.secondarySwellHeightFT];
			doubleValue = period.secondarySwellHeightM;
			break;
		case MaritimeReportViewControllerPeriodRowSecondarySwellDirection:
			label = NSLocalizedString(@"Direction", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%@ (%.0f%@)", nil), period.secondarySwellDirectionENG, period.secondarySwellDirection, AWFDegree];
			doubleValue = period.secondarySwellDirection;
			break;
		case MaritimeReportViewControllerPeriodRowSecondarySwellPeriod:
			label = NSLocalizedString(@"Period", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f seconds", nil), period.secondarySwellPeriod];
			doubleValue = period.secondarySwellPeriod;
			break;
		case MaritimeReportViewControllerPeriodRowTertiarySwellHeight:
			label = NSLocalizedString(@"Height", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f feet", nil), period.tertiarySwellHeightFT];
			doubleValue = period.tertiarySwellHeightM;
			break;
		case MaritimeReportViewControllerPeriodRowTertiarySwellDirection:
			label = NSLocalizedString(@"Direction", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%@ (%.0f%@)", nil), period.tertiarySwellDirectionENG, period.tertiarySwellDirection, AWFDegree];
			doubleValue = period.tertiarySwellDirection;
			break;
		case MaritimeReportViewControllerPeriodRowTertiarySwellPeriod:
			label = NSLocalizedString(@"Period", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f seconds", nil), period.tertiarySwellPeriod];
			doubleValue = period.tertiarySwellPeriod;
			break;
		case MaritimeReportViewControllerPeriodRowTideLevel:
			label = NSLocalizedString(@"Level", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f feet", nil), period.tideLevelFT];
			doubleValue = period.tideLevelM;
			break;
		case MaritimeReportViewControllerPeriodRowSurgeLevel:
			label = NSLocalizedString(@"Level", nil);
			value = [NSString stringWithFormat:NSLocalizedString(@"%.1f feet", nil), period.surgeLevelFT];
			doubleValue = period.surgeLevelM;
			break;
	}
	
	BOOL valueEnabled = !isnan(doubleValue);
	groupedCell.titleLabel.text = label;
	groupedCell.valueLabel.text = valueEnabled ? value : NSLocalizedString(@"not available", nil);
	groupedCell.valueLabel.textColor = valueEnabled ? UIColor.blackColor : UIColor.grayColor;
	
	groupedCell.titleLabel.font = [UIFont systemFontOfSize:13.0];
	groupedCell.valueLabel.font = [UIFont boldSystemFontOfSize:13.0];
	
	NSInteger nextRowIndex = indexPath.row + 1;
	BOOL nextRowIsSubheader = (nextRowIndex < MaritimeReportViewControllerPeriodRow_Count) && MaritimeReportViewControllerPeriodRowIsSubheader(nextRowIndex);
	if (nextRowIsSubheader) {
		//cell.separatorInset = UIEdgeInsetsZero; // full-width separator line
		cell.separatorInset = UIEdgeInsetsMake(0, 0, 0, UIScreen.mainScreen.bounds.size.width); // no separator line
	} else {
		cell.separatorInset = self.tableView.separatorInset;
	}
}

@end
