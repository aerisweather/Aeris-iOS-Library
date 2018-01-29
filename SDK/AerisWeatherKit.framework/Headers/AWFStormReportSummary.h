//
//  AWFStormReportSummary.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/3/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

@class AWFStormReportSummaryType;
@class AWFGeoPolygon;

/**
 An `AWFStormReportSummary` object represents data returned by the [**stormreports/summary** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/stormreports-summary/)
 of the Aeris Weather API.
 */
@interface AWFStormReportSummary : AWFWeatherObject

/**
 Starting date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeStartDate;

/**
 Ending date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeEndDate;

/**
 Total number of storm reports for the period.
 */
@property (nonatomic, assign) NSInteger totalReports;

/**
 Array of states that have one or more storm reports for the period as abbreviations.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *states;

/**
 An array of `AWFGeoPolygon` instances that define the groups of reports used within the summary.
 
 In order to return polygons with your request, you must also include the `geo` filter with your request options. If this filter is not included and/or
 there are no report groups, then this value will be `nil`.
 */
@property (nonatomic, strong, nullable) NSArray<AWFGeoPolygon *> *polygons;

/**
 Array of storm report summary types according to their report code/type.
 */
@property (nonatomic, strong, nullable) NSArray<AWFStormReportSummaryType *> *types;

@end


/**
 An `AWFStormReportSummaryType` object contains summary information for a single storm report type.
 */
@interface AWFStormReportSummaryType : AWFWeatherObject

/**
 Starting date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeStartDate;

/**
 Ending date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeEndDate;

/**
 Total number of storm reports for the period.
 */
@property (nonatomic, assign) NSInteger totalReports;

/**
 Array of states that have one or more storm reports for the period as abbreviations.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *states;

/**
 Report code as assigned by the National Weather Service (NWS).
 */
@property (nonatomic, copy, nullable) NSString *code;

/**
 For wind-related events, the minimum wind speed for all reports in miles per hour.
 */
@property (nonatomic, assign) CGFloat minWindSpeedMPH;

/**
 For wind-related events, the minimum wind speed for all reports in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat minWindSpeedKMH;

/**
 For wind-related events, the minimum wind speed for all reports in knots.
 */
@property (nonatomic, assign) CGFloat minWindSpeedKTS;

/**
 For wind-related events, the maximum wind speed for all reports in miles per hour.
 */
@property (nonatomic, assign) CGFloat maxWindSpeedMPH;

/**
 For wind-related events, the maximum wind speed for all reports in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat maxWindSpeedKMH;

/**
 For wind-related events, the maximum wind speed for all reports in knots.
 */
@property (nonatomic, assign) CGFloat maxWindSpeedKTS;

/**
 For wind-related events, the average wind speed for all reports in miles per hour.
 */
@property (nonatomic, assign) CGFloat averageWindSpeedMPH;

/**
 For wind-related events, the average wind speed for all reports in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat averageWindSpeedKMH;

/**
 For wind-related events, the average wind speed for all reports in knots.
 */
@property (nonatomic, assign) CGFloat averageWindSpeedKTS;

/**
 For rain/flood-related events, the minimum rainfall observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat minRainIN;

/**
 For rain/flood-related events, the minimum rainfall observed for all reports in millimeters.
 */
@property (nonatomic, assign) CGFloat minRainMM;

/**
 For rain/flood-related events, the maximum rainfall observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat maxRainIN;

/**
 For rain/flood-related events, the maximum rainfall observed for all reports in millimeters.
 */
@property (nonatomic, assign) CGFloat maxRainMM;

/**
 For rain/flood-related events, the average rainfall observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat averageRainIN;

/**
 For rain/flood-related events, the average rainfall observed for all reports in millimeters.
 */
@property (nonatomic, assign) CGFloat averageRainMM;

/**
 For snow-related events, the minimum snowfall observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat minSnowIN;

/**
 For snow-related events, the minimum snowfall observed for all reports in centimeters.
 */
@property (nonatomic, assign) CGFloat minSnowCM;

/**
 For snow-related events, the maximum snowfall observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat maxSnowIN;

/**
 For snow-related events, the maximum snowfall observed for all reports in centimeters.
 */
@property (nonatomic, assign) CGFloat maxSnowCM;

/**
 For snow-related events, the average snowfall observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat averageSnowIN;

/**
 For snow-related events, the average snowfall observed for all reports in centimeters.
 */
@property (nonatomic, assign) CGFloat averageSnowCM;

/**
 For hail-related events, the minimum hail stone diameter observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat minHailIN;

/**
 For hail-related events, the minimum hail stone diameter observed for all reports in millimeters.
 */
@property (nonatomic, assign) CGFloat minHailMM;

/**
 For hail-related events, the maximum hail stone diameter observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat maxHailIN;

/**
 For hail-related events, the maximum hail stone diameter observed for all reports in millimeters.
 */
@property (nonatomic, assign) CGFloat maxHailMM;

/**
 For hail-related events, the average hail stone diameter observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat averageHailIN;

/**
 For hail-related events, the average hail stone diameter observed for all reports in millimeters.
 */
@property (nonatomic, assign) CGFloat averageHailMM;

/**
 For sleet-related events, the minimum sleet observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat minSleetIN;

/**
 For sleet-related events, the minimum sleet observed for all reports in centimeters.
 */
@property (nonatomic, assign) CGFloat minSleetCM;

/**
 For sleet-related events, the maximum sleet observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat maxSleetIN;

/**
 For sleet-related events, the maximum sleet observed for all reports in centimeters.
 */
@property (nonatomic, assign) CGFloat maxSleetCM;

/**
 For sleet-related events, the average sleet observed for all reports in inches.
 */
@property (nonatomic, assign) CGFloat averageSleetIN;

/**
 For sleet-related events, the average sleet observed for all reports in centimeters.
 */
@property (nonatomic, assign) CGFloat averageSleetCM;

@end
