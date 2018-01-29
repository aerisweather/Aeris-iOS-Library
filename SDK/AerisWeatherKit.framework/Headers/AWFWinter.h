//
//  AWFWinter.h
//  Aeris
//
//  Created by Nicholas Shipes on 4/5/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFSnowDepth.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `AWFSnowDepths` provides conveninece methods for interacting with the
 [`winter/snowdepth` endpoint](http://www.aerisweather.com/support/docs/api/reference/endpoints/winter/snowdepth) of the Aeris API. All requests will return
 instances of `AWFSnowDepth` that will be populated with the data returned from the API unless otherwise indicated.
 */
@interface AWFSnowDepths : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
