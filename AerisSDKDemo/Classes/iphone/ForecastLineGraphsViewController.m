//
//  ForecastLineGraphsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "ForecastLineGraphsViewController.h"

@implementation ForecastLineGraphsViewController

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
	
	// temperature
	AWFSeriesItem *tempItem = [[AWFSeriesItem alloc] init];
	tempItem.title = NSLocalizedString(@"Temp", nil);
	tempItem.rendererType = AWFGraphRendererTypeLine;
	tempItem.xAxisPropertyName = @"periods.#.timestamp";
	tempItem.yAxisPropertyName = @"periods.#.tempF";
	tempItem.strokeColor = [UIColor redColor];
	tempItem.interval = 5.0;
	[tempItem setValueFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.0f%@F", value, AWFDegree];
	}];
	
	AWFSeriesItem *feelsLikeItem = [tempItem copy];
	feelsLikeItem.title = NSLocalizedString(@"Feels Like", nil);
	feelsLikeItem.yAxisPropertyName = @"periods.#.feelslikeF";
	feelsLikeItem.strokeColor = [UIColor colorWithRed:1.000 green:0.678 blue:0.000 alpha:1.000];
	
	AWFSeriesItem *dewpointItem = [tempItem copy];
	dewpointItem.title = NSLocalizedString(@"Dew Point", nil);
	dewpointItem.yAxisPropertyName = @"periods.#.dewpointF";
	dewpointItem.strokeColor = [UIColor blueColor];
	
	AWFGraphSeries *tempSeries = [AWFGraphSeries seriesWithItems:@[tempItem, feelsLikeItem, dewpointItem]];
	tempSeries.roundingTimeInterval = AWFHourInterval;
	AWFGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Temperature + Dewpoint", nil) series:tempSeries yOffset:10.0];
	self.tempGraph = tempGraph;
	
	
	// precip
	AWFSeriesItem *precipItem = [[AWFSeriesItem alloc] init];
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
	
	AWFGraphSeries *precipSeries = [AWFGraphSeries seriesWithItems:@[precipItem]];
	AWFGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Precipitation", nil) series:precipSeries yOffset:CGRectGetMaxY(tempGraph.frame) + 10.0];
	[precipGraph.yAxis setTickFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f", value];
	}];
	self.precipGraph = precipGraph;

	
	// winds
	AWFSeriesItem *windItem = [[AWFSeriesItem alloc] init];
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
	
	AWFGraphSeries *windSeries = [AWFGraphSeries seriesWithItems:@[windItem]];
	AWFGraphView *windsGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Winds", nil) series:windSeries yOffset:CGRectGetMaxY(precipGraph.frame) + 10.0];
	self.windGraph = windsGraph;

	
	// sky
	AWFSeriesItem *skyItem = [[AWFSeriesItem alloc] init];
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
	
	AWFSeriesItem *humidityItem = [skyItem copy];
	humidityItem.title = NSLocalizedString(@"Humidity", nil);
	humidityItem.yAxisPropertyName = @"periods.#.humidity";
	humidityItem.strokeColor = [UIColor purpleColor];
	
	AWFSeriesItem *popItem = [skyItem copy];
	popItem.title = NSLocalizedString(@"POP", nil);
	popItem.yAxisPropertyName = @"periods.#.pop";
	popItem.strokeColor = [UIColor colorWithRed:0.092 green:0.496 blue:0.039 alpha:1.000];
	
	AWFGraphSeries *skySeries = [AWFGraphSeries seriesWithItems:@[skyItem, humidityItem, popItem]];
	AWFGraphView *skyGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Sky Conditions", nil) series:skySeries yOffset:CGRectGetMaxY(windsGraph.frame) + 10.0];
	skyGraph.yAxisRange = AWFGraphSeriesRangeMake(0, 100);
	self.skyGraph = skyGraph;

	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(skyGraph.frame) + 10.0);
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	if (!self.loader) {
		self.loader = [[AWFForecastsLoader alloc] init];
		self.loader.options.filterString = @"3hr";
		self.loader.options.limit = 40;
	}
	self.loader.options.place = place;
	
	[self.tempGraph.series setLoaderForAllSeriesItems:self.loader];
	[self.precipGraph.series setLoaderForAllSeriesItems:self.loader];
	[self.windGraph.series setLoaderForAllSeriesItems:self.loader];
	[self.skyGraph.series setLoaderForAllSeriesItems:self.loader];

	if ([self.delegate respondsToSelector:@selector(graphViewControllerDidStartLoading:)]) {
		//[self.delegate graphViewControllerDidStartLoading:self];
	}
	
	[self.tempGraph reloadData];
	[self.precipGraph reloadData];
	[self.windGraph reloadData];
	[self.skyGraph reloadData];
}

@end
