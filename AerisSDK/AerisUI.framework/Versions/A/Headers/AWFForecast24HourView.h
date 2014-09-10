//
//  AWFForecast24HourView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFWeatherView.h"

@class AWFForecastDetailView, AWFWeatherHeaderView;

@interface AWFForecast24HourView : AWFWeatherView

@property (nonatomic, strong) UILabel *periodLabel;
@property (nonatomic, strong) UILabel *dateLabel;

/**
 The `AWFForecastDetailView` instance for the first period.
 */
@property (nonatomic, strong, readonly) AWFForecastDetailView *firstPeriodView;

/**
 The `AWFForecastDetailView` instance for the second period.
 */
@property (nonatomic, strong, readonly) AWFForecastDetailView *secondPeriodView;

@end
