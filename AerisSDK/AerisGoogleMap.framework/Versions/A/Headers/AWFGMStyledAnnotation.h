//
//  AWFGMStyledAnnotation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/23/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>
#import <AerisMap/AWFStyledAnnotation.h>

@class AWFObject, AWFAnnotationStyle;

@interface AWFGMStyledAnnotation : GMSMarker <MKAnnotation, AWFStyledAnnotation>

@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, strong) UIImage *image;
@property (readonly, nonatomic, strong) AWFAnnotationStyle *annotationStyle;
@property (readonly, nonatomic, strong) CAShapeLayer *pointLayer;

@property (readonly, nonatomic, copy) NSString *identifier;
@property (readonly, nonatomic, strong) AWFObject *modelObject;
@property (nonatomic, assign, getter = isAnimatable) BOOL animatable;
@property (nonatomic, assign) BOOL belongsToTimelineAnimation;

- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate modelObject:(AWFObject *)modelObject style:(AWFAnnotationStyle *)style;
- (void)startAnimating __attribute__((objc_requires_super));
- (void)stopAnimating;
- (void)animateOut;
- (void)applyStyle:(AWFAnnotationStyle *)style;

@end
