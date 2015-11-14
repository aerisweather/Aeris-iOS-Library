//
//  MKMapView+AerisMap.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

@class AWFCoordinateBounds;

@interface MKMapView (AerisMap)

/**
 *  Returns the current zoom level as an integer from 1 to 20 based on the map's current zoom scale and region.
 *
 *  @return The current zoom level
 */
- (NSUInteger)awf_zoomLevel;

/**
 *  Returns the current zoom scale for the map.
 *
 *  @return The current zoom scale
 */
- (MKZoomScale)awf_zoomScale;

/**
 *  Sets the map's center coordinate and zoom level.
 *
 *  @param centerCoordinate The center coordinate for the map
 *  @param zoomLevel        The zoom level
 *  @param animated         A Boolean indicating whether or not the change should be animated
 */
- (void)awf_setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate zoomLevel:(NSUInteger)zoomLevel animated:(BOOL)animated;

/**
 *  Returns a new coordinate based on a coordinate, point offset and zoom level regardless of the map's current zoom level.
 *
 *  @param centerCoordinate The coordinate from which to calculate the offset from
 *  @param offset           The pixel offset from the `coordinate`
 *  @param zoomLevel        The zoom level to use for the calculation
 *
 *  @return A new coordinate that is `offset` pixels from `centerCoordinate` for the given `zoomLevel`
 */
- (CLLocationCoordinate2D)awf_coordinateByOffsettingCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate offset:(UIOffset)offset zoomLevel:(NSUInteger)zoomLevel;

//----------------------
// @name Coordinate Bounds
//----------------------

/**
 *  Returns the northwest (top-left) coordinate of the visible map bounds.
 *
 *  @return CLLocationCoordinate2D
 */
- (CLLocationCoordinate2D)awf_northwestCoordinate;

/**
 *  Returns the southwest (bottom-left) coordinate of the visible map bounds.
 *
 *  @return CLLocationCoordinate2D
 */
- (CLLocationCoordinate2D)awf_southwestCoordinate;

/**
 *  Returns the northeast (top-right) coordinate of the visible map bounds.
 *
 *  @return CLLocationCoordinate2D
 */
- (CLLocationCoordinate2D)awf_northeastCoordinate;

/**
 *  Returns to southeast (bottom-right) coordinate of the visible map bounds.
 *
 *  @return CLLocationCoordinate2D
 */
- (CLLocationCoordinate2D)awf_southeastCoordinate;

//----------------------
// @name Map Tiles
//----------------------

/**
 *  Returns a map tile's x and y grid locations that a coordinate falls within at the specified zoom level.
 *
 *	The tile grid location calculations are based on the standard 256x256 tile sizes that most mapping APIs use. The zoom level
 *	should be a value from 1 to 20 and is based on the map's zoom scale. You can retrieve the map's current zoom level using 
 *	the `awf_zoomLevel` category method provided.
 *
 *  @param coord     The coordinate to use when determining the tile grid location
 *  @param zoomLevel The map zoom level to use in determining the tile grid location
 *
 *  @return The tile's x and y grid location to be used when requesting the proper tile.
 */
- (CGPoint)awf_tileXYForCoordinate:(CLLocationCoordinate2D)coord zoomLevel:(NSUInteger)zoomLevel;

/**
 *  Calculates the coordinate bounds at the corners of the tile at a specific grid location and zoom level.
 *
 *  @param x The tile's x coordinate.
 *  @param y The tile's y coordinate.
 *
 *  @return An {@link AWFCoordinateBounds} instance with the calculated coordinates for the four corners and center.
 */
- (AWFCoordinateBounds *)af_coordinateBoundsForTileAtX:(NSUInteger)x y:(NSUInteger)y;

@end
