//
//  AWFTimelineView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/8/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//


@class AWFTimelineView;
@class AWFTimelineBarView, AWFTimelinePositionView;

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

@property (readonly, nonatomic, strong) AWFTimelineBarView *barView;
@property (readonly, nonatomic, strong) AWFTimelinePositionView *positionView;
@property (readonly, nonatomic, strong) UIButton *playButton;
@property (readonly, nonatomic, strong) UIButton *nowButton;

@property (nonatomic, assign, getter = isPlaying) BOOL playing;
@property (nonatomic, weak) id<AWFTimelineViewDelegate> delegate;

- (void)showLoading:(BOOL)loading;
- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;
- (void)updatePositionForCurrentTime;

@end

@interface AWFTimelineBarView : UIView

@property (nonatomic, assign) CGFloat progress;
@property (nonatomic, assign) CGFloat futurePosition;
@property (nonatomic, strong) UIColor *barFillColor;
@property (nonatomic, strong) UIColor *futureBarFillColor;
@property (nonatomic, strong) UIColor *barStrokeColor;

@end

@interface AWFTimelinePositionView : UIView

@property (readonly, nonatomic, strong) UILabel *textLabel;
@property (readonly, nonatomic, strong) UILabel *detailTextLabel;
@property (nonatomic, assign) CGFloat radius;
@property (nonatomic, strong) UIColor *fillColor;
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, assign) CGFloat strokeWidth;
@property (nonatomic, assign) BOOL pressed;

- (void)showLoading:(BOOL)loading;

@end
