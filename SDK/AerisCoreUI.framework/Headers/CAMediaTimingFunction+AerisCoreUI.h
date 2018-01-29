//
//  CAMediaTimingFunction+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 12/21/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <AerisCoreUI/AWFEasing.h>

NS_ASSUME_NONNULL_BEGIN

@interface CAMediaTimingFunction (AerisCoreUI)

/**
 *  Creates and returns a new instance of `CAMediaTimingFunction` configured with the given `AWFEasing` value.
 *
 *  @param easingFunction The easing function to use
 *
 *  @return A new instance of `CAMediaTimingFunction` with the timing function specified by `easingFunction`
 */
+ (instancetype)awf_functionWithEasing:(AWFEasing)easingFunction;

@end

NS_ASSUME_NONNULL_END
