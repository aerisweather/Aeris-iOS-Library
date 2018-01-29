//
//  AFMoonPhasesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFMoonPhase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFMoonPhaseFilter NS_TYPED_EXTENSIBLE_ENUM;
FOUNDATION_EXPORT AWFMoonPhaseFilter const AWFMoonPhaseFilterNew;
FOUNDATION_EXPORT AWFMoonPhaseFilter const AWFMoonPhaseFilterFirst;
FOUNDATION_EXPORT AWFMoonPhaseFilter const AWFMoonPhaseFilterFull;
FOUNDATION_EXPORT AWFMoonPhaseFilter const AWFMoonPhaseFilterThird;

typedef NSString * AWFMoonPhaseField NS_TYPED_EXTENSIBLE_ENUM;
FOUNDATION_EXPORT AWFMoonPhaseField const AWFMoonPhaseFieldDateTime;
FOUNDATION_EXPORT AWFMoonPhaseField const AWFMoonPhaseFieldCode;
FOUNDATION_EXPORT AWFMoonPhaseField const AWFMoonPhaseFieldType;

@class AWFMoonPhase;

/**
 `AWFMoonPhases` provides convenience methods for interacting with the
 [`moonphases` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/moonphases) of the Aeris API. All requests will
 return instances of `AWFMoonPhase` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFMoonPhases : AWFWeatherEndpoint

@end

NS_ASSUME_NONNULL_END
