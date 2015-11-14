//
//  AWFMultiShapeOverlayView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/15/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

@interface AWFMultiShapeOverlayView : MKPolygonView

@property (nonatomic, assign) CGFloat arrowheadWidth;
@property (nonatomic, assign) CGFloat arrowheadLength;
@property (nonatomic, strong) UIColor *arrowColor;

@end
