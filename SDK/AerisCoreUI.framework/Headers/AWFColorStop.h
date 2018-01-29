//
//  AWFColorStop.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 8/23/16.
//  Copyright © 2016 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern CGFloat const AWFColorStopNilValue;

@interface AWFColorStop : NSObject

@property (nonatomic, strong) UIColor *color;
@property (nonatomic, assign) CGFloat alpha;
@property (nonatomic, assign) NSUInteger totalSteps;
@property (nonatomic, assign) CGFloat value;
@property (nonatomic, copy, nullable) NSString *labelValue;

+ (instancetype)stopWithColor:(UIColor *)color value:(CGFloat)value;
+ (instancetype)stopWithColor:(UIColor *)color value:(CGFloat)value label:(nullable NSString *)label;
+ (instancetype)stopWithColor:(UIColor *)color steps:(NSUInteger)steps value:(CGFloat)value;
+ (instancetype)stopWithColor:(UIColor *)color steps:(NSUInteger)steps value:(CGFloat)value label:(nullable NSString *)label;

@end

NS_ASSUME_NONNULL_END
