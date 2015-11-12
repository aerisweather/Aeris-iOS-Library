//
//  AWFAdvisory.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@class AWFGeoPolygon;

@interface AWFAdvisory : AWFGeographicObject

/**
 *  Valid-time event code (VTEC) for the advisory.
 */
@property (nonatomic, copy) NSString *type;

/**
 *  Type name of the advisory.
 */
@property (nonatomic, copy) NSString *name;

/**
 *  Weather zone for the advisory.
 */
@property (nonatomic, copy) NSString *zone;

/**
 *  Shortened and formatted version of the advisory body text.
 */
@property (nonatomic, copy) NSString *body;

/**
 *  Complete, unmodified version of the advisory body text including raw headers.
 */
@property (nonatomic, copy) NSString *bodyFull;

/**
 *  GMT date when the advisory was issued.
 */
@property (nonatomic, strong) NSDate *issued;

/**
 *  GMT date when the advisory goes into effect.
 */
@property (nonatomic, strong) NSDate *begins;

/**
 *  GMT date when the advisory expires.
 */
@property (nonatomic, strong) NSDate *expires;

/**
 *  GMT date when the advisory was stored.
 */
@property (nonatomic, strong) NSDate *added;

/**
 *  A comma-delimited string of coordinates (longitude, latitude) defining the boundary for the advisory.
 *
 *  Typically this is only used for certain short-fuse advisories, such as tornado and severe thunderstorm warnings.
 */
@property (nonatomic, copy) NSString *polygon;

/**
 *  A `AWFGeoPolygon` instance created from the string of coordinates found in `polygon`, if any.
 */
@property (readonly, nonatomic) AWFGeoPolygon *geoPolygon;

/**
 *  Returns a dictionary of `UIColor` instances mapped to their respective advisory VTEC codes. This is the standard advisory color associations used by the
 *  National Weather Service (NWS) and those used with the advisory map overlay.
 */
+ (NSDictionary *)colorMappingsForTypes;

/**
 *  Returns a dictionary of advisory names mapped to their respective advisory VTEC codes.
 */
+ (NSDictionary *)namesByType;

/**
 *  Returns the standard color associated with the specific advisory VTEC code.
 *
 *  @param type The advisory VTEC code to return the color for
 *
 *  @return A `UIColor` instance for the advisory type
 */
+ (UIColor *)colorForAdvisoryWithType:(NSString *)type;

@end