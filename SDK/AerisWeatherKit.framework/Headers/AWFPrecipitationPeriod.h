//
//  AWFPrecipitationPeriod.h
//  Aeris
//
//  Created by Nicholas Shipes on 4/5/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <AerisWeatherKit/AWFGeographicObject.h>

@interface AWFPrecipitationPeriod : AWFGeographicObject

/**
 Date the period is for.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

@property (nonatomic, assign) CGFloat dailyIN;
@property (nonatomic, assign) CGFloat dailyMM;
@property (nonatomic, assign) CGFloat monthlyIN;
@property (nonatomic, assign) CGFloat monthlyMM;
@property (nonatomic, assign) CGFloat yearlyIN;
@property (nonatomic, assign) CGFloat yearlyMM;

@end
