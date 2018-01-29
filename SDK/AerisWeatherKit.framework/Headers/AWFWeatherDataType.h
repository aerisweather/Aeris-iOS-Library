//
//  AWFWeatherDataType.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/21/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The supported weather data types.

 - AWFWeatherDataTypeNone: Invalid data type
 - AWFWeatherDataTypeWeather: Weather data type
 - AWFWeatherDataTypeSkyCover: Sky cover data type
 - AWFWeatherDataTypeLight: Daylight data type
 - AWFWeatherDataTypeVisibility: Visibility data type
 - AWFWeatherDataTypeTemperature: Temperature data type
 - AWFWeatherDataTypeMaxTemperature: Maximum temperature data type
 - AWFWeatherDataTypeMinTemperature: Minimum temperature data type
 - AWFWeatherDataTypeAverageTemperature: Average temperature data type
 - AWFWeatherDataTypeDewPoint: Dew point data type
 - AWFWeatherDataTypeHumidity: Humidity data type
 - AWFWeatherDataTypeWindSpeed: Wind speed data type
 - AWFWeatherDataTypeWindGust: Wind gust data type
 - AWFWeatherDataTypePressure: Barometric pressure data type
 - AWFWeatherDataTypePrecipitation: Precipitation data type
 - AWFWeatherDataTypeAccumulatedPrecipitation: Accumulated precipitation data type
 - AWFWeatherDataTypeSnowfall: Snowfall data type
 - AWFWeatherDataTypeAccumulatedSnowfall: Accumulated snowfall data type
 - AWFWeatherDataTypeSnowDepth: Snow depth data type
 - AWFWeatherDataTypePOP: Probability of precipitation (POP) data type
 - AWFWeatherDataTypeSolarRadiation: Solar radiation data type
 - AWFWeatherDataTypeFeelsLike: Feels like data type
 - AWFWeatherDataTypeWindChill: Wind chill data type
 - AWFWeatherDataTypeHeatIndex: Heat index data type
 */
typedef NS_ENUM(NSUInteger, AWFWeatherDataType) {
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

/**
 Returns the unit of measurement for the specified data type.

 @param type The data type to return the unit for
 @param metric Whether the metric unit should be returned
 */
NSString * _Nullable AWFUnitForWeatherDataType(AWFWeatherDataType type, BOOL metric);
