//
//  AWFMKTileDataLayer.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisMap/AWFTileDataLayer.h>

@class AWFMKTileOverlay;

/**
 *  An `AWFMKTileDataLayer` object is a subclass of `AWFTileDataLayer` that provides the necessary `MKOverlay` instance to use with Apple's MapKit for displaying
 *  a tile overlay on an `MKMapView` instance.
 */
@interface AWFMKTileDataLayer : AWFTileDataLayer <AWFTileDataLayer, AWFTileDataSource>

/**
 *  The `MKTileOverlay` instance managed by the layer.
 */
@property (readonly, nonatomic, strong) id<MKOverlay> overlay;

@end
