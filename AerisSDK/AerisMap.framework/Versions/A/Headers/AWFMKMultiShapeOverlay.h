//
//  AWFMultiShapeOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/15/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFLayerType.h>
#import <AerisMap/AWFStyledMapItem.h>
#import <AerisMap/AWFMultiShapeOverlay.h>

@interface AWFMKMultiShapeOverlay : NSObject <AWFStyledMapItem, AWFMultiShapeOverlay, MKOverlay>

@property (nonatomic, strong) NSArray *polygons;
@property (nonatomic, strong) NSArray *polylines;

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, assign) AWFLayerType layerType;

@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;
@property (nonatomic, readonly) MKMapRect boundingMapRect;

- (instancetype)initWithPolygons:(NSArray *)polygons polylines:(NSArray *)polylines;
- (void)updatePolygons:(NSArray *)polygons polylines:(NSArray *)polylines;

@end
