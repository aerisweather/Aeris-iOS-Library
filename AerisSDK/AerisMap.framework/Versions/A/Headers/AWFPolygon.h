//
//  AWFPolygon.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/28/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

@class AWFGeographicObject;

@protocol AWFPolygon <NSObject>
@required
@property (nonatomic, copy) NSString *identifier;
@property (readonly, nonatomic, strong) AWFObject *modelObject;
@property (readonly, nonatomic, strong) id overlay;

@end

@interface AWFPolygon : NSObject

//@property (readonly, nonatomic, copy) NSString *identifier;
//@property (readonly, nonatomic, strong) AWFObject *modelObject;
//@property (readonly, nonatomic, strong) id overlay;

+ (instancetype)polygonWithGeographicObject:(AWFGeographicObject *)object;
+ (instancetype)polygonWithGeoPolygon:(AWFGeoPolygon *)geoPolygon;
+ (instancetype)polygon;

@end
