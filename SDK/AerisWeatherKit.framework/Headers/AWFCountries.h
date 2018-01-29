//
//  AFCountriesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/26/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFCountry.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFCountryField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFCountryField const AWFCountryFieldName;
FOUNDATION_EXPORT AWFCountryField const AWFCountryFieldAltName;
FOUNDATION_EXPORT AWFCountryField const AWFCountryFieldISO;
FOUNDATION_EXPORT AWFCountryField const AWFCountryFieldISO3;
FOUNDATION_EXPORT AWFCountryField const AWFCountryFieldPopulation;
FOUNDATION_EXPORT AWFCountryField const AWFCountryFieldArea;

/**
 `AWFCountries` provides conveninece methods for interacting with the
 [`countries` endpoint](http://www.aerisweather.com/support/docs/api/reference/endpoints/countries) of the Aeris API. All requests will return
 instances of `AWFCountry` that will be populated with the data returned from the API unless otherwise indicated.
 */
@interface AWFCountries : AWFWeatherEndpoint

@end

NS_ASSUME_NONNULL_END
