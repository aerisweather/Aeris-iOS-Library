//
//  AWFMapControlStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/5/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <AerisCoreUI/AerisCoreUI.h>

/**
 An `AWFMapControlStyle` object provides style specifications for a map control view. This class is used in conjunction with `AWFBasicControlView`
 and `AWFTimelineView` to control the styling of the map controls.
 */
@interface AWFMapControlStyle : NSObject

/**
 The background color to use for the view.
 */
@property (nonatomic, strong) UIColor *backgroundColor;

/**
 The fill color of the progress indicator.
 */
@property (nonatomic, strong) UIColor *progressFillColor;

/**
 The stroke color of the progress indicator.
 */
@property (nonatomic, strong) UIColor *progressStrokeColor;

/**
 The default text style.
 */
@property (nonatomic, strong) AWFTextStyleSpec *defaultTextStyle;

/**
 The secondary text style.
 */
@property (nonatomic, strong) AWFTextStyleSpec *detailTextStyle;

@end
