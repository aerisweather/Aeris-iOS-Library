//
//  AWFURLSessionManager.h
//  AerisCore
//
//  Created by Nicholas Shipes on 6/9/16.
//  Copyright © 2016 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisCore/AWFURLSessionManagerDelegate.h>
#import <AerisCore/AWFRequest.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const AWFNetworkErrorDomain;

@class AWFRequest;

@interface AWFURLSessionManager : NSObject

@property (readonly, nonatomic, strong) NSURLSession *session;
@property (readonly, nonatomic, strong) AWFURLSessionManagerDelegate *delegate;

@property (nonatomic, assign) BOOL startsRequestsImmediately;

+ (instancetype)sharedManager;

- (instancetype)initWithConfiguration:(NSURLSessionConfiguration *)configuration;
- (instancetype)initWithConfiguration:(NSURLSessionConfiguration *)configuration delegate:(nullable AWFURLSessionManagerDelegate *)delegate;

- (AWFRequest *)requestWithMethod:(AWFRequestMethod)method URLString:(NSString *)URLString parameters:(nullable id)parameters;
- (AWFRequest *)requestWithMethod:(AWFRequestMethod)method URLString:(NSString *)URLString parameters:(nullable id)parameters encoding:(AWFParameterEncoding)encoding headers:(nullable NSDictionary<NSString *, NSString *> *)headers;

- (AWFRequest *)requestWithURLRequest:(NSURLRequest *)URLRequest parameters:(nullable id)parameters;
- (AWFRequest *)requestWithURLRequest:(NSURLRequest *)URLRequest parameters:(nullable id)parameters encoding:(AWFParameterEncoding)encoding;

@end

NS_ASSUME_NONNULL_END
