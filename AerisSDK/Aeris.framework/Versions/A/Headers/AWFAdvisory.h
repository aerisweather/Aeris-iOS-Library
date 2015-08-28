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
@property (readonly, nonatomic) AWFGeoPolygon *geoPolygon;

+ (NSDictionary *)colorMappingsForTypes;
+ (NSDictionary *)namesByType;

+ (UIColor *)colorForAdvisoryWithType:(NSString *)type;

@end