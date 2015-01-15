//
//  AWFPolyline.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/15/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AWFGeographicObject;

/**
 *  The `AWFPolyline` protocol defines the required properties and methods for polyline overlay objects for a specific mapping SDK.
 */
@protocol AWFPolyline <NSObject>
@required

/**
 *  The overlay instance. The value of this property depends on the required object type expected by a given mapping SDK.
 */
@property (readonly, nonatomic, strong) id overlay;

@end

@interface AWFPolyline : NSObject

/**
 *  Creates and returns a new `AWFPolyline` instance initialized with the `geoPolygon`.
 *
 *  The default implementation of this method returns `nil`. This method must be overriden by a subclass for each map strategy in order to create the proper
 *  polyline overlay instance required by the strategy's map view.
 *
 *  @param geoPolygon The `AWFGeoPolygon` instance to create a polyline from.
 *
 *  @return An initialized polyline object.
 */
+ (instancetype)polylineWithGeoPolygon:(AWFGeoPolygon *)geoPolygon;

/**
 *  Creates and returns an empty `AWFPolyline` instance. This instance will not create a polyline overlay instance required for the map.
 *
 *  @return An initialized empty polyline object.
 */
+ (instancetype)polyline;

@end
