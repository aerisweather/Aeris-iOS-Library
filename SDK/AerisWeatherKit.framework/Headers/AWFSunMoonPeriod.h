//
//  AFSunMoon.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

/**
 An `AWFSunMoonPeriod` object represents data returned by the [**sunmoon** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/sunmoon/)
 of the Aeris Weather API.
 */
@interface AWFSunMoonPeriod : AWFGeographicObject

/**
 GMT date for the day the information is for.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

//-----------------------------------------------------------------------------
// @name Sun Information
//-----------------------------------------------------------------------------

/**
 GMT date for the sunrise.
 */
@property (nonatomic, strong, nullable) NSDate *sunrise;

/**
 GMT date for the sunset.
 */
@property (nonatomic, strong, nullable) NSDate *sunset;

/**
 GMT date for the point at which the sun is directly overhead.
 */
@property (nonatomic, strong, nullable) NSDate *sunTransit;

/**
 GMT date for the first civil twilight.
 */
@property (nonatomic, strong, nullable) NSDate *twilightCivilBegin;

/**
 GMT date for the second civil twilight.
 */
@property (nonatomic, strong, nullable) NSDate *twilightCivilEnd;

/**
 GMT date for the first nautical twilight.
 */
@property (nonatomic, strong, nullable) NSDate *twilightNauticalBegin;

/**
 GMT date for the second nautical twilight.
 */
@property (nonatomic, strong, nullable) NSDate *twilightNauticalEnd;

/**
 GMT date for the first astronomical twilight.
 */
@property (nonatomic, strong, nullable) NSDate *twilightAstronomicalBegin;

/**
 GMT date for the second astronomical twilight.
 */
@property (nonatomic, strong, nullable) NSDate *twilightAstronomicalEnd;

//-----------------------------------------------------------------------------
// @name Moon Information
//-----------------------------------------------------------------------------

/**
 GMT date for the moon rise.
 */
@property (nonatomic, strong, nullable) NSDate *moonrise;

/**
 GMT date for the moon set.
 */
@property (nonatomic, strong, nullable) NSDate *moonset;

/**
 Date at which point the moon is overhead, or `nil` if not expected.
 */
@property (nonatomic, strong, nullable) NSDate *moonTransit;

/**
 Date at which point the moon is underfoot, or `nil` if not expected.
 */
@property (nonatomic, strong, nullable) NSDate *moonUnderfoot;

/**
 Moon phase as a percentage.
 */
@property (nonatomic, assign) CGFloat moonPhasePercentage;

/**
 Name of the moon phase.
 */
@property (nonatomic, copy, nullable) NSString *moonPhaseName;

/**
 Percentage of the moon that is illuminated.
 */
@property (nonatomic, assign) CGFloat moonIllumination;

/**
 Age of the moon phase in days.
 */
@property (nonatomic, assign) CGFloat moonAge;

/**
 Angle of the moon phase.
 */
@property (nonatomic, assign) CGFloat moonAngle;

@end
