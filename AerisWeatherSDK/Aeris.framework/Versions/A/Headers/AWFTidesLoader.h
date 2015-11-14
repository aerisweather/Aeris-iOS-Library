//
//  AFTidesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFTideFilterHigh;
extern NSString * const AWFTideFilterLow;
extern NSString * const AWFTideFilterHighLow;

extern NSString * const AWFTideFieldStationId;
extern NSString * const AWFTideFieldDateTime;
extern NSString * const AWFTideFieldType;
extern NSString * const AWFTideFieldHeightFT;
extern NSString * const AWFTideFieldHeightM;
extern NSString * const AWFTideFieldCity;
extern NSString * const AWFTideFieldState;
extern NSString * const AWFTideFieldCountry;

@class AWFTideStation;

/**
 *  `AWFTidesLoader` provides convenience methods for interacting with the
 *  [`tides` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/tides) of the Aeris API. All requests will
 *  return instances of `AWFTide` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFTidesLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests tidal data for the specified place.
 *
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getTidesForPlace:(AWFPlace *)place
                 options:(AWFRequestOptions *)options
              completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests tidal data for a specific station.
 *
 *  @param station         The station to request data for. This station's unique identifier will be used when performing the request.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getTidesForStation:(AWFTideStation *)station
                   options:(AWFRequestOptions *)options
                completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests tidal data for a specific station by its unique station identifier.
 *
 *  @param stationId       The unique station identifier to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getTidesForStationWithId:(NSString *)stationId
                         options:(AWFRequestOptions *)options
                      completion:(AWFObjectLoaderCompletionBlock)completionBlock;

//-----------------------------------------------------------------------------
// @name Requesting Stations
//-----------------------------------------------------------------------------

/**
 *  Requests a station and its profile by its unique station identifier.
 *
 *  @param stationId       The unique station identifier to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 *  @warning Objects returned to the completion block upon a successful request will be instances of `AWFTideStation`, not `AWFTide`.
 */
- (void)getStationWithId:(NSString *)stationId
                 options:(AWFRequestOptions *)options
              completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests a list of stations and their profiles closest to the specified place.
 *
 *  @param place           The place to search nearby stations for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 *  @warning Objects returned to the completion block upon a successful request will be instances of `AWFTideStation`, not `AWFTide`.
 */
- (void)getStationsClosestToPlace:(AWFPlace *)place
                          options:(AWFRequestOptions *)options
                       completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end