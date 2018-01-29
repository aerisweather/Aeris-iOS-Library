//
//  AWFStormCellSummary.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/3/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

@class AWFRangeSummary;
@class AWFGeoPolygon;

/**
 An `AWFStormCellSummary` object represents data returned by the [**stormcells/summary** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/stormcells-summary/)
 of the Aeris Weather API.
 */
@interface AWFStormCellSummary : AWFWeatherObject

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
@property (nonatomic, assign) NSInteger totalCells;

/**
 Array of states that have one or more storm reports for the period as abbreviations.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *states;

/**
 An array of `AWFGeoPolygon` instances that define the groups of cells used within the summary.
 
 In order to return polygons with your request, you must also include the `geo` filter with your request options. If this filter is not included and/or
 there are no cell groups, then this value will be `nil`.
 */
@property (nonatomic, strong, nullable) NSArray<AWFGeoPolygon *> *polygons;

//-----------------------------------------------------------------------------
// @name Storm Cell Properties
//-----------------------------------------------------------------------------

@property (nonatomic, strong, nullable) AWFRangeSummary *tvs;

/**
 Mesocyclone rotation (MESO).
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *mda;

/**
 Total number of cells that meet or exceed the threat criteria based on their MDA values.
 */
@property (nonatomic, assign) NSInteger mdaThreatCount;

/**
 Vertically integrated liquid value for the cell.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *vil;

/**
 Highest reflectivity indicated within the cell.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *maxDbz;

/**
 Height of the storm in feet.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *topFT;

/**
 Height of the storm in meters.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *topM;

/**
 Probabilty the cell contains hail of any size.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *hailProbability;

/**
 Total number of cells that meet or exceed the threat criteria based on their hail probability values.
 */
@property (nonatomic, assign) NSInteger hailProbabilityThreatCount;

/**
 Probability the cell contains severe hail (3/4" diameter or higher) as a percentage.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *severeHailProbability;

/**
 Total number of cells that meet or exceed the threat criteria based on their severe hail probability values.
 */
@property (nonatomic, assign) NSInteger severeHailProbabilityThreatCount;

/**
 Maximum diameter of hail stones found within the cell in inches.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *hailMaxSizeIN;

/**
 Maximum diameter of hail stones found within the cell in centimeters.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *hailMaxSizeCM;

/**
 Speed the cell is moving in knots.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *movingSpeedKTS;

/**
 Speed the cell is moving in miles per hour.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *movingSpeedMPH;

/**
 Speed the cell is moving in kilometers per hour.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *movingSpeedKMH;

@end
