//
//  AWFAerisAccount.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 1/27/17.
//  Copyright © 2017 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisWeatherKit/AWFApiPermissions.h>
#import <AerisWeatherKit/AWFMapPermissions.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFAerisAccount` object contains the access information associated with an API account.
 */
@interface AWFAerisAccount : NSObject

typedef void (^AWFAerisAccountPermissionsCompletionBlock)(AWFAerisAccount *account, NSError * _Nullable error);

/**
 The API key associated with the user account.
 */
@property (nonatomic, readonly) NSString *apiKey;

/**
 The secret key associated with the user account and application.
 */
@property (nonatomic, readonly) NSString *secretKey;

/**
 Account access permissions for Aeris API
 */
@property (nonatomic, readonly, nullable) AWFApiPermissions *apiPermissions;

/**
 Account access permissions for Aeris Maps
 */
@property (nonatomic, readonly, nullable) AWFMapPermissions *mapPermissions;


/**
 Initializes and returns an `AWFAerisAccount` instance with the specified API access key and secret. This account will be used for all requests to the Aeris API.

 @param apiKey The access key for the account
 @param secretKey The account secret for the account
 @param completionBlock An optional block that is called when the account has been initialized and permissions have loaded
 @return The account instance initialized with the API key and secret
 */
- (instancetype)initWithApiKey:(NSString *)apiKey secret:(NSString *)secretKey completion:(nullable AWFAerisAccountPermissionsCompletionBlock)completionBlock;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
