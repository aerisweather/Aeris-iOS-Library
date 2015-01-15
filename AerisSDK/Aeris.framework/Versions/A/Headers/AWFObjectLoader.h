//
//  AFObjectLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGlobals.h>

@class AerisAPIClient, AWFObject, AWFObjectLoader, AWFRequestOptions, AWFPlace;
@protocol AFObjectLoaderDelegate;

typedef void (^AFObjectLoaderSuccessBlock)(AWFObjectLoader *loader, NSArray *objects);
typedef void (^AFObjectLoaderObjectSuccessBlock)(AWFObjectLoader *loader, AWFObject *object);
typedef void (^AFObjectLoaderFailureBlock)(AWFObjectLoader *loader, NSError *error);

typedef void (^AWFObjectLoaderCompletionBlock)(NSArray *objects, NSError *error);
typedef void (^AWFObjectLoaderObjectCompletionBlock)(AWFObject *object, NSError *error);

/**
 *  `AWFObjectLoader` is a concrete class that is responsible for handling all requests, data parsing, and object mapping for
 *  a specific API endpoint. This class should not be used as is, but rather should be subclassed to provided the required configuration
 *  for interacting with the API.
 */
@interface AWFObjectLoader : NSObject <NSCopying>

/**
 *  The endpoint used for all data requests.
 */
@property (nonatomic, readonly) NSString *endpoint;
@property (nonatomic, readonly) NSString *recordEndpoint;

/**
 *  The default request options used for all requests.
 */
@property (nonatomic, strong) AWFRequestOptions *options;

/**
 *  The model object class used when parsing requests into the associated objects.
 */
@property (nonatomic, readonly) Class objectClass;

/**
 *  The duration, in seconds, before the data loaded with this loader expires.
 */
@property (nonatomic, readonly) NSTimeInterval expires;

/**
 *  A Boolean value indicating if the object loader is currently requesting data.
 */
@property (nonatomic, readonly) BOOL isLoading;

/**
 *  A Boolean value indicating if the object loader has already loaded data at least once.
 */
@property (nonatomic, readonly) BOOL hasLoaded;

/**
 *  The receiver's delegate.
 *
 *	An object loader sends messages to its delegate when requests have either completed successfully or failed.
 *
 *  @deprecated As of version 2.0. Use execution blocks instead.
 */
@property (nonatomic, weak) NSObject <AFObjectLoaderDelegate> *delegate;


/**
 *  Initializes and returns an object loader instance.
 *
 *  If an `options` value is provided, it will be stored with the object loader and used as the default for all requests.
 *
 *  @param options An `AWFRequestOptions` instance containing additional parameters to be used as the default set of options for each
 *		request (optional).
 *
 *  @return The initialized object loader instance.
 */
- (instancetype)initWithOptions:(AWFRequestOptions *)options;

/**
 *  The API client used for all requests.
 */
- (AerisAPIClient *)sharedClient;

