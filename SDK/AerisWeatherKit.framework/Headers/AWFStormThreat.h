//
//  AWFStormThreat.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/13/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

/**
 An `AWFStormThreat` object represents storm threatdata returned by the [**threats** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/threats/)
 of the Aeris Weather API.
 */
@interface AWFStormThreat : AWFWeatherObject

//-----------------------------------------------------------------------------
// @name DBZ Range
//-----------------------------------------------------------------------------

/**
 Minimum DBZ (intensity) reported within the threat area.
 */
@property (nonatomic, assign) CGFloat minDbz;

/**
 Maximum DBZ (intensity) reported within the threat area.
 */
@property (nonatomic, assign) CGFloat maxDbz;

/**
 Average DBZ (intensity) reported within the threat area.
 */
@property (nonatomic, assign) CGFloat avgDbz;

//-----------------------------------------------------------------------------
// @name Direction
//-----------------------------------------------------------------------------

/**
 The Cardinal direction from which the threat area is approaching.
 */
@property (nonatomic, copy, nullable) NSString *directionFrom;

/**
 The bearing in degrees from which the threat area is approaching.
 */
@property (nonatomic, assign) CGFloat directionFromDEG;

/**
 The Cardinal direction to which the threat area is moving.
 */
@property (nonatomic, copy, nullable) NSString *directionTo;

/**
 The bearing in degress to which the threat area is moving.
 */
@property (nonatomic, assign) CGFloat directionToDEG;

/**
 Arc span angle indicating the coverage and size of the threat area. Larger clusters of storms within a short distance from a location will result 
 in larger span angles.
 */
@property (nonatomic, assign) CGFloat span;

//-----------------------------------------------------------------------------
// @name Distance
//-----------------------------------------------------------------------------

/**
 Minimum distance to the threat area, in kilometers. Comparing maximum and minimum distances can be an indicator of how large a threat area is.
 */
@property (nonatomic, assign) CGFloat minDistanceKM;

/**
 Minimum distance to the threat area, in miles. Comparing maximum and minimum distances can be an indicator of how large a threat area is.
 */
@property (nonatomic, assign) CGFloat minDistanceMI;

/**
 Maximum distance to the threat area, in kilometers. Comparing maximum and minimum distances can be an indicator of how large a threat area is.
 */
@property (nonatomic, assign) CGFloat maxDistanceKM;

/**
 Maximum distance to the threat area, in miles. Comparing maximum and minimum distances can be an indicator of how large a threat area is.
 */
@property (nonatomic, assign) CGFloat maxDistanceMI;

/**
 Average distance to the threat area, in kilometers.
 */
@property (nonatomic, assign) CGFloat avgDistanceKM;

/**
 Average distance to the threat area, in miles.
 */
@property (nonatomic, assign) CGFloat avgDistanceMI;

//-----------------------------------------------------------------------------
// @name Moving Speed
//-----------------------------------------------------------------------------

/**
 Minimum speed the threat area is moving, in knots.
 */
@property (nonatomic, assign) CGFloat minSpeedKTS;

/**
 Minimum speed the threat area is moving, in miles per hour.
 */
@property (nonatomic, assign) CGFloat minSpeedMPH;

/**
 Minimum speed the threat area is moving, in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat minSpeedKMH;

/**
 Maximum speed the threat area is moving, in knots.
 */
@property (nonatomic, assign) CGFloat maxSpeedKTS;

/**
 Maximum speed the threat area is moving, in miles per hour.
 */
@property (nonatomic, assign) CGFloat maxSpeedMPH;

/**
 Maximum speed the threat area is moving, in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat maxSpeedKMH;

/**
 Average speed the threat area is moving, in knots.
 */
@property (nonatomic, assign) CGFloat avgSpeedKTS;

/**
 Average speed the threat area is moving, in miles per hour.
 */
@property (nonatomic, assign) CGFloat avgSpeedMPH;

/**
 Average speed the threat area is moving, in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat avgSpeedKMH;

//-----------------------------------------------------------------------------
// @name Threats & Hazards
//-----------------------------------------------------------------------------

@property (nonatomic, assign) CGFloat approaching;
@property (nonatomic, assign) CGFloat rotation;
@property (nonatomic, assign) CGFloat tornadic;

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
 Estimated number of lightning strikes within any threat area near the location within a 10-15 mile radius. If lightning strikes were not detected or
 your API account is not licensed for lightning data, this value will be `0`.
 */
@property (nonatomic, assign) NSInteger lightningCountNearby;

/**
 Estimated number of lightning strikes found within an approaching threat. If lightning strikes were not detected or your API account is not licensed
 for lightning data, this value will be `0`.
 */
@property (nonatomic, assign) NSInteger lightningCountApproaching;

/**
 A Boolean indicating whether the threat area is approaching the location.
 */
@property (nonatomic, readonly) BOOL isApproaching;

/**
 A Boolean indicating whether lightning is found within the threat area.
 */
@property (nonatomic, readonly) BOOL hasLightning;

/**
 A Boolean indicating whether hail is found within the threat area.
 */
@property (nonatomic, readonly) BOOL hasHail;

/**
 A Boolean indicating whether rotation is found within the threat area.
 */
@property (nonatomic, readonly) BOOL hasRotation;

/**
 A Boolean indicating whether a tornado or tornadic signature is found within the threat area. If `YES`, this does NOT always indicate a tornado 
 is found within the threat area and should be combined with the latest advisory data.
 */
@property (nonatomic, readonly) BOOL isTornadic;

//-----------------------------------------------------------------------------
// @name Phrasing
//-----------------------------------------------------------------------------

/**
 Shortened version of the `longPhrase` that dosn't display specific threat details, like hail size or lightning.
 */
@property (nonatomic, copy, nullable) NSString *phraseShort;

/**
 Full phrase detailing information about the threats.
 */
@property (nonatomic, copy, nullable) NSString *phraseLong;

@end
