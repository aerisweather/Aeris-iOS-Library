//
//  AWFResponseSerializer.h
//  AerisCore
//
//  Created by Nicholas Shipes on 6/9/16.
//  Copyright © 2016 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AWFResponseResult;

typedef AWFResponseResult * _Nullable (^AWFResponseSerializerBlock)(NSURLRequest * _Nullable request, NSHTTPURLResponse * _Nullable response, NSData * _Nullable data, NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface AWFResponseResult<__covariant Value> : NSObject

@property (nonatomic, strong) Value value;
@property (nonatomic, strong) NSError *error;

+ (instancetype)result;

@end


@interface AWFResponseSerializer<__covariant Value> : NSObject

@property (nonatomic, copy, nullable) AWFResponseSerializerBlock serializeResponse;

- (instancetype)initWithSerializeResponseBlock:(AWFResponseSerializerBlock)serializeResponse;

@end

NS_ASSUME_NONNULL_END
