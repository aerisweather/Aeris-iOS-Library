//
//  AFStormCell.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>
#import <AerisWeatherKit/AWFGeoPolygon.h>

@class AWFStormCellForecast;

/**
 An `AWFStormCell` object represents data returned by the [**stormcells** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/stormcells/)
 of the Aeris Weather API.
 */
@interface AWFStormCell : AWFGeographicObject

/**
 GMT date of the cell observation.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Location of the cell relative to the nearest populated place.
 */
@property (nonatomic, copy, nullable) NSString *location;

//-----------------------------------------------------------------------------
// @name Storm Cell Details
//-----------------------------------------------------------------------------

/**
 
 */
@property (nonatomic, copy, nullable) NSString *code;

/**
 Radar station ID reporting the cell.
 */
@property (nonatomic, copy, nullable) NSString *radarId;

/**
 Unique cell identifier.
 */
@property (nonatomic, copy, nullable) NSString *cellId;

/**
 Tornado vortex signature (TVS).
 
 If the cell contains a tornadic signature or a tornado has been reported, this value will be `1`, otherwise `0`.
 */
@property (nonatomic, assign) CGFloat tvs;

/**
 Mesocyclone rotation (MESO).
 */
@property (nonatomic, assign) CGFloat mda;

/**
 Vertically integrated liquid value for the cell.
 */
@property (nonatomic, assign) CGFloat vil;

/**
 Highest reflectivity indicated within the cell.
 */
@property (nonatomic, assign) CGFloat maxDbz;

/**
 Height of the storm in feet.
 */
@property (nonatomic, assign) CGFloat topFT;

/**
 Height of the storm structure.
 */
@property (nonatomic, assign) CGFloat height;

/**
 Probability the cell contains severe hail (3/4" diameter or higher) as a percentage.
 */
@property (nonatomic, assign) CGFloat hailSevereProbability;

/**
 Probabilty the cell contains hail of any size.
 */
@property (nonatomic, assign) CGFloat hailProbability;

/**
 Maximum diameter of hail stones found within the cell in inches.
 */
@property (nonatomic, assign) CGFloat hailMaxSizeIN;

/**
 Distance of the cell relative to the requested location in kilometers.
 */
@property (nonatomic, assign) CGFloat distanceKM;

/**
 Distance of the cell relative to the requested location in miles.
 */
@property (nonatomic, assign) CGFloat distanceMI;

/**
 Direction to the cell relative to the requested location in degrees.
 */
@property (nonatomic, assign) CGFloat bearingDEG;

/**
 Cardinal direction to the cell relative to the requested location.
 */
@property (nonatomic, copy, nullable) NSString *bearing;

/**
 Cardinal direction the cell is moving.
 */
@property (nonatomic, copy, nullable) NSString *movingDirection;

/**
 Direction the cell is moving in degrees.
 */
@property (nonatomic, assign) CGFloat movingDirectionDEG;

/**
 Speed the cell is moving in knots.
 */
@property (nonatomic, assign) CGFloat movingSpeedKTS;

/**
 Speed the cell is moving in miles per hour.
 */
@property (nonatomic, assign) CGFloat movingSpeedMPH;

/**
 Speed the cell is moving in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat movingSpeedKMH;

//-----------------------------------------------------------------------------
// @name Storm Cell Forecast
//-----------------------------------------------------------------------------

/**
 An array of AFStormCellForecast instances returned for this cell.
 */
@property (nonatomic, copy, nullable) NSArray<AWFStormCellForecast *> *forecast;

/**
 Array of coordinates (latitude, longitude) defining a 20-degree cone of error along the forecast path.
 */
@property (nonatomic, copy, nullable) NSArray<AWFGeoPolygonCoordValue> *forecastConeWide;

/**
 Array of coordinates (latitude, longitude) defining a 5-degree cone of error along the forecast path which can be used
 to better determine locations along the forecast path of the storm.
 */
@property (nonatomic, copy, nullable) NSArray<AWFGeoPolygonCoordValue> *forecastConeNarrow;

/**
 A Boolean indicating whether the storm cell is affecting the specified place by comparing distance and whether or not the storm cell is moving
 toward the location.
 
 @param place The place to determine if the cell is affecting
 @return `YES` if the cell is affecting the place, otherwise `NO`
 */
- (BOOL)affectsPlace:(nonnull AWFPlace *)place;

/**
 A Boolean indicating whether the storm cell is approaching the specified place based on the cell's distance and moving direction.
 
 @param place The place to determine if the cell is approaching
 @return `YES` if the cell is apporaching the place, otherwise `NO`
 */
- (BOOL)isMovingTowardPlace:(nonnull AWFPlace *)place;

@end


/**
 An `AWFStormCellForecast` object represents a single forecast period and position for a storm cell.
 */
@interface AWFStormCellForecast : AWFWeatherObject

/**
 Forecasted coordinate position for the period.
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 Forecasted bearing of the cell relative to the radar station in degrees.
 */
@property (nonatomic, assign) CGFloat degree;

/**
 Forecasted distance of the cell relative to the radar station in nautical miles.
 */
@property (nonatomic, assign) CGFloat distance;

/**
 GMT date of the forecasted time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

@end
