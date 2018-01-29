//
//  AWFMapTileURL.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFMapURL.h>
#import <AerisMapKit/AWFBaseMapStyle.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFRasterMapLayer;
@class AWFMapCoordinateBounds;

/**
 `AWFMapTileURL` is a subclass of `AWFMapURL` that is responsible for configuring a URL for interacting with the Aeris Maps Platform (AMP) tile
 imagery service. These images are intended to be displayed using mapping libraries, such as Apple Maps, Mapbox or Google Maps.
 */
@interface AWFMapTileURL : AWFMapURL

/**
 The full URL template required for the tile request by including the current `offset` value.
 */
@property (nonatomic, readonly) NSString *URLPathWithOffset;

/**
 The full URL template required for requesting a tile using a bounding box.
 */
@property (nonatomic, readonly) NSString *boundingBoxURLPath;

/**
 Returns the tile URL for the specified tile coordinate and zoom level.

 @param x The tile column
 @param y Tile tile row
 @param zoomLevel The zoom level
 */
- (NSURL *)tileURLForX:(NSInteger)x y:(NSInteger)y zoomLevel:(NSUInteger)zoomLevel;

/**
 Returns the tile URL for the specified tile coordinate, zoom level and time offset for the data relative to the current time.

 @param x The tile column
 @param y The tile row
 @param zoomLevel The zoom level
 @param offset The time offset for the data relative to now
 */
- (NSURL *)tileURLForX:(NSInteger)x y:(NSInteger)y zoomLevel:(NSUInteger)zoomLevel offset:(nullable NSString *)offset;

/**
 Returns the tile URL for the region defined by the specified coordinate bounds and image size.

 @param bounds The region's coordinate bounds
 @param size The image size
 */
- (NSURL *)tileURLForBounds:(AWFMapCoordinateBounds *)bounds size:(CGSize)size;

/**
 Returns the tile URL for the region defined by the specified coordinate bounds, image size and time offset for the data relative
 to the current time.

 @param bounds The region's coordinate bounds
 @param size The image size
 @param offset The time offset for the data relative to now
 */
- (NSURL *)tileURLForBounds:(AWFMapCoordinateBounds *)bounds size:(CGSize)size offset:(nullable NSString *)offset;

@end

NS_ASSUME_NONNULL_END
