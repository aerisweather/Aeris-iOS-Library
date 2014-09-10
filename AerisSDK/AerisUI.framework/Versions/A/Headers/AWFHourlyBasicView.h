//
//  AFHourlyBasicView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/28/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFWeatherView.h"

@interface AWFHourlyBasicView : AWFWeatherView

/**
 The text to display for the period.
 */
@property (nonatomic, copy) NSString *period;

/**
 The text to display for the temperature.
 */
@property (nonatomic, copy) NSString *temp;

@property (nonatomic, copy) NSString *pop;

@property (nonatomic, copy) NSString *precip;

@property (nonatomic, copy) NSString *winds;

/**
 The UIImage instance to display for the icon.
 */
@property (nonatomic, strong) UIImage *icon;

/**
 Background color for the header above each period.
 */
@property (nonatomic, strong) UIColor *periodBackgroundColor;

/**
 An array of colors to use for a linear gradient background for the header above each period. This value takes precedent over 
 {@link #periodBackgroundColor} when both values are assigned.
 */
@property (nonatomic, strong) NSArray *periodBackgroundGradientColors;

@property (nonatomic, strong) UILabel *periodLabel;
@property (nonatomic, strong) UILabel *tempTextLabel;
@property (nonatomic, strong) UILabel *popLabel;
@property (nonatomic, strong) UILabel *precipLabel;
@property (nonatomic, strong) UILabel *windsTextLabel;
@property (nonatomic, strong) UIImageView *iconImageView;

@end
