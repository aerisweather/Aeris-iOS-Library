//
//  AWFMKArrow.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/15/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

@interface AWFMKArrow : MKMultiPoint <MKOverlay>

@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;
@property (nonatomic, readonly) MKMapRect boundingMapRect;

+ (instancetype)arrowWithCoordinates:(CLLocationCoordinate2D *)coord count:(NSUInteger)count;
+ (instancetype)arrowWithPoints:(MKMapPoint *)points count:(NSUInteger)count;

@end
