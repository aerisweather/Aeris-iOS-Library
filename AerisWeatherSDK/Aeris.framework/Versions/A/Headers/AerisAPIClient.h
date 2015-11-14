//
//  AerisAPIClient.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AFHTTPRequestOperationManager.h"

#import <Aeris/AWFResponse.h>

extern NSString * const AerisAPIServer;
extern NSString * const AerisAPISecureServer;
extern NSString * const AerisAPIPathPrefix;

extern NSString * const AerisAPIActionClosest;
extern NSString * const AerisAPIActionWithin;
extern NSString * const AerisAPIActionSearch;
extern NSString * const AerisAPIActionAffects;
extern NSString * const AerisAPIActionContains;

extern NSString * const AerisAPIParamKeyClientKey;
extern NSString * const AerisAPIParamKeyClientSecret;
extern NSString * const AerisAPIParamKeyPlace;
extern NSString * const AerisAPIParamKeyFilter;
extern NSString * const AerisAPIParamKeyFields;
extern NSString * const AerisAPIParamKeyRadius;
extern NSString * const AerisAPIParamKeyQuery;
extern NSString * const AerisAPIParamKeyLimit;
extern NSString * const AerisAPIParamKeySkip;
extern NSString * const AerisAPIParamKeySort;
extern NSString * const AerisAPIParamKeyDateFrom;
extern NSString * const AerisAPIParamKeyDateTo;
extern NSString * const AerisAPIParamKeyObject;
extern NSString * const AerisAPIParamKeyPeriodLimit;
extern NSString * const AerisAPIParamKeyPeriodSkip;
extern NSString * const AerisAPIParamKeyPeriodSort;
extern NSString * const AerisAPIParamKeyFormat;

extern NSString * const AerisAPIOutputFormatGeoJSON;

extern NSString * const AerisAPIResponseKeySuccess;
extern NSString * const AerisAPIResponseKeyError;
extern NSString * const AerisAPIResponseKeyErrorCode;
extern NSString * const AerisAPIResponseKeyErrorDescription;
extern NSString * const AerisAPIResponseKeyResponse;
extern NSString * const AerisAPIResponseKeyRequest;
extern NSString * const AerisAPIResponseKeyBatchResponse;

/* Default format strings for date and time objects returned from API */
extern NSString * const AerisAPIValidTimeFormatString;
extern NSString * const AerisAPIValidTimeWithOffsetString;

extern NSString * const AerisAPIErrorDomain;
/* Error Codes */
extern NSUInteger const AerisAPIErrorCodeInvalidResponse;
extern NSUInteger const AerisAPIErrorCodeInvalidClient;
extern NSUInteger const AerisAPIErrorCodeInsufficientScope;
extern NSUInteger const AerisAPIErrorCodeUnauthorizedNamespace;
extern NSUInteger const AerisAPIErrorCodeInvalidPlace;
extern NSUInteger const AerisAPIErrorCodeInvalidCoordinateBounds;
extern NSUInteger const AerisAPIErrorCodeInvalidPolygon;
extern NSUInteger const AerisAPIErrorCodeObjectNotExists;

typedef void (^AWFRequestCompletionBlock)(AFHTTPRequestOperation *operation, AWFResponse *response, NSError *error);

@interface AerisAPIClient : AFHTTPRequestOperationManager

@property (readonly, nonatomic) NSString *serverPath;

+ (instancetype)sharedClient;

- (AFHTTPRequestOperation *)GET:(NSString *)URLString
						expires:(NSTimeInterval)expires
                     parameters:(NSDictionary *)parameters
                        success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                        failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

//- (void)getPath:(NSString *)path
//		expires:(NSTimeInterval)expires
//	 parameters:(NSDictionary *)parameters
//		success:(void (^)(AFHTTPRequestOperation *, id responseObject))success
//		failure:(void (^)(AFHTTPRequestOperation *, NSError *error))failure;

- (AFHTTPRequestOperation *)GET:(NSString *)URLString
						expires:(NSTimeInterval)expires
                     parameters:(NSDictionary *)parameters
					 completion:(AWFRequestCompletionBlock)completionBlock;

- (BOOL)isResponseSuccessful:(id)responseObject;

@end
