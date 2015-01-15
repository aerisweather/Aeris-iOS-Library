//
//  ModelGraphsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/25/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "ModelGraphsViewController.h"

@interface ModelGraphsViewController ()
@property (nonatomic, strong) NSArray *models;
@property (nonatomic, strong) NSArray *modelData;
@property (nonatomic, strong) NSArray *modelTitles;
@property (nonatomic, strong) NSMutableDictionary *modelLoaders;
@property (nonatomic, strong) NSArray *tempColors;
@property (nonatomic, strong) NSArray *precipColors;
@property (nonatomic, strong) NSArray *windColors;
@end

@implementation ModelGraphsViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.loader = [[AWFBatchLoader alloc] init];

		self.models = @[@"default", @"nam12k", @"nam4k", @"gfs", @"gefs", @"ndfd"];

		self.tempColors = @[
		    [UIColor colorWithRed:0.810 green:0.040 blue:0.118 alpha:1.000],
		    [UIColor colorWithRed:0.377 green:0.033 blue:0.959 alpha:1.000],

		    [UIColor colorWithRed:0.848 green:0.135 blue:0.124 alpha:1.000],
		    [UIColor colorWithRed:0.288 green:0.129 blue:0.959 alpha:1.000],

		    [UIColor colorWithRed:0.964 green:0.329 blue:0.146 alpha:1.000],
		    [UIColor colorWithRed:0.224 green:0.263 blue:0.959 alpha:1.000],

		    [UIColor colorWithRed:0.967 green:0.531 blue:0.171 alpha:1.000],
		    [UIColor colorWithRed:0.177 green:0.416 blue:0.959 alpha:1.000],

		    [UIColor colorWithRed:0.976 green:0.759 blue:0.203 alpha:1.000],
		    [UIColor colorWithRed:0.167 green:0.593 blue:0.969 alpha:1.000],

		    [UIColor colorWithRed:0.987 green:0.900 blue:0.179 alpha:1.000],
		    [UIColor colorWithRed:0.184 green:0.779 blue:0.979 alpha:1.000]
		];

		self.precipColors = @[
		    [UIColor colorWithRed:0.229 green:1.000 blue:0.201 alpha:1.000],
		    [UIColor colorWithRed:0.185 green:0.820 blue:0.165 alpha:1.000],
		    [UIColor colorWithRed:0.147 green:0.647 blue:0.131 alpha:1.000],
		    [UIColor colorWithRed:0.111 green:0.489 blue:0.096 alpha:1.000],
		    [UIColor colorWithRed:0.076 green:0.339 blue:0.067 alpha:1.000],
		    [UIColor colorWithRed:0.047 green:0.204 blue:0.041 alpha:1.000]
		];
		self.windColors = @[
		    [UIColor colorWithRed:0.377 green:0.033 blue:0.959 alpha:1.000],
		    [UIColor colorWithRed:0.288 green:0.129 blue:0.959 alpha:1.000],
		    [UIColor colorWithRed:0.224 green:0.263 blue:0.959 alpha:1.000],
		    [UIColor colorWithRed:0.177 green:0.416 blue:0.959 alpha:1.000],
		    [UIColor colorWithRed:0.167 green:0.593 blue:0.969 alpha:1.000],
		    [UIColor colorWithRed:0.184 green:0.779 blue:0.979 alpha:1.000]
		];
	}

	return self;
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
}

