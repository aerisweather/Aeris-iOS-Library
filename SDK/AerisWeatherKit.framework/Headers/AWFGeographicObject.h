//
//  AFGeographicObject.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFPlace;
@class AWFRelativeTo;

/**
 An `AWFGeographicObject` object is an `AWFWeatherObject` subclass that represents data for a specific geographical location. The geographical location can
 either be a coordinate or a place and is represented by an `AWFPlace` instance.
 */
@interface AWFGeographicObject : AWFWeatherObject

/**
 Location and place information associated with this object.
 @see AWFPlace
 */
@property (nonatomic, strong, nullable) AWFPlace *place;

/**
 An object representing the actual location used for the request and its geographical position relative to this object.
 @see AWFRelativeTo
 */
@property (nonatomic, strong, nullable) AWFRelativeTo *relativeTo;

@end

NS_ASSUME_NONNULL_END
