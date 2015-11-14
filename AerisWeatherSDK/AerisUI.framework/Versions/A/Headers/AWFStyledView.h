//
//  AWFStyledView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/6/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

typedef NS_ENUM (NSUInteger, AWFLayout) {
	AWFLayoutVertical = 0,
	AWFLayoutHorizontal
};

@class AWFCascadingStyle;

/**
 *  An `AWFStyledView` object is a view that supports applying styles from an `AWFCascadingStyle` instance. This is the base class for all `AWFWeatherView`
 *  instances.
 */
@interface AWFStyledView : UIView

/**
 *  An array of colors to use as the background gradient.
 */
@property (nonatomic, strong) NSArray *backgroundGradientColors;

/**
 *  The `AWFCascadingStyle` instance currently associated with the view.
 */
@property (nonatomic, strong, readonly) AWFCascadingStyle *style;

/**
 *  Defines the top, left, bottom and right insets around the content relative to the view's bounds.
 */
@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;

/**
 *  Creates and returns an `AWFStyledView` instance initialized with the `style` and `frame`.
 *
 *  @param style The style to apply to the view
 *  @param frame The frame rectangle for the view, measured in points.
 *
 *  @return An initialized view or `nil` if the object couldn't be created.
 */
- (instancetype)initWithStyle:(AWFCascadingStyle *)style frame:(CGRect)frame;

/**
 *  Updates the view with the `style` options.
 *
 *  @param style The style to apply to the view
 */
- (void)applyStyle:(AWFCascadingStyle *)style;

- (void)setup;

/**
 *  Returns the frame for the view's content based on `contentEdgeInsets`.
 */
- (CGRect)contentFrame;

@end