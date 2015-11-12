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
		
	}

	return self;
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
}

- (void)setupGraphs {
	// temps
	AWFSeriesItem *highTempItem = [[AWFSeriesItem alloc] init];
	highTempItem.title = NSLocalizedString(@"High Temp", nil);
	highTempItem.rendererType = AWFGraphRendererTypeLine;
	highTempItem.xAxisPropertyName = @"periods.#.timestamp";
	highTempItem.yAxisPropertyName = @"periods.#.maxTempF";
	highTempItem.strokeColor = [UIColor redColor];
	highTempItem.interval = 5.0;
	highTempItem.ignoreTime = YES;
	[highTempItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.0f%@F", value, AWFDegree];
	}];
	
	AWFSeriesItem *lowTempItem = [highTempItem copy];
	lowTempItem.title = NSLocalizedString(@"Low Temp", nil);
	lowTempItem.yAxisPropertyName = @"periods.#.minTempF";
	lowTempItem.strokeColor = [UIColor blueColor];
	
	// precip
	AWFSeriesItem *precipItem = [[AWFSeriesItem alloc] init];
	precipItem.title = NSLocalizedString(@"Precip", nil);
	precipItem.rendererType = AWFGraphRendererTypeBar;
	precipItem.xAxisPropertyName = @"periods.#.timestamp";
	precipItem.yAxisPropertyName = @"periods.#.precipIN";
	precipItem.fillColor = [UIColor colorWithRed:0.038 green:0.746 blue:0.000 alpha:1.000];
	precipItem.interval = 0.25;
	precipItem.ignoreTime = YES;
	precipItem.constrainToPositiveValues = YES;
	[precipItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f\"", value];
	}];
	
	AWFGraphSeries *tempSeries = [AWFGraphSeries seriesWithItems:@[highTempItem, lowTempItem]];
	AWFGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Temperatures", nil) series:tempSeries yOffset:10.0];
	self.tempGraph = tempGraph;
	
	AWFGraphSeries *precipSeries = [AWFGraphSeries seriesWithItems:@[precipItem]];
	AWFGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Precipitation", nil) series:precipSeries yOffset:CGRectGetMaxY(tempGraph.frame) + 10.0];
	[precipGraph.yAxis setTickFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f", value];
	}];
	self.precipGraph = precipGraph;
	
	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(precipGraph.frame) + 10.0);
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	if (!self.loader) {
		self.loader = [[AWFObservationsLoader alloc] init];
		self.loader.options.dataType = AerisAPIObservationDataTypeSummary;
		self.loader.options.periodLimit = 14;
		self.loader.options.periodSort = [NSString stringWithFormat:@"dt:%li", (long)AWFRequestSortDescending];
		self.loader.options.fromDate = [[NSDate date] awf_dateByAddingDays:-14 ignoringTime:YES];
	}
	self.loader.options.place = place;
	
	[self.tempGraph.series setLoaderForAllSeriesItems:self.loader];
	[self.precipGraph.series setLoaderForAllSeriesItems:self.loader];
	
	if ([self.delegate respondsToSelector:@selector(graphViewControllerDidStartLoading:)]) {
		//[self.delegate graphViewControllerDidStartLoading:self];
	}
	
	[self.tempGraph reloadData];
	[self.precipGraph reloadData];
}

@end
