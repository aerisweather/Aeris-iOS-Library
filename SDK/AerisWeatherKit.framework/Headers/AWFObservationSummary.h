//
//  AWFObservationSummary.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/20/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>
#import <AerisWeatherKit/AWFObservation.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFObservationSummaryPeriod;

/**
 An `AWFObservationSummary` object represents data returned by the [**observations/summary** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/observations-summary/)
 of the Aeris Weather API.
 */
@interface AWFObservationSummary : AWFGeographicObject

/**
 Station identifier for this location, usually an ICAO.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 Array of `AWFObservationSummaryPeriod` instances.
 */
@property (nonatomic, strong, nullable) NSArray<AWFObservationSummaryPeriod *> *periods;

@end


/**
 An `AWFObservationSummaryPeriod` object represents data for a single period returned by the [**observations/summary** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/observations-summary/)
 of the Aeris Weather API.
 */
@interface AWFObservationSummaryPeriod : AWFWeatherObject

/**
 GMT date for the period.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Local timezone for the forecast period.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

/**
 Starting date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeStartDate;

/**
 Ending date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeEndDate;

//-----------------------------------------------------------------------------
// @name Weather & Clouds
//-----------------------------------------------------------------------------

/**
 Primary observed weather phrase for the period.
 */
@property (nonatomic, copy, nullable) NSString *weather;

/**
 Coded weather for the primary weather observed during the period.
 */
@property (nonatomic, copy, nullable) NSString *weatherCoded;

/**
 Full observed weather phrase for the period.
 */
@property (nonatomic, copy, nullable) NSString *weatherFull;

/**
 Full set of weather codes for the observed weather during the period.
 */
@property (nonatomic, strong, nullable) NSArray<AWFObservationWeatherCodedItem> *weatherFullCoded;

/**
 Total number of weather records for the period. If no weather other than sky conditions was reported, this value will be zero.
 */
@property (nonatomic, assign) NSInteger weatherCount;

/**
 Array of unique cloud codes that were observed during the period.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *cloudsCoded;

/**
 Weather icon representing the observed weather from the default icon set.
 */
@property (nonatomic, copy, nullable) NSString *icon;

/**
 Maximum sky cover during the period as a percentage.
 */
@property (nonatomic, assign) CGFloat maxSkyCoverPercentage;

/**
 Minimum sky cover during the period as a percentage.
 */
@property (nonatomic, assign) CGFloat minSkyCoverPercentage;

/**
 Average sky cover for the period as a percentage.
 */
@property (nonatomic, assign) CGFloat avgSkyCoverPercentage;

/**
 Total number of sky cover records for the period.
 */
@property (nonatomic, assign) NSInteger skyCoverPercentageCount;

//-----------------------------------------------------------------------------
// @name Temperatures
//-----------------------------------------------------------------------------

/**
 Maximum temperature observed during the period in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat maxTempF;

/**
 Maximum temperature observed during the period in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat maxTempC;

/**
 Minimum temperature observed during the period in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat minTempF;

/**
 Minimum temperature observed during the period in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat minTempC;

/**
 Average temperature for the period in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat avgTempF;

/**
 Average temperature observed during the period in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat avgTempC;

/**
 Total number of temperature records for the period.
 */
@property (nonatomic, assign) NSInteger tempCount;

//-----------------------------------------------------------------------------
// @name Dew Points
//-----------------------------------------------------------------------------

/**
 Maximum dew point temperature observed during the period in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat maxDewpointF;

/**
 Maximum dew point temperature observed during the period in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat maxDewpointC;

/**
 Minimum dew point temperature observed during the period in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat minDewpointF;

/**
 Minimum dew point temperature observed during the period in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat minDewpointC;

/**
 Average dew point temperature for the period in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat avgDewpointF;

/**
 Average dew point temperature for the period in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat avgDewpointC;

/**
 Total number of dew point temperature records for the period.
 */
@property (nonatomic, assign) NSInteger dewpointCount;

//-----------------------------------------------------------------------------
// @name Relative Humidity
//-----------------------------------------------------------------------------

/**
 Maximum relative humidity observed during the period as a percentage.
 */
@property (nonatomic, assign) CGFloat maxHumidity;

/**
 Minimum relative humidity observed during the period as a percentage.
 */
@property (nonatomic, assign) CGFloat minHumidity;

/**
 Average relative humidity for the period as a percentage.
 */
@property (nonatomic, assign) CGFloat avgHumidity;

/**
 Total number of relative humidity records for the period.
 */
@property (nonatomic, assign) NSInteger humidityCount;

//-----------------------------------------------------------------------------
// @name Precipitation
//-----------------------------------------------------------------------------

/**
 Total precipitation observed for the period in inches.
 */
