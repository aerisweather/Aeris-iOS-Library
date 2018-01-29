//
//  AWFMKPolygon.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/19/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFPolygon.h>
#import <AerisMapKit/AWFPolygonStyle.h>
#import <AerisMapKit/AWFStyledMapItem.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFMKPolygon` object is an instance of `MKPolygon` that represents a stylable polygon that is added to a map view.
 */
@interface AWFMKPolygon : MKPolygon <AWFPolygon, AWFStyledMapItem>

/**
 The group identifier for the polygon. This controls which style is used when multiple styles are available for a single layer source type.
 */
@property (nonatomic, copy, nullable) NSString *identifier;

/**
 The style associated with the polygon.
 */
@property (nonatomic, strong, nullable) AWFPolygonStyle *style;

/**
 The model object that is represented by the polygon.
 */
@property (readonly, nonatomic, strong, nullable) AWFWeatherObject *modelObject;

/**
 The geometric centroid of the polygon.
 */
@property (nonatomic, assign) CLLocationCoordinate2D centroid;

/**
 The area of the polygon.
 */
@property (nonatomic, assign) CGFloat area;

+ (instancetype)polygon NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
