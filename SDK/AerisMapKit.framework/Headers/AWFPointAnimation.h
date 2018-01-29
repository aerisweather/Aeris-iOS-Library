//
//  AFPointDataAnimation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/13/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFAnimation.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFPointAnimation;
@class AWFAnnotation;

/**
 The `AWFPointAnimationDataSource` is adopted by an object that provides the necessary data for an point-based
 overlay to complete its animation.
 */
@protocol AWFPointAnimationDataSource <AWFAnimationDataSource>

/**
 Asks the data source for the data to be used for this animation. (required)
 *
 @param animation The animation object requesting the data.
 *
 @return An array of data items to use for the animation. These instances may vary depending on subclasses and what they expect to receive.
 */
- (nullable NSArray<AWFAnnotation *> *)annotationsForAnimation:(AWFAnimation *)animation;

@end

/**
 The `AWFPointAnimationDelegate` protocol defines a set of optional methods that can be used to be notified when the point data
 animation data changes.
 */
@protocol AWFPointAnimationDelegate <AWFAnimationDelegate>
@optional

/**
 Tells the delegate the animation has annotations to be added for the current position in the timeline.
 *
 Typically this is used by a `AWFWeatherMap` instance to be notified when annotations should be added to the map.
 *
 @param animation   The animation that added annotations.
 @param annotations The annotations that are active for the current timeline range.
 */
- (void)animation:(AWFPointAnimation *)animation didAddAnnotations:(NSArray<AWFAnnotation *> *)annotations;

/**
 Tells the delegate the animation has annotations to be removed for the current position in the timeline.
 *
 Typically this is used by a `AWFWeatherMap` instance to be notified when annotations should be removed from the map.
 *
 @param animation   The animation managing the annotations.
 @param annotations The annotations that are inactive for the current timeline range.
 */
- (void)animation:(AWFPointAnimation *)animation didRemoveAnnotations:(NSArray<AWFAnnotation *> *)annotations;

@end

/**
 An `AWFPointAnimation` object manages the animation of of date-specific point data across a period of time.
 */
@interface AWFPointAnimation : AWFAnimation

/**
 The object that acts as the data source of the receiving animation.
 */
@property (nonatomic, unsafe_unretained, nullable) id<AWFPointAnimationDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
