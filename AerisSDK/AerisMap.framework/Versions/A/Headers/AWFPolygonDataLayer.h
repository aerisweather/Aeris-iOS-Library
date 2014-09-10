//
//  AFPolygonOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/11/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFDataLayer.h"

@interface AWFPolygonDataLayer : AWFDataLayer

@property (nonatomic, strong) NSArray *polygons;

/**
 *  The options to use when requesting data for the overlay.
 */
@property (nonatomic, strong) AWFRequestOptions *requestOptions;

/**
 *  Requests data for the overlay within the region described by the specified coordinate bounds.
 *
 *  @param bounds  The coordinate bounds to request data for.
 *  @param results The completion block when the request finishes or fails.
 */
- (void)loadForMapBounds:(AWFCoordinateBounds *)bounds results:(void (^)(NSArray *results, NSError *error))results;
- (void)loadForMapBounds:(AWFCoordinateBounds *)bounds fromDate:(NSDate *)fromDate toDate:(NSDate *)toDate results:(void (^)(NSArray *, NSError *))results;
- (void)reset;

/**
 *  Performs additional actions on the overlay's polygons after new data has been loaded.
 *
 *	Subclasses should override this method to provide necessary actions on polygon objects, such as setting additional properties needed
 *	for annotation views. The default implementation does not do anything.
 *
 *  @param annotations The polygon to perform the additional actions on.
 *  @param completion  The completion block when all actions have completed.
 */
- (void)processPolygons:(NSArray *)polygons completion:(void (^)(NSArray *polygons))completion;

@end
