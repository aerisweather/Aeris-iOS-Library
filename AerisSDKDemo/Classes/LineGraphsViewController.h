//
//  LineGraphViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/12/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "GraphViewController.h"

@interface LineGraphsViewController : GraphViewController <AWFLineGraphViewDataSource, AWFLineGraphViewDelegate, GraphViewControllerDelegate>

- (AWFLineGraphView *)addGraphViewWithTitle:(NSString *)title yOffset:(CGFloat)yOffset;

@end
