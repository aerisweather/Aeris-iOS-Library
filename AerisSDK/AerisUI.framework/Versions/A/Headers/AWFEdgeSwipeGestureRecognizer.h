//
//  AWFEdgeSwipeGestureRecognizer.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/7/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

typedef NS_ENUM(NSUInteger, AWFEdgeSwipeGestureRecognizerSide) {
	AWFEdgeSwipeGestureRecognizerSideLeft = 0,
	AWFEdgeSwipeGestureRecognizerSideRight,
	AWFEdgeSwipeGestureRecognizerSideTop,
	AWFEdgeSwipeGestureRecognizerSideBottom
};

/**
 *  A `AWFEdgeSwipeGestureRecognizer` looks for panning (dragging) gestures that start near an edge of a particular view instead of the screen.
 */

@interface AWFEdgeSwipeGestureRecognizer : UIPanGestureRecognizer

//-----------------------------------------------------------------------------
// @name Configuring the Gesture
//-----------------------------------------------------------------------------

/**
 *  From which edge to detect the swipe.
 */
@property (nonatomic, assign) AWFEdgeSwipeGestureRecognizerSide side;

/**
 *  Minimum distance that must be traveled before recognizing the direction.
 */
@property (nonatomic, assign) CGFloat minimumDistance;

/**
 *  Margin from the side used to detect the gesture.
 */
@property (nonatomic, assign) CGFloat margin;

@end

//-----------------------------------------------------------------------------
// @name Constants
//-----------------------------------------------------------------------------

/**
 ## AWFEdgeSwipeGestureRecognizerSide
 
 
 The following constants are provided as possible edge sides.
 
 typedef enum {
      AWFEdgeSwipeGestureRecognizerSideLeft = 0,
      AWFEdgeSwipeGestureRecognizerSideRight,
      AWFEdgeSwipeGestureRecognizerSideTop,
      AWFEdgeSwipeGestureRecognizerSideBottom
 }
 
 `AWFEdgeSwipeGestureRecognizerSideLeft`
 Detects a pan gesture from the left edge of the view. This is the default side.
 
 `AWFEdgeSwipeGestureRecognizerSideRight`
 Detects a pan gesture from the right edge of the view.
 
 `AWFEdgeSwipeGestureRecognizerSideTop`
 Detects a pan gesture from the top edge of the view.
 
 `AWFEdgeSwipeGestureRecognizerSideBottom`
 Detects a pan gesture from the bottom edge of the view.
 */