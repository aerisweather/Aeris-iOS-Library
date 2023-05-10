//
//  RecentObsGraphViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GraphViewController.h"

@interface RecentObsGraphViewController : GraphViewController

@property (nonatomic, strong) AWFGraphView *tempGraph;
@property (nonatomic, strong) AWFGraphView *precipGraph;
@property (nonatomic, strong) AWFGraphView *windGraph;
@property (nonatomic, strong) AWFGraphView *skyGraph;

@end