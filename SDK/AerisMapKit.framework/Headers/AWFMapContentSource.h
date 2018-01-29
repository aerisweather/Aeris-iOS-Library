//
//  AWFOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFMapStrategy.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AWFMapContentDelegate;

/**
 An `AWFMapContentSource` object is the base class that represents an data source on a map. This base class should not be
 used directly. Instead, `AWFMapContentSource` subclasses should be used to provide the necessary functionality for that
 layer type.
 */
@interface AWFMapContentSource : NSObject

/**
 An identifier string for the layer. 
 
 A default identifier will be generated at initialization but can be overridden afterwards.
 */
@property (nonatomic, copy) NSString *identifier;

/**
 The layer type for the source.
 */
@property (nonatomic, assign, readonly) AWFMapLayer layerType;

/**
 The map strategy that is managing the layer.
 */
@property (nonatomic, strong, nullable) id<AWFMapStrategy> strategy;

/**
 The coordinate bounds currently covered by the layer.
 */
@property (nonatomic, strong, nullable) AWFMapCoordinateBounds *visibleBounds;

/**
 The receiver's delegate.
 */
@property (nonatomic, unsafe_unretained) id<AWFMapContentDelegate> delegate;

/**
 Initializes and returns the layer object and associates it with the specified layer type.
 
 @param layerType The layer type to associate the layer with
 @return An initialized layer instance
 */
- (instancetype)initWithLayerType:(AWFMapLayer)layerType;

/**
 Initializes and returns a layer object and associates it with the specified layer type and map strategy.

 @param layerType The layer type to associate the layer with
 @param strategy The map strategy object to use for managing the layer
 @return An initialized layer instance
 */
- (instancetype)initWithLayerType:(AWFMapLayer)layerType mapStrategy:(nullable id<AWFMapStrategy>)strategy;

//-----------------------------------------------------------------------------
// @name Class Methods
//-----------------------------------------------------------------------------

/**
 Returns the `AWFWeatherDataType` associated with the specified layer type.
 
 @param layerType The layer type
 @return The `AWFWeatherDataType` for the layer type, or `AWFWeatherDataTypeNone` if not specified
 */
+ (AWFWeatherDataType)weatherDataTypeForLayerType:(AWFMapLayer)layerType;

@end

/**
 The `AWFMapContentDelegate` protocol defines a set of optional methods that can be used to receive messages related to data changes for a particular
 map content source. The delegate should handle any data cleanup on the map that is required in response to these messages.
 */
@protocol AWFMapContentDelegate <NSObject>
@optional

/**
 Tells the delegate that the map source is about to request data for the layer with the specified options. This is called immediately before the request begins and allows you to
 override request options as needed.
 
 @param source The map content source that is about to perform the request
 @param options   The request options 
 */
- (void)contentSource:(AWFMapContentSource *)source willRequestDataWithOptions:(AWFWeatherRequestOptions *)options;

/**
 Tells the delegate that the map source will remove an array of annotation from the map. This is called before the `annotations` property on the map source will be reset with a new value.
 
 @param source   The map content source that will remove annotations
 @param annotations An array of annotations that will be removed
 */
- (void)contentSource:(AWFMapContentSource *)source willRemoveAnnotations:(NSArray<id<AWFAnnotation>> *)annotations;

/**
 Tells the delegate that the map source will remove an array of overlays from the map. This is called before the `overlays` property on the map source will be reset with a new value.
 
 @param source The map content source that will remove overlays
 @param overlays  An array of overlays that will be removed
 */
- (void)contentSource:(AWFMapContentSource *)source willRemoveOverlays:(NSArray *)overlays;

/**
 Tells the delegate that the map source needs to be invalidated.

 @param source The map content source that requested the invalidation.
 */
- (void)contentSourceNeedsInvalidating:(AWFMapContentSource *)source;

@end

NS_ASSUME_NONNULL_END
