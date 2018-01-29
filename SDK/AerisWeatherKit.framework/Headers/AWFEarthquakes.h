//
//  AFEarthquakesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFEarthquake.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFEarthquakeFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFEarthquakeFilter const AWFEarthquakeFilterMini;
FOUNDATION_EXPORT AWFEarthquakeFilter const AWFEarthquakeFilterMinor;
FOUNDATION_EXPORT AWFEarthquakeFilter const AWFEarthquakeFilterLight;
FOUNDATION_EXPORT AWFEarthquakeFilter const AWFEarthquakeFilterModerate;
FOUNDATION_EXPORT AWFEarthquakeFilter const AWFEarthquakeFilterStrong;
FOUNDATION_EXPORT AWFEarthquakeFilter const AWFEarthquakeFilterMajor;
FOUNDATION_EXPORT AWFEarthquakeFilter const AWFEarthquakeFilterGreat;
FOUNDATION_EXPORT AWFEarthquakeFilter const AWFEarthquakeFilterShallow;

typedef NSString * AWFEarthquakeField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFEarthquakeField const AWFEarthquakeFieldId;
FOUNDATION_EXPORT AWFEarthquakeField const AWFEarthquakeFieldDateTime;
FOUNDATION_EXPORT AWFEarthquakeField const AWFEarthquakeFieldMagnitude;
FOUNDATION_EXPORT AWFEarthquakeField const AWFEarthquakeFieldDepth;
FOUNDATION_EXPORT AWFEarthquakeField const AWFEarthquakeFieldName;
FOUNDATION_EXPORT AWFEarthquakeField const AWFEarthquakeFieldState;
FOUNDATION_EXPORT AWFEarthquakeField const AWFEarthquakeFieldCountry;
FOUNDATION_EXPORT AWFEarthquakeField const AWFEarthquakeFieldRegion;

/**
 `AWFEarthquakes` provides convenience methods for interacting with the
 [`earthquakes` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/earthquakes) of the Aeris API. All requests will
 return instances of `AWFEarthquake` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFEarthquakes : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
