//
//  AWFIndicesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFIndexFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFIndexFilter const AWFIndexFilterDay;
FOUNDATION_EXPORT AWFIndexFilter const AWFIndexFilterDayNight;
FOUNDATION_EXPORT AWFIndexFilter const AWFIndexFilterAllStations;

typedef NSString * AWFIndexDataType NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFIndexDataType const AWFIndexDataTypeArthritis;
FOUNDATION_EXPORT AWFIndexDataType const AWFIndexDataTypeColdFlu;
FOUNDATION_EXPORT AWFIndexDataType const AWFIndexDataTypeMigraine;
FOUNDATION_EXPORT AWFIndexDataType const AWFIndexDataTypeSinus;
FOUNDATION_EXPORT AWFIndexDataType const AWFIndexDataTypeOutdoors;
FOUNDATION_EXPORT AWFIndexDataType const AWFIndexDataTypeGolf;
FOUNDATION_EXPORT AWFIndexDataType const AWFIndexDataTypeBiking;
FOUNDATION_EXPORT AWFIndexDataType const AWFIndexDataTypeSwimming;
FOUNDATION_EXPORT AWFIndexDataType const AWFIndexDataTypeCampfires;
FOUNDATION_EXPORT AWFIndexDataType const AWFIndexDataTypeBees;

/**
 `AWFIndices` provides convenience methods for interacting with the
 [`indices` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/indices) of the Aeris API. All requests will
 return instances of `AWFIndexPeriod` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFIndices : AWFWeatherEndpoint

- (instancetype)initWithIndexType:(AWFIndexDataType)indexType;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
