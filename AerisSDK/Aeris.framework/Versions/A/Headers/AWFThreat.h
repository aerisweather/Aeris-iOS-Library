//
//  AWFThreat.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@class AWFStormThreat;

@interface AWFThreat : AWFGeographicObject

/**
 *  Array of `AWFThreatPeriod` instances for the current and future periods as supported.
 */
@property (nonatomic, strong) NSArray *periods;

@end


@interface AWFThreatPeriod : AWFObject

/**
 *  GMT date for the period.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  The storm threat for the period, or `nil` if no threat exists.
 */
@property (nonatomic, strong) AWFStormThreat *stormThreat;

@end