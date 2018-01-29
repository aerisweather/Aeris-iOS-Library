//
//  AWFApiClient.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisCore/AWFApiClient.h>
#import <AerisWeatherKit/AWFWeatherApiResponse.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const AWFApiPathPrefix;

typedef NSString *AWFWeatherRequestAction NS_TYPED_EXTENSIBLE_ENUM;

/**
 The *closest* action of the API.
 */
extern AWFWeatherRequestAction const AWFWeatherRequestActionClosest;

/**
 The *within* action of the API.
 */
extern AWFWeatherRequestAction const AWFWeatherRequestActionWithin;

/**
 The *search* action of the API.
 */
extern AWFWeatherRequestAction const AWFWeatherRequestActionSearch;

/**
 The *affects* action of the API.
 */
extern AWFWeatherRequestAction const AWFWeatherRequestActionAffects;

/**
 The *contains* action of the API.
 */
extern AWFWeatherRequestAction const AWFWeatherRequestActionContains;


typedef NSString *AWFWeatherParamKey NS_TYPED_EXTENSIBLE_ENUM;
extern AWFWeatherParamKey const AWFWeatherParamKeyClientKey;
extern AWFWeatherParamKey const AWFWeatherParamKeyClientSecret;
extern AWFWeatherParamKey const AWFWeatherParamKeyPlace;
extern AWFWeatherParamKey const AWFWeatherParamKeyFilter;
extern AWFWeatherParamKey const AWFWeatherParamKeyFields;
extern AWFWeatherParamKey const AWFWeatherParamKeyRadius;
extern AWFWeatherParamKey const AWFWeatherParamKeyQuery;
extern AWFWeatherParamKey const AWFWeatherParamKeyLimit;
extern AWFWeatherParamKey const AWFWeatherParamKeySkip;
extern AWFWeatherParamKey const AWFWeatherParamKeySort;
extern AWFWeatherParamKey const AWFWeatherParamKeyDateFrom;
extern AWFWeatherParamKey const AWFWeatherParamKeyDateTo;
extern AWFWeatherParamKey const AWFWeatherParamKeyObject;
extern AWFWeatherParamKey const AWFWeatherParamKeyPeriodLimit;
extern AWFWeatherParamKey const AWFWeatherParamKeyPeriodSkip;
extern AWFWeatherParamKey const AWFWeatherParamKeyPeriodSort;
extern AWFWeatherParamKey const AWFWeatherParamKeyFormat;
extern AWFWeatherParamKey const AWFWeatherParamKeyRequests;

typedef NSString *AWFWeatherOutputFormat NS_TYPED_EXTENSIBLE_ENUM;
extern AWFWeatherOutputFormat const AWFWeatherOutputFormatDefault;
extern AWFWeatherOutputFormat const AWFWeatherOutputFormatGeoJSON;

typedef NSString *AWFWeatherResponseKey NS_TYPED_EXTENSIBLE_ENUM;
extern AWFWeatherResponseKey const AWFWeatherResponseKeySuccess;
extern AWFWeatherResponseKey const AWFWeatherResponseKeyError;
extern AWFWeatherResponseKey const AWFWeatherResponseKeyErrorCode;
extern AWFWeatherResponseKey const AWFWeatherResponseKeyErrorDescription;
extern AWFWeatherResponseKey const AWFWeatherResponseKeyResponse;
extern AWFWeatherResponseKey const AWFWeatherResponseKeyRequest;
extern AWFWeatherResponseKey const AWFWeatherResponseKeyBatchResponse;

/* Default format strings for date and time objects returned from API */
extern NSString * const AWFWeatherValidTimeFormatString;
extern NSString * const AWFWeatherValidTimeWithOffsetString;

extern NSString * const AWFWeatherErrorDomain;

/* Error Codes */
typedef NSUInteger AWFWeatherErrorCode NS_TYPED_EXTENSIBLE_ENUM;
extern AWFWeatherErrorCode const AWFWeatherErrorCodeInvalidClient;
extern AWFWeatherErrorCode const AWFWeatherErrorCodeInsufficientScope;
extern AWFWeatherErrorCode const AWFWeatherErrorCodeUnauthorizedNamespace;
extern AWFWeatherErrorCode const AWFWeatherErrorCodeInvalidPlace;
extern AWFWeatherErrorCode const AWFWeatherErrorCodeInvalidCoordinateBounds;
extern AWFWeatherErrorCode const AWFWeatherErrorCodeInvalidId;
extern AWFWeatherErrorCode const AWFWeatherErrorCodeInvalidPolygon;
extern AWFWeatherErrorCode const AWFWeatherErrorCodeInvalidRequest;
extern AWFWeatherErrorCode const AWFWeatherErrorCodeInvalidResponse;
extern AWFWeatherErrorCode const AWFWeatherErrorCodeObjectNotExists;

typedef void (^AWFRequestCompletionBlock)(NSURLSessionDataTask *operation, AWFWeatherApiResponse * _Nullable response, NSError * _Nullable error);

/**
 `AWFWeatherApiClient` is a subclass of `AWFApiClient` that interacts with the Aeris Weather API.
 
 This class is not intended to be used directly but instead used by subclasses of `AWFWeatherEndpoint` to perform requests for data on specific endpoints of 
 the API and transform them into the appropriate `AWFWeatherObject` model instances.
 @see AWFWeatherEndpoint
 */
@interface AWFWeatherApiClient : AWFApiClient

/**
 Returns the currently configured Aeris Weather API server path.
 */
+ (NSString *)apiServerPath;

/**
 Returns the currently configured Aeris Maps Platform (AMP) server path.
 */
+ (NSString *)ampServerPath;

@end

NS_ASSUME_NONNULL_END
