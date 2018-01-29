//
//  AWFMKPolyline.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/15/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFPolyline.h>
#import <AerisMapKit/AWFStyledMapItem.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFMKPolyline` object is an instance of `MKPolyline` that represents a stylable polyline that is added to a map view.
 */
@interface AWFMKPolyline : MKPolyline <AWFPolyline, AWFStyledMapItem>

/**
 The group identifier for the polygon. This controls which style is used when multiple styles are available for a single layer source type.
 */
@property (nonatomic, copy, nullable) NSString *identifier;

/**
 The model object that is represented by the polyline.
 */
@property (readonly, nonatomic, strong, nullable) AWFWeatherObject *modelObject;

@end

NS_ASSUME_NONNULL_END
