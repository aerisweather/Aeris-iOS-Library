//
//  AWFAmpTileSourceProvider.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/15/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AWFAmpTileSourceProviderDelegate;
@class AWFWeatherMap, AWFMapTileURL, AWFAmpTileSource, AWFRasterMapLayer;

/**
 An `AWFAmpTileSourceProvider` instance is responsible for managing all raster and text layers and layer options for the Aeris Maps Platform (AMP).
 */
@interface AWFAmpTileSourceProvider : NSObject

/**
 The current timestamp to use for image requests.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 The tile data layer used for managing past and current imagery.
 */
@property (nonatomic, strong, readonly) AWFAmpTileSource *tileLayer;

/**
 The tile data layer used for managing past and current text imagery.
 */
@property (nonatomic, strong, readonly) AWFAmpTileSource *textTileLayer;

/**
 The tile data layer used for managing future imagery.
 */
@property (nonatomic, strong, readonly) AWFAmpTileSource *futureTileLayer;

/**
 The tile data layer used for managing future text imager.
 */
@property (nonatomic, strong, readonly) AWFAmpTileSource *futureTextTileLayer;

/**
 The object that acts as the delegate of the tile source provider.
 
 The delegate must adopt the `AWFAmpTileSourceProviderDelegate` protocol.
 */
@property (nonatomic, unsafe_unretained) id<AWFAmpTileSourceProviderDelegate> delegate;

/**
 Initializes and returns a newly allocated provider with the specified weather map.

 @param weatherMap The weather map associated with the provider.
 @return An allocated provider.
 */
- (instancetype)initWithWeatherMap:(AWFWeatherMap *)weatherMap;
- (instancetype)init NS_UNAVAILABLE;

/**
 Adds a new raster map layer at the top of the layer stack.

 @param layer The raster layer to add.
 */
- (void)addRasterLayer:(AWFRasterMapLayer *)layer;

/**
 Adds a new raster map layer at the specified index.
 
 If the specified index is greater than the total number of active layers, then the layer will be added to the top of the layer stack.

 @param layer The raster layer to add.
 @param index The index into which to insert the layer.
 */
- (void)addRasterLayer:(AWFRasterMapLayer *)layer atIndex:(NSInteger)index;

/**
 Removes a raster map layer.

 @param layer The raster layer to remove.
 */
- (void)removeRasterLayer:(AWFRasterMapLayer *)layer;

/**
 Returns whether the provider contains the specified layer type.

 @param layerType The layer type to search for.
 @return `YES` if the provider contains the layer type, otherwise `NO`.
 */
- (BOOL)containsLayerType:(AWFMapLayer)layerType;

/**
 Returns the raster map layer instance for the specified layer type.
 
 If the provider does not contain the layer type, then `nil` will be returned.

 @param layerType The layer type to return the raster map layer for.
 @return The raster map layer if it exists, otherwise `nil`.
 */
- (nullable AWFRasterMapLayer *)rasterLayerForLayerType:(AWFMapLayer)layerType;

/**
 Adds a text map layer at the top of the layer stack.

 @param layer The text layer to add.
 */
- (void)addTextLayer:(AWFRasterMapLayer *)layer;

/**
 Adds a text map layer for the specified raster layer.
 
 @note Not all raster layers support text layers. If the provided raster layer does not contain a text layer, this method will not add a new layer to the provider.

 @param layer The layer to add a new text layer for.
 */
- (void)addTextLayerForRasterLayer:(AWFRasterMapLayer *)layer;

/**
 Removes a text map layer.

 @param layer The text map layer to remove.
 */
- (void)removeTextLayer:(AWFRasterMapLayer *)layer;

/**
 Removes the text map layer associated with the specified raster map layer, if any.

 @param layer The raster map layer to remove the text layer for.
 */
- (void)removeTextLayerForRasterLayer:(AWFRasterMapLayer *)layer;

/**
 Returns the text map layer instance for the specified layer type.
 
 If the provider does not contain the layer type or a text map layer for the layer type, then `nil` will be returned.

 @param layerType The layer type to return the text map layer for.
 @return The text map layer if it exists, otherwise `nil`.
 */
- (nullable AWFRasterMapLayer *)textLayerForLayerType:(AWFMapLayer)layerType;

/**
 Updates the current date and time for all layers.

 @param date The new date to use.
 */
- (void)updateLayersForDate:(NSDate *)date;

@end


/**
 The `AWFAmpTileSourceProviderDelegate` protocol defines a set of optional methods that can be used to receive messages from the provider when tile sources
 should be added and/or removed from the weather map.
 */
@protocol AWFAmpTileSourceProviderDelegate <NSObject>
@optional

/**
 Tells the delegate that the tile source should be added to the weather map.

 @param provider The provider requesting the addition.
 @param source The source that should be added to the map.
 */
- (void)ampSourceProvider:(AWFAmpTileSourceProvider *)provider needsSourceAddedToMap:(AWFTileSource *)source;

/**
 Tells the delegate that the tile source should be removed from the weather map.

 @param provider The provider requesting the removal.
 @param source The source that should be removed from the map.
 */
- (void)ampSourceProvider:(AWFAmpTileSourceProvider *)provider needsSourceRemovedFromMap:(AWFTileSource *)source;

@end

NS_ASSUME_NONNULL_END
