//
//  AWFCoordinateBounds.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 1/24/17.
//  Copyright © 2017 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFCoordinateBounds` object describes a map coordinate region defined by a bounding rectangle.
 */
@interface AWFCoordinateBounds : NSObject

/**
 The northern latitude value of the bounding box.
 */
@property (nonatomic, assign) CGFloat north;

/**
 The southern latitude value of the bounding box.
 */
@property (nonatomic, assign) CGFloat south;

/**
 The western longitude value of the bounding box.
 */
@property (nonatomic, assign) CGFloat west;

/**
 The eastern longitude value of the bounding box.
 */
@property (nonatomic, assign) CGFloat east;

/**
 The top-left map coordinate of the bounding box.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D northwest;

/**
 The bottom-left map coordinate of the bounding box;
 */
@property (nonatomic, readonly) CLLocationCoordinate2D southwest;

/**
 The top-right map coordinate of the bounding box.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D northeast;

/**
 The bottom-right map coordinate of the bounding box.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D southeast;

/**
 The center coordinate of the bounding box.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D center;

/**
 A convenience method that returns an instantiated instance of `AWFCoordinateBounds` with empty coordinate bounds.
 */
+ (instancetype)coordinateBounds;

/**
 Returns a newly initialized coordinate bounds instance for the specified `northwest` and `southeast` coordinate bounds.
 
 @param northwest The northwest coordinate defining the top-left corner of the region.
 @param southeast The southeast coordinate defining the bottom-right corner of the region.
 @return An `AWFCoordinateBounds` object initialized with the specified bounding coordinates
 */
+ (instancetype)coordinateBoundsWithNorthwest:(CLLocationCoordinate2D)northwest southeast:(CLLocationCoordinate2D)southeast;

/**
 Returns a newly initialized coordinate bounds instance for the specified `northwest` and `southeast` coordinate bounds.

 @param northwest The northwest coordinate defining the top-left corner of the region.
 @param southeast The southeast coordinate defining the bottom-right corner of the region.
 @return An `AWFCoordinateBounds` object initialized with the specified bounding coordinates
 */
- (instancetype)initWithNorthwest:(CLLocationCoordinate2D)northwest southeast:(CLLocationCoordinate2D)southeast;

/**
 Returns the coordinate bounds as a string, which is typically used when performing API requests for the region.
 
 The returned string will be in the format `northwest.latitude,northwest.longitude,southeast.latitude,southeast.longitude`.

 @return The coordinate bounds as a string.
 */
- (NSString *)boundsAsString;

@end

NS_ASSUME_NONNULL_END
