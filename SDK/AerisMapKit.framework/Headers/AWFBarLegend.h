//
//  AWFBarLegend.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/24/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import <AerisMapKit/AWFLegendRenderer.h>
#import <AerisMapKit/AWFLegendConfig.h>
#import <AerisMapKit/AWFLegendStyle.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFBarLegend` is an object that adopts the `AWFLegendRenderer` protocol and is responsible for rendering a legend image based on a specific legend
 configuration and style.
 
 A bar legend is typically used to represent contoured and/or gradient data on a map, such as temperatures or wind speeds.
 */
@interface AWFBarLegend : NSObject <AWFLegendRenderer>

/**
 The legend configuration.
 */
@property (nonatomic, strong) AWFLegendConfig *config;

/**
 The orientation of the legend. The default value is `AWFLegendOrientationHorizontal`.
 */
@property (nonatomic, assign) AWFLegendOrientation orientation;

/**
 An array of color stops that define the bar legend.
 */
@property (nonatomic, strong, nullable) NSArray<AWFColorStop *> *colorStops;

/**
 The min and max values and data interval for the legend's scale.
 */
@property (nonatomic, assign) AWFDataScale scale;

@property (nonatomic, assign) AWFLegendRange range;

/**
 The style associated with the legend.
 */
@property (nonatomic, strong) AWFLegendStyle *style;

/**
 A Boolean value indicating whether the legend should be rendered using Metric values when applicable.
 */
@property (nonatomic, assign, getter=isMetric) BOOL metric;

/**
 Initializes and returns a newly allocated bar renderer with the specified legend configuration instance.

 @param config The legend configuration.
 @return An initialized legend renderer.
 */
- (nullable instancetype)initWithConfig:(AWFLegendConfig *)config;

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

NS_ASSUME_NONNULL_END
