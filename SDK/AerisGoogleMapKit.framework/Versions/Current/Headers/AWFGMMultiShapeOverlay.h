//
//  AWFGMMultiShapeOverlay.h
//  AerisGoogleMap
//
//  Created by Nicholas Shipes on 8/19/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>
#import <AerisMapKit/AerisMapKit.h>

@interface AWFGMMultiShapeOverlay : NSObject <AWFStyledMapItem, AWFMultiShapeOverlay>

@property (readonly, nonatomic, strong) GMSGroundOverlay *overlay;

@property (nonatomic, strong) NSArray<GMSPolygon *> *polygons;
@property (nonatomic, strong) NSArray<GMSPolyline *> *polylines;

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic) AWFMapLayer layerType;

/**
 The style associated with the polygon.
 */
@property (nonatomic, strong) id style;

- (void)invalidate;

@end
