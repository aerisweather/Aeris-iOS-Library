//
//  AWFObservationSummary.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/20/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFObservationSummary : AWFGeographicObject

/**
 *  Station identifier for this location, usually an ICAO.
 */
@property (nonatomic, copy) NSString *stationId;

/**
 *  Array of `AWFObservationSummaryPeriod` instances.
 */
@property (nonatomic, strong) NSArray *periods;

@end


@interface AWFObservationSummaryPeriod : AWFObject

/**
 *  GMT date for the period.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Local timezone for the forecast period.
 */
@property (nonatomic, strong) NSTimeZone *timeZone;

/**
 *  Starting date and time for the period.
 */
@property (nonatomic, strong) NSDate *rangeStartDate;

/**
 *  Ending date and time for the period.
 */
@property (nonatomic, strong) NSDate *rangeEndDate;

//-----------------------------------------------------------------------------
// @name Weather & Clouds
//-----------------------------------------------------------------------------

/**
 *  Primary observed weather phrase for the period.
 */
@property (nonatomic, copy) NSString *weather;

/**
 *  Coded weather for the primary weather observed during the period.
 */
@property (nonatomic, copy) NSString *weatherCoded;

/**
 *  Full observed weather phrase for the period.
 */
@property (nonatomic, copy) NSString *weatherFull;

/**
 *  Full set of weather codes for the observed weather during the period.
 */
@property (nonatomic, strong) NSArray *weatherFullCoded;

/**
 *  Total number of weather records for the period. If no weather other than sky conditions was reported, this value will be zero.
 */
@property (nonatomic, strong) NSNumber *weatherCount;

/**
 *  Array of unique cloud codes that were observed during the period.
 */
@property (nonatomic, strong) NSArray *cloudsCoded;

/**
 *  Weather icon representing the observed weather from the default icon set.
 */
@property (nonatomic, copy) NSString *icon;

/**
 *  Maximum sky cover during the period as a percentage.
 */
@property (nonatomic, strong) NSNumber *maxSkyCoverPercentage;

/**
 *  Minimum sky cover during the period as a percentage.
 */
@property (nonatomic, strong) NSNumber *minSkyCoverPercentage;

/**
 *  Average sky cover for the period as a percentage.
 */
@property (nonatomic, strong) NSNumber *avgSkyCoverPercentage;

/**
 *  Total number of sky cover records for the period.
 */
@property (nonatomic, strong) NSNumber *skyCoverPercentageCount;

//-----------------------------------------------------------------------------
// @name Temperatures
//-----------------------------------------------------------------------------

/**
 *  Maximum temperature observed during the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *maxTempF;

/**
 *  Maximum temperature observed during the period in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *maxTempC;

/**
 *  Minimum temperature observed during the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *minTempF;

/**
 *  Minimum temperature observed during the period in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *minTempC;

/**
 *  Average temperature for the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *avgTempF;

/**
 *  Average temperature observed during the period in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *avgTempC;

/**
 *  Total number of temperature records for the period.
 */
@property (nonatomic, strong) NSNumber *tempCount;

//-----------------------------------------------------------------------------
// @name Dew Points
//-----------------------------------------------------------------------------

/**
 *  Maximum dew point temperature observed during the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *maxDewpointF;

/**
 *  Maximum dew point temperature observed during the period in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *maxDewpointC;

/**
 *  Minimum dew point temperature observed during the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *minDewpointF;

/**
 *  Minimum dew point temperature observed during the period in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *minDewpointC;

/**
 *  Average dew point temperature for the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *avgDewpointF;

/**
 *  Average dew point temperature for the period in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *avgDewpointC;

/**
 *  Total number of dew point temperature records for the period.
 */
@property (nonatomic, strong) NSNumber *dewpointCount;

//-----------------------------------------------------------------------------
// @name Relative Humidity
//-----------------------------------------------------------------------------

/**
 *  Maximum relative humidity observed during the period as a percentage.
 */
@property (nonatomic, strong) NSNumber *maxHumidity;

/**
 *  Minimum relative humidity observed during the period as a percentage.
 */
@property (nonatomic, strong) NSNumber *minHumidity;

/**
 *  Average relative humidity for the period as a percentage.
 */
@property (nonatomic, strong) NSNumber *avgHumidity;

/**
 *  Total number of relative humidity records for the period.
 */
@property (nonatomic, strong) NSNumber *humidityCount;

//-----------------------------------------------------------------------------
// @name Precipitation
//-----------------------------------------------------------------------------

/**
 *  Total precipitation observed for the period in inches.
 */
@property (nonatomic, strong) NSNumber *precipIN;

/**
 *  Total precipitation observed for the period in millimeters.
 */
