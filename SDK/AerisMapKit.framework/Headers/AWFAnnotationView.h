//
//  AWFAnnotationView.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 12/20/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

@protocol AWFAnnotation;
@class AWFAnnotationStyle;

NS_ASSUME_NONNULL_BEGIN

/**
 The `AWFAnnotationView` protocol represents an annotation renderer, typically an instance of `UIView` or `MKAnnotationView`, that manages animating the
 annotation while displayed on a map.
 */
@protocol AWFAnnotationView <NSObject>

/**
 The annotation object currently associated with the view.
 */
@property (nonatomic, strong) id<AWFAnnotation> annotation;

/**
 The annotation style used for rendering the annotation.
 */
//@property (readonly, nonatomic, strong) AWFAnnotationStyle *style;

- (instancetype)initWithAnnotation:(id<AWFAnnotation>)annotation reuseIdentifier:(NSString *)reuseIdentifier style:(AWFAnnotationStyle *)style;

/**
 Performs the presentation animation if one has been configured with for the associated annotation `style`.
 
 If the annotation belongs to a timeline animation, this animation will be only be performed once instead of repeating.
 */
- (void)startAnimating;

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
