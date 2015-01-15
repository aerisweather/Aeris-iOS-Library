//
//  AWFGMMultiShapeOverlay.h
//  AerisGoogleMap
//
//  Created by Nicholas Shipes on 8/19/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>

@interface AWFGMMultiShapeOverlay : GMSGroundOverlay <AWFStyledMapItem, AWFMultiShapeOverlay>

@property (nonatomic, strong) NSArray *polygons;
@property (nonatomic, strong) NSArray *polylines;

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, assign) AWFLayerType layerType;
@property (nonatomic, strong) AWFMapItemStyle *mapStyle;

- (void)invalidate;

@end
