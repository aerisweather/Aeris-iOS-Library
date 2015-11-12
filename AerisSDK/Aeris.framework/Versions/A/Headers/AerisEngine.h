//
//  AerisEngine.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFLog.h>

extern NSString *const AWFEngineIsReady;

/**
 *  The `AerisEngine` object is a singleton class that sets up and manages the initial startup and account access requirements that is used
 *  throughout the entire SDK. Before you can perform any data requests using the SDK, you must first initialize this `AerisEngine` instance
 *  with your account credentials:
 *
 *	`[AerisEngine engineWithKey:@"__ACCOUNT_ID__" secret:@"__CLIENT_SECRET_KEY__"];`
 */
@interface AerisEngine : NSObject

/**
 *  The consumer key (client ID) being used for all API requests.
 */
@property (nonatomic, copy, readonly) NSString *consumerKey;

/**
 *  The consumer secret (client secret) being used for all API requests.
 */
@property (nonatomic, copy, readonly) NSString *consumerSecret;

/**
 *  The bundle name for the current application.
 */
@property (nonatomic, copy, readonly) NSString *consumerAppName;

/**
 *  The version number of the current application.
 */
@property (nonatomic, copy, readonly) NSString *consumerAppVersion;

/**
 *  The account access key being used for AerisGraphics static map accounts.
 */
@property (nonatomic, copy, readonly) NSString *consumerGraphicsKey;

/**
 *  The specific API version being used for all requests. If this value is not set, then the latest stable API version will always be used.
 */
@property (nonatomic, copy, readonly) NSString *apiVersion;

/**
 *  Whether the API engine is using secure HTTPS requests. Default is `NO`. Use `setSecure:` to change this value.
 */
@property (nonatomic, readonly) BOOL secure;

/**
 *  The version of the SDK.
 */
@property (readonly, nonatomic) NSString *sdkVersion;

/**
 *  Initializes the framework API engine with the proper consumer key and secret values for the desired account.
 *
 *  @param consumerKey    The client ID to be used for all requests.
 *  @param consumerSecret The client secret key to be used for all requests.
 */
+ (void)engineWithKey:(NSString *)consumerKey secret:(NSString *)consumerSecret;
+ (void)secureEngineWithKey:(NSString *)consumerKey secret:(NSString *)consumerSecret;

/**
 *  Initializes the framework API engine with the proper consumer key and secret values for the desired account and a specific
 *  version of the API.
 *
 *  @param consumerKey    The client ID to be used for all requests.
 *  @param consumerSecret The client secret key to be used for all requests.
 *  @param version        The version of the API to use for all requests. If not provided, the most recent version will be used.
 */
+ (void)engineWithKey:(NSString *)consumerKey secret:(NSString *)consumerSecret version:(NSString *)version;
+ (void)secureEngineWithKey:(NSString *)consumerKey secret:(NSString *)consumerSecret version:(NSString *)version;

/**
 *	Returns the current AerisEngine singleton instance.
 */
+ (AerisEngine *)currentEngine;

/**
 *  Enables all detailed debug output throughout the SDK. By default, just errors and warnings out output.
 */
+ (void)enableDebug;

/**
 *  Changes the current logging level for the Aeris SDK.
 *
 *  @param level The logging level to use.
 */
+ (void)setLogLevel:(AWFLogLevel)level;

/**
 *  A Boolean value indicating if account information for the specified keys has been loaded and the framework is ready.
 */
+ (BOOL)isEngineReady;

@end