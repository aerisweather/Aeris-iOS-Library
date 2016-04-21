//
//  AWFAnnotation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/20/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

/**
 *  An `AWFAnnotation` object is the base class used for all annotations within the library.
 */
@interface AWFAnnotation : NSObject <MKAnnotation>

/**
 *  The string containing the annotation's title.
 */
@property (nonatomic, copy) NSString *title;

/**
 *  The string containing the annotation's subtitle.
 */
@property (nonatomic, copy) NSString *subtitle;

/**
 *  The center point (specified as a map coordinate) of the annotation.
 */
@property (readonly, nonatomic) CLLocationCoordinate2D coordinate;

/**
 *  Initializes and returns a newly allocated annotation object for the specified `coordinate`.
 *
 *  @param coordinate The coordinate of the annotation
 *
 *  @return An initialized annotation or `nil` if the object couldn't be created.
 */
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

@end