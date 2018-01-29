//
//  AWFPrecipitationLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 4/5/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFPrecipitationEstimate.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `AWFPrecipitation` provides conveninece methods for interacting with the
 [`precip` endpoint](http://www.aerisweather.com/support/docs/api/reference/endpoints/precip) of the Aeris API. All requests will return
 instances of `AWFPrecipitationPeriod` that will be populated with the data returned from the API unless otherwise indicated.
 */
@interface AWFPrecipitationEstimates : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
