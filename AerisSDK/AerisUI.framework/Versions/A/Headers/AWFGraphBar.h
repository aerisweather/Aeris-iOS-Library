//
//  AWFGraphBar.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/14/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AWFGraphBar : NSObject

@property (nonatomic, assign) CGFloat minValue;
@property (nonatomic, assign) CGFloat maxValue;
@property (nonatomic, copy) NSString *label;

@property (nonatomic, strong) UIColor *fillColor;
@property (nonatomic, assign) CGFloat thickness;
@property (nonatomic, assign) CGFloat cornerRadius;

@property (readonly, nonatomic, strong) CAShapeLayer *layer;

@end
