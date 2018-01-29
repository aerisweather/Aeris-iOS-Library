//
//  RecentObsGraphViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "RecentObsGraphViewController.h"

@interface RecentObsGraphViewController ()
@end

@implementation RecentObsGraphViewController

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	//[TestFlight passCheckpoint:TFCheckpointRecentObsGraphs];
}

- (void)setupGraphs {
	
	// temperature
	AWFWeatherSeriesItem *tempItem = [[AWFWeatherSeriesItem alloc] init];
	tempItem.title = NSLocalizedString(@"Temp", nil);
	tempItem.rendererType = AWFGraphRendererTypeLine;
	tempItem.xAxisPropertyName = @"periods.#.timestamp";
	tempItem.yAxisPropertyName = @"periods.#.tempF";
	tempItem.strokeColor = [UIColor redColor];
	tempItem.interval = 5.0;
	[tempItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.0f%@F", value, AWFDegree];
	}];
	
	AWFWeatherSeriesItem *feelsLikeItem = [tempItem copy];
	feelsLikeItem.title = NSLocalizedString(@"Feels Like", nil);
	feelsLikeItem.yAxisPropertyName = @"periods.#.feelslikeF";
	feelsLikeItem.strokeColor = [UIColor colorWithRed:1.000 green:0.678 blue:0.000 alpha:1.000];
	
	AWFWeatherSeriesItem *dewpointItem = [tempItem copy];
	dewpointItem.title = NSLocalizedString(@"Dew Point", nil);
	dewpointItem.yAxisPropertyName = @"periods.#.dewpointF";
	dewpointItem.strokeColor = [UIColor blueColor];
	
	AWFWeatherGraphSeries *tempSeries = [AWFWeatherGraphSeries seriesWithItems:@[tempItem, feelsLikeItem, dewpointItem]];
	AWFGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Temperature + Dewpoint", nil) series:tempSeries];
	self.tempGraph = tempGraph;
	
	
	// precip
	AWFWeatherSeriesItem *precipItem = [[AWFWeatherSeriesItem alloc] init];
	precipItem.title = NSLocalizedString(@"Precip", nil);
	precipItem.rendererType = AWFGraphRendererTypeLine;
	precipItem.xAxisPropertyName = @"periods.#.timestamp";
	precipItem.yAxisPropertyName = @"periods.#.precipIN";
	precipItem.fillColor = [UIColor colorWithRed:0.038 green:0.746 blue:0.000 alpha:0.500];
	precipItem.strokeColor = [UIColor colorWithRed:0.038 green:0.746 blue:0.000 alpha:1.000];
	precipItem.interval = 0.1;
	precipItem.constrainToPositiveValues = YES;
	[precipItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f\"", value];
	}];
	
	AWFWeatherGraphSeries *precipSeries = [AWFWeatherGraphSeries seriesWithItems:@[precipItem]];
	AWFGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Precipitation", nil) series:precipSeries];
	[precipGraph.yAxis setTickFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f", value];
	}];
	self.precipGraph = precipGraph;
	
	
	// winds
	AWFWeatherSeriesItem *windItem = [[AWFWeatherSeriesItem alloc] init];
	windItem.title = NSLocalizedString(@"Winds", nil);
	windItem.rendererType = AWFGraphRendererTypeLine;
	windItem.xAxisPropertyName = @"periods.#.timestamp";
	windItem.yAxisPropertyName = @"periods.#.windSpeedMPH";
	windItem.fillColor = [UIColor colorWithRed:0.000 green:0.548 blue:0.911 alpha:0.500];
	windItem.strokeColor = [UIColor colorWithRed:0.000 green:0.548 blue:0.911 alpha:1.000];
	windItem.interval = 5.0;
	windItem.constrainToPositiveValues = YES;
	[windItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.0fmph", value];
	}];
	
	AWFWeatherGraphSeries *windSeries = [AWFWeatherGraphSeries seriesWithItems:@[windItem]];
	AWFGraphView *windsGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Winds", nil) series:windSeries];
	self.windGraph = windsGraph;
	
	
	// sky
	AWFWeatherSeriesItem *skyItem = [[AWFWeatherSeriesItem alloc] init];
	skyItem.title = NSLocalizedString(@"Sky Cover", nil);
	skyItem.rendererType = AWFGraphRendererTypeLine;
	skyItem.xAxisPropertyName = @"periods.#.timestamp";
	skyItem.yAxisPropertyName = @"periods.#.skyCoverPercentage";
	skyItem.strokeColor = [UIColor colorWithWhite:0.3 alpha:1.0];
	skyItem.interval = 5.0;
	skyItem.constrainToPositiveValues = YES;
	[skyItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.0f%%", value];
	}];
	
	AWFWeatherSeriesItem *humidityItem = [skyItem copy];
	humidityItem.title = NSLocalizedString(@"Humidity", nil);
	humidityItem.yAxisPropertyName = @"periods.#.humidity";
	humidityItem.strokeColor = [UIColor purpleColor];
	
	AWFWeatherGraphSeries *skySeries = [AWFWeatherGraphSeries seriesWithItems:@[skyItem, humidityItem]];
	AWFGraphView *skyGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Sky Conditions", nil) series:skySeries];
	self.skyGraph = skyGraph;
	
	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(skyGraph.frame) + 10.0);
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	if (!self.endpoint) {
		self.endpoint = [AWFObservationsArchive new];
		self.endpoint.options.periodLimit = 12;
	}
	self.endpoint.options.place = place;
	
	[(AWFWeatherGraphSeries *)self.tempGraph.series setEndpointForAllSeriesItems:self.endpoint];
	[(AWFWeatherGraphSeries *)self.precipGraph.series setEndpointForAllSeriesItems:self.endpoint];
	[(AWFWeatherGraphSeries *)self.windGraph.series setEndpointForAllSeriesItems:self.endpoint];
	[(AWFWeatherGraphSeries *)self.skyGraph.series setEndpointForAllSeriesItems:self.endpoint];
	
	[self.tempGraph reloadData];
	[self.precipGraph reloadData];
	[self.windGraph reloadData];
	[self.skyGraph reloadData];
}

@end
