//
//  AWFAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/17/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFAnnotation.h>
#import <AerisMapKit/AWFMapItemStyle.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^AWFCalloutFormatter)(NSObject<AWFAnnotation> *annotation);

/**
 The `AWFOverlayStylable` protocol is adopted by an object that provides the style specifications for a map overlay.
 */
@protocol AWFOverlayStylable <NSObject>

/**
 The style specification for map overlays.
 */
@property (nonatomic, strong) AWFMapItemStyle *overlay;

@end

/**
 An `AWFAnnotationStyle` object provides the style specifications to be used for an annotation's representation on a map.
 */
@interface AWFAnnotationStyle : AWFMapItemStyle

/**
 Radius of the annotation's shape.
 */
@property (nonatomic, assign) CGFloat radius;

/**
 Image to apply to the annotation.
 */
@property (nonatomic, strong, nullable) UIImage *image;

/**
 The inset or outset margins for the rectangle around the annotation's image.
 */
@property (nonatomic, assign) UIEdgeInsets imageEdgeInsets;

/**
 A Boolean value indicating whether the specified image should be scaled down to fit within the radius value.
 
 The default value is `YES`, meaning the image will be scaled down as needed.
 */
@property (nonatomic, assign) BOOL resizesImageToBounds;

/**
 A Boolean value indicating whether the point should be displayed.
 
 This value is typically used when providing an image to display for the annotation. If this value is `YES` and an image is also
 specified, then the image will appear over the annotation's point. The default value is `YES`.
 */
@property (nonatomic, assign) BOOL showsPoint;

/**
 Whether or not the annotation should be filled.
 */
@property (nonatomic, assign, getter=isFilled) BOOL filled;

/**
 The offset (in pixels) relative to the annotation coordinate at which to display the annotation view.
 */
@property (nonatomic, assign) CGPoint centerOffset;

/**
 A Boolean value indicating whether the annotation is enabled.
 
 @see MKAnnotation
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

/**
 A block that is used to format the callout content when presenting.
 */
@property (readonly, nonatomic, nullable) AWFCalloutFormatter calloutFormatter;

/**
 A Boolean value indicating whether the annotation view is able to display extra information in a callout bubble.
 
 @see MKAnnotation
 */
@property (nonatomic, assign) BOOL canShowCallout;

/**
 A Boolean value indicating whether the annotation is animatable.
 */
@property (nonatomic, assign, getter=isAnimatable) BOOL animatable;

/**
 A Boolean value indicating whether the view associated with the annotation should be animated.
 */
@property (nonatomic, assign) BOOL shouldAnimate;

/**
 The number of seconds to display the annotation before hiding when part of a weather map animation.
 */
@property (nonatomic, assign) NSTimeInterval animationSecondsToHideAfterDisplaying;

/**
 The initial transform to apply to the annotation view when animating. Default is `CATransform3DIdentity`.
 */
@property (nonatomic, assign) CATransform3D transform;

/**
 The `CAAnimation` instance to use when presenting the annotation.
 */
@property (nonatomic, strong, nullable) CAAnimation *inAnimation;

/**
 The `CAAnimation` instance to use when dismissing the annotation.
 */
@property (nonatomic, strong, nullable) CAAnimation *outAnimation;

/**
 The image to display for the annotation.
 */
@property (nonatomic, strong, nullable) UIImage *icon;

/**
 Initializes and returns a style object with the specified style options.
 
 @param radius      The radius of the annotation.
 @param fillColor   The color used to fill the annotation.
 @param strokeColor The color used to stroke the annotation.
 @param strokeWidth The line width of the annotation's stroke.
 @return The initialized style object.
 */
+ (instancetype)styleWithRadius:(CGFloat)radius fillColor:(UIColor *)fillColor strokeColor:(UIColor *)strokeColor strokeWidth:(CGFloat)strokeWidth;

/**
 Initializes and returns a style object with the specified image.
 
 @param image The image to use for the annotation.
 @return The initialized style object.
 */
+ (instancetype)styleWithImage:(UIImage *)image;

/**
 Generates an image representation of the annotation's view based on the style specifications.
 
 @return An image representation of the annotation.
 */
- (nullable UIImage *)imageFromStyle;

/**
 Sets the formatting block to use for the annotation's callout content.

 @param calloutFormatter The formatting block
 */
- (void)setCalloutFormatter:(nullable AWFCalloutFormatter)calloutFormatter;

/**
 Presents the annotation view by applying the `inAnimation` animation to the specified `layer`.
 
 @param layer The layer to apply the animation to
 */
- (void)applyPresentationAnimationToLayer:(CALayer *)layer;

/**
 Dismisses the annotation view by applying the `outAnimation` animation to the specified `layer`.
 
 @param layer The layer to apply the animation to
 */
- (void)applyDismissAnimationToLayer:(CALayer *)layer;

/**
 Returns the default annotation style for the specified layer type. This may return a single instance of `AWFAnnotationStyle`, or if there are multiple
 styles associated with a layer type this method will return an instance of `AWFGroupedStyle`.

 @param layerType The layer type to return the default style for
 @return Either an instance of `AWFAnnotationStyle` or `AWFGroupedStyle`
 */
+ (nullable id)defaultStyleForLayerType:(AWFMapLayer)layerType;

@end

NS_ASSUME_NONNULL_END
