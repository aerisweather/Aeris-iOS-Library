//
//  AWFStormReportSummary.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/3/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

@interface AWFStormReportSummary : AWFObject

/**
 *  Starting date and time for the period.
 */
@property (nonatomic, strong) NSDate *rangeStartDate;

/**
 *  Ending date and time for the period.
 */
@property (nonatomic, strong) NSDate *rangeEndDate;

/**
 *  Total number of storm reports for the period.
 */
@property (strong, nonatomic) NSNumber *totalReports;

/**
 *  Array of states that have one or more storm reports for the period as abbreviations.
 */
@property (strong, nonatomic) NSArray *states;

/**
 *  An array of `AWFGeoPolygon` instances that define the groups of reports used within the summary.
 *
 *  In order to return polygons with your request, you must also include the `geo` filter with your request options. If this filter is not included and/or
 *  there are no report groups, then this value will be `nil`.
 */
@property (strong, nonatomic) NSArray *polygons;

/**
 *  Array of storm report summary types according to their report code/type.
 */
@property (strong, nonatomic) NSArray *types;

@end



@interface AWFStormReportSummaryType : AWFObject

/**
 *  Starting date and time for the period.
 */
@property (nonatomic, strong) NSDate *rangeStartDate;

/**
 *  Ending date and time for the period.
 */
@property (nonatomic, strong) NSDate *rangeEndDate;

/**
 *  Total number of storm reports for the period.
 */
@property (strong, nonatomic) NSNumber *totalReports;

/**
 *  Array of states that have one or more storm reports for the period as abbreviations.
 */
@property (strong, nonatomic) NSArray *states;

/**
 *  Report code as assigned by the National Weather Service (NWS).
 */
@property (nonatomic, copy) NSString *code;

/**
 *  For wind-related events, the minimum wind speed for all reports in miles per hour.
 */
@property (nonatomic, strong) NSNumber *minWindSpeedMPH;

/**
 *  For wind-related events, the minimum wind speed for all reports in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *minWindSpeedKMH;

/**
 *  For wind-related events, the minimum wind speed for all reports in knots.
 */
@property (nonatomic, strong) NSNumber *minWindSpeedKTS;

/**
 *  For wind-related events, the maximum wind speed for all reports in miles per hour.
 */
@property (nonatomic, strong) NSNumber *maxWindSpeedMPH;

/**
 *  For wind-related events, the maximum wind speed for all reports in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *maxWindSpeedKMH;

/**
 *  For wind-related events, the maximum wind speed for all reports in knots.
 */
@property (nonatomic, strong) NSNumber *maxWindSpeedKTS;

/**
 *  For wind-related events, the average wind speed for all reports in miles per hour.
 */
@property (nonatomic, strong) NSNumber *averageWindSpeedMPH;

/**
 *  For wind-related events, the average wind speed for all reports in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *averageWindSpeedKMH;

/**
 *  For wind-related events, the average wind speed for all reports in knots.
 */
@property (nonatomic, strong) NSNumber *averageWindSpeedKTS;

/**
 *  For rain/flood-related events, the minimum rainfall observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *minRainIN;

/**
 *  For rain/flood-related events, the minimum rainfall observed for all reports in millimeters.
 */
@property (nonatomic, strong) NSNumber *minRainMM;

/**
 *  For rain/flood-related events, the maximum rainfall observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *maxRainIN;

/**
 *  For rain/flood-related events, the maximum rainfall observed for all reports in millimeters.
 */
@property (nonatomic, strong) NSNumber *maxRainMM;

/**
 *  For rain/flood-related events, the average rainfall observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *averageRainIN;

/**
 *  For rain/flood-related events, the average rainfall observed for all reports in millimeters.
 */
@property (nonatomic, strong) NSNumber *averageRainMM;

/**
 *  For snow-related events, the minimum snowfall observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *minSnowIN;

/**
 *  For snow-related events, the minimum snowfall observed for all reports in centimeters.
 */
@property (nonatomic, strong) NSNumber *minSnowCM;

/**
 *  For snow-related events, the maximum snowfall observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *maxSnowIN;

/**
 *  For snow-related events, the maximum snowfall observed for all reports in centimeters.
 */
@property (nonatomic, strong) NSNumber *maxSnowCM;

/**
 *  For snow-related events, the average snowfall observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *averageSnowIN;

/**
 *  For snow-related events, the average snowfall observed for all reports in centimeters.
 */
@property (nonatomic, strong) NSNumber *averageSnowCM;

/**
 *  For hail-related events, the minimum hail stone diameter observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *minHailIN;

/**
 *  For hail-related events, the minimum hail stone diameter observed for all reports in millimeters.
 */
@property (nonatomic, strong) NSNumber *minHailMM;

/**
 *  For hail-related events, the maximum hail stone diameter observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *maxHailIN;

/**
 *  For hail-related events, the maximum hail stone diameter observed for all reports in millimeters.
 */
@property (nonatomic, strong) NSNumber *maxHailMM;

/**
 *  For hail-related events, the average hail stone diameter observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *averageHailIN;

/**
 *  For hail-related events, the average hail stone diameter observed for all reports in millimeters.
 */
@property (nonatomic, strong) NSNumber *averageHailMM;

/**
 *  For sleet-related events, the minimum sleet observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *minSleetIN;

/**
 *  For sleet-related events, the minimum sleet observed for all reports in centimeters.
 */
@property (nonatomic, strong) NSNumber *minSleetCM;

/**
 *  For sleet-related events, the maximum sleet observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *maxSleetIN;

/**
 *  For sleet-related events, the maximum sleet observed for all reports in centimeters.
 */
@property (nonatomic, strong) NSNumber *maxSleetCM;

/**
 *  For sleet-related events, the average sleet observed for all reports in inches.
 */
@property (nonatomic, strong) NSNumber *averageSleetIN;

/**
 *  For sleet-related events, the average sleet observed for all reports in centimeters.
 */
@property (nonatomic, strong) NSNumber *averageSleetCM;

@end