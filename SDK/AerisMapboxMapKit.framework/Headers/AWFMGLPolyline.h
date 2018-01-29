//
//  AWFMGLPolyline.h
//  AerisMapboxMapKit
//
//  Created by Nicholas Shipes on 11/16/16.
//  Copyright © 2016 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AerisMapKit.h>
#import <Mapbox/Mapbox.h>

@interface AWFMGLPolyline : MGLPolyline <AWFPolyline, AWFStyledMapItem>

/**
 The group identifier for the annotation. This controls which style is used when multiple styles are available for a single layer source type.
 */
@property (nonatomic, copy) NSString *identifier;

/**
 The model object associated with the polyline, which is used for styling and callout information.
 */
@property (readonly, nonatomic, strong) AWFWeatherObject *modelObject;

@end
