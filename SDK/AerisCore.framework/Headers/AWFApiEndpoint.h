//
//  AWFApiEndpoint.h
//  AerisApiLibrary
//
//  Created by Nicholas Shipes on 3/24/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisCore/AWFRequest.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFApiClient, AWFApiObject, AWFApiRequestOptions;

@interface AWFApiEndpointResult<__covariant Value: NSArray<AWFApiObject *> *> : NSObject

@property (nonatomic, strong) Value value;
@property (nonatomic, strong) NSError *error;

+ (instancetype)resultWithValue:(nullable Value)value error:(nullable NSError *)error;

@end


typedef void (^AWFApiEndpointCompletionBlock)(AWFApiEndpointResult *result);
typedef void (^AWFApiEndpointArrayCompletionBlock)(NSArray<AWFApiObject *> *results, NSError *error);
typedef void (^AWFApiEndpointObjectCompletionBlock)(AWFApiObject *result, NSError *error);

@interface AWFApiEndpoint : NSObject

@property (readonly, nonatomic) AWFApiClient *sharedClient;
@property (readonly, nonatomic) NSString *path;
@property (readonly, nonatomic) Class objectClass;

- (instancetype)initWithPath:(NSString *)path objectClass:(Class)objectClass;

- (void)getWithOptions:(nullable id)options completion:(AWFApiEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(options:completion:));
- (void)getWithOptions:(nullable id)options expires:(NSTimeInterval)expirationInterval completion:(AWFApiEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(options:expires:completion:));
- (void)getFromResource:(NSString *)resource options:(nullable id)options completion:(AWFApiEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(resource:options:completion:));
- (void)getFromResource:(NSString *)resource options:(nullable id)options expires:(NSTimeInterval)expirationInterval completion:(AWFApiEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(resource:options:expires:completion:));
- (void)getFromResource:(NSString *)resource options:(nullable id)options mappingClass:(Class)mappingClass completion:(AWFApiEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(resource:options:mappingClass:completion:));
- (void)getFromResource:(NSString *)resource options:(nullable id)options expires:(NSTimeInterval)expirationInterval mappingClass:(Class)mappingClass completion:(AWFApiEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(resource:options:expires:mappingClass:completion:));
- (void)getForId:(id)objectId options:(nullable id)options completion:(AWFApiEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(objectId:options:completion:));

/**
 *  Cancels any active request operations that have not yet completed.
 */
- (void)cancel;

/**
 *  Cancels any active requests and restores the instance back to its original state before any data was requested.
 */
- (void)reset;

- (void)performRequestForResource:(NSString *)resource method:(AWFRequestMethod)httpMethod options:(nullable id)options mappingClass:(Class)mappingClass sourceObject:(nullable id)sourceObject completion:(AWFApiEndpointCompletionBlock)completionBlock;
- (void)performRequestForResource:(NSString *)resource method:(AWFRequestMethod)httpMethod options:(nullable id)options expires:(NSTimeInterval)expires mappingClass:(Class)mappingClass sourceObject:(nullable id)sourceObject completion:(AWFApiEndpointCompletionBlock)completionBlock;
- (NSDictionary *)filterEncodedObject:(NSDictionary *)encodedObject ofClass:(Class)klass forMethod:(AWFRequestMethod)method;

@end

NS_ASSUME_NONNULL_END