- (void)setupGraphs {
	if (!self.modelLoaders) {
		self.modelLoaders = [NSMutableDictionary dictionary];
	}
	
	AWFGraphSeries *tempSeries = [[AWFGraphSeries alloc] init];
	AWFGraphSeries *precipSeries = [[AWFGraphSeries alloc] init];
	AWFGraphSeries *windSeries = [[AWFGraphSeries alloc] init];
	
	__block NSInteger tempIndex = 0;
	[self.models enumerateObjectsUsingBlock:^(NSString *modelName, NSUInteger idx, BOOL *stop) {
		AWFForecastsLoader *modelLoader = self.modelLoaders[modelName];
		if (!modelLoader) {
			modelLoader = [[AWFForecastsLoader alloc] init];
	        modelLoader.options.limit = 14;
	        [modelLoader.options addFilter:[AWFRequestFilter filterWithName:modelName]];
	        self.modelLoaders[modelName] = modelLoader;
		}
		
		// temps
		AWFSeriesItem *highTempItem = [[AWFSeriesItem alloc] init];
		highTempItem.title = [NSLocalizedString(@"High", nil) stringByAppendingString:[NSString stringWithFormat:@" (%@)", [modelName uppercaseString]]];
		highTempItem.rendererType = AWFGraphRendererTypeLine;
		highTempItem.objectLoader = modelLoader;
		highTempItem.xAxisPropertyName = @"periods.#.timestamp";
		highTempItem.yAxisPropertyName = @"periods.#.maxTempF";
		highTempItem.strokeColor = self.tempColors[tempIndex];
		highTempItem.interval = 5.0;
		highTempItem.ignoreTime = YES;
		[highTempItem setValueFormatter:^NSString *(CGFloat value) {
			return [NSString stringWithFormat:@"%.0f%@F", value, AWFDegree];
		}];
		[tempSeries addSeriesItem:highTempItem];
		
		AWFSeriesItem *lowTempItem = [highTempItem copy];
		lowTempItem.title = [NSLocalizedString(@"Low", nil) stringByAppendingString:[NSString stringWithFormat:@" (%@)", [modelName uppercaseString]]];
		lowTempItem.yAxisPropertyName = @"periods.#.minTempF";
		lowTempItem.strokeColor = self.tempColors[tempIndex + 1];
		[tempSeries addSeriesItem:lowTempItem];
		
		// precip
		AWFSeriesItem *precipItem = [[AWFSeriesItem alloc] init];
		precipItem.title = [modelName uppercaseString];
		precipItem.rendererType = AWFGraphRendererTypeBar;
		precipItem.objectLoader = modelLoader;
		precipItem.xAxisPropertyName = @"periods.#.timestamp";
		precipItem.yAxisPropertyName = @"periods.#.precipIN";
		precipItem.fillColor = self.precipColors[idx];
		precipItem.interval = 0.25;
		precipItem.ignoreTime = YES;
		precipItem.constrainToPositiveValues = YES;
		[precipItem setValueFormatter:^NSString *(CGFloat value) {
			return [NSString stringWithFormat:@"%.2f\"", value];
		}];
		[precipSeries addSeriesItem:precipItem];
		
		AWFSeriesItem *windItem = [[AWFSeriesItem alloc] init];
		windItem.title = [modelName uppercaseString];
		windItem.rendererType = AWFGraphRendererTypeLine;
		windItem.xAxisPropertyName = @"periods.#.timestamp";
		windItem.yAxisPropertyName = @"periods.#.windSpeedMPH";
		windItem.strokeColor = self.windColors[idx];
		windItem.interval = 5.0;
		windItem.constrainToPositiveValues = YES;
		[windItem setValueFormatter:^NSString *(CGFloat value) {
			return [NSString stringWithFormat:@"%.0fmph", value];
		}];
		[windSeries addSeriesItem:windItem];
		
		tempIndex += 2;
	}];
	
	AWFGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Temperatures", nil) series:tempSeries yOffset:10.0];
	self.tempGraph = tempGraph;
	
	AWFGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Precipitation", nil) series:precipSeries yOffset:CGRectGetMaxY(tempGraph.frame) + 10.0];
	[precipGraph.yAxis setTickFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f", value];
	}];
	self.precipGraph = precipGraph;
	
	AWFGraphView *windsGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Winds", nil) series:windSeries yOffset:CGRectGetMaxY(precipGraph.frame) + 10.0];
	self.windGraph = windsGraph;
	
	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(windsGraph.frame) + 10.0);
}

