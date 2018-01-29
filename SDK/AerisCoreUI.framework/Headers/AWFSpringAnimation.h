//
//  AWFSpringAnimation.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/25/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//
//  Internal adapted version of JNWSpringAnimation: https://github.com/jwilling/JNWSpringAnimation
//  Copyright (c) 2013, Jonathan Willing. All rights reserved.
//  Licensed under the MIT license <http://opensource.org/licenses/MIT>
//

#import <QuartzCore/QuartzCore.h>

@interface AWFSpringAnimation : CAKeyframeAnimation

@property (assign, nonatomic) CGFloat stiffness;
@property (assign, nonatomic) CGFloat damping;
@property (assign, nonatomic) CGFloat mass;
@property (nonatomic, strong) id fromValue;
@property (nonatomic, strong) id toValue;
@property (readonly, assign, nonatomic) CFTimeInterval duration;

@end
