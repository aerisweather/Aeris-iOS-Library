//
//  AFStormReportsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFStormReportFilterAvalanche;
extern NSString * const AWFStormReportFilterBlizzard;
extern NSString * const AWFStormReportFilterFire;
extern NSString * const AWFStormReportFilterFlood;
extern NSString * const AWFStormReportFilterFog;
extern NSString * const AWFStormReportFilterIce;
extern NSString * const AWFStormReportFilterHail;
extern NSString * const AWFStormReportFilterLightning;
extern NSString * const AWFStormReportFilterRain;
extern NSString * const AWFStormReportFilterSnow;
extern NSString * const AWFStormReportFilterTides;
extern NSString * const AWFStormReportFilterTornado;
extern NSString * const AWFStormReportFilterWind;

extern NSString * const AWFStormReportFieldDateTime;
extern NSString * const AWFStormReportFieldCode;
extern NSString * const AWFStormReportFieldType;
extern NSString * const AWFStormReportFieldWFO;
extern NSString * const AWFStormReportFieldDetail;
extern NSString * const AWFStormReportFieldCity;
extern NSString * const AWFStormReportFieldState;
extern NSString * const AWFStormReportFieldCountry;

/**
 *  `AWFStormReportsLoader` provides convenience methods for interacting with the
 *  [`stormreports` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/stormreports) of the Aeris API. All requests will
 *  return instances of `AWFStormReport` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFStormReportsLoader : AWFGeographicObjectLoader

/**
 *  Requests storm report summaries by day starting from the specified number of days before the current GMT date.
 *
 *  @param daysAgo         The number of days before the current date to use as the starting date.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 *  @warning Objects returned to the completion block upon a successful request will be instances of `AWFObservationSummary`, not `AWFObservation`.
 */
- (void)getStormReportsSummaryFromDaysAgo:(NSInteger)daysAgo
								  options:(AWFRequestOptions *)options
							   completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests storm report summaries by day between a starting and ending GMT date. If no ending date is provided, then the current date GMT will be used.
 *
 *  @param fromDate        Starting date in the range from which to return data for, which can only be a date in the past.
 *  @param toDate          Ending date in the range to which data is returned for, which can only be a date in the past.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 *  @warning Objects returned to the completion block upon a successful request will be instances of `AWFObservationSummary`, not `AWFObservation`.
 */
- (void)getStormReportSummaryFromDate:(NSDate *)fromDate
							   toDate:(NSDate *)toDate
							  options:(AWFRequestOptions *)options
						   completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end