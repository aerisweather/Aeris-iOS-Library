//
//  AWFAnimatableOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/13/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisMapKit/AWFAnimation.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFAnimation;

/**
 The `AWFAnimatableOverlay` protocol defines an overlay object that can be animated and provides a required
 `animation` property to store the animation object.
 */
@protocol AWFAnimatableOverlay <MKOverlay, AWFAnimationDataSource>

/**
 The animation object associated with the overlay.
 */
@property (nonatomic, strong) AWFAnimation *animation;

@optional

/**
 The maximum number of intervals to show during an animation. This value is typically only used for image and tile data animations.
 */
@property (nonatomic, assign) NSInteger maximumIntervalsForAnimation;

@end

NS_ASSUME_NONNULL_END
