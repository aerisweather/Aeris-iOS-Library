//
//  AFGMAnnotation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>

@protocol AWFGMAnnoation <NSObject>
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) GMSMapView *map;
@end

@interface AWFGMAnnotation : GMSMarker <AWFGMAnnoation>

@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, strong) UIImage *image;

- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

@end
