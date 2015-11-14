//
//  UIImage+AerisUI.h
//  AerisUI
//
//  Created by Nicholas Shipes on 4/14/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (AerisUI)

//----------------------
// @name Resizing
//----------------------

- (UIImage *)awf_imageScaledToSize:(CGSize)destinationSize;

//----------------------
// @name Color Adjustments
//----------------------

- (UIImage *)awf_desaturatedImage;
- (UIImage *)awf_imageTintedWithColor:(UIColor *)tintColor;
- (UIColor *)awf_averageColor;

//----------------------
// @name Drawing Images
//----------------------

+ (UIImage *)awf_imageWithSize:(CGSize)size drawing:(void (^)())drawingBlock;
+ (UIImage *)awf_imageWithIdentifier:(NSString *)identifier size:(CGSize)size drawing:(void (^)())drawingBlock;
+ (UIImage *)awf_imageWithIdentifier:(NSString *)identifier;

+ (void)awf_cacheImage:(UIImage *)image withIdentifier:(NSString *)identifier;
+ (void)awf_removeImageWithIdentifier:(NSString *)identifier;
+ (void)awf_removeAllImages;

@end
