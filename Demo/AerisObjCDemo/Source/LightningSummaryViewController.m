//
//  LightningSummaryViewController.m
//  AerisDemo
//
//  Created by Slipp Douglas Thompson on 5/31/23.
//  Copyright © 2023 AerisWeather. All rights reserved.
//

#import "LightningSummaryViewController.h"

@interface LightningSummaryViewController () <UITableViewDataSource>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) AWFLightningSummaries *endpoint;
@property (nonatomic, strong) AWFPlace *place;
@property (nonatomic, strong, nullable) AWFLightningSummary *summary;
@property (nonatomic, strong) ListingEventView *eventView;
@property (nonatomic, strong) NSNumberFormatter *signedPeakAmperageNumberFormatter;
@property (nonatomic, strong) NSNumberFormatter *unsignedPeakAmperageNumberFormatter;

- (NSString *)textStringFromSignedAmperage:(CGFloat)amperageValue;
- (NSString *)textStringFromUnsignedAmperage:(CGFloat)amperageValue;
- (NSString *)textStringFromCount:(NSInteger)countValue;
@end

static NSString *cellIdentifier = @"LightningSummaryCellIdentifier";

@implementation LightningSummaryViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.endpoint = [AWFLightningSummaries new];
		
		NSNumberFormatter *signedPeakAmperageNumberFormatter = [NSNumberFormatter new];
		signedPeakAmperageNumberFormatter.numberStyle = NSNumberFormatterDecimalStyle;
		signedPeakAmperageNumberFormatter.positivePrefix = signedPeakAmperageNumberFormatter.plusSign;
		signedPeakAmperageNumberFormatter.maximumFractionDigits = 0;
		self.signedPeakAmperageNumberFormatter = signedPeakAmperageNumberFormatter;
		
		NSNumberFormatter *unsignedPeakAmperageNumberFormatter = [signedPeakAmperageNumberFormatter copy];
		unsignedPeakAmperageNumberFormatter.positivePrefix = @"";
		unsignedPeakAmperageNumberFormatter.negativePrefix = @"";
		self.unsignedPeakAmperageNumberFormatter = unsignedPeakAmperageNumberFormatter;
	}
	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];

	UITableView *tableView = [UITableView new];
	tableView.translatesAutoresizingMaskIntoConstraints = NO;
	tableView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	tableView.rowHeight = UITableViewAutomaticDimension;
	tableView.separatorInset = UIEdgeInsetsZero;
	tableView.allowsSelection = NO;
	tableView.dataSource = self;
	[tableView registerClass:[AWFTableViewLightningSummaryCell class] forCellReuseIdentifier:cellIdentifier];
	[self.view addSubview:tableView];
	self.tableView = tableView;

	ListingEventView *eventView = [[ListingEventView alloc] initWithFrame:self.view.bounds];
	eventView.translatesAutoresizingMaskIntoConstraints = NO;
	eventView.alpha = 0;
	[self.view addSubview:eventView];
	self.eventView = eventView;
	
	[NSLayoutConstraint activateConstraints:@[
		[tableView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
		[tableView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
		[tableView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
		[tableView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
		[eventView.topAnchor constraintEqualToAnchor:tableView.topAnchor],
		[eventView.leftAnchor constraintEqualToAnchor:tableView.leftAnchor],
		[eventView.rightAnchor constraintEqualToAnchor:tableView.rightAnchor],
		[eventView.bottomAnchor constraintEqualToAnchor:tableView.bottomAnchor]]
	];
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];

	// refresh styles if it's different than the user's preference
	AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
	self.view.backgroundColor = style.viewControllerBackgroundColor;
	self.tableView.backgroundColor = style.viewControllerBackgroundColor;

	self.eventView.backgroundColor = style.viewControllerBackgroundColor;
	self.eventView.messageLabel.textColor = style.defaultTextStyle.textColor;
	self.eventView.detailedMessageLabel.textColor = style.detailTextStyle.textColor;

	[self.tableView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	[self loadDataForDefaultPlace];
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return (self.summary == nil) ? 0 : 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 1;
}

- (NSString *)textStringFromSignedAmperage:(CGFloat)amperageValue {
	if (isnan(amperageValue)) {
		return @"--";
	} else {
		return [NSString stringWithFormat:NSLocalizedString(@"%@ kA", nil),
			[self.signedPeakAmperageNumberFormatter stringFromNumber:@(AWFConvert(amperageValue, AWFUnitAmps, AWFUnitKiloamps))]
		];
	}
}

- (NSString *)textStringFromUnsignedAmperage:(CGFloat)amperageValue {
	if (isnan(amperageValue)) {
		return @"--";
	} else {
		return [NSString stringWithFormat:NSLocalizedString(@"±%@ kA", nil),
			[self.unsignedPeakAmperageNumberFormatter stringFromNumber:@(AWFConvert(amperageValue, AWFUnitAmps, AWFUnitKiloamps))]
		];
	}
}

- (NSString *)textStringFromCount:(NSInteger)countValue {
	if (countValue == NSNotFound) {
		return @"--";
	} else {
		return [NSString stringWithFormat:@"%ld", countValue];
	}
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
	
	if ([cell isKindOfClass:AWFTableViewLightningSummaryCell.class]) {
		AWFTableViewLightningSummaryCell *summaryCell = (AWFTableViewLightningSummaryCell *)cell;
		[summaryCell.weatherView applyStyle:[[Preferences sharedInstance] preferredStyle]];
		
		AWFLightningSummary *summary = (AWFLightningSummary *)self.summary;
		
		summaryCell.weatherView.headerView.textLabel.text = [NSString stringWithFormat:@"%@ - %@",
			[summary.range.minTimestamp awf_formattedDateWithFormat:@"h:mm a" timeZone:self.place.timeZone],
			[summary.range.maxTimestamp awf_formattedDateWithFormat:@"h:mm a" timeZone:self.place.timeZone]
		];
		
		[summaryCell.weatherView removeAllRows];
		
		[summaryCell.weatherView addRowWithTitle:NSLocalizedString(@"Earliest Pulse", nil)
			andValue:[summary.earliestPulseTimestamp awf_formattedDateWithFormat:@"h:mm:ss a" timeZone:self.place.timeZone]
		];
		[summaryCell.weatherView addRowWithTitle:NSLocalizedString(@"Latest Pulse", nil)
			andValue:[summary.latestPulseTimestamp awf_formattedDateWithFormat:@"h:mm:ss a" timeZone:self.place.timeZone]
		];
		
		[summaryCell.weatherView addRowWithTitle:NSLocalizedString(@"Total Pulses", nil)
			andValue:[self textStringFromCount:summary.pulseCount]
		];
		[summaryCell.weatherView addRowWithTitle:NSLocalizedString(@"Cloud-to-Ground Pulses", nil)
			andValue:[self textStringFromCount:summary.cloudToGroundPulseCount]
		];
		[summaryCell.weatherView addRowWithTitle:NSLocalizedString(@"Cloud-to-Cloud Pulses", nil)
			andValue:[self textStringFromCount:summary.intracloudPulseCount]
		];
		[summaryCell.weatherView addRowWithTitle:NSLocalizedString(@"+ Polarity Pulses", nil)
			andValue:[self textStringFromCount:summary.positivePulseCount]
		];
		[summaryCell.weatherView addRowWithTitle:NSLocalizedString(@"- Polarity Pulses", nil)
			andValue:[self textStringFromCount:summary.negativePulseCount]
		];
		
		if (summary.peakAmperage == nil) {
			[summaryCell.weatherView setAllValues:@"--" forWeatherType:AWFWeatherDataTypeLightningPeakAmperage];
		} else {
			[summaryCell.weatherView setMinValue:[self textStringFromUnsignedAmperage:summary.peakAmperage.min] forWeatherType:AWFWeatherDataTypeLightningPeakAmperage];
			[summaryCell.weatherView setMaxValue:[self textStringFromUnsignedAmperage:summary.peakAmperage.max] forWeatherType:AWFWeatherDataTypeLightningPeakAmperage];
			[summaryCell.weatherView setAverageValue:[self textStringFromUnsignedAmperage:summary.peakAmperage.average] forWeatherType:AWFWeatherDataTypeLightningPeakAmperage];
		}
		
		if (summary.peakPositiveAmperage == nil) {
			[summaryCell.weatherView setAllValues:@"--" forWeatherType:AWFWeatherDataTypeLightningPeakPositiveAmperage];
		} else {
			[summaryCell.weatherView setMinValue:[self textStringFromSignedAmperage:summary.peakPositiveAmperage.min] forWeatherType:AWFWeatherDataTypeLightningPeakPositiveAmperage];
			[summaryCell.weatherView setMaxValue:[self textStringFromSignedAmperage:summary.peakPositiveAmperage.max] forWeatherType:AWFWeatherDataTypeLightningPeakPositiveAmperage];
			[summaryCell.weatherView setAverageValue:[self textStringFromSignedAmperage:summary.peakPositiveAmperage.average] forWeatherType:AWFWeatherDataTypeLightningPeakPositiveAmperage];
		}
		
		if (summary.peakNegativeAmperage == nil) {
			[summaryCell.weatherView setAllValues:@"--" forWeatherType:AWFWeatherDataTypeLightningPeakNegativeAmperage];
		} else {
			[summaryCell.weatherView setMinValue:[self textStringFromSignedAmperage:(-summary.peakNegativeAmperage.min)] forWeatherType:AWFWeatherDataTypeLightningPeakNegativeAmperage];
			[summaryCell.weatherView setMaxValue:[self textStringFromSignedAmperage:(-summary.peakNegativeAmperage.max)] forWeatherType:AWFWeatherDataTypeLightningPeakNegativeAmperage];
			[summaryCell.weatherView setAverageValue:[self textStringFromSignedAmperage:(-summary.peakNegativeAmperage.average)] forWeatherType:AWFWeatherDataTypeLightningPeakNegativeAmperage];
		}
		
		if (summary.sensorCount == nil) {
			[summaryCell.weatherView setAllValues:@"--" forWeatherType:AWFWeatherDataTypeLightningSensorCount];
		} else {
			[summaryCell.weatherView setMinValue:[self textStringFromCount:summary.sensorCount.min] forWeatherType:AWFWeatherDataTypeLightningSensorCount];
			[summaryCell.weatherView setMaxValue:[self textStringFromCount:summary.sensorCount.max] forWeatherType:AWFWeatherDataTypeLightningSensorCount];
			[summaryCell.weatherView setAverageValue:[self textStringFromCount:summary.sensorCount.average] forWeatherType:AWFWeatherDataTypeLightningSensorCount];
		}
		
		[summaryCell setNeedsLayout];
	}

	return cell;
}

#pragma mark - Private Methods

- (void)loadDataForDefaultPlace {
	__weak typeof(self) weakSelf = self;
	
	AWFPlace *place = UserLocationsManager.sharedManager.defaultLocation;
	self.place = place;
	
	// load forecast
	AWFWeatherRequestOptions *options = [AWFWeatherRequestOptions new];
	options.limit = 1;

	// only show loader if we haven't already populated the view once
	if (self.summary) {
		[self.eventView showLoading];
	}
	
	[self.endpoint getForPlace:place options:options completion:^(AWFWeatherEndpointResult * _Nullable result) {
		typeof(self) self = weakSelf;
		
		if (result.error) {
			[self.eventView showMessage:NSLocalizedString(@"An error occurred while requesting the weather data.", nil)];
			NSLog(@"Lightning summaries failed to load! %@", result.error.localizedDescription);
			return;
		}
		
		[self.eventView hide];
		
		NSArray *objects = result.results;
		if (objects.count > 0) {
			self.summary = objects.firstObject;
		} else {
			self.summary = nil;
			[self.eventView showNoResultsMessage];
		}
		
		[self.tableView reloadData];
	}];
}

@end
