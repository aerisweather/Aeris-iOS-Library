//
//  AFStormReportsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFStormReport.h>
#import <AerisWeatherKit/AWFStormReportSummary.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFStormReportFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterAvalanche;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterBlizzard;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterFire;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterFlood;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterFog;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterIce;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterHail;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterLightning;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterRain;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterSnow;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterTides;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterTornado;
FOUNDATION_EXPORT AWFStormReportFilter const AWFStormReportFilterWind;

typedef NSString * AWFStormReportField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFStormReportField const AWFStormReportFieldDateTime;
FOUNDATION_EXPORT AWFStormReportField const AWFStormReportFieldCode;
FOUNDATION_EXPORT AWFStormReportField const AWFStormReportFieldType;
FOUNDATION_EXPORT AWFStormReportField const AWFStormReportFieldWFO;
FOUNDATION_EXPORT AWFStormReportField const AWFStormReportFieldDetail;
FOUNDATION_EXPORT AWFStormReportField const AWFStormReportFieldCity;
FOUNDATION_EXPORT AWFStormReportField const AWFStormReportFieldState;
FOUNDATION_EXPORT AWFStormReportField const AWFStormReportFieldCountry;

/**
 `AWFStormReports` provides convenience methods for interacting with the
 [`stormreports` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/stormreports) of the Aeris API. All requests will
 return instances of `AWFStormReport` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFStormReports : AWFWeatherEndpoint
@end

@interface AWFStormReportsSummaries : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
