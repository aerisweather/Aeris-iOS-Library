//
//  AWFObservation.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFObservation : AWFGeographicObject

/**
 *  Station identifier for this location, usually an ICAO.
 */
@property (nonatomic, copy) NSString *stationId;

/**
 *  GMT Date of the observation.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Local date of the observation.
 *  @deprecated Provided the same value as `timestamp` so use `timestamp` for the `NSDate` for this period.
 */
@property (nonatomic, strong) NSDate *validTime;

//-----------------------------------------------------------------------------
// @name Weather & Clouds
//-----------------------------------------------------------------------------

/**
 *  Primary observed weather phrase.
 */
@property (nonatomic, copy) NSString *weather;

/**
 *  Coded weather for the primary weather observed.
 */
@property (nonatomic, copy) NSString *weatherCoded;

/**
 *  Full observed weather phrase.
 */
@property (nonatomic, copy) NSString *weatherFull;

/**
 *  Full set of weather codes for the observed weather.
 */
@property (nonatomic, copy) NSString *weatherFullCoded;

/**
 *  Weather icon representing the observed weather from the default icon set.
 */
@property (nonatomic, copy) NSString *icon;

/**
 *  Sky coverage code.
 */
@property (nonatomic, copy) NSString *cloudsCoded;

/**
 *  Percentage of the sky covered by clouds. A value of `0` indicates clear sky conditions, while a value of `100` indicates entirely overcase sky
 *  conditions.
 *  @since 2.0
 */
@property (nonatomic, strong) NSNumber *skyCoverPercentage;

/**
 *  Estimated light level as a percentage.
 *  @since 2.0
 */
@property (nonatomic, strong) NSNumber *lightPercentage;

/**
 *  Solar radiation in watts per square meter (not provided by all stations).
 */
@property (nonatomic, strong) NSNumber *solarRadiationWM2;

//-----------------------------------------------------------------------------
// @name Temperatures
//-----------------------------------------------------------------------------

/**
 *  Observed temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *tempF;

/**
 *  Observed temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *tempC;

/**
 *  Apparent temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *feelslikeF;

/**
 *  Apparent temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *feelslikeC;

/**
 *  Calculated wind chill temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *windchillF;

/**
 *  Calculated wind chill temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *windchillC;

/**
 *  Calculated heat index temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *heatindexF;

/**
 *  Calculated heat index temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *heatindexC;

//-----------------------------------------------------------------------------
// @name Dew Points
//-----------------------------------------------------------------------------

/**
 *  Observed dew point temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *dewpointF;

/**
 *  Observed dew point temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *dewpointC;

//-----------------------------------------------------------------------------
// @name Relative Humidity
//-----------------------------------------------------------------------------

/**
 *  Calculated relative humidity as a percentage.
 */
@property (nonatomic, strong) NSNumber *humidity;

//-----------------------------------------------------------------------------
// @name Winds
//-----------------------------------------------------------------------------

/**
 *  Observed wind speed in knots.
 */
@property (nonatomic, strong) NSNumber *windSpeedKTS;

/**
 *  Observed wind speed in miles per hour.
 */
@property (nonatomic, strong) NSNumber *windSpeedMPH;

/**
 *  Observed wind speed in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *windSpeedKMH;

/**
 *  Observed cardianal wind direction.
 */
@property (nonatomic, copy) NSString *windDirection;

/**
 *  Observed wind direction in degrees (0=North).
 */
@property (nonatomic, strong) NSNumber *windDirectionDEG;

/**
 *  Observed wind gust speed in knots.
 */
@property (nonatomic, strong) NSNumber *windGustKTS;

/**
 *  Observed wind gust speed in miles per hour.
 */
@property (nonatomic, strong) NSNumber *windGustMPH;

/**
 *  Observed wind gust speed in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *windGustKMH;

//-----------------------------------------------------------------------------
// @name Barometric Pressure
//-----------------------------------------------------------------------------

/**
 *  Mean sea level pressure (MSLP) in inches of mercury. This value is adjusted from the observed station pressure to estimate the pressure that would
 *  exist at sea level at the same location by removing the effects of the station's elevation.
 */
@property (nonatomic, strong) NSNumber *pressureIN;

/**
 *  Mean sea level pressure (MSLP) in millibars. This value is adjusted from the observed station pressure to estimate the pressure that would
 *  exist at sea level at the same location by removing the effects of the station's elevation.
 */
@property (nonatomic, strong) NSNumber *pressureMB;

/**
 *  Actual barometric pressure observed at the station in inches of mercury. This value does not include an adjustment for the station's elevation.
 */
@property (nonatomic, strong) NSNumber *stationPressureIN;

/**
 *  Actual barometric pressure observed at the station in millibars. This value does not include an adjustment for the station's elevation.
 */
@property (nonatomic, strong) NSNumber *stationPressureMB;

/**
 *  Observed pressure reduced to mean sea level using the temperature profile of average conditions, in inches of mercury.
 */
@property (nonatomic, strong) NSNumber *altimeterIN;

/**
 *  Observed pressure reduced to mean sea level using the temperature profile of average conditions, in millibars.
 */
@property (nonatomic, strong) NSNumber *altimeterMB;

//-----------------------------------------------------------------------------
// @name Visibility
//-----------------------------------------------------------------------------

/**
 *  Observed visibility in kilometers.
 */
@property (nonatomic, strong) NSNumber *visibilityKM;

/**
 *  Observed visibility in miles.
 */
@property (nonatomic, strong) NSNumber *visibilityMI;

//-----------------------------------------------------------------------------
// @name Precipitation
//-----------------------------------------------------------------------------

/**
 *  Total precipitation observed in inches. This value can vary depending on the station.
 *  @since 2.0
 */
@property (nonatomic, strong) NSNumber *precipIN;

/**
 *  Total precipitation observed in millimeters. This value can vary depending on the station.
 *  @since 2.0
 */
@property (nonatomic, strong) NSNumber *precipMM;

/**
 *  Estimated snow depth at the station in inches.
 */
@property (nonatomic, strong) NSNumber *snowDepthIN;

/**
 *  Estimated snow depth at the station in centimeters.
 */
@property (nonatomic, strong) NSNumber *snowDepthCM;

//-----------------------------------------------------------------------------
// @name Other
//-----------------------------------------------------------------------------

/**
 *  Flight rule indicator based on weather conditions only.
 *
 *  Potential values are: LIFR, IFR, MVFR, VFR
 */
@property (nonatomic, copy) NSString *flightRule;

/**
 *  Raw observation data if available.
 */
@property (nonatomic, copy) NSString *raw;

/**
 *  GMT date of the sunrise at the reporting location.
 */
@property (nonatomic, strong) NSDate *sunrise;

/**
 *  GMT date of the sunset at the reporting location.
 */
@property (nonatomic, strong) NSDate *sunset;

/**
 *  Whether or not the observation occurred during daylight hours based on sunrise and sunset times.
 */
@property (nonatomic, assign) BOOL isDay;

@end


@interface AWFObservationArchive : AWFGeographicObject

/**
 *  Station identifier for this location, usually an ICAO.
 */
@property (nonatomic, copy) NSString *stationId;

/**
 *  Array of observation objects.
 */
@property (nonatomic, strong) NSArray *periods;

@end