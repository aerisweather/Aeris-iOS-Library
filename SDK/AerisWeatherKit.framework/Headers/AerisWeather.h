//
//  AerisWeather.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 1/27/17.
//  Copyright © 2017 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const AerisWeatherDidFinishStartup;

@class AWFAerisAccount;

/**
 The `AerisWeather` object is a singleton class instance that sets up and manages the account requirements that are needed before the SDK can interact
 with the Aeris APIs. Before you can perform any data requests using the SDK you must first initialize the SDK with your Aeris account using your unique
 account credentials:
 
 `[AerisWeather startWithApiKey:@"__API_KEY__" secret:@"__SECRET_KEY__"];`
 */
@interface AerisWeather : NSObject

/**
 The Aeris account currently associated with the SDK session.
 */
@property (nonatomic, readonly, nullable) AWFAerisAccount *account;

/**
 The API key associated with the active Aeris account.
 */
@property (nonatomic, readonly, nullable) NSString *apiKey;

/**
 The API secret key associated with the active Aeris account.
 */
@property (nonatomic, readonly, nullable) NSString *secretKey;

/**
 The unique bundle identifier for the current application.
 */
@property (nonatomic, readonly, nullable) NSString *appIdentifer;

/**
 The version number for the current application.
 */
@property (nonatomic, readonly, nullable) NSString *appVersion;

/**
 A Boolean value indicating whether or not the SDK is in debug mode. If `YES`, then more debug information will be output to the debug console during
 testing. The default is `NO`.
 */
@property (nonatomic, assign) BOOL debugMode;

/**
 The current version of the SDK.
 */
@property (nonatomic, readonly) NSString *version;

/**
 Initializes the SDK for the Aeris account associated with the specified API key and secret.

 @param apiKey The account's API key
 @param secretKey The account's API secret key
 */
+ (void)startWithApiKey:(NSString *)apiKey secret:(NSString *)secretKey;

/**
 Returns the server path to use for all API requests.
 */
+ (NSString *)apiServerPath;

/**
 Sets the server path to use for all data API requests.
 
 You shouldn't need to set this value unless you are using your own CDN in front of all Aeris data API requests. Setting this value to `nil` will use the default
 server path for all data API requests. This value must contain the protocol and host for the server:
 
 `[AerisEngine setApiServerPath:@"https://cdn.mydomain.com"];`
 
 @param serverPath The custom server path to use for data API requests
 */
+ (void)setApiServerPath:(nullable NSString *)serverPath;

/**
 Returns the server path to use for all map API requests.
 */
+ (NSString *)ampServerPath;

/**
 Sets the server path to use for all map API requests.
 
 You shouldn't need to set this value unless you are using your own CDN in front of all Aeris Maps API requests. Setting this value to `nil` will use the default
 server path for all map API requests. This value must contain the protocol and host for the server:
 
 `[AerisEngine setAmpServerPath:@"https://cdn.mydomain.com"];`
 
 @param serverPath The custom server path to use for map API requests
 */
+ (void)setAmpServerPath:(nullable NSString *)serverPath;

/**
 Returns the Aeris Weather singleton instance.
 */
+ (instancetype)sharedInstance;

/**
 Returns a Boolean value indicating whether the SDK has been initialized with a valid Aeris account and all account permissions have been setup.
 */
+ (BOOL)isReady;

+ (void)validateAccessKeys;

- (NSString *)urlPathByAddingAccessKeys:(NSString *)urlPath;
- (NSDictionary *)parametersByAddingAccessKeys:(NSDictionary *)params;

- (instancetype)init __attribute__((unavailable("Use +startWithApiKey:secret: instead.")));
- (instancetype)new __attribute__((unavailable("Use +startWithApiKey:secret: instead.")));

@end

NS_ASSUME_NONNULL_END
