//
//  AWFMGLMultiShapeOverlay.h
//  AerisMapboxMapKit
//
//  Created by Nicholas Shipes on 11/22/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AerisMapKit.h>
#import <Mapbox/Mapbox.h>

@protocol AWFMGLMultiShapeOverlayDataSource <NSObject>

- (CGPoint)pointForMapCoordinate:(CLLocationCoordinate2D)coord;
- (CLLocationCoordinate2D)mapCoordinateForPoint:(CGPoint)point;

@end

@interface AWFMGLMultiShapeOverlay : NSObject <MGLOverlay, AWFStyledMapItem, AWFMultiShapeOverlay>

@property (readonly, nonatomic, strong) MGLShapeSource *source;
@property (readonly, nonatomic, strong) MGLFillStyleLayer *layer;

@property (readonly, nonatomic, strong) MGLShapeSource *arrowSource;
@property (readonly, nonatomic, strong) MGLFillStyleLayer *arrowLayer;

@property (readonly, nonatomic, strong) NSArray<MGLPolygon *> *polygons;
@property (readonly, nonatomic, strong) NSArray<MGLPolyline *> *polylines;

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic) AWFMapLayer layerType;

/**
 The style associated with the polygon.
 */
@property (nonatomic, strong) id style;

@property (nonatomic, unsafe_unretained) id<AWFMGLMultiShapeOverlayDataSource> dataSource;

- (void)invalidate;

@end
