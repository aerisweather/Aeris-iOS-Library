//
//  AFMoonPhase.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

@interface AWFMoonPhase : AWFObject

/**
 *  GMT date when the event took place.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Local time zone of the event location.
 */
@property (nonatomic, strong) NSTimeZone *timeZone;

/**
 *
 */
@property (nonatomic, strong) NSNumber *code;

/**
 *
 */
@property (nonatomic, copy) NSString *name;

@end