//
//  AWFMapboxMapStrategy.h
//  AerisMapboxMap
//
//  Created by Nicholas Shipes on 7/2/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <AerisMap/AWFAppleMapStrategy.h>

@class MBXRasterTileOverlay;

/**
 *  An `AWFAppleMapStrategy` object implements the `AWFMapStrategy` protocol and provides the necessary functionality for managing a `AWFWeatherMap` configured
 *  with an `MKMapView` instance and MapBox base map.
 */
@interface AWFMapboxMapStrategy : AWFAppleMapStrategy

/**
 *  The base raster Mapbox tile overlay associated with the Mapbox ID.
 */
@property (readonly, strong, nonatomic) MBXRasterTileOverlay *baseOverlay;

/**
 *  Initializes and returns a map strategy associated with the specified weather map instance while specifying whether to load Mapbox metadata and markers.
 *
 *  @param weatherMap      The weather map instance associated with the map strategy
 *  @param includeMetadata Whether to load the map's metadata including center coordinate and zoom limits
 *  @param includeMarkers  Whether to load the map's markers
 *
 *  @return An initialized map strategy
 */
- (instancetype)initWithWeatherMap:(AWFWeatherMap *)weatherMap includeMetadata:(BOOL)includeMetadata includeMarkers:(BOOL)includeMarkers;

@end