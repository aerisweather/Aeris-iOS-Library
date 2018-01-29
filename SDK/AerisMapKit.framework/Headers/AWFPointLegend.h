//
//  AWFPointLegend.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/25/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import <AerisMapKit/AWFLegendRenderer.h>
#import <AerisMapKit/AWFLegendConfig.h>
#import <AerisMapKit/AWFLegendStyle.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFPointLegendItem;
/**
 An `AWFPointLegend` is an object that adopts the `AWFLegendRenderer` protocol and is responsible for rendering a pointlegend image based on a
 specific legend configuration and style.
 
 A point legend is typically used to represent point (annotation) and shape (polygon) data on a map, such as earthquakes or storm reports.
 */
@interface AWFPointLegend : NSObject <AWFLegendRenderer>

/**
 The legend configuration.
 */
@property (nonatomic, strong) AWFLegendConfig *config;

/**
 An array of point items to display for the legend.
 */
@property (nonatomic, strong) NSArray<AWFPointLegendItem *> *items;

/**
 The style associated with the legend.
 */
@property (nonatomic, strong) AWFLegendStyle *style;

/**
 An array of point item keys used to limit which point items are displayed. If `nil`, then all point items will be rendered.
 */
@property (nonatomic, strong) NSArray<NSString *> *filterKeys;

/**
 Initializes and returns a newly allocated bar renderer with the specified legend configuration instance.
 
 @param config The legend configuration.
 @return An initialized legend renderer.
 */
- (nullable instancetype)initWithConfig:(AWFLegendConfig * _Nonnull)config;

/**
 Renders and returns a legend image with for the specified image size and insets.
 
 @param size The size for the image.
 @param insets The margin insets to use when rendering.
 @return A rendered legend image, or `nil` if an image could not be generated.
 */
- (nullable UIImage *)imageForSize:(CGSize)size insets:(UIEdgeInsets)insets;

/**
 Returns the minimum size required to render the legend based on the legend's configuration and style.
 */
- (CGSize)sizeThatFits;

@end


/**
 An `AWFPointLegendItem` is an object that is used to represent a single group, category or value in a `AWFPointLegend` instance.
 */
@interface AWFPointLegendItem : NSObject

/**
 The identifier for the item.
 */
@property (nonatomic, copy) NSString *key;

/**
 The text label to display for this item. If `nil`, then the item's key will be displayed.
 */
@property (nonatomic, copy, nullable) NSString *label;

/**
 The color associated with this item for the map data.
 */
@property (nonatomic, strong) UIColor *color;

/**
 Initializes and returns a newly allocated point legend item with the provided key, label and color.

 @param key The identifier for the item.
 @param label The title text to display.
 @param color The item color.
 @return An initialized point legend item object.
 */
+ (instancetype)itemWithKey:(NSString *)key label:(NSString * _Nullable)label color:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
