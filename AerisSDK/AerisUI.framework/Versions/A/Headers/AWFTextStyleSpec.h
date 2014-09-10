//
//  AWFTextStyleSpec.h
//  AerisUI
//
//  Created by Nicholas Shipes on 4/24/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AWFTextStyleSpec : NSObject

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, assign) NSTextAlignment textAlignment;
@property (nonatomic, strong) UIColor *shadowColor;
@property (nonatomic, assign) CGSize shadowOffset;

@property (nonatomic, assign) BOOL adjustsFontSizeToFitWidth;
@property (nonatomic, assign) CGFloat minimumScaleFactor;

- (void)applyToLabel:(UILabel *)label;
- (void)applyToLabel:(UILabel *)label withFontSize:(CGFloat)fontSize;

@end
