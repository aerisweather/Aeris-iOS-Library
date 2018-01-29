//
//  AWFWritableApiEndpoint.h
//  AerisCore
//
//  Created by Nicholas Shipes on 10/25/17.
//  Copyright © 2017 AerisWeather. All rights reserved.
//

#import <AerisCore/AWFApiEndpoint.h>

@interface AWFWritableApiEndpoint : AWFApiEndpoint

- (void)postObject:(id)object options:(id)options completion:(AWFApiEndpointCompletionBlock)completionBlock;
- (void)postObject:(id)object toResource:(NSString *)resource options:(id)options completion:(AWFApiEndpointCompletionBlock)completionBlock;
- (void)putObject:(id)object options:(id)options completion:(AWFApiEndpointCompletionBlock)completionBlock;
- (void)putObject:(id)object toResource:(NSString *)resource options:(id)options completion:(AWFApiEndpointCompletionBlock)completionBlock;
- (void)deleteObject:(id)object options:(id)options completion:(AWFApiEndpointCompletionBlock)completionBlock;
- (void)deleteObjectWithIdentifer:(id)identifier options:(id)options completion:(AWFApiEndpointCompletionBlock)completionBlock;

@end
