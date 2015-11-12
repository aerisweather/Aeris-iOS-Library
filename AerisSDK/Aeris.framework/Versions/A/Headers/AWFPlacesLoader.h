//
//  AWFPlacesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFPlaceFilterAirport;
extern NSString * const AWFPlaceFilterAmusement;
extern NSString * const AWFPlaceFilterBridge;
extern NSString * const AWFPlaceFilterCamp;
extern NSString * const AWFPlaceFilterChurch;
extern NSString * const AWFPlaceFilterCounty;
extern NSString * const AWFPlaceFilterDivision;
extern NSString * const AWFPlaceFilterFeature;
extern NSString * const AWFPlaceFilterFort;
extern NSString * const AWFPlaceFilterGolf;
extern NSString * const AWFPlaceFilterLake;
extern NSString * const AWFPlaceFilterNeighborhood;
extern NSString * const AWFPlaceFilterParish;
extern NSString * const AWFPlaceFilterPark;
extern NSString * const AWFPlaceFilterPOI;
extern NSString * const AWFPlaceFilterPort;
extern NSString * const AWFPlaceFilterPopulatedPlace;
extern NSString * const AWFPlaceFilterReserve;
extern NSString * const AWFPlaceFilterSchool;
extern NSString * const AWFPlaceFilterStadium;
extern NSString * const AWFPlaceFilterTemple;
extern NSString * const AWFPlaceFilterTrail;
extern NSString * const AWFPlaceFilterTunnel;
extern NSString * const AWFPlaceFilterUniversity;
extern NSString * const AWFPlaceFilterWorship;

extern NSString * const AWFPlaceFieldName;
extern NSString * const AWFPlaceFieldAltName;
extern NSString * const AWFPlaceFieldState;
extern NSString * const AWFPlaceFieldCountry;
extern NSString * const AWFPlaceFieldPopulation;

/**
 *  `AWFPlacesLoader` provides convenience methods for interacting with the
 *  [`places` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/places) of the
 *  Aeris API. In most cases, all requests will return instances of `AWFPlace` that will be populated by the data returned by the API unless
 *  otherwise indicated.
 */
@interface AWFPlacesLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests a location's complete profile data using a specified place.
 *
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 *		arguments: an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getPlace:(AWFPlace *)place
         options:(AWFRequestOptions *)options
      completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Searches for a location using a valid zip code string, which can be US (@"98109") or Canadian (@"").
 *
 *  @param zipcode         The zip code string to search for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 *		arguments: an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)searchForPlaceWithZipcode:(NSString *)zipcode
                          options:(AWFRequestOptions *)options
                       completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Searches for a location by city name, state and country. The state value is optional, use `nil` for locations that do
 *	not contain a state.
 *
 *  @param name            The city name to search for.
 *  @param state           The two-letter abbreviation for the state or province to be used for the search (optional).
 *  @param country         The two-letter abbreviation for the country to be used for the search.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 *		arguments: an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)searchForPlaceWithName:(NSString *)name
                         state:(NSString *)state
                       country:(NSString *)country
                       options:(AWFRequestOptions *)options
                    completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Searches for a location by matching the beginning of a city's name with the specified search string.
 *
 *  @param startsWith      The string that the returned location(s) must begin with.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 *		arguments: an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)searchForPlaceWithNameStartingWith:(NSString *)startsWith
                                   options:(AWFRequestOptions *)options
                                completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end