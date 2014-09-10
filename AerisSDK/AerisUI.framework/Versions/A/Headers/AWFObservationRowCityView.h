//
//  AWFObservationRowCityView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFWeatherView.h"

@interface AWFObservationRowCityView : AWFWeatherView

@property (nonatomic, strong) UILabel *nameLabel;
@property (nonatomic, strong) UILabel *timeLabel;
@property (nonatomic, strong) UILabel *weatherTextLabel;
@property (nonatomic, strong) UILabel *tempTextLabel;
@property (nonatomic, strong) UIImageView *iconImageView;

@property (nonatomic, strong) UIColor *headerBackgroundColor;
@property (nonatomic, strong) NSArray *headerBackgroundGradientColors;

@end
