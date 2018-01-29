//
// AFActivity.h
// Aeris
//
// Created by Nicholas Shipes on 9/6/13.
// Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

typedef NS_ENUM (NSUInteger, AWFActivityType) {
	AWFActivityTypeUnknown = 0,
	AWFActivityTypeSnowmobile,
	AWFActivityTypeAtv
};

typedef NS_ENUM (NSUInteger, AWFActivityQuality) {
	AWFActivityQualityUnknown = 0,
	AWFActivityQualityBad,
	AWFActivityQualityPoor,
	AWFActivityQualityGood,
	AWFActivityQualityExcellent,
	AWFActivityQualityBest
};

@class AWFActivityPeriod;

/**
 An `AWFActivity` object represents data returned by the [**activities** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/activities/)
 of the Aeris Weather API.
 */
@interface AWFActivity : AWFGeographicObject

//-----------------------------------------------------------------------------
// @name Activity Data
//-----------------------------------------------------------------------------

/**
 The enumerated representation of the activity type.
 */
@property (nonatomic, readonly) AWFActivityType activityType;

/**
 The string representation of the activity type.
 */
@property (nonatomic, copy, nullable) NSString *activityTypeENG;

/**
 An `AWFActivityPeriod` containing activity-related data based on current conditions.
 */
@property (nonatomic, strong, nullable) AWFActivityPeriod *current;

/**
 Array of AWFActivityPeriod instances that contain the activity-related data for that period.
 */
@property (nonatomic, copy, nullable) NSArray<AWFActivityPeriod *> *periods;

+ (nullable NSString *)filterStringForActivityType:(enum AWFActivityType)activityType;

@end


@interface AWFActivityPeriod : AWFWeatherObject

/**
 GMT date for the period.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 The enumerated activity quality value.
 */
@property (nonatomic, readonly) AWFActivityQuality quality;

/**
 The numeric representation of the quality index.
 */
@property (nonatomic, assign) NSInteger qualityIndex;

/**
 The string representation of the quality index.
 */
@property (nonatomic, copy, nullable) NSString *qualityENG;

@end
