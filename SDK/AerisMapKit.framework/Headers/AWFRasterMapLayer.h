//
//  AWFRasterMapLayer.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFMapLayer.h>
#import <AerisMapKit/AWFRasterBlendMode.h>
#import <AerisMapKit/AWFRasterMask.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFRasterMapLayerFilter;

/**
 An `AWFRasterMapLayer` object represents and manages a single Aeris Maps (AMP) raster layer for a weather map.
 */
@interface AWFRasterMapLayer : NSObject

/**
 The raster layer type to use for the layer.
 */
@property (nonatomic, readonly) AWFMapLayer layerType;

/**
 The blend mode to apply to the layer.
 */
@property (nonatomic) AWFRasterBlendMode blendMode;

/**
 The forecast model type to use for the layer if it's intended to be a future or forecast layer.
 */
@property (nonatomic) AWFForecastModelType forecastModel;

/**
 The opacity of the layer.
 */
@property (nonatomic, assign) CGFloat alpha;

/**
 The amount to blur the layer, which is a value from `0` meaning no blur (default) to `10`. The higher the value, the greater the blur effect.
 */
@property (nonatomic, assign) CGFloat blurAmount;

/**
 The mask to apply to the layer.
 */
@property (nonatomic) AWFRasterMask mask;

/**
 
 */
@property (nonatomic, strong, readonly) NSArray<AWFRasterMapLayerFilter *> *filters;

/**
 A Boolean value indicating if this layer should use the dark style. This property is used specifically for text and overlay layers, such as data text
 and administrative overlay layers.
 */
@property (nonatomic, assign, getter=isDarkStyle) BOOL darkStyle;

/**
 A Boolean value indicating if this layer should display the text information for the layer type.
 
 @note Not all layer types support text layers. Refer to the [Aeris Maps Layers documetation](https://www.aerisweather.com/support/docs/aeris-maps/reference/map-layers/)
 for more information regarding the supported layers.
 */
@property (nonatomic, assign, getter=isTextLayer) BOOL textLayer;

/**
 A Boolean value indicating if this layer should use large text. This property is used only for text-specific layer types or layers where `isTextLayer` is
 `YES`.
 */
@property (nonatomic, assign, getter=isLargeText) BOOL largeText;

/**
 A Boolean value indicating if this layer should display Metric values. This property is used only for text-specific layer types or layers where
 `isTextLayer` is `YES`.
 */
@property (nonatomic, assign, getter=isMetric) BOOL metric;
@property (nonatomic, assign) BOOL includeTextData;

/**
 The Aeris Maps (AMP) string for this layer.
 */
@property (nonatomic, readonly, nullable) NSString *valueString;

/**
 Initializes and returns a newly allocated raster layer with the specified layer type.

 @param layerType The layer type for the raster layer.
 @return An initialized raster layer object.
 */
- (instancetype)initWithLayerType:(AWFMapLayer)layerType;

/**
 Initializes and returns a newly allocated raster layer with the specified AMP layer key.

 @param layerKey The AMP layer key for the raster layer.
 @return An initialized raster layer object.
 */
- (instancetype)initWithLayerKey:(NSString *)layerKey;

/**
 Initializes and returns a newly allocated raster layer with the specified layer type and forecast model.
 
 @note The forecast model value will only be used if the specified layer type corresponds to a future layer or supports future data.

 @param layerType The layer type for the raster layer.
 @param forecastModel The forecast model to use for the layer.
 @return An initialized raster layer object.
 */
- (instancetype)initWithLayerType:(AWFMapLayer)layerType forecastModel:(AWFForecastModelType)forecastModel;
- (instancetype)init NS_UNAVAILABLE;

/**
 Initializes and returns a newly allocated raster layer with the specified layer type.
 
 @param layerType The layer type for the raster layer.
 @return An initialized raster layer object.
 */
+ (instancetype)layerWithLayerType:(AWFMapLayer)layerType;

/**
 Initializes and returns a newly allocated raster layer with the specified layer type and forecast model.
 
 @note The forecast model value will only be used if the specified layer type corresponds to a future layer or supports future data.
 
 @param layerType The layer type for the raster layer.
 @param forecastModel The forecast model to use for the layer.
 @return An initialized raster layer object.
 */
+ (instancetype)layerWithLayerType:(AWFMapLayer)layerType forecastModel:(AWFForecastModelType)forecastModel;

/**
 Adds a filter to the raster layer.

 @param filter The filter to add.
 */
- (void)addFilter:(AWFRasterMapLayerFilter *)filter;

/**
 Removes a filter from the layer.

 @param filter The filter to remove.
 */
- (void)removeFilter:(AWFRasterMapLayerFilter *)filter;

//-----------------------------------------------------------------------------
// @name Class Utility Methods
//-----------------------------------------------------------------------------

/**
 Returns a dictionary containing the default titles for all supported raster layers.
 */
+ (NSDictionary<AWFMapLayer, NSString *> *)layerTitles;

/**
 Returns whether or not the future raster layer requires a forecast model.

 @param layer The future raster layer.
 */
+ (BOOL)futureLayerRequiresModel:(AWFMapLayer)layer;

///**
// Returns the future raster layer type for the specified layer type and forecast model.
// 
// If the specified `layerType` does not contain a corresponding future layer type or does not have a future layer type for the specified
// forecast model, then `nil` will be returned.
// 
// @param layerType The raster layer type to use
// @param forecastModel The forecast model type to use
// @return The future raster layer type for the layer type, otherwise `nil`.
// */
//+ (nullable AWFMapLayer)futureMapLayerTypeForLayerType:(AWFMapLayer)layerType forecastModel:(AWFForecastModelType)forecastModel;
//
///**
// Returns the base raster layer type for the specified future layer type.
// 
// If the specified `futureLayerType` does not have a corresponding base layer type, then `nil` will be returned.
// 
// @param futureLayerType The future layer type to use
// @return The base raster layer type for the future layer type, otherwise `nil`.
// */
//+ (nullable AWFMapLayer)layerTypeForFutureLayerType:(AWFMapLayer)futureLayerType;
//
///**
// Returns the forecast model type associated with the future raster layer.
// 
// @param layerType The future raster layer to return the forecast model for
// */
//+ (AWFForecastModelType)forecastModelTypeForRasterLayerType:(AWFMapLayer)layerType;

/**
 Returns the weather data type associated with the specified layer type.
 
 @param layerType The layer type to use
 */
+ (AWFWeatherDataType)weatherDataTypeForLayerType:(AWFMapLayer)layerType;

@end

//BOOL AWFIsFutureRasterLayer(AWFMapLayer layerType);
AWFMapLayer AWFMapLayerForWeatherDataType(AWFWeatherDataType weatherDataType);
AWFWeatherDataType AWFWeatherDataTypeForRasterLayerType(AWFMapLayer layerType);

NS_ASSUME_NONNULL_END
