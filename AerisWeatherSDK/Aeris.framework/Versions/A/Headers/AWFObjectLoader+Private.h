//
//  AFObjectLoader+Private.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFObjectLoader.h"
#import "AWFObject.h"

dispatch_queue_t backgroundQueue;

@interface AWFObjectLoader ()

@property (nonatomic, strong) NSMutableArray *currentOperations;
@property (nonatomic, assign) BOOL isLoading;
@property (nonatomic, assign) BOOL hasLoaded;
@property (nonatomic, assign) BOOL allowDebugOutput;
@property (nonatomic, strong) NSOperationQueue *processOperationQueue;

- (void)validateConnector;
- (void)getObjectsForResource:(NSString *)resource
              intoObjectClass:(Class)className
                      options:(NSDictionary *)options
                   completion:(AWFObjectLoaderCompletionBlock)completionBlock;

- (void)getObjectWithId:(NSString *)objectId
           fromResource:(NSString *)resource
                options:(NSDictionary *)options
             completion:(AWFObjectLoaderObjectCompletionBlock)completionBlock;

// error handling and forwarding
- (NSError *)errorForFailedResponse:(NSDictionary *)errorDict;
- (NSError *)errorFromAPIError:(NSError *)apiError;
- (void)handleInvalidPlaceWithCompletion:(AWFObjectLoaderCompletionBlock)completionBlock;
- (void)notifyLoadingHasStarted;
- (void)notifyRequestFailedWithError:(NSError *)error completion:(AWFObjectLoaderCompletionBlock)completionBlock;

- (NSDictionary *)prepareRequestOptions:(NSDictionary *)options;

- (void)cleanup:(NSOperation *)operation;

@end