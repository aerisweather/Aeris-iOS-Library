//
//  AWFRiver.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 10/25/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFRiverStatus NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFRiverStatus const AWFRiverStatusOutOfService;
FOUNDATION_EXPORT AWFRiverStatus const AWFRiverStatusOldData;
FOUNDATION_EXPORT AWFRiverStatus const AWFRiverStatusNotDefined;
FOUNDATION_EXPORT AWFRiverStatus const AWFRiverStatusLowWater;
FOUNDATION_EXPORT AWFRiverStatus const AWFRiverStatusNoFlood;
FOUNDATION_EXPORT AWFRiverStatus const AWFRiverStatusAction;
FOUNDATION_EXPORT AWFRiverStatus const AWFRiverStatusMinorFlood;
FOUNDATION_EXPORT AWFRiverStatus const AWFRiverStatusModerateFlood;
FOUNDATION_EXPORT AWFRiverStatus const AWFRiverStatusMajorFlood;

@class AWFRiverObservation;
@class AWFRiverCategory;

/**
 An `AWFRiver` object represents data returned by the [**rivers** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/rivers/)
 of the Aeris Weather API.
 */
@interface AWFRiver : AWFGeographicObject

/**
 The river gauge identifier.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 GMT date for the observation.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 The latest river observation.
 */
@property (nonatomic, strong, nullable) AWFRiverObservation *obs;

/**
 The latest river observation from a secondary sensor when the guage includes a backup. This value is typically `nil` since most guages do not
 include backups.
 */
@property (nonatomic, strong, nullable) AWFRiverObservation *secondaryObs;

/**
 The current river/lake status:
 
 - `out_of_service`: Gauge is known to be out of service
 - `obs_not_current`: Gauge has not reported updated observations recently
 - `not_defined`: Gauge is reporting observations but has no action/flooding levels defined and cannot determine if flooding
 - `low_threshold`: Gauge is reporting levels below the defined low water threshold
 - `no_flooding`: Gauge is reporting observations below flood and action levels
 - `action`: Gauge is reporting observations at or above action levels and near flood stage
 - `minor`: Gauge is reporting levels at or above the defined minor flood level
 - `moderate`: Gauge is reporting levels at or above the defined moderate flood level
 - `major`: Gauge is reporting levels at or above the defined major flood level
 */
@property (nonatomic, copy, nullable) NSString *status;

/**
 The numeric code corresponding to the current river/lake status:
 
 - `-1`: out_of_service
 - `0`: obs_not_current
 - `1`: not_defined
 - `3`: low_threshold
 - `5`: no_flooding
 - `7`: action
 - `9`: minor
 - `11`: moderate
 - `13`: major
 */
@property (nonatomic, assign) CGFloat statusCode;

/**
 Local impacts if available and river is flooding, or `nil` if unavailable or river is not flooding.
 */
@property (nonatomic, copy, nullable) NSString *impacts;

/**
 The body of water where the gauge is located.
 */
@property (nonatomic, copy, nullable) NSString *waterbody;

/**
 The categories for various flood and action levels at the gauge location when available.
 */
@property (nonatomic, strong) NSArray<AWFRiverCategory *> *categories;

/**
 A Boolean indicating whether the gauge contains flooding impacts.
 */
@property (nonatomic, assign) BOOL hasImpacts;

@end

/**
 An `AWFRiverObservation` object represents the latest river observation data for a river.
 */
@interface AWFRiverObservation : AWFWeatherObject

/**
 The water height in feet.
 */
@property (nonatomic, assign) CGFloat heightFT;

/**
 The water height in meters.
 */
@property (nonatomic, assign) CGFloat heightM;

/**
 The water flow in cubic feet per second.
 */
@property (nonatomic, assign) CGFloat flowCFS;

/**
 The water flow in cubic meters per second.
 */
@property (nonatomic, assign) CGFloat flowCMS;

@end

/**
 An `AWFRiverCategory` object represents the various stages and their respective levels for a river.
 */
@interface AWFRiverCategory : AWFWeatherObject

/**
 The height in feet when the water body enters action stage (near flood stage).
 */
@property (nonatomic, assign) CGFloat actionFT;

/**
 The height in meters when the water body enters action stage (nears flood stage).
 */
@property (nonatomic, assign) CGFloat actionM;

/**
 The height in feet that flooding begins for the water body.
 */
@property (nonatomic, assign) CGFloat floodFT;

/**
 The height in meters that flooding begins for the water body.
 */
@property (nonatomic, assign) CGFloat floodM;

/**
 The height in feet that moderate flooding begins for the water body.
 */
@property (nonatomic, assign) CGFloat moderateFT;

/**
 The height in meters that moderate flooding begins for the water body.
 */
@property (nonatomic, assign) CGFloat moderateM;

/**
 The height in feet that major flooding begins for the water body.
 */
@property (nonatomic, assign) CGFloat majorFT;

/**
 The height in meters that major flooding begins for the water body.
 */
@property (nonatomic, assign) CGFloat majorM;

/**
 The height in feet that the water body is considered to be low.
 */
@property (nonatomic, assign) CGFloat lowThresholdFT;

/**
 The height in meters that the water body is considered to be low.
 */
@property (nonatomic, assign) CGFloat lowThresholdM;

@end

NS_ASSUME_NONNULL_END
