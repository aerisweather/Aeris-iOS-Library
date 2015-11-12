//
//  AFEarthquakesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFEarthquakeFilterMini;
extern NSString * const AWFEarthquakeFilterMinor;
extern NSString * const AWFEarthquakeFilterLight;
extern NSString * const AWFEarthquakeFilterModerate;
extern NSString * const AWFEarthquakeFilterStrong;
extern NSString * const AWFEarthquakeFilterMajor;
extern NSString * const AWFEarthquakeFilterGreat;
extern NSString * const AWFEarthquakeFilterShallow;

extern NSString * const AWFEarthquakeFieldId;
extern NSString * const AWFEarthquakeFieldDateTime;
extern NSString * const AWFEarthquakeFieldMagnitude;
extern NSString * const AWFEarthquakeFieldDepth;
extern NSString * const AWFEarthquakeFieldName;
extern NSString * const AWFEarthquakeFieldState;
extern NSString * const AWFEarthquakeFieldCountry;
extern NSString * const AWFEarthquakeFieldRegion;

// keep these for backwards compatability with previous versions
extern NSString *const AerisAPIFilterEarthquakesMini;
extern NSString *const AerisAPIFilterEarthquakesMinor;
extern NSString *const AerisAPIFilterEarthquakesLight;
extern NSString *const AerisAPIFilterEarthquakesModerate;
extern NSString *const AerisAPIFilterEarthquakesStrong;
extern NSString *const AerisAPIFilterEarthquakesMajor;
extern NSString *const AerisAPIFilterEarthquakesGreat;
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