//
//  AWFCircularProgressView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/5/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//


@interface AWFCircularProgressView : UIView

@property (nonatomic, assign) CGFloat progress;
@property (nonatomic, strong) UIColor *progressColor;
@property (nonatomic, strong) UIColor *fillColor;
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, assign) CGFloat strokeWidth;

- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;

@end
