//
//  AWFAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/17/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFMapItemStyle.h>

/**
 *  An `AWFAnnotationStyle` object provides the style specifications to be used for an annotation's representation on a map.
 */
@interface AWFAnnotationStyle : AWFMapItemStyle

/**
 *  Radius of the annotation's shape.
 */
@property (nonatomic, assign) CGFloat radius;

/**
 *  Image to apply to the annotation.
 */
@property (nonatomic, strong) UIImage *image;

/**
 *  The inset or outset margins for the rectangle around the annotation's image.
 */
@property (nonatomic, assign) UIEdgeInsets imageEdgeInsets;

/**
 *  A Boolean value indicating whether the specified image should be scaled down to fit within the radius value.
 *
 *  The default value is `YES`, meaning the image will be scaled down as needed.
 */
@property (nonatomic, assign) BOOL resizesImageToBounds;

/**
 *  A Boolean value indicating whether the point should be displayed.
 *
 *  This value is typically used when providing an image to display for the annotation. If this value is `YES` and an image is also
 *  specified, then the image will appear over the annotation's point. The default value is `YES`.
 */
@property (nonatomic, assign) BOOL showsPoint;

/**
 *  Whether or not the annotation should be filled.
 */
@property (nonatomic, assign, getter = isFilled) BOOL filled;

/**
 *  The offset (in pixels) relative to the annotation coordinate at which to display the annotation view.
 */
@property (nonatomic, assign) CGPoint centerOffset;

/**
 *  A Boolean value indicating whether the annotation is enabled.
 *
 *  @see MKAnnotation
 */
@property (nonatomic, assign, getter = isEnabled) BOOL enabled;

/**
 *  A Boolean value indicating whether the annotation view is able to display extra information in a callout bubble.
 *
 *  @see MKAnnotation
 */
@property (nonatomic, assign) BOOL canShowCallout;

/**
 *  A Boolean value indicating whether the view associated with the annotation should be animated.
 */
@property (nonatomic, assign) BOOL shouldAnimate;

@property (nonatomic, assign) NSTimeInterval animationSecondsToHideAfterDisplaying;

@property (nonatomic, assign) CATransform3D transform;
@property (nonatomic, strong) CAAnimation *inAnimation;
@property (nonatomic, strong) CAAnimation *outAnimation;

@property (nonatomic, strong) UIImage *icon;

/**
 *  Initializes and returns a style object with the specified style options.
 *
 *  @param radius      The radius of the annotation.
 *  @param fillColor   The color used to fill the annotation.
 *  @param strokeColor The color used to stroke the annotation.
 *  @param strokeWidth The line width of the annotation's stroke.
 *
 *  @return The initialized style object.
 */
+ (instancetype)styleWithRadius:(CGFloat)radius fillColor:(UIColor *)fillColor strokeColor:(UIColor *)strokeColor strokeWidth:(CGFloat)strokeWidth;

/**
 *  Initializes and returns a style object with the specified image.
 *
 *  @param image The image to use for the annotation.
 *
 *  @return The initialized style object.
 */
+ (instancetype)styleWithImage:(UIImage *)image;

/**
 *  Generates an image representation of the annotation's view based on the style specifications.
 *
 *  @return An image representation of the annotation.
 */
- (UIImage *)imageFromStyle;

- (void)applyPresentationAnimationToLayer:(CALayer *)layer;
- (void)applyDismissAnimationToLayer:(CALayer *)layer;

@end