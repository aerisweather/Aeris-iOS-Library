//
//  AWFCalloutView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/19/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 The supported arrow directions for a callout view.

 - AWFCalloutArrowDirectionUp: Callout arrow points up towards the target.
 - AWFCalloutArrowDirectionDown: Callout arrow points down towards the target.
 - AWFCalloutArrowDirectionAny: Callout arrow direction is determined based on the target and constrained bounds.
 */
typedef NS_ENUM(NSUInteger, AWFCalloutArrowDirection) {
    AWFCalloutArrowDirectionUp = 1UL << 0,
    AWFCalloutArrowDirectionDown = 1UL << 1,
    AWFCalloutArrowDirectionAny = AWFCalloutArrowDirectionUp | AWFCalloutArrowDirectionDown
};

/**
 The supported animation options for presenting a callout view.

 - AWFCalloutAnimationBounce: The standard bounce animation the native UICalloutView uses.
 - AWFCalloutAnimationFade: Simple fade in or out.
 - AWFCalloutAnimationStretch: Grows or shrinks linearly like in the iPad Calendar app.
 */
typedef NS_ENUM(NSInteger, AWFCalloutAnimation) {
    AWFCalloutAnimationBounce,
    AWFCalloutAnimationFade,
    AWFCalloutAnimationStretch
};

// when delaying our popup in order to scroll content into view, you can use this amount to match the
// animation duration of UIScrollView when using -setContentOffset:animated.
extern NSTimeInterval kAWFCalloutViewRepositionDelayForUIScrollView;

@protocol AWFCalloutViewDelegate;
@class __AWFCalloutBackgroundView;

/**
 `AWFCalloutView` is a lightweight callout view that mimic's the native UICalloutView in iOS that offers greater flexibility and supports being used
 outside of MapKit.
 */
@interface AWFCalloutView : UIView

/**
 The title for the callout.
 */
@property (nonatomic, copy) NSString *title;

/**
 The subtitle for the callout.
 */
@property (nonatomic, copy) NSString *subtitle;

/**
 The view to display on the left side of the callout view.
 */
@property (nonatomic, strong) UIView *leftAccessoryView;

/**
 The view to display on the right side of the callout view.
 */
@property (nonatomic, strong) UIView *rightAccessoryView;

/**
 The arrow directions that are permitted when presenting a callout view. The default value is `AWFCalloutArrowDirectionDown`.
 */
@property (nonatomic, assign) AWFCalloutArrowDirection permittedArrowDirection;

/**
 The current arrow direction used for the callout view.
 */
@property (nonatomic, readonly) AWFCalloutArrowDirection currentArrowDirection;

/**
 The insets to apply to the constrained view's bounds, specifically if the specified constrained view has portions that are overlapped by a navigation bar,
 tab bar or other navigation element.
 */
@property (nonatomic, assign) UIEdgeInsets constrainedInsets;

@property (nonatomic, strong) __AWFCalloutBackgroundView *backgroundView; // default is AWFCalloutMaskedBackgroundView, or AWFCalloutDrawnBackgroundView when using SMClassicCalloutView

/**
 The receiver's delegate.
 
 A callout view sends messages to its delegate regarding the presentation and dismissal of a callout view.
 */
@property (nonatomic, unsafe_unretained) id<AWFCalloutViewDelegate> delegate;

/**
 The view to display for the title.
 
 If this property is set, then `title` will be ignored.
 
 @note Keep in mind that `AWFCalloutView` calls `sizeThatFits` on this view if provided, so your view may be resized as a result, especially for `UILabel`
 and `UITextField`. You may want to subclass and override `sizeThatFits`, or just wrap your view in a generic `UIView` if you do not want it to be auto-sized.
 */
@property (nonatomic, strong) UIView *titleView;

/**
 The view to display for the subtitle.
 
 If this property is set, then `subtitle` will be ignored.
 
 @note Keep in mind that `AWFCalloutView` calls `sizeThatFits` on this view if provided, so your view may be resized as a result, especially for `UILabel`
 and `UITextField`. You may want to subclass and override `sizeThatFits`, or just wrap your view in a generic `UIView` if you do not want it to be auto-sized.
 */
@property (nonatomic, strong) UIView *subtitleView;

/**
 The custom content view that can be any width and/or height.
 
 If this property is set, then `title`, `subtitle`, `titleView`, and `subtitleView` are all ignored.
 */
@property (nonatomic, strong) UIView *contentView;

/**
 The custom content view margin.
 */
@property (nonatomic, assign) UIEdgeInsets contentViewInset;

/**
 The offset in screen points from the top-middle of the annotation view where the anchor of the callout should be drawn.
 */
@property (nonatomic, assign) CGPoint calloutOffset;

/**
 The animation style to use when presenting the callout view. The default is `AWFCalloutAnimationBounce`.
 */
@property (nonatomic, assign) AWFCalloutAnimation presentAnimation;

/**
 The animation style to use when dismissing the callout view. The default is `AWFCalloutAnimationFade`.
 */
@property (nonatomic, assign) AWFCalloutAnimation dismissAnimation;

/**
 Returns a new instance of `AWFCalloutView` that mimics the platform's native callout style.
 */
+ (AWFCalloutView *)platformCalloutView;

