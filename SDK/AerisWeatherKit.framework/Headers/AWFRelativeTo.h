//
//  AWFRelativeTo.h
//  Aeris
//
//  Created by Nicholas Shipes on 3/21/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFRelativeTo` object provides information about the geographical relationship between a location that is used for a request and the location
 of the objects that are actually returned from that request.
 */
@interface AWFRelativeTo : AWFWeatherObject

/**
 Bearing, in degrees, of the event or object's actual location relative to the requested location.
 */
@property (nonatomic, assign) CGFloat bearing;

/**
 Cardinal direction of the event or object relative to the requested location.
 */
@property (nonatomic, copy, nullable) NSString *bearingENG;

/**
 Distance, in kilometers, from the requested location to the object or event.
 */
@property (nonatomic, assign) CGFloat distanceKM;

/**
 Distance, in miles, from the requested location to the object or event.
 */
@property (nonatomic, assign) CGFloat distanceMI;

/**
 Latitude coordinate of the location used for the request.
 */
@property (nonatomic, assign) CGFloat latitude;

/**
 Longitude coordinate of the location used for the request.
 */
@property (nonatomic, assign) CGFloat longitude;

@end

NS_ASSUME_NONNULL_END
