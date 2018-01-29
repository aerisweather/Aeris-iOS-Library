//
//  AWFPolygonStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/28/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFMapItemStyle.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFPolygonStyle` object provides the style specifications to be used for a polygon's representation on a map.
 */
@interface AWFPolygonStyle : AWFMapItemStyle

/**
 Returns the default polygon style for the specified layer type. This may return a single instance of `AWFPolygonStyle`, or if there are multiple
 styles associated with a layer type this method will return an instance of `AWFGroupedStyle`.
 
 @param layerType The layer type to return the default style for
 @return Either an instance of `AWFPolygonStyle` or `AWFGroupedStyle`
 */
+ (nullable id)defaultStyleForLayerType:(AWFMapLayer)layerType;

@end

NS_ASSUME_NONNULL_END
