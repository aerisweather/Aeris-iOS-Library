//
//  AWFGMPolyline.h
//  AerisGoogleMap
//
//  Created by Nicholas Shipes on 8/19/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>
#import <AerisMap/AerisMap.h>

@interface AWFGMPolyline : AWFPolyline <AWFPolyline, AWFStyledMapItem>

@property (nonatomic, copy) NSString *identifier;
@property (readonly, nonatomic, strong) AWFObject *modelObject;
@property (readonly, nonatomic, strong) GMSPolyline *overlay;

@end
