//
//  AWFRiversLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/4/17.
//  Copyright © 2017 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * AWFRiverFilterOutOfService;
extern NSString * AWFRiverFilterInService;
extern NSString * AWFRiverFilterObsNotCurrent;
extern NSString * AWFRiverFilterNotDefined;
extern NSString * AWFRiverFilterLowThreshold;
extern NSString * AWFRiverFilterNoFlooding;
extern NSString * AWFRiverFilterAction;
extern NSString * AWFRiverFilterFlood;
extern NSString * AWFRiverFilterMinor;
extern NSString * AWFRiverFilterModerate;
extern NSString * AWFRiverFilterMajor;
extern NSString * AWFRiverFilterAllFlood;
extern NSString * AWFRiverFilterHeightType;
extern NSString * AWFRiverFilterFlowType;

extern NSString * AWFRiverFieldStationId;
extern NSString * AWFRiverFieldDateTime;
extern NSString * AWFRiverFieldStatus;
extern NSString * AWFRiverFieldStatusCode;
extern NSString * AWFRiverFieldHasImpact;
extern NSString * AWFRiverFieldName;
extern NSString * AWFRiverFieldWaterbody;
extern NSString * AWFRiverFieldState;
extern NSString * AWFRiverFieldCountry;

/**
 *  `AWFRiversLoader` provides convenience methods for interacting with the
 *  [`rivers` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/rivers) of the Aeris API. All requests will
 *  return instances of `AWFRiver` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFRiversLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests nearby rivers for the specified place.
 *
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getRiversForPlace:(AWFPlace *)place
				  options:(AWFRequestOptions *)options
			   completion:(AWFObjectLoaderCompletionBlock)completionBlock;

//-----------------------------------------------------------------------------
// @name Requesting Stations
//-----------------------------------------------------------------------------

/**
 *  Requests a river gauge station and its profile by its unique station identifier.
 *
 *  @param stationId       The unique station identifier to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 *  @warning Objects returned to the completion block upon a successful request will be instances of `AWFRiverGauge`, not `AWFRiver`.
 */
- (void)getStationWithId:(NSString *)stationId
				 options:(AWFRequestOptions *)options
			  completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests a list of river gauge stations and their profiles closest to the specified place.
 *
 *  @param place           The place to search nearby stations for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 *  @warning Objects returned to the completion block upon a successful request will be instances of `AWFRiverGauge`, not `AWFRiver`.
 */
- (void)getStationsClosestToPlace:(AWFPlace *)place
						  options:(AWFRequestOptions *)options
					   completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end
