//
//  AFCoordinateBounds.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/7/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  An `AWFCoordinateBounds` object describes a map coordinate region defined by a bounding rectangle.
 */
@interface AWFCoordinateBounds : NSObject

/**
 *  The northern latitude value of the bounding box.
 */
@property (nonatomic, assign) CGFloat north;

/**
 *  The southern latitude value of the bounding box.
 */
@property (nonatomic, assign) CGFloat south;

/**
 *  The western longitude value of the bounding box.
 */
@property (nonatomic, assign) CGFloat west;

/**
 *  The eastern longitude value of the bounding box.
 */
@property (nonatomic, assign) CGFloat east;

/**
 *  The top-left map coordinate of the bounding box.
 */
@property (readonly, nonatomic) CLLocationCoordinate2D northwest;

/**
 *  The bottom-left map coordinate of the bounding box;
 */
@property (readonly, nonatomic) CLLocationCoordinate2D southwest;

/**
 *  The top-right map coordinate of the bounding box.
 */
@property (readonly, nonatomic) CLLocationCoordinate2D northeast;

/**
 *  The bottom-right map coordinate of the bounding box.
 */
@property (readonly, nonatomic) CLLocationCoordinate2D southeast;

/**
 *  The center coordinate of the bounding box.
 */
@property (readonly, nonatomic) CLLocationCoordinate2D center;

/**
 *  The area currently covered by the bounding box.
 */
@property (readonly, nonatomic) MKCoordinateRegion region;

/**
 *  The zoom level of the bounds.
 */
@property (assign, nonatomic) NSUInteger zoomLevel;

/**
 *  The zoom level of the bounds adjusted for Retina displays.
 *
 *	When returning tiles for Retina displays, the next highest zoom level is returned to provide a tile image that is higher resolution.
 */
@property (readonly, nonatomic) NSUInteger zoomLevelForScreenScale;

/**
 *  Initializes and returns an empty coordinate bounds object.
 *
 *  @return The initialized coordinate bounds object.
 */
+ (instancetype)coordinateBounds;

/**
 *  Initializes and returns a coordinate bounds object specified by the top-left and bottom-right map coordinates.
 *
 *  @param northwest The top-left map coordinate.
 *  @param southeast The bottom-right map coordinate.
 *
 *  @return The initialized coordinate bounds object.
 */
+ (instancetype)coordinateBoundsWithNorthwest:(CLLocationCoordinate2D)northwest southeast:(CLLocationCoordinate2D)southeast;

/**
 *  Returns the x and y indexes of the map tile for the top-left map coordinate.
 *
 *  @param adjustForRetina Specify `YES` if the zoom level used in the calculation should be adjusted for Retina displays.
 *
 *  @return The tile x and y indexes.
 */
- (CGPoint)northwestTile:(BOOL)adjustForRetina;

/**
 *  Returns the x and y indexes of the map tile for the bottom-left map coordinate.
 *
 *  @param adjustForRetina Specify `YES` if the zoom level used in the calculation should be adjusted for Retina displays.
 *
 *  @return The tile x and y indexes.
 */
- (CGPoint)southwestTile:(BOOL)adjustForRetina;

/**
 *  Returns the x and y indexes of the map tile for the top-right map coordinate.
 *
 *  @param adjustForRetina Specify `YES` if the zoom level used in the calculation should be adjusted for Retina displays.
 *
 *  @return The tile x and y indexes.
 */
- (CGPoint)northeastTile:(BOOL)adjustForRetina;

/**
 *  Returns the x and y indexes of the map tile for the bottom-right map coordinate.
 *
 *  @param adjustForRetina Specify `YES` if the zoom level used in the calculation should be adjusted for Retina displays.
 *
 *  @return The tile x and y indexes.
 */
- (CGPoint)southeastTile:(BOOL)adjustForRetina;

@end
