//
//  AFStormCellsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFStormCellFilterHail;
extern NSString * const AWFStormCellFilterRotating;
extern NSString * const AWFStormCellFilterTornadic;

extern NSString * const AWFStormCellFieldDateTime;
extern NSString * const AWFStormCellFieldHail;
extern NSString * const AWFStormCellFieldSevereHail;
extern NSString * const AWFStormCellFieldHailSize;
extern NSString * const AWFStormCellFieldTVS;
extern NSString * const AWFStormCellFieldRotation;
extern NSString * const AWFStormCellFieldCity;
extern NSString * const AWFStormCellFieldState;
extern NSString * const AWFStormCellFieldCountry;

/**
 *  `AWFStormCellsLoader` provides convenience methods for interacting with the
 *  [`stormcells` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/stormcells) of the Aeris API. All requests will
 *  return instances of `AWFStormCell` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFStormCellsLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests a storm cell based on its unique identifier.
 *
 *  @param cellId          The unique identifier of the storm cell to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getStormCellWithId:(NSString *)cellId
                   options:(AWFRequestOptions *)options
                completion:(AWFObjectLoaderObjectCompletionBlock)completionBlock;

/**
 *  Requests a list of places affected by a storm specified by the storm cell's unique identifer.
 *
 *  The list of places affected by a single storm cell is based on the cell's forecasted path and narrow cone along that path from its current
 *  position.
 *
 *  @param cellId          The unique identifier of the storm cell to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getPlacesAffectedByStormCellWithId:(NSString *)cellId
                                   options:(AWFRequestOptions *)options
                                completion:(AWFObjectLoaderCompletionBlock)completionBlock;

- (void)getCurrentStormCellSummary:(AWFRequestOptions *)options completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end