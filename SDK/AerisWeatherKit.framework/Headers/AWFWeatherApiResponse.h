//
//  AWFResponse.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/4/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisCore/AerisCore.h>

/**
 `AWFWeatherApiResponse` is a subclass of `AWFApiResponse` that is responsible for receiving a response from an Aeris Weather API request and determining
 whether or not the request was successful along with any warnings or errors that occurred.
 */
@interface AWFWeatherApiResponse : AWFApiResponse

@end
