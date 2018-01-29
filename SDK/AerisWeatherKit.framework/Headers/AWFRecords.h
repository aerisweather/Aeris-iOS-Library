//
//  AFRecordsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFRecord.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFRecordFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFRecordFilter const AWFRecordFilterPrecip;
FOUNDATION_EXPORT AWFRecordFilter const AWFRecordFilterSnow;
FOUNDATION_EXPORT AWFRecordFilter const AWFRecordFilterMaxTemp;
FOUNDATION_EXPORT AWFRecordFilter const AWFRecordFilterMinTemp;
FOUNDATION_EXPORT AWFRecordFilter const AWFRecordFilterLowMaxTemp;
FOUNDATION_EXPORT AWFRecordFilter const AWFRecordFilterHighMinTemp;
FOUNDATION_EXPORT AWFRecordFilter const AWFRecordFilterPrecipTrace;
FOUNDATION_EXPORT AWFRecordFilter const AWFRecordFilterPrecipNoTrace;
FOUNDATION_EXPORT AWFRecordFilter const AWFRecordFilterTied;
FOUNDATION_EXPORT AWFRecordFilter const AWFRecordFilterNotTied;

typedef NSString * AWFRecordField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldDay;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldMonth;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldYear;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldType;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldEvent;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldCode;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldValue;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldTrace;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldTied;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldPreviousValue;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldPreviousYear;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldCity;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldState;
FOUNDATION_EXPORT AWFRecordField const AWFRecordFieldCountry;

/**
 `AWFRecords` provides convenience methods for interacting with the
 [`records` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/records) of the Aeris API. All requests will
 return instances of `AWFRecord` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFRecords : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
