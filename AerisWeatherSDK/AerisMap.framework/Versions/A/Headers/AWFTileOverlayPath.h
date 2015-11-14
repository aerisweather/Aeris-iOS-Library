//
//  AWFTileOverlayPath.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The `AWFTileOverlayPath` class provides an object used to specify the index values for a single tile.
 */
@interface AWFTileOverlayPath : NSObject

/**
 *  The index of the tile along the x axis of the map.
 */
@property (assign, nonatomic) NSInteger x;

/**
 *  The index of the tile along the y axis of the map.
 */
@property (assign, nonatomic) NSInteger y;

/**
 *  The zoom level number for the tile.
 */
@property (assign, nonatomic) NSInteger z;

/**
 *  The screen scale factor for which the tile is intended. This value is either `1.0` (for standard resolution displays) or
 *	`2.0` (for Retina displays).
 */
@property (assign, nonatomic) CGFloat contentScaleFactor;

/**
 *  The timestamp string for which the tile is intended. This value is usually assigned by a tile overlay's metadata object, which provides
 *	the available times and intervals for a specific tile overlay.
 */
@property (copy, nonatomic) NSString *time;

/**
 *  The interval offset for which the tile is intended. You can use this instead of `time` to specify the number of intervals 
 *	to offset from the most recent interval. `0` is the most recent interval, `1` is the interval before the most
 *	recent, `2` is two intervals before, and so on.
 */
@property (assign, nonatomic) NSInteger offset;

/**
 *  Initializes and returns an overlay path object at the specified indexes.
 *
 *  @return An initialized overlay path object.
 */
+ (AWFTileOverlayPath *)overlayPathWithX:(NSInteger)x y:(NSInteger)y z:(NSInteger)z;

/**
 *  Initializes and returns an overlay path object at the specified indexes and interval offset.
 *
 *  @return An initialized overlay path object.
 */
+ (AWFTileOverlayPath *)overlayPathWithX:(NSInteger)x y:(NSInteger)y z:(NSInteger)z offset:(NSInteger)offset;

@end