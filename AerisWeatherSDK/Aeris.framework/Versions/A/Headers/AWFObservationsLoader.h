//
// AWFObservationsConnector.h
// Aeris
//
// Created by Nicholas Shipes on 9/5/13.
// Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFObservationFilterAll;
extern NSString * const AWFObservationFilterMetar;
extern NSString * const AWFObservationFilterMesonet;
extern NSString * const AWFObservationFilterPWS;
extern NSString * const AWFObservationFilterOfficial;
extern NSString * const AWFObservationFilterHasPrecip;

extern NSString * const AWFObservationFieldStationId;
extern NSString * const AWFObservationFieldDateTime;
extern NSString * const AWFObservationFieldName;
extern NSString * const AWFObservationFieldState;
extern NSString * const AWFObservationFieldCountry;
extern NSString * const AWFObservationFieldElevation;
extern NSString * const AWFObservationFieldTemp;
extern NSString * const AWFObservationFieldDewPoint;
extern NSString * const AWFObservationFieldHumidity;
extern NSString * const AWFObservationFieldWind;
extern NSString * const AWFObservationFieldWindDirection;
extern NSString * const AWFObservationFieldWindGust;
extern NSString * const AWFObservationFieldPressure;
extern NSString * const AWFObservationFieldPrecip;

extern NSString * const AWFObservationDataTypeRecent;
extern NSString * const AWFObservationDataTypeArchive;
extern NSString * const AWFObservationDataTypeSummary;

// keep for backwards compatability with previous versions
extern NSString *const AerisAPIFilterObservationsMetar;
extern NSString *const AerisAPIFilterObservationsMesonet;
extern NSString *const AerisAPIFilterObservationsPWS;
extern NSString *const AerisAPIFilterObservationsAll;
extern NSString *const AerisAPIObservationDataTypeRecent;
extern NSString *const AerisAPIObservationDataTypeArchive;
extern NSString *const AerisAPIObservationDataTypeSummary;

@class AWFPlace, AWFRequestOptions;

/**
 *  `AWFObservationsLoader` provides convenience methods for interacting with the
 *  [`observations` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/observations) of the
 *  Aeris API. In most cases, all requests will return instances of `AWFObservation` that will be populated by the data returned by the API unless
 *  otherwise indicated.
 */
@interface AWFObservationsLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests the latest observation for the specified place.
 *
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getObservationForPlace:(AWFPlace *)place
                       options:(AWFRequestOptions *)options
                    completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests recent observations relative to the current time/date for the specified place. Results will be returned in descending order
 *	relative to the current time and date of the place.
 *
 *  @param place           The place to request data for.
 *  @param total           The total number of observations to return.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getRecentObservationsForPlace:(AWFPlace *)place
                                total:(NSUInteger)total
                              options:(AWFRequestOptions *)options
                           completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests archived observations for the specified place between a starting and ending date. If no ending date is provided, then the current
 *	date at the location will be used.
 *
 *  @param place           The place to request data for.
 *  @param fromDate        The starting date for the date range to return data for. This date must be a date in the past.
 *  @param toDate          The ending date for the date range to return data for. This date must be a date in the past. If this date is not provided,
 *		then the current date for the specified location will be used instead.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getArchivedObservationsForPlace:(AWFPlace *)place
                               fromDate:(NSDate *)fromDate
                                 toDate:(NSDate *)toDate
                                options:(AWFRequestOptions *)options
                             completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests daily observation summaries for the specified place between a starting and ending date. If no ending date is provided, then the current
 *  date at the location will be used.
 *
 *  @param place           The place to request observation summaries for.
 *  @param fromDate        Starting date in the range from which to return data for, which can only be a date in the past.
 *  @param toDate          Ending date in the range to which data is returned for, which can only be a date in the past.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 *  @warning Objects returned to the completion block upon a successful request will be instances of `AWFObservationSummary`, not `AWFObservation`.
 */
- (void)getObservationSummaryForPlace:(AWFPlace *)place
                             fromDate:(NSDate *)fromDate
                               toDate:(NSDate *)toDate
                              options:(AWFRequestOptions *)options
                           completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end