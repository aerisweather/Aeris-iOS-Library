//
//  AWFGMPolyline.h
//  AerisGoogleMap
//
//  Created by Nicholas Shipes on 8/19/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>
#import <AerisMapKit/AerisMapKit.h>

@interface AWFGMPolyline : NSObject <AWFPolyline, AWFStyledMapItem>

/**
 The map representation of the polyline as required by Google Maps.
 */
@property (readonly, nonatomic, strong) GMSPolyline *overlay;

/**
 The group identifier for the annotation. This controls which style is used when multiple styles are available for a single layer source type.
 */
@property (nonatomic, copy) NSString *identifier;

/**
 The style associated with the polyline.
 */
@property (nonatomic, strong) id style;

/**
 The model object associated with the polyline, which is used for styling and callout information.
 */
@property (readonly, nonatomic, strong) AWFWeatherObject *modelObject;

@end
