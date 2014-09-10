//
//  AWFPolyline.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/15/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AWFGeographicObject;

@protocol AWFPolyline <NSObject>
@required
@property (readonly, nonatomic, strong) id overlay;

@end

@interface AWFPolyline : NSObject

+ (instancetype)polylineWithGeoPolygon:(AWFGeoPolygon *)geoPolygon;
+ (instancetype)polyline;

@end
