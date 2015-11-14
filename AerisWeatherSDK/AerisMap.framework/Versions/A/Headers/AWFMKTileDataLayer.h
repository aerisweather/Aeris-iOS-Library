//
//  AWFMKTileDataLayer.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFTileDataLayer.h>

@class AWFMKTileOverlay;

@interface AWFMKTileDataLayer : AWFTileDataLayer <AWFTileDataLayer, AWFTileDataSource>

@property (readonly, nonatomic, strong) id<MKOverlay> overlay;

@end
