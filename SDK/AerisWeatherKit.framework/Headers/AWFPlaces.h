//
//  AWFPlacesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFPlace.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFPlaceFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterAirport;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterAmusement;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterBridge;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterCamp;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterChurch;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterCounty;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterDivision;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterFeature;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterFort;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterGolf;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterLake;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterNeighborhood;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterParish;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterPark;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterPOI;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterPort;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterPopulatedPlace;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterReserve;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterSchool;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterStadium;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterTemple;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterTrail;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterTunnel;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterUniversity;
FOUNDATION_EXPORT AWFPlaceFilter const AWFPlaceFilterWorship;

typedef NSString * AWFPlaceField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFPlaceField const AWFPlaceFieldName;
FOUNDATION_EXPORT AWFPlaceField const AWFPlaceFieldAltName;
FOUNDATION_EXPORT AWFPlaceField const AWFPlaceFieldState;
FOUNDATION_EXPORT AWFPlaceField const AWFPlaceFieldCountry;
FOUNDATION_EXPORT AWFPlaceField const AWFPlaceFieldPopulation;

/**
 `AWFPlaces` provides convenience methods for interacting with the
 [`places` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/places) of the
 Aeris API. In most cases, all requests will return instances of `AWFPlace` that will be populated by the data returned by the API unless
 otherwise indicated.
 */
@interface AWFPlaces : AWFWeatherEndpoint

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 Requests a location's complete profile data using a specified place.
 
 @param place           The place to request data for.
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 		arguments: an array of associated `AWFWeatherObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getPlace:(AWFPlace *)place
         options:(nullable AWFWeatherRequestOptions *)options
      completion:(AWFWeatherEndpointCompletionBlock)completionBlock;

/**
 Searches for a location using a valid zip code string, which can be US (@"98109") or Canadian (@"").
 
 @param zipcode         The zip code string to search for.
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 		arguments: an array of associated `AWFWeatherObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)searchUsingZipcode:(NSString *)zipcode
				   options:(nullable AWFWeatherRequestOptions *)options
				completion:(AWFWeatherEndpointCompletionBlock)completionBlock;

/**
 Searches for a location by city name, state and country. The state value is optional, use `nil` for locations that do not contain a state.
 
 @param name            The city name to search for.
 @param state           The two-letter abbreviation for the state or province to be used for the search (optional).
 @param country         The two-letter abbreviation for the country to be used for the search.
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 		arguments: an array of associated `AWFWeatherObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)searchUsingName:(NSString *)name
				  state:(nullable NSString *)state
				country:(NSString *)country
				options:(nullable AWFWeatherRequestOptions *)options
			 completion:(AWFWeatherEndpointCompletionBlock)completionBlock;

/**
 Searches for a location by matching the beginning of a city's name with the specified search string.
 
 @param startsWith      The string that the returned location(s) must begin with.
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 		arguments: an array of associated `AWFWeatherObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)searchUsingNameStartingWith:(NSString *)startsWith
							options:(nullable AWFWeatherRequestOptions *)options
						 completion:(AWFWeatherEndpointCompletionBlock)completionBlock;

/**
 Searches for a location using a string, which can be a place name, zip code or latitude/longitude coordinate string.

 @param placeString The string to use for the search request
 @param options An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
	 arguments: an array of associated `AWFWeatherObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)searchUsingString:(NSString *)placeString
				  options:(nullable AWFWeatherRequestOptions *)options
			   completion:(AWFWeatherEndpointCompletionBlock)completionBlock;

@end

@interface AWFAirports : AWFWeatherEndpoint
@end

@interface AWFPostalCodes : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
