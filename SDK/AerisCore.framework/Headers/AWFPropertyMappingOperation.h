//
//  AWFPropertyMappingOperation.h
//  AerisApiLibrary
//
//  Created by Nicholas Shipes on 3/24/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AWFApiResponse, AWFPropertyMapper;

typedef void (^AWFPropertyMappingOperationCompletionBlock)(NSArray *objects);

@interface AWFPropertyMappingOperation : NSOperation

- (instancetype)initWithDictionary:(NSDictionary *)dictionary class:(Class)klass mapper:(AWFPropertyMapper *)mapper;
- (instancetype)initWithApiResponse:(AWFApiResponse *)response class:(Class)klass mapper:(AWFPropertyMapper *)mapper;
- (void)setMappingCompletionBlock:(AWFPropertyMappingOperationCompletionBlock)completionBlock;

@end
