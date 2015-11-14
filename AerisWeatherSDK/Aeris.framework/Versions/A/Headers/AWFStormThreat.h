//
//  AWFStormThreat.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

@interface AWFStormThreat : AWFObject

//-----------------------------------------------------------------------------
// @name DBZ Range
//-----------------------------------------------------------------------------

/**
 *  Minimum DBZ (intensity) reported within the threat area.
 */
@property (nonatomic, strong) NSNumber *minDbz;

/**
 *  Maximum DBZ (intensity) reported within the threat area.
 */
@property (nonatomic, strong) NSNumber *maxDbz;

/**
 *  Average DBZ (intensity) reported within the threat area.
 */
@property (nonatomic, strong) NSNumber *avgDbz;

//-----------------------------------------------------------------------------
// @name Direction
//-----------------------------------------------------------------------------

/**
 *  The Cardinal direction from which the threat area is approaching.
 */
@property (nonatomic, copy) NSString *directionFrom;

/**
 *  The bearing in degrees from which the threat area is approaching.
 */
@property (nonatomic, strong) NSNumber *directionFromDEG;

/**
 *  The Cardinal direction to which the threat area is moving.
 */
@property (nonatomic, copy) NSString *directionTo;

/**
 *  The bearing in degress to which the threat area is moving.
 */
@property (nonatomic, strong) NSNumber *directionToDEG;

/**
 *  Arc span angle indicating the coverage and size of the threat area. Larger clusters of storms within a short distance from a location will result 
 *  in larger span angles.
 */
@property (nonatomic, strong) NSNumber *span;

//-----------------------------------------------------------------------------
// @name Distance
//-----------------------------------------------------------------------------

/**
 *  Minimum distance to the threat area, in kilometers. Comparing maximum and minimum distances can be an indicator of how large a threat area is.
 */
@property (nonatomic, strong) NSNumber *minDistanceKM;

/**
 *  Minimum distance to the threat area, in miles. Comparing maximum and minimum distances can be an indicator of how large a threat area is.
 */
@property (nonatomic, strong) NSNumber *minDistanceMI;

/**
 *  Maximum distance to the threat area, in kilometers. Comparing maximum and minimum distances can be an indicator of how large a threat area is.
 */
@property (nonatomic, strong) NSNumber *maxDistanceKM;

/**
 *  Maximum distance to the threat area, in miles. Comparing maximum and minimum distances can be an indicator of how large a threat area is.
 */
@property (nonatomic, strong) NSNumber *maxDistanceMI;

/**
 *  Average distance to the threat area, in kilometers.
 */
@property (nonatomic, strong) NSNumber *avgDistanceKM;

/**
 *  Average distance to the threat area, in miles.
 */
@property (nonatomic, strong) NSNumber *avgDistanceMI;

//-----------------------------------------------------------------------------
// @name Moving Speed
//-----------------------------------------------------------------------------

/**
 *  Minimum speed the threat area is moving, in knots.
 */
@property (nonatomic, strong) NSNumber *minSpeedKTS;

/**
 *  Minimum speed the threat area is moving, in miles per hour.
 */
@property (nonatomic, strong) NSNumber *minSpeedMPH;

/**
 *  Minimum speed the threat area is moving, in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *minSpeedKMH;

/**
 *  Maximum speed the threat area is moving, in knots.
 */
@property (nonatomic, strong) NSNumber *maxSpeedKTS;

/**
 *  Maximum speed the threat area is moving, in miles per hour.
 */
@property (nonatomic, strong) NSNumber *maxSpeedMPH;

/**
 *  Maximum speed the threat area is moving, in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *maxSpeedKMH;

/**
 *  Average speed the threat area is moving, in knots.
 */
@property (nonatomic, strong) NSNumber *avgSpeedKTS;

/**
 *  Average speed the threat area is moving, in miles per hour.
 */
@property (nonatomic, strong) NSNumber *avgSpeedMPH;

/**
 *  Average speed the threat area is moving, in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *avgSpeedKMH;

//-----------------------------------------------------------------------------
// @name Threats & Hazards
//-----------------------------------------------------------------------------

@property (nonatomic, strong) NSNumber *approaching;
@property (nonatomic, strong) NSNumber *rotation;
@property (nonatomic, strong) NSNumber *tornadic;

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
 *  Estimated number of lightning strikes within any threat area near the location within a 10-15 mile radius. If lightning strikes were not detected or
 *  your API account is not licensed for lightning data, this value will be `nil`.
 */
@property (nonatomic, strong) NSNumber *lightningCountNearby;

/**
 *  Estimated number of lightning strikes found within an approaching threat. If lightning strikes were not detected or your API account is not licensed
 *  for lightning data, this value will be `nil`.
 */
@property (nonatomic, strong) NSNumber *lightningCountApproaching;

/**
 *  A Boolean indicating whether the threat area is approaching the location.
 */
@property (readonly, nonatomic) BOOL isApproaching;

/**
 *  A Boolean indicating whether lightning is found within the threat area.
 */
@property (readonly, nonatomic) BOOL hasLightning;

/**
 *  A Boolean indicating whether hail is found within the threat area.
 */
@property (readonly, nonatomic) BOOL hasHail;

/**
 *  A Boolean indicating whether rotation is found within the threat area.
 */
@property (readonly, nonatomic) BOOL hasRotation;

/**
 *  A Boolean indicating whether a tornado or tornadic signature is found within the threat area. If `YES`, this does NOT always indicate a tornado 
 *  is found within the threat area and should be combined with the latest advisory data.
 */
@property (readonly, nonatomic) BOOL isTornadic;

//-----------------------------------------------------------------------------
// @name Phrasing
//-----------------------------------------------------------------------------

/**
 *  Shortened version of the `longPhrase` that dosn't display specific threat details, like hail size or lightning.
 */
@property (nonatomic, copy) NSString *phraseShort;

/**
 *  Full phrase detailing information about the threats.
 */
@property (nonatomic, copy) NSString *phraseLong;

@end
