//
//  AWFAnimationContainer.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/15/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

@class AWFCoordinateBounds;

@interface AWFAnimationContainer : NSObject <MKAnnotation>

@property (readonly, nonatomic) CLLocationCoordinate2D coordinate;
@property (readonly, nonatomic) AWFCoordinateBounds *coordinateBounds;

- (void)setCoordinate:(CLLocationCoordinate2D)newCoordinate;
- (void)setCoordinateBounds:(AWFCoordinateBounds *)newCoordinateBounds;

@end
