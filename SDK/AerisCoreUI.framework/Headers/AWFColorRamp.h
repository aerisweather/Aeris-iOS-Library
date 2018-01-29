//
//  AWFColorRamp.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 8/23/16.
//  Copyright © 2016 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFColorStop, AWFColorRampInterval, AWFColorRampIntervalRange;

@interface AWFColorRamp : NSObject

@property (nonatomic, strong, readonly, nullable) NSArray<AWFColorStop *> *stops;
@property (nonatomic, readonly, nullable) NSArray<AWFColorRampInterval *> *intervals;
@property (nonatomic, readonly) NSInteger totalIntervals;
@property (nonatomic, assign) BOOL includeValueLabels;

@property (nonatomic, strong) NSArray<AWFColorRampIntervalRange *> *colorIntervalRanges;
@property (nonatomic, strong) NSArray<AWFColorRampIntervalRange *> *labelIntervalRanges;

- (instancetype)initWithColorStops:(NSArray<AWFColorStop *> *)stops;

- (void)addStop:(AWFColorStop *)stop;
- (void)addStops:(NSArray<AWFColorStop *> *)stops;
- (AWFColorStop *)addStopWithColor:(UIColor *)color steps:(NSUInteger)steps value:(CGFloat)value;
- (AWFColorStop *)addStopWithColor:(UIColor *)color steps:(NSUInteger)steps value:(CGFloat)value label:(nullable NSString *)label;
- (AWFColorStop *)addStopWithColor:(UIColor *)color steps:(NSUInteger)steps value:(CGFloat)value label:(nullable NSString *)label alpha:(CGFloat)alpha;
- (void)removeStop:(AWFColorStop *)stop;
- (void)removeAllStops;

@end


@interface AWFColorRampInterval : NSObject

@property (nonatomic, assign) CGFloat value;
@property (nonatomic, copy, nullable) NSString *label;
@property (nonatomic, assign) NSTextAlignment labelAlignment;
@property (nonatomic, strong) UIColor *color;

- (instancetype)initWithValue:(CGFloat)value color:(UIColor *)color label:(nullable NSString *)label;

@end


@interface AWFColorRampIntervalRange : NSObject

@property (nonatomic, assign) CGFloat minValue;
@property (nonatomic, assign) CGFloat maxValue;
@property (nonatomic, assign) CGFloat interval;
@property (nonatomic, assign) BOOL isEvery;

+ (instancetype)rangeFromValue:(CGFloat)fromValue toValue:(CGFloat)toValue withInterval:(CGFloat)interval;
+ (instancetype)rangeFromString:(NSString *)string;
+ (NSArray<AWFColorRampIntervalRange *> *)arrayOfRangesFromString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
