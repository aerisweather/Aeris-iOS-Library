//
//  AFNormalStation.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFNormalStation` object represents data returned by the [**normals/stations** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/normals-stations/)
 of the Aeris Weather API.
 */
@interface AWFNormalStation : AWFGeographicObject

/**
 Coop/station id.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 Elevation of the station in feet.
 */
@property (nonatomic, assign) CGFloat elevationFT;

/**
 Elevation of the station in meters.
 */
@property (nonatomic, assign) CGFloat elevationM;

/**
 WMO id of the station, if available.
 */
@property (nonatomic, copy, nullable) NSString *wmoId;

/**
 Whether or not the station has temperature normals data.
 */
@property (nonatomic, assign) BOOL hasTemp;

/**
 Whether or not the station has precipitation normals data.
 */
@property (nonatomic, assign) BOOL hasPrecip;

/**
 Whether or not the station has snowfall normals data.
 */
@property (nonatomic, assign) BOOL hasSnow;

@end

NS_ASSUME_NONNULL_END
