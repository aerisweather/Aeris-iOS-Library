//
//  AWFMapURL.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFMapURL.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFRasterMapLayer;

/**
 `AWFMapImageURL` is a subclass of `AWFMapURL` that is responsible for configuring a URL for interacting with the Aeris Maps Platform (AMP) static 
 imagery service. These images are single images and typically consist of a solid base style layer.
 */
@interface AWFMapImageURL : AWFMapURL

/**
 The center coordinate for the map.
 */
@property (nonatomic, assign) CLLocationCoordinate2D centerCoordinate;

/**
 The coordinate bounds for the map's visible region. 
 
 If this value is defined, then `centerCoordinate` will return the center of the specified bounds.
 */
@property (nonatomic, assign) AWFCoordinateRect boundingBox;

/**
 The zoom level for the map.
 */
@property (nonatomic, assign) NSUInteger zoomLevel;

/**
 The size of the image to request.
 */
@property (nonatomic, assign) CGSize mapSize;

/**
 The image format to request. The default is `png`.
 */
@property (nonatomic, assign) NSInteger imageFormat;

/**
 Sets the map's center coordinate to that of the specified place. This will override any value previously defined for `boundingBox`.

 @param place The `AWFPlace` to center the map on
 */
- (void)centerOnPlace:(AWFPlace *)place;

@end

NS_ASSUME_NONNULL_END
