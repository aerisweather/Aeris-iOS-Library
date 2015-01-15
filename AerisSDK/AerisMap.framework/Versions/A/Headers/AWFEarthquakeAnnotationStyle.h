//
//  AWFEarthquakeAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/17/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFAnnotationStyle.h"

@interface AWFEarthquakeAnnotationStyle : AWFAnnotationStyle

@property (nonatomic, strong) UIColor *ringColor;
@property (nonatomic, assign) CGFloat ringWidth;

@property (nonatomic, assign) BOOL showsRing;
@property (nonatomic, assign) CGFloat ringAnimationDuration;
@property (nonatomic, assign) BOOL ringAnimationRepeatCount;

@end
