//
//  UIColor+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/20/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (AerisCoreUI)

+ (UIColor *)awf_colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
+ (UIColor *)awf_colorWithRGB:(NSString *)rgb;

+ (UIColor *)awf_colorWithHue:(CGFloat)hue saturation:(CGFloat)saturation brightness:(CGFloat)brightness alpha:(CGFloat)alpha;
+ (UIColor *)awf_colorWithHSL:(NSString *)hsl;

- (BOOL)awf_isEqualToColor:(UIColor *)otherColor;
- (UIColor *)awf_adjustAlpha:(CGFloat)alpha;

- (UIColor *)awf_interpolatedToColor:(UIColor *)toColor position:(CGFloat)position;

//----------------------
// @name Hex String Support
//----------------------

+ (UIColor *)awf_colorWithHex:(NSString *)hex;
- (nullable NSString *)awf_hexValue;
- (nullable NSString *)awf_hexValueWithAlpha:(BOOL)includeAlpha;

//----------------------
// @name Brightness Adjustments
//----------------------

- (nullable UIColor *)awf_adjustBrightness:(CGFloat)amount;
- (UIColor *)awf_grayscale;
- (BOOL)awf_isLightColor;

//----------------------
// @name Color Components
//----------------------

- (CGFloat)awf_red;
- (CGFloat)awf_green;
- (CGFloat)awf_blue;
- (CGFloat)awf_alpha;

@end

NS_ASSUME_NONNULL_END
