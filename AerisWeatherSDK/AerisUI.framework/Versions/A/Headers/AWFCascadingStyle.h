//
//  AWFCascadingStyle.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class AWFTextStyleSpec;

/**
 *  An `AWFCascadingStyle` object contains style information that can be applied to `AWFStyledView` instances. This base class already contains default
 *  styles that are used for all styled views and should be subclassed to provide your own custom styles.
 */
@interface AWFCascadingStyle : NSObject

//------------------
// @name Layout
//------------------

/**
 *  Padding to use within a content view.
 */
@property (nonatomic, assign) CGFloat inset;

//------------------
// @name Text Styles
//------------------

/**
 *  The default text style for all text.
 */
@property (nonatomic, strong) AWFTextStyleSpec *defaultTextStyle;

/**
 *  The text style for secondary text, such as date and time.
 */
@property (nonatomic, strong) AWFTextStyleSpec *detailTextStyle;

/**
 *  The primary text style for a header view.
 */
@property (nonatomic, strong) AWFTextStyleSpec *headerTextStyle;

/**
 *  The text style for secondary text within a header view, such as date and time.
 */
@property (nonatomic, strong) AWFTextStyleSpec *headerDetailTextStyle;

//------------------------
// @name Background Colors
//------------------------

/**
 *  The primary background color
 */
@property (nonatomic, strong) UIColor *backgroundColor;

/**
 *  An array of colors to use for the gradient background.
 */
@property (nonatomic, strong) NSArray *backgroundGradientColors;

/**
 *  The primary background color for header views.
 */
@property (nonatomic, strong) UIColor *headerBackgroundColor;

/**
 *  An array of colors to use for the gradient background in header views.
 */
@property (nonatomic, strong) NSArray *headerBackgroundGradientColors;

/**
 *  The primary background color for view controller root views.
 */
@property (nonatomic, strong) UIColor *viewControllerBackgroundColor;


@property (nonatomic, strong) UIColor *tintColor;

/**
 *  The color for keylines within a view.
 */
@property (nonatomic, strong) UIColor *keylineColor;

/**
 *  Creates and returns a `AWFCascadingStyle` instance initialized with the default styles.
 *
 *  @return The initialized style instance
 */
+ (instancetype)style;

//+ (id)styleFromObject:(id)object;
//- (void)applyToObject:(id)object;
//- (void)setValuesFromObject:(id)object;

/**
 *  Returns the current default style instance.
 */
+ (instancetype)defaultStyle;

/**
 *  Sets the default style instance.
 *
 *  @param style The style to use as the default
 */
+ (void)setDefaultStyle:(AWFCascadingStyle *)style;

@end
