//
// AFTide.h
// Aeris
//
// Created by Nicholas Shipes on 9/6/13.
// Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

@class AWFTidePeriod;

/**
 An `AWFTide` object represents data returned by the [**tides** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/tides/)
 of the Aeris Weather API.
 */
@interface AWFTide : AWFGeographicObject

/**
 Station identifier that the tide data is based on.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 Array of `AWFTidePeriod` instances that contain the tidal information, where each object is for a specific tidal period (high, low etc).
 */
@property (nonatomic, copy, nullable) NSArray<AWFTidePeriod *> *periods;

@end


/**
 An `AWFTidePeriod` object contains tide data for a specific time period.
 */
@interface AWFTidePeriod : AWFWeatherObject

/**
 GMT date when the event took place.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Local time zone of the event location.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

/**
 Type of tide, "l" for low and "h" for high.
 */
@property (nonatomic, strong, nullable) NSString *type;

/**
 Tide height in feet.
 */
@property (nonatomic, assign) CGFloat heightFT;

/**
 Tide height in meters.
 */
@property (nonatomic, assign) CGFloat heightM;

@end
