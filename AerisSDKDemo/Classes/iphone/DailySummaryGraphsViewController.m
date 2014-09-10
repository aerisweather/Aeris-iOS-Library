//
//  DailySummaryGraphsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "DailySummaryGraphsViewController.h"

@interface DailySummaryGraphsViewController ()

@end

@implementation DailySummaryGraphsViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.loader = [[AWFObservationsLoader alloc] init];
	}

	return self;
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
}

- (void)setupGraphs {
	AWFBarGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Temperatures", nil) yOffset:10.0];
	tempGraph.valueInterval = 5.0;
	tempGraph.stringFormatForValue = [@"%.0f" stringByAppendingString:AWFDegree];
	self.tempGraph = tempGraph;

	AWFBarGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Precipitation", nil) yOffset:CGRectGetMaxY(tempGraph.frame) + 10.0];
	precipGraph.valueInterval = 1.0;
	precipGraph.constrainToPositiveValues = YES;
	precipGraph.stringFormatForValue = @"%.2f\"";
	self.precipGraph = precipGraph;

	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(precipGraph.frame) + 10.0);
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];

	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.periodLimit = 14;
	options.periodSort = [NSString stringWithFormat:@"dt:%i", AWFRequestSortDescending];

	NSDate *fromDate = [[NSDate date] awf_dateByAddingDays:-14];

	if ([self.delegate respondsToSelector:@selector(graphViewControllerDidStartLoading:)]) {
		[self.delegate graphViewControllerDidStartLoading:self];
	}

	AWFObservationsLoader *loader = (AWFObservationsLoader *)self.loader;
	[loader getObservationSummaryForPlace:place fromDate:fromDate toDate:nil options:options completion:^(NSArray *objects, NSError *error) {
	    if (error) {
	        if ([self.delegate respondsToSelector:@selector(graphViewController:didFailLoading:)]) {
	            [self.delegate graphViewController:self didFailLoading:error];
			}

	        return;
		}

	    if ([objects count] > 0) {
	        self.data = ((AWFObservationSummary *)objects[0]).periods;
		}
	    if ([self.delegate respondsToSelector:@selector(graphViewControllerDidFinishLoading:)]) {
	        [self.delegate graphViewControllerDidFinishLoading:self];
		}
	}];
}

#pragma mark - AWFBarGraphViewDataSource

- (NSInteger)numberOfDatasetsForBarGraph:(AWFBarGraphView *)barGraph {
	return 1;
}

- (NSInteger)barGraph:(AWFBarGraphView *)barGraph numberOfBarsInDataset:(NSInteger)dataset {
	return [self.data count];
}

- (AWFGraphBar *)barGraph:(AWFBarGraphView *)barGraph barForItemAtIndexPath:(NSIndexPath *)indexPath {
	AWFObservationSummaryPeriod *period = (AWFObservationSummaryPeriod *)self.data[indexPath.row];
	NSDate *date = period.timestamp;

	AWFGraphBar *graphBar = [[AWFGraphBar alloc] init];
	graphBar.label = [NSString stringWithFormat:@"%@", [date awf_stringWithFormat:AWFDateFormatDayName]];

	if (barGraph == self.tempGraph) {
		graphBar.minValue = [period.minTempF floatValue];
		graphBar.maxValue = [period.maxTempF floatValue];
	}
	else if (barGraph == self.precipGraph) {
		graphBar.minValue = 0;
		graphBar.maxValue = [period.precipIN floatValue];
	}

	return graphBar;
}

- (NSString *)barGraph:(AWFBarGraphView *)barGraph titleForDatasetAtIndex:(NSInteger)index {
	NSString *title;

	if (barGraph == self.tempGraph) {
		title = NSLocalizedString(@"Temp", nil);
	}
	else if (barGraph == self.precipGraph) {
		title = NSLocalizedString(@"Precip", nil);
	}

	return title;
}

- (UIColor *)barGraph:(AWFBarGraphView *)barGraph barColorForDatasetAtIndex:(NSInteger)index {
	UIColor *color;

	if (barGraph == self.tempGraph) {
		color = [UIColor colorWithRed:0.834 green:0.000 blue:0.000 alpha:1.000];
	}
	else if (barGraph == self.precipGraph) {
		color = [UIColor colorWithRed:0.036 green:0.704 blue:0.000 alpha:1.000];
	}

	return color;
}

#pragma mark - AWFBarGraphViewDelegate

- (void)barGraph:(AWFBarGraphView *)barGraph didSelectBarAtIndexPath:(NSIndexPath *)indexPath {
	AWFObservationSummaryPeriod *period = (AWFObservationSummaryPeriod *)self.data[indexPath.row];
	CGFloat minValue = 0, maxValue = 0;

	if (barGraph == self.tempGraph) {
		minValue = [period.minTempF floatValue];
		maxValue = [period.maxTempF floatValue];
	}
	else {
		minValue = 0;
		maxValue = [period.precipIN floatValue];
	}
	NSLog(@"selected bar at %@: min value=%.2f, max value=%.2f", indexPath, minValue, maxValue);
}

@end
