//
//  AFTideStation.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

@interface AWFTideStation : AWFObject

/**
 *  Coop/station id.
 */
@property (nonatomic, copy) NSString *stationId;

/**
 *  Latitude position of the event.
 */
@property (nonatomic, retain) NSNumber *latitude;

/**
 *  Longitude position of the event.
 */
@property (nonatomic, retain) NSNumber *longitude;

/**
 *  Place or nearest place to the event.
 */
@property (nonatomic, copy) NSString *city;

/**
 *  Abbreviated state in which the event occurred.
 */
@property (nonatomic, copy) NSString *state;

/**
 *  Abbreviated country in which the event occurred.
 */
@property (nonatomic, copy) NSString *country;

/**
 *  Local time zone of the event location.
 */
@property (nonatomic, retain) NSTimeZone *timeZone;

/**
 *  The station type "harmonic" or "subordinate"
 */
@property (nonatomic, retain) NSNumber *type;

@end