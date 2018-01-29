//
//  AWFForecast.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

@class AWFForecastPeriod;

typedef NSDictionary<NSString *, id> *AWFForecastWeatherCodedItem;

/**
 An `AWFForecast` object represents data returned by the [**forecasts** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/forecasts/)
 of the Aeris Weather API.
 */
@interface AWFForecast : AWFGeographicObject

/**
 An array of forecast period returned for this forecast.
 */
@property (nonatomic, strong, nullable) NSArray<AWFForecastPeriod *> *periods;

@end


/**
 An `AWFForecastPeriod` object represents data for a single period returned by the [**forecasts** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/forecasts/)
 of the Aeris Weather API.
 */
@interface AWFForecastPeriod : AWFWeatherObject

/**
 GMT date for the period.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Local timezone for the forecast period.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

/**
 The short primary weather phrase for the period.
 */
@property (nonatomic, copy, nullable) NSString *weather;

/**
 The primary coded weather type for the period.
 */
@property (nonatomic, copy, nullable) NSString *weatherCoded;

/**
 The full weather phrase for the period.
 */
@property (nonatomic, copy, nullable) NSString *weatherFull;

/**
 All coded weather types for the period.
 */
@property (nonatomic, copy, nullable) NSArray<AWFForecastWeatherCodedItem> *weatherFullCoded;

/**
 Sky coverage code.
 */
@property (nonatomic, copy, nullable) NSString *cloudsCoded;

/**
 Sky coverage as a percentage.
 */
@property (nonatomic, assign) CGFloat skyCoverPercentage;

/**
 Weather icon for the primary weather type.
 */
@property (nonatomic, copy, nullable) NSString *icon;

/**
 Maximum temperature forecasted for the period in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat maxTempF;

/**
 Maximum temperature forecasted for the period in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat maxTempC;

/**
 Minimum temperature forecasted for the period in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat minTempF;

/**
 Minimum temperature forecasted for the period in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat minTempC;

/**
 Forecasted temperature for the date specified by `validDate` in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat tempF;

/**
 Forecasted temperature for the date specified by 'validDate` in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat tempC;

/**
 The average temperature across the period in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat avgTempF;

/**
 The average temperature across the period in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat avgTempC;

/**
 The forecasted apparent temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat feelslikeF;

/**
 Forecasted apparent temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat feelslikeC;

/**
 Forecasted dew point at the start of the period in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat dewpointF;

/**
 Forecasted dew point at the start of the period in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat dewpointC;

/**
 Relative humidity for the period as a percentage.
 */
@property (nonatomic, assign) CGFloat humidity;

/**
 Probability of precipitation (POP) for the period as a percentage.
 */
@property (nonatomic, assign) CGFloat pop;

/**
 Forecasted forecasted precipitation for the period in inches.
 **/
@property (nonatomic, assign) CGFloat precipIN;

/**
 Forecasted precipitation for the period in millimeters.
 */
@property (nonatomic, assign) CGFloat precipMM;

/**
 Forecasted snowfall for the period in inches.
 */
@property (nonatomic, assign) CGFloat snowIN;

/**
 Forecasted snowfall for the period in centimeters.
 */
@property (nonatomic, assign) CGFloat snowCM;

/**
 Forecasted wind speed in knots (KTS).
 */
@property (nonatomic, assign) CGFloat windSpeedKTS;

/**
 Forecasted wind speed in miles per hour (MPH).
 */
@property (nonatomic, assign) CGFloat windSpeedMPH;

/**
 Forecasted wind speed in kilometers per hour (KMH).
 */
@property (nonatomic, assign) CGFloat windSpeedKMH;

/**
 Forecasted wind gust speed in knots (KTS).
 */
@property (nonatomic, assign) CGFloat windGustKTS;

/**
 Forecasted wind gust speed in miles per hour (MPH).
 */
@property (nonatomic, assign) CGFloat windGustMPH;

/**
 Forecasted wind gust speed in kilometers per hour (KMH).
 */
@property (nonatomic, assign) CGFloat windGustKMH;

/**
 Forecasted maximum wind speed in knots (KTS).
 */
@property (nonatomic, assign) CGFloat windSpeedMaxKTS;

/**
 Forecasted maximum wind speed in miles per hour (MPH).
 */
@property (nonatomic, assign) CGFloat windSpeedMaxMPH;

/**  Forecasted maximum wind speed in kilometers per hour (KMH).
 */
@property (nonatomic, assign) CGFloat windSpeedMaxKMH;

/**
 Forecasted minimum wind speed in knots (KTS).
 */
@property (nonatomic, assign) CGFloat windSpeedMinKTS;

/**
 Forecasted minimum wind speed in miles per hour (MPH).
 */
@property (nonatomic, assign) CGFloat windSpeedMinMPH;

/**
 Forecasted minimum wind speed in kilometers per hour (KMH).
 */
@property (nonatomic, assign) CGFloat windSpeedMinKMH;

/**
 The wind speed range rounded to the nearest interval of 5 miles per hour above and below the forecasted value.
 */
@property (nonatomic, readonly, nullable) NSString *windSpeedRangeMPH;

/**
 The wind speed range rounded to the nearest interval of 5 kilometers per hour above and below the forecasted value.
 */
@property (nonatomic, readonly, nullable) NSString *windSpeedRangeKMH;

/**
 The wind speed range rounded to the nearest interval of 5 knots per hour above and below the forecasted value.
 */
@property (nonatomic, readonly, nullable) NSString *windSpeedRangeKTS;

/**
 Forecasted cardinal wind direction (e.g., N, E, S, W).
 */
@property (nonatomic, copy, nullable) NSString *windDirection;

/**
 Forecasted wind direction in degrees (0-359, 0=North).
 */
@property (nonatomic, assign) CGFloat windDirectionDEG;

/**
 Cardinal wind direction at the time of the forecasted minimum wind speed.
 */
@property (nonatomic, copy, nullable) NSString *windDirMin;

/**
 Wind direction in degrees at the time of the forecast minimum wind speed.
 */
@property (nonatomic, assign) CGFloat windDirMinDEG;

/**
 Cardinal wind direction at the time of the forecasted maximum wind speed.
 */
@property (nonatomic, copy, nullable) NSString *windDirMax;

/**
 Wind direction in degrees at the time of the forecast maximum wind speed.
 */
@property (nonatomic, assign) CGFloat windDirMaxDEG;

/**
 Forecasted barometric pressure in inches of mercury.
 */
@property (nonatomic, assign) CGFloat pressureIN;

/**
 Forecasted barometric pressure in millibars.
 */
@property (nonatomic, assign) CGFloat pressureMB;

/**
 GMT date of the sunrise for the period.
 */
@property (nonatomic, strong, nullable) NSDate *sunrise;

/**
 GMT date of the sunset for the period.
 */
@property (nonatomic, strong, nullable) NSDate *sunset;

/**
 Whether or not the period is during the day (between sunrise and sunset times).
 */
@property (nonatomic, assign) BOOL isDay;

@end
