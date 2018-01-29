//
//  AWFForecastsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFForecast.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFForecastFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFForecastFilter const AWFForecastFilterDay;
FOUNDATION_EXPORT AWFForecastFilter const AWFForecastFilterDayNight;
FOUNDATION_EXPORT AWFForecastFilter const AWFForecastFilter1Hour;
FOUNDATION_EXPORT AWFForecastFilter const AWFForecastFilter3Hour;
FOUNDATION_EXPORT AWFForecastFilter const AWFForecastFilter6Hour;
FOUNDATION_EXPORT AWFForecastFilter const AWFForecastFilter12Hour;

/**
 `AWFForecasts` provides convenience methods for interacting with the
 [`forecasts` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/forecasts) of the Aeris API. All requests will
 return instances of `AWFForecast` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFForecasts : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
