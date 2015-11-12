//
//  AWFIndicesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>
#import <Aeris/AWFIndexPeriod.h>

extern NSString * const AWFIndexFilterDay;
extern NSString * const AWFIndexFilterDayNight;
extern NSString * const AWFIndexFilterAllStations;

extern NSString * const AWFIndexDataTypeArthritis;
extern NSString * const AWFIndexDataTypeColdFlu;
extern NSString * const AWFIndexDataTypeMigrane;
extern NSString * const AWFIndexDataTypeSinus;
extern NSString * const AWFIndexDataTypeOutdoor;

/**
 *  `AWFIndicesLoader` provides convenience methods for interacting with the
 *  [`indices` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/indices) of the Aeris API. All requests will
 *  return instances of `AWFIndexPeriod` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFIndicesLoader : AWFGeographicObjectLoader

/**
 *  Requests indices for the specified index type and place.
 *
 *  @param indexType       The index type to use.
 *  @param place           The place to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 *		arguments: an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getIndicesOfType:(AWFIndexType)indexType
                forPlace:(AWFPlace *)place
                 options:(AWFRequestOptions *)options
              completion:(AWFObjectLoaderCompletionBlock)completionBlock;

/**
 *  Requests indicies for the specified index type and place between a starting and ending date.
 *
 *  @param indexType       The index type to use.
 *  @param place           The place to request data for.
 *  @param fromDate        The starting date for the date range to return data for. This date must be a date in the past. If this date is not
 *		provided, then the current date for the specified location will be used instead.
 *  @param toDate          The ending date for the date range to return data for. This date must be a date in the past. If this date is not provided,
 *		then the current date for the specified location will be used instead.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two
 *		arguments: an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getIndicesOfType:(AWFIndexType)indexType
                forPlace:(AWFPlace *)place
                fromDate:(NSDate *)fromDate
                  toDate:(NSDate *)toDate
                 options:(AWFRequestOptions *)options
              completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end