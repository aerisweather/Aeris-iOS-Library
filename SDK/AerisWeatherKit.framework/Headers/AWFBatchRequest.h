//
//  AWFBatchRequest.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/13/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFBatchRequestOptions` object is a subclass of `AWFWeatherRequestOptions` that includes additional parameters necessary when performing batch
 requests to the API.
 */
@interface AWFBatchRequestOptions : AWFWeatherRequestOptions

/**
 The chained endpoint request string for the batch request.
 */
@property (nonatomic, copy) NSString *requestsUrlPath;

@end

@class AWFBatchRequest;

typedef void (^AWFBatchRequestCompletionBlock)(AWFBatchRequest *request, NSError * _Nullable error);

/**
 `AWFBatchLoader` provides convenience methods for combining multiple endpoint requests into a single HTTP request using Aeris API's `batch`
 endpoint. This request allows you to easily add and remove existing specific endpoints before performing a request.
 */
@interface AWFBatchRequest : NSObject

/**
 An array of `AWFWeatherEndpoint` instances currently associated with this batch request.
 */
@property (nullable, nonatomic, strong, readonly) NSArray<AWFWeatherEndpoint *> *endpoints;

/**
 The chained request string used by the `requests` parameter.
 */
@property (nonatomic, readonly) NSString *URLPath;

/**
 Initializes and returns a batch request instance with the specified array of endpoint instances.
 
 @param endpoints The array of endpoint instances to initialize the batch request with.
 @return The initialized batch request instance.
 */
- (instancetype)initWithEndpoints:(nullable NSArray<AWFWeatherEndpoint *> *)endpoints NS_SWIFT_NAME(init(endpoints:));

//-----------------------------------------------------------------------------
// @name Managing Endpoints
//-----------------------------------------------------------------------------

/**
 Adds an endpoint to the batch request.
 
 @param endpoint The endpoint to add
 */
- (void)addEndpoint:(AWFWeatherEndpoint *)endpoint;

/**
 Adds an endpoint to the batch request.
 
 @param endpoint The endpoint to add
 */
- (void)addEndpoint:(AWFWeatherEndpoint *)endpoint options:(nullable AWFWeatherRequestOptions *)options;

/**
 Adds an endpoint to the batch request and assigns a reference key to it.
 
 The reference key is a convenient way to get a reference to a specific endpoint in the batch using `objectLoaderForKey:` or to return all of the
 available objects from a endpoint using `objectsForLoaderWithKey:`.
 
 @param endpoint The endpoint to add
 @param key    The reference key for the endpoint
 */
- (void)addEndpoint:(AWFWeatherEndpoint *)endpoint forKey:(nullable NSString *)key;

/**
 Adds an endpoint to the batch request and assigns a reference key to it.
 
 The reference key is a convenient way to get a reference to a specific endpoint in the batch using `objectLoaderForKey:` or to return all of the
 available objects from a endpoint using `objectsForLoaderWithKey:`.
 
 @param endpoint The endpoint to add
 @param key    The reference key for the endpoint
 */
- (void)addEndpoint:(AWFWeatherEndpoint *)endpoint forKey:(nullable NSString *)key options:(nullable AWFWeatherRequestOptions *)options;

/**
 Adds an endpoint to the batch request with the given endpoint action.
 
 @param endpoint The endpoint to add
 @param action The endpoint action to use with the endpoint
 */
- (void)addEndpoint:(AWFWeatherEndpoint *)endpoint action:(nullable NSString *)action options:(nullable AWFWeatherRequestOptions *)options;

/**
 Adds an endpoint to the batch request with the given endpoint action and reference key.
 
 The reference key is a convenient way to get a reference to a specific endpoint in the batch using `objectLoaderForKey:` or to return all of the
 available objects from a endpoint using `objectsForLoaderWithKey:`.
 
 @param endpoint The endpoint to add
 @param action The endpoint action to use with the endpoint
 @param key    The reference key for the endpoint.
 */
- (void)addEndpoint:(AWFWeatherEndpoint *)endpoint action:(nullable NSString *)action forKey:(nullable NSString *)key options:(nullable AWFWeatherRequestOptions *)options;

/**
 Removes an endpoint from the batch request.
 
 @param endpoint The endpoint to remove
 */
- (void)removeEndpoint:(AWFWeatherEndpoint *)endpoint;

/**
 Removes an endpoint from the batch request associated with the specific reference key.
 
 @param key    The reference key associated with the endpoint to remove
 */
- (void)removeEndpointForKey:(NSString *)key;

/**
 Removes all endpoints from the batch request.
 */
- (void)removeAllEndpoints;

/**
 Updates the `place` option value on all endpoints currently within the batch request.
 
 @param place The place to use for all endpoints
 */
- (void)setPlaceForAllEndpoints:(AWFPlace *)place;

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 Performs the request by combining each internal endpoint's associated enpoint and options into a single batch request.
 
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 	    the batch request that performed the request and the error that occurred during the request, if any.
 */
- (AWFRequest *)getWithOptions:(nullable AWFBatchRequestOptions *)options completion:(AWFBatchRequestCompletionBlock)completionBlock NS_SWIFT_NAME(get(options:completion:));

/**
 Performs the request by combining each internal endpoint's associated endpoint and options into a single batch request. Cached data will be used 
 when available and not older than the specified `expirationInterval`.
 
 @param expirationInterval The maximum age allowed to use previously cached data for the request. If the data is older than this value, new remote data will be requested.
 @param completionBlock    The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 	    the batch request that performed the request and the error that occurred during the request, if any.
 */
- (AWFRequest *)getWithOptions:(nullable AWFBatchRequestOptions *)options expiration:(NSTimeInterval)expirationInterval completion:(AWFBatchRequestCompletionBlock)completionBlock NS_SWIFT_NAME(get(options:expiration:completion:));

//-----------------------------------------------------------------------------
// @name Accessing Results
//-----------------------------------------------------------------------------

/**
 Returns an array of `AWFWeatherObject` instances that were returned with the request for a specific endpoint used with the batch request.
 
 @param endpoint The endpoint to return results for
 @return An array of `AWFWeatherObject` instances for the endpoint, or `nil` if no results were loaded
 */
- (nullable NSArray<AWFWeatherObject *> *)resultsForEndpoint:(AWFWeatherEndpoint *)endpoint;

/**
 Returns all objects loaded from the batch request for the endpoint associated with the specified reference key.
 
 @param key The reference key associated with the endpoint to return available results for
 @return An array of `AWFWeatherObject` instances returned for the endpoint
 */
- (nullable NSArray<AWFWeatherObject *> *)resultsForEndpointWithKey:(NSString *)key;

/**
 Returns the endpoint within the batch associated with the specified reference key.
 
 @param key The reference key associated with the endpoint
 @return The endpoint for the reference key
 */
- (nullable AWFWeatherEndpoint *)endpointForKey:(NSString *)key;

/**
 Returns the url path for the specified endpoint instance by combining the endpoint's path and request options.

 @param endpoint The endpoint to return the url path for
 @param queryString Whether or not the options query string should be included in the url path
 */
- (nullable NSString *)URLPathForEndpoint:(AWFWeatherEndpoint *)endpoint appendQueryString:(BOOL)queryString;

@end

NS_ASSUME_NONNULL_END
