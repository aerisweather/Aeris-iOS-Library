//
//  AWFBarLegendStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/2/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFLegendStyle.h>

/**
 *  An `AWFBarLegendStyle` object is an `AWFLegendStyle` subclass that provides the style specifications to be used for a bar-type legend defined by a color ramp/interval.
 */
@interface AWFBarLegendStyle : AWFLegendStyle

/**
 *  The height of the color bar.
 */
@property (nonatomic, assign) CGFloat barHeight;

/**
 *  A Boolean value indicating whether the interval labels should be rendered.
 */
@property (nonatomic, assign) BOOL showsIntervalLabels;

/**
 *  A Boolean value indicating whether the item group labels should be rendered.
 */
@property (nonatomic, assign) BOOL showsGroupLabels;

/**
 *  A Boolean value indicating whether the bar should be rendered as a gradient where each `item` is a seprate color stop.
 */
@property (nonatomic, assign, getter = isGradient) BOOL gradient;

/**
 *  Returns a Boolean value indicating whether the label at the specified index should be rendered. 
 *
 *  This method is typically used to reduce the labels by certain values or only show labels of values that are divisible by a certain interval.
 *
 *  @param label The label for the index
 *  @param idx   The item index of the label
 *
 *  @return `YES` if the label should be rendered, otherwise `NO`.
 */
- (BOOL)shouldShowLabel:(NSString *)label atIndex:(NSInteger)idx;

@end

/**
 *  An `AWFBarLegendInterval` object is used to represent a single value interval for a `AWFBarLegendStyle` instance, which is typically a single color stop for a
 *  color ramp or interval.
 */
@interface AWFBarLegendInterval : NSObject

/**
 *  The color for the color stop.
 */
@property (nonatomic, strong) UIColor *color;

/**
 *  The label to display for the color stop.
 */
@property (nonatomic, copy) NSString *label;

/**
 *  Initializes and returns a new `AWFBarLegendInterval` instance configured with the specified `color` and `label`.
 *
 *  @param color The color for the interval
 *  @param label The value label for the interval
 *
 *  @return An initialized `AWFBarLegendInterval` instance or `nil` if one couldn't be created
 */
+ (instancetype)intervalWithColor:(UIColor *)color label:(NSString *)label;

@end