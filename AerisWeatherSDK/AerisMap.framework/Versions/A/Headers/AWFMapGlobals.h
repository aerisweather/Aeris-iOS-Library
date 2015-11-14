//
//  AWFMapGlobals.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFLayerType.h"

//-----------------------
// @name Paths
//-----------------------

extern NSString * const AerisTileServer;

//typedef struct {
//	CLLocationCoordinate2D northwest;
//	CLLocationCoordinate2D southwest;
//	CLLocationCoordinate2D northeast;
//	CLLocationCoordinate2D southeast;
//} AFMapCoordinateBounds;

//-----------------------
// @name Overlay Type Conversions
//-----------------------

/**
 *  Returns the code string associated with the layer type.
 *
 *  @param type The {@link AWFLayerType} to return the code for.
 *
 *  @return The code string for the layer type.
 */
NSString* AWFStringFromLayerType(AWFLayerType type);

/**
 *  Returns the {@link AWFLayerType} for the code string.
 *
 *  @param string The code string to return the layer type for.
 *
 *  @return The {@link AWFLayerType} for the code string.
 */
AWFLayerType AWFLayerTypeFromString(NSString *string);

/**
 *  Returns the name for the specified {@link AWFLayerType}.
 *
 *  @param type The {@link AWFLayerType} to return the name for.
 *
 *  @return The name for the layer type.
 */
NSString* AWFNameForLayerType(AWFLayerType type);

/**
 *  Returns `YES` if the layer type is any type of image overlay.
 *
 *  @param type The `AWFLayerType` to check.
 *
 *  @return `YES` if the layer type is an overlay, otherwise `NO`.
 */
BOOL AWFIsOverlayType(AWFLayerType type);

/**
 *  Returns `YES` if the layer type is a tile overlay.
 *
 *  @param type The {@link AWFLayerType} to check.
 *
 *  @return `YES` if the layer type is a tile overlay, otherwise `NO`.
 */
BOOL AWFIsTileLayerType(AWFLayerType type);

/**
 *  Returns `YES` if the layer type is a combined tile overlay.
 *
 *  @param type The {@link AWFLayerType} to check.
 *
 *  @return `YES` if the layer type is a combined tile overlay, otherwise `NO`.
 */
BOOL AWFIsCombinedTileLayerType(AWFLayerType type);

/**
 *  Returns `YES` if the layer type is a ground tile overlay.
 *
 *	A ground tile overlay is one that covers most or all of the map and is always inserted below non-ground overlays
 *	when added to the map.
 *
 *  @param type The {@link AWFLayerType} to check.
 *
 *  @return `YES` if the layer type is a ground tile overlay, otherwise `NO`.
 */
BOOL AWFIsGroundTileOverlay(AWFLayerType type);

/**
 *  Returns `YES` if the layer type is a point data overlay.
 *
 *  @param type The {@link AWFLayerType} to check.
 *
 *  @return `YES` if the layer type is a point data overlay, otherwise `NO`.
 */
BOOL AWFIsPointDataLayerType(AWFLayerType type);

/**
 *  Returns `YES` if the layer type is a polygon overlay.
 *
 *  @param type The {@link AWFLayerType} to check.
 *
 *  @return `YES` if the layer type is a polygon overlay, otherwise `NO`.
 */
BOOL AWFIsPolygonLayerType(AWFLayerType type);

/**
 *  Returns `YES` is the layer type if a future overlay.
 *
 *  @param type The {@link AWFLayerType} to check.
 *
 *  @return `YES` if the layer type is a future overlay, otherwise `NO`.
 */
BOOL AWFIsFutureLayerType(AWFLayerType type);
BOOL AWFIsFutureGroupLayerType(AWFLayerType type);

//-----------------------
// @name Utilities
//-----------------------

/**
 *  Converts a map scale to a zoom level.
 *
 *  @param zoomScale The zoom scale to convert.
 *
 *  @return The zoom level corresponding to the zoom scale.
 */
NSUInteger AWFMapZoomLevelFromZoomScale(MKZoomScale zoomScale);

/**
 *  Returns a map coordinate that corresponds to the specified point.
 *
 *  @param point     The point to convert.
 *  @param zoomLevel The zoom level to use when converting to map coordinates.
 *
 *  @return The map coordinate at the point.
 */
CLLocationCoordinate2D AWFMapTilePointToCoordinate(CGPoint point, NSUInteger zoomLevel);

/**
 *  Returns tile x and y indexes that contain the map point.
 *
 *  @param mapPoint  The map point to convert.
 *  @param zoomLevel The zoom level to use when calculating tile indexes.
 *
 *  @return The tile x and y indexes that contain the map point.
 */
CGPoint AWFMapPointToTilePoint(MKMapPoint mapPoint, NSUInteger zoomLevel);

/**
 *  Returns tile x and y indexes that contain the map coordinate.
 *
 *  @param coord     The map coordinate to convert.
 *  @param zoomLevel The zoom level to use when calculating the tile indexes.
 *
 *  @return The tile x and y indexes that contain the map coordinate.
 */
CGPoint AWFMapTilePointFromCoordinate(CLLocationCoordinate2D coord, NSUInteger zoomLevel);
