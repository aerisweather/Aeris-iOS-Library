//
//  CAKeyframeAnimation+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/25/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>
#import <AerisCoreUI/AWFEasing.h>

NS_ASSUME_NONNULL_BEGIN

@interface CAKeyframeAnimation (AerisCoreUI)

//-----------------------------------------------------------------------------
// @name Convenience Constructors
//-----------------------------------------------------------------------------

+ (instancetype)awf_animationWithKeyPath:(NSString *)keyPath fromDouble:(double)fromValue toDouble:(double)toValue easing:(AWFEasing)easing;
+ (instancetype)awf_animationFromPoint:(CGPoint)fromValue toPoint:(CGPoint)toValue easing:(AWFEasing)easing;
+ (instancetype)awf_animationFromSize:(CGSize)fromValue toSize:(CGSize)toValue easing:(AWFEasing)easing;
+ (instancetype)awf_animationFromRect:(CGRect)fromValue toRect:(CGRect)toValue easing:(AWFEasing)easing;
+ (instancetype)awf_animationFromColor:(UIColor *)fromValue toColor:(UIColor *)toValue easing:(AWFEasing)easing;
+ (instancetype)awf_animationFromTransform:(CATransform3D)fromValue toTransform:(CATransform3D)toValue easing:(AWFEasing)easing;

@end

NS_ASSUME_NONNULL_END
