//
//  AWFObservationView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFWeatherView.h"

@interface AWFObservationView : AWFWeatherView

@property (nonatomic, assign) NSUInteger numberOfDetailColumns;

@property (nonatomic, strong, readonly) UILabel *locationTextLabel;
@property (nonatomic, strong, readonly) UILabel *tempTextLabel;
@property (nonatomic, strong, readonly) UILabel *weatherTextLabel;
@property (nonatomic, strong, readonly) UILabel *feelslikeTextLabel;
@property (nonatomic, strong, readonly) UILabel *windsTextLabel;
@property (nonatomic, strong, readonly) UILabel *humidityTextLabel;
@property (nonatomic, strong, readonly) UILabel *dewpointTextLabel;
@property (nonatomic, strong, readonly) UILabel *pressureTextLabel;
@property (nonatomic, strong, readonly) UIImageView *iconImageView;

/**
 *  Controls the visibility of the detail view.
 *
 *  @param show     `YES` if the detail view should be visible, otherwise `NO`.
 *  @param animated `YES` if showing or hiding the detail view should be animated, otherwise `NO` for instantly showing or hiding the view.
 */
- (void)showDetails:(BOOL)show animated:(BOOL)animated;

@end
