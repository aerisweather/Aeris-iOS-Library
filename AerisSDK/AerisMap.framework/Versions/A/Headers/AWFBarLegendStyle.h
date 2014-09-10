//
//  AWFBarLegendStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/2/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFLegendStyle.h"

@interface AWFBarLegendStyle : AWFLegendStyle

@property (nonatomic, assign) CGFloat barHeight;

@property (nonatomic, assign) BOOL showsIntervalLabels;
@property (nonatomic, assign) BOOL showsGroupLabels;

@property (nonatomic, assign, getter = isGradient) BOOL gradient;

- (BOOL)shouldShowLabel:(NSString *)label atIndex:(NSInteger)idx;

@end


@interface AWFBarLegendInterval : NSObject

@property (nonatomic, strong) UIColor *color;
@property (nonatomic, copy) NSString *label;

+ (instancetype)intervalWithColor:(UIColor *)color label:(NSString *)label;

@end