//
//  AWFEarthquakeAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/17/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFAnnotationStyle.h>
#import <AerisMapKit/AWFGroupedStyle.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFEarthquakeAnnotationType NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFEarthquakeAnnotationType const AWFEarthquakeAnnotationTypeMini;
FOUNDATION_EXPORT AWFEarthquakeAnnotationType const AWFEarthquakeAnnotationTypeMinor;
FOUNDATION_EXPORT AWFEarthquakeAnnotationType const AWFEarthquakeAnnotationTypeLight;
FOUNDATION_EXPORT AWFEarthquakeAnnotationType const AWFEarthquakeAnnotationTypeModerate;
FOUNDATION_EXPORT AWFEarthquakeAnnotationType const AWFEarthquakeAnnotationTypeStrong;
FOUNDATION_EXPORT AWFEarthquakeAnnotationType const AWFEarthquakeAnnotationTypeMajor;
FOUNDATION_EXPORT AWFEarthquakeAnnotationType const AWFEarthquakeAnnotationTypeGreat;
FOUNDATION_EXPORT AWFEarthquakeAnnotationType const AWFEarthquakeAnnotationTypeCatastrophic;

/**
 An `AWFEarthquakeAnnotationStyle` object provides the style specifications to be used for an earthquake-related annotation's representation on a map.
 */
@interface AWFEarthquakeAnnotationStyle : AWFAnnotationStyle <AWFGroupedStyle>

/**
 The stroke color for the outer ring.
 */
@property (nonatomic, strong, nullable) UIColor *ringColor;

/**
 The stroke width for the outer ring.
 */
@property (nonatomic, assign) CGFloat ringWidth;

/**
 A Boolean value indicating whether the annotation should show the outer ring, which is usually animated.
 */
@property (nonatomic, assign) BOOL showsRing;

/**
 The duration of the ring animation in seconds.
 */
@property (nonatomic, assign) CGFloat ringAnimationDuration;

/**
 The total number of times the ring animation should be repeated.
 */
@property (nonatomic, assign) CGFloat ringAnimationRepeatCount;

@end

NS_ASSUME_NONNULL_END
