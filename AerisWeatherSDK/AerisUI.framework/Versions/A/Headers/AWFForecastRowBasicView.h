//
//  AWFForecastRowBasicView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/28/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFWeatherView.h"

@interface AWFForecastRowBasicView : AWFWeatherView

/**
 The text to display for the day title/name.
 */
@property (nonatomic, copy) NSString *day;

/**
 The text to display for the date.
 */
@property (nonatomic, copy) NSString *date;

/**
 The text to display for the weather phrase.
 */
@property (nonatomic, copy) NSString *weather;

/**
 The text to display for the high temperature.
 */
@property (nonatomic, copy) NSString *hightemp;

/**
 The text to display for the low temperature.
 */
@property (nonatomic, copy) NSString *lowtemp;

/**
 The UIImage to display for the icon.
 */
@property (nonatomic, strong) UIImage *icon;

@property (nonatomic, strong) UILabel *dayLabel;
@property (nonatomic, strong) UILabel *dateLabel;
@property (nonatomic, strong) UILabel *weatherTextLabel;
@property (nonatomic, strong) UILabel *hightempLabel;
@property (nonatomic, strong) UILabel *lowtempLabel;
@property (nonatomic, strong) UIImageView *iconImageView;

@end
