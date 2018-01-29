//
//  AWFRequest.h
//  AerisCore
//
//  Created by Nicholas Shipes on 6/9/16.
//  Copyright © 2016 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisCore/AWFResponseSerializer.h>

typedef NS_ENUM(NSUInteger, AWFRequestMethod) {
	AWFRequestMethodGET = 0,
	AWFRequestMethodHEAD,
	AWFRequestMethodPOST,
	AWFRequestMethodPUT,
	AWFRequestMethodPATCH,
	AWFRequestMethodDELETE
};

typedef NS_ENUM(NSUInteger, AWFParameterEncoding) {
	AWFParameterEncodingURL = 0,
	AWFParameterEncodingURLEncodedInURL,
	AWFParameterEncodingJSON,
	AWFParameterEncodingPropertyList,
	AWFParameterEncodingCustom
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^AWFRequestProgress)(int64_t bytesRecieved, int64_t totalBytesReceived, int64_t totalBytesExpectedToReceive);

@class AWFResponse, AWFResponseSerializer, AWFURLSessionTaskDelegate;

@interface AWFRequest : NSObject

@property (readonly, nonatomic, strong) AWFURLSessionTaskDelegate *delegate;
@property (nonatomic) NSURLSessionTask *task;
@property (readonly, nonatomic, strong) NSURLSession *session;
@property (nonatomic, nullable) NSURLRequest *request;
@property (nonatomic, nullable) NSHTTPURLResponse *response;
@property (nonatomic) NSProgress *progress;

- (instancetype)initWithSession:(NSURLSession *)session task:(NSURLSessionTask *)task;

- (void)resume;
- (void)suspend;
- (void)cancel;

- (void)setProgressHandler:(AWFRequestProgress)progressHandler;

//-----------------------------------------------------------------------------
// @name Responses
//-----------------------------------------------------------------------------

- (void)responseInQueue:(nullable dispatch_queue_t)queue completionHandler:(AWFResponseSerializerBlock)completionHandler;
- (void)responseWithSerializer:(AWFResponseSerializer *)serializer inQueue:(nullable dispatch_queue_t)queue completionHandler:(void (^)(AWFResponse *response))completionHandler;

- (void)responseAsData:(nullable dispatch_queue_t)queue completionHandler:(void (^)(AWFResponse *response))completionHandler;
- (void)responseAsString:(nullable dispatch_queue_t)queue encoding:(NSStringEncoding)encoding completionHandler:(void (^)(AWFResponse *response))completionHandler;
- (void)responseAsJSON:(nullable dispatch_queue_t)queue options:(NSJSONReadingOptions)options completionHandler:(void (^)(AWFResponse *response))completionHandler;
- (void)responseAsImage:(nullable dispatch_queue_t)queue completionHandler:(void (^)(AWFResponse *response))completionHandler;

@end

NS_ASSUME_NONNULL_END
