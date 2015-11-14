//
//  AWFSeriesPoint.h
//  AerisUI
//
//  Created by Nicholas Shipes on 12/19/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  `AWFSeriesPoint` represents a single data point on a graph within a series. The values for both x- and y-axis should be defined for the series 
 *  point to be valid.
 */
@interface AWFSeriesPoint : NSObject

/**
 *  The data value on the x-axis.
 */
@property (nonatomic, assign) CGFloat x;

/**
 *  The data value on the y-axis.
 */
@property (nonatomic, assign) CGFloat y;

/**
 *  Creates and returns an new empty `AWFSeriesPoint` instance.
 *
 *  @return The initialized instance
 */
+ (instancetype)point;

/**
 *  Creates and returns a new `AWFSeriesPoint` instance initialized with the specified x and y data values.
 *
 *  @param x The x value
 *  @param y The y value
 *
 *  @return The instance initialized with the x and y values
 */
+ (instancetype)pointWithX:(CGFloat)x y:(CGFloat)y;

@end
