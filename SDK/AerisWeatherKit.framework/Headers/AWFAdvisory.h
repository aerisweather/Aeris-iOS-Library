//
//  AWFAdvisory.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisWeatherKit/AWFGeographicObject.h>

@class AWFGeoPolygon;

/**
 An `AWFAdvisory` object represents data returned by the [**advisories** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/advisories/)
 of the Aeris Weather API.
 */
@interface AWFAdvisory : AWFGeographicObject

/**
 Valid-time event code (VTEC) for the advisory.
 */
@property (nonatomic, copy, nullable) NSString *type;

/**
 Type name of the advisory.
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 Weather zone for the advisory.
 */
@property (nonatomic, copy, nullable) NSString *zone;

/**
 Shortened and formatted version of the advisory body text.
 */
@property (nonatomic, copy, nullable) NSString *body;

/**
 Complete, unmodified version of the advisory body text including raw headers.
 */
@property (nonatomic, copy, nullable) NSString *bodyFull;

/**
 GMT date when the advisory was issued.
 */
@property (nonatomic, strong, nullable) NSDate *issued;

/**
 GMT date when the advisory goes into effect.
 */
@property (nonatomic, strong, nullable) NSDate *begins;

/**
 GMT date when the advisory expires.
 */
@property (nonatomic, strong, nullable) NSDate *expires;

/**
 GMT date when the advisory was stored.
 */
@property (nonatomic, strong, nullable) NSDate *added;

/**
 A comma-delimited string of coordinates (longitude, latitude) defining the boundary for the advisory.
 *
 Typically this is only used for certain short-fuse advisories, such as tornado and severe thunderstorm warnings.
 */
@property (nonatomic, copy, nullable) NSString *polygon;

/**
 A `AWFGeoPolygon` instance created from the string of coordinates found in `polygon`, if any.
 */
@property (readonly, nonatomic, nullable) AWFGeoPolygon *geoPolygon;

/**
 Returns a dictionary of `UIColor` instances mapped to their respective advisory VTEC codes. This is the standard advisory color associations used by the
 National Weather Service (NWS) and those used with the advisory map overlay.
 */
+ (nonnull NSDictionary<NSString *, UIColor *> *)colorMappingsForTypes;

/**
 Returns a dictionary of advisory names mapped to their respective advisory VTEC codes.
 */
+ (nonnull NSDictionary<NSString *, NSString *> *)namesByType;

/**
 Returns the standard color associated with the specific advisory VTEC code.
 
 @param type The advisory VTEC code to return the color for
 @return A `UIColor` instance for the advisory type
 */
+ (nullable UIColor *)colorForAdvisoryWithType:(nonnull NSString *)type;

@end
