//
//  AWFApiClient.h
//  AerisApiLibrary
//
//  Created by Nicholas Shipes on 3/24/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <AerisCore/AWFURLSessionManager.h>
#import <AerisCore/AWFRequest.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const AWFApiParamKeyClientKey;
extern NSString * const AWFApiParamKeyClientSecret;

@class AWFRequest, AWFApiResponse, AWFPropertyMapper;

typedef void (^AWFApiRequestCompletionBlock)(AWFApiResponse * _Nullable response);

@interface AWFApiClient : AWFURLSessionManager

@property (readonly, strong, nonatomic, nullable) NSURL *baseURL;
@property (readonly, copy, nonatomic, nullable) NSString *clientID;
@property (readonly, copy, nonatomic, nullable) NSString *clientSecret;
@property (readonly, nonatomic) Class responseClass;
@property (readonly, nonatomic, nullable) AWFPropertyMapper *mapper;

+ (instancetype)sharedClient;
+ (void)configureWithClientID:(NSString *)clientID secret:(NSString *)clientSecret;
+ (NSString *)serverPath;

- (instancetype)initWithBaseURL:(nullable NSURL *)url;
- (instancetype)initWithBaseURL:(nullable NSURL *)url sessionConfiguration:(NSURLSessionConfiguration *)sessionConfiguration;
- (instancetype)initWithBaseURL:(nullable NSURL *)url sessionConfiguration:(NSURLSessionConfiguration *)sessionConfiguration clientID:(nullable NSString *)clientID secret:(nullable NSString *)secret;

- (AWFRequest *)request:(NSString *)URLString method:(AWFRequestMethod)method parameters:(nullable id)parameters completion:(AWFApiRequestCompletionBlock)completionBlock;
- (AWFRequest *)request:(NSString *)URLString method:(AWFRequestMethod)method expirationInterval:(NSTimeInterval)expirationInterval parameters:(nullable id)parameters completion:(AWFApiRequestCompletionBlock)completionBlock;

- (void)setupMappings;

@end

NS_ASSUME_NONNULL_END
