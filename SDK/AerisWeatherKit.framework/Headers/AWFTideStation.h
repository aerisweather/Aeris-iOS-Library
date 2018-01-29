//
//  AFTideStation.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

/**
 An `AWFTideStation` object represents data returned by the [**tides/stations** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/tides-stations/)
 of the Aeris Weather API.
 */
@interface AWFTideStation : AWFWeatherObject

/**
 Coop/station id.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 Latitude position of the event.
 */
@property (nonatomic, assign) CGFloat latitude;

/**
 Longitude position of the event.
 */
@property (nonatomic, assign) CGFloat longitude;

/**
 Place or nearest place to the event.
 */
@property (nonatomic, copy, nullable) NSString *city;

/**
 Abbreviated state in which the event occurred.
 */
@property (nonatomic, copy, nullable) NSString *state;

/**
 Abbreviated country in which the event occurred.
 */
@property (nonatomic, copy, nullable) NSString *country;

/**
 Local time zone of the event location.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

/**
 The station type "harmonic" or "subordinate"
 */
@property (nonatomic, assign) CGFloat type;

@end
