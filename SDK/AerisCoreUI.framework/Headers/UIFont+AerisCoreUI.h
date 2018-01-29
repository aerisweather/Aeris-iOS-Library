//
//  UIFont+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/23/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIFont (AerisCoreUI)

- (CGSize)awf_sizeNeededForString:(NSString *)string maxWidth:(CGFloat)maxWidth;
- (CGSize)awf_sizeNeededForString:(NSString *)string maxWidth:(CGFloat)maxWidth lineBreakMode:(NSLineBreakMode)lineBreakMode;

@end

NS_ASSUME_NONNULL_END
