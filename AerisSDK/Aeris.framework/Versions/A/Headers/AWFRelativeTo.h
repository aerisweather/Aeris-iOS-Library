//
//  AWFRelativeTo.h
//  Aeris
//
//  Created by Nicholas Shipes on 3/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

/**
 *  An `AWFRelativeTo` object provides information about the geographical relationship between a location that is used for a request and the location
 *  of the objects that are actually returned from that request.
 *  @since 2.0
 */
@interface AWFRelativeTo : AWFObject

/**
 *  Bearing, in degrees, of the event or object's actual location relative to the requested location.
 */
@property (nonatomic, strong) NSNumber *bearing;

/**
 *  Cardinal direction of the event or object relative to the requested location.
 */
@property (nonatomic, copy) NSString *bearingENG;

/**
 *  Distance, in kilometers, from the requested location to the object or event.
 */
@property (nonatomic, strong) NSNumber *distanceKM;

/**
 *  Distance, in miles, from the requested location to the object or event.
 */
@property (nonatomic, strong) NSNumber *distanceMI;

/**
 *  Latitude coordinate of the location used for the request.
 */
@property (nonatomic, strong) NSNumber *latitude;

/**
 *  Longitude coordinate of the location used for the request.
 */
@property (nonatomic, strong) NSNumber *longitude;

@end