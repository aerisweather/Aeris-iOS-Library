//
//  AWFAnnotation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/20/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisWeatherKit/AerisWeatherKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `AWFAnnotation` protocol represents an annotation object on a weather map and provides the common set of properties and methods for
 annotation items across different mapping libraries.
 */
@protocol AWFAnnotation <NSObject>

/**
 The string containing the annotation's title.
 */
@property (nonatomic, copy, nullable) NSString *title;

/**
 The string containing the annotation's subtitle.
 */
@property (nonatomic, copy, nullable) NSString *subtitle;

/**
 The center point (specified as a map coordinate) of the annotation.
 */
@property (readonly, nonatomic) CLLocationCoordinate2D coordinate;

/**
 The model object associated with the annotation, which is used for styling and callout information.
 */
@property (readonly, nonatomic, strong, nullable) AWFWeatherObject *modelObject;

/**
 A Boolean value indicating whether the annotation belongs to a timeline animation.
 */
@property (nonatomic, assign) BOOL belongsToTimelineAnimation;

/**
 Initializes and returns a newly allocated annotation object for the specified `coordinate`.
 *
 @param coordinate The coordinate of the annotation
 *
 @return An initialized annotation or `nil` if the object couldn't be created.
 */
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 Initializes and returns a newly allocated annotation object for the specified `coordinate` and `modelObject`.
 *
 @param coordinate The coordinate of the annoation
 @param object     The model object the annotation represents
 *
 @return An initialized annotation or `nil` if the object couldn't be created.
 */
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate modelObject:(nullable AWFWeatherObject *)object;

@end

NS_ASSUME_NONNULL_END
