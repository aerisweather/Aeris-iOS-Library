//
//  AWFGMAnnotationView.h
//  AerisGoogleMapKit
//
//  Created by Nicholas Shipes on 12/20/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisMapKit/AerisMapKit.h>
#import <AerisGoogleMapKit/AWFGMAnnotation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AWFGMAnnotationView : UIView <AWFAnnotationView>

@property (nonatomic, nullable) AWFGMAnnotation *annotation;
@property (readonly, nonatomic, strong) AWFAnnotationStyle *style;
@property (readonly, nonatomic, strong) CAShapeLayer *pointLayer;
@property (nonatomic, assign) BOOL reduceAnimatedEffects;
@property (nonatomic, assign) BOOL needsDisplayBeforeAddingToMap;
@property (readonly, nonatomic) BOOL hasAnimationCompleted;

- (instancetype)initWithAnnotation:(AWFGMAnnotation *)annotation reuseIdentifier:(NSString *)reuseIdentifier style:(AWFAnnotationStyle *)style;
- (void)startAnimating __attribute__((objc_requires_super));
- (void)stopAnimating;
- (void)animateOut;

@end

NS_ASSUME_NONNULL_END
