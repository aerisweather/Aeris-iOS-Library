//
//  AWFMultiShapeOverlayRenderer.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/15/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisMap/AWFMultiShapeOverlay.h>

@interface AWFMultiShapeOverlayRenderer : MKOverlayRenderer

@property (nonatomic, strong) UIColor *fillColor;
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, assign) CGFloat lineWidth;
@property (nonatomic, assign) CGLineJoin lineJoin;
@property (nonatomic, assign) CGLineCap lineCap;
@property (nonatomic, assign) CGFloat miterLimit;
@property (nonatomic, strong) NSArray *lineDashPattern;
@property (nonatomic, assign) CGFloat lineDashPhase;

@property (nonatomic, assign) AWFArrowheadType arrowheadType;
@property (nonatomic, assign) CGFloat arrowheadWidth;
@property (nonatomic, assign) CGFloat arrowheadLength;
@property (nonatomic, strong) UIColor *arrowColor;

@end
