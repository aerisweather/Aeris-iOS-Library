//
//  AFRecordsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * AWFRecordFilterPrecip;
extern NSString * AWFRecordFilterSnow;
extern NSString * AWFRecordFilterMaxTemp;
extern NSString * AWFRecordFilterMinTemp;
extern NSString * AWFRecordFilterLowMaxTemp;
extern NSString * AWFRecordFilterHighMinTemp;
extern NSString * AWFRecordFilterPrecipTrace;
extern NSString * AWFRecordFilterPrecipNoTrace;
extern NSString * AWFRecordFilterTied;
extern NSString * AWFRecordFilterNotTied;

extern NSString * AWFRecordFieldDay;
extern NSString * AWFRecordFieldMonth;
extern NSString * AWFRecordFieldYear;
extern NSString * AWFRecordFieldType;
extern NSString * AWFRecordFieldEvent;
extern NSString * AWFRecordFieldCode;
extern NSString * AWFRecordFieldValue;
extern NSString * AWFRecordFieldTrace;
extern NSString * AWFRecordFieldTied;
extern NSString * AWFRecordFieldPreviousValue;
extern NSString * AWFRecordFieldPreviousYear;
extern NSString * AWFRecordFieldCity;
extern NSString * AWFRecordFieldState;
extern NSString * AWFRecordFieldCountry;

/**
 *  `AWFRecordsLoader` provides convenience methods for interacting with the
 *  [`records` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/records) of the Aeris API. All requests will
 *  return instances of `AWFRecord` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFRecordsLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests climate records for the specified place.
 *
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getRecordsForPlace:(AWFPlace *)place
                   options:(AWFRequestOptions *)options
                completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end