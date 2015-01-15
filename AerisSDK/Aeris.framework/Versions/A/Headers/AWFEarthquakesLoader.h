//
//  AFEarthquakesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

/**
 *  Earthquakes with a magnitude of less than 3.0.
 */
extern NSString *const AerisAPIFilterEarthquakesMini;

/**
 *  Earthquakes with a magnitude from 3.0 to 3.9.
 */
extern NSString *const AerisAPIFilterEarthquakesMinor;

/**
 *  Earthquakes with a magnitude from 4.0 to 4.9.
 */
extern NSString *const AerisAPIFilterEarthquakesLight;

/**
 *  Earthquakes with a magnitude from 5.0 to 5.9.
 */
extern NSString *const AerisAPIFilterEarthquakesModerate;

/**
 *  Earthquakes with a magnitude from 6.0 to 6.9.
 */
extern NSString *const AerisAPIFilterEarthquakesStrong;

/**
 *  Earthquakes with a magnitude from 7.0 to 7.9.
 */
extern NSString *const AerisAPIFilterEarthquakesMajor;

/**
 *  Earthquakes with a magnitude of 8.0 or greater.
 */
extern NSString *const AerisAPIFilterEarthquakesGreat;

/**
 *  Earthquakes with a depth of less than 70km.
 */
extern NSString *const AerisAPIFilterEarthquakesShallow;

/**
 *  `AWFEarthquakesLoader` provides convenience methods for interacting with the
 *  [`earthquakes` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/earthquakes) of the Aeris API. All requests will
 *  return instances of `AWFEarthquake` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFEarthquakesLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests data for a specific earthquake based on a earthquake's unique identifier.
 *
 *  @param quakeId         The unique identifier of the earthquake to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getEarthquakeWithId:(NSString *)quakeId
                    options:(AWFRequestOptions *)options
                 completion:(AWFObjectLoaderObjectCompletionBlock)completionBlock;

/**
 *  Requests a list of places affected by an earthquake specified by the earthquake's unique identifer.
 *
 *  The list of places affected by a single earthquake is based on a radius determined by the earthquake's location and magnitude.
 *
 *  @param quakeId         The unique identifier of the earthquake to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getPlacesAffectedByEarthquakeWithId:(NSString *)quakeId
                                    options:(AWFRequestOptions *)options
                                 completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end