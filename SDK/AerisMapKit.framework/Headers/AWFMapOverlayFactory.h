//
//  AWFMapOverlayFactory.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/11/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFTileSource;

/**
 The `AWFMapOverlayFactory` protocol is adopted by an object that provides the necessary overlay and annotation objects required for rendering
 elements using a specific mapping strategy.
 */
@protocol AWFMapOverlayFactory <NSObject>

/**
 Returns an array of overlay objects for a series of `AWFGeographicObject` instances.

 @param objects An array of `AWFGeographicObject` instances to create overlays for
 @return An array of overlay objects
 */
- (NSArray *)overlaysFromObjects:(NSArray *)objects;

/**
 Returns an array of polygon overlay objects for a series of `AWFGeographicObject` instances. These objects must have a valid polygon string or `AWFGeoPolygon`
 instance in order for a polygon to be created for it.
 
 @param objects An array of `AWFGeographicObject` instances to create polygon overlays for
 @return An array of polygon objects
 */
- (NSArray *)polygonsFromObjects:(NSArray<AWFGeographicObject *> *)objects;

/**
 Returns an array of polygon overlay objects for a series of `AWFGeoPolygon` instances.
 
 @param geoPolygons An array of `AWFGeoPolygon` objects to create polygon overlays for
 @return An array of polygon objects
 */
- (NSArray *)polygonsFromGeoPolygons:(NSArray<AWFGeoPolygon *> *)geoPolygons;

/**
 Returns an array of polyline overlay objects for a series of `AWFGeoPolygon` instances.
 
 @param geoPolygons An array of `AWFGeoPolygon` objects to create polyline overlays for
 @return An array of polyline objects
 */
- (NSArray *)polylinesFromGeoPolygons:(NSArray<AWFGeoPolygon *> *)geoPolygons;

/**
 Returns a single overlay object that conforms to the `AWFMultiShapeOverlay` protocol for managing and rendering multiple polygons and polylines into
 a single overlay renderer.
 
 @param polygons  An array of polygons to add to the overlay.
 @param polylines An array of polylines to add to the overlay.
 @return The multi-shape overlay instance
 */
- (id)combinedOverlayForPolygons:(NSArray *)polygons polylines:(NSArray *)polylines;

/**
 Iterates through an array of polygon objects and returns an array of polygon overlays that the strategy's map view requires when adding to the map. This
 method will pull out the overlay instances stored within `AWFPolygon` and `AWFPolyline` objects in order to add them to the map view.
 
 @param polygons An array of polygon objects.
 @return An array of polygon overlay instances that can be added to the map view.
 */
- (NSArray *)reducePolygonsToMapPolygons:(NSArray *)polygons;

/**
 Returns a tile data layer initialized with the `URLTemplate` to use for tile URLs.
 
 @param URLTemplate The template for generating tile URLs
 @return An initialized tile data source object
 */
- (AWFTileSource *)tileOverlayWithURLTemplate:(NSString *)URLTemplate;

/**
 Returns a tile source initialized with the `URLTemplate` to use for tile URLs.

 @param URLTemplate The template for generating tile URLs
 @param isAmp Whether or not the returned source should be an AMP tile source
 @return An initialized tile data source object
 */
- (AWFTileSource *)tileOverlayWithURLTemplate:(NSString *)URLTemplate isAmp:(BOOL)isAmp;

/**
 Returns an array of annotation objects for a series of `AWFGeographicObject` instances. These objects must have a valid coordinate in order for an
 annotation to be created for it.
 
 @param objects An array of `AWFGeographicObject` instances to create annotations for
 @return An array of annotation objects
 */
- (NSArray *)annotationsFromObjects:(NSArray<AWFGeographicObject *> *)objects;

/**
 Returns an array of text annotation objects for a series of `AWFGeographicObject` instances. These objects must have a valid coordinate in order for an
 annotation to be created for it.
 
 @param objects An array of `AWFGeographicObject` instances to create annotations for
 @return An array of annotation objects
 */
- (NSArray *)textAnnotationsFromObjects:(NSArray<AWFGeographicObject *> *)objects;

@end

NS_ASSUME_NONNULL_END
