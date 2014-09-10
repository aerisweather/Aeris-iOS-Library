//
//  AFAdvisoriesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

/**
 *  `AWFAdvisoriesLoader` provides convenience methods for interacting with the
 *  [`advisories` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/advisories) of the Aeris API. All requests will
 *  return instances of `AWFAdvisory` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFAdvisoriesLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests currently active advisories for the specified place.
 *
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getAdvisoriesForPlace:(AWFPlace *)place
                      options:(AWFRequestOptions *)options
                   completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end