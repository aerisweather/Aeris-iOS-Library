//
//  AWFPolygon.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/28/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFStylable.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFGeographicObject;
@class AWFPolygonStyle;

/**
 The `AWFPolygon` protocol defines the required properties and methods for polygon overlay objects for a specific mapping SDK.
 */
@protocol AWFPolygon <NSObject>
@required

/**
 The geometric centroid of the polygon.
 */
@property (nonatomic, assign) CLLocationCoordinate2D centroid;

/**
 The area of the polygon.
 */
@property (nonatomic, assign) CGFloat area;

/**
 Creates and returns a new polygon instance initialized with the `object`.
 
 This method must be implemented by a base class for each map strategy in order to create the proper polygon overlay instance 
 required by the strategy's map view.
 
 @param object The `AWFGeographicObject` instance to create a polygon from.
 @return An initialized polygon object.
 */
+ (instancetype)polygonWithGeographicObject:(AWFGeographicObject *)object;

/**
 Creates and returns a new polygon instance initialized with the `geoPolygon`.
 
 This method must be implemented by a base class for each map strategy in order to create the proper polygon overlay instance 
 required by the strategy's map view.
 
 @param geoPolygon The `AWFGeoPolygon` instance to create a polygon from
 @return An initialized polygon object
 */
+ (instancetype)polygonWithGeoPolygon:(AWFGeoPolygon *)geoPolygon;

/**
 Creates and returns a new polygon instance initialized with the `geoPolygon` and `object`.

 @param geoPolygon The `AWFGeoPolygon` instance to create a polygon from
 @param object The model object to associate with the polygon
 @return An initialized polygon object
 */
+ (instancetype)polygonWithGeoPolygon:(AWFGeoPolygon *)geoPolygon object:(nullable AWFWeatherObject *)object;

/**
 Creates and returns an empty polygon instance. This instance will not create a polygon overlay instance required for the map.
 
 @return An initialized empty polygon object.
 */
+ (instancetype)polygon;

@end

NS_ASSUME_NONNULL_END
