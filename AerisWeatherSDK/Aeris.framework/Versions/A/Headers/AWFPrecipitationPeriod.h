//
//  AWFPrecipitationPeriod.h
//  Aeris
//
//  Created by Nicholas Shipes on 4/5/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFPrecipitationPeriod : AWFGeographicObject

/**
 *  Date the period is for.
 */
@property (strong, nonatomic) NSDate *timestamp;
@property (strong, nonatomic) NSTimeZone *timeZone;

@property (strong, nonatomic) NSNumber *dailyIN;
@property (strong, nonatomic) NSNumber *dailyMM;
@property (strong, nonatomic) NSNumber *monthlyIN;
@property (strong, nonatomic) NSNumber *monthlyMM;
@property (strong, nonatomic) NSNumber *yearlyIN;
@property (strong, nonatomic) NSNumber *yearlyMM;

@end
