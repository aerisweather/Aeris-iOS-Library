//
//  GraphViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/15/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "GraphViewController.h"

@interface GraphViewController ()
@property (nonatomic, strong) NSMutableArray *mutableTitles;
@property (nonatomic, strong) NSMutableArray *mutableGraphs;
@end

@implementation GraphViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	
	self.view.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	self.delegate = self;

	self.scrollView = [[UIScrollView alloc] initWithFrame:self.view.bounds];
	self.scrollView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
	[self.view addSubview:self.scrollView];
	
	[self setupGraphs];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	// update graph renderers with preferences
	for (AWFGraphView *graphView in self.graphs) {
		AWFLineGraphRenderer *lineRenderer = (AWFLineGraphRenderer *)[graphView rendererForType:AWFGraphRendererTypeLine];
		if (lineRenderer) {
			lineRenderer.showPoints = [Preferences sharedInstance].graphShowPoints;
			lineRenderer.showLines = [Preferences sharedInstance].graphShowLines;
			lineRenderer.smoothed = [Preferences sharedInstance].graphSmoothLines;
		}
	}
	
	[self loadDataForDefaultPlace];
}

#pragma mark - Properties

- (NSArray *)titles {
	return [NSArray arrayWithArray:self.mutableTitles];
}

- (NSArray *)graphs {
	return [NSArray arrayWithArray:self.mutableGraphs];
}

#pragma mark - Public

- (void)setupGraphs {
	// subclasses should implement
}

- (void)loadDataForDefaultPlace {
	// subclasses should implement
}

- (AWFGraphView *)addGraphViewWithTitle:(NSString *)title series:(AWFGraphSeries *)series yOffset:(CGFloat)yOffset {
	UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(10.0, yOffset, CGRectGetWidth(self.view.frame) - 20.0, 20.0)];
	titleLabel.backgroundColor = [UIColor clearColor];
	titleLabel.font = [UIFont boldSystemFontOfSize:16.0];
	titleLabel.text = title;
	titleLabel.textColor = [UIColor blackColor];
	titleLabel.autoresizingMask = UIViewAutoresizingFlexibleWidth;
	[self.scrollView addSubview:titleLabel];
	
	AWFGraphView *graphView = [[AWFGraphView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(titleLabel.frame) + 5.0, CGRectGetWidth(self.view.frame), 200.0)];
	graphView.backgroundColor = [[AWFCascadingStyle style].viewControllerBackgroundColor awf_adjustBrightness:1.04];
	graphView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
	graphView.series = series;
	[self.scrollView addSubview:graphView];
	
	if (!self.mutableTitles) {
		self.mutableTitles = [NSMutableArray array];
	}
	[self.mutableTitles addObject:titleLabel];
	
	if (!self.mutableGraphs) {
		self.mutableGraphs = [NSMutableArray array];
	}
	[self.mutableGraphs addObject:graphView];
	
	return graphView;
}

#pragma mark - AWFGraphViewDelegate

- (void)graphView:(AWFGraphView *)graphView didSelectItemForSeries:(AWFSeriesItem *)seriesItem atIndex:(NSInteger)index {
	AWFSeriesPoint *point = seriesItem.points[index];
	NSLog(@"selected point at %lu: value=%.2f", index, point.y);
}

#pragma mark - GraphViewControllerDelegate

- (void)graphViewControllerDidStartLoading:(GraphViewController *)graphViewController {
	for (AWFGraphView *graphView in self.graphs) {
		[graphView showLoading:YES];
	}
}

- (void)graphViewControllerDidFinishLoading:(GraphViewController *)graphViewController {
	for (AWFGraphView *graphView in self.graphs) {
		[graphView showLoading:NO];
		[graphView reloadData];
	}
}

- (void)graphViewController:(GraphViewController *)graphViewController didFailLoading:(NSError *)error {
	for (AWFGraphView *graphView in self.graphs) {
		[graphView showLoading:NO];
	}
}

@end
