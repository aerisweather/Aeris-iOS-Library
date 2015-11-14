//
//  AFNormalsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFNormalFilterDaily;
extern NSString * const AWFNormalFilterMonthly;
extern NSString * const AWFNormalFilterYearly;
extern NSString * const AWFNormalFilterHasTemp;
extern NSString * const AWFNormalFilterHasPrecip;
extern NSString * const AWFNormalFilterHasSnow;

extern NSString * const AWFNormalFieldStationId;
extern NSString * const AWFNormalFieldName;
extern NSString * const AWFNormalFieldState;
extern NSString * const AWFNormalFieldCountry;
extern NSString * const AWFNormalFieldMonth;
extern NSString * const AWFNormalFieldDay;
extern NSString * const AWFNormalFieldMonthDay;
extern NSString * const AWFNormalFieldMaxTemp;
extern NSString * const AWFNormalFieldMinTemp;
extern NSString * const AWFNormalFieldAverageTemp;
extern NSString * const AWFNormalFieldHeatingDegreeDays;
extern NSString * const AWFNormalFieldCoolingDegreeDays;
extern NSString * const AWFNormalFieldMonthlyPrecip;
extern NSString * const AWFNormalFieldYearlyPrecip;
extern NSString * const AWFNormalFieldMonthlySnow;
extern NSString * const AWFNormalFieldYearlySnow;

@class AWFNormalStation;

/**
 *  `AWFNormalsLoader` provides convenience methods for interacting with the
 *  [`normals` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/normals) of the Aeris API. All requests will
 *  return instances of `AWFNormal` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFNormalsLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests climate normals for the specified place.
 *
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getNormalsForPlace:(AWFPlace *)place
                   options:(AWFRequestOptions *)options
                completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests climate normals for a specific station.
 *
 *  @param station         The station to request data for. This station's unique identifier will be used when performing the request.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getNormalsForStation:(AWFNormalStation *)station
                     options:(AWFRequestOptions *)options
                  completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests climate normals for a specific station by its unique station identifier.
 *
 *  @param stationId       The unique station identifier to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getNormalsForStationWithId:(NSString *)stationId
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
 *  @warning Objects returned to the completion block upon a successful request will be instances of `AWFNormalStation`, not `AWFNormal`.
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
 *  @warning Objects returned to the completion block upon a successful request will be instances of `AWFNormalStation`, not `AWFNormal`.
 */
- (void)getStationsClosestToPlace:(AWFPlace *)place
                          options:(AWFRequestOptions *)options
                       completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end