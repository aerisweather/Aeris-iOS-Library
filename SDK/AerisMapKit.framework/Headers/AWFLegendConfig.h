//
//  AWFLegendConfig.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 7/14/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisMapKit/AWFGroupedStyle.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `AWFLegendRange` defines the min and max values covered by a legend.
 */
typedef struct {
	CGFloat min;
	CGFloat max;
} AWFLegendRange;

AWFLegendRange AWFLegendRangeMake(CGFloat min, CGFloat max);

/**
 `AWFDataScale` defines the min and max values as well as the data interval for a legend.
 */
typedef struct {
	CGFloat min;
	CGFloat max;
	CGFloat interval;
} AWFDataScale;

AWFDataScale AWFDataScaleMake(CGFloat min, CGFloat max, CGFloat interval);
extern AWFDataScale const AWFDataScaleZero;

/**
 The legend type.

 - AWFLegendTypeBar: A bar legend type defined by a series of color stops and values.
 - AWFLegendTypePoint: A point legend type defined by a series of keyed items.
 */
typedef NS_ENUM(NSUInteger, AWFLegendType) {
	AWFLegendTypeBar = 0,
	AWFLegendTypePoint
};

@class AWFPointLegendItem;

/**
 An `AWFLegendConfig` object provides the configuration options used to define a legend.
 */
@interface AWFLegendConfig : NSObject <NSCopying>

/**
 The identifier key for the configuration.
 */
@property (nonatomic, copy, nullable) NSString *key;

/**
 The legend type.
 */
@property (nonatomic, assign) AWFLegendType type;

/**
 The measurement type for the data represented by the legend.
 */
@property (nonatomic, assign) AWFMeasurement measurement;

/**
 The units represented by the legend.
 */
@property (readonly, nonatomic, assign, nullable) AWFUnit units;

/**
 For bar type legends, an array of color stops defining the colors and values for the bar legend.
 */
@property (nonatomic, strong, nullable) NSArray<AWFColorStop *> *colorStops;

/**
 For point type legends, an array of point items to include in the legend.
 */
@property (nonatomic, strong, nullable) NSArray<AWFPointLegendItem *> *pointItems;

/**
 For point type legends, an array of point item keys that define the order in which the point items are rendered. If this value is `nil`, then the items
 will be rendered in the order provided by `pointItems`.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *pointOrder;

@property (nonatomic, assign) AWFLegendRange scale;

/**
 The data interval (for bar type legends only).
 */
@property (nonatomic, assign) CGFloat interval;

/**
 Initializes and returns a newly allocated legend configuration object with the specified JSON dictionary.

 @param data The JSON dictionary of options to use.
 @return An initialized configuration object.
 */
- (instancetype)initWithDictionary:(NSDictionary *)data;

/**
 Initializes and returns a newly allocated legend configuration object with the specified grouped style.

 @param groupedStyle The grouped style to use.
 @return An initialized configuration object.
 */
- (instancetype)initWithGroupedStyle:(AWFGroupedStyle *)groupedStyle;

/**
 For point type legends, returns the point legend items associated with the specified keys.

 @param keys The array of point item keys to return items for.
 @return The point items associated with the keys, if any.
 */
- (NSArray<AWFPointLegendItem *> *)pointItemsForKeys:(NSArray<NSString *> *)keys;

@end


/**
 `AWFGroupedLegendConfig` is an object that represents a grouped legend by containing a series of individual legend configuration instances.
 */
@interface AWFGroupedLegendConfig : NSObject

/**
 The identifier key for the configuration.
 */
@property (nonatomic, copy, nullable) NSString *key;

/**
 An array of legend configuration instances for the group.
 */
@property (nonatomic, strong, nullable) NSArray<AWFLegendConfig *> *configs;

/**
 Initializes and returns a newly allocated legend configuration group with the specified configuration instances.

 @param configs The legend configuration instances for the group.
 @return An initialized configuration object.
 */
- (instancetype)initWithLegendConfigs:(NSArray<AWFLegendConfig *> *)configs;

@end

NS_ASSUME_NONNULL_END
