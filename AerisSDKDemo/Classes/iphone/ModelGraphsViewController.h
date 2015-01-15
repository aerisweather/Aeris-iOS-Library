//
//  ModelGraphsViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/25/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "GraphViewController.h"

@interface ModelGraphsViewController : GraphViewController

@property (nonatomic, strong) AWFGraphView *tempGraph;
@property (nonatomic, strong) AWFGraphView *precipGraph;
@property (nonatomic, strong) AWFGraphView *windGraph;

@end
