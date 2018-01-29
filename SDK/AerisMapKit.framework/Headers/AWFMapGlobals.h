//
//  AWFMapGlobals.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

//-----------------------
// @name Paths
//-----------------------

extern NSString * const AerisMapCenteredURL;
extern NSString * const AerisMapBoundingBoxURL;
extern NSString * const AerisMapTileURL;

//-----------------------
// @name Utilities
//-----------------------

/**
 Converts a map scale to a zoom level.
 
 @param zoomScale The zoom scale to convert.
 @return The zoom level corresponding to the zoom scale.
 */
NSUInteger AWFMapZoomLevelFromZoomScale(MKZoomScale zoomScale);

/**
 Returns a map coordinate that corresponds to the specified point.
 
 @param point     The point to convert.
 @param zoomLevel The zoom level to use when converting to map coordinates.
 @return The map coordinate at the point.
 */
CLLocationCoordinate2D AWFMapTilePointToCoordinate(CGPoint point, NSUInteger zoomLevel);

/**
 Returns tile x and y indexes that contain the map point.
 
 @param mapPoint  The map point to convert.
 @param zoomLevel The zoom level to use when calculating tile indexes.
 @return The tile x and y indexes that contain the map point.
 */
CGPoint AWFMapPointToTilePoint(MKMapPoint mapPoint, NSUInteger zoomLevel);

/**
 Returns tile x and y indexes that contain the map coordinate.
 
 @param coord     The map coordinate to convert.
 @param zoomLevel The zoom level to use when calculating the tile indexes.
 @return The tile x and y indexes that contain the map coordinate.
 */
CGPoint AWFMapTilePointFromCoordinate(CLLocationCoordinate2D coord, NSUInteger zoomLevel);
