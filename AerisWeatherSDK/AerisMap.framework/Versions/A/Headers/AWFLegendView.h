//
//  AWFLegendView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/29/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AWFLegendStyle;

/**
 An `AWFLegendView` object provides the base view class used for rendering data-specific legends based on a `AWFLegendStyle`.
 */
@interface AWFLegendView : UIView

/**
 *  Initializes and returns a newly allocated `AWFLegendView` instance with the specified `style` and `frame`.
 *
 *  @param style The `AWFLegendStyle` to use when rendering the legend
 *  @param frame The initial frame for the legend; the legend's height will be calculated automatically based on the width and style configuration.
 *
 *  @return The initialized `AWFLegendView` instance or `nil` if one couldn't be created
 */
- (instancetype)initWithStyle:(AWFLegendStyle *)style frame:(CGRect)frame;

@end
