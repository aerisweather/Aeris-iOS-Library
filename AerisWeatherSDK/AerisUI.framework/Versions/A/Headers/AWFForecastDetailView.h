//
//  AWFForecastDetailView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFWeatherView.h"

@interface AWFForecastDetailView : AWFWeatherView

@property (nonatomic, assign) BOOL showsPeriod;

@property (nonatomic, strong, readonly) UILabel *periodTextLabel;
@property (nonatomic, strong, readonly) UILabel *tempTextLabel;
@property (nonatomic, strong, readonly) UILabel *weatherTextLabel;
@property (nonatomic, strong, readonly) UILabel *windsTextLabel;
@property (nonatomic, strong, readonly) UILabel *precipTextLabel;
@property (nonatomic, strong, readonly) UILabel *precipTypeTextLabel;
@property (nonatomic, strong, readonly) UIImageView *iconImageView;
@property (nonatomic, strong, readonly) UIView *detailsView;

@end
