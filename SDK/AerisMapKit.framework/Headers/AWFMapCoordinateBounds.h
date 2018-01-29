//
//  AFCoordinateBounds.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/7/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisWeatherKit/AerisWeatherKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFMapCoordinateBounds` object describes a map coordinate region defined by a bounding rectangle.
 */
@interface AWFMapCoordinateBounds : AWFCoordinateBounds

/**
 The area currently covered by the bounding box.
 */
@property (readonly, nonatomic) MKCoordinateRegion region;

/**
 The zoom level of the bounds.
 */
@property (nonatomic, assign) NSUInteger zoomLevel;

/**
 The zoom level of the bounds adjusted for Retina displays.
 
 When returning tiles for Retina displays, the next highest zoom level is returned to provide a tile image that is higher resolution.
 */
@property (readonly, nonatomic) NSUInteger zoomLevelForScreenScale;

/**
 Returns the x and y indexes of the map tile for the top-left map coordinate.
 
 @param adjustForRetina Specify `YES` if the zoom level used in the calculation should be adjusted for Retina displays.
 
 @return The tile x and y indexes.
 */
- (CGPoint)northwestTile:(BOOL)adjustForRetina;

/**
 Returns the x and y indexes of the map tile for the bottom-left map coordinate.
 
 @param adjustForRetina Specify `YES` if the zoom level used in the calculation should be adjusted for Retina displays.
 
 @return The tile x and y indexes.
 */
- (CGPoint)southwestTile:(BOOL)adjustForRetina;

/**
 Returns the x and y indexes of the map tile for the top-right map coordinate.
 
 @param adjustForRetina Specify `YES` if the zoom level used in the calculation should be adjusted for Retina displays.
 
 @return The tile x and y indexes.
 */
- (CGPoint)northeastTile:(BOOL)adjustForRetina;

/**
 Returns the x and y indexes of the map tile for the bottom-right map coordinate.
 
 @param adjustForRetina Specify `YES` if the zoom level used in the calculation should be adjusted for Retina displays.
 
 @return The tile x and y indexes.
 */
- (CGPoint)southeastTile:(BOOL)adjustForRetina;

@end

NS_ASSUME_NONNULL_END
