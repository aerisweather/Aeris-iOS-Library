//
//  AWFObservationCalloutContentView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFDataLoading.h>

/**
 An `AWFObservationCalloutContentView` object is a `UIView` subclass that displays a temperature value and weather icon within a weather
 map's callout view. This class is typically used on a long press gesture on the weather map to display current weather conditions at that coordinate.
 */
@interface AWFObservationCalloutContentView : UIView <AWFDataLoading>

/**
 The temperature text label.
 */
@property (readonly, nonatomic, strong) UILabel *tempLabel;

/**
 The icon image view.
 */
@property (readonly, nonatomic, strong) UIImageView *iconView;

/**
 A Boolean value indicated whether the view currently has data.
 */
@property (nonatomic, readonly) BOOL hasData;

/**
 A Boolean value indicating whether the view is currently loading data.
 */
@property (nonatomic, readonly) BOOL isLoading;

@end
