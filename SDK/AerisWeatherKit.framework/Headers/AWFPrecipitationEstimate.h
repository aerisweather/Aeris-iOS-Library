//
//  AWFPrecipitationEstimate.h
//  Aeris
//
//  Created by Nicholas Shipes on 4/5/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFPrecipitationPeriod;

@interface AWFPrecipitationEstimate : AWFGeographicObject

@property (nonatomic, strong, nullable) NSArray<AWFPrecipitationPeriod *> *periods;

@end

NS_ASSUME_NONNULL_END
