//
//  AWFMKAnnotationView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/28/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

@class AWFAnnotationStyle;

@interface AWFMKAnnotationView : MKAnnotationView

@property (readonly, nonatomic, strong) AWFAnnotationStyle *style;
@property (readonly, nonatomic, strong) CAShapeLayer *pointLayer;
@property (nonatomic, assign) BOOL reduceAnimatedEffects;
@property (nonatomic, assign) BOOL needsDisplayBeforeAddingToMap;
@property (readonly, nonatomic) BOOL hasAnimationCompleted;

- (instancetype)initWithAnnotation:(id<MKAnnotation>)annotation reuseIdentifier:(NSString *)reuseIdentifier style:(AWFAnnotationStyle *)style;
- (void)startAnimating __attribute__((objc_requires_super));
- (void)stopAnimating;
- (void)animateOut;

@end
