//
//  AWFEarthquakeAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/17/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFAnnotationStyle.h>

/**
 *  An `AWFEarthquakeAnnotationStyle` object provides the style specifications to be used for an earthquake-related annotation's representation on a map.
 */
@interface AWFEarthquakeAnnotationStyle : AWFAnnotationStyle

/**
 *  The stroke color for the outer ring.
 */
@property (nonatomic, strong) UIColor *ringColor;

/**
 *  The stroke width for the outer ring.
 */
@property (nonatomic, assign) CGFloat ringWidth;

/**
 *  A Boolean value indicating whether the annotation should show the outer ring, which is usually animated.
 */
@property (nonatomic, assign) BOOL showsRing;

/**
 *  The duration of the ring animation in seconds.
 */
@property (nonatomic, assign) CGFloat ringAnimationDuration;

/**
 *  The total number of times the ring animation should be repeated.
 */
@property (nonatomic, assign) CGFloat ringAnimationRepeatCount;

@end
