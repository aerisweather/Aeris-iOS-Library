//
//  AFFiresLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFFire.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFFireFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFFireFilter const AWFFireFilterLarge;
FOUNDATION_EXPORT AWFFireFilter const AWFFireFilterCritical;
FOUNDATION_EXPORT AWFFireFilter const AWFFireFilterModis;

typedef NSString * AWFFireField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFFireField const AWFFireFieldId;
FOUNDATION_EXPORT AWFFireField const AWFFireFieldDateTime;
FOUNDATION_EXPORT AWFFireField const AWFFireFieldType;
FOUNDATION_EXPORT AWFFireField const AWFFireFieldConfidence;
FOUNDATION_EXPORT AWFFireField const AWFFireFieldArea;
FOUNDATION_EXPORT AWFFireField const AWFFireFieldName;
FOUNDATION_EXPORT AWFFireField const AWFFireFieldState;
FOUNDATION_EXPORT AWFFireField const AWFFireFieldCountry;
FOUNDATION_EXPORT AWFFireField const AWFFireFieldStationSource;
FOUNDATION_EXPORT AWFFireField const AWFFireFieldSatelliteSource;

/**
 `AWFFires` provides convenience methods for interacting with the
 [`fires` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/fires) of the Aeris API. All requests will
 return instances of `AWFFire` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFFires : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
