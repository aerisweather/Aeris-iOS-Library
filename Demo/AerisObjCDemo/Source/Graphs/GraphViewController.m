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
@property (nonatomic, strong) NSLayoutConstraint *contentBottomConstraint;
@end

@implementation GraphViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	
	self.view.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	self.delegate = self;

	UIScrollView *scrollView = [UIScrollView new];
	scrollView.translatesAutoresizingMaskIntoConstraints = NO;
	[self.view addSubview:scrollView];
	self.scrollView = scrollView;
	
	UIView *contentView = [UIView new];
	contentView.translatesAutoresizingMaskIntoConstraints = NO;
	contentView.preservesSuperviewLayoutMargins = YES;
	[scrollView addSubview:contentView];
	self.contentView = contentView;
	
	[NSLayoutConstraint activateConstraints:@[[scrollView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
											  [scrollView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [scrollView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [scrollView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
											  [contentView.topAnchor constraintEqualToAnchor:scrollView.topAnchor],
											  [contentView.leftAnchor constraintEqualToAnchor:scrollView.leftAnchor],
											  [contentView.rightAnchor constraintEqualToAnchor:scrollView.rightAnchor],
											  [contentView.bottomAnchor constraintEqualToAnchor:scrollView.bottomAnchor],
											  [contentView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [contentView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor]]];
	
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

- (AWFGraphView *)addGraphViewWithTitle:(NSString *)title series:(AWFWeatherGraphSeries *)series {
	NSMutableArray *constraints = [NSMutableArray new];
	UIView *lastView = [self.mutableGraphs lastObject];
	UILayoutGuide *layoutGuide = self.contentView.layoutMarginsGuide;
	
	UILabel *titleLabel = [UILabel new];
	titleLabel.translatesAutoresizingMaskIntoConstraints = NO;
	titleLabel.backgroundColor = [UIColor clearColor];
	titleLabel.font = [UIFont boldSystemFontOfSize:16.0];
	titleLabel.text = title;
	titleLabel.textColor = [UIColor blackColor];
	[self.contentView addSubview:titleLabel];
	
	AWFGraphView *graphView = [AWFGraphView new];
	graphView.translatesAutoresizingMaskIntoConstraints = NO;
	graphView.backgroundColor = [[AWFCascadingStyle style].viewControllerBackgroundColor awf_adjustBrightness:1.04];
	graphView.series = series;
	[self.contentView addSubview:graphView];
	
	if (lastView) {
		[constraints addObject:[titleLabel.topAnchor constraintEqualToAnchor:lastView.bottomAnchor constant:20.0]];
	} else {
		[constraints addObject:[titleLabel.topAnchor constraintEqualToAnchor:layoutGuide.topAnchor]];
	}
	
	[constraints addObjectsFromArray:@[[titleLabel.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
									   [graphView.topAnchor constraintEqualToAnchor:titleLabel.bottomAnchor constant:5.0],
									   [graphView.leftAnchor constraintEqualToAnchor:self.contentView.leftAnchor],
									   [graphView.rightAnchor constraintEqualToAnchor:self.contentView.rightAnchor],
									   [graphView.heightAnchor constraintEqualToConstant:200.0]]];
	
	// update bottom constraint for contentView
	if (self.contentBottomConstraint) {
		[NSLayoutConstraint deactivateConstraints:@[self.contentBottomConstraint]];
	}
	
	self.contentBottomConstraint = [graphView.bottomAnchor constraintEqualToAnchor:layoutGuide.bottomAnchor];
	[constraints addObject:self.contentBottomConstraint];
	
	[NSLayoutConstraint activateConstraints:constraints];
	
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
	NSLog(@"selected point at %ld: value=%.2f", (long)index, point.y);
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
