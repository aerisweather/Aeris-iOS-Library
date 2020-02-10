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

- (void)setupGraphs {
	// temps
	AWFWeatherSeriesItem *highTempItem = [[AWFWeatherSeriesItem alloc] init];
	highTempItem.title = NSLocalizedString(@"High Temp", nil);
	highTempItem.rendererType = AWFGraphRendererTypeLine;
	highTempItem.xAxisPropertyName = @"periods.#.timestamp";
	highTempItem.yAxisPropertyName = @"periods.#.tempF.max";
	highTempItem.strokeColor = [UIColor redColor];
	highTempItem.interval = 5.0;
	highTempItem.ignoreTime = YES;
	[highTempItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.0f%@F", value, AWFDegree];
	}];
	
	AWFWeatherSeriesItem *lowTempItem = [highTempItem copy];
	lowTempItem.title = NSLocalizedString(@"Low Temp", nil);
	lowTempItem.yAxisPropertyName = @"periods.#.tempF.min";
	lowTempItem.strokeColor = [UIColor blueColor];
	
	// precip
	AWFWeatherSeriesItem *precipItem = [[AWFWeatherSeriesItem alloc] init];
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
	
	AWFWeatherGraphSeries *tempSeries = [AWFWeatherGraphSeries seriesWithItems:@[highTempItem, lowTempItem]];
	AWFGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Temperatures", nil) series:tempSeries];
	self.tempGraph = tempGraph;
	
	AWFWeatherGraphSeries *precipSeries = [AWFWeatherGraphSeries seriesWithItems:@[precipItem]];
	AWFGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Precipitation", nil) series:precipSeries];
	[precipGraph.yAxis setTickFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f", value];
	}];
	self.precipGraph = precipGraph;
	
	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(precipGraph.frame) + 10.0);
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	if (!self.endpoint) {
		self.endpoint = [AWFObservationsSummaries new];
		self.endpoint.options.periodLimit = 14;
		self.endpoint.options.periodSort = [NSString stringWithFormat:@"dt:%li", (long)AWFRequestSortDescending];
		self.endpoint.options.fromDate = [[[NSDate date] awf_dateByIgnoringTime] awf_dateBySubtractingDays:14];
	}
	self.endpoint.options.place = place;
	
	[(AWFWeatherGraphSeries *)self.tempGraph.series setEndpointForAllSeriesItems:self.endpoint];
	[(AWFWeatherGraphSeries *)self.precipGraph.series setEndpointForAllSeriesItems:self.endpoint];
	
	if ([self.delegate respondsToSelector:@selector(graphViewControllerDidStartLoading:)]) {
		//[self.delegate graphViewControllerDidStartLoading:self];
	}
	
	[self.tempGraph reloadData];
	[self.precipGraph reloadData];
}

@end
