//
//  AWFObservation.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSDictionary<NSString *, id> *AWFObservationWeatherCodedItem;

/**
 An `AWFObservation` object represents data returned by the [**observations** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/observations/)
 of the Aeris Weather API.
 */
@interface AWFObservation : AWFGeographicObject

/**
 Station identifier for this location, usually an ICAO.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 GMT Date of the observation.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

//-----------------------------------------------------------------------------
// @name Weather & Clouds
//-----------------------------------------------------------------------------

/**
 Primary observed weather phrase.
 */
@property (nonatomic, copy, nullable) NSString *weather;

/**
 Coded weather for the primary weather observed.
 
 The coded weather values can often be used for translating the weather observed. Refer to the [Weather Codes](https://www.aerisweather.com/support/docs/api/reference/weather-codes/)
 API documentation for additional information.
 */
@property (nonatomic, copy, nullable) NSString *weatherCoded;

/**
 Full observed weather phrase.
 */
@property (nonatomic, copy, nullable) NSString *weatherFull;

/**
 Full set of weather codes for the observed weather.
 */
@property (nonatomic, copy, nullable) NSString *weatherFullCoded;

/**
 Weather icon representing the observed weather from the default icon set.
 */
@property (nonatomic, copy, nullable) NSString *icon;

/**
 Sky coverage code.
 */
@property (nonatomic, copy, nullable) NSString *cloudsCoded;

/**
 Percentage of the sky covered by clouds. A value of `0` indicates clear sky conditions, while a value of `100` indicates entirely overcast sky
 conditions.
 */
@property (nonatomic, assign) CGFloat skyCoverPercentage;

/**
 Estimated light level as a percentage.
 */
@property (nonatomic, assign) CGFloat lightPercentage;

/**
 Solar radiation in watts per square meter (not provided by all stations).
 */
@property (nonatomic, assign) CGFloat solarRadiationWM2;

//-----------------------------------------------------------------------------
// @name Temperatures
//-----------------------------------------------------------------------------

/**
 Observed temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat tempF;

/**
 Observed temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat tempC;

/**
 Apparent temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat feelslikeF;

/**
 Apparent temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat feelslikeC;

/**
 Calculated wind chill temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat windchillF;

/**
 Calculated wind chill temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat windchillC;

/**
 Calculated heat index temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat heatindexF;

/**
 Calculated heat index temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat heatindexC;

//-----------------------------------------------------------------------------
// @name Dew Points
//-----------------------------------------------------------------------------

/**
 Observed dew point temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat dewpointF;

/**
 Observed dew point temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat dewpointC;

//-----------------------------------------------------------------------------
// @name Relative Humidity
//-----------------------------------------------------------------------------

/**
 Calculated relative humidity as a percentage.
 */
@property (nonatomic, assign) CGFloat humidity;

//-----------------------------------------------------------------------------
// @name Winds
//-----------------------------------------------------------------------------

/**
 Observed wind speed in knots.
 */
@property (nonatomic, assign) CGFloat windSpeedKTS;

/**
 Observed wind speed in miles per hour.
 */
@property (nonatomic, assign) CGFloat windSpeedMPH;

/**
 Observed wind speed in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat windSpeedKMH;

/**
 Observed cardianal wind direction.
 */
@property (nonatomic, copy, nullable) NSString *windDirection;

/**
 Observed wind direction in degrees (0=North).
 */
@property (nonatomic, assign) CGFloat windDirectionDEG;

/**
 Observed wind gust speed in knots.
 */
@property (nonatomic, assign) CGFloat windGustKTS;

/**
 Observed wind gust speed in miles per hour.
 */
@property (nonatomic, assign) CGFloat windGustMPH;

/**
 Observed wind gust speed in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat windGustKMH;

//-----------------------------------------------------------------------------
// @name Barometric Pressure
//-----------------------------------------------------------------------------

/**
 Mean sea level pressure (MSLP) in inches of mercury. This value is adjusted from the observed station pressure to estimate the pressure that would
 exist at sea level at the same location by removing the effects of the station's elevation.
 */
@property (nonatomic, assign) CGFloat pressureIN;

/**
 Mean sea level pressure (MSLP) in millibars. This value is adjusted from the observed station pressure to estimate the pressure that would
 exist at sea level at the same location by removing the effects of the station's elevation.
 */
@property (nonatomic, assign) CGFloat pressureMB;

/**
 Actual barometric pressure observed at the station in inches of mercury. This value does not include an adjustment for the station's elevation.
 */
@property (nonatomic, assign) CGFloat stationPressureIN;

/**
 Actual barometric pressure observed at the station in millibars. This value does not include an adjustment for the station's elevation.
 */
@property (nonatomic, assign) CGFloat stationPressureMB;

/**
 Observed pressure reduced to mean sea level using the temperature profile of average conditions, in inches of mercury.
 */
@property (nonatomic, assign) CGFloat altimeterIN;

/**
 Observed pressure reduced to mean sea level using the temperature profile of average conditions, in millibars.
 */
@property (nonatomic, assign) CGFloat altimeterMB;

//-----------------------------------------------------------------------------
// @name Visibility
//-----------------------------------------------------------------------------

/**
 Observed visibility in kilometers.
 */
@property (nonatomic, assign) CGFloat visibilityKM;

/**
 Observed visibility in miles.
 */
@property (nonatomic, assign) CGFloat visibilityMI;

//-----------------------------------------------------------------------------
// @name Precipitation
//-----------------------------------------------------------------------------

/**
 Total precipitation observed in inches. This value can vary depending on the station.
 */
@property (nonatomic, assign) CGFloat precipIN;

/**
 Total precipitation observed in millimeters. This value can vary depending on the station.
 @since 2.0
 */
@property (nonatomic, assign) CGFloat precipMM;

/**
 Estimated snow depth at the station in inches.
 */
@property (nonatomic, assign) CGFloat snowDepthIN;

/**
 Estimated snow depth at the station in centimeters.
 */
@property (nonatomic, assign) CGFloat snowDepthCM;

//-----------------------------------------------------------------------------
// @name Other
//-----------------------------------------------------------------------------

/**
 Flight rule indicator based on weather conditions only.
 
 Potential values are: LIFR, IFR, MVFR, VFR
 */
@property (nonatomic, copy, nullable) NSString *flightRule;

/**
 Raw observation data if available.
 */
@property (nonatomic, copy, nullable) NSString *raw;

/**
 GMT date of the sunrise at the reporting location.
 */
@property (nonatomic, strong, nullable) NSDate *sunrise;

/**
 GMT date of the sunset at the reporting location.
 */
@property (nonatomic, strong, nullable) NSDate *sunset;

/**
 Whether or not the observation occurred during daylight hours based on sunrise and sunset times.
 */
@property (nonatomic, assign) BOOL isDay;

@end


/**
 An `AWFObservationArchive` object represents data returned by the [**observations/archive** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/observations-archive/)
 of the Aeris Weather API.
 */
@interface AWFObservationArchive : AWFGeographicObject

/**
 Station identifier for this location, usually an ICAO.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 Array of observation objects.
 */
@property (nonatomic, strong, nullable) NSArray<AWFObservation *> *periods;

@end

NS_ASSUME_NONNULL_END
