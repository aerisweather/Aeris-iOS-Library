//
//  AWFImageOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFMapCoordinateBounds;

/**
 An `AWFMKImageOverlay` object is a data object that contains the information needed to render raster imagery in a map view's area.
 */
@interface AWFMKImageOverlay : NSObject <MKOverlay>

/**
 Creates and returns an overlay object for the specified coordinate bounds.
 
 @param bounds  The coordinate bounds describing the region covered by the overlay
 @return The initialized overlay object
 */
- (instancetype)initWithBounds:(AWFMapCoordinateBounds *)bounds;

@end

NS_ASSUME_NONNULL_END
