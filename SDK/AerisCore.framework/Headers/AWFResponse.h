//
//  AWFResponse.h
//  AerisCore
//
//  Created by Nicholas Shipes on 6/9/16.
//  Copyright © 2016 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisCore/AWFResponseSerializer.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFRequestMetrics;

@interface AWFResponse : NSObject

@property (readonly, nonatomic, strong, nullable) NSURLRequest *request;
@property (readonly, nonatomic, strong, nullable) NSHTTPURLResponse *response;
@property (readonly, nonatomic, strong, nullable) NSData *data;
@property (readonly, nonatomic, strong, nullable) AWFResponseResult *result;
@property (readonly, nonatomic, strong, nullable) NSError *error;
@property (readonly, nonatomic, strong, nullable) AWFRequestMetrics *metrics;

- (instancetype)initWithRequest:(NSURLRequest * _Nullable)request
					   response:(NSHTTPURLResponse * _Nullable)response
						   data:(NSData * _Nullable)data
						 result:(AWFResponseResult *)result
						  error:(NSError *)error
						metrics:(AWFRequestMetrics *)metrics;

@end

NS_ASSUME_NONNULL_END
