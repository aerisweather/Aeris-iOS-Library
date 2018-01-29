//
//  AWFMapArrow.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 11/22/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <AerisWeatherKit/AerisWeatherKit.h>

/**
 The `AWFMapArrow` protocol defines the required properties and methods for an object that defines a directional arrow element on a map.
 */
@protocol AWFMapArrow

/**
 The starting coordinate for the arrow.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

/**
 The coordinate bounds containing the arrow.
 */
@property (nonatomic, readonly) AWFCoordinateBounds *bounds;

/**
 Initializes and returns a newly allocated arrow object with the specified array of coordinates and point count.

 @param coord The array of coordinates that define the arrow path.
 @param count The number of points included in the coordinate array.
 @return An initialized arrow object.
 */
+ (instancetype)arrowWithCoordinates:(CLLocationCoordinate2D *)coord count:(NSUInteger)count;

/**
 Initializes and returns a newly allocated arrow object with the specified array of map points and point count.

 @param points The array of map points that define the arrow path.
 @param count The number of points included in the point array.
 @return An initialized arrow object.
 */
+ (instancetype)arrowWithPoints:(MKMapPoint *)points count:(NSUInteger)count;

@end
