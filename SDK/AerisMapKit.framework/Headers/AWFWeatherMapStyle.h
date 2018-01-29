//
//  AWFWeatherMapStyle.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 7/31/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFMapItemStyle.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFWeatherMapStyle` defines the styles used for various elements displayed on a weather map, such as overlays, annotations and legends.
 */
@interface AWFWeatherMapStyle : NSObject

/**
 The overlay styles keyed by layer type.
 */
@property (nonatomic, readonly) NSDictionary<AWFMapLayer, id<AWFStyleProvider>> *overlays;

/**
 The annotation styles keyed by layer type.
 */
@property (nonatomic, readonly) NSDictionary<AWFMapLayer, id<AWFStyleProvider>> *annotations;

/**
 The polygon styles keyed by layer type.
 */
@property (nonatomic, readonly) NSDictionary<AWFMapLayer, id<AWFStyleProvider>> *polygons;

/**
 
 */
@property (nonatomic, readonly) NSDictionary *legends;

/**
 Returns the style for the specified layer type.

 @param layerType The layer type.
 @return The style specification for the layer type if it exists, otherwise `nil`.
 */
- (nullable id<AWFStyleProvider>)styleForLayerType:(AWFMapLayer)layerType;

/**
 Sets the style to use for the specified layer type.

 @param style The style to associate with the layer type.
 @param layerType The layer type.
 */
- (void)setStyle:(id<AWFStyleProvider>)style forLayerType:(AWFMapLayer)layerType;

@end

NS_ASSUME_NONNULL_END
