//
//  AWFMGLPolygon.h
//  AerisMapboxMapKit
//
//  Created by Nicholas Shipes on 11/15/16.
//  Copyright © 2016 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AerisMapKit.h>
#import <Mapbox/Mapbox.h>

@interface AWFMGLPolygon : MGLPolygon <AWFPolygon, AWFStyledMapItem>

/**
 The group identifier for the annotation. This controls which style is used when multiple styles are available for a single layer source type.
 */
@property (nonatomic, copy) NSString *identifier;

/**
 The style associated with the polygon.
 */
@property (nonatomic, strong) AWFPolygonStyle *style;

/**
 The model object associated with the polygon, which is used for styling and callout information.
 */
@property (readonly, nonatomic, strong) AWFWeatherObject *modelObject;

/**
 The geometric centroid of the polygon.
 */
@property (nonatomic, assign) CLLocationCoordinate2D centroid;

/**
 The area of the polygon.
 */
@property (nonatomic, assign) CGFloat area;

@end
