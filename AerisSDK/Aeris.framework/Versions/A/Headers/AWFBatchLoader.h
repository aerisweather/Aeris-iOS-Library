//
//  AWFBatchLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Aeris/AWFObjectLoader.h>

@class AWFBatchLoader;

typedef void (^AWFBatchLoaderCompletionBlock)(AWFBatchLoader *loader, NSError *error);

/**
 *  `AWFBatchLoader` provides convenience methods for combining multiple object loader requests into a single HTTP request using Aeris API's `batch`
 *  endpoint. This loader allows you to easily add and remove existing specific object loaders before performing a request.
 */
@interface AWFBatchLoader : AWFObjectLoader

/**
 *  An array of object loader instances currently associated with this batch loader.
 */
@property (readonly, nonatomic, strong) NSArray *loaders;

/**
 *  Initializes and returns a batch loader object with the specified array of object loader instances.
 *
 *  @param loaders The array of object loader instances to initialize the batch loader with.
 *
 *  @return The initialized batch loader instance.
 */
- (instancetype)initWithLoaders:(NSArray *)loaders;

//-----------------------------------------------------------------------------
// @name Managing Object Loaders
//-----------------------------------------------------------------------------

/**
 *  Adds an object loader to the batch.
 *
 *  @param loader The object loader to add. This cannot be another batch loader instance.
 */
- (void)addLoader:(AWFObjectLoader *)loader;

/**
 *  Adds an object loader to the batch and assigns a reference key to it.
 *
 *  The reference key is a convenient way to get a reference to a specific object loader in the batch using `objectLoaderForKey:` or to return all of the
 *  available objects from a loader using `objectsForLoaderWithKey:`.
 *
 *  @param loader The object loader to add. This cannot be another batch loader instance.
 *  @param key    The reference key for the loader
 */
- (void)addLoader:(AWFObjectLoader *)loader forKey:(NSString *)key;

/**
 *  Adds an object loader to the batch with the given endpoint action.
 *
 *  @param loader The object loader to add. This cannot be another batch loader instance.
 *  @param action The endpoint action to use with the loader
 */
- (void)addLoader:(AWFObjectLoader *)loader action:(NSString *)action;

/**
 *  Adds an object loader to the batch with the given endpoint action and reference key.
 *
 *  The reference key is a convenient way to get a reference to a specific object loader in the batch using `objectLoaderForKey:` or to return all of the
 *  available objects from a loader using `objectsForLoaderWithKey:`.
 *
 *  @param loader The object loader to add. This cannot be another batch loader instance.
 *  @param action The endpoint action to use with the loader
 *  @param key    The reference key for the loader.
 */
- (void)addLoader:(AWFObjectLoader *)loader action:(NSString *)action forKey:(NSString *)key;

/**
 *  Removes an object loader from the batch.
 *
 *  @param loader The object loader to remove.
 */
- (void)removeLoader:(AWFObjectLoader *)loader;

/**
 *  Removes an object loader from the batch associated with the specific reference key.
 *
 *  @param key    The reference key associated with the object loader to remove
 */
- (void)removeLoaderForKey:(NSString *)key;

/**
 *  Removes all object loaders from the batch.
 */
- (void)removeAllLoaders;

/**
 *  Updates the `place` option value on all object loaders currently within the batch.
 *
 *  @param place The place to use for all loaders
 */
- (void)setPlaceForAllLoaders:(AWFPlace *)place;

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Performs the request by combining each internal object loader's associated enpoint and options into a single batch request.
 *
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *	    the batch loader that performed the request and the error that occurred during the request, if any.
 */
- (void)getWithCompletionBlock:(AWFBatchLoaderCompletionBlock)completionBlock;

/**
 *  Performs the request by combining each internal object loader's associated endpoint and options into a single batch request. Cached data will be used 
 *  when available and not older than the specified `expirationInterval`.
 *
 *  @param expirationInterval The maximum age allowed to use previously cached data for the request. If the data is older than this value, new remote data will be requested.
 *  @param completionBlock    The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *	    the batch loader that performed the request and the error that occurred during the request, if any.
 */
- (void)getWithExpirationInterval:(NSTimeInterval)expirationInterval completion:(AWFBatchLoaderCompletionBlock)completionBlock;

/**
 *  Returns an array of `AWFObject` instances that were returned with the request for a specific object loader used with the batch request.
 *
 *  @param loader The object loader to return loaded objects for.
 *
 *  @return An array of `AWFObject` instances for the loader, or `nil` if no objects were loaded.
 */
- (NSArray *)objectsForLoader:(AWFObjectLoader *)loader;

/**
 *  Returns all objects loaded from the batch request for the object loader associated with the specified reference key.
 *
 *  @param key The reference key associated with the object loader to return available objects for
 *
 *  @return An array of `AWFObject` instances returned for the object loader
 */
- (NSArray *)objectsForLoaderWithKey:(NSString *)key;

/**
 *  Returns the object loader within the batch associated with the specified reference key.
 *
 *  @param key The reference key associated with the object loader
 *
 *  @return The object loader for the reference key
 */
- (AWFObjectLoader *)objectLoaderForKey:(NSString *)key;

@end