//
//  AFStormCellsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFStormCell.h>
#import <AerisWeatherKit/AWFStormCellSummary.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFStormCellFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFStormCellFilter const AWFStormCellFilterHail;
FOUNDATION_EXPORT AWFStormCellFilter const AWFStormCellFilterRotating;
FOUNDATION_EXPORT AWFStormCellFilter const AWFStormCellFilterTornadic;

typedef NSString * AWFStormCellField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFStormCellField const AWFStormCellFieldDateTime;
FOUNDATION_EXPORT AWFStormCellField const AWFStormCellFieldHail;
FOUNDATION_EXPORT AWFStormCellField const AWFStormCellFieldSevereHail;
FOUNDATION_EXPORT AWFStormCellField const AWFStormCellFieldHailSize;
FOUNDATION_EXPORT AWFStormCellField const AWFStormCellFieldTVS;
FOUNDATION_EXPORT AWFStormCellField const AWFStormCellFieldRotation;
FOUNDATION_EXPORT AWFStormCellField const AWFStormCellFieldCity;
FOUNDATION_EXPORT AWFStormCellField const AWFStormCellFieldState;
FOUNDATION_EXPORT AWFStormCellField const AWFStormCellFieldCountry;

/**
 `AWFStormCells` provides convenience methods for interacting with the
 [`stormcells` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/stormcells) of the Aeris API. All requests will
 return instances of `AWFStormCell` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFStormCells : AWFWeatherEndpoint
@end

@interface AWFStormCellsSummaries : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
