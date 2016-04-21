//
//  AWFRequest.h
//  Aeris
//
//  Created by Nicholas Shipes on 2/4/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

@import Foundation;

@interface AWFRequest : NSObject

- (NSURLSessionDataTask *)get:(NSString *)URLPath
				   parameters:(id)parameters
					  success:(void (^)(NSURLSessionDataTask *task, id response))success
					  failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

- (NSURLSessionDataTask *)get:(NSString *)URLPath
				   parameters:(id)parameters
					  manager:(AFHTTPSessionManager *)manager
					  success:(void (^)(NSURLSessionDataTask *task, id response))success
					  failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

- (NSURLSessionDataTask *)getImage:(NSString *)URLPath
						parameters:(id)parameters
						   success:(void (^)(NSURLSessionDataTask *task, UIImage *image))success
						   failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

- (NSURLSessionDataTask *)getImage:(NSString *)URLPath
						parameters:(id)parameters
						   manager:(AFHTTPSessionManager *)manager
						   success:(void (^)(NSURLSessionDataTask *task, UIImage *image))success
						   failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

@end