@property (nonatomic, assign) CGFloat precipIN;

/**
 Total precipitation observed for the period in millimeters.
 */
@property (nonatomic, assign) CGFloat precipMM;

/**
 Total number of preciptiation records for the period.
 */
@property (nonatomic, assign) NSInteger precipCount;

//-----------------------------------------------------------------------------
// @name Winds
//-----------------------------------------------------------------------------

/**
 Maximum wind speed observed during the period in knots.
 */
@property (nonatomic, assign) CGFloat maxWindSpeedKTS;

/**
 Maximum wind speed observed during the period in miles per hour.
 */
@property (nonatomic, assign) CGFloat maxWindSpeedMPH;

/**
 Maximum wind speed observed during the period in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat maxWindSpeedKMH;

/**
 Minimum wind speed observed during the period in knots.
 */
@property (nonatomic, assign) CGFloat minWindSpeedKTS;

/**
 Minimum wind speed observed during the period in miles per hour.
 */
@property (nonatomic, assign) CGFloat minWindSpeedMPH;

/**
 Minimum wind speed observed during the period in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat minWindSpeedKMH;

/**
 Average wind speed for the period in knots.
 */
@property (nonatomic, assign) CGFloat avgWindSpeedKTS;

/**
 Average wind speed for the period in miles per hour.
 */
@property (nonatomic, assign) CGFloat avgWindSpeedMPH;

/**
 Average wind speed for the period in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat avgWindSpeedKMH;

/**
 Total number of wind speed records for the period.
 */
@property (nonatomic, assign) NSInteger windSpeedCount;

/**
 Maximum wind gust observed during the period in knots.
 */
@property (nonatomic, assign) CGFloat windGustKTS;

/**
 Maximum wind gust observed during the period in miles per hour.
 */
@property (nonatomic, assign) CGFloat windGustMPH;

/**
 Maximum wind gust observed during the period in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat windGustKMH;

//-----------------------------------------------------------------------------
// @name Barometric Pressure
//-----------------------------------------------------------------------------

/**
 Maximum barometric pressure observed during the period in inches of mercury.
 */
@property (nonatomic, assign) CGFloat maxPressureIN;

/**
 Maximum barometric pressure observed during the period in millibars.
 */
@property (nonatomic, assign) CGFloat maxPressureMB;

/**
 Minimum barometric pressure observed during the period in inches of mercury.
 */
@property (nonatomic, assign) CGFloat minPressureIN;

/**
 Minimum barometric pressure observed during the period in millibars.
 */
@property (nonatomic, assign) CGFloat minPressureMB;

/**
 Average barometric pressure for the period in inches of mercury.
 */
@property (nonatomic, assign) CGFloat avgPressureIN;

/**
 Average barometric pressure for the period in millibars.
 */
@property (nonatomic, assign) CGFloat avgPressureMB;

/**
 Total number of barometric pressure records for the period.
 */
@property (nonatomic, assign) NSInteger pressureCount;

//-----------------------------------------------------------------------------
// @name Visibility
//-----------------------------------------------------------------------------

/**
 Maximum visibility observed during the period in miles.
 */
@property (nonatomic, assign) CGFloat maxVisibilityMI;

/**
 Maximum visibility observed during the period in kilometers.
 */
@property (nonatomic, assign) CGFloat maxVisibilityKM;

/**
 Minimum visibility observed during the period in miles.
 */
@property (nonatomic, assign) CGFloat minVisibilityMI;

/**
 Minimum visibility observed during the period in kilometers.
 */
@property (nonatomic, assign) CGFloat minVisibilityKM;

/**
 Average visibility for the period in miles.
 */
@property (nonatomic, assign) CGFloat avgVisibilityMI;

/**
 Average visibility for the period in kilometers.
 */
@property (nonatomic, assign) CGFloat avgVisibilityKM;

/**
 Total number of visibility records for the period.
 */
@property (nonatomic, assign) NSInteger visibilityCount;

//-----------------------------------------------------------------------------
// @name Solar Radiation
//-----------------------------------------------------------------------------

/**
 Maximum solar radiation observed during the period in watts per square meter (not provided by all stations).
 */
@property (nonatomic, assign) CGFloat maxSolarRadiationKM2;

/**
 Minimun solar radiation observed during the period in watts per square meter (not provided by all stations).
 */
@property (nonatomic, assign) CGFloat minSolarRadiationKM2;

/**
 Average solar radiation for the period in watts per square meter (not provided by all stations).
 */
@property (nonatomic, assign) CGFloat avgSolarRadiationKM2;

/**
 Total number of solar radiation records for the period.
 */
@property (nonatomic, assign) NSInteger solarRadiationCount;

@end

NS_ASSUME_NONNULL_END
