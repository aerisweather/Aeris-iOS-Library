//
//  AWFLegend.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/29/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The legend orientation.

 - AWFLegendOrientationHorizontal: Horizontal legend orientation.
 - AWFLegendOrientationVertical: Vertical legend orientation.
 */
typedef NS_ENUM(NSUInteger, AWFLegendOrientation) {
	AWFLegendOrientationHorizontal = 0,
	AWFLegendOrientationVertical
};

/**
 The legend label position relative to the bar or point.

 - AWFLabelPositionBottom: Labels are rendered underneath the bar (bar legends only).
 - AWFLabelPositionTop: Labels are rendered above the bar (bar legends only).
 - AWFLabelPositionLeft: Labels are rendered to the left of the bar or point.
 - AWFLabelPositionRight: Labels are rendered to the right of the bar or point.
 */
typedef NS_ENUM(NSUInteger, AWFLabelPosition) {
	AWFLabelPositionBottom = 0,
	AWFLabelPositionTop,
	AWFLabelPositionLeft,
	AWFLabelPositionRight
};

/**
 The legend point style for point legends.

 - AWFPointTypeCircle: Points are drawn as squares.
 - AWFPointTypeSquare: Points are drawn as circles.
 */
typedef NS_ENUM(NSUInteger, AWFPointType) {
	AWFPointTypeCircle = 0,
	AWFPointTypeSquare
};

/**
 An `AWFLegendStyle` object provides the style specifications to be used for a data legend on a map.
 */
@interface AWFLegendStyle : NSObject <NSCopying>

/**
 The title of the legend.
 */
@property (nonatomic, copy) NSString *name;

/**
 An array of layer types associated with this style.
 */
@property (nonatomic, strong) NSArray<AWFMapLayer> *layerTypes;

/**
 The text style used for value labels.
 */
@property (nonatomic, strong) AWFTextStyleSpec *labelStyle;

/**
 The value label offset relative to the bar or point item.
 */
@property (nonatomic, assign) UIOffset labelOffset;

/**
 The spacing between items, measured in points.
 */
@property (nonatomic, assign) CGFloat interitemSpacing;

/**
 The margin insets to apply around the legend content.
 */
@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;

/**
 A Boolean value indicating whether the layout should be adjusted to fit the target width.
 */
@property (nonatomic, assign) BOOL adjustsLayoutToFitWidth;

/**
 A Boolean value indicating whether the legend should be centered within the target size when rendering.
 */
@property (nonatomic, assign) BOOL shouldCenter;

//-----------------------------------------------------------------------------
// @name Bar Legend Styling
//-----------------------------------------------------------------------------

/**
 The data value interval for which to draw cells between color stops.
 
 To define different cell intervals for different value ranges, use `cellIntervalRanges`.
 */
@property (nonatomic, assign) CGFloat cellInterval;

/**
 An array of interval ranges that define the cell interval to use for different value ranges of a bar legend. If this value is defined, then `cellInterval`
 will be ignored.
 */
@property (nonatomic, strong) NSArray<AWFColorRampIntervalRange *> *cellIntervalRanges;

/**
 The size for color cells.
 */
@property (nonatomic, assign) CGSize cellSize;

/**
 The data value interval for which to display value labels.
 
 To define different label intervals for different value ranges, use `labelIntervalRanges`.
 */
@property (nonatomic, assign) CGFloat labelInterval;

/**
 An array of interval ranges that define the label interval to use for different value ranges of a bar legend. If this value is defined, then `labelInterval`
 will be ignored.
 */
@property (nonatomic, strong) NSArray<AWFColorRampIntervalRange *> *labelIntervalRanges;

/**
 A Boolean value that indicates whether the label interval is based on an incremental value instead of cell value. The default is `NO`.
 */
@property (nonatomic, assign) BOOL isLabelIntervalByCounter;

/**
 The custom labels to display based on cell values.
 */
@property (nonatomic, strong, nullable) NSDictionary<NSNumber *, NSString *> *labels;

/**
 The position of value labels relative to the color bar.
 */
@property (nonatomic, assign) AWFLabelPosition labelPosition;

/**
 A Boolean value indicating whether labels should be generated automatically based on cell values. The default value is `YES`.
 */
@property (nonatomic, assign) BOOL automaticallyGenerateLabels;

//-----------------------------------------------------------------------------
// @name Point Legend Styling
//-----------------------------------------------------------------------------

/**
 The total number of columns for point items.
 */
@property (nonatomic, assign) NSUInteger totalColumns;

/**
 The amount of spacing between rows of point items, measured in points.
 */
@property (nonatomic, assign) CGFloat lineSpacing;

/**
 A Boolean value indicating whether each column should be adjusted to have equal widths even when all items exist on a single row. The default value is `NO`.
 */
@property (nonatomic, assign) BOOL shouldUseEqualSpacingForSingleRow;

/**
 The point type style to render.
 */
@property (nonatomic, assign) AWFPointType pointType;

/**
 The size of each point in the legend.
 */
@property (nonatomic, assign) CGSize pointSize;

/**
 The stroke width applied to the points.
 */
@property (nonatomic, assign) CGFloat pointStrokeWidth;

/**
 The stoke color applied to the points.
 */
@property (nonatomic, strong) UIColor *pointStrokeColor;

/**
 If `items` is a dictionary of array elements, specifies the order in which each item group is rendered.
 */
@property (nonatomic, strong) NSArray *displayOrderForItemGroups;

/**
 Specifies the order in which the items are rendered.
 */
@property (nonatomic, strong) NSArray *displayOrderForItems;

/**
 Initializes and returns a newly allocated legend style object configured from the specified dictionary.

 @param dict The dictionary containing the style configuration.
 @return An initialized style object.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dict;

/**
 Returns the cell interval to use for the specified value.
 
 The value returned may vary depending on whether `cellIntervalRanges` has been defined.

 @param value The value to return the cell interval for.
 @return The cell interval to use for the value.
 */
- (CGFloat)cellIntervalForValue:(CGFloat)value;

/**
 Returns the label interval to use for the specified value.
 
 The value returned may vary depending on whether `labelIntervalRanges` has been defined.

 @param value The value to return the label interval for.
 @return The label interval to use for the value.
 */
- (CGFloat)labelIntervalForValue:(CGFloat)value;

@end

NS_ASSUME_NONNULL_END
