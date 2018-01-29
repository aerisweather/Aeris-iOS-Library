//
//  AFGeoPolygon.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>
#import <AerisCore/AerisCore.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSArray<NSNumber *> *AWFGeoPolygonCoordValue;

/**
 An `AWFGeoPolygon` object manages a series of coordinates that define a region or polygon that is used when requesting data from the API or rendering 
 API data on a map.
 */
@interface AWFGeoPolygon : NSObject <NSCoding>

/**
 Returns the array of coordinates as instances of `NSValue` that comprises the polygon bounds.
 */
@property (readonly, nonatomic, strong) NSArray<NSValue *> *coordinates;

/**
 Returns an array of coordinate values that defines the polygon bounds. The value of this property is typically passed to overlay rendering methods when
 drawing the polygon on a map, such as `MKPolyline` or `MKPolygon`.
 */
@property (readonly, nonatomic) CLLocationCoordinate2D *coords;

/**
 Returns the bounding box that encloses the polygon.
 @see AWFCoordinateRect
 */
@property (nonatomic, readonly) AWFCoordinateRect boundingBox;

/**
 Returns the coordinate at the midpoint of the overall polygon bounds.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D centerCoordinate;

/**
 Calculates the centroid of the polygon, which is the average of the coordinate sums from all coordinates.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D centroid;

/**
 Calculates the approximate area of the polygon when the polygon is closed in square meters.
 
 This method is only an approximation and can be inaccurate for large regions because the Earth's curvature is not
 accounted for in the area calculation.
 */
@property (nonatomic, readonly) CGFloat area;

/**
 An array of `AWFGeoPolygon` instances that are cut out from the polygon when rendering on a map.
 */
@property (nonatomic, strong, nullable) NSArray<AWFGeoPolygon *> *interiorPolygons;

/**
 Initializes and returns a polygon object defined by the array of coordinates and their order.
 
 @param coordinates The array of `CLLocationCoordinate2D` values.
 @return The initialized polygon instance.
 */
- (instancetype)initWithArrayOfCoordinates:(NSArray<NSValue *> *)coordinates;

/**
 Initializes and returns a polygon object defined by an array of coordinate values.
 
 Each item in the array should be an array that provides the latitude and longitude values, e.g. `@[@(47.61), @(-122.33)]`.
 
 @param points The array of latitude, longitude arrays.
 @return The initialized polygon instance.
 */
- (instancetype)initWithArrayOfPoints:(NSArray<AWFGeoPolygonCoordValue> *)points;

/**
 Initializes and returns a polygon object defined by an array of coordinate values.
 
 Each item in the array should be an array that provides the latitude and longitude values, e.g. `@[@(47.61), @(-122.33)]`.

 @param points The array of coordinate values containing the latitude and longitude values
 @param startsWithLongitude Whether or not the first value in each coordinate array represents the longitude value. Default is `NO`.
 @return The initialized polygon instance
 */
- (instancetype)initWithArrayOfPoints:(NSArray<AWFGeoPolygonCoordValue> *)points startingWithLongitude:(BOOL)startsWithLongitude;

/**
 Initializes and returns a polygon object defined by the polygon string.
 
 The provided string should be a series of latitude and longitude coordinate points, e.g.
 '@"30.844648845745,-95.62972672269,30.473950476293,-95.489974064209,..."'.
 
 @param polygonString The polygon string that provides the list of latitude and longitude coordinates.
 @return The initialized polygon instance.
 */
- (instancetype)initWithPolygonString:(NSString *)polygonString;

//-----------------------------------------------------------------------------
// @name Managing Coordinates
//-----------------------------------------------------------------------------

/**
 Appends a new coordinate value to the end of the existing polygon. If no coordinates already exist, the specified coordinate will be the starting
 coordinate point.
 
 @param coordinate The coordinate to add.
 */
- (void)addCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 Inserts a new coordinate value at a specific index within the array of coordinates that defines the polygon. If the specified index is greater
 than the total number of coordinates, it will be appended to the end of the coordinates array.
 
 @param coordinate The coordinate to insert.
 @param index      The index in which to insert the coordinate.
 */
- (void)insertCoordinate:(CLLocationCoordinate2D)coordinate atIndex:(NSUInteger)index;

/**
 Removes all coordinate values from the polygon.
 */
- (void)removeAllCoordinates;

/**
 Returns a string representation of the polygon as a series of latitude and longitude values, e.g.
 '@"30.844648845745,-95.62972672269,30.473950476293,-95.489974064209,..."'.
 */
- (NSString *)polygonAsString;

/**
 Determines whether or not the specified coordinate falls within the polygon's bounds.
 
 @param coord The coordinate to determine if it's within the polygon.
 @return `YES` if the polygon contains the coordinate, otherwise `NO`.
 */
- (BOOL)containsCoordinate:(CLLocationCoordinate2D)coord;

/**
 Returns an array of `AWFGeoPolygon` instances generated from the specified GeoJSON dictionary data.
 
 Note that the provided GeoJSON data must follow the GeoJSON spec: http://geojson.org/geojson-spec.html#polygon

 @param geoJSON The GeoJSON data to generate polygon instances from
 @return An array of polygon instances based on the GeoJSON data
 */
+ (nullable NSArray<AWFGeoPolygon *> *)polygonsFromGeoJSON:(NSDictionary *)geoJSON;

@end

NS_ASSUME_NONNULL_END
