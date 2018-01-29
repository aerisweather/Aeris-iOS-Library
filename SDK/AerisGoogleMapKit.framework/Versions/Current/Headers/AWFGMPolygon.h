//
//  AWFGMPolygon.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/28/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>
#import <AerisMapKit/AerisMapKit.h>

@class AWFWeatherObject;

@interface AWFGMPolygon : NSObject <AWFPolygon, AWFStyledMapItem>

/**
 The map representation of the polygon as required by Google Maps.
 */
@property (readonly, nonatomic, strong) GMSPolygon *overlay;

/**
 The group identifier for the annotation. This controls which style is used when multiple styles are available for a single layer source type.
 */
@property (nonatomic, copy) NSString *identifier;

/**
 The style associated with the polygon.
 */
@property (nonatomic, strong) id style;

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
