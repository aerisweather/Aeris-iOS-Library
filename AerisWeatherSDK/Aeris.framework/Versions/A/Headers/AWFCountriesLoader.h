//
//  AFCountriesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/26/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFCountryFieldName;
extern NSString * const AWFCountryFieldAltName;
extern NSString * const AWFCountryFieldISO;
extern NSString * const AWFCountryFieldISO3;
extern NSString * const AWFCountryFieldPopulation;
extern NSString * const AWFCountryFieldArea;

/**
 *  `AWFCountriesLoader` provides conveninece methods for interacting with the
 *  [`countries` endpoint](http://www.aerisweather.com/support/docs/api/reference/endpoints/countries) of the Aeris API. All requests will return
 *  instances of `AWFCountry` that will be populated with the data returned from the API unless otherwise indicated.
 */
@interface AWFCountriesLoader : AWFGeographicObjectLoader

@end