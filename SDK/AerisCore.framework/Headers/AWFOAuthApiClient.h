//
//  AWFOAuthApiClient.h
//  AerisApiLibrary
//
//  Created by Nicholas Shipes on 3/24/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <AerisCore/AWFApiClient.h>
#import <AerisCore/AWFOAuthCredential.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const AWFOAuth2ErrorDomain;

extern NSString * const kAWFOAuthCodeGrantType;
extern NSString * const kAWFOAuthClientCredentialsGrantType;
extern NSString * const kAWFOAuthPasswordCredentialsGrantType;
extern NSString * const kAWFOAuthRefreshGrantType;

extern NSString * const AWFResourcePathKey;
extern NSString * const AWFResourceMethodKey;

typedef void (^AWFOAuthCompletionBlock)(AWFOAuthCredential * _Nullable credential,  NSError * _Nullable error);

@interface AWFOAuthApiClient : AWFApiClient

@property (readonly, nonatomic, copy) NSString *serviceProviderIdentifier;
@property (readonly, nonatomic) AWFOAuthCredential *oauthCredential;
@property (readonly, nonatomic) BOOL sendsDataAsHttpBody;
@property (nonatomic, assign) BOOL useHTTPBasicAuthentication;

+ (NSString *)authenticationPath;
+ (NSArray *)publicResources;

///---------------------
/// @name Authenticating
///---------------------

- (NSURLSessionTask *)authenticateUsingOAuthWithURLString:(NSString *)URLString
												 username:(NSString *)username
												 password:(NSString *)password
													scope:(nullable NSString *)scope
												  success:(void (^)(AWFOAuthCredential *credential))success
												  failure:(void (^)(NSError *error))failure;

- (NSURLSessionTask *)authenticateUsingOAuthWithURLString:(NSString *)URLString
													scope:(nullable NSString *)scope
												  success:(void (^)(AWFOAuthCredential *credential))success
												  failure:(void (^)(NSError *error))failure;

- (NSURLSessionTask *)authenticateUsingOAuthWithURLString:(NSString *)URLString
											 refreshToken:(NSString *)refreshToken
												  success:(void (^)(AWFOAuthCredential *credential))success
												  failure:(void (^)(NSError *error))failure;

- (NSURLSessionTask *)authenticateUsingOAuthWithURLString:(NSString *)URLString
													 code:(NSString *)code
											  redirectURI:(NSString *)uri
												  success:(void (^)(AWFOAuthCredential *credential))success
												  failure:(void (^)(NSError *error))failure;

- (NSURLSessionTask *)authenticateUsingOAuthWithURLString:(NSString *)URLString
											   parameters:(NSDictionary *)parameters
												  success:(void (^)(AWFOAuthCredential *credential))success
												  failure:(void (^)(NSError *error))failure;

- (NSURLSessionTask *)authenticateUsingOAuthWithUsername:(NSString *)username password:(NSString *)password completion:(AWFOAuthCompletionBlock)completionBlock;
- (NSURLSessionTask *)refreshAccessTokenWithCompletion:(AWFOAuthCompletionBlock)completionBlock;
- (void)unauthenticateWithCompletion:(AWFOAuthCompletionBlock)completionBlock;
- (BOOL)isAuthenticated;

@end

NS_ASSUME_NONNULL_END
