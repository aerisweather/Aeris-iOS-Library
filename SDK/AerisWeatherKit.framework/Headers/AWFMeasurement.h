//
//  AWFMeasurement.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/22/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisWeatherKit/AWFWeatherGlobals.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Units of measurement for weather data.

 - AWFMeasurementNone: No unit of measurement
 - AWFMeasurementTemperature: Temperature measurement
 - AWFMeasurementDistance: Distance measurement
 - AWFMeasurementSpeed: Speed measurement
 - AWFMeasurementSize: Size measurement
 - AWFMeasurementDepth: Depth measurement
 - AWFMeasurementAccumulation: Accumulation measurement
 - AWFMeasurementProbability: Probability measurement
 - AWFMeasurementPressure: Pressure Measurement
 */
typedef NS_ENUM(NSUInteger, AWFMeasurement) {
	AWFMeasurementNone = 0,
	AWFMeasurementTemperature,
	AWFMeasurementDistance,
	AWFMeasurementHeight,
	AWFMeasurementSpeed,
	AWFMeasurementSize,
	AWFMeasurementDepth,
	AWFMeasurementAccumulation,
	AWFMeasurementPercentage,
	AWFMeasurementProbability,
	AWFMeasurementPressure,
	AWFMeasurementConcentration,
	AWFMeasurementDecibals
};

/**
 Returns the unit string for the specified `AWFMeasurement` and Metric designation.
 */
AWFUnit AWFUnitForMeasurement(AWFMeasurement type, BOOL metric);

NS_ASSUME_NONNULL_END
