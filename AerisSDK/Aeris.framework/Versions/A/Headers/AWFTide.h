//
// AFTide.h
// Aeris
//
// Created by Nicholas Shipes on 9/6/13.
// Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFTide : AWFGeographicObject

/**
 *  Station ID that the tide data is based on.
 */
@property (nonatomic, copy) NSString *stationId;

/**
 *  Array of `AWFTidePeriod` instances that contain the tidal information, where each object is for a specific tidal period (high, low etc).
 */
@property (nonatomic, copy) NSArray *periods;

@end


@interface AWFTidePeriod : AWFObject

/**
 *  GMT date when the event took place.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Local time zone of the event location.
 */
@property (nonatomic, strong) NSTimeZone *timeZone;

/**
 *  Type of tide, "l" for low and "h" for high.
 */
@property (nonatomic, strong) NSString *type;

/**
 *  Tide height in feet.
 */
@property (nonatomic, strong) NSNumber *heightFT;

/**
 *  Tide height in meters.
 */
@property (nonatomic, strong) NSNumber *heightM;

@end