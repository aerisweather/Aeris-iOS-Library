//
//  AWFForecast.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFForecast : AWFGeographicObject

/**
 *  An array of AWFForecastPeriod instances returned for this forecast.
 */
@property (nonatomic, strong) NSArray *periods;

@end

@interface AWFForecastPeriod : AWFObject

/**
 *  GMT date for the period.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Local timezone for the forecast period.
 *  @since version 1.0.3
 */
@property (nonatomic, strong) NSTimeZone *timeZone;

/**
 *  The short primary weather phrase for the period.
 */
@property (nonatomic, copy) NSString *weather;

/**
 *  The primary coded weather type for the period.
 */
@property (nonatomic, copy) NSString *weatherCoded;

/**
 *  The full weather phrase for the period.
 */
@property (nonatomic, copy) NSString *weatherFull;

/**
 *  All coded weather types for the period.
 */
@property (nonatomic, copy) NSArray *weatherFullCoded;

/**
 *  Sky coverage code.
 */
@property (nonatomic, copy) NSString *cloudsCoded;

/**
 *  Sky coverage as a percentage.
 */
@property (nonatomic, strong) NSNumber *skyCoverPercentage;

/**
 *  Weather icon for the primary weather type.
 */
@property (nonatomic, copy) NSString *icon;

/**
 *  Maximum temperature forecasted for the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *maxTempF;

/**
 *  Maximum temperature forecasted for the period in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *maxTempC;

/**
 *  Minimum temperature forecasted for the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *minTempF;

/**
 *  Minimum temperature forecasted for the period in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *minTempC;

/**
 *  Forecasted temperature for the date specified by `validDate` in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *tempF;

/**
 *  Forecasted temperature for the date specified by 'validDate` in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *tempC;

/**
 *  The average temperature across the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *avgTempF;

/**
 *  The average temperature across the period in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *avgTempC;

/**
 *  The forecasted apparent temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *feelslikeF;

/**
 *  Forecasted apparent temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *feelslikeC;

/**
 *  Forecasted dew point at the start of the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *dewpointF;

/**
 *  Forecasted dew point at the start of the period in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *dewpointC;

/**
 *  Relative humidity for the period as a percentage.
 */
@property (nonatomic, strong) NSNumber *humidity;

/**
 *  Probability of precipitation (POP) for the period as a percentage.
 */
@property (nonatomic, strong) NSNumber *pop;

/**
 *  Forecasted forecasted precipitation for the period in inches.
 **/
@property (nonatomic, strong) NSNumber *precipIN;

/**
 *  Forecasted precipitation for the period in millimeters.
 */
@property (nonatomic, strong) NSNumber *precipMM;

/**
 *  Forecasted snowfall for the period in inches.
 */
@property (nonatomic, strong) NSNumber *snowIN;

/**
 *  Forecasted snowfall for the period in centimeters.
 */
@property (nonatomic, strong) NSNumber *snowCM;

/**
 *  Forecasted wind speed in knots (KTS).
 */
@property (nonatomic, strong) NSNumber *windSpeedKTS;

/**
 *  Forecasted wind speed in miles per hour (MPH).
 */
@property (nonatomic, strong) NSNumber *windSpeedMPH;

/**
 *  Forecasted wind speed in kilometers per hour (KMH).
 */
@property (nonatomic, strong) NSNumber *windSpeedKMH;

/**
 *  Forecasted wind gust speed in knots (KTS).
 */
@property (nonatomic, strong) NSNumber *windGustKTS;

/**
 *  Forecasted wind gust speed in miles per hour (MPH).
 */
@property (nonatomic, strong) NSNumber *windGustMPH;

/**
 *  Forecasted wind gust speed in kilometers per hour (KMH).
 */
@property (nonatomic, strong) NSNumber *windGustKMH;

/**
 *  Forecasted maximum wind speed in knots (KTS).
 */
@property (nonatomic, strong) NSNumber *windSpeedMaxKTS;

/**
 *  Forecasted maximum wind speed in miles per hour (MPH).
 */
@property (nonatomic, strong) NSNumber *windSpeedMaxMPH;

/**  Forecasted maximum wind speed in kilometers per hour (KMH).
 */
@property (nonatomic, strong) NSNumber *windSpeedMaxKMH;

/**
 *  Forecasted minimum wind speed in knots (KTS).
 */
@property (nonatomic, strong) NSNumber *windSpeedMinKTS;

/**
 *  Forecasted minimum wind speed in miles per hour (MPH).
 */
@property (nonatomic, strong) NSNumber *windSpeedMinMPH;

/**
 *  Forecasted minimum wind speed in kilometers per hour (KMH).
 */
@property (nonatomic, strong) NSNumber *windSpeedMinKMH;

/**
 *  The wind speed range rounded to the nearest interval of 5 miles per hour above and below the forecasted value.
 */
@property (nonatomic, readonly) NSString *windSpeedRangeMPH;

/**
 *  The wind speed range rounded to the nearest interval of 5 kilometers per hour above and below the forecasted value.
 */
@property (nonatomic, readonly) NSString *windSpeedRangeKMH;

/**
 *  The wind speed range rounded to the nearest interval of 5 knots per hour above and below the forecasted value.
 */
@property (nonatomic, readonly) NSString *windSpeedRangeKTS;

/**
 *  Forecasted cardinal wind direction (e.g., N, E, S, W).
 */
@property (nonatomic, copy) NSString *windDirection;

/**
 *  Forecasted wind direction in degrees (0-359, 0=North).
 */
@property (nonatomic, strong) NSNumber *windDirectionDEG;

/**
 *  Cardinal wind direction at the time of the forecasted minimum wind speed.
 */
@property (nonatomic, copy) NSString *windDirMin;

/**
 *  Wind direction in degrees at the time of the forecast minimum wind speed.
 */
@property (nonatomic, strong) NSNumber *windDirMinDEG;

/**
 *  Cardinal wind direction at the time of the forecasted maximum wind speed.
 */
@property (nonatomic, copy) NSString *windDirMax;

/**
 *  Wind direction in degrees at the time of the forecast maximum wind speed.
 */
@property (nonatomic, strong) NSNumber *windDirMaxDEG;

/**
 *  Forecasted barometric pressure in inches of mercury.
 */
@property (nonatomic, strong) NSNumber *pressureIN;

/**
 *  Forecasted barometric pressure in millibars.
 */
@property (nonatomic, strong) NSNumber *pressureMB;

/**
 *  GMT date of the sunrise for the period.
 */
@property (nonatomic, strong) NSDate *sunrise;

/**
 *  GMT date of the sunset for the period.
 */
@property (nonatomic, strong) NSDate *sunset;

/**
 *  Whether or not the period is during the day (between sunrise and sunset times).
 */
@property (nonatomic, assign) BOOL isDay;

@end