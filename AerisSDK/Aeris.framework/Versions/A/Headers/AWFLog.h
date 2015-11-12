//
//  AFLog.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AWFLogLevel) {
	AWFLogLevelNone = 0,
	AWFLogLevelDebug,
	AWFLogLevelInfo,
	AWFLogLevelWarn,
	AWFLogLevelError
};

@interface AWFLog : NSObject

+ (void)debug:(NSString *)format,...;

+ (void)info:(NSString *)format,...;

+ (void)warn:(NSString *)format,...;

+ (void)error:(NSString *)format,...;

+ (void)setLoggingLevel:(AWFLogLevel)level;

+ (void)traceStack;
+ (void)logExecutionTimeOfBlock:(void (^)())block key:(NSString *)key;

@end
