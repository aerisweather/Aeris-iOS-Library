//
//  AFActivitiesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFActivity.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFActivity;

/**
 `AWFActivities` provides convenience methods for interacting with the
 [`activities` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/activities) of the Aeris API. All requests will
 return instances of `AWFActivity` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFActivities : AWFWeatherEndpoint

@end

NS_ASSUME_NONNULL_END
