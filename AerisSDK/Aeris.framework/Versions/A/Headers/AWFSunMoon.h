//
//  AFSunMoon.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFSunMoon : AWFGeographicObject

/**
 *  GMT date for the day the information is for.
 */
@property (nonatomic, strong) NSDate *timestamp;

//-----------------------------------------------------------------------------
// @name Sun Information
//-----------------------------------------------------------------------------

/**
 *  GMT date for the sunrise.
 */
@property (nonatomic, strong) NSDate *sunrise;

/**
 *  GMT date for the sunset.
 */
@property (nonatomic, strong) NSDate *sunset;

/**
 *  GMT date for the point at which the sun is directly overhead.
 */
@property (nonatomic, strong) NSDate *sunTransit;

/**
 *  GMT date for the first civil twilight.
 */
@property (nonatomic, strong) NSDate *twilightCivilBegin;

/**
 *  GMT date for the second civil twilight.
 */
@property (nonatomic, strong) NSDate *twilightCivilEnd;

/**
 *  GMT date for the first nautical twilight.
 */
@property (nonatomic, strong) NSDate *twilightNauticalBegin;

/**
 *  GMT date for the second nautical twilight.
 */
@property (nonatomic, strong) NSDate *twilightNauticalEnd;

/**
 *  GMT date for the first astronomical twilight.
 */
@property (nonatomic, strong) NSDate *twilightAstronomicalBegin;

/**
 *  GMT date for the second astronomical twilight.
 */
@property (nonatomic, strong) NSDate *twilightAstronomicalEnd;

//-----------------------------------------------------------------------------
// @name Moon Information
//-----------------------------------------------------------------------------

/**
 *  GMT date for the moon rise.
 */
@property (nonatomic, strong) NSDate *moonrise;

/**
 *  GMT date for the moon set.
 */
@property (nonatomic, strong) NSDate *moonset;

/**
 *  Moon phase as a percentage.
 */
@property (nonatomic, strong) NSNumber *moonPhasePercentage;

/**
 *  Name of the moon phase.
 */
@property (nonatomic, copy) NSString *moonPhaseName;

/**
 *  Percentage of the moon that is illuminated.
 */
@property (nonatomic, strong) NSNumber *moonIllumination;

/**
 *  Age of the moon phase in days.
 */
@property (nonatomic, strong) NSNumber *moonAge;

/**
 *  Angle of the moon phase.
 */
@property (nonatomic, strong) NSNumber *moonAngle;

@end