//- (void)setupGraphs {
//	AWFLineGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Temperatures", nil) yOffset:10.0];
//	tempGraph.valueInterval = 5.0;
//	tempGraph.stringFormatForValue = [@"%.0f" stringByAppendingString:AWFDegree];
//	self.tempGraph = tempGraph;
//
//	AWFLineGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Precipitation", nil) yOffset:CGRectGetMaxY(tempGraph.frame) +
//	                                 10.0];
//	precipGraph.valueInterval = 0.1;
//	precipGraph.constrainToPositiveValues = YES;
//	precipGraph.stringFormatForValue = @"%.2f\"";
//	self.precipGraph = precipGraph;
//
//	AWFLineGraphView *windsGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Winds", nil) yOffset:CGRectGetMaxY(precipGraph.frame) + 10.0];
//	windsGraph.valueInterval = 5.0;
//	windsGraph.constrainToPositiveValues = YES;
//	windsGraph.stringFormatForValue = @"%.0fmph";
//	self.windGraph = windsGraph;
//
//	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(windsGraph.frame) + 10.0);
//}
//
- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	[self.tempGraph.series setPlaceForAllSeriesItemLoaders:place];
	[self.precipGraph.series setPlaceForAllSeriesItemLoaders:place];
	[self.windGraph.series setPlaceForAllSeriesItemLoaders:place];
	
	if ([self.delegate respondsToSelector:@selector(graphViewControllerDidStartLoading:)]) {
		//[self.delegate graphViewControllerDidStartLoading:self];
	}
	
	[self.tempGraph reloadData];
	[self.precipGraph reloadData];
	[self.windGraph reloadData];
	
	
	
//	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
//
//	if (!self.modelLoaders) {
//		self.modelLoaders = [NSMutableDictionary dictionary];
//	}
//
//	AWFBatchLoader *loader = (AWFBatchLoader *)self.loader;
//
//	[self.models enumerateObjectsUsingBlock:^(NSString *modelName, NSUInteger idx, BOOL *stop) {
//	    AWFForecastsLoader *modelLoader = self.modelLoaders[modelName];
//	    if (!modelLoader) {
//	        modelLoader = [[AWFForecastsLoader alloc] init];
//	        modelLoader.options.place = place;
//	        modelLoader.options.limit = 14;
//	        [modelLoader.options addFilter:[AWFRequestFilter filterWithName:modelName]];
//	        [loader addLoader:modelLoader];
//	        self.modelLoaders[modelName] = modelLoader;
//		}
//	}];
//
//	if ([self.delegate respondsToSelector:@selector(graphViewControllerDidStartLoading:)]) {
//		[self.delegate graphViewControllerDidStartLoading:self];
//	}
//
//	[loader getWithCompletionBlock:^(AWFBatchLoader *loader, NSError *error) {
//	    if (error) {
//	        if ([self.delegate respondsToSelector:@selector(graphViewController:didFailLoading:)]) {
//	            [self.delegate graphViewController:self didFailLoading:error];
//			}
//
//	        return;
//		}
//
//	    NSMutableArray *models = [NSMutableArray array];
//	    NSMutableArray *titles = [NSMutableArray array];
//
//	    [self.models enumerateObjectsUsingBlock:^(NSString *modelName, NSUInteger idx, BOOL *stop) {
//	        AWFForecastsLoader *modelLoader = self.modelLoaders[modelName];
//	        NSArray *results = [loader objectsForLoader:modelLoader];
//	        if ([results count] > 0) {
//	            [models addObject:results[0]];
//	            [titles addObject:[modelName uppercaseString]];
//			}
//		}];
//
//	    self.modelData = [NSArray arrayWithArray:models];
//	    self.modelTitles = [NSArray arrayWithArray:titles];
//
//	    if ([self.delegate respondsToSelector:@selector(graphViewControllerDidFinishLoading:)]) {
//	        [self.delegate graphViewControllerDidFinishLoading:self];
//		}
//	}];
}






