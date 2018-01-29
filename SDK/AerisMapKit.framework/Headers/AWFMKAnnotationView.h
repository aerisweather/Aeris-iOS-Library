//
//  AWFMKAnnotationView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/28/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisMapKit/AWFAnnotationView.h>
#import <AerisMapKit/AWFMKAnnotation.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFAnnotationStyle;

/**
 The `AWFMKAnnotationView` class is a sublcass of `MKAnnotationView` that supports annotation style and animation effects 
 when rendered on a map view.
 */
@interface AWFMKAnnotationView : MKAnnotationView <AWFAnnotationView>

/**
 The annotation object currently associated with the view.
 */
@property (nonatomic, strong) AWFMKAnnotation *annotation;

/**
 The annotation style used for rendering the annotation.
 */
@property (readonly, nonatomic, strong) AWFAnnotationStyle *style;

/**
 The layer in which the annotation is rendered.
 */
@property (readonly, nonatomic, strong) CAShapeLayer *pointLayer;

/**
 A Boolean value that determines whether the annotation view should reduce or eliminate animations.
 */
@property (nonatomic, assign) BOOL reduceAnimatedEffects;

/**
 A Boolean value that determines whether the annotation view should be rendered before being added to a map view.
 */
@property (nonatomic, assign) BOOL needsDisplayBeforeAddingToMap;

/**
 A Boolean value that indicates whether the initial presentation animation has completed.
 */
@property (readonly, nonatomic) BOOL hasAnimationCompleted;

/**
 Initializes and returns a newly allocated annotation view for the specified annotation, identifier and style.

 @param annotation The annotation object to associate with the view.
 @param reuseIdentifier The identifier string for the view when reusing annotation views.
 @param style The style specification for the annotation view.
 @return An initialized annotation view.
 */
- (instancetype)initWithAnnotation:(AWFMKAnnotation *)annotation reuseIdentifier:(NSString *)reuseIdentifier style:(AWFAnnotationStyle *)style;

/**
 Performs the presentation animation if one has been configured with for the associated annotation `style`.
 
 If the annotation belongs to a timeline animation, this animation will be only be performed once instead of repeating.
 */
- (void)startAnimating __attribute__((objc_requires_super));

/**
 Removes all animations from the annotation.
 */
- (void)stopAnimating;

/**
 Performs the dismissal animation if one has been configured with for the associated annotation `style`.
 */
- (void)animateOut;

@end

NS_ASSUME_NONNULL_END
