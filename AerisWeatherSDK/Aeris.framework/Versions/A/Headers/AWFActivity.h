//
// AFActivity.h
// Aeris
//
// Created by Nicholas Shipes on 9/6/13.
// Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

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

@interface AWFActivity : AWFGeographicObject

//-----------------------------------------------------------------------------
// @name Activity Data
//-----------------------------------------------------------------------------

/**
 *  The enumerated representation of the activity type.
 */
@property (nonatomic, readonly) AWFActivityType activityType;

/**
 *  The string representation of the activity type.
 */
@property (nonatomic, copy) NSString *activityTypeENG;

/**
 *  An `AWFActivityPeriod` containing activity-related data based on current conditions.
 */
@property (nonatomic, strong) AWFActivityPeriod *current;

/**
 *  Array of AWFActivityPeriod instances that contain the activity-related data for that period.
 */
@property (nonatomic, copy) NSArray *periods;

+ (NSString *)filterStringForActivityType:(enum AWFActivityType)activityType;

@end


@interface AWFActivityPeriod : AWFObject

/**
 *  GMT date for the period.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  The enumerated activity quality value.
 */
@property (nonatomic, readonly) AWFActivityQuality quality;

/**
 *  The `NSNumber` representation of the quality index.
 */
@property (nonatomic, strong) NSNumber *qualityIndex;

/**
 *  The string representation of the quality index.
 */
@property (nonatomic, copy) NSString *qualityENG;

@end