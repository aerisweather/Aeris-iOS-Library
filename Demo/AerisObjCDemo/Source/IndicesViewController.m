//
//  IndicesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "IndicesViewController.h"

@interface IndicesOptionsViewController : UITableViewController
@property (nonatomic, assign) AWFIndexDataType selectedIndexType;
@property (nonatomic, strong) NSArray *indexTypes;
@property (nonatomic, unsafe_unretained) id <OptionsViewControllerDelegate> delegate;
@end

@protocol OptionsViewControllerDelegate <NSObject>
- (void)optionsViewControllerDidChangeSelectedOption:(UIViewController *)optionsViewController;
@end

@interface IndicesViewController () <OptionsViewControllerDelegate>
@property (nonatomic, strong) AWFIndices *endpoint;
@property (nonatomic, assign) AWFIndexDataType dataLastIndexType;
@property (nonatomic, strong) UINavigationController *optionsController;
@end

@implementation IndicesViewController

@synthesize endpoint;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.endpoint = [[AWFIndices alloc] initWithIndexType:AWFIndexDataTypeArthritis];
		self.currentIndexType = AWFIndexDataTypeArthritis;
	}
	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];

	self.title = NSLocalizedString(@"Indices", nil);
	self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"Type", nil) style:UIBarButtonItemStylePlain target:self action:@selector(showOptions)];
	self.tableView.allowsSelection = NO;
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	//[TestFlight passCheckpoint:TFCheckpointIndices];

	[self loadDataForDefaultPlace];
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.toDate = [[[NSDate date] awf_dateByIgnoringTime] awf_dateByAddingDays:7];
	self.place = place;

	[self loadDataForPlace:place options:options];
}

#pragma mark - GroupedListingViewController

- (void)loadDataForPlace:(AWFPlace *)place options:(AWFWeatherRequestOptions *)options {
	if (self.endpoint) {
		[self.eventView showLoading];
		
		if (self.currentIndexType != self.dataLastIndexType) {
			self.endpoint = [[AWFIndices alloc] initWithIndexType:self.currentIndexType];
			self.dataLastIndexType = self.currentIndexType;
		}

		__weak typeof(self) weakSelf = self;
		[self.endpoint getForPlace:place options:options completion:^(AWFWeatherEndpointResult * _Nullable result) {
		    if (result.error) {
		        NSLog(@"Listing data failed to load! %@", result.error);
		        [weakSelf.eventView showMessage:NSLocalizedString(@"An error occurred during the request.", nil)];
		        return;
			}

		    NSArray *objects = result.results;
			if ([objects count] > 0) {
		        weakSelf.results = objects;
		        [weakSelf.tableView reloadData];
		        [weakSelf.tableView setContentOffset:CGPointZero];
		        [weakSelf.eventView hide];
			} else {
		        weakSelf.results = @[];
		        [weakSelf.eventView showNoResultsMessage];
			}
		}];
	}
}

