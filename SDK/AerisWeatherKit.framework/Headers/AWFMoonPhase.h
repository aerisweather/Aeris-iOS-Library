//
//  AFMoonPhase.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFMoonPhase` object represents data returned by the [**sunmoon/moonphases** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/sunmoon-moonphases/)
 of the Aeris Weather API.
 */
@interface AWFMoonPhase : AWFWeatherObject

/**
 GMT date when the event took place.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Local time zone of the event location.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

/**
 The numeric representation of the moon phase:
 
 - `0`: new moon
 - `1`: first quarter moon
 - `2`: full moon
 - `3`: third quarter moon
 */
@property (nonatomic, assign) NSInteger code;

/**
 The moon phase name.
 */
@property (nonatomic, copy, nullable) NSString *name;

@end

NS_ASSUME_NONNULL_END
