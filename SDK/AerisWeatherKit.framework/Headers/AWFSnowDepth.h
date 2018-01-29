//
//  AWFSnowDepth.h
//  Aeris
//
//  Created by Nicholas Shipes on 4/5/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFSnowDepthPeriod;

@interface AWFSnowDepth : AWFGeographicObject

@property (nonatomic, strong, nullable) NSArray<AWFSnowDepthPeriod *> *periods;

@end



@interface AWFSnowDepthPeriod : AWFWeatherObject

@property (nonatomic, strong, nullable) NSDate *timestamp;
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;
@property (nonatomic, assign) CGFloat depthIN;
@property (nonatomic, assign) CGFloat depthCM;

@end

NS_ASSUME_NONNULL_END
