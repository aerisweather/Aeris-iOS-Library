//
//  AFAdvisoriesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFAdvisory.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFAdvisoryFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterAll;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterCounty;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterWarning;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterWatch;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterAdvisory;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterOutlook;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterStatement;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterSevere;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterFlood;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterTropical;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterWinter;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterMarine;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterNonPrecip;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterForecast;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterWind;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterFire;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterTsunami;
FOUNDATION_EXPORT AWFAdvisoryFilter const AWFAdvisoryFilterSynopsis;

typedef NSString * AWFAdvisoryField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFAdvisoryField const AWFAdvisoryFieldType;
FOUNDATION_EXPORT AWFAdvisoryField const AWFAdvisoryFieldWeatherZone;
FOUNDATION_EXPORT AWFAdvisoryField const AWFAdvisoryFieldState;
FOUNDATION_EXPORT AWFAdvisoryField const AWFAdvisoryFieldSignificance;
FOUNDATION_EXPORT AWFAdvisoryField const AWFAdvisoryFieldPriority;
FOUNDATION_EXPORT AWFAdvisoryField const AWFAdvisoryFieldName;
FOUNDATION_EXPORT AWFAdvisoryField const AWFAdvisoryFieldCountry;
FOUNDATION_EXPORT AWFAdvisoryField const AWFAdvisoryFieldDateIssued;
FOUNDATION_EXPORT AWFAdvisoryField const AWFAdvisoryFieldDateExpires;

@class AWFAdvisory;

/**
 `AWFAdvisories` provides convenience methods for interacting with the
 [`advisories` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/advisories) of the Aeris API. All requests will
 return instances of `AWFAdvisory` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFAdvisories : AWFWeatherEndpoint

@end

NS_ASSUME_NONNULL_END
