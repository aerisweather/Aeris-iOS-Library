//
//  AWFIconSet.h
//  AerisUI
//
//  Created by Nicholas Shipes on 4/14/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AWFIcon) {
	AWFIconPlay = 0,
	AWFIconStop,
	AWFIconNow
};

@interface AWFIconSet : NSObject

+ (UIImage *)iconWithType:(AWFIcon)icon size:(CGSize)size color:(UIColor *)color;
+ (UIImage *)iconWithType:(AWFIcon)icon width:(CGFloat)width color:(UIColor *)color;
+ (UIImage *)iconWithType:(AWFIcon)icon height:(CGFloat)height color:(UIColor *)color;

@end
