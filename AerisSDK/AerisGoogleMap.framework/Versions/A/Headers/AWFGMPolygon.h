//
//  AWFGMPolygon.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/28/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>
#import <AerisMap/AWFPolygon.h>

@class AWFObject;

@interface AWFGMPolygon : AWFPolygon <AWFPolygon>

@property (nonatomic, copy) NSString *identifier;
@property (readonly, nonatomic, strong) AWFObject *modelObject;
@property (readonly, nonatomic, strong) GMSPolygon *overlay;

@end
