//
//  AFSunMoon.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFSunMoonPeriod.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFSunMoonFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFSunMoonFilter const AWFSunMoonFilterSun;
FOUNDATION_EXPORT AWFSunMoonFilter const AWFSunMoonFilterTwilight;
FOUNDATION_EXPORT AWFSunMoonFilter const AWFSunMoonFilterMoon;
FOUNDATION_EXPORT AWFSunMoonFilter const AWFSunMoonFilterMoonPhase;

/**
 `AWFSunMoon` provides convenience methods for interacting with the
 [`sunmoon` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/sunmoon) of the Aeris API. All requests will
 return instances of `AWFSunMoon` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFSunMoon : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
