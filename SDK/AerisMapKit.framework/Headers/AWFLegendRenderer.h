//
//  AWFLegendRenderer.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/24/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFLegendConfig;
@class AWFLegendStyle;

/**
 The `AWFLegendRenderer` protocol defines the required properties and methods for an object that renders a legend.
 */
@protocol AWFLegendRenderer <NSObject>

/**
 The style associated with the legend.
 */
@property (nonatomic, strong) AWFLegendStyle *style;

/**
 Initializes and returns a newly allocated bar renderer with the specified legend configuration instance.
 
 @param config The legend configuration.
 @return An initialized legend renderer.
 */
- (instancetype)initWithConfig:(AWFLegendConfig * _Nonnull)config;

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
