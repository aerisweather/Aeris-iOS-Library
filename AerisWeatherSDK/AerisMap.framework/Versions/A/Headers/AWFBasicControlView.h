//
//  AWFBasicControlView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/5/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

/**
 *  A `AWFBasicControlView` is a small view that provides a play/stop button for controlling a weather map's animation and displays the current time and
 *  date for the map's timeline.
 */
@interface AWFBasicControlView : AWFStyledView

/**
 *  The play button that controls a weather map's timeline.
 */
@property (readonly, nonatomic, strong) UIButton *playButton;

/**
 *  The progress view that is displayed while an animation is loading data.
 */
@property (readonly, nonatomic, strong) AWFCircularProgressView *progressView;

/**
 *  The day label for the timeline.
 */
@property (readonly, nonatomic, strong) UILabel *dayLabel;

/**
 *  The time label for the timeline.
 */
@property (readonly, nonatomic, strong) UILabel *timeLabel;

/**
 *  Updates the day and time labels with the specified date.
 */
@property (nonatomic, assign) NSDate *currentTime;

+ (CGRect)defaultFrame;

- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;
- (void)showLoading:(BOOL)loading;

@end
