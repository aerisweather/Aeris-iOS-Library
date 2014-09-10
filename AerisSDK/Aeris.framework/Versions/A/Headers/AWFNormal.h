//
//  AFNormal.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFNormal : AWFGeographicObject

/**
 *  The coop/station id that the normal data is based on.
 */
@property (nonatomic, copy) NSString *stationId;

/**
 *  Array of AWFNormalPeriod objects that contain the normals, where each object is for a specific period (day, month, year etc).
 */
@property (nonatomic, strong) NSArray *periods;

@end

@interface AWFNormalPeriod : AWFObject

//-----------------------------------------------------------------------------
// @name Period Details
//-----------------------------------------------------------------------------

/**
 *  Type of normal: "daily", "monthly" or "annual".
 */
@property (nonatomic, copy) NSString *type;

/**
 *  Number of the month the period is for (1=January, 12=December). Value will be NULL for annual summaries.
 */
@property (nonatomic, strong) NSNumber *month;

/**
 *  Day of the month the period is for (1-31). Value will be NULL for both monthly and annual summaries.
 */
@property (nonatomic, strong) NSNumber *date;

//-----------------------------------------------------------------------------
// @name Temperature
//-----------------------------------------------------------------------------

/**
 *  Normal maximum temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *tempMaxF;

/**
 *  Normal maximum temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *tempMaxC;

/**
 *  Normal minimum temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *tempMinF;

/**
 *  Normal minimum temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *tempMinC;

/**
 *  Normal average temperature in degrees Fahrenheit.
 */
@property (nonatomic, strong) NSNumber *tempAvgF;

/**
 *  Normal average temperature in degrees Celsius.
 */
@property (nonatomic, strong) NSNumber *tempAvgC;

//-----------------------------------------------------------------------------
// @name Precipitation
//-----------------------------------------------------------------------------

/**
 *  Normal precipitation in inches for the month to date. Value will be NULL for annual summaries.
 */
@property (nonatomic, strong) NSNumber *precipMonthToDateIN;

/**
 *  Normal precipitation in millimeters for the month to date. Value will be NULL for annual summaries.
 */
@property (nonatomic, strong) NSNumber *precipMonthToDateMM;

/**
 *  Normal precipitation in inches for the year to date.
 */
@property (nonatomic, strong) NSNumber *precipYearToDateIN;

/**
 *  Normal precipitation in millimeters for the year to date.
 */
@property (nonatomic, strong) NSNumber *precipYearToDateMM;

/**
 *  Normal snowfall in inches for the month to date. Value will be NULL for annual summaries.
 */
@property (nonatomic, strong) NSNumber *snowMonthToDateIN;

/**
 *  Normal snowfall in centimeters for the month to date. Value will be NULL for annual summaries.
 */
@property (nonatomic, strong) NSNumber *snowMonthToDateCM;

/**
 *  Normal snowfall in inches for the year to date.
 */
@property (nonatomic, strong) NSNumber *snowYearToDateIN;

/**
 *  Normal snowfall in centimeters for the year to date.
 */
@property (nonatomic, strong) NSNumber *snowYearToDateCM;

//-----------------------------------------------------------------------------
// @name Degree Days
//-----------------------------------------------------------------------------

/**
 *  Normal heating degree days.
 */
@property (nonatomic, strong) NSNumber *heatingDegreeDays;

/**
 *  Normal cooling degree days.
 */
@property (nonatomic, strong) NSNumber *coolingDegreeDays;

@end