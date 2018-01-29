//
//  AWFMultiShapeOverlayRenderer.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/15/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisMapKit/AWFMultiShapeOverlay.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFMKMultiShapeOverlayRenderer` is an `MKOverlayRenderer` subclass that draws the visual representation of the polygons and polylines 
 associated with an `AWFMKMultiShapeOverlay` instance.
 */
@interface AWFMKMultiShapeOverlayRenderer : MKOverlayRenderer

/**
 The color used to fill polygon shapes.
 */
@property (nonatomic, strong, nullable) UIColor *fillColor;

/**
 The color used to stroke polygon and polyline paths.
 */
@property (nonatomic, strong, nullable) UIColor *strokeColor;

/**
 The line width of polygon and polyline paths.
 */
@property (nonatomic, assign) CGFloat lineWidth;

/**
 The line join style for all shape paths.
 */
@property (nonatomic, assign) CGLineJoin lineJoin;

/**
 The line cap style for all shape paths.
 */
@property (nonatomic, assign) CGLineCap lineCap;

/**
 The miter limit used when stroking the shape paths.
 */
@property (nonatomic, assign) CGFloat miterLimit;

/**
 The dash pattern applied to the shape paths when stroked.
 */
@property (nonatomic, strong, nullable) NSArray *lineDashPattern;

/**
 The dash phase applied to the shape paths when stroked.
 */
@property (nonatomic, assign) CGFloat lineDashPhase;

/**
 The arrow head style to be used for polylines.
 */
@property (nonatomic, assign) AWFArrowheadType arrowheadType;

/**
 The width of the polyline arrowheads.
 */
@property (nonatomic, assign) CGFloat arrowheadWidth;

/**
 The length of the polyline arrowheads.
 */
@property (nonatomic, assign) CGFloat arrowheadLength;

/**
 The color used to fill the arrowheads.
 */
@property (nonatomic, strong, nullable) UIColor *arrowColor;

@end

NS_ASSUME_NONNULL_END
