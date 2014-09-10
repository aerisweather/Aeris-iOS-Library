//
//  AFRecord.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFRecord : AWFGeographicObject

/**
 *  Record type as a code.
 *
 *  prcp:	precipitation/rain
 *  snow:	snow
 *  maxt:	maximum temperature
 *  mint:	minimum temperature
 *  himn:	high minimum temperature
 *  lomx:	low maximum temperature
 */
@property (nonatomic, copy) NSString *type;

/**
 *  Numeric representation of the record type.
 */
@property (nonatomic, strong) NSNumber *code;

/**
 *  Station id where the record occurred.
 */
@property (nonatomic, copy) NSString *stationId;

/**
 *  Type of reporting station.
 */
@property (nonatomic, copy) NSString *stationType;

/**
 *  Name of the reporting station.
 */
@property (nonatomic, copy) NSString *stationName;

/**
 *  Brief description of the event, usually contains the location or relative distance from a populated place.
 */
@property (nonatomic, copy) NSString *name;

//-----------------------------------------------------------------------------
// @name New Record Data
//-----------------------------------------------------------------------------

/**
 *  GMT date when the new record took place.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Actual reported value from the report (rainfall or snowfall total, temperature, etc).
 */
@property (nonatomic, copy) NSString *value;

/**
 *  For snow-related records, the observed snowfall in inches.
 */
@property (nonatomic, strong) NSNumber *snowIN;

/**
 *  For snow-related records, the observed snowfall in centimeters.
 */
@property (nonatomic, strong) NSNumber *snowCM;

/**
 *  For rain-related records, the observed rainfall in inches.
 */
@property (nonatomic, strong) NSNumber *rainIN;

/**
 *  For rain-related records, the observed rainfall in millimeters.
 */
@property (nonatomic, strong) NSNumber *rainMM;

/**
 *  For temperature-related records, the observed temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *tempF;

/**
 *  For temperature-related records, the observed temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *tempC;

//-----------------------------------------------------------------------------
// @name Previous Record Data
//-----------------------------------------------------------------------------

/**
 *  GMT date when the previous record took place.
 */
@property (nonatomic, strong) NSDate *previousTimestamp;

/**
 *  Actual previous value from the report (rainfall or snowfall total, temperature, etc).
 */
@property (nonatomic, copy) NSString *previousValue;

/**
 *  For snow-related records, the previously observed snowfall in inches.
 */
@property (nonatomic, strong) NSNumber *previousSnowIN;

/**
 *  For snow-related records, the previously observed snowfall in centimeters.
 */
@property (nonatomic, strong) NSNumber *previousSnowCM;

/**
 *  For rain-related records, the previously observed rainfall in inches.
 */
@property (nonatomic, strong) NSNumber *previousRainIN;

/**
 *  For rain-related records, the previously observed rainfall in millimeters.
 */
@property (nonatomic, strong) NSNumber *previousRainMM;

/**
 *  For temperature-related records, the previously observed temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *previousTempF;

/**
 *  For temperature-related records, the previously observed temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *previousTempC;

/**
 *  Whether or not the record was tied.
 */
@property (nonatomic, assign) BOOL isTied;

@end