//
//  AWFWeatherLayer.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFMapContentType.h>
#import <AerisMapKit/AWFMapLayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `AWFLayerGroup` type defines the various groups a layer type can belong to.
 
 @note When using Swift, reference these values as their enumerated types instead of the Objective-C constants:
 `let group = AWFLayerGroup.raster`
 */
typedef NSString *AWFLayerGroup;

/**
 The raster data layer group.
 */
extern AWFLayerGroup const AWFLayerGroupRaster;

/**
 The point data layer group.
 */
extern AWFLayerGroup const AWFLayerGroupPoint;

/**
 The shape/polygon data layer group.
 */
extern AWFLayerGroup const AWFLayerGroupShape;

/**
 The future data layer group.
 */
extern AWFLayerGroup const AWFLayerGroupFuture;

/**
 The text data layer group.
 */
extern AWFLayerGroup const AWFLayerGroupText;

/**
 The base map layer group.
 */
extern AWFLayerGroup const AWFLayerGroupBase;

/**
 The map overlay layer group.
 */
extern AWFLayerGroup const AWFLayerGroupOverlay;

/**
 The layer mask group.
 */
extern AWFLayerGroup const AWFLayerGroupMask;

/**
 The `AWFWeatherLayer` class provides utility methods for working with layer types. This class is intended to be a static class and should not be
 instantiated as separate instances.
 */
@interface AWFWeatherLayer : NSObject

/**
 Returns a dictionary that maps each {@link AWFLayerType} to its display name.
 */
+ (NSDictionary *)names;

/**
 Returns the layer name for the specified layer type.

 @param layerType The layer type.
 @return The layer name for the code.
 */
+ (NSString *)nameForLayerType:(AWFMapLayer)layerType;

/**
 Returns the map content type for the specified layer type (e.g. tile, point, shape, etc).

 @param layerType The layer type to return the map content type for.
 @return The map content type for the layer type.
 */
+ (AWFMapContentType)contentTypeForLayerType:(AWFMapLayer)layerType;

/**
 Returns the layer types used to modify the specified layer type (e.g. different accumulated precipitation periods).

 @param layerType The layer type to the return the modifier layer types for.
 @return The modifier layer types, if any.
 */
+ (NSArray<AWFMapLayer> *)modifierLayersForLayerType:(AWFMapLayer)layerType;

/**
 Returns a dictionary of all of the supported layer types.
 
 The returned dictionary contains three objects, one for each data layer category (e.g. "tile", "point" and "polygon"). Each of these category objects contains an
 array of dictionarys, one for each layer type within the category, and includes the overlay's code, type and name:
 
 `{@"type": @(AWFLayerTypeRadar), @"code": @"radar", @"name": @"Radar"}`
 
 This dictionary of supported layer types is often used to dynamically generate menus or listings of the available overlays {@link AWFWeatherMap} supports.
 
 @return The dictionary of supported layer types.
 */
+ (NSDictionary *)layersByGroup;

/**
 Returns whether the specified layer type is a raster layer.
 */
+ (BOOL)isRaster:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type is a raster tile layer.
 */
+ (BOOL)isTile:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type is a point data layer.
 */
+ (BOOL)isPoint:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type is a shape/polygon layer.
 */
+ (BOOL)isShape:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type is a text layer.
 */
+ (BOOL)isLabel:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type is a base map layer.
 */
+ (BOOL)isBase:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type is a map overlay layer.
 */
+ (BOOL)isOverlay:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type is a surface data layer. A layer is considered surface data if it's raster data covers much of the map, such as
 temperatures or wind speeds.
 */
+ (BOOL)isSurfaceData:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type is an overlay mask layer.
 */
+ (BOOL)isMask:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type is an Aeris Maps (AMP) layer.
 */
+ (BOOL)isAmp:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type represents current data or data in the past.
 */
+ (BOOL)isPast:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type can also represent data in the past, such as surface temperatures or radar.
 */
+ (BOOL)hasPast:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type represents data in the future, such as future radar or forecast temperatures.
 */
+ (BOOL)isFuture:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type can also represent data in the future, such as radar/future radar.
 */
+ (BOOL)hasFuture:(AWFMapLayer)layerType;

/**
 Returns whether the specified layer type contains modifiers.
 */
+ (BOOL)hasModifiers:(AWFMapLayer)layerType;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
