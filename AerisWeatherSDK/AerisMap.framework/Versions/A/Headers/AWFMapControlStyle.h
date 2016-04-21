//
//  AWFMapControlStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/5/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AerisUI.h>

/**
 *  An `AWFMapControlStyle` object is a `AWFCascadingStyle` subclass that provides style specifications for a map control view. This class is used in conjunction
 *  with `AWFBasicControlView` and `AWFTimelineView` to control the styling of the map controls.
 */
@interface AWFMapControlStyle : AWFCascadingStyle

/**
 *  The fill color of the progress indicator.
 */
@property (nonatomic, strong) UIColor *progressFillColor;

/**
 *  The stroke color of the progress indicator.
 */
@property (nonatomic, strong) UIColor *progressStrokeColor;

@end
