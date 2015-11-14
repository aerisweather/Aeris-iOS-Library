//
//  AWFPhrasesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/12/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

/**
 *  `AWFPhrasesLoader` provides convenience methods for interacting with the 
 *  [`phrases` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/phrases) of the
 *  Aeris API. In most cases, all requests will return instances of `AWFPhrase` that will be populated by the data returned by the API unless
 *  otherwise indicated.
 */
@interface AWFPhrasesLoader : AWFGeographicObjectLoader

/**
 *  Requests the short-term forecast (outlook) phrasing for the specified place.
 *
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 *		arguments: an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getOutlookPhrasingForPlace:(AWFPlace *)place options:(AWFRequestOptions *)options completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests the forecast phrasing for the specified place and date range.
 *
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 *		arguments: an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getForecastPhrasingForPlace:(AWFPlace *)place options:(AWFRequestOptions *)options completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end