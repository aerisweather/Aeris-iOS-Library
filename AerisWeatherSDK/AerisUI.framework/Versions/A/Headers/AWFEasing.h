//
//  AWFEasing.h
//  AerisUI
//
//  Created by Nicholas Shipes on 4/16/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#if CGFLOAT_IS_DOUBLE
#define AWFFloat double
#else
#define AWFFloat float
#endif

/**
 *  A block representing a parametric easing function that takes normalized time as input and returns the normalized progress
 *  from.
 *
 *  @param time A value from `0` to `1` representing the progress between start and end times.
 *
 *  @return A value representing the progress between start and finish values for the given time.
 */
typedef double (^AWFEasingAnimationTimeBlock)(double time);

/**
 *  A block that interpolates between two value objects.
 *
 *  @param progress  A value from `0` to `1` representing the progress between the start and end values.
 *  @param fromValue A value object for when progress is `0`, which should be of the same type as `toValue`.
 *  @param toValue   A value object for when progress is `1`, which should be of the same type as `fromValue`.
 *
 *  @return An interpolated value between `fromValue` and `toValue` for the specified progress.
 */
typedef id (^AWFEasingValueBlock)(double progress, id fromValue, id toValue);

/**
 *  A block that sets animated properties for the given time.
 *
 *  This block usually leverages the parametric time blocks and value blocks above.
 *
 *  @param time A value from `0` to `1` representing the progress between the start and finish times.
 */
typedef void (^AWFEasingAnimationBlock)(double time);


extern const NSInteger AWFEasingAnimationNumberOfSteps;

@interface AWFEasing : NSObject

// @name Timing Function Blocks

extern const AWFEasingAnimationTimeBlock AWFAnimationLinear;

extern const AWFEasingAnimationTimeBlock AWFAnimationEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationEaseInOut;

extern const AWFEasingAnimationTimeBlock AWFAnimationBackEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationBackEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationBackEaseInOut;

extern const AWFEasingAnimationTimeBlock AWFAnimationQuadraticEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationQuadraticEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationQuadraticEaseInOut;

extern const AWFEasingAnimationTimeBlock AWFAnimationQuarticEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationQuarticEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationQuarticEaseInOut;

extern const AWFEasingAnimationTimeBlock AWFAnimationQuinticEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationQuinticEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationQuinticEaseInOut;

extern const AWFEasingAnimationTimeBlock AWFAnimationCubicEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationCubicEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationCubicEaseInOut;

extern const AWFEasingAnimationTimeBlock AWFAnimationCircularEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationCircularEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationCircularEaseInOut;

extern const AWFEasingAnimationTimeBlock AWFAnimationExpoEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationExpoEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationExpoEaseInOut;

extern const AWFEasingAnimationTimeBlock AWFAnimationSineEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationSineEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationSineEaseInOut;

extern const AWFEasingAnimationTimeBlock AWFAnimationBounceEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationBounceEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationBounceEaseInOut;

extern const AWFEasingAnimationTimeBlock AWFAnimationElasticEaseIn;
extern const AWFEasingAnimationTimeBlock AWFAnimationElasticEaseOut;
extern const AWFEasingAnimationTimeBlock AWFAnimationElasticEaseInOut;

// @name Value Constructor Blocks

extern const AWFEasingValueBlock AWFEasingValueBlockDouble;
extern const AWFEasingValueBlock AWFEasingValueBlockCGPoint;
extern const AWFEasingValueBlock AWFEasingValueBlockCGSize;
extern const AWFEasingValueBlock AWFEasingValueBlockCGRect;
extern const AWFEasingValueBlock AWFEasingValueBlockCGColor;
extern const AWFEasingValueBlock AWFEasingValueBlockCGAffineTransform;
extern const AWFEasingValueBlock AWFEasingValueBlockCATransform3D;

extern const double (^AWFParametricAnimationBezierEvaluator)(double time, CGPoint ct1, CGPoint ct2);

@end
