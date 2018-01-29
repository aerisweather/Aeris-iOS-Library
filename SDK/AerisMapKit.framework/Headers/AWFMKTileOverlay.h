//
//  AWFMKTileOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/9/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFTileSource.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `AWFMKTileOverlay` class provides an `MKTileOverlay` instance that provides improved disk and in-memory caching of tile data.
 */
@interface AWFMKTileOverlay : MKTileOverlay

/**
 The data source object that provides URL and request information required for loading tile resources.
 */
@property (nonatomic, weak, nullable) id<AWFTileDataSource> dataSource;

/**
 Cancels all active asynchronous requests for tile resources.
 */
- (void)cancelRequests;

@end

NS_ASSUME_NONNULL_END
