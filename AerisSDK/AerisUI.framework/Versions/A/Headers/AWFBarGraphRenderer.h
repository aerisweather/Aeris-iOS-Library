//
//  AWFBarSeriesRenderer.h
//  AerisUI
//
//  Created by Nicholas Shipes on 12/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AWFGraphRenderer.h>

@interface AWFBarGraphRenderer : AWFGraphRenderer

/**
 *  The spacing to use between bars in the same interval, in points.
 */
@property (nonatomic, assign) CGFloat barSpacing;

/**
 *  The spacing to use between intervals, in points.
 */
@property (nonatomic, assign) CGFloat intervalSpacing;

/**
 *  Whether the renderer should stack (overlap) the bars, `YES`, otherwise bars will be rendered side-by-side.
 */
@property (nonatomic, assign) BOOL stacked;

/**
 *  Returns the width needed for a single interval based on the total number of series items and spacing.
 */
- (CGFloat)neededWidthPerInterval;

@end
