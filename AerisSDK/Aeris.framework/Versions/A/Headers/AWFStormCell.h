//
//  AFStormCell.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFStormCell : AWFGeographicObject

/**
 *  GMT date of the cell observation.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Location of the cell relative to the nearest populated place.
 *  @since version 1.0.3
 */
@property (nonatomic, copy) NSString *location;

//-----------------------------------------------------------------------------
// @name Storm Cell Details
//-----------------------------------------------------------------------------

/**
 *
 */
@property (nonatomic, copy) NSString *code;

/**
 *  Radar station ID reporting the cell.
 */
@property (nonatomic, copy) NSString *radarId;

/**
 *  Unique cell identifier.
 */
@property (nonatomic, copy) NSString *cellId;

/**
 *  Tornado vortex signature (TVS).
 *
 *  If the cell contains a tornadic signature or a tornado has been reported, this value will be 1, otherwise 0.
 */
@property (nonatomic, strong) NSNumber *tvs;

/**
 *  Mesocyclone rotation (MESO).
 */
@property (nonatomic, strong) NSNumber *mda;

/**
 *  Vertically integrated liquid value for the cell.
 */
@property (nonatomic, strong) NSNumber *vil;

/**
 *  Highest reflectivity indicated within the cell.
 */
@property (nonatomic, strong) NSNumber *maxDbz;

/**
 *  Height of the storm in feet.
 */
@property (nonatomic, strong) NSNumber *topFT;

/**
 *  Height of the storm structure.
 */
@property (nonatomic, strong) NSNumber *height;

/**
 *  Probability the cell contains severe hail (3/4" diameter or higher) as a percentage.
 */
@property (nonatomic, strong) NSNumber *hailSevereProbability;

/**
 *  Probabilty the cell contains hail of any size.
 */
@property (nonatomic, strong) NSNumber *hailProbability;

/**
 *  Maximum diameter of hail stones found within the cell in inches.
 */
@property (nonatomic, strong) NSNumber *hailMaxSizeIN;

/**
 *  Distance of the cell relative to the requested location in kilometers.
 */
@property (nonatomic, strong) NSNumber *distanceKM;

/**
 *  Distance of the cell relative to the requested location in miles.
 */
@property (nonatomic, strong) NSNumber *distanceMI;

/**
 *  Direction to the cell relative to the requested location in degrees.
 */
@property (nonatomic, strong) NSNumber *bearingDEG;

/**
 *  Cardinal direction to the cell relative to the requested location.
 */
@property (nonatomic, copy) NSString *bearing;

/**
 *  Cardinal direction the cell is moving.
 */
@property (nonatomic, copy) NSString *movingDirection;

/**
 *  Direction the cell is moving in degrees.
 */
@property (nonatomic, strong) NSNumber *movingDirectionDEG;

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

//-----------------------------------------------------------------------------
// @name Storm Cell Forecast
//-----------------------------------------------------------------------------

/**
 *  An array of AFStormCellForecast instances returned for this cell.
 */
@property (nonatomic, copy) NSArray *forecast;

/**
 *  Array of coordinates (latitude, longitude) defining a 20-degree cone of error along the forecast path.
 */
@property (nonatomic, copy) NSArray *forecastConeWide;

/**
 *  Array of coordinates (latitude, longitude) defining a 5-degree cone of error along the forecast path which can be used
 *  to better determine locations along the forecast path of the storm.
 */
@property (nonatomic, copy) NSArray *forecastConeNarrow;

/**
 *  A Boolean indicating whether the storm cell is affecting the specified place by comparing distance and whether or not the storm cell is moving
 *  toward the location.
 *
 *  @param place The place to determine if the cell is affecting
 *
 *  @return `YES` if the cell is affecting the place, otherwise `NO`
 */
- (BOOL)affectsPlace:(AWFPlace *)place;

/**
 *  A Boolean indicating whether the storm cell is approaching the specified place based on the cell's distance and moving direction.
 *
 *  @param place The place to determine if the cell is approaching
 *
 *  @return `YES` if the cell is apporaching the place, otherwise `NO`
 */
- (BOOL)isMovingTowardPlace:(AWFPlace *)place;

@end


@interface AWFStormCellForecast : AWFObject

/**
 *  Forecasted latitude position for the period.
 */
@property (nonatomic, strong) NSNumber *latitude;

/**
 *  Forecasted longitude position for the period.
 */
@property (nonatomic, strong) NSNumber *longitude;

/**
 *  Forecasted bearing of the cell relative to the radar station in degrees.
 */
@property (nonatomic, strong) NSNumber *degree;

/**
 *  Forecasted distance of the cell relative to the radar station in nautical miles.
 */
@property (nonatomic, strong) NSNumber *distance;

/**
 *  GMT date of the forecasted time for the period.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Forecasted coordinate position for the period.
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@end