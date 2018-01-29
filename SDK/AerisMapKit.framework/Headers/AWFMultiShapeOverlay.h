//
//  AWFMultiShapeOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/19/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AWFArrowheadType) {
	AWFArrowheadTypeNone = 0,
	AWFArrowheadTypeHead,
	AWFArrowheadTypeTail
};

@class AWFMapItemStyle;
@protocol AWFPolygon;
@protocol AWFPolyline;

/**
 The `AWFMultiShapeOverlay` protocol defines the properties and methods required by an overlay instance that renders multiple types of elements 
 into a single overlay renderer, such as both polygon and polylines.
 */
@protocol AWFMultiShapeOverlay <NSObject>
@optional

/**
 Initializes and returns an overlay instance with the specified arrays of polygons and polylines.

 @param polygons The polygons to render
 @param polylines The polylines to render
 @return An instantiated overlay instance
 */
- (instancetype)initWithPolygons:(nullable NSArray<id<AWFPolygon>> *)polygons polylines:(nullable NSArray<id<AWFPolyline>> *)polylines;

/**
 Sets the polygons and polylines to be rendered with the overlay.

 @param polygons The polygons to render
 @param polylines The polylines to render
 */
- (void)updatePolygons:(nullable NSArray<id<AWFPolygon>> *)polygons polylines:(nullable NSArray<id<AWFPolyline>> *)polylines;

@end

NS_ASSUME_NONNULL_END
