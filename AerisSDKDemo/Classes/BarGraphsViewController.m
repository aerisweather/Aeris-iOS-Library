//
//  BarGraphsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/14/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "BarGraphsViewController.h"

@interface BarGraphsViewController ()
@property (nonatomic, strong) NSMutableArray *mutableTitles;
@property (nonatomic, strong) NSMutableArray *mutableGraphs;
@end

@implementation BarGraphsViewController

- (void)viewDidLoad {
	[super viewDidLoad];

	self.view.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	self.delegate = self;

	[self setupGraphs];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];

	[self loadDataForDefaultPlace];
}

- (AWFBarGraphView *)addGraphViewWithTitle:(NSString *)title yOffset:(CGFloat)yOffset {
	UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(10.0, yOffset, CGRectGetWidth(self.view.frame) - 20.0, 20.0)];
	titleLabel.backgroundColor = [UIColor clearColor];
	titleLabel.font = [UIFont boldSystemFontOfSize:16.0];
	titleLabel.text = title;
	titleLabel.textColor = [UIColor blackColor];
	titleLabel.autoresizingMask = UIViewAutoresizingFlexibleWidth;
	[self.scrollView addSubview:titleLabel];

	AWFBarGraphView *graphView = [[AWFBarGraphView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(titleLabel.frame) + 5.0, CGRectGetWidth(self.view.frame), 200.0)];
	graphView.backgroundColor = [[AWFCascadingStyle style].viewControllerBackgroundColor awf_adjustBrightness:1.04];
	graphView.dataSource = self;
	graphView.delegate = self;
	graphView.itemSpacing = 30.0;
	graphView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
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

#pragma mark - Properties

- (NSArray *)titles {
	return [NSArray arrayWithArray:self.mutableTitles];
}

- (NSArray *)graphs {
	return [NSArray arrayWithArray:self.mutableGraphs];
}

#pragma mark - GraphViewControllerDelegate

- (void)graphViewControllerDidStartLoading:(GraphViewController *)graphViewController {
	for (AWFLineGraphView *graphView in self.graphs) {
		[graphView showLoading:YES];
	}
}

- (void)graphViewControllerDidFinishLoading:(GraphViewController *)graphViewController {
	for (AWFLineGraphView *graphView in self.graphs) {
		[graphView showLoading:NO];
		[graphView reloadData];
	}
}

- (void)graphViewController:(GraphViewController *)graphViewController didFailLoading:(NSError *)error {
	for (AWFLineGraphView *graphView in self.graphs) {
		[graphView showLoading:NO];
	}
}

#pragma mark - AWFBarGraphViewDataSource

- (NSInteger)numberOfDatasetsForBarGraph:(AWFBarGraphView *)barGraph {
	return 0;
}

- (NSInteger)barGraph:(AWFBarGraphView *)barGraph numberOfBarsInDataset:(NSInteger)dataset {
	return [self.data count];
}

- (AWFGraphBar *)barGraph:(AWFBarGraphView *)barGraph barForItemAtIndexPath:(NSIndexPath *)indexPath {
	return nil;
}

@end
