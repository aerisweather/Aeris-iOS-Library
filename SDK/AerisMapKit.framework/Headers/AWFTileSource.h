//
//  AWFTileSource.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/17/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFMapContentSource.h>
#import <AerisMapKit/AWFAnimatableOverlay.h>
#import <AerisMapKit/AWFTimeDependent.h>
#import <AerisMapKit/AWFImageAnimation.h>

@class AWFOverlayMetadata, AWFMapStrategy, AWFTileOverlayPath;
@protocol AWFTileDataSource;

/**
 An `AWFTileSource` object is a map content source that represents and manages a tile resources on a map.
 */
@interface AWFTileSource : AWFMapContentSource <AWFTimeDependent, AWFAnimatableOverlay, AWFImageAnimationDataSource>

/**
 The template for generating tile URLs (read-only).
 */
@property (nonatomic, readonly) NSString *URLTemplate;

/**
 The amount of transparency to apply to the overlay.
 */
@property (nonatomic, assign) CGFloat alpha;

///**
// The metadata object that handles loading and storing additional information about the content source, such as available timestamps and intervals.
// */
@property (nonatomic, readonly) AWFOverlayMetadata *metadata;

/**
 Current date of the data being used in the content source.
 */
@property (nonatomic, strong) NSDate *date;

/**
 The time offset string relative to now being used with the content source.
 */
@property (nonatomic, strong) NSString *offset;

/**
 A Boolean value that determine whether the data being maintained by this content source represents data in the future.
 */
@property (nonatomic, assign) BOOL isFutureLayer;

/**
 The animation object associated with the content source.
 */
@property (nonatomic, strong) AWFImageAnimation *animation;

/**
 The maximum number of intervals to show during an animation.
 */
@property (nonatomic, assign) NSInteger maximumIntervalsForAnimation;

/**
 Initializes and returns a tile overlay object using the specified tile-access template.
 
 @param URLTemplate A string that can be used to build a URL to access tile images. The string specified can use the placeholder values `{x}`,
 `{y}`, `{z}`, `{scale}` and `{time}` as stand-ins for the x and y tile indexes, zoom level, resolution of the tile image and timestamp.
 @return An initialized tile overlay object.
 */
- (id)initWithURLTemplate:(NSString *)URLTemplate;

/**
 Returns the URL for the specified tile path structure.
 
 @param path The path structure that identifies the specific tile.
 @return The URL to use to retrive the tile.
 */
- (NSURL *)URLForTilePath:(AWFTileOverlayPath *)path;

/**
 Returns the tile URL for the region defined by the specified coordinate bounds, image size and time string for the data relative
 to the current time.
 
 @param bounds The region's coordinate bounds.
 @param size The image size.
 @param timestamp The time string to use for the data.
 */
- (NSURL *)URLForBounds:(AWFMapCoordinateBounds *)bounds size:(CGSize)size timestamp:(NSString *)timestamp;

/**
 Cancels any active requests removes any cached data.
 */
- (void)reset;

@end

/**
 The `AWFTileDataSource` protocol is adopted by an object that provides information a tile overlay needs to request and load tiles.
 */
@protocol AWFTileDataSource <NSObject>

/**
 Returns the URL for the specified tile path structure.
 
 @param path The path structure that identifies the specific tile.
 @return The URL to use to retrive the tile.
 */
- (NSURL *)URLForTilePath:(AWFTileOverlayPath *)path;

/**
 Returns the tile URL for the region defined by the specified coordinate bounds, image size and time string for the data relative
 to the current time.
 
 @param bounds The region's coordinate bounds.
 @param size The image size.
 @param timestamp The time string to use for the data.
 */
- (NSURL *)URLForBounds:(AWFMapCoordinateBounds *)bounds size:(CGSize)size timestamp:(NSString *)timestamp;

@end
