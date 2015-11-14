//
//  AFPointDataOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFDataLayer.h"
#import "AWFAnimatableOverlay.h"
#import "AWFPointDataAnimation.h"
#import "AWFMapGlobals.h"

@class AWFCoordinateBounds, AWFPointDataAnimation;

/**
 *  An `AWFPointDataOverlay` object represents an overlay that manages a series of points on the map.
 */
@interface AWFPointDataLayer : AWFDataLayer <AWFAnimatableOverlay, AWFPointDataAnimationDataSource>

/**
 *  The annotations being managed by the overlay (readonly).
 */
@property (readonly, nonatomic, strong) NSArray *annotations;

/**
 *  The options to use when requesting data for the overlay.
 */
@property (nonatomic, strong) AWFRequestOptions *requestOptions;

/**
 *  The animation object associated with the overlay.
 */
@property (nonatomic, strong) AWFPointDataAnimation *animation;

/**
 *  Requests data for the overlay within the region described by the specified coordinate bounds.
 *
 *  @param bounds  The coordinate bounds to request data for
 *  @param results The completion block when the request finishes or fails
 */
- (void)loadForMapBounds:(AWFCoordinateBounds *)bounds results:(void (^)(NSArray *results, NSError *error))results;

/**
 *  Requests data for the overlay within the region described the the specified coordinate bounds and the date range.
 *
 *  @param bounds   The coordinate bounds to request data for
 *  @param fromDate The starting date to use for the request, or `nil` to use the current date and time
 *  @param toDate   The ending date to use for the request, or `nil` to use the current date and time
 *  @param results  The completion block when the requet finishes or fails
 */
- (void)loadForMapBounds:(AWFCoordinateBounds *)bounds fromDate:(NSDate *)fromDate toDate:(NSDate *)toDate results:(void (^)(NSArray *, NSError *))results;

/**
 *  Cancels any active requests and prepared for a new request.
 */
- (void)reset;


/**
 *  Performs additional actions on the overlay's annotations after new data has been loaded.
 *
 *	Subclasses should override this method to provide necessary actions on annotation objects, such as setting additional properties needed
 *	for annotation views. The default implementation does not do anything.
 *
 *  @param annotations The annotations to perform the additional actions on.
 *  @param completion  The completion block when all actions have completed.
 */
- (void)processAnnotations:(NSArray *)annotations completion:(void (^)(NSArray *annotations))completion;

@end
