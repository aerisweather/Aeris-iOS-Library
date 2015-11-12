//
//  AWFMeasurement.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/22/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

typedef NS_ENUM(NSUInteger, AWFMeasurement) {
	AWFMeasurementNone = 0,
	AWFMeasurementTemperature,
	AWFMeasurementDistance,
	AWFMeasurementSpeed,
	AWFMeasurementSize,
	AWFMeasurementDepth,
	AWFMeasurementAccumulation,
	AWFMeasurementProbability,
	AWFMeasurementPressure
};