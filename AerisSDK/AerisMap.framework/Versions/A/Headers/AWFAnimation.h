//
//  AFAnimation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AWFAnimation, AWFAnimationTimeline, AWFCoordinateBounds;

/**
 *  The `AWFAnimationDataSource` protocol is adopted by an object that provides basic information that is needed
 *	for an animation object.
 */
@protocol AWFAnimationDataSource <NSObject>
@optional

/**
 *  Asks the data source what property to use for each item in the data set for assigning its date position. (optional)
 *
 *  @param animation The animation object requesting the data.
 *
 *  @return The property name to use for assigning each item's date position.
 */
- (NSString *)modelPropertyToUseForDateAssignment:(AWFAnimation *)animation;

/**
 *  Asks the data source if the animation should request new data for the specified coordinate bounds.
 *
 *  @param animation The animation object requesting the information.
 *  @param bounds    The coordinate bounds to be used for the request.
 *
 *  @return `YES` if the animation should request data for the bounds, otherwise `NO`.
 */
- (BOOL)animation:(AWFAnimation *)animation shouldLoadDataForBounds:(AWFCoordinateBounds *)bounds;

/**
 *  Tells the delegate when the animation object cancelled its data loading process.
 *
 *  @param animation The animation object that cancelled loading.
 */
- (void)cancelLoadingDataForAnimation:(AWFAnimation *)animation;

/**
 *  Asks the data source for the total number of requests being made for the current loading process.
 *
 *  This value is the sum of both completed and queued requests and is not an indicator of the number of requests currently
 *  remaining before the animation is ready for playback.
 *
 *  @param animation The animation object requesting the information.
 *
 *  @return The total number of requests needed before the animation is ready for playback.
 */
- (NSInteger)totalRequestsForAnimation:(AWFAnimation *)animation;

/**
 *  Asks the data source for the total number of requests remaining for the current loading process.
 *
 *  @param animation The animation object requesting the information.
 *
 *  @return The total number of requests remaining before the animation is ready for playback.
 */
- (NSInteger)totalRequestsRemainingForAnimation:(AWFAnimation *)animation;

/**
 *  Tells the data source that the animation data needs to be invalidated.
 *
 *  This is usually called when the animation is reset to its original state and new data needs to be reloaded.
 *
 *  @param animation The animation object that needs to be invalidated.
 */
- (void)invalidateDataForAnimation:(AWFAnimation *)animation;

@end

/**
 *  The `AWFAnimationDelegate` protocol defines a set of optional methods that can be used to receive animation-related update
 *  messages. These methods notify your application of changes to the state of the animation, such as when playback starts or 
 *  stops.
 */
@protocol AWFAnimationDelegate <NSObject>
@optional

/**
 *  Tells the delegate the animation started playback.
 *
 *  @param animation The animation that started playing.
 *  @param startDate The date from which the animation started.
 */
- (void)animation:(AWFAnimation *)animation didStartAtDate:(NSDate *)startDate;

/**
 *  Tells the delegate the animation ended playback.
 *
 *  @param animation The animation that stopped playing.
 *  @param stopDate  The date at which the animation stopped.
 */
- (void)animation:(AWFAnimation *)animation didStopAtDate:(NSDate *)stopDate;

/**
 *  Tells the delegate the animation paused playback.
 *
 *  @param animation The animation that paused.
 *  @param date      The date at which the animation was paused.
 */
- (void)animation:(AWFAnimation *)animation didPauseAtDate:(NSDate *)date;

/**
 *  Tells the delegate the animation did update to a specific date along its timeline.
 *
 *  @param animation   The animation whose date was updated.
 *  @param currentDate The date the animation updated to along its timeline.
 */
- (void)animation:(AWFAnimation *)animation didUpdateToDate:(NSDate *)currentDate;

/**
 *  Tells the delegate the animation is ready for playback.
 *
 *  This is often used for animations that require loading remote data before playing.
 *
 *  @param animation The animation that is ready.
 *  @see AWFImageAnimation, AWFPointDataAnimation
 */
- (void)animationIsReady:(AWFAnimation *)animation;

/**
 *  Tells the delegate the animation restarted playing from the beginning of its timeline.
 *
 *  @param animation The animation that restarted.
 */
- (void)animationDidRestart:(AWFAnimation *)animation;

/**
 *  Tells the delegate the animation started loading remote data required for playback.
 *
 *  @param animation The animation that started loading.
 *  @param total     The total number of data requests required for the animation.
 */
- (void)animationDidStartLoading:(AWFAnimation *)animation total:(NSInteger)total;

/**
 *  Tells the delegate the loading progress for the animation changed.
 *
 *  @param animation The animation whose loading progress changed.
 *  @param progress  The total number of requests completed.
 *  @param total     The total number of requests required.
 */
- (void)animation:(AWFAnimation *)animation didUpdateLoadingProgress:(NSInteger)progress total:(NSInteger)total;

/**
 *  Tells the delegate the loading progress for the animation has completed.
 *
 *  @param animation The animation whose loading progress completed.
 */
- (void)animationDidFinishLoading:(AWFAnimation *)animation;

/**
 *  Tells the delegate the loading progress was cancelled and is no longer requesting data.
 *
 *  @param animation The animation that cancelled the loading process.
 *  @param total     The total number of remaining requests that were cancelled.
 */
- (void)animationDidCancelLoading:(AWFAnimation *)animation totalCancelledRequests:(NSInteger)total;

/**
 *  Tells the delegate the animation has been reset.
 *
 *  When an animation is reset, it is returned to its original state. All data that may have been previously loaded was purged
 *  and will need to be reloaded again before the animation can begin playing again.
 *
 *  @param animation The animatoin that was reset.
 */