@property (nonatomic, strong) NSNumber *precipMM;
@property (nonatomic, strong) NSNumber *precipCount;

//-----------------------------------------------------------------------------
// @name Winds
//-----------------------------------------------------------------------------

/**
 *  Maximum wind speed observed during the period in knots.
 */
@property (nonatomic, strong) NSNumber *maxWindSpeedKTS;

/**
 *  Maximum wind speed observed during the period in miles per hour.
 */
@property (nonatomic, strong) NSNumber *maxWindSpeedMPH;

/**
 *  Maximum wind speed observed during the period in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *maxWindSpeedKMH;

/**
 *  Minimum wind speed observed during the period in knots.
 */
@property (nonatomic, strong) NSNumber *minWindSpeedKTS;

/**
 *  Minimum wind speed observed during the period in miles per hour.
 */
@property (nonatomic, strong) NSNumber *minWindSpeedMPH;

/**
 *  Minimum wind speed observed during the period in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *minWindSpeedKMH;

/**
 *  Average wind speed for the period in knots.
 */
@property (nonatomic, strong) NSNumber *avgWindSpeedKTS;

/**
 *  Average wind speed for the period in miles per hour.
 */
@property (nonatomic, strong) NSNumber *avgWindSpeedMPH;

/**
 *  Average wind speed for the period in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *avgWindSpeedKMH;

/**
 *  Total number of wind speed records for the period.
 */
@property (nonatomic, strong) NSNumber *windSpeedCount;

/**
 *  Maximum wind gust observed during the period in knots.
 */
@property (nonatomic, strong) NSNumber *windGustKTS;

/**
 *  Maximum wind gust observed during the period in miles per hour.
 */
@property (nonatomic, strong) NSNumber *windGustMPH;

/**
 *  Maximum wind gust observed during the period in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *windGustKMH;

//-----------------------------------------------------------------------------
// @name Barometric Pressure
//-----------------------------------------------------------------------------

/**
 *  Maximum barometric pressure observed during the period in inches of mercury.
 */
@property (nonatomic, strong) NSNumber *maxPressureIN;

/**
 *  Maximum barometric pressure observed during the period in millibars.
 */
@property (nonatomic, strong) NSNumber *maxPressureMB;

/**
 *  Minimum barometric pressure observed during the period in inches of mercury.
 */
@property (nonatomic, strong) NSNumber *minPressureIN;

/**
 *  Minimum barometric pressure observed during the period in millibars.
 */
@property (nonatomic, strong) NSNumber *minPressureMB;

/**
 *  Average barometric pressure for the period in inches of mercury.
 */
@property (nonatomic, strong) NSNumber *avgPressureIN;

/**
 *  Average barometric pressure for the period in millibars.
 */
@property (nonatomic, strong) NSNumber *avgPressureMB;

/**
 *  Total number of barometric pressure records for the period.
 */
@property (nonatomic, strong) NSNumber *pressureCount;

//-----------------------------------------------------------------------------
// @name Visibility
//-----------------------------------------------------------------------------

/**
 *  Maximum visibility observed during the period in miles.
 */
@property (nonatomic, strong) NSNumber *maxVisibilityMI;

/**
 *  Maximum visibility observed during the period in kilometers.
 */
@property (nonatomic, strong) NSNumber *maxVisibilityKM;

/**
 *  Minimum visibility observed during the period in miles.
 */
@property (nonatomic, strong) NSNumber *minVisibilityMI;

/**
 *  Minimum visibility observed during the period in kilometers.
 */
@property (nonatomic, strong) NSNumber *minVisibilityKM;

/**
 *  Average visibility for the period in miles.
 */
@property (nonatomic, strong) NSNumber *avgVisibilityMI;

/**
 *  Average visibility for the period in kilometers.
 */
@property (nonatomic, strong) NSNumber *avgVisibilityKM;

/**
 *  Total number of visibility records for the period.
 */
@property (nonatomic, strong) NSNumber *visibilityCount;

//-----------------------------------------------------------------------------
// @name Solar Radiation
//-----------------------------------------------------------------------------

/**
 *  Maximum solar radiation observed during the period in watts per square meter (not provided by all stations).
 */
@property (nonatomic, strong) NSNumber *maxSolarRadiationKM2;

/**
 *  Minimun solar radiation observed during the period in watts per square meter (not provided by all stations).
 */
@property (nonatomic, strong) NSNumber *minSolarRadiationKM2;

/**
 *  Average solar radiation for the period in watts per square meter (not provided by all stations).
 */
@property (nonatomic, strong) NSNumber *avgSolarRadiationKM2;

/**
 *  Total number of solar radiation records for the period.
 */
@property (nonatomic, strong) NSNumber *solarRadiationCount;

@end