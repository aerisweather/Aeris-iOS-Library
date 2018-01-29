//
//  AWFThreatsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/13/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFThreat.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `AWFThreats` provides convenience methods for interacting with the
 [`threats` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/threats) of the Aeris API. All requests will
 return instances of `AWFThreat` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFThreats : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
