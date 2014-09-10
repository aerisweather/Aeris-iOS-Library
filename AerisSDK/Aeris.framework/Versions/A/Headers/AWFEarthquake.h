//
//  AFEarthquake.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFEarthquake : AWFGeographicObject

//-----------------------------------------------------------------------------
// @name Location
//-----------------------------------------------------------------------------

/**
 *  USGS region in which the event occurred.
 */
@property (nonatomic, copy) NSString *region;

//-----------------------------------------------------------------------------
// @name Earthquake Details
//-----------------------------------------------------------------------------

/**
 *  USGS earthquake id.
 */
@property (nonatomic, copy) NSString *quakeId;

/**
 *  GMT date when the event took place.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Magnitude of the earthquake.
 */
@property (nonatomic, strong) NSNumber *magnitude;

/**
 *  Earthquake category based on magnitude.
 *
 *  mini:		0 - 2.9
 *  minor:		3 - 3.9
 *  light:		4 - 4.9
 *  moderate:	5 - 5.9
 *  strong:	6 - 6.9
 *  major:		7 -7.9
 *  great:		8+
 */
@property (nonatomic, copy) NSString *type;

/**
 *  Depth of the earthquake in kilometers.
 */
@property (nonatomic, strong) NSNumber *depthKM;

/**
 *  Depth of the earthquake in miles.
 */
@property (nonatomic, strong) NSNumber *depthMI;

@end