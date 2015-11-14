//
//  AWFPolygon.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/28/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

@class AWFGeographicObject;

/**
 *  The `AWFPolygon` protocol defines the required properties and methods for polygon overlay objects for a specific mapping SDK.
 */
@protocol AWFPolygon <NSObject>
@required

/**
 *  An identifier for the polygon, which is typically used for applying the necessary style.
 */
@property (nonatomic, copy) NSString *identifier;

/**
 *  The `AWFObject` instance associated with the polygon object.
 */
@property (readonly, nonatomic, strong) AWFObject *modelObject;

/**
 *  The overlay instance. The value of this property depends on the required object type expected by a given mapping SDK.
 */
@property (readonly, nonatomic, strong) id overlay;

@end

/**
 *  The `AWFPolygon` class is the base class for all polygon overlays on the weather map. This should not be used directly but should be subclassed for 
 *  each map strategy in order to provide the necessary overlay setup required by the mapping SDK.
 */
@interface AWFPolygon : NSObject

/**
 *  Creates and returns a new `AWFPolygon` instance initialized with the `object`. 
 *
 *  The default implementation of this method returns `nil`. This method must be overriden by a subclass for each map strategy in order to create the proper
 *  polygon overlay instance required by the strategy's map view.
 *
 *  @param object The `AWFGeographicObject` instance to create a polygon from.
 *
 *  @return An initialized polygon object.
 */
+ (instancetype)polygonWithGeographicObject:(AWFGeographicObject *)object;

/**
 *  Creates and returns a new `AWFPolygon` instance initialized with the `geoPolygon`.
 *
 *  The default implementation of this method returns `nil`. This method must be overriden by a subclass for each map strategy in order to create the proper
 *  polygon overlay instance required by the strategy's map view.
 *
 *  @param geoPolygon The `AWFGeoPolygon` instance to create a polygon from.
 *
 *  @return An initialized polygon object.
 */
+ (instancetype)polygonWithGeoPolygon:(AWFGeoPolygon *)geoPolygon;
+ (instancetype)polygonWithGeoPolygon:(AWFGeoPolygon *)geoPolygon object:(AWFObject *)object;

/**
 *  Creates and returns an empty `AWFPolygon` instance. This instance will not create a polygon overlay instance required for the map.
 *
 *  @return An initialized empty polygon object.
 */
+ (instancetype)polygon;

- (instancetype)initWithGeographicObject:(AWFGeographicObject *)object;
- (instancetype)initWithGeoPolygon:(AWFGeoPolygon *)geoPolygon object:(AWFObject *)object;

@end
