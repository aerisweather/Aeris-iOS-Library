//
//  BarGraphsViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/14/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "GraphViewController.h"

@interface BarGraphsViewController : GraphViewController <AWFBarGraphViewDataSource, AWFBarGraphViewDelegate, GraphViewControllerDelegate>

- (AWFBarGraphView *)addGraphViewWithTitle:(NSString *)title yOffset:(CGFloat)yOffset;

@end
