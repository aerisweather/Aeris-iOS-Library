//
//  AWFStormCellSummary.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/3/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

@class AWFRangeSummary;

@interface AWFStormCellSummary : AWFObject

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
@property (strong, nonatomic) NSNumber *totalCells;

/**
 *  Array of states that have one or more storm reports for the period as abbreviations.
 */
@property (strong, nonatomic) NSArray *states;

/**
 *  An array of `AWFGeoPolygon` instances that define the groups of cells used within the summary.
 *
 *  In order to return polygons with your request, you must also include the `geo` filter with your request options. If this filter is not included and/or
 *  there are no cell groups, then this value will be `nil`.
 */
@property (strong, nonatomic) NSArray *polygons;

//-----------------------------------------------------------------------------
// @name Storm Cell Properties
//-----------------------------------------------------------------------------

@property (nonatomic, strong) AWFRangeSummary *tvs;

/**
 *  Mesocyclone rotation (MESO).
 */
@property (nonatomic, strong) AWFRangeSummary *mda;

/**
 *  Total number of cells that meet or exceed the threat criteria based on their MDA values.
 */
@property (nonatomic, strong) NSNumber *mdaThreatCount;

/**
 *  Vertically integrated liquid value for the cell.
 */
@property (nonatomic, strong) AWFRangeSummary *vil;

/**
 *  Highest reflectivity indicated within the cell.
 */
@property (nonatomic, strong) AWFRangeSummary *maxDbz;

/**
 *  Height of the storm in feet.
 */
@property (nonatomic, strong) AWFRangeSummary *topFT;

/**
 *  Height of the storm in meters.
 */
@property (nonatomic, strong) AWFRangeSummary *topM;

/**
 *  Probabilty the cell contains hail of any size.
 */
@property (nonatomic, strong) AWFRangeSummary *hailProbability;

/**
 *  Total number of cells that meet or exceed the threat criteria based on their hail probability values.
 */
@property (nonatomic, strong) NSNumber *hailProbabilityThreatCount;

/**
 *  Probability the cell contains severe hail (3/4" diameter or higher) as a percentage.
 */
@property (nonatomic, strong) AWFRangeSummary *severeHailProbability;

/**
 *  Total number of cells that meet or exceed the threat criteria based on their severe hail probability values.
 */
@property (nonatomic, strong) NSNumber *severeHailProbabilityThreatCount;

/**
 *  Maximum diameter of hail stones found within the cell in inches.
 */
@property (nonatomic, strong) AWFRangeSummary *hailMaxSizeIN;

/**
 *  Maximum diameter of hail stones found within the cell in centimeters.
 */
@property (nonatomic, strong) AWFRangeSummary *hailMaxSizeCM;

/**
 *  Speed the cell is moving in knots.
 */
@property (nonatomic, strong) NSNumber *movingSpeedKTS;

/**
 *  Speed the cell is moving in miles per hour.
 */
@property (nonatomic, strong) NSNumber *movingSpeedMPH;

/**
 *  Speed the cell is moving in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *movingSpeedKMH;

@end
