//
//  AFNormalsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFNormal.h>
#import <AerisWeatherKit/AWFNormalStation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFNormalFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFNormalFilter const AWFNormalFilterDaily;
FOUNDATION_EXPORT AWFNormalFilter const AWFNormalFilterMonthly;
FOUNDATION_EXPORT AWFNormalFilter const AWFNormalFilterYearly;
FOUNDATION_EXPORT AWFNormalFilter const AWFNormalFilterHasTemp;
FOUNDATION_EXPORT AWFNormalFilter const AWFNormalFilterHasPrecip;
FOUNDATION_EXPORT AWFNormalFilter const AWFNormalFilterHasSnow;

typedef NSString * AWFNormalField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldStationId;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldName;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldState;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldCountry;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldMonth;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldDay;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldMonthDay;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldMaxTemp;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldMinTemp;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldAverageTemp;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldHeatingDegreeDays;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldCoolingDegreeDays;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldMonthlyPrecip;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldYearlyPrecip;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldMonthlySnow;
FOUNDATION_EXPORT AWFNormalField const AWFNormalFieldYearlySnow;

/**
 `AWFNormals` provides convenience methods for interacting with the
 [`normals` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/normals) of the Aeris API. All requests will
 return instances of `AWFNormal` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFNormals : AWFWeatherEndpoint

@end

@interface AWFNormalsStations : AWFWeatherEndpoint

@end

NS_ASSUME_NONNULL_END
