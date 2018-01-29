//
//  AFEarthquake.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

/**
 An `AWFEarthquake` object that represents data returned by the [**earthquakes** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/earthquakes/)
 of the Aeris Weather API.
 */
@interface AWFEarthquake : AWFGeographicObject

//-----------------------------------------------------------------------------
// @name Location
//-----------------------------------------------------------------------------

/**
 USGS region in which the event occurred.
 */
@property (nonatomic, copy, nullable) NSString *region;

//-----------------------------------------------------------------------------
// @name Earthquake Details
//-----------------------------------------------------------------------------

/**
 USGS earthquake id.
 */
@property (nonatomic, copy, nullable) NSString *quakeId;

/**
 GMT date when the event took place.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Magnitude of the earthquake.
 */
@property (nonatomic, assign) CGFloat magnitude;

/**
 Earthquake category based on magnitude.
 
 - mini:		0 - 2.9
 - minor:		3 - 3.9
 - light:		4 - 4.9
 - moderate:	5 - 5.9
 - strong:	6 - 6.9
 - major:		7 -7.9
 - great:		8+
 */
@property (nonatomic, copy, nullable) NSString *type;

/**
 Depth of the earthquake in kilometers.
 */
@property (nonatomic, assign) CGFloat depthKM;

/**
 Depth of the earthquake in miles.
 */
@property (nonatomic, assign) CGFloat depthMI;

@end
