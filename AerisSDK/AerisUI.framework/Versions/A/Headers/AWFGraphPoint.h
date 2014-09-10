//
//  AWFGraphPoint.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AWFGraphPoint : NSObject

@property (nonatomic, assign) CGFloat value;
@property (nonatomic, copy) NSString *label;

@property (nonatomic, strong) UIColor *fillColor;
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, assign) CGFloat strokeWidth;
@property (nonatomic, assign) CGFloat radius;

@property (readonly, nonatomic, strong) CAShapeLayer *layer;

@end
