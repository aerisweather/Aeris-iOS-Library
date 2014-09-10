//
//  AFAnnotation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <Aeris/Aeris.h>

@protocol AWFStyledAnnotation <NSObject>
@required

@property (readonly, nonatomic, copy) NSString *identifier;
@property (readonly, nonatomic, strong) AWFObject *modelObject;

- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate modelObject:(AWFObject *)object;
- (instancetype)initWithGeographicObject:(AWFGeographicObject *)object;

@end

@interface AWFStyledAnnotation : NSObject <MKAnnotation, AWFStyledAnnotation>

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property (readonly, nonatomic) CLLocationCoordinate2D coordinate;

@property (readonly, nonatomic, copy) NSString *identifier;
@property (readonly, nonatomic, strong) AWFObject *modelObject;
@property (nonatomic, assign, getter = isAnimatable) BOOL animatable;
@property (nonatomic, assign) BOOL belongsToTimelineAnimation;

@end