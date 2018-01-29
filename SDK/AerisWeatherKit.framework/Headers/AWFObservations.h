//
// AWFObservationsConnector.h
// Aeris
//
// Created by Nicholas Shipes on 9/5/13.
// Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFObservation.h>
#import <AerisWeatherKit/AWFObservationSummary.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFObservationFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFObservationFilter const AWFObservationFilterAll;
FOUNDATION_EXPORT AWFObservationFilter const AWFObservationFilterMetar;
FOUNDATION_EXPORT AWFObservationFilter const AWFObservationFilterMesonet;
FOUNDATION_EXPORT AWFObservationFilter const AWFObservationFilterPWS;
FOUNDATION_EXPORT AWFObservationFilter const AWFObservationFilterOfficial;
FOUNDATION_EXPORT AWFObservationFilter const AWFObservationFilterHasPrecip;

typedef NSString * AWFObservationField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldStationId;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldDateTime;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldName;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldState;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldCountry;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldElevation;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldTemp;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldDewPoint;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldHumidity;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldWind;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldWindDirection;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldWindGust;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldPressure;
FOUNDATION_EXPORT AWFObservationField const AWFObservationFieldPrecip;

typedef NSString * AWFObservationDataType NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFObservationDataType const AWFObservationDataTypeRecent;
FOUNDATION_EXPORT AWFObservationDataType const AWFObservationDataTypeArchive;
FOUNDATION_EXPORT AWFObservationDataType const AWFObservationDataTypeSummary;

/**
 `AWFObservations` provides convenience methods for interacting with the
 [`observations` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/observations) of the
 Aeris API. In most cases, all requests will return instances of `AWFObservation` that will be populated by the data returned by the API unless
 otherwise indicated.
 */
@interface AWFObservations : AWFWeatherEndpoint
@end

@interface AWFObservationsArchive : AWFWeatherEndpoint
@end

@interface AWFObservationsSummaries : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
