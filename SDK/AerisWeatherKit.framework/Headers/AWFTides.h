//
//  AFTidesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFTide.h>
#import <AerisWeatherKit/AWFTideStation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFTideFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFTideFilter const AWFTideFilterHigh;
FOUNDATION_EXPORT AWFTideFilter const AWFTideFilterLow;
FOUNDATION_EXPORT AWFTideFilter const AWFTideFilterHighLow;

typedef NSString * AWFTideField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFTideField const AWFTideFieldStationId;
FOUNDATION_EXPORT AWFTideField const AWFTideFieldDateTime;
FOUNDATION_EXPORT AWFTideField const AWFTideFieldType;
FOUNDATION_EXPORT AWFTideField const AWFTideFieldHeightFT;
FOUNDATION_EXPORT AWFTideField const AWFTideFieldHeightM;
FOUNDATION_EXPORT AWFTideField const AWFTideFieldCity;
FOUNDATION_EXPORT AWFTideField const AWFTideFieldState;
FOUNDATION_EXPORT AWFTideField const AWFTideFieldCountry;

/**
 `AWFTidesLoader` provides convenience methods for interacting with the
 [`tides` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/tides) of the Aeris API. All requests will
 return instances of `AWFTide` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFTides : AWFWeatherEndpoint
@end

@interface AWFTidesStations : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
