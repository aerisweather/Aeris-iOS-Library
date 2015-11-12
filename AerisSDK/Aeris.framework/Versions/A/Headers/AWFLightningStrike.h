//
//  AFLightning.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

extern NSString * const AWFLightningStrikeFilterAll;
extern NSString * const AWFLightningStrikeFilterCloudToGround;
extern NSString * const AWFLightningStrikeFilterCloudToCloud;

extern NSString * const AWFLightningStrikeFieldDateTime;

@interface AWFLightningStrike : AWFGeographicObject

/**
 *  GMT date of the strike.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Type of lightning strike, either cloud-to-cloud (IC) or cloud-to-ground (CG).
 */
@property (nonatomic, copy) NSString *pulseType;

/**
 *  Peak electric current in amps.
 */
@property (nonatomic, strong) NSNumber *peakAmperage;

@end