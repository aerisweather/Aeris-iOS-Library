//
//  AWFBasicControlView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/5/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//


@interface AWFBasicControlView : AWFStyledView

@property (readonly, nonatomic, strong) UIButton *playButton;
@property (readonly, nonatomic, strong) AWFCircularProgressView *progressView;
@property (readonly, nonatomic, strong) UILabel *dayLabel;
@property (readonly, nonatomic, strong) UILabel *timeLabel;
@property (nonatomic, assign) NSDate *currentTime;

@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;

+ (CGRect)defaultFrame;

- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;
- (void)showLoading:(BOOL)loading;

@end
