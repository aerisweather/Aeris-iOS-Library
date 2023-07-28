//
//  AWFLightningSummaryView.h
//  AerisDemoSupport
//
//  Created by Slipp Douglas Thompson on 5/31/23.
//  Copyright © 2023 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisDemoSupport/AWFStyledView.h>

@class AWFStyledHeaderView;

@interface AWFLightningSummaryView : AWFStyledView

@property (readonly, nonatomic, strong) AWFStyledHeaderView *headerView;

- (void)addRowWithTitle:(NSString *)titleString andValue:(NSString *)valueString;
- (void)removeAllRows;

- (void)setMinValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
- (void)setMaxValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
- (void)setAverageValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
- (void)setAllValues:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;

@end
