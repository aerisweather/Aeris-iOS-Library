//
//  UIView+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/24/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (AerisCoreUI)

- (NSArray<NSLayoutConstraint *> *)awf_constraintsByCenteringInView:(UIView *)view;
- (NSArray<NSLayoutConstraint *> *)awf_constraintsByPinningToEdgesOfView:(UIView *)view;
- (NSArray<NSLayoutConstraint *> *)awf_constraintsByPinningToEdgesOfView:(UIView *)view inset:(CGFloat)inset;
- (NSArray<NSLayoutConstraint *> *)awf_constraintsByPinningToEdgesOfView:(UIView *)view insets:(UIEdgeInsets)insets;
- (NSArray<NSLayoutConstraint *> *)awf_constraintsBySettingDimensionsToSize:(CGSize)size;

- (nullable UIImage *)awf_screenshot;
- (void)awf_debug;

@end

NS_ASSUME_NONNULL_END
