//
//  AFRecord.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFRecord` object represents data returned by the [**records** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/records/)
 of the Aeris Weather API.
 */
@interface AWFRecord : AWFGeographicObject

/**
 Record type as a code.
 
 - `prcp`:	precipitation/rain
 - `snow`:	snow
 - `maxt`:	maximum temperature
 - `mint`:	minimum temperature
 - `himn`:	high minimum temperature
 - `lomx`:	low maximum temperature
 */
@property (nonatomic, copy, nullable) NSString *type;

/**
 Numeric representation of the record type.
 */
@property (nonatomic, assign) CGFloat code;

/**
 Station id where the record occurred.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 Type of reporting station.
 */
@property (nonatomic, copy, nullable) NSString *stationType;

/**
 Name of the reporting station.
 */
@property (nonatomic, copy, nullable) NSString *stationName;

/**
 Brief description of the event, usually contains the location or relative distance from a populated place.
 */
@property (nonatomic, copy, nullable) NSString *name;

//-----------------------------------------------------------------------------
// @name New Record Data
//-----------------------------------------------------------------------------

/**
 GMT date when the new record took place.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Actual reported value from the report (rainfall or snowfall total, temperature, etc).
 */
@property (nonatomic, copy, nullable) NSString *value;

/**
 For snow-related records, the observed snowfall in inches.
 */
@property (nonatomic, assign) CGFloat snowIN;

/**
 For snow-related records, the observed snowfall in centimeters.
 */
@property (nonatomic, assign) CGFloat snowCM;

/**
 For rain-related records, the observed rainfall in inches.
 */
@property (nonatomic, assign) CGFloat rainIN;

/**
 For rain-related records, the observed rainfall in millimeters.
 */
@property (nonatomic, assign) CGFloat rainMM;

/**
 For temperature-related records, the observed temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat tempF;

/**
 For temperature-related records, the observed temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat tempC;

//-----------------------------------------------------------------------------
// @name Previous Record Data
//-----------------------------------------------------------------------------

/**
 GMT date when the previous record took place.
 */
@property (nonatomic, strong, nullable) NSDate *previousTimestamp;

/**
 Actual previous value from the report (rainfall or snowfall total, temperature, etc).
 */
@property (nonatomic, copy, nullable) NSString *previousValue;

/**
 For snow-related records, the previously observed snowfall in inches.
 */
@property (nonatomic, assign) CGFloat previousSnowIN;

/**
 For snow-related records, the previously observed snowfall in centimeters.
 */
@property (nonatomic, assign) CGFloat previousSnowCM;

/**
 For rain-related records, the previously observed rainfall in inches.
 */
@property (nonatomic, assign) CGFloat previousRainIN;

/**
 For rain-related records, the previously observed rainfall in millimeters.
 */
@property (nonatomic, assign) CGFloat previousRainMM;

/**
 For temperature-related records, the previously observed temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat previousTempF;

/**
 For temperature-related records, the previously observed temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat previousTempC;

/**
 Whether or not the record was tied.
 */
@property (nonatomic, assign) BOOL isTied;

@end

NS_ASSUME_NONNULL_END
