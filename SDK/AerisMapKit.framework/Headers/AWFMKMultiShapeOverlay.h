//
//  AWFMultiShapeOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/15/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFWeatherLayer.h>
#import <AerisMapKit/AWFStyledMapItem.h>
#import <AerisMapKit/AWFMultiShapeOverlay.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFMKMultiShapeOverlay` object is a data object that contains the information needed to render multiple polygons and polylines 
 in a map view's area.
 */
@interface AWFMKMultiShapeOverlay : NSObject <MKOverlay, AWFStyledMapItem, AWFMultiShapeOverlay>

/**
 The group identifier for the map item. This controls which style is used when multiple styles are available for a single data layer type.
 */
@property (nonatomic, copy, nullable) NSString *identifier;

/**
 The style associated with the overlay.
 */
@property (nonatomic, strong, nullable) AWFMapItemStyle *style;

/**
 The layer type this map item belongs to.
 */
@property (nonatomic) AWFMapLayer layerType;

/**
 The complete list of polygons associated with the overlay.
 */
@property (nonatomic, strong, nullable) NSArray<MKPolygon *> *polygons;

/**
 The complete list of polylines associated with the overlay.
 */
@property (nonatomic, strong, nullable) NSArray<MKPolyline *> *polylines;

/**
 The approximate center point of the overlay area.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

/**
 The projected rectangle that encompasses the overlay.
 */
@property (nonatomic, readonly) MKMapRect boundingMapRect;

/**
 Creates and returns an `AWFMKMultiShapeOverlay` from the specified polygons and polylines.

 @param polygons The array of polygons
 @param polylines The array of polylines
 @return A new overlay object
 */
- (instancetype)initWithPolygons:(nullable NSArray<MKPolygon *> *)polygons polylines:(nullable NSArray<MKPolyline *> *)polylines;

/**
 Updates the polygons and polylines associated with the overlay.

 @param polygons The array of polygons
 @param polylines The array of polylines
 */
- (void)updatePolygons:(nullable NSArray<MKPolygon *> *)polygons polylines:(nullable NSArray<MKPolyline *> *)polylines;

@end

NS_ASSUME_NONNULL_END
