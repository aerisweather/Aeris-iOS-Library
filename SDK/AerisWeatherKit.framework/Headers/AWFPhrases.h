//
//  AWFPhrases.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/12/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFPhrase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `AWFPhrases` provides convenience methods for interacting with the 
 [`phrases` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/phrases) of the
 Aeris API. In most cases, all requests will return instances of `AWFPhrase` that will be populated by the data returned by the API unless
 otherwise indicated.
 */
@interface AWFPhrases : AWFWeatherEndpoint
@end

@interface AWFOutlookPhrases : AWFWeatherEndpoint
@end

@interface AWFForecastPhrases : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
