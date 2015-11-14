//
//  DailySummaryGraphsViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "GraphViewController.h"

@interface DailySummaryGraphsViewController : GraphViewController

@property (nonatomic, strong) AWFGraphView *tempGraph;
@property (nonatomic, strong) AWFGraphView *precipGraph;

@end