//#pragma mark - AWFLineGraphViewDataSource
//
//- (NSInteger)numberOfLinesForLineGraph:(AWFLineGraphView *)lineGraph {
//	NSInteger total = [self.models count];
//
//	if (lineGraph == self.tempGraph) {
//		return total * 2;
//	}
//
//	return total;
//}
//
//- (NSInteger)lineGraph:(AWFLineGraphView *)lineGraph numberOfPointsInDataset:(NSInteger)dataset {
//	NSInteger modelIndex = dataset;
//	if (lineGraph == self.tempGraph) {
//		modelIndex = floorf(modelIndex / 2.0);
//	}
//
//	if (modelIndex < [self.modelData count]) {
//		return [((AWFForecast *)self.modelData[modelIndex]).periods count];
//	}
//
//	return 0;
//}
//
//- (AWFGraphPoint *)lineGraph:(AWFLineGraphView *)lineGraph pointForItemAtIndexPath:(NSIndexPath *)indexPath {
//	NSInteger modelIndex = indexPath.section;
//	if (lineGraph == self.tempGraph) {
//		modelIndex = floorf(modelIndex / 2.0);
//	}
//
//	AWFForecast *forecast = (AWFForecast *)self.modelData[modelIndex];
//	AWFForecastPeriod *period = forecast.periods[indexPath.row];
//	NSDate *date = period.timestamp;
//
//	AWFGraphPoint *graphPoint = [[AWFGraphPoint alloc] init];
//	graphPoint.label = [NSString stringWithFormat:@"%@ %@%@", [date awf_stringWithFormat:AWFDateFormatDayName], [date awf_stringWithFormat:AWFDateFormatHour], [date awf_stringWithFormat:AWFDateFormatPeriod]];
//
//	if (lineGraph == self.tempGraph) {
//		if (indexPath.section % 2 == 0) {
//			graphPoint.value = [period.maxTempF floatValue];
//		}
//		else {
//			graphPoint.value = [period.minTempF floatValue];
//		}
//	}
//	else if (lineGraph == self.precipGraph) {
//		graphPoint.value = [period.precipIN floatValue];
//	}
//	else if (lineGraph == self.windGraph) {
//		graphPoint.value = [period.windSpeedMPH floatValue];
//	}
//
//	return graphPoint;
//}
//
//- (NSString *)lineGraph:(AWFLineGraphView *)lineGraph titleForLineAtIndex:(NSInteger)index {
//	NSString *title;
//	NSInteger modelIndex = index;
//
//	if (lineGraph == self.tempGraph) {
//		modelIndex = floorf(modelIndex / 2.0);
//	}
//
//	if (lineGraph == self.tempGraph) {
//		if (index % 2 == 0) {
//			title = NSLocalizedString(@"Max Temp", nil);
//		}
//		else {
//			title = NSLocalizedString(@"Min Temp", nil);
//		}
//	}
//	else if (lineGraph == self.precipGraph) {
//		title = NSLocalizedString(@"Precip", nil);
//	}
//	else if (lineGraph == self.windGraph) {
//		title = NSLocalizedString(@"Winds", nil);
//	}
//
//	title = [title stringByAppendingString:[NSString stringWithFormat:@" (%@)", self.modelTitles[modelIndex]]];
//
//	return title;
//}
//
//- (UIColor *)lineGraph:(AWFLineGraphView *)lineGraph lineColorForLineAtIndex:(NSInteger)index {
//	UIColor *color;
//
//	if (lineGraph == self.tempGraph) {
//		color = self.tempColors[index];
//	}
//	else if (lineGraph == self.precipGraph) {
//		color = self.precipColors[index];
//	}
//	else if (lineGraph == self.windGraph) {
//		color = self.windColors[index];
//	}
//
//	return color;
//}
//
//- (CGFloat)lineGraph:(AWFLineGraphView *)lineGraph lineWidthForLineAtIndex:(NSInteger)index {
//	CGFloat width = 1.0;
//
//	NSInteger modelIndex = index;
//	if (lineGraph == self.tempGraph) {
//		modelIndex = floorf(modelIndex / 2.0);
//		if (modelIndex == 0) {
//			width = 2.0;
//		}
//	}
//	else if (modelIndex == 0) {
//		width = 2.0;
//	}
//
//	return width;
//}

@end
