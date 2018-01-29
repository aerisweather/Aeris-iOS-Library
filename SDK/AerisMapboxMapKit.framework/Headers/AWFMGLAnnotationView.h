//
//  AWFMGLAnnotationView.h
//  AerisMapboxMapKit
//
//  Created by Nicholas Shipes on 11/16/16.
//  Copyright © 2016 AerisWeather, LLC. All rights reserved.
//

#import <Mapbox/Mapbox.h>
#import <AerisMapKit/AerisMapKit.h>
#import <AerisMapboxMapKit/AWFMGLAnnotation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AWFMGLAnnotationView : MGLAnnotationView <AWFAnnotationView>

@property (nonatomic, nullable) id <MGLAnnotation, AWFAnnotation> annotation;
@property (readonly, nonatomic, strong) AWFAnnotationStyle *style;
@property (readonly, nonatomic, strong) CAShapeLayer *pointLayer;
@property (nonatomic, assign) BOOL reduceAnimatedEffects;
@property (nonatomic, assign) BOOL needsDisplayBeforeAddingToMap;
@property (readonly, nonatomic) BOOL hasAnimationCompleted;

- (instancetype)initWithAnnotation:(AWFMGLAnnotation *)annotation reuseIdentifier:(NSString *)reuseIdentifier style:(AWFAnnotationStyle *)style;
- (void)startAnimating __attribute__((objc_requires_super));
- (void)stopAnimating;
- (void)animateOut;

@end

NS_ASSUME_NONNULL_END
