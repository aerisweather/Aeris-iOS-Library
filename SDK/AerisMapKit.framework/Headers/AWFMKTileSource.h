//
//  AWFMKTileSource.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFTileSource.h>
#import <AerisMapKit/AWFOverlayProvider.h>
#import <AerisMapKit/AWFAmpTileSource.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `AWFMKTileProvider` protocol defines the properties required by overlay sources rendered on an `MKMapView` instance.
 */
@protocol AWFMKTileProvider <NSObject>

/**
 The `MKTileOverlay` instance managed by the layer.
 */
@property (readonly, nonatomic, strong) id<MKOverlay> overlay;

/**
 The position of the overlay relative to other content on the map.
 */
@property (nonatomic, assign) MKOverlayLevel overlayLevel;

@end

/**
 An `AWFMKTileSource` object is a subclass of `AWFTileSource` that provides the necessary `MKOverlay` instance to use with Apple's MapKit 
 for displaying a tile overlay on an `MKMapView` instance.
 */
@interface AWFMKTileSource : AWFTileSource <AWFOverlayProvider, AWFMKTileProvider>

/**
 The `MKTileOverlay` instance managed by the layer.
 */
@property (readonly, nonatomic, strong) id<MKOverlay> overlay;

/**
 The position of the overlay relative to other content on the map.
 */
@property (nonatomic, assign) MKOverlayLevel overlayLevel;

@end

/**
 An `AWFMKAmpTileSource` object is a subclass of `AWFAmpTileSource` that provides the necessary `MKOverlay` instance to use with Apple's 
 MapKit for displaying a tile overlay using imagery from the Aeris Maps Platform (AMP) on an `MKMapView` instance.
 */
@interface AWFMKAmpTileSource : AWFAmpTileSource <AWFOverlayProvider, AWFMKTileProvider>

/**
 The `MKTileOverlay` instance managed by the layer.
 */
@property (readonly, nonatomic, strong) id<MKOverlay> overlay;

/**
 The position of the overlay relative to other content on the map.
 */
@property (nonatomic, assign) MKOverlayLevel overlayLevel;

@end

NS_ASSUME_NONNULL_END
