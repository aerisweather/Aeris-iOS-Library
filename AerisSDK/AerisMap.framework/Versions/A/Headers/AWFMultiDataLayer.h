//
//  AWFMultiDataLayer.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/14/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFPointDataLayer.h>

/**
 *  An `AWFMultiDataLayer` represents a data layer that manages a combination of different overlays on a map. Specifically, this layer type
 *  manages overlays, polygons and polylines needed to display a specific data layer.
 */
@interface AWFMultiDataLayer : AWFPointDataLayer

/**
 *  The overlays being managed by the data layer (readonly).
 */
@property (readonly, nonatomic, strong) NSArray *overlays;

/**
 *  The polygons being managed by the data layer (readonly).
 */
@property (readonly, nonatomic, strong) NSArray *polygons;

/**
 *  The polylines being managed by the data layer (readonly).
 */
@property (readonly, nonatomic, strong) NSArray *polylines;

/**
 *  Returns a single overlay representing a set of objects on the map based on a specific group identifier.
 *
 *  @param identifier The group identifier to return an overlay for.
 *
 *  @return Returns a single map overlay object, which varies depending on the map strategy being used.
 */
- (NSArray *)overlayForIdentifier:(NSString *)identifier;

/**
 *  Returns an array of polygons representing a set of objects on the map based on a specific group identifier.
 *
 *  @param identifier The group identifier to return polygons for.
 *
 *  @return Returns an array of map polygon objects, which varies depending on the map strategy being used.
 */
- (NSArray *)polygonsForIdentifier:(NSString *)identifier;

/**
 *  Returns an array of polylines representing a set of objects on the map based on a specific group identifier.
 *
 *  @param identifier The group identifier to return polylines for.
 *
 *  @return Returns an array of map polyline objects, which varies depending on the map strategy being used.
 */
- (NSArray *)polylinesForIdentifier:(NSString *)identifier;

@end
