//
//  AFImageOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/11/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFDataLayer.h"

@class AWFCoordinateBounds;
@protocol AWFImageDataLayer;

/**
 *  An `AWFImageOverlay` object represents a overlay that contains a single image on a map.
 */
@interface AWFImageDataLayer : AWFDataLayer

/**
 *  Initializes and returns an overlay object located at the specified coordinate bounds and associates it with the specified map strategy.
 *
 *  @param bounds  The coordinate bounds describing the region covered by the overlay.
 *  @param manager The map strategy object to use for managing the overlay.
 *
 *  @return The initialized overlay object.
 */
- (instancetype)initWithCoordinateBounds:(AWFCoordinateBounds *)bounds strategy:(id<AWFMapStrategy>)strategy;

@end


@protocol AWFImageDataLayer <NSObject>
@required

@property (readonly, nonatomic, strong) id overlay;

@end