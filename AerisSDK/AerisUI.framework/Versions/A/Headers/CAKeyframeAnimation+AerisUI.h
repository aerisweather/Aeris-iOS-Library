//
//  CAKeyframeAnimation+AerisUI.h
//  AerisUI
//
//  Created by Nicholas Shipes on 4/16/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import "AWFEasing.h"

@interface CAKeyframeAnimation (AerisUI)

+ (instancetype)animationWithKeyPath:(NSString *)path timingFunction:(AWFEasingAnimationTimeBlock)timingFunction fromValue:(id)fromValue toValue:(id)toValue;

+ (instancetype)animationWithKeyPath:(NSString *)path timingFunction:(AWFEasingAnimationTimeBlock)timingFunction fromPoint:(CGPoint)fromPoint toPoint:(CGPoint)toPoint;
+ (instancetype)animationWithKeyPath:(NSString *)path timingFunction:(AWFEasingAnimationTimeBlock)timingFunction fromSize:(CGSize)fromSize toSize:(CGSize)toSize;
+ (instancetype)animationWithKeyPath:(NSString *)path timingFunction:(AWFEasingAnimationTimeBlock)timingFunction fromRect:(CGRect)fromRect toRect:(CGRect)toRect;

@end
