//
//  AFGMTileOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFTileDataLayer.h>

@class GMSTileLayer;

@interface AWFGMTileDataLayer : AWFTileDataLayer <AWFTileDataLayer>

@property (readonly, nonatomic, strong) GMSTileLayer *overlay;

@end
