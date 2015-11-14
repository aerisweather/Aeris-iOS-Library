//
//  AWFAnimatableOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AWFAnimation.h"

@class AWFAnimation;

/**
 *  The `AWFAnimatableOverlay` protocol defines an overlay object that can be animated and provides a required
 *	`animation` property to store the animation object.
 */
@protocol AWFAnimatableOverlay <MKOverlay, AWFAnimationDataSource>

/**
 *  The animation object associated with the overlay.
 */
@property (strong, nonatomic) AWFAnimation *animation;

@optional

/**
 *  The maximum number of intervals to show during an animation. This value is typically only used for image and tile data animations.
 */
@property (assign, nonatomic) NSInteger maximumIntervalsForAnimation;

@end