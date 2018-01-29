//
//  AWFApiPermissions.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 1/27/17.
//  Copyright © 2017 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFApiPermissions` object contains the access permissions when interacting with the Aeris API.
 */
@interface AWFApiPermissions : NSObject

/**
 Initializes and returns an `AWFApiPermissions` instance using the specified access permissions data.

 @param dictionary The access permissions dictionary to use
 @return A permissions object initialized with the specified permissions dictionary
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/**
 Returns a Boolean value indicating whether or not the configured permissions allow access to the specified endpoint path.

 @param endpoint The endpoint path to check access for
 */
- (BOOL)canAccessEndpoint:(NSString *)endpoint;

@end

NS_ASSUME_NONNULL_END
