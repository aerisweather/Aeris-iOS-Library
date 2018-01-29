//
//  AWFMapURL.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFBaseMapStyle.h>
#import <AerisMapKit/AWFMapLayer.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFRasterMapLayer;

/**
 `AWFMapURL` is a the base class that is responsible for configuring a URL for interacting with the Aeris Maps Platform (AMP).
 */
@interface AWFMapURL : NSObject

/**
 An array of layers used for the URL.
 */
@property (nonatomic, readonly) NSArray<AWFRasterMapLayer *> *layers;

/**
 An array of layer types used in the URL.
 */
@property (nonatomic, readonly) NSArray<NSString *> *layerTypes;

/**
 The full URL path required for the map request for the specified layers and options.
 */
@property (nonatomic, readonly) NSString *URLPath;

/**
 The date and time for the map request.
 */
@property (nonatomic, strong) NSDate *date;

/**
 The timestamp string for the map's date in the format `YYYYMMddhhmmss`.
 */
@property (nonatomic, readonly) NSString *timestamp;

/**
 The offset string for the map's date relative to the current time (e.g. `-10minutes`, `+1hour`).
 */
@property (nonatomic, readonly) NSString *offset;

/**
 Initializes and returns a map image URL instance using the specified base map style.
 
 @param style The base map style to use for the map
 @return An `AWFMapImageURL` instance initialized with the base map style
 */
- (instancetype)initWithStyle:(AWFBaseMapStyle)style;

/**
 Initializes and returns a map image URL instance using the specified base map style and raster map layers.
 
 @param style The base map style to use for the map
 @param layers An array of raster layers to add to the map
 @return An `AWFMapImageURL` instance initialized with the base map style and raster layers
 */
- (instancetype)initWithStyle:(AWFBaseMapStyle)style layers:(nullable NSArray<AWFRasterMapLayer *> *)layers;

/**
 Adds a map layer to the request.
 */
- (void)addLayer:(AWFRasterMapLayer *)layer;

/**
 Adds an array of map layers to the request.
 */
- (void)addLayers:(NSArray<AWFRasterMapLayer *> *)layers;

/**
 Inserts a map layer to the request at the specified index relative to existing layers.
 */
- (void)insertLayer:(AWFRasterMapLayer *)layer atIndex:(NSInteger)index;

/**
 Inserts a map layer to the request on top of the specified existing layer. If `otherLayer` is not currently associated with the request,
 then the layer will be inserted at the top of the layer stack.
 */
- (void)insertLayer:(AWFRasterMapLayer *)layer aboveLayer:(AWFRasterMapLayer *)otherLayer;

/**
 Inserts a map layer to the request underneath the specified existing layer. If `otherLayer` is not currently associated with the request,
 then the layer will be inserted at the top of the layer stack.
 */
- (void)insertLayer:(AWFRasterMapLayer *)layer belowLayer:(AWFRasterMapLayer *)otherLayer;

/**
 Removes a map layer from the request.
 */
- (void)removeLayer:(AWFRasterMapLayer *)layer;

/**
 Removes an array of map layers from the request.
 */
- (void)removeLayers:(NSArray<AWFRasterMapLayer *> *)layers;

/**
 Removes all existing map layers from the request.
 */
- (void)removeAllLayers;

/**
 Returns the existing map layer for the specified raster layer type if it exists in the request.
 */
- (nullable AWFRasterMapLayer *)layerForRasterLayer:(AWFMapLayer)layerType;

/**
 Returns `YES` if the request has a layer for the specified raster layer type, otherwise `NO`.
 */
- (BOOL)hasLayerForRasterLayer:(AWFMapLayer)layerType;

@end

NS_ASSUME_NONNULL_END
