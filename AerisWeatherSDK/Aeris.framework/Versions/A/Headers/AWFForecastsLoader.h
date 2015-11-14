//
//  AWFForecastsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFForecastFilterDay;
extern NSString * const AWFForecastFilterDayNight;
extern NSString * const AWFForecastFilter1Hour;
extern NSString * const AWFForecastFilter3Hour;
extern NSString * const AWFForecastFilter6Hour;
extern NSString * const AWFForecastFilter12Hour;

/**
 *  `AWFForecastsLoader` provides convenience methods for interacting with the
 *  [`forecasts` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/forecasts) of the Aeris API. All requests will
 *  return instances of `AWFForecast` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFForecastsLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests forecast data for the specified place.
 *
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 *		arguments: an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getForecastForPlace:(AWFPlace *)place
                    options:(AWFRequestOptions *)options
                 completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end