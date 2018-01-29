//
//  AWFStyledMapItem.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/14/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFStylable.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `AWFStyledMapItem` protocol defines the required and optional methods for a map overlay item that can be styled. This is typically used for map
 overlays like annotation, polygons and polylines.
 */
@protocol AWFStyledMapItem <AWFStylable>
@required

/**
 The group identifier for the map item. This controls which style is used when multiple styles are available for a single data layer type.
 */
@property (nonatomic, copy) NSString *identifier;

@optional

/**
 The model object associated with the map item.
 */
@property (readonly, nonatomic, strong) AWFWeatherObject *modelObject;

/**
 The layer type this map item belongs to.
 */
@property (nonatomic) AWFMapLayer layerType;


/**
 Creates and returns a new `AWFStyledMapItem` instance initialized with the `object`.
 
 @param object The `AWFGeographicObject` to use with the map item. This object determines the style to be applied during initialization.
 @return An initialized styled map item.
 */
- (instancetype)initWithGeographicObject:(AWFGeographicObject *)object;

@end

NS_ASSUME_NONNULL_END
