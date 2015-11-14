//
//  AWFGraphAxis.h
//  AerisUI
//
//  Created by Nicholas Shipes on 12/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NSString *(^AWFGraphTickFormatter)(CGFloat value);

typedef NS_ENUM(NSInteger, AWFGraphAxisOrientation) {
	AWFGraphAxisOrientationLeft = 0,
	AWFGraphAxisOrientationRight,
	AWFGraphAxisOrientationBottom,
	AWFGraphAxisOrientationTop
};

@class AWFGraphView, AWFTextStyleSpec;

@interface AWFGraphAxis : NSObject

/**
 *  The view for this axis.
 */
@property (readonly, strong, nonatomic) UIView *view;

/**
 *  The grid view for this axis.
 */
@property (readonly, strong, nonatomic) UIView *gridView;

/**
 *  The orientation and position of this axis along the graph.
 */
@property (nonatomic, assign) AWFGraphAxisOrientation orientation;

/**
 *  The total number of ticks to draw along the axis. If this is set, then the ticks won't be rendered at the specified `tickInterval`.
 */
@property (nonatomic, assign) NSInteger totalTicks;

/**
 *  The value interval to use between ticks along the axis.
 */
@property (nonatomic, assign) CGFloat tickInterval;

/**
 *  An array of values to display along the axis. If this is set, then the ticks won't be rendered at the specified `tickInterval`.
 */
@property (nonatomic, strong) NSArray *tickValues;

/**
 *  The minimum number of pixels allowed between ticks.
 */
@property (nonatomic, assign) CGFloat minimumPixelsPerTick;

/**
 *  The color used for axis ticks.
 */
@property (nonatomic, strong) UIColor *tickColor;

/**
 *  The color used for the axis grid lines.
 */
@property (nonatomic, strong) UIColor *gridColor;

/**
 *  The unit name to display on the axis.
 */
@property (nonatomic, copy) NSString *unit;

/**
 *  The text style spec to apply to the axis labels.
 */
@property (nonatomic, strong) AWFTextStyleSpec *textStyle;

/**
 *  Whether the axis should be positioned statically within the graph view.
 */
@property (nonatomic, assign, getter=isStaticPosition) BOOL staticPosition;

/**
 *  The graph view this axis belongs to.
 */
@property (nonatomic, strong) AWFGraphView *graphView;

/**
 *  A block used to format the tick label values. This block receives the value at the position along the axis as its argument.
 *
 *  @param formatter The block to use to format the tick label
 */
- (void)setTickFormatter:(AWFGraphTickFormatter)formatter;

/**
 *  Redraws the axis.
 */
- (void)renderAxis;
- (void)updateLayout;

/**
 *  Updates the axis for the specified zoom scale.
 *
 *  This is called automatically by the parent graph view when its zoom scale changes and should not be called directly.
 *
 *  @param zoomScale The zoom scale to use
 */
- (void)adjustForZoomScale:(CGFloat)zoomScale;

@end
