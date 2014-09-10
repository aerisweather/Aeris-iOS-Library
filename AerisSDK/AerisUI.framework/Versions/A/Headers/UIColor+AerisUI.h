//
//  UIColor+AerisUI.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (AerisUI)

+ (UIColor *)awf_colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
+ (UIColor *)awf_colorWithRGB:(NSString *)rgb;

+ (UIColor *)awf_colorWithHue:(CGFloat)hue saturation:(CGFloat)saturation brightness:(CGFloat)brightness alpha:(CGFloat)alpha;
+ (UIColor *)awf_colorWithHSL:(NSString *)hsl;

- (BOOL)awf_isEqualToColor:(UIColor *)otherColor;
- (UIColor *)awf_adjustAlpha:(CGFloat)alpha;

//----------------------
// @name Hex String Support
//----------------------

+ (UIColor *)awf_colorWithHex:(NSString *)hex;
- (NSString *)awf_hexValue;
- (NSString *)awf_hexValueWithAlpha:(BOOL)includeAlpha;

//----------------------
// @name Brightness Adjustments
//----------------------

- (UIColor *)awf_adjustBrightness:(CGFloat)amount;
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
