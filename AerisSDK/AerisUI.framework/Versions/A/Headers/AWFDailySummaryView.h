//
//  AWFDailySummaryView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 8/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AWFWeatherView.h>

@interface AWFDailySummaryView : AWFWeatherView

@property (readonly, nonatomic, strong) UILabel *periodTextLabel;
@property (readonly, nonatomic, strong) UILabel *weatherTextLabel;
@property (readonly, nonatomic, strong) UILabel *hightempLabel;
@property (readonly, nonatomic, strong) UILabel *lowtempLabel;
@property (readonly, nonatomic, strong) UIImageView *iconImageView;

- (void)setMinValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
- (void)setMaxValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
- (void)setAverageValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;

@end