#pragma mark - ListingViewController

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath {
	GroupedTableViewCell *groupedCell = (GroupedTableViewCell *)cell;
	AWFIndexPeriod *report = nil;

	NSString *label;
	NSString *value;

	if ([self.results count] > 0) {
		report = (AWFIndexPeriod *)self.results[0];
	}

	switch (indexPath.section) {
		case 0: {
			AWFIndexDataType type = self.currentIndexType;
			NSString *typeName;
			
			if (type == AWFIndexDataTypeArthritis) {
				typeName = NSLocalizedString(@"Arthritis", nil);
			} else if (type == AWFIndexDataTypeColdFlu) {
				typeName = NSLocalizedString(@"Cold & Flu", nil);
			} else if (type == AWFIndexDataTypeMigraine) {
				typeName = NSLocalizedString(@"Migraine", nil);
			} else if (type == AWFIndexDataTypeSinus) {
				typeName = NSLocalizedString(@"Sinus", nil);
			} else if (type == AWFIndexDataTypeOutdoors) {
				typeName = NSLocalizedString(@"Outdoor", nil);
			}

			cell.textLabel.text = typeName;
			break;
		}

		// current
		case 1: {
			AWFIndex *currentIndex = report.current;
			switch (indexPath.row) {
				case 0:
					label = NSLocalizedString(@"Date", nil);
					value = [currentIndex.timestamp awf_formattedDateWithFormat:@"M/d/y h:mm a" timeZone:self.place.timeZone];
					break;
				case 1:
					label = NSLocalizedString(@"Index", nil);
					value = [NSString stringWithFormat:@"%li", currentIndex.index];
					break;
				case 2:
					label = NSLocalizedString(@"Risk", nil);
					value = currentIndex.indexString;
					break;
			}
			cell.textLabel.text = nil;
			break;
		}

		// forecast
		default: {
			if ([report.forecast count] == 0) {
				label = NSLocalizedString(@"No tidal information.", nil);
			} else {
				AWFIndex *forecastIndex = (AWFIndex *)report.forecast[indexPath.section - 2];
				switch (indexPath.row) {
					case 0:
						label = NSLocalizedString(@"Date", nil);
						value = [forecastIndex.timestamp awf_formattedDateWithFormat:@"M/d/y" timeZone:self.place.timeZone];
						break;
					case 1:
						label = NSLocalizedString(@"Index", nil);
						value = [NSString stringWithFormat:@"%li", forecastIndex.index];
						break;
					case 2:
						label = NSLocalizedString(@"Risk", nil);
						value = forecastIndex.indexString;
						break;
				}
			}
			cell.textLabel.text = nil;
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
		AWFIndexPeriod *report = (AWFIndexPeriod *)self.results[0];
		total += [report.forecast count];
	}

	return total;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	if (section == 1) {
		return NSLocalizedString(@"Current Index", nil);
	} else if (section == 2) {
		return NSLocalizedString(@"Forecasted Indices", nil);
	}

	return nil;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	NSInteger rows = 3;

	if (section == 0) {
		rows = 1;
	}

	return rows;
}

#pragma mark - OptionsViewControllerDelegate

- (void)optionsViewControllerDidChangeSelectedOption:(UIViewController *)optionsViewController {
	self.currentIndexType = ((IndicesOptionsViewController *)optionsViewController).selectedIndexType;
}

#pragma mark - Private Methods

- (void)showOptions {
	IndicesOptionsViewController *optionsController;

	if (!self.optionsController) {
		optionsController = [[IndicesOptionsViewController alloc] initWithNibName:nil bundle:nil];
		optionsController.delegate = self;

		self.optionsController = [[UINavigationController alloc] initWithRootViewController:optionsController];
	} else {
		optionsController = (IndicesOptionsViewController *)self.optionsController.topViewController;
	}

	[self.navigationController presentViewController:self.optionsController animated:YES completion:nil];
}

@end


@implementation IndicesOptionsViewController

static NSString *optionCellIdentifier = @"OptionCell";

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.indexTypes = @[AWFIndexDataTypeArthritis, AWFIndexDataTypeColdFlu, AWFIndexDataTypeMigraine, AWFIndexDataTypeSinus, AWFIndexDataTypeOutdoors];
	}
	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];
	[self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:optionCellIdentifier];
}

- (void)close {
	[self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return [self.indexTypes count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:optionCellIdentifier];

	AWFIndexDataType type = self.indexTypes[indexPath.row];
	NSString *typeName;

	if (type == AWFIndexDataTypeArthritis) {
		typeName = NSLocalizedString(@"Arthritis", nil);
	} else if (type == AWFIndexDataTypeColdFlu) {
		typeName = NSLocalizedString(@"Cold & Flu", nil);
	} else if (type == AWFIndexDataTypeMigraine) {
		typeName = NSLocalizedString(@"Migraine", nil);
	} else if (type == AWFIndexDataTypeSinus) {
		typeName = NSLocalizedString(@"Sinus", nil);
	} else if (type == AWFIndexDataTypeOutdoors) {
		typeName = NSLocalizedString(@"Outdoor", nil);
	}

	cell.textLabel.text = typeName;
	cell.selected = (self.selectedIndexType == type);

	return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	AWFIndexDataType indexType = self.indexTypes[indexPath.row];
	if (indexType != self.selectedIndexType) {
		self.selectedIndexType = indexType;

		if ([self.delegate respondsToSelector:@selector(optionsViewControllerDidChangeSelectedOption:)]) {
			[self.delegate optionsViewControllerDidChangeSelectedOption:self];
		}
	}

	[self close];
}

@end
