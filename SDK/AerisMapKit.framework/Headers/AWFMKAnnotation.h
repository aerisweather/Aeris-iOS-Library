//
//  AWFMKAnnotation.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 12/2/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisMapKit/AWFAnnotation.h>
#import <AerisMapKit/AWFStyledMapItem.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFAnnotationStyle;

/**
 An `AWFMKAnnotation` object adopts the `AWFAnnotation` protocol and represents a stylable annotation that is added to a map view.
 */
@interface AWFMKAnnotation : NSObject <MKAnnotation, AWFAnnotation, AWFStyledMapItem>

/**
 The group identifier for the annotation. This controls which style is used when multiple styles are available for a single layer source type.
 */
@property (nonatomic, copy, nullable) NSString *identifier;

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
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

/**
 The style associated with the annotation.
 */
@property (nonatomic, strong, nullable) AWFAnnotationStyle *style;

/**
 The model object that is represented by the annotation.
 */
@property (nonatomic, strong, readonly, nullable) AWFWeatherObject *modelObject;

/**
 Whether or not the instance belongs to a timeline animation.
 */
@property (nonatomic, assign) BOOL belongsToTimelineAnimation;

@end

NS_ASSUME_NONNULL_END
