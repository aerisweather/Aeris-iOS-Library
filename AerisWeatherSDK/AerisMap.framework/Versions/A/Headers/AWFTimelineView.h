//
//  AWFTimelineView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/8/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//


@class AWFTimelineView;
@class AWFTimelineBarView, AWFTimelinePositionView;

/**
 *  The `AWFTimelineViewDelegate` protocol defines a set of optional methods that you can use to receive messages related to updates or changes
 *  to a timeline.
 */
@protocol AWFTimelineViewDelegate <NSObject>
@optional

/**
 *  Tells the delegate that the timeline was scrubbed to the given `date`.
 *
 *  @param timelineView The timeline that was panned
 *  @param date         The date that the timeline was panned to
 */
- (void)timelineView:(AWFTimelineView *)timelineView didPanToDate:(NSDate *)date;

/**
 *  Tells the delegate that the timeline was changed to a different date.
 *
 *  @param timelineView The timeline that changed
 *  @param date         The new date for the timeline's current position
 */
- (void)timelineView:(AWFTimelineView *)timelineView didSelectDate:(NSDate *)date;

@end


/**
 *  An `AWFTimelineView` is a view that provides a play/stop control, the current date and time and a scrubbable timeline slider bar for use with animatable weather
 *  data layers on an `AWFWeatherMap` instance.
 */
@interface AWFTimelineView : AWFStyledView

/**
 *  The current date and time being displayed. Setting this value will automatically update the day and time labels with the specified date.
 */
@property (nonatomic, strong) NSDate *currentTime;

/**
 *  The starting date and time for the animation timeline. This should correspond to the `timelineStartDate` property on `AWFWeatherMap`.
 */
@property (nonatomic, strong) NSDate *startDate;

/**
 *  The ending date and time for the animation timeline. This should correspond to the `timelineEndDate` property on `AWFWeatherMap`.
 */
@property (nonatomic, strong) NSDate *endDate;

/**
 *  The current animation position along the timeline, from `0.0` (beginning) to `1.0` (end).
 */
@property (readonly, nonatomic, assign) CGFloat position;

/**
 *  The timeline bar view.
 */
@property (readonly, nonatomic, strong) AWFTimelineBarView *barView;

/**
 *  The circular view indicating the timeline's current position.
 */
@property (readonly, nonatomic, strong) AWFTimelinePositionView *positionView;

/**
 *  The play button used to start and stop an animation. If an animation is currently playing, this button will update to a stop icon instead.
 */
@property (readonly, nonatomic, strong) UIButton *playButton;

/**
 *  Used to update the timeline position immediately to the current date and time.
 */
@property (readonly, nonatomic, strong) UIButton *nowButton;

/**
 *  Whether or not the animation and timeline are currently playing.
 */
@property (nonatomic, assign, getter = isPlaying) BOOL playing;


@property (nonatomic, weak) id<AWFTimelineViewDelegate> delegate;

/**
 *  Whether or not to display the loading indicator on the timeline view. This is used when data has to be requested from a remote source before an animation
 *  can begin playback.
 *
 *  @param loading A Boolean indicating whether or not to display the loading indicator.
 */
- (void)showLoading:(BOOL)loading;

/**
 *  Updates the timeline loading progress position based on the download progress when requesting remote data required for the animation.
 *
 *  @param progress The download progress of animation data, from `0.0` (none) to `1.0` (complete).
 *  @param animated A Boolean indicating whether or not the update should be animated.
 */
- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;

/**
 *  Updates the timeline's position indicator view to the current date and time along the timeline.
 */
- (void)updatePositionForCurrentTime;

@end



/**
 *  An `AWFTimelineBarView` object is used in an `AWFTimelineView` instance to represent the timeline bar and full date/time range of the animation.
 */
@interface AWFTimelineBarView : UIView

/**
 *  The current data loading progress for an animation, from `0.0` to `1.0`. Updating this value will adjust the width of the bar filled using the `barFillColor` color
 *  and is used to represent what percentage of the data required for an animation has loaded, if required.
 */
@property (nonatomic, assign) CGFloat progress;

/**
 *  Indicates the position along the timeline, from `0.0` (beginning) to `1.0` (ending), where the date and time range changes to be in the future. This position
 *  be just to the right of the current date and time. If the timeline range does not include the current date and time, then this value will not be used.
 */
@property (nonatomic, assign) CGFloat futurePosition;

/**
 *  The fill color used to indicate the portion of the timeline that has been loaded based on the `progress` value.
 */
@property (nonatomic, strong) UIColor *barFillColor;

/**
 *  The fill color used to indiciate the time range in the future. The timeline bar will be filled with this color from the position along the timeline bar indicated
 *  by `futurePosition` and extend to the right bounds of the bar.
 */
@property (nonatomic, strong) UIColor *futureBarFillColor;

/**
 *  The stroke color to apply around the timeline bar.
 */
@property (nonatomic, strong) UIColor *barStrokeColor;

@end



/**
 *  An `AWFTimelinePositionView` object is used in an `AWFTimelineView` instance to represent an animation's current position along a timeline.
 */
@interface AWFTimelinePositionView : UIView

/**
 *  The primary text label displayed above the indicator. This is typically used for displaying the current time at a give position along the timeline.
 */
@property (readonly, nonatomic, strong) UILabel *textLabel;

/**
 *  The secondary text label displayed below the indicator. This is typically used for displaying the current day and date at a given position along the timeline.
 */
@property (readonly, nonatomic, strong) UILabel *detailTextLabel;

/**
 *  The corner radius for the indicator.
 */
@property (nonatomic, assign) CGFloat radius;

/**
 *  The fill color for the indicator.
 */
@property (nonatomic, strong) UIColor *fillColor;

/**
 *  The stroke color for the indicator.
 */
@property (nonatomic, strong) UIColor *strokeColor;

/**
 *  The stroke width for the indicator.
 */
@property (nonatomic, assign) CGFloat strokeWidth;

/**
 *  A Boolean indicating whether or not the indicator should appear in a pressed state. When in a pressed state, the indicator increases in scale.
 */
@property (nonatomic, assign) BOOL pressed;

/**
 *  Whether or not to update the indicator to the loading state. When in a loading state, the indiciator is scaled up to reveal an animated loading indicator
 *  and the text labels are hidden until the control is updated back to its default state.
 *
 *  @param loading A Boolean indicating whether the indicator should appear in a loading state
 */
- (void)showLoading:(BOOL)loading;

@end