/**
 *  Requests all objects for the related endpoint. If additional options are provided, then the request will be filtered by those options.
 *
 *  Note: If no objects were returned from the request, but the request did not contain any errors, then the `completionBlock` block will still
 *  be executed without errors. Your block handler should verify the total number of objects returned before trying to access them.
 *
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional)
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *      the array of `AWFObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getWithOptions:(AWFRequestOptions *)options completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests all objects for the related endpoint using the specified expiration age for the request. If additional options are provided, then the request 
 *  will be filtered by those options.
 *
 *  Note: If no objects were returned from the request, but the request did not contain any errors, then the `completionBlock` block will still
 *  be executed without errors. Your block handler should verify the total number of objects returned before trying to access them.
 *
 *  @param options            An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional)
 *  @param expirationInterval The maximum age allowed to use previously cached data for the request. If the data is older than this value, new remote data will be requested.
 *  @param completionBlock    The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *      the array of `AWFObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getWithOptions:(AWFRequestOptions *)options expirationInterval:(NSTimeInterval)expirationInterval completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests data for the provided object. The object's unique identifier will be used in the actual request.
 *
 *  This method is often used to update a previously loaded object that may have changed on the server, or to request additional data
 *  from a related endpoint using the same identifier.
 *
 *  @param object          The object to request
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional)
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *      the array of `AWFObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getObject:(AWFObject *)object withOptions:(AWFRequestOptions *)options completion:(AWFObjectLoaderObjectCompletionBlock)completionBlock;

/**
 *  Requests data for the provided object using the specified expiration age for the request. The object's unique identifier will be used in the actual request.
 *
 *  This method is often used to update a previously loaded object that may have changed on the server, or to request additional data
 *  from a related endpoint using the same identifier.
 *
 *  @param object             The object to request
 *  @param options            An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional)
 *  @param expirationInterval The maximum age allowed to use previously cached data for the request. If the data is older than this value, new remote data will be requested.
 *  @param completionBlock    The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *      the array of `AWFObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getObject:(AWFObject *)object withOptions:(AWFRequestOptions *)options expirationInterval:(NSTimeInterval)expirationInterval completion:(AWFObjectLoaderObjectCompletionBlock)completionBlock;

/**
 *  Requests data for a specific object based on that object's unique identifier.
 *
 *  Note: If no objects were returned from the request, but the request did not contain any errors, then the `completionBlock` block will still
 *  be executed without errors. Your block handler should verify the total number of objects returned before trying to access them.
 *
 *  @param objectId        The identifier of the object to request.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional)
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *      the array of `AWFObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getObjectWithId:(NSString *)objectId withOptions:(AWFRequestOptions *)options completion:(AWFObjectLoaderObjectCompletionBlock)completionBlock;

/**
 *  Requests data for a specific object based on that unique identifier and expiration interval.
 *
 *  @param objectId           The identifier of the object to request.
 *  @param options            An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional)
 *  @param expirationInterval The maximum age allowed to use previously cached data for the request. If the data is older than this value, new remote data will be requested.
 *  @param completionBlock    The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *      the array of `AWFObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getObjectWithId:(NSString *)objectId withOptions:(AWFRequestOptions *)options expirationInterval:(NSTimeInterval)expirationInterval completion:(AWFObjectLoaderObjectCompletionBlock)completionBlock;

/**
 *  Requests data based on a specific search query and request options. This method requires a valid `query` value on the provided
 *  options instance.
 *
 *  Note: If no objects were returned from the request, but the request did not contain any errors, then the `completionBlock` block will still
 *  be executed without errors. Your block handler should verify the total number of objects returned before trying to access them.
 *
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional)
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *      the array of `AWFObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)searchWithOptions:(AWFRequestOptions *)options completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Cancels any active request operations that have not yet completed.
 */
- (void)cancel;

/**
 *  Cancels any active requests and restores the loader back to its original state before any data was requested.
 */
- (void)reset;

/**
 *  Returns the `AWFObject` subclass to use for a specific data type, or subendpoint, under this loader.
 *
 *  This is used specifically with the `dataType` property on an object loader's `AWFRequestOptions` object if you need the loader to use a subendpoint 
 *  supported by its primary API endpoint.
 *
 *  @param dataType The data type key to return the object class for
 */
- (Class)objectClassForDataType:(NSString *)dataType;

//-----------------------------------------------------------------------------
// @name Deprecated Methods
//-----------------------------------------------------------------------------

/**
 *  Requests data based on the provided search options.
 *  Using this method requires you to at least provide a value for the `query` parameter in your options.
 *
 *  @param options An optional dictionary containing additional parameters to be used with the request.
 *  @deprecated    As of version 2.0, replaced by {@link #searchWithOptions:success:failure:}
 */
- (void)requestWithSearchOptions:(NSDictionary *)options AWF_DEPRECATED("Deprecated as of 2.0.0, use searchWithOptions:success:failure: instead.");

@end

@protocol AFObjectLoaderDelegate

/**
 * Called when the loader successfully loaded and processed the requested object.
 */
- (void)objectLoader:(AWFObjectLoader *)objectLoader didLoadObjects:(NSArray *)objects;

@optional

/**
 * Called when there was an error loading and/or processing the requested object.
 */
- (void)objectLoader:(AWFObjectLoader *)objectLoader didFailWithError:(NSError *)error;

/**
 * Called when the loader begins its internal request.
 */
- (void)objectLoaderDidStartLoad:(AWFObjectLoader *)objectLoader;

@end;