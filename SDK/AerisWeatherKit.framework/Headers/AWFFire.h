//
// AFFire.h
// Aeris
//
// Created by Nicholas Shipes on 9/6/13.
// Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

/**
 An `AWFFire` object represents data returned by the [**fires** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/fires/)
 of the Aeris Weather API.
 */
@interface AWFFire : AWFGeographicObject

//-----------------------------------------------------------------------------
// @name Fire Profile
//-----------------------------------------------------------------------------

/**
 Unique identifier for the fire event.
 */
@property (nonatomic, copy, nullable) NSString *fireId;

/**
 GMT date for the observation.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Type of fire observation.
 
 - "L" = Confirmed large fire as deteremined by the USFS
 - "M" = Fire detection by the MODIS satellite
 */
@property (nonatomic, copy, nullable) NSString *type;

/**
 Name assigned to the fire event.
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 Descriptive location of the fire.
 */
@property (nonatomic, copy, nullable) NSString *location;

/**
 GMT date when the fire started.
 
 This property is usually only provided for critical/large fires (type=`L`), but not always.
 */
@property (nonatomic, strong, nullable) NSDate *startDate;

/**
 The confidence percentage of the fire ranging from 0 to 100%.
 */
@property (nonatomic, assign) CGFloat confidence;

/**
 Estimated coverage of the fire in square kilometers.
 */
@property (nonatomic, assign) CGFloat areaKM;

/**
 Estimated coverage of the fire in square miles.
 */
@property (nonatomic, assign) CGFloat areaMI;

/**
 Estimated coverage of the fire in acres.
 */
@property (nonatomic, assign) CGFloat areaAC;

/**
 Percentage of the fire that is currently contained.
 
 This property is usually only provided for critical/large fires (type="L"), but not always.
 */
@property (nonatomic, assign) CGFloat percentContained;

//-----------------------------------------------------------------------------
// @name Satellite Detection
//-----------------------------------------------------------------------------

/**
 Satellite-estimated width of the fire in kilometers.
 */
@property (nonatomic, assign) CGFloat satelliteWidthKM;

/**
 Satellite-estimated width of the fire in miles.
 */
@property (nonatomic, assign) CGFloat satelliteWidthMI;

/**
 Satellite-estimated height of the fire in kilometers.
 */
@property (nonatomic, assign) CGFloat satelliteHeightKM;

/**
 Satellite-estimated height of the fire in miles.
 */
@property (nonatomic, assign) CGFloat satelliteHeightMI;

/**
 Measured brightness temperature of the detected fire in degrees Kelvin.
 */
@property (nonatomic, assign) CGFloat satelliteTempK;

/**
 Measured brightness temperature of the detected fire in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat satelliteTempC;

/**
 Measured brightness temperature of the detected fire in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat satelliteTempF;

/**
 Station source of MODIS data and detection (for MODIS-detected fires only).
 
 - `gsfc`: NASA-Goddard Space Flight Center MODIS Rapid Response System
 - `rsac`: USDA Forecast Serice Remote Sensing Application Center
 - `ssec`: University of Wisconsin Space Science Engineering Center
 - `uaf`: University of Alaska-Fairbanks
 */
@property (nonatomic, copy, nullable) NSString *satelliteSource;

/**
 Satellite source of MODIS data and detection (for MODIS-detected fires only).
 
 - `T`: TERRA MODIS
 - `A`: AQUA MODIS
 */
@property (nonatomic, copy, nullable) NSString *satelliteCode;

@end