/**
 Presents a callout view by adding it to the specified `inView` and pointing at the given rect of `inView`'s bounds.
 
 The callout is constrained to the bounds of the given view. This method optionally scrolls the given rect into view (plus margins) if `delegate` is
 set and responds to `delayForRepositionWithSize:`.

 @param rect The rect at which the callout points.
 @param view The view in which to add the callout view.
 @param constrainedView The view whose bounds are used to constrain the callout view.
 @param animated `YES` if the presentation should be animated, otherwise `NO`.
 */
- (void)presentCalloutFromRect:(CGRect)rect inView:(UIView *)view constrainedToView:(UIView *)constrainedView animated:(BOOL)animated;

/**
 Presents a callout view by adding it to the specified layer and pointing at the given rect of the layer's bounds.

 The callout is constrained to the bounds of the given layer. This method optionally scrolls the given rect into view (plus margins) if `delegate` is
 set and responds to `delayForRepositionWithSize:`.
 
 @note Be aware that you'll have to direct your own touches to any accessory views presenting within a layer since `CALayer` doesn't relay touch events.

 @param rect The rect at which the callout points.
 @param layer The layer in which to add the callout view.
 @param constrainedLayer The layer whose bounds are used to constrain the callout view.
 @param animated `YES` if the presentation should be animated, otherwise `NO`.
 */
- (void)presentCalloutFromRect:(CGRect)rect inLayer:(CALayer *)layer constrainedToLayer:(CALayer *)constrainedLayer animated:(BOOL)animated;

/**
 Updates the callout position by providing a new target rect and view.
 
 @param rect  The rect to move the callout to
 @param view The view in which the callout will appear
 @param constrainedView The view in which the callout should be constrained to
 */
- (void)moveCalloutToRect:(CGRect)rect inView:(UIView *)view constrainedToView:(UIView *)constrainedView;

/**
 Updates the callout position by providing a new target rect and layer.
 
 @param rect The rect to move the callout to
 @param layer The layer in which the callout will appear
 @param constrainedLayer The layer in which the callout will be constrained to
 */
- (void)moveCalloutToRect:(CGRect)rect inLayer:(CALayer *)layer constrainedToLayer:(CALayer *)constrainedLayer;

/**
 Dismisses the callout.
 
 @param animated A Boolean indicating if the dismissal should be animated using a fade out effect.
 */
- (void)dismissCalloutAnimated:(BOOL)animated;

/**
 Updates the callout's layout and size by recalculating the size needed for its subviews, specifically when changing the contentView bounds.
 
 @param animated A Boolean indicating whether the layout change should be animated
 */
- (void)updateLayoutAnimated:(BOOL)animated;

/**
 When subclassing `AWFCalloutView`, this method allows you to return a custom animation to use when presenting and/or dismissing the callout.

 @param type The animation type.
 @param presenting A Boolean value indicating whether the callout is being presented, `YES`, or dismissed, `NO`.
 @return The animation to use for the action.
 */
- (CAAnimation *)animationWithType:(AWFCalloutAnimation)type presenting:(BOOL)presenting;

@end

// Abstract base class
@interface __AWFCalloutBackgroundView : UIView
@property (nonatomic, assign) CGPoint arrowPoint; // indicates where the tip of the arrow should be drawn, as a pixel offset
@property (nonatomic, assign) BOOL highlighted; // will be set by the callout when the callout is in a highlighted state
@property (nonatomic, assign) CALayer *contentMask; // returns an optional layer whose contents should mask the callout view's contents (not honored by SMClassicCalloutView)
@end

// Default for iOS 7, this reproduces the "masked" behavior of the iOS 7-style callout view.
// Accessories are masked by the shape of the callout (including the arrow itself).
@interface __AWFCalloutMaskedBackgroundView : __AWFCalloutBackgroundView
@end

@protocol AWFCalloutViewDelegate <NSObject>
@optional

// Implementing this method allows the callout to be "clicked" like a button, with highlight state. default YES.
// Not honored by SMClassicCalloutView.
- (void)calloutViewClicked:(AWFCalloutView *)calloutView;

// Called when the callout view detects that it will be outside the constrained view when it appears,
// or if the target rect was already outside the constrained view. You can implement this selector to
// respond to this situation by repositioning your content first in order to make everything visible. The
// CGSize passed is the calculated offset necessary to make everything visible (plus a nice margin).
// It expects you to return the amount of time you need to reposition things so the popup can be delayed.
// Typically you would return kAWFCalloutViewRepositionDelayForUIScrollView if you're repositioning by
// calling [UIScrollView setContentOffset:animated:].
- (NSTimeInterval)calloutView:(AWFCalloutView *)calloutView delayForRepositionWithSize:(CGSize)offset;

// Called before the callout view appears on screen, or before the appearance animation will start.
- (void)calloutViewWillAppear:(AWFCalloutView*)calloutView;

// Called after the callout view appears on screen, or after the appearance animation is complete.
- (void)calloutViewDidAppear:(AWFCalloutView *)calloutView;

// Called before the callout view is removed from the screen, or before the disappearance animation is complete.
- (void)calloutViewWillDisappear:(AWFCalloutView*)calloutView;

// Called after the callout view is removed from the screen, or after the disappearance animation is complete.
- (void)calloutViewDidDisappear:(AWFCalloutView *)calloutView;

@end
