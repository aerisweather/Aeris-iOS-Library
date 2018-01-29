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
@property (nonatomic, strong) NSMutableDictionary *endpoints;
@property (nonatomic, strong) NSArray *tempColors;
@property (nonatomic, strong) NSArray *precipColors;
@property (nonatomic, strong) NSArray *windColors;
@end

@implementation ModelGraphsViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
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

- (void)setupGraphs {
	if (!self.endpoints) {
		self.endpoints = [NSMutableDictionary dictionary];
	}
	
	AWFWeatherGraphSeries *tempSeries = [[AWFWeatherGraphSeries alloc] init];
	AWFWeatherGraphSeries *precipSeries = [[AWFWeatherGraphSeries alloc] init];
	AWFWeatherGraphSeries *windSeries = [[AWFWeatherGraphSeries alloc] init];
	
	__block NSInteger tempIndex = 0;
	[self.models enumerateObjectsUsingBlock:^(NSString *modelName, NSUInteger idx, BOOL *stop) {
		AWFForecasts *model = self.endpoints[modelName];
		if (!model) {
			model = [AWFForecasts new];
	        model.options.limit = 14;
			model.options.filterString = modelName;
	        self.endpoints[modelName] = model;
		}
		
		// temps
		AWFWeatherSeriesItem *highTempItem = [AWFWeatherSeriesItem new];
		highTempItem.title = [NSLocalizedString(@"High", nil) stringByAppendingString:[NSString stringWithFormat:@" (%@)", [modelName uppercaseString]]];
		highTempItem.rendererType = AWFGraphRendererTypeLine;
		highTempItem.endpoint = model;
		highTempItem.xAxisPropertyName = @"periods.#.timestamp";
		highTempItem.yAxisPropertyName = @"periods.#.maxTempF";
		highTempItem.strokeColor = self.tempColors[tempIndex];
		highTempItem.interval = 5.0;
		highTempItem.ignoreTime = YES;
		[highTempItem setValueFormatter:^NSString *(CGFloat value) {
			return [NSString stringWithFormat:@"%.0f%@F", value, AWFDegree];
		}];
		[tempSeries addSeriesItem:highTempItem];
		
		AWFWeatherSeriesItem *lowTempItem = [highTempItem copy];
		lowTempItem.title = [NSLocalizedString(@"Low", nil) stringByAppendingString:[NSString stringWithFormat:@" (%@)", [modelName uppercaseString]]];
		lowTempItem.yAxisPropertyName = @"periods.#.minTempF";
		lowTempItem.strokeColor = self.tempColors[tempIndex + 1];
		[tempSeries addSeriesItem:lowTempItem];
		
		// precip
		AWFWeatherSeriesItem *precipItem = [AWFWeatherSeriesItem new];
		precipItem.title = [modelName uppercaseString];
		precipItem.rendererType = AWFGraphRendererTypeBar;
		precipItem.endpoint = model;
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
		
		AWFWeatherSeriesItem *windItem = [AWFWeatherSeriesItem new];
		windItem.title = [modelName uppercaseString];
		windItem.rendererType = AWFGraphRendererTypeLine;
		windItem.endpoint = model;
		windItem.xAxisPropertyName = @"periods.#.timestamp";
		windItem.yAxisPropertyName = @"periods.#.windSpeedMPH";
		windItem.strokeColor = self.windColors[idx];
		windItem.interval = 5.0;
		windItem.ignoreTime = YES;
		windItem.constrainToPositiveValues = YES;
		[windItem setValueFormatter:^NSString *(CGFloat value) {
			return [NSString stringWithFormat:@"%.0fmph", value];
		}];
		[windSeries addSeriesItem:windItem];
		
		tempIndex += 2;
	}];
	
	AWFGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Temperatures", nil) series:tempSeries];
	self.tempGraph = tempGraph;
	
	AWFGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Precipitation", nil) series:precipSeries];
	[precipGraph.yAxis setTickFormatter:^NSString *(CGFloat value) {
		return [NSString stringWithFormat:@"%.2f", value];
	}];
	self.precipGraph = precipGraph;
	
	AWFGraphView *windsGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Winds", nil) series:windSeries];
	self.windGraph = windsGraph;
	
	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(windsGraph.frame) + 10.0);
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	[(AWFWeatherGraphSeries *)self.tempGraph.series setPlaceForAllSeriesItemEndpoints:place];
	[(AWFWeatherGraphSeries *)self.precipGraph.series setPlaceForAllSeriesItemEndpoints:place];
	[(AWFWeatherGraphSeries *)self.windGraph.series setPlaceForAllSeriesItemEndpoints:place];
	
	if ([self.delegate respondsToSelector:@selector(graphViewControllerDidStartLoading:)]) {
		//[self.delegate graphViewControllerDidStartLoading:self];
	}
	
	[self.tempGraph reloadData];
	[self.precipGraph reloadData];
	[self.windGraph reloadData];
}

@end
