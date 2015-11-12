//
//  AFGeoPolygon.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>

#import <Aeris/CLLocation+Aeris.h>

//#import "AWFCoordinateBounds.h"

@interface AWFGeoPolygon : NSObject <NSCoding>

/**
 *  Returns the array of coordinates that comprises the polygon bounds.
 */
@property (readonly, nonatomic, strong) NSArray *coordinates;

/**
 *  Returns the bounding box that encloses the polygon.
 *	@see AWFCoordinateRect
 */
@property (nonatomic, readonly) AWFCoordinateRect boundingBox;

/**
 *  Returns the coordinate at the midpoint of the overall polygon bounds.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D centerCoordinate;

/**
 *  Calculates the centroid of the polygon, which is the average of the coordinate sums from all coordinates.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D centroid;

/**
 *  Calculates the approximate area of the polygon when the polygon is closed in square meters.
 *
 *	This method is only an approximation and can be inaccurate for large regions because the Earth's curvature is not
 *  accounted for in the area calculation.
 */
@property (nonatomic, readonly) CGFloat area;

@property (nonatomic, strong) NSArray *interiorPolygons;

/**
 *  Initializes and returns a polygon object defined by the array of coordinate values and their order.
 *
 *  @param coordinates The array of `CLLocationCoordinate2D` values.
 *
 *  @return The initialized polygon instance.
 */
- (instancetype)initWithArrayOfCoordinates:(NSArray *)coordinates;

/**
 *  Initializes and returns a polygon object defined by an array of latitude, longitude array instances.
 *
 *  Each item in the array should be an array that provides the latitude and longitude values, e.g. `@[@(47.61), @(-122.33)]`.
 *
 *  @param points The array of latitude, longitude arrays.
 *
 *  @return The initialized polygon instance.
 */
- (instancetype)initWithArrayOfPoints:(NSArray *)points;
- (instancetype)initWithArrayOfPoints:(NSArray *)points startingWithLongitude:(BOOL)startsWithLongitude;

/**
 *  Initializes and returns a polygon object defined by the polygon string.
 *
 *  The provided string should be a series of latitude and longitude coordinate points, e.g.
 *  '@"30.844648845745,-95.62972672269,30.473950476293,-95.489974064209,..."'.
 *
 *  @param polygonString The polygon string that provides the list of latitude and longitude coordinates.
 *
 *  @return The initialized polygon instance.
 */
- (instancetype)initWithPolygonString:(NSString *)polygonString;

/**
 *  Appends a new coordinate value to the end of the existing polygon. If no coordinates already exist, the specified coordinate will be the starting
 *  coordinate point.
 *
 *  @param coordinate The coordinate to add.
 */
- (void)addCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 *  Inserts a new coordinate value at a specific index within the array of coordinates that defines the polygon. If the specified index is greater
 *  than the total number of coordinates, it will be appended to the end of the coordinates array.
 *
 *  @param coordinate The coordinate to insert.
 *  @param index      The index in which to insert the coordinate.
 */
- (void)insertCoordinate:(CLLocationCoordinate2D)coordinate atIndex:(NSUInteger)index;

/**
 *  Removes all coordinate values from the polygon.
 */
- (void)removeAllCoordinates;

/**
 *  Returns a string representation of the polygon as a series of latitude and longitude values, e.g.
 *  '@"30.844648845745,-95.62972672269,30.473950476293,-95.489974064209,..."'.
 */
- (NSString *)polygonAsString;

/**
 *  Determines whether or not the specified coordinate falls within the polygon's bounds.
 *
 *  @param coord The coordinate to determine if it's within the polygon.
 *
 *  @return `YES` if the polygon contains the coordinate, otherwise `NO`.
 */
- (BOOL)containsCoordinate:(CLLocationCoordinate2D)coord;

+ (NSArray *)polygonsFromGeoJSON:(NSDictionary *)geoJSON;

@end