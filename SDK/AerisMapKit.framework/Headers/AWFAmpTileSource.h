//
//  AWFAmpTileSource.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 2/8/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFTileSource.h>

@class AWFMapTileURL;

/**
 An `AWFAmpTileSource` object is a sublcass of `AWFTileSource` that manages a tile URL responsible for generating the proper URLs when requesting
 Aeris Maps (AMP) imagery.
 */
@interface AWFAmpTileSource : AWFTileSource

/**
 The map tile URL for the source.
 */
@property (nonatomic, strong) AWFMapTileURL *tileURL;

@end
