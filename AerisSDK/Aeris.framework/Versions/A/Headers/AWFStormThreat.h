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
@property (nonatomic, strong) NSNumber *minDbz;
@property (nonatomic, strong) NSNumber *maxDbz;
@property (nonatomic, strong) NSNumber *avgDbz;

//-----------------------------------------------------------------------------
// @name Direction
//-----------------------------------------------------------------------------
@property (nonatomic, copy) NSString *directionFrom;
@property (nonatomic, strong) NSNumber *directionFromDEG;
@property (nonatomic, copy) NSString *directionTo;
@property (nonatomic, strong) NSNumber *directionToDEG;
@property (nonatomic, strong) NSNumber *span;

//-----------------------------------------------------------------------------
// @name Distance
//-----------------------------------------------------------------------------
@property (nonatomic, strong) NSNumber *minDistanceKM;
@property (nonatomic, strong) NSNumber *minDistanceMI;
@property (nonatomic, strong) NSNumber *maxDistanceKM;
@property (nonatomic, strong) NSNumber *maxDistanceMI;
@property (nonatomic, strong) NSNumber *avgDistanceKM;
@property (nonatomic, strong) NSNumber *avgDistanceMI;

//-----------------------------------------------------------------------------
// @name Moving Speed
//-----------------------------------------------------------------------------
@property (nonatomic, strong) NSNumber *minSpeedKTS;
@property (nonatomic, strong) NSNumber *minSpeedMPH;
@property (nonatomic, strong) NSNumber *minSpeedKMH;
@property (nonatomic, strong) NSNumber *maxSpeedKTS;
@property (nonatomic, strong) NSNumber *maxSpeedMPH;
@property (nonatomic, strong) NSNumber *maxSpeedKMH;
@property (nonatomic, strong) NSNumber *avgSpeedKTS;
@property (nonatomic, strong) NSNumber *avgSpeedMPH;
@property (nonatomic, strong) NSNumber *avgSpeedKMH;

//-----------------------------------------------------------------------------
// @name Threats & Hazards
//-----------------------------------------------------------------------------
@property (nonatomic, strong) NSNumber *approaching;

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
@property (nonatomic, strong) NSNumber *rotation;
@property (nonatomic, strong) NSNumber *tornadic;
@property (nonatomic, strong) NSNumber *lightningCountNearby;
@property (nonatomic, strong) NSNumber *lightningCountApproaching;

@property (readonly, nonatomic) BOOL isApproaching;
@property (readonly, nonatomic) BOOL hasLightning;
@property (readonly, nonatomic) BOOL hasHail;
@property (readonly, nonatomic) BOOL hasRotation;
@property (readonly, nonatomic) BOOL isTornadic;

//-----------------------------------------------------------------------------
// @name Phrasing
//-----------------------------------------------------------------------------
@property (nonatomic, copy) NSString *phraseShort;
@property (nonatomic, copy) NSString *phraseLong;

@end
