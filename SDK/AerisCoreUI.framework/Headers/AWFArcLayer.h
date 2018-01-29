//
//  AWFArcLayer.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 12/4/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

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

@property (nonatomic, strong, nullable) UIColor *fillColor;
@property (nonatomic, strong, nullable) UIColor *strokeColor;
@property (nonatomic, strong, nullable) UIColor *innerShadowColor;
@property (nonatomic, assign) CGFloat innerShadowRadius;
@property (nonatomic, assign) CGFloat innerShadowOpacity;

@property (nonatomic, assign) BOOL shouldAnimate;

- (CGPoint)pointForArcEdge:(enum AWFArcEdge)edge side:(enum AWFArcSide)side;
- (CGPoint)pointForArcAngle:(CGFloat)angle edge:(enum AWFArcEdge)edge radiusOffset:(CGFloat)offset;

@end

NS_ASSUME_NONNULL_END
