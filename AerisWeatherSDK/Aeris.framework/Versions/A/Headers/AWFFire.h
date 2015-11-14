//
// AFFire.h
// Aeris
//
// Created by Nicholas Shipes on 9/6/13.
// Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFFire : AWFGeographicObject

//-----------------------------------------------------------------------------
// @name Fire Profile
//-----------------------------------------------------------------------------

/**
 *  Unique identifier for the fire event.
 */
@property (nonatomic, copy) NSString *fireId;

/**
 *  GMT date for the observation.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Type of fire observation.
 *
 * "L" = Confirmed large fire as deteremined by the USFS
 * "M" = Fire detection by the MODIS satellite
 */
@property (nonatomic, copy) NSString *type;

/**
 *  Name assigned to the fire event.
 */
@property (nonatomic, copy) NSString *name;

/**
 *  Descriptive location of the fire.
 */
@property (nonatomic, copy) NSString *location;

/**
 *  GMT date when the fire started.
 *
 *  This property is usually only provided for critical/large fires (type="L"), but not always.
 */
@property (nonatomic, strong) NSDate *startDate;

/**
 *  The confidence percentage of the fire ranging from 0 to 100%.
 */
@property (nonatomic, strong) NSNumber *confidence;

/**
 *  Estimated coverage of the fire in square kilometers.
 */
@property (nonatomic, strong) NSNumber *areaKM;

/**
 *  Estimated coverage of the fire in square miles.
 */
@property (nonatomic, strong) NSNumber *areaMI;

/**
 *  Estimated coverage of the fire in acres.
 */
@property (nonatomic, strong) NSNumber *areaAC;

/**
 *  Percentage of the fire that is currently contained.
 *
 *  This property is usually only provided for critical/large fires (type="L"), but not always.
 */
@property (nonatomic, strong) NSNumber *percentContained;

//-----------------------------------------------------------------------------
// @name Satellite Detection
//-----------------------------------------------------------------------------

/**
 *  Satellite-estimated width of the fire in kilometers.
 */
@property (nonatomic, strong) NSNumber *satelliteWidthKM;

/**
 *  Satellite-estimated width of the fire in miles.
 */
@property (nonatomic, strong) NSNumber *satelliteWidthMI;

/**
 *  Satellite-estimated height of the fire in kilometers.
 */
@property (nonatomic, strong) NSNumber *satelliteHeightKM;

/**
 *  Satellite-estimated height of the fire in miles.
 */
@property (nonatomic, strong) NSNumber *satelliteHeightMI;

/**
 *  Measured brightness temperature of the detected fire in degrees Kelvin.
 */
@property (nonatomic, strong) NSNumber *satelliteTempK;

/**
 *  Measured brightness temperature of the detected fire in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *satelliteTempC;

/**
 *  Measured brightness temperature of the detected fire in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *satelliteTempF;

/**
 *  Station source of MODIS data and detection (for MODIS-detected fires only).
 *
 * "gsfc": NASA-Goddard Space Flight Center MODIS Rapid Response System
 * "rsac": USDA Forecast Serice Remote Sensing Application Center
 * "ssec": University of Wisconsin Space Science Engineering Center
 * "uaf": University of Alaska-Fairbanks
 */
@property (nonatomic, copy) NSString *satelliteSource;

/**
 *  Satellite source of MODIS data and detection (for MODIS-detected fires only).
 *
 * "T": TERRA MODIS
 * "A": AQUA MODIS
 */
@property (nonatomic, copy) NSString *satelliteCode;

@end