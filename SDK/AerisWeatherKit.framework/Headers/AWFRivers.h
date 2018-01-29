//
//  AWFRivers.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 10/25/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFRiver.h>
#import <AerisWeatherKit/AWFRiverGauge.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `AWFRivers` provides access for interacting with the [`rivers` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/rivers)
 of the Aeris API. All requests will return instances of `AWFRiver` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFRivers : AWFWeatherEndpoint
@end

/**
 `AWFRiversGauges` provides access for interacting with the [`rivers/gauges` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/rivers/gauges)
 of the Aeris API. All requests will return instances of `AWFRiverGauge` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFRiversGauges : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