- (void)animationDidReset:(AWFAnimation *)animation;

@end


/**
 *  An `AWFAnimation` object provides the core functionality necessary for a single time-based animation. The animation
 *	is defined by a specified start and end date.
 */
@interface AWFAnimation : NSObject

/**
 *  Starting date for the animation.
 */
@property (strong, nonatomic) NSDate *fromTime;

/**
 *  Ending date for the animation.
 */
@property (strong, nonatomic) NSDate *toTime;

/**
 *  Total time in seconds for the animation to complete before restarting from the beginning. The animation speed will be calcuated
 *	based on this value, so a longer duration will result in a slower animation speed.
 */
@property (assign, nonatomic) CGFloat duration;

/**
 *  Delay duration to hold the last interval of the animation before restarting from the beginning, in seconds.
 */
@property (assign, nonatomic) CGFloat endDelay;


@property (assign, nonatomic) NSInteger repeatCount;

/**
 *  Total time, in seconds, of the animation based on the start and end dates.
 */
@property (readonly, assign, nonatomic) NSTimeInterval totalTime;

/**
 *  Date of the animation's current position.
 */
@property (readonly, strong, nonatomic) NSDate *currentTime;

/**
 *  The parent timeline animation controlling the animation, if any.
 */
@property (nonatomic, strong) AWFAnimationTimeline *timeline;

/**
 *  The coordinate bounds for the current data being animated.
 */
@property (nonatomic, strong) AWFCoordinateBounds *currentBoundsForData;

/**
 *  Returns whether the animation is currently animating.
 */
@property (readonly, nonatomic, getter = isAnimating) BOOL animating;

/**
 *  Returns whether the animation is currently loading data to be animated.
 */
@property (readonly, nonatomic, getter = isLoading) BOOL loading;

/**
 *  Returns whether the animation has loaded all necessary data and is ready to begin animating.
 */
@property (readonly, nonatomic, getter = isReady) BOOL ready;

/**
 *  Returns whether the animation has played at least once through the end of its timeline.
 */
@property (readonly, nonatomic, getter = hasPlayed) BOOL played;

/**
 *  The object that acts as the data source of the receiving animation.
 *
 *	The data source must adopt an `{@link AWFAnimationDataSource}` protocol.
 */
@property (nonatomic, assign) id<AWFAnimationDataSource> dataSource;

/**
 *  The object that acts as the delegate of the receiving animation.
 *
 *	The delegate must adopt the `{@link AWFAnimationDelegate}` protocol.
 */
@property (nonatomic, assign) id<AWFAnimationDelegate> delegate;

/**
 *  Created a new animation with specific starting and ending dates.
 *
 *  @param startDate The date when the animation should start
 *  @param endDate   The date when the animation should end
 *
 *  @return An animation instance with the defined date range.
 */
- (instancetype)initWithStartDate:(NSDate *)startDate endDate:(NSDate *)endDate;

/**
 *  Creates a new animation whose start date is defined by the specified time interval before the current time/date.
 *
 *	Using this selector will automatically set the `toTime` to the current date, `[NSDate date]`, and the interval provided will
 *	automatically be converted to a negative value to indicate an interval before now.
 *
 *  @param intervalBeforeNow The time interval in seconds before now from which the animation should start
 *
 *  @return An animation instance with the defined date range.
 */
- (instancetype)initWithTimeIntervalBeforeNow:(NSTimeInterval)intervalBeforeNow;

/**
 *  Starts the animation if not already animating.
 */
- (void)start;

/**
 *  Stops the animation if currently animating.
 *
 *	Starting the animation again using `start` will restart the animation from the beginning.
 */
- (void)stop;

/**
 *  Pauses the animation at the current interval.
 *
 *	Starting the animation again using `start` will resume the animation from the current interval.
 */
- (void)pause;

/**
 *  Restarts the animation from the beginning.
 */
- (void)restart;

/**
 *  Advances the animation to a relative position in the time interval.
 *
 *	This value provided should be a value from `0` to `1`, `0` indicating the beginning of the animation and `1` indicating the end. For example,
 *	if you wanted to advance the animation to the midpoint, you would pass a value of `0.5`.
 *
 *  @param position The position to move the animation to as a value from 0 to 1.
 */
- (void)goToPosition:(CGFloat)position;

/**
 *  Advances the animation to a specific time and date in the time interval.
 *
 *	If the provided date is beyond the bounds of the animation, this method will do nothing and a warning will be fired.
 *
 *  @param date The date within the animation range to advance to.
 */
- (void)goToTime:(NSDate *)date;

/**
 *  Advances the animation to a specific time and date in the time interval with an option to stop playback if the animation is
 *  currently playing.
 *
 *  @param date The date within the animation range to advance to.
 *  @param stop Whether or not the animation should stop playing when the position is changed.
 */
- (void)goToTime:(NSDate *)date stop:(BOOL)stop;

/**
 *  Advances the animation to a specific time interval offset, in seconds, from the beginning of the animation.
 *
 *  @param timeOffset The time interval offset from the beginning in seconds.
 */
- (void)goToTimeIntervalWithOffset:(NSTimeInterval)timeOffset;

/**
 *  Reloads the data that is used for the animation as provided by the data source.
 *
 *	Call this method to reload and prepare the data that is used for this animation, specifically after the data source has loaded or
 *	updated the data to be used.
 */
- (void)reloadData;

/**
 *  Resets the animation to its original state, removing all cached data that was previously loaded.
 *
 *  Call this method to remove all cached data and force new data to be loaded next time the animation begins playback. Calling this
 *  method will stop the animation if it is currently playing.
 */
- (void)reset;

@end
