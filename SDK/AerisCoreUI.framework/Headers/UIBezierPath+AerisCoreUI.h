//
//  UIBezierPath+AerisUI.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/15/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIBezierPath (AerisCoreUI)

+ (void)awf_pointsForArrowFromPoint:(CGPoint)startPoint toPoint:(CGPoint)endPoint tailWidth:(CGFloat)tailWidth
							   headWidth:(CGFloat)headWidth headLength:(CGFloat)headLength points:(CGPoint *)points count:(NSUInteger)count;

+ (instancetype)awf_bezierPathWithArrowFromPoint:(CGPoint)startPoint toPoint:(CGPoint)endPoint tailWidth:(CGFloat)tailWidth
									   headWidth:(CGFloat)headWidth headLength:(CGFloat)headLength;

- (UIBezierPath *)awf_smoothedPathWithGranularity:(NSInteger)granularity;

@end

NS_ASSUME_NONNULL_END
