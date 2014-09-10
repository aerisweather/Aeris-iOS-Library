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
 *  Removes an object loader from the batch.
 *
 *  @param loader The object loader to remove.
 */
- (void)removeLoader:(AWFObjectLoader *)loader;

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Performs the request by combining each internal object loader's associated enpoint and options into a single batch request.
 *
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		the batch loader that performed the request and the error that occurred during the request, if any.
 */
- (void)getWithCompletionBlock:(AWFBatchLoaderCompletionBlock)completionBlock;

/**
 *  Returns an array of `AWFObject` instances that were returned with the request for a specific object loader used with the batch request.
 *
 *  @param loader The object loader to return loaded objects for.
 *
 *  @return An array of `AWFObject` instances for the loader, or `nil` if no objects were loaded.
 */
- (NSArray *)objectsForLoader:(AWFObjectLoader *)loader;

@end