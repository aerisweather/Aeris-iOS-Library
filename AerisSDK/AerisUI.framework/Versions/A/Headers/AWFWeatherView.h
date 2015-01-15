//
//  AWFWeatherView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/26/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AWFStyledView.h>

@class AWFWeatherHeaderView, AWFCascadingStyle;

/**
 *  An `AWFWeatherView` object an `AWFStyledView` subclass that supports adding a header view and is the base class for all built-in weather views.
 */
@interface AWFWeatherView : AWFStyledView

@property (nonatomic, strong) AWFWeatherHeaderView *headerView;

@end
