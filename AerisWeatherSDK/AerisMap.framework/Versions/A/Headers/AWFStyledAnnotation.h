//
//  AFAnnotation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <Aeris/Aeris.h>
#import <AerisMap/AWFAnnotation.h>

/**
 *  The `AWFStyledAnnotation` protocol is adopted by an object that provides style information for an annotation that is intended to be styled based on the
 *  associated model object.
 */
@protocol AWFStyledAnnotation <NSObject>
@required

/**
 *  The identifier of the annotation based on the model object.
 */
@property (readonly, nonatomic, copy) NSString *identifier;

/**
 *  The model object associated with the annotation, which is used for styling and callout information.
 */
@property (readonly, nonatomic, strong) AWFObject *modelObject;

/**
 *  Initializes and returns a newly allocated annotation object for the specified `coordinate` and `modelObject`.
 *
 *  @param coordinate The coordinate of the annoation
 *  @param object     The model object the annotation represents
 *
 *  @return An initialized annotation or `nil` if the object couldn't be created.
 */
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate modelObject:(AWFObject *)object;

/**
 *  Initializes an returns a newly allocated annotation object for the specified geographic model object.
 *
 *  The annotation's coordinate will be assigned based on the `coordinate` property of the `AWFGeographicObject` instance provided.
 *
 *  @param object The `AWFGeographicObject` model object the annotation represents
 *
 *  @return An initialized annotation or `nil` if the object couldn't be created.
 */
- (instancetype)initWithGeographicObject:(AWFGeographicObject *)object;

@end

@interface AWFStyledAnnotation : AWFAnnotation <AWFStyledAnnotation>

/**
 *  The identifier of the annotation based on the model object.
 */
@property (readonly, nonatomic, copy) NSString *identifier;

/**
 *  The model object associated with the annotation, which is used for styling and callout information.
 */
@property (readonly, nonatomic, strong) AWFObject *modelObject;

/**
 *  A Boolean value indicating whether the annotation is animatable.
 */
@property (nonatomic, assign, getter = isAnimatable) BOOL animatable;

/**
 *  A Boolean value indicating whether the annotation belongs to a timeline animation.
 */
@property (nonatomic, assign) BOOL belongsToTimelineAnimation;

@end