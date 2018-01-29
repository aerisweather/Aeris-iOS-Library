//
//  AWFApiResponse.h
//  AerisApiLibrary
//
//  Created by Nicholas Shipes on 3/24/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/* Response keys */
extern NSString * const AWFApiResponseKeySuccess;
extern NSString * const AWFApiResponseKeyError;
extern NSString * const AWFApiResponseKeyErrorCode;
extern NSString * const AWFApiResponseKeyErrorDescription;
extern NSString * const AWFApiResponseKeyResponse;
extern NSString * const AWFApiResponseKeyRequest;
extern NSString * const AWFApiResponseKeyBatchResponse;

extern NSString * const AWFApiErrorDomain;

/* Error Codes */
extern NSUInteger const AWFApiErrorCodeInvalidResponse;
extern NSUInteger const AWFApiErrorCodeInvalidClient;
extern NSUInteger const AWFApiErrorCodeInsufficientScope;
extern NSUInteger const AWFApiErrorCodeUnauthorizedNamespace;
extern NSUInteger const AWFApiErrorCodeInvalidPlace;
extern NSUInteger const AWFApiErrorCodeInvalidCoordinateBounds;
extern NSUInteger const AWFApiErrorCodeInvalidPolygon;
extern NSUInteger const AWFApiErrorCodeObjectNotExists;

@interface AWFApiResponse : NSObject

/**
 *  The response object returned by the API.
 */
@property (nonatomic, strong) id response;

/**
 *  The error returned by the API.
 */
@property (nonatomic, strong) NSError *error;

/**
 *  Whether the API request was successful and an error did not occur.
 */
@property (readonly, nonatomic) BOOL isSuccessful;

/**
 *  Creates and returns a new `AWFResponse` instance initialized with the specified dictionary object. The provided dictionary should be the JSON object
 *  returned from the API request.
 *
 *  @param dictionary The dictionary object to use with the response
 *
 *  @return The initialized response instance
 */
- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end
