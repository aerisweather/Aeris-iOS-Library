//
//  AFAnimationTimeline.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AWFAnimation.h"

/**
 *  An `AWFAnimationTimeline` object is a subclass of `AWFAnimation` that manages and controls multiple
 *	instances of `AWFAnimation`. All animation instances added to an `AWFAnimationTimeline` are controlled
 *	by a single timeline, resulting in all animations being synced while playing simultaneously.
 */
@interface AWFAnimationTimeline : AWFAnimation

/**
 *  The animation objects currently being controlled by the timeline animation (read-only).
 */
@property (readonly, strong, nonatomic) NSArray *animations;

/**
 *  Adds a single animation object to the timeline.
 *
 *  @param animations The animation object to add.
 */
- (void)addAnimations:(NSArray *)animations;

/**
 *  Removes a single animation object to the timeline.
 *
 *  @param animations The animation object to remove.
 */
- (void)removeAnimations:(NSArray *)animations;

@end
