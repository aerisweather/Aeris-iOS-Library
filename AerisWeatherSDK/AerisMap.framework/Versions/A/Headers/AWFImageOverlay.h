//
//  AWFImageOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

@class AWFCoordinateBounds;

@interface AWFImageOverlay : NSObject <MKOverlay>

- (instancetype)initWithCoordinateBounds:(AWFCoordinateBounds *)bounds;

@end
