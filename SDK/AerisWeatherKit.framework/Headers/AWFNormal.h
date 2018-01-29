//
//  AFNormal.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFNormalPeriod;

/**
 An `AWFNormal` object represents data returned by the [**normals** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/normals/)
 of the Aeris Weather API.
 */
@interface AWFNormal : AWFGeographicObject

/**
 The coop/station id that the normal data is based on.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 Array of AWFNormalPeriod objects that contain the normals, where each object is for a specific period (day, month, year etc).
 */
@property (nonatomic, strong, nullable) NSArray<AWFNormalPeriod *> *periods;

@end


/**
 An `AWFNormalPeriod` object represents data for a single period returned by the [**normals** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/normals/)
 of the Aeris Weather API.
 */
@interface AWFNormalPeriod : AWFWeatherObject

//-----------------------------------------------------------------------------
// @name Period Details
//-----------------------------------------------------------------------------

/**
 Type of normal: "daily", "monthly" or "annual".
 */
@property (nonatomic, copy, nullable) NSString *type;

/**
 Number of the month the period is for (1=January, 12=December). Value will be NULL for annual summaries.
 */
@property (nonatomic, assign) NSInteger month;

/**
 Day of the month the period is for (1-31). Value will be NULL for both monthly and annual summaries.
 */
@property (nonatomic, assign) NSInteger date;

//-----------------------------------------------------------------------------
// @name Temperature
//-----------------------------------------------------------------------------

/**
 Normal maximum temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat tempMaxF;

/**
 Normal maximum temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat tempMaxC;

/**
 Normal minimum temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat tempMinF;

/**
 Normal minimum temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat tempMinC;

/**
 Normal average temperature in degrees Fahrenheit.
 */
@property (nonatomic, assign) CGFloat tempAvgF;

/**
 Normal average temperature in degrees Celsius.
 */
@property (nonatomic, assign) CGFloat tempAvgC;

//-----------------------------------------------------------------------------
// @name Precipitation
//-----------------------------------------------------------------------------

/**
 Normal precipitation in inches for the month to date. Value will be NULL for annual summaries.
 */
@property (nonatomic, assign) CGFloat precipMonthToDateIN;

/**
 Normal precipitation in millimeters for the month to date. Value will be NULL for annual summaries.
 */
@property (nonatomic, assign) CGFloat precipMonthToDateMM;

/**
 Normal precipitation in inches for the year to date.
 */
@property (nonatomic, assign) CGFloat precipYearToDateIN;

/**
 Normal precipitation in millimeters for the year to date.
 */
@property (nonatomic, assign) CGFloat precipYearToDateMM;

/**
 Normal snowfall in inches for the month to date. Value will be NULL for annual summaries.
 */
@property (nonatomic, assign) CGFloat snowMonthToDateIN;

/**
 Normal snowfall in centimeters for the month to date. Value will be NULL for annual summaries.
 */
@property (nonatomic, assign) CGFloat snowMonthToDateCM;

/**
 Normal snowfall in inches for the year to date.
 */
@property (nonatomic, assign) CGFloat snowYearToDateIN;

/**
 Normal snowfall in centimeters for the year to date.
 */
@property (nonatomic, assign) CGFloat snowYearToDateCM;

//-----------------------------------------------------------------------------
// @name Degree Days
//-----------------------------------------------------------------------------

/**
 Normal heating degree days.
 */
@property (nonatomic, assign) CGFloat heatingDegreeDays;

/**
 Normal cooling degree days.
 */
@property (nonatomic, assign) CGFloat coolingDegreeDays;

@end

NS_ASSUME_NONNULL_END
