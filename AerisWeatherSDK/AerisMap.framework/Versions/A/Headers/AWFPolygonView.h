//
//  AWFPolygonView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/28/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

@class AWFAnnotationStyle;

@interface AWFPolygonView : MKPolygonView

@property (readonly, nonatomic, strong) AWFAnnotationStyle *style;

@end
