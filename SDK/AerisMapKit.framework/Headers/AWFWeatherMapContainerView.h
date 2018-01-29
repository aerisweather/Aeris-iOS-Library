//
//  AWFWeatherMapContainerView.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/11/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol AWFWeatherMapContainerViewDelegate;

/**
 `AWFWeatherMapContainerView` is a subclass of `UIView` that contains the stategy-specific map view for a weather map and manages user interactions
 necessary for additional weather map functionality, such as long-press to display current weather conditions at any location.
 */
@interface AWFWeatherMapContainerView : UIView <UIGestureRecognizerDelegate>

/**
 The tap gesture recognizer associated with the view.
 */
@property (nonatomic, strong, readonly) UITapGestureRecognizer *tapGestureRecognizer;

/**
 The long press gesture recognizer associated with the view.
 */
@property (nonatomic, strong, readonly) UILongPressGestureRecognizer *longPressRecognizer;

/**
 The long press gesture recognizer associated with the view and used to control the animated circle that initially appears while performing a long press
 on a weather map.
 */
@property (nonatomic, strong, readonly) UILongPressGestureRecognizer *longPressRecognizerForCircle;

/**
 The receiver's delegate.
 
 A map container view delegate is notified about the successful completion of gesture recognizers necessary to perform certain weather map
 functionality.
 */
@property (nonatomic, unsafe_unretained) id<AWFWeatherMapContainerViewDelegate> delegate;

@end



/**
 The `AWFWeatherMapContainerViewDelegate` protocol defines a set of optional methods that you can use to receive messages about the completion of
 gesture recognizers within the view.
 */
@protocol AWFWeatherMapContainerViewDelegate <NSObject>
@optional

/**
 Tells the delegate that a tap was received on the view.

 @param containerView The view that received the tap.
 @param point The point in the view's screen coordinates where the gesture occurred.
 */
- (void)weatherMapContainerView:(AWFWeatherMapContainerView *)containerView didReceiveTapAtPoint:(CGPoint)point;

/**
 Tells the delegate that a long press gesture was recognized and has begun.

 @param containerView The view that received the long press.
 @param point The point in the view's screen coordinates where the gesture occurred.
 */
- (void)weatherMapContainerView:(AWFWeatherMapContainerView *)containerView didStartLongPressGestureAtPoint:(CGPoint)point;

/**
 Tells the delegate that a long press gesture was recognized and has completed.

 @param containerView The view that received the long press.
 @param point The point in the view's screen coordinates where the gesture occurred.
 */
- (void)weatherMapContainerView:(AWFWeatherMapContainerView *)containerView didFinishLongPressGestureAtPoint:(CGPoint)point;

/**
 Tells the delegate that a long press gesture was cancelled.

 @param containerView The view that received the long press.
 */
- (void)weatherMapContainerViewDidCancelLongPressGesture:(AWFWeatherMapContainerView *)containerView;

@end
