//
//  AWFSeriesItem.h
//  AerisUI
//
//  Created by Nicholas Shipes on 12/19/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisUI/AWFGraphSeries.h>
#import <AerisUI/AWFGraphRenderer.h>

typedef NS_ENUM(NSUInteger, AWFSeriesModifier) {
	AWFSeriesModifierNone = 0,
	AWFSeriesModifierSum
};

typedef NSString *(^AWFGraphValueFormatter)(CGFloat value);

@class AWFGraphRenderer, AWFGraphView, AWFSeriesPoint;

/**
 *  The `AWFSeriesItem` class represents a single dataset that is displayed in a graph view. This class parses and stores its data as well as provides 
 *  the necessary styling configuration for a graph renderer.
 */
@interface AWFSeriesItem : NSObject <NSCopying>

/**
 *  The title of the series.
 */
@property (nonatomic, copy) NSString *title;

/**
 *  The unique identifier for the series. If not assigned, a random string will be generated for the identifier.
 */
@property (nonatomic, copy) NSString *identifier;

/**
 *  An array of data points for the series.
 *
 *  The array can contain be array of arrays (`@[@[x1, y1], @[x2, y2]]`), an array of `AWFSeriesPoint` instances or an array of `AWFObject` instances 
 *  (if returned from an object loader.
 */
@property (nonatomic, strong) NSArray *data;

/**
 *  The object loader to use for loading the data needed for the series item.
 */
@property (nonatomic, strong) AWFObjectLoader *objectLoader;

/**
 *  The property key path to use for x-axis values from objects loaded by the associated object loader.
 */
@property (nonatomic, copy) NSString *xAxisPropertyName;

/**
 *  The property key path to use for y-axis values from objects loaded by the associated object loader.
 */
@property (nonatomic, copy) NSString *yAxisPropertyName;

/**
 *  The value interval of the data.
 */
@property (nonatomic, assign) CGFloat interval;

/**
 *  Whether or not the series item's range should be constrained to only positive values.
 */
@property (nonatomic, assign) BOOL constrainToPositiveValues;

/**
 *  Whether the time value should be ignored for date-specific values. Default is `NO`.
 */
@property (nonatomic, assign) BOOL ignoreTime;

/**
 *  Whether zero values should be ignored in the series. Default is `NO`.
 */
@property (nonatomic, assign) BOOL ignoreZeroValues;

@property (nonatomic, assign) AWFSeriesModifier modifier;

//-----------------------------------------------------------------------------
// @name Styling a Series Item
//-----------------------------------------------------------------------------

/**
 *  The graph renderer type to use to render the series item.
 */
@property (nonatomic, assign) AWFGraphRendererType rendererType;

/**
 *  The fill color used for the series item.
 *
 *  When using a renderer type of `AWFGraphRendererTypeBar`, this will be the color of each bar in the series. For `AWFGraphRendererTypeLine`, the
 *  fill color defines the color of the region underneath the line.
 */
@property (nonatomic, strong) UIColor *fillColor;

/**
 *  The stroke color used for the series item.
 */
@property (nonatomic, strong) UIColor *strokeColor;

/**
 *  The width of the stroke to use for the series item.
 */
@property (nonatomic, assign) CGFloat strokeWidth;

/**
 *  The point radius to use for the series item. This is only used for a renderer type of `AWFGraphRendererTypeLine`.
 */
@property (nonatomic, assign) CGFloat pointRadius;

/**
 *  An array of `AWFSeriesPoint` instances representing the series data.
 */
@property (readonly, nonatomic) NSArray *points;

/**
 *  The minimum date found within the series data, if any.
 */
@property (readonly, nonatomic) NSDate *minDate;

/**
 *  The maximum date found within the series data, if any.
 */
@property (readonly, nonatomic) NSDate *maxDate;

/**
 *  Returns the range of values within the series data for the specified axis.
 *
 *  @param axis The axis to return the range for
 */
- (AWFGraphSeriesRange)rangeForAxis:(AWFGraphAxisType)axis;

/**
 *  Returns the closest data point in the series to the specified value and axis.
 *
 *  @param value The value to return the closest data point for
 *  @param axis  The axis the value is on
 */
- (AWFSeriesPoint *)closestPointToValue:(CGFloat)value forAxis:(AWFGraphAxisType)axis;

/**
 *  Sets the block used to format values in the series for display.
 *
 *  @param formatter The block to be used to format values
 */
- (void)setValueFormatter:(AWFGraphValueFormatter)formatter;

/**
 *  Returns a value formatted using the defined formatter block.
 *
 *  @param value The value to format
 *
 *  @return A formatted string from the value
 */
- (NSString *)formatValue:(CGFloat)value;

- (BOOL)containsData;

@end
