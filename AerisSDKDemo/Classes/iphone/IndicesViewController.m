//
//  IndicesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "IndicesViewController.h"
#import "ListingEventView.h"
#import "GroupedTableViewCell.h"

@interface IndicesOptionsViewController : UITableViewController
@property (nonatomic, assign) AWFIndexType selectedIndexType;
@property (nonatomic, strong) NSArray *indexTypes;
@property (nonatomic, unsafe_unretained) id <OptionsViewControllerDelegate> delegate;
@end

@protocol OptionsViewControllerDelegate <NSObject>
- (void)optionsViewControllerDidChangeSelectedOption:(UIViewController *)optionsViewController;
@end

@interface IndicesViewController () <OptionsViewControllerDelegate>
@property (nonatomic, strong) AWFIndicesLoader *loader;
@property (nonatomic, strong) UINavigationController *optionsController;
@end

@implementation IndicesViewController

@synthesize loader;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.loader = [[AWFIndicesLoader alloc] init];
		self.currentIndexType = AWFIndexTypeArthritis;
	}

	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];

	self.title = NSLocalizedString(@"Indices", nil);
	self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"Type", nil) style:UIBarButtonItemStyleBordered target:self action:@selector(showOptions)];
	self.tableView.allowsSelection = NO;
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];

	[self loadDataForDefaultPlace];
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.toDate = [[NSDate date] awf_dateByAddingDays:7 ignoringTime:NO];

	[self loadDataForPlace:place options:options];
}

#pragma mark - GroupedListingViewController

- (void)loadDataForPlace:(AWFPlace *)place options:(AWFRequestOptions *)options {
	if (self.loader) {
		[self.eventView showLoading];

		__weak typeof(self) weakSelf = self;

		[self.loader getIndicesOfType:self.currentIndexType forPlace:place options:options completion:^(NSArray *objects, NSError *error) {
		    if (error) {
		        NSLog(@"Listing data failed to load! %@", error);
		        [weakSelf.eventView showMessage:NSLocalizedString(@"An error occurred during the request.", nil)];

		        return;
			}

		    if ([objects count] > 0) {
		        weakSelf.results = objects;
		        [weakSelf.tableView reloadData];
		        [weakSelf.tableView setContentOffset:CGPointZero];
		        [weakSelf.eventView hide];
			}
		    else {
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
			NSString *typeName;

			switch (self.currentIndexType) {
				case AWFIndexTypeArthritis:
					typeName = NSLocalizedString(@"Arthritis", nil);
					break;

				case AWFIndexTypeColdFlu:
					typeName = NSLocalizedString(@"Cold & Flu", nil);
					break;

				case AWFIndexTypeMigraine:
					typeName = NSLocalizedString(@"Migraine", nil);
					break;

				case AWFIndexTypeSinus:
					typeName = NSLocalizedString(@"Sinuses", nil);
					break;

				default:
					break;
			}

			cell.textLabel.text = typeName;

			break;
		}

		// current
		case 1: {
			AWFIndex *currentIndex = report.current;
			switch (indexPath.row) {
				case 0:
					// set global NSDateFormatter timezone to local time
					[NSDate awf_setDefaultTimezone:report.place.timeZone];

					label = NSLocalizedString(@"Date", nil);
					value = [currentIndex.timestamp awf_stringWithFormat:@"M/d/y h:mm a"];
					break;

				case 1:
					label = NSLocalizedString(@"Index", nil);
					value = [NSString stringWithFormat:@"%i", [currentIndex.index intValue]];
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
			}
			else {
				AWFIndex *forecastIndex = (AWFIndex *)report.forecast[indexPath.section - 2];
				switch (indexPath.row) {
					case 0:
						// set global NSDateFormatter timezone to local time
						[NSDate awf_setDefaultTimezone:report.place.timeZone];

						label = NSLocalizedString(@"Date", nil);
						value = [forecastIndex.timestamp awf_stringWithFormat:@"M/d/y"];
						break;

					case 1:
						label = NSLocalizedString(@"Index", nil);
						value = [NSString stringWithFormat:@"%i", [forecastIndex.index intValue]];
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

	groupedCell.descriptionLabel.text = label;
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
	}
	else if (section == 2) {
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
	}
	else {
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
		self.indexTypes = @[@(AWFIndexTypeArthritis), @(AWFIndexTypeColdFlu), @(AWFIndexTypeMigraine), @(AWFIndexTypeSinus)];
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

	AWFIndexType indexType = [self.indexTypes[indexPath.row] intValue];
	NSString *typeName;

	switch (indexType) {
		case AWFIndexTypeArthritis:
			typeName = NSLocalizedString(@"Arthritis", nil);
			break;

		case AWFIndexTypeColdFlu:
			typeName = NSLocalizedString(@"Cold & Flu", nil);
			break;

		case AWFIndexTypeMigraine:
			typeName = NSLocalizedString(@"Migraine", nil);
			break;

		case AWFIndexTypeSinus:
			typeName = NSLocalizedString(@"Sinuses", nil);
			break;

		default:
			break;
	}

	cell.textLabel.text = typeName;
	cell.selected = (self.selectedIndexType == indexType);

	return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	AWFIndexType indexType = [self.indexTypes[indexPath.row] intValue];
	if (indexType != self.selectedIndexType) {
		self.selectedIndexType = indexType;

		if ([self.delegate respondsToSelector:@selector(optionsViewControllerDidChangeSelectedOption:)]) {
			[self.delegate optionsViewControllerDidChangeSelectedOption:self];
		}
	}

	[self close];
}

@end
