//
//  AWFTileOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AWFTileOverlayPath;
@protocol AWFTileDataSource;

@interface AWFTileOverlay : NSObject <MKOverlay>

@property (nonatomic, unsafe_unretained) id<AWFTileDataSource> dataSource;

/**
 *  Loads the specified tile asynchronously.
 *
 *	The default implementation of this method uses the `URLForTilePath:` method to retrieve the URL for the specified tile and then loads it asynchronously.
 *	Subclasses may override this to provide their own custom tile-loading behavior.
 *
 *  @param path   The path structure that identifies the specific tile needed.
 *  @param result The completion block to call when the tile data is available.
 */
- (void)loadTileAtPath:(AWFTileOverlayPath *)path result:(void (^)(NSData *tileData, NSError *error))result;

@end
