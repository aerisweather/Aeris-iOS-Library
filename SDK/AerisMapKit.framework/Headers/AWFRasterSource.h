//
//  AWFRasterSource.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/11/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFMapContentSource.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFMapCoordinateBounds;

/**
 An `AWFRasterSource` object represents a map content source that maintains a single image on a map.
 */
@interface AWFRasterSource : AWFMapContentSource

/**
 The map overlay managed by the content source.
 
 The type of this overlay is dependent upon which map strategy is being used.
 */
@property (readonly, nonatomic, strong) id overlay;

/**
 The amount of transparency to apply to the overlay.
 */
@property (nonatomic, assign) CGFloat alpha;

/**
 Initializes and returns a content source object located at the specified coordinate bounds and associates it with the specified map strategy.
 
 @param bounds  The coordinate bounds describing the region covered by the content source.
 @return The initialized content source object.
 */
- (instancetype)initWithBounds:(AWFMapCoordinateBounds *)bounds;

/**
 Initializes and returns a content source object located at the specified coordinate bounds for the provided layer type.

 @param bounds The coordinate bounds describing the region covered by the content source.
 @param layerType The layer type for the content source.
 @return An initialized content source object.
 */
- (instancetype)initWithBounds:(AWFMapCoordinateBounds *)bounds layerType:(nullable AWFMapLayer)layerType;

@end

NS_ASSUME_NONNULL_END
