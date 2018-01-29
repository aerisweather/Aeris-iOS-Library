//
//  AWFThreat.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/13/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

@class AWFStormThreat;
@class AWFThreatPeriod;

/**
 An `AWFThreat` object represents data returned by the [**threats** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/threats/)
 of the Aeris Weather API.
 */
@interface AWFThreat : AWFGeographicObject

/**
 Array of `AWFThreatPeriod` instances for the current and future periods as supported.
 */
@property (nonatomic, strong, nullable) NSArray<AWFThreatPeriod *> *periods;

@end


/**
 An `AWFThreatPeriod` object contains threat information for a specific time period.
 */
@interface AWFThreatPeriod : AWFWeatherObject

/**
 GMT date for the period.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 The storm threat for the period, or `nil` if no threat exists.
 */
@property (nonatomic, strong, nullable) AWFStormThreat *stormThreat;

@end
