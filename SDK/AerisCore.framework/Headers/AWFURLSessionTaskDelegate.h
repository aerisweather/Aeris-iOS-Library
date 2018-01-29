//
//  AWFURLSessionTaskDelegate.h
//  AerisCore
//
//  Created by Nicholas Shipes on 6/9/16.
//  Copyright © 2016 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisCore/AWFURLSessionManager.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^AWFURLSessionDataTaskDataProgress)(int64_t bytesRecieved, int64_t totalBytesReceived, int64_t totalBytesExpectedToReceive);
typedef void (^AWFURLSessionDataTaskDataStream)(NSData * _Nullable data);

@interface AWFURLSessionTaskDelegate : NSObject <NSURLSessionTaskDelegate>

@property (readonly, nonatomic, strong) NSURLSessionTask *task;
@property (readonly, nonatomic, strong) NSOperationQueue *queue;
@property (readonly, nonatomic, strong) NSProgress *progress;
@property (nonatomic, strong, nullable) NSData *data;
@property (nonatomic, strong, nullable) NSError *error;
@property (readonly, nonatomic, assign) CFAbsoluteTime initialResponseTime;
@property (readonly, nonatomic, strong, nullable) NSURLCredential *credential;
@property (nonatomic, copy, nullable) AWFURLSessionTaskWillPerformHTTPRedirectionBlock taskWillPerformHTTPRedirection;
@property (nonatomic, copy, nullable) AWFURLSessionTaskDidReceiveAuthenticationChallengeBlock taskDidReceiveAuthenticationChallenge;
@property (nonatomic, copy, nullable) AWFURLSessionTaskNeedNewBodyStreamBlock taskNeedNewBodyStream;
@property (nonatomic, copy, nullable) AWFURLSessionTaskDidCompleteBlock taskDidComplete;

- (instancetype)initWithTask:(NSURLSessionTask *)task;

@end


@interface AWFURLSessionDataTaskDelegate : AWFURLSessionTaskDelegate <NSURLSessionDataDelegate>

@property (readonly, nonatomic, strong) NSURLSessionDataTask *task;
@property (nonatomic, copy, nullable) AWFURLSessionDataTaskDataProgress dataProgress;
@property (nonatomic, copy, nullable) AWFURLSessionDataTaskDataStream dataStream;
@property (nonatomic, copy, nullable) AWFURLSessionDataTaskDidReceiveResponseBlock dataTaskDidReceiveResponse;
@property (nonatomic, copy, nullable) AWFURLSessionDataTaskDidBecomeDownloadTaskBlock dataTaskDidBecomeDownloadTask;
@property (nonatomic, copy, nullable) AWFURLSessionDataTaskDidReceiveDataBlock dataTaskDidReceiveData;
@property (nonatomic, copy, nullable) AWFURLSessionDataTaskWillCacheResponseBlock dataTaskWillCacheResponse;

@end

@interface AWFURLSessionUploadTaskDelegate : AWFURLSessionDataTaskDelegate

@end

@interface AWFURLSessionDownloadTaskDelegate : AWFURLSessionTaskDelegate

@end

NS_ASSUME_NONNULL_END