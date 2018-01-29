//
//  UIImage+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/20/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisCoreUI/AWFIcon.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (AerisCoreUI)

+ (nullable UIImage *)awf_uncachedImageNamed:(NSString *)name;

//----------------------
// @name Resizing
//----------------------

- (nullable UIImage *)awf_imageScaledToSize:(CGSize)destinationSize;

//----------------------
// @name Color Adjustments
//----------------------

- (nullable UIImage *)awf_desaturatedImage;
- (nullable UIImage *)awf_imageTintedWithColor:(UIColor *)tintColor;
- (nullable UIColor *)awf_averageColor;

//----------------------
// @name Drawing Images
//----------------------

+ (nullable UIImage *)awf_imageWithSize:(CGSize)size drawing:(void (^)(void))drawingBlock;
+ (nullable UIImage *)awf_imageWithIdentifier:(NSString *)identifier size:(CGSize)size drawing:(void (^)(void))drawingBlock;
+ (nullable UIImage *)awf_imageWithIdentifier:(NSString *)identifier;

+ (void)awf_cacheImage:(UIImage *)image withIdentifier:(NSString *)identifier;
+ (void)awf_removeImageWithIdentifier:(NSString *)identifier;
+ (void)awf_removeAllImages;

//-----------------------------------------------------------------------------
// @name Icon Library
//-----------------------------------------------------------------------------

+ (nullable UIImage *)awf_iconWithType:(AWFIcon)icon size:(CGSize)size color:(UIColor *)color;
+ (nullable UIImage *)awf_iconWithType:(AWFIcon)icon width:(CGFloat)width color:(UIColor *)color;
+ (nullable UIImage *)awf_iconWithType:(AWFIcon)icon height:(CGFloat)height color:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
