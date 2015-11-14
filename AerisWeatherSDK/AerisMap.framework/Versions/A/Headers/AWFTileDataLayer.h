//
//  AWFTileOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/17/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFDataLayer.h"
#import "AWFAnimatableOverlay.h"
#import "AWFImageAnimation.h"

@class AWFOverlayMetadata, AWFMapStrategy, AWFTileOverlayPath, AWFOverlayMetadata;
@protocol AWFTileDataLayer, AWFTileDataSource;

/**
 *  An `AWFTileOverlay` object represents and manages a tile overlay on a map.
 */
@interface AWFTileDataLayer : AWFDataLayer <AWFAnimatableOverlay, AWFImageAnimationDataSource>

/**
 *  The template for generating tile URLs (read-only).
 */
@property (nonatomic, readonly) NSString *URLTemplate;

/**
 *  The base URL string to use for generating tile URLs.
 */
@property (nonatomic, copy) NSString *URLBase;

///**
// *  The overlay object that is added to a map.
// *
// *	The class type for this object will vary depending on the type of mapping library used. For example, when using Apple's MapKit, this object
// *	will be an instance of `MKTileOverlay` on iOS 7 and higher. For iOS 6 and lower, this object will be an instance of `AWFTileOverlay`.
// */
//@property (nonatomic, readonly) NSObject *overlayObject;

/**
 *  The metadata object that handles loading and storing additional information about the data layer, such as available timestamps and intervals.
 */
@property (nonatomic, readonly) AWFOverlayMetadata *metadata;

/**
 *  Current date of the data being used in the data layer.
 */
@property (nonatomic, strong) NSDate *date;

/**
 *  The animation object associated with the data layer.
 */
@property (nonatomic, strong) AWFImageAnimation *animation;

/**
 *  The maximum number of intervals to show during an animation.
 */
@property (nonatomic, assign) NSInteger maximumIntervalsForAnimation;

/**
 *  Initializes and returns a tile overlay object using the specified tile-access template.
 *
 *  @param URLTemplate A string that can be used to build a URL to access tile images. The string specified can use the placeholder values `{x}`,
 *	`{y}`, `{z}`, `{scale}` and `{time}` as stand-ins for the x and y tile indexes, zoom level, resolution of the
 *	tile image and timestamp.
 *
 *  @return An initialized tile overlay object.
 */
- (id)initWithURLTemplate:(NSString *)URLTemplate;

/**
 *  Returns the URL for the specified tile path structure.
 *
 *  @param path The path structure that identifies the specific tile.
 *
 *  @return The URL to use to retrive the tile.
 */
- (NSURL *)URLForTilePath:(AWFTileOverlayPath *)path;

@end

@protocol AWFTileDataLayer <NSObject>
@required

/**
 *  The overlay object that is added to a map.
 *
 *	The class type for this object will vary depending on the type of mapping library used. For example, when using Apple's MapKit, this object
 *	will be an instance of `MKTileOverlay` on iOS 7 and higher. For iOS 6 and lower, this object will be an instance of `AWFTileOverlay`.
 */
@property (readonly, nonatomic, strong) id overlay;

@end

/**
 *  The `AWFTileDataSource` protocol is adopted by an object that provides information a tile overlay needs to request
 *	and load tiles.
 */
@protocol AWFTileDataSource <NSObject>

/**
 *  Returns the URL for the specified tile path structure.
 *
 *  @param path The path structure that identifies the specific tile.
 *
 *  @return The URL to use to retrive the tile.
 */
- (NSURL *)URLForTilePath:(AWFTileOverlayPath *)path;

@end