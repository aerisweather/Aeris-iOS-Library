//
//  AWFRequestTimeline.h
//  AerisCore
//
//  Created by Nicholas Shipes on 9/16/16.
//  Copyright © 2016 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AWFRequestMetrics : NSObject

@property (nonatomic, readonly) CFAbsoluteTime requestStartTime;
@property (nonatomic, readonly) CFAbsoluteTime initialResponseTime;
@property (nonatomic, readonly) CFAbsoluteTime requestCompletionTime;
@property (nonatomic, readonly) CFAbsoluteTime serializationCompletionTime;
@property (nonatomic, readonly) NSTimeInterval latency;
@property (nonatomic, readonly) NSTimeInterval requestDuration;
@property (nonatomic, readonly) NSTimeInterval serializationDuration;
@property (nonatomic, readonly) NSTimeInterval totalDuration;

- (instancetype)initWithRequestStartTime:(CFAbsoluteTime)requestStartTime
					 initialResponseTime:(CFAbsoluteTime)initialResponseTime
				   requestCompletionTime:(CFAbsoluteTime)requestCompletionTime
			 serializationCompletionTime:(CFAbsoluteTime)serializationCompletionTime;

@end
