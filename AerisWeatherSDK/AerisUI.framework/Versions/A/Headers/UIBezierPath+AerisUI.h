//
//  UIBezierPath+AerisUI.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/15/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBezierPath (AerisUI)

+ (instancetype)awf_bezierPathWithArrowFromPoint:(CGPoint)startPoint toPoint:(CGPoint)endPoint tailWidth:(CGFloat)tailWidth
									   headWidth:(CGFloat)headWidth headLength:(CGFloat)headLength;

- (UIBezierPath *)awf_smoothedPathWithGranularity:(NSInteger)granularity;

@end
