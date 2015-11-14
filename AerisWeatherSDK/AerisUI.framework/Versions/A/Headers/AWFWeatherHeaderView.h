//
//  AWFWeatherHeaderView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AWFStyledView.h>

/**
 *  An `AWFWeatherHeaderView` object is a `AWFStyledView` subclass that is used within `AWFWeatherView` instances and is should be styled differently than
 *  other content within the weather view. This view is commonly used to display a title and subtitle, such as date and time or location coordinates.
 */
@interface AWFWeatherHeaderView : AWFStyledView

/**
 *  Returns the label used for the main textual content of the header view.
 */
@property (nonatomic, strong) UILabel *textLabel;

/**
 *  Returns the secondary label of the header view.
 */
@property (nonatomic, strong) UILabel *detailTextLabel;

/**
 *  The layout of the `textLabel` and `detailTextLabel` labels within the view. The default value is `AWFLayoutVertical`.
 */
@property (nonatomic, assign) AWFLayout layout;

@end