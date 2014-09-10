//
//  ForecastLineGraphsViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "LineGraphsViewController.h"

@interface ForecastLineGraphsViewController : LineGraphsViewController

@property (nonatomic, strong) AWFLineGraphView *tempGraph;
@property (nonatomic, strong) AWFLineGraphView *precipGraph;
@property (nonatomic, strong) AWFLineGraphView *windGraph;
@property (nonatomic, strong) AWFLineGraphView *skyGraph;

@end
