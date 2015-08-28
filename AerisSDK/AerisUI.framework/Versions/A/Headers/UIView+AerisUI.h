//
//  UIView+AerisUI.h
//  AerisUI
//
//  Created by Nicholas Shipes on 4/16/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "AWFEasing.h"

@interface UIView (AerisUI)

/**
 *  Assigns an easing function to an animatable `UIView` property.
 *  
 *  The function remains assigned and in effect until removed using `awf_removeEasingFunctionForKeyPath:`.
 *
 *  @param function Pointer to a function that defines the pacing of an animation by mapping an input time normalized to the range `[0,1]` to an output time.
 *  @param keyPath  The key-path of the property to assign the easing function to.
 */
- (void)awf_setEasingFunction:(AWFEasingAnimationTimeBlock)function forKeyPath:(NSString *)keyPath;

/**
 *  Disassociates a previously assigned easing function from an animatable `UIView` property.
 *
 *  @param keyPath The key-path of the property to remove a previously assigned easing function from.
 */
- (void)awf_removeEasingFunctionForKeyPath:(NSString *)keyPath;

- (void)awf_debug;

@end
