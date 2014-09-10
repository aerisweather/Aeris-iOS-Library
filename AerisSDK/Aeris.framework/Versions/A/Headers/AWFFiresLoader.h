//
//  AFFiresLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

/**
 *  `AWFFiresLoader` provides convenience methods for interacting with the
 *  [`fires` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/fires) of the Aeris API. All requests will
 *  return instances of `AWFFire` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFFiresLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests a fire based on its unique identifier.
 *
 *  @param fireId          The unique identifier of the fire to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getFireWithId:(NSString *)fireId
              options:(AWFRequestOptions *)options
           completion:(AWFObjectLoaderObjectCompletionBlock)completionBlock;

@end