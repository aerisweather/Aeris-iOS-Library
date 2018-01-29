//
//  AFLightning.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFLightningStrike` object represents data returned by the [**lightning** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/lightning/)
 of the Aeris Weather API.
 */
@interface AWFLightningStrike : AWFGeographicObject

/**
 GMT date of the strike.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Type of lightning strike, either cloud-to-cloud (IC) or cloud-to-ground (CG).
 */
@property (nonatomic, copy, nullable) NSString *pulseType;

/**
 Peak electric current in amps.
 */
@property (nonatomic, assign) CGFloat peakAmperage;

@end

NS_ASSUME_NONNULL_END
