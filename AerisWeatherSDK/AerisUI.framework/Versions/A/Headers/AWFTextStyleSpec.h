//
//  AWFTextStyleSpec.h
//  AerisUI
//
//  Created by Nicholas Shipes on 4/24/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AWFTextStyleSpec : NSObject

/**
 *  The background color for the text label.
 */
@property (nonatomic, strong) UIColor *backgroundColor;

/**
 *  The text font.
 */
@property (nonatomic, strong) UIFont *font;

/**
 *  The text color.
 */
@property (nonatomic, strong) UIColor *textColor;

/**
 *  The text alignment.
 */
@property (nonatomic, assign) NSTextAlignment textAlignment;

/**
 *  The shadow color.
 */
@property (nonatomic, strong) UIColor *shadowColor;

/**
 *  The shadow offset.
 */
@property (nonatomic, assign) CGSize shadowOffset;

/**
 *  Whether text labels using this style spec should adjust their font size to fit the text.
 */
@property (nonatomic, assign) BOOL adjustsFontSizeToFitWidth;

/**
 *  The minimum scale factor to use when adjusting font size to fit the text.
 */
@property (nonatomic, assign) CGFloat minimumScaleFactor;

/**
 *  Applies the receiver's styles to a text label.
 *
 *  @param label The text label to apply the styles to
 */
- (void)applyToLabel:(UILabel *)label;

/**
 *  Applies the receiver's styles to a text label while overriding the style's font size.
 *
 *  @param label    The text label to apply the styles to
 *  @param fontSize The font size for the text
 */
- (void)applyToLabel:(UILabel *)label withFontSize:(CGFloat)fontSize;

@end
