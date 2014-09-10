//
//  ForecastBarGraphsViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "BarGraphsViewController.h"

@interface ForecastBarGraphsViewController : BarGraphsViewController

@property (nonatomic, strong) AWFBarGraphView *tempGraph;
@property (nonatomic, strong) AWFBarGraphView *precipGraph;
@property (nonatomic, strong) AWFBarGraphView *snowGraph;

@end
