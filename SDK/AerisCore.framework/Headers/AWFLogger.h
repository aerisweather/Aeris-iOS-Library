//
//  AWFLogger.h
//  AerisCore
//
//  Created by Nicholas Shipes on 11/24/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <UIKit/UIKit.h>

#define AWF_LOG_MACRO(lvl, fnct, frmt, ...) [AWFLogger logLevel: lvl file: __FILE__ function: fnct line: __LINE__ format: (frmt), ## __VA_ARGS__]

#define AWFLogError(frmt, ...)   AWF_LOG_MACRO(AWFLogLevelError, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AWFLogWarn(frmt, ...)    AWF_LOG_MACRO(AWFLogLevelWarn,  __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AWFLogInfo(frmt, ...)    AWF_LOG_MACRO(AWFLogLevelInfo,  __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AWFLogDebug(frmt, ...)   AWF_LOG_MACRO(AWFLogLevelDebug, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

typedef NS_ENUM(NSUInteger, AWFLogLevel) {
	AWFLogLevelNone = 0,
	AWFLogLevelDebug,
	AWFLogLevelInfo,
	AWFLogLevelWarn,
	AWFLogLevelError
};

@interface AWFLogger : NSObject

+ (instancetype)logger;
+ (void)setLoggingLevel:(AWFLogLevel)level;
+ (void)enableLogToFile;
+ (void)resetFile;
+ (void)synchronizeLogFile;
+ (NSString *)logFilePath;

+ (void)logLevel:(AWFLogLevel)level format:(NSString *)format, ...;
+ (void)logLevel:(AWFLogLevel)level file:(const char *)file function: (const char *)function line:(int)line format:(NSString *)format, ...;
+ (void)traceStack;
+ (void)logExecutionTimeOfBlock:(void (^)(void))block key:(NSString *)key;

@end
