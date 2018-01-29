//
//  AWFBasicControlView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/5/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <AerisCoreUI/AerisCoreUI.h>

/**
 A `AWFBasicControlView` is a small view that provides a play/stop button for controlling a weather map's animation and displays the current time and
 date for the map's timeline.
 */
@interface AWFBasicControlView : UIView

/**
 The play button that controls a weather map's timeline.
 */
@property (readonly, nonatomic, strong) UIButton *playButton;

/**
 The progress view that is displayed while an animation is loading data.
 */
@property (readonly, nonatomic, strong) AWFCircularProgressView *progressView;

/**
 The day label for the timeline.
 */
@property (readonly, nonatomic, strong) UILabel *dayLabel;

/**
 The time label for the timeline.
 */
@property (readonly, nonatomic, strong) UILabel *timeLabel;

@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;

/**
 Updates the day and time labels with the specified date.
 */
@property (nonatomic, assign) NSDate *currentTime;


/**
 The default frame of the view.
 */
+ (CGRect)defaultFrame;

/**
 Updates the loading progress indicator based on the download progress when requesting remote data required for the animation.
 *
 @param progress The download progress of animation data, from `0.0` (none) to `1.0` (complete).
 @param animated A Boolean indicating whether or not the update should be animated.
 */
- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;

/**
 Whether or not to display the loading indicator. This is used when data has to be requested from a remote source before an animation
 can begin playback.
 *
 @param loading A Boolean indicating whether or not to display the loading indicator.
 */
- (void)showLoading:(BOOL)loading;

@end
