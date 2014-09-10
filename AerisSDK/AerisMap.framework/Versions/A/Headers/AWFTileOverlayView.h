//
//  AWFTileOverlayView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

@class AWFTileOverlay;

/**
 *  An `AWFTileOverlayView` object provides the visual representation of a tile overlay. This class performs the necessary
 *	tile requests and rendering in the overlay view.
 *
 *	In iOS 7 and later, use the {@link MKTileOverlayRenderer} class to display tile overlays instead.
 */
@interface AWFTileOverlayView : MKOverlayView

/**
 *  Initializes and returns a tile overlay view and associates it with the specified tile overlay.
 *
 *  @param overlay The tile overlay to display in the overlay view.
 *
 *  @return The initialized tile overlay view.
 */
- (id)initWithTileOverlay:(AWFTileOverlay *)overlay;

@end
