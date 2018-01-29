//
//  AWFRasterBlendMode.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/10/16.
//  Copyright © 2016 Aeris Weather; LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `AWFRasterBlendMode` type defines the supported color and alpha blend modes supported by raster map layers.
 
 @note When using Swift, reference these values as their enumerated types instead of the Objective-C constants:
 `let blend = AWFRasterBlendMode.sourceOver`
 */
typedef NSString * AWFRasterBlendMode NS_TYPED_ENUM;

FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeNone;

/**
 An alpha blend method that will simply return the source image, ignoring the destination image.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeSource;

/**
 An alpha blend method that will simply return the destination image, ignoring the source image.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeDest;

/**
 An alpha blend method that will layer the source image on top of the destination image. This is the same as using no blend.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeSourceOver;

/**
 An alpha blend method that will layer the destination image on top of the source image.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeDestOver;

/**
 An alpha blend method that will only include portions of the source image if they intersect with parts of the destination image. The colors of the
 destination image will not be drawn.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeSourceIn;

/**
 An alpha blend method that will only include portions of the destination image if they intersect with parts of the source image. The colors of the source
 image will not be drawn.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeDestIn;

/**
 An alpha blend method that will only include portions of the source image if they **do not** intersect with parts of the destination image. The colors
 of the destination image will not be drawn.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeSourceOut;

/**
 An alpha blend method that will only include portions of the destination image if they **do not** intersect with parts of the source image. The colors of
 the source image will not be drawn.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeDestOut;

/**
 An alpha blend method that will only include portions of the source image that intersect the destination image. These portions will be layered on top of
 the destination image.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeSourceAtop;

/**
 An alpha blend method that will only include portions of the destination image that intersect the source image. These portions will be layered on top of
 the source image.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeDestAtop;

/**
 A blend method that adds the source color to the destination, tinting the destination towards the source. The lighter the source, the lighter the result.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModePlus;

/**
 A blend method that subtracts the source color from the destination, tinting the destination opposite of the source. The lighter the source, the lighter
 the result.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeMinus;

/**
 A blend method that multiplies colors from the source image with the colors of the destination. The result tends to be a darker image that highlights
 the source.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeMultiply;

/**
 A blend method that multiplies the inverse of the source and destination colors, resulting in a lighter color. Screening with black produces no change,
 while screening with white produces white.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeScreen;

/**
 A blend method that combines colors from the source image with the brightness and darkness of the destination. The overlay blend is useful for showing
 terrain texture within the source mage and works best with lighter destination layers.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeOverlay;

/**
 A blend method that looks at the color information in each channel and selects the destination or source color, whichever is darker, as the result.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeDarken;

/**
 A blend method that looks at the color information in each channel and selects the destination or source color, whichever is lighter, as the result.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeLighten;

/**
 A blend method that looks at the color information in each channel and brightens the destination to reflect the source by decreasing the contrast
 between the two. Blending with black produces no change.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeColorDodge;

/**
 A blend method that looks at the color information in each channel and darkens the destination to reflect the source by increasing the contrast between
 the two. Blending with white produces no change.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeColorBurn;

/**
 A blend method that multiplies or screens the colors depending on the source. The effect is similar to shining a harsh spotlight on the image. If the source
 is lighter than 50% gray, the result is lightened. Otherwise, the result is darkened.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeHardLight;

/**
 A blend method that darkens or lightens the colors depending on the source. The effect is similar to shining a diffused spotlight on the image. If the source
 is lighter than 50% gray, the result is lightened. Otherwise, the result is darkened.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeSoftLight;

/**
 A blend method that looks at the color information in each channel and subtracts either the source from the destination or the destination from the source
 depending on which has the greater brightness value. Blending with white inverts the base color values, while blending with black produces no change.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeDifference;

/**
 A blend method that creates an effect similar to but lower in contrast than the difference blend mode. Blending with white inverts the base color values,
 while blending with black produces no change.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeExclusion;

/**
 
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeContrast;

/**
 
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeInvert;

/**
 
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeInvertRGB;

/**
 A blend method that is useful with showing terrain texture within the source image and works well with both light and dark destination layers.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeGrainMerge;

/**
 
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeGrainExtract;

/**
 A blend method that creates a result with the luminance and saturation of the destination and the hue of the source.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeHue;

/**
 A blend method that creates a result with the luminance and hue of the destination and the saturation of the source. This method preserves the grey levels
 in the image and is useful for coloring monochrome images or tinting color images.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeSaturation;

/**
 A blend method that looks at the color information in each channel and brightens the source color to reflect the destination color by increasing the
 brightness. Blending with black produces no change.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeLinearDodge;

/**
 A blend method that looks at the color information in each channel and darkens the source color to reflect the destination color by decreasing the
 brightness. Blending with white produces no change.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeLinearBurn;

/**
 A blend method that looks at the color information in each channel and divides the destination color from the source color.
 */
FOUNDATION_EXPORT AWFRasterBlendMode const AWFRasterBlendModeDivide;

NS_ASSUME_NONNULL_END
