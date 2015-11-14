//
//  AWFArcLayer.h
//  AerisUI
//
//  Created by Nicholas Shipes on 4/16/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

typedef NS_ENUM(NSUInteger, AWFArcEdge) {
	AWFArcEdgeInner = 0,
	AWFArcEdgeOuter
};

typedef NS_ENUM(NSUInteger, AWFArcSide) {
	AWFArcSideStart = 0,
	AWFArcSideEnd
};

@interface AWFArcLayer : CALayer

@property (nonatomic, assign) CGFloat startAngle;
@property (nonatomic, assign) CGFloat endAngle;
@property (nonatomic, assign) CGFloat strokeWidth;
@property (nonatomic, assign) CGFloat thickness;

@property (nonatomic, strong) UIColor *fillColor;
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, strong) UIColor *innerShadowColor;
@property (nonatomic, assign) CGFloat innerShadowRadius;
@property (nonatomic, assign) CGFloat innerShadowOpacity;

@property (nonatomic, assign) BOOL shouldAnimate;

- (CGPoint)pointForArcEdge:(enum AWFArcEdge)edge side:(enum AWFArcSide)side;
- (CGPoint)pointForArcAngle:(CGFloat)angle edge:(enum AWFArcEdge)edge radiusOffset:(CGFloat)offset;

@end
