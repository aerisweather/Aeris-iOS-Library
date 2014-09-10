//
//  AWFTimelineView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/8/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//


@class AWFTimelineView;

@protocol AWFTimelineViewDelegate <NSObject>
@optional

- (void)timelineView:(AWFTimelineView *)timelineView didPanToDate:(NSDate *)date;
- (void)timelineView:(AWFTimelineView *)timelineView didSelectDate:(NSDate *)date;

@end

@interface AWFTimelineView : AWFStyledView

@property (nonatomic, strong) NSDate *currentTime;
@property (nonatomic, strong) NSDate *startDate;
@property (nonatomic, strong) NSDate *endDate;
@property (readonly, nonatomic, assign) CGFloat position;

@property (readonly, nonatomic, strong) UIButton *playButton;
@property (readonly, nonatomic, strong) UIButton *nowButton;

@property (nonatomic, assign, getter = isPlaying) BOOL playing;
@property (nonatomic, weak) id<AWFTimelineViewDelegate> delegate;

- (void)showLoading:(BOOL)loading;
- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;
- (void)updatePositionForCurrentTime;

@end
