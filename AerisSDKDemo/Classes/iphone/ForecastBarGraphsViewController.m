//
//  ForecastBarGraphsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "ForecastBarGraphsViewController.h"

@implementation ForecastBarGraphsViewController

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
	
	// temperatures
	AWFSeriesItem *highTempItem = [[AWFSeriesItem alloc] init];
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
	
	AWFSeriesItem *lowTempItem = [highTempItem copy];
	lowTempItem.title = NSLocalizedString(@"Low Temp", nil);
	lowTempItem.yAxisPropertyName = @"periods.#.minTempF";
	lowTempItem.fillColor = [UIColor blueColor];
	
	AWFGraphSeries *tempSeries = [AWFGraphSeries seriesWithItems:@[lowTempItem, highTempItem]];
	AWFGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Forecast Temperatures", nil) series:tempSeries yOffset:10.0];
	self.tempGraph = tempGraph;

	
	// precip
	AWFSeriesItem *precipItem = [[AWFSeriesItem alloc] init];
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
	
	AWFGraphSeries *precipSeries = [AWFGraphSeries seriesWithItems:@[precipItem]];
	AWFGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Forecast Precipitation", nil) series:precipSeries yOffset:CGRectGetMaxY(tempGraph.frame) + 10.0];
	[precipGraph.yAxis setTickFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f", value];
	}];
	self.precipGraph = precipGraph;

	
	// snowfall
	AWFSeriesItem *snowItem = [[AWFSeriesItem alloc] init];
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
	
	AWFGraphSeries *snowSeries = [AWFGraphSeries seriesWithItems:@[snowItem]];
	AWFGraphView *snowGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Forecast Snowfall", nil) series:snowSeries yOffset:CGRectGetMaxY(precipGraph.frame) + 10.0];
	[snowGraph.yAxis setTickFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.1f", value];
	}];
	self.snowGraph = snowGraph;

	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(snowGraph.frame) + 10.0);
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	if (!self.loader) {
		self.loader = [[AWFForecastsLoader alloc] init];
		self.loader.options.limit = 15;
	}
	self.loader.options.place = place;
	
	[self.tempGraph.series setLoaderForAllSeriesItems:self.loader];
	[self.precipGraph.series setLoaderForAllSeriesItems:self.loader];
	[self.snowGraph.series setLoaderForAllSeriesItems:self.loader];
	
	if ([self.delegate respondsToSelector:@selector(graphViewControllerDidStartLoading:)]) {
		//[self.delegate graphViewControllerDidStartLoading:self];
	}
	
	[self.tempGraph reloadData];
	[self.precipGraph reloadData];
	[self.snowGraph reloadData];

//	AWFForecastsLoader *loader = (AWFForecastsLoader *)self.loader;
//	[loader getForecastForPlace:place options:forecastOptions completion:^(NSArray *objects, NSError *error) {
//	    if (error) {
//	        if ([self.delegate respondsToSelector:@selector(graphViewController:didFailLoading:)]) {
//	            [self.delegate graphViewController:self didFailLoading:error];
//			}
//
//	        return;
//		}
//
//	    if ([objects count] > 0) {
//	        self.data = ((AWFForecast *)objects[0]).periods;
//		}
//	    if ([self.delegate respondsToSelector:@selector(graphViewControllerDidFinishLoading:)]) {
//	        [self.delegate graphViewControllerDidFinishLoading:self];
//		}
//	}];
}

//#pragma mark - AWFBarGraphViewDataSource
//
//- (NSInteger)numberOfDatasetsForBarGraph:(AWFBarGraphView *)barGraph {
//	return 1;
//}
//
//- (NSInteger)barGraph:(AWFBarGraphView *)barGraph numberOfBarsInDataset:(NSInteger)dataset {
//	return [self.data count];
//}
//
//- (AWFGraphBar *)barGraph:(AWFBarGraphView *)barGraph barForItemAtIndexPath:(NSIndexPath *)indexPath {
//	AWFForecastPeriod *period = (AWFForecastPeriod *)self.data[indexPath.row];
//	NSDate *date = period.timestamp;
//
//	AWFGraphBar *graphBar = [[AWFGraphBar alloc] init];
//	graphBar.label = [NSString stringWithFormat:@"%@", [date awf_stringWithFormat:AWFDateFormatDayName]];
//
//	if (barGraph == self.tempGraph) {
//		graphBar.minValue = [period.minTempF floatValue];
//		graphBar.maxValue = [period.maxTempF floatValue];
//	}
//	else if (barGraph == self.precipGraph) {
//		graphBar.minValue = 0;
//		graphBar.maxValue = [period.precipIN floatValue];
//	}
//	else if (barGraph == self.snowGraph) {
//		graphBar.minValue = 0;
//		graphBar.maxValue = [period.snowIN floatValue];
//	}
//
//	return graphBar;
//}
//
//- (NSString *)barGraph:(AWFBarGraphView *)barGraph titleForDatasetAtIndex:(NSInteger)index {
//	NSString *title;
//
//	if (barGraph == self.tempGraph) {
//		title = NSLocalizedString(@"Temp", nil);
//	}
//	else if (barGraph == self.precipGraph) {
//		title = NSLocalizedString(@"Precip", nil);
//	}
//	else if (barGraph == self.snowGraph) {
//		title = NSLocalizedString(@"Snow", nil);
//	}
//
//	return title;
//}
//
//- (UIColor *)barGraph:(AWFBarGraphView *)barGraph barColorForDatasetAtIndex:(NSInteger)index {
//	UIColor *color;
//
//	if (barGraph == self.tempGraph) {
//		color = [UIColor colorWithRed:0.834 green:0.000 blue:0.000 alpha:1.000];
//	}
//	else if (barGraph == self.precipGraph) {
//		color = [UIColor colorWithRed:0.036 green:0.704 blue:0.000 alpha:1.000];
//	}
//	else if (barGraph == self.snowGraph) {
//		color = [UIColor colorWithRed:0.000 green:0.426 blue:1.000 alpha:1.000];
//	}
//
//	return color;
//}
//
//#pragma mark - AWFBarGraphViewDelegate
//
//- (void)barGraph:(AWFBarGraphView *)barGraph didSelectBarAtIndexPath:(NSIndexPath *)indexPath {
//	AWFForecastPeriod *period = (AWFForecastPeriod *)self.data[indexPath.row];
//	CGFloat minValue = 0, maxValue = 0;
//
//	if (barGraph == self.tempGraph) {
//		minValue = [period.minTempF floatValue];
//		maxValue = [period.maxTempF floatValue];
//	}
//	else {
//		minValue = 0;
//		maxValue = [period.precipIN floatValue];
//	}
//	NSLog(@"selected bar at %@: min value=%.2f, max value=%.2f", indexPath, minValue, maxValue);
//}

@end
