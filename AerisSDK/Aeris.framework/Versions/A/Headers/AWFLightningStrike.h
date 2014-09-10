//
//  AFLightning.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFLightningStrike : AWFGeographicObject

/**
 *  GMT date of the strike.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *
 */
@property (nonatomic, copy) NSString *pulseType;

/**
 *
 */
@property (nonatomic, strong) NSNumber *peakAmperage;

@end