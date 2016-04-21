//
//  AWFWeatherDataType.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger, AWFWeatherDataType) {
	AWFWeatherDataTypeNone = 0,
	AWFWeatherDataTypeWeather,
	AWFWeatherDataTypeSkyCover,
	AWFWeatherDataTypeLight,
	AWFWeatherDataTypeVisibility,
	AWFWeatherDataTypeTemperature,
	AWFWeatherDataTypeMaxTemperature,
	AWFWeatherDataTypeMinTemperature,
	AWFWeatherDataTypeAverageTemperature,
	AWFWeatherDataTypeDewPoint,
	AWFWeatherDataTypeHumidity,
	AWFWeatherDataTypeWindSpeed,
	AWFWeatherDataTypeWindGust,
	AWFWeatherDataTypePressure,
	AWFWeatherDataTypePrecipitation,
	AWFWeatherDataTypeAccumulatedPrecipitation,
	AWFWeatherDataTypeSnowfall,
	AWFWeatherDataTypeAccumulatedSnowfall,
	AWFWeatherDataTypeSnowDepth,
	AWFWeatherDataTypePOP,
	AWFWeatherDataTypeSolarRadiation,
	AWFWeatherDataTypeFeelsLike,
	AWFWeatherDataTypeWindChill,
	AWFWeatherDataTypeHeatIndex
};