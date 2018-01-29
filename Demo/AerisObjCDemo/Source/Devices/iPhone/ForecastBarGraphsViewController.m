//
//  ForecastBarGraphsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "ForecastBarGraphsViewController.h"

@implementation ForecastBarGraphsViewController

- (void)setupGraphs {
	
	// temperatures
	AWFWeatherSeriesItem *highTempItem = [[AWFWeatherSeriesItem alloc] init];
	highTempItem.title = NSLocalizedString(@"High Temp", nil);
	highTempItem.rendererType = AWFGraphRendererTypeBar;
	highTempItem.xAxisPropertyName = @"periods.#.timestamp";
	highTempItem.yAxisPropertyName = @"periods.#.maxTempF";
	highTempItem.fillColor = [UIColor redColor];
	highTempItem.interval = 5.0;
	highTempItem.ignoreTime = YES;
	[highTempItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.0f%@F", value, AWFDegree];
	}];
	
	AWFWeatherSeriesItem *lowTempItem = [highTempItem copy];
	lowTempItem.title = NSLocalizedString(@"Low Temp", nil);
	lowTempItem.yAxisPropertyName = @"periods.#.minTempF";
	lowTempItem.fillColor = [UIColor blueColor];
	
	AWFWeatherGraphSeries *tempSeries = [AWFWeatherGraphSeries seriesWithItems:@[lowTempItem, highTempItem]];
	AWFGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Forecast Temperatures", nil) series:tempSeries];
	self.tempGraph = tempGraph;

	
	// precip
	AWFWeatherSeriesItem *precipItem = [[AWFWeatherSeriesItem alloc] init];
	precipItem.title = NSLocalizedString(@"Precip", nil);
	precipItem.rendererType = AWFGraphRendererTypeBar;
	precipItem.xAxisPropertyName = @"periods.#.timestamp";
	precipItem.yAxisPropertyName = @"periods.#.precipIN";
	precipItem.fillColor = [UIColor colorWithRed:0.036 green:0.704 blue:0.000 alpha:1.000];
	precipItem.interval = 0.25;
	precipItem.ignoreTime = YES;
	precipItem.constrainToPositiveValues = YES;
	[precipItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f\"", value];
	}];
	
	AWFWeatherGraphSeries *precipSeries = [AWFWeatherGraphSeries seriesWithItems:@[precipItem]];
	AWFGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Forecast Precipitation", nil) series:precipSeries];
	[precipGraph.yAxis setTickFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f", value];
	}];
	self.precipGraph = precipGraph;

	
	// snowfall
	AWFWeatherSeriesItem *snowItem = [[AWFWeatherSeriesItem alloc] init];
	snowItem.title = NSLocalizedString(@"Snow", nil);
	snowItem.rendererType = AWFGraphRendererTypeBar;
	snowItem.xAxisPropertyName = @"periods.#.timestamp";
	snowItem.yAxisPropertyName = @"periods.#.snowIN";
	snowItem.fillColor = [UIColor colorWithRed:0.000 green:0.426 blue:1.000 alpha:1.000];
	snowItem.interval = 0.5;
	snowItem.ignoreTime = YES;
	snowItem.constrainToPositiveValues = YES;
	[snowItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.1f\"", value];
	}];
	
	AWFWeatherGraphSeries *snowSeries = [AWFWeatherGraphSeries seriesWithItems:@[snowItem]];
	AWFGraphView *snowGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Forecast Snowfall", nil) series:snowSeries];
	[snowGraph.yAxis setTickFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.1f", value];
	}];
	self.snowGraph = snowGraph;

	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(snowGraph.frame) + 10.0);
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	if (!self.endpoint) {
		self.endpoint = [[AWFForecasts alloc] init];
		self.endpoint.options.limit = 15;
	}
	self.endpoint.options.place = place;
	
	[(AWFWeatherGraphSeries *)self.tempGraph.series setEndpointForAllSeriesItems:self.endpoint];
	[(AWFWeatherGraphSeries *)self.precipGraph.series setEndpointForAllSeriesItems:self.endpoint];
	[(AWFWeatherGraphSeries *)self.snowGraph.series setEndpointForAllSeriesItems:self.endpoint];
	
	if ([self.delegate respondsToSelector:@selector(graphViewControllerDidStartLoading:)]) {
		//[self.delegate graphViewControllerDidStartLoading:self];
	}
	
	[self.tempGraph reloadData];
	[self.precipGraph reloadData];
	[self.snowGraph reloadData];
}

@end
