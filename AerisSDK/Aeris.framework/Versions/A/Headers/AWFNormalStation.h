//
//  AFNormalStation.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFNormalStation : AWFGeographicObject

/**
 *  Coop/station id.
 */
@property (nonatomic, copy) NSString *stationId;

/**
 *  Elevation of the station in feet.
 */
@property (nonatomic, strong) NSNumber *elevationFT;

/**
 *  Elevation of the station in meters.
 */
@property (nonatomic, strong) NSNumber *elevationM;

/**
 *  WMO id of the station, if available.
 */
@property (nonatomic, copy) NSString *wmoId;

/**
 *  Whether or not the station has temperature normals data.
 */
@property (nonatomic, assign) BOOL hasTemp;

/**
 *  Whether or not the station has precipitation normals data.
 */
@property (nonatomic, assign) BOOL hasPrecip;

/**
 *  Whether or not the station has snowfall normals data.
 */
@property (nonatomic, assign) BOOL hasSnow;

@end