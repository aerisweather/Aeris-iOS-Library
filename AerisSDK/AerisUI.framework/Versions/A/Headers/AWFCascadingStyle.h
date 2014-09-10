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

@property (nonatomic, strong) AWFTextStyleSpec *defaultTextStyle;
@property (nonatomic, strong) AWFTextStyleSpec *detailTextStyle;
@property (nonatomic, strong) AWFTextStyleSpec *headerTextStyle;
@property (nonatomic, strong) AWFTextStyleSpec *headerDetailTextStyle;

//------------------------
// @name Background Colors
//------------------------

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) NSArray *backgroundGradientColors;
@property (nonatomic, strong) UIColor *headerBackgroundColor;
@property (nonatomic, strong) NSArray *headerBackgroundGradientColors;
@property (nonatomic, strong) UIColor *viewControllerBackgroundColor;

@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic, strong) UIColor *keylineColor;

+ (instancetype)style;
+ (id)styleFromObject:(id)object;

- (void)applyToObject:(id)object;
- (void)setValuesFromObject:(id)object;

+ (instancetype)defaultStyle;
+ (void)setDefaultStyle:(AWFCascadingStyle *)style;

@end
