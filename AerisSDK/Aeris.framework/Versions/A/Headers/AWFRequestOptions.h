//
//  AWFRequestOptions.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AWFPlace, AWFRequestFilter, AWFRequestQuery;

/**
 *  The sorting codes to use for a request's `sort` direction option, such as `sort=field:direction`.
 */
typedef NS_ENUM (NSInteger, AWFRequestSort) {
	/**
	 *  Sorts the returned results based on the associated field name in descending order.
	 */
	AWFRequestSortDescending = -1,
	/**
	 *  Disables any specific sorting on the field name.
	 */
	AWFRequestSortDisabled = 0,
	/**
	 *  Sorts the returned results based on the associated field name in ascending order.
	 */
	AWFRequestSortAscending = 1,
	/**
	 *  The default sorting order.
	 */
	AWFRequestSortDefault = AWFRequestSortAscending
};

/**
 *  The operators used when combining multiple queries in a request.
 */
typedef NS_ENUM (NSUInteger, AWFRequestOperator) {
	/**
	 *  Joins the queries using an `OR` operator.
	 */
	AWFRequestOperatorOr = 0,
	/**
	 *  Joins the queries using an `AND` operator.
	 */
	AWFRequestOperatorAnd
};

/**
 *  An `AWFRequesetOptions` object represents all of the supported options that can be passed to an API request through object
 *  loaders. This is a convenience class that will properly format parameters as required by the API before the request is actually
 *  initiated.
 *
 *  @since 2.0
 */
@interface AWFRequestOptions : NSObject <NSCopying>

/**
 *  The place to use for the request. This corresponds to the `AerisAPIParamKeyPlace`, or `p`, parameter when accessing the API directly.
 */
@property (nonatomic, strong) AWFPlace *place;

@property (nonatomic, copy) NSString *identifier;

/**
 *  A string of comma-separated latitude/longitude coordinates defining a bounding region. This corresponds to the `AerisAPIParamKeyPlace`,
 *  or `p`, parameter when accessing the API directly and using a coordinate region instead of a single place.
 */
@property (nonatomic, copy) NSString *boundsString;

/**
 *  The maximum number of objects to return. This corresponds to the `AerisAPIParamKeyLimit`, or `limit`, parameter when accessing the API
 *  directly.
 */
@property (nonatomic, assign) NSUInteger limit;

/**
 *  The number of items to skip from the expected data set. This corresponds to the `AerisAPIParamKeySkip`, or `skip`, parameter when
 *  accessing the API directly.
 */
@property (nonatomic, assign) NSUInteger skip;

/**
 *  The search radius, in miles, to use when performing a closest request from a single location. If `radiusKM` is defined, this value is
 *  ignored in the request. This corresponds to the `AerisAPIParamKeyRadius`, or `radius`, parameter when accessing the API directly.
 */
@property (nonatomic, assign) NSUInteger radiusMI;

/**
 *  The search radius, in kilometers, to use when performing a closest request from a single location. This value will take precedence over
 *  `radiusMI` if both values are defined. This corresponds to the `AerisAPIParamKeyRadius`, or `radius`, parameter when accessing the API
 *  directly.
 */
@property (nonatomic, assign) NSUInteger radiusKM;

@property (nonatomic) NSString *radiusString;

/**
 *  The query string to use when performing a search request. This corresponds to the `AerisAPIParamKeyQuery`, or `query`, parameter when
 *  accessing the API directly.
 */
@property (nonatomic) NSString *queryString;

/**
 *  Returns an array of `AWFRequestQuery` instances currently assigned.
 */
@property (readonly, nonatomic, strong) NSArray *queries;

/**
 *  A string of comma-separated filter keys to limit the request to. This corresponds to the `AerisAPIParamKeyFilter`, or `filter`,
 *  parameter when accessing the API directly.
 */
@property (nonatomic) NSString *filterString;

/**
 *  Returns an array of `AWFRequestFilter` instances currently assigned.
 */
@property (readonly, nonatomic, strong) NSArray *filters;

/**
 *  A string of comma-separate field names to limit the request to. This corresponds to the `AerisAPIParamKeyFields`, or `fields`, parameter
 *  when accessing the API directly.
 */
@property (nonatomic, copy) NSString *fields;

/**
 *  The order in which to sort the returned objects, either ascending (default) or descending. This corresponds to the
 *  `AerisAPIParamKeySort`, or `sort`, parameter when accessing the API directly.
 */
@property (nonatomic, copy) NSString *sort;

/**
 *  The starting date from which to request objects for. This corresponds to the `AerisAPIParamKeyDateFrom`, or `from`, parameter when
 *  accessing the API directly.
 */
@property (nonatomic, strong) NSDate *fromDate;

/**
 *  The starting date string from which to request objects for. This value can be in the format of a relative string, `@"-2 days"`, or an
 *  actual date, `@"2/7/2014"`. This corresponds to the `AerisAPIParamKeyDateFrom`, or `from`, parameter when accessing the API directly.
 */
@property (nonatomic, copy) NSString *fromDateString;

/**
 *  The ending date to which to request objects for. This corresponds to the `AerisAPIParamKeyDateTo`, or `to`, parameter when accessing the
 *  API directly.
 */
@property (nonatomic, strong) NSDate *toDate;

/**
 *  The ending date to which to request objects for. This value can be in the format of a relative string, `@"+2 days"`, or an actual date,
 *  `@"2/7/2015"`. This corresponds to the `AerisAPIParamKeyDateTo`, or `to`, parameter when accessing the API directly.
 */
@property (nonatomic, copy) NSString *toDateString;

//-----------------------------------------------------------------------------
// @name Periods
//-----------------------------------------------------------------------------

/**
 *  The total number of periods to return. This option is only used for objects that contain a `periods` property. This corresponds to the
 *  `AerisAPIParamKeyPeriodLimit`, or `plimit`, parameter when accessing the API directly.
 */
@property (nonatomic, assign) NSUInteger periodLimit;

/**
 *  The total number of periods to skip. This option is only used for objects that contain a `periods` property. This corresponds to the
 *  `AerisAPIParamKeyPeriodSkip`, or `pskip`, parameter when accessing the API directly.
 */
@property (nonatomic, assign) NSUInteger periodSkip;

/**
 *  The order in which to sort the periods. This option is only used for objects that contain a `periods` property. This corresponds to the
 *  `AerisAPIParamKeyPeriodSort`, or `psort`, parameter when accessing the API directly.
 */
@property (nonatomic, copy) NSString *periodSort;

/**
 *  The endpoint data type to use for a request. An endpoint data type should be one of the subendpoints supported by an API endpoint.
 */
@property (nonatomic, copy) NSString *dataType;

//-----------------------------------------------------------------------------
// @name Output Format
//-----------------------------------------------------------------------------

/**
 *  The format type for the request response. The default is the standard Aeris API response as a JSON object.
 */
@property (nonatomic, copy) NSString *format;

/**
 *  Creates a new empty `AWFRequestOptions` instance.
 *
 *  @return The empty instance
 */
+ (instancetype)options;

/**
 *  Creates and returns a new `AWFRequestOptions` instance using the provided dictionary values.
 *
 *  @param dictionary A dictionary of values to assign to the instance. These must be valid API parameter keys.
 *
 *  @return The instantiated instance from the `dictionary`
 */
+ (instancetype)requestOptionsFromDictionary:(NSDictionary *)dictionary;

/**
 *  Creates and returns a new `AWFRequestOptions` instance initialized with the specified query string.
 *
 *  @param queryString The query string to populate the new instance with.
 *
 *  @return The initialized instance from the `queryString`
 */
+ (instancetype)requestOptionsFromQueryString:(NSString *)queryString;

/**
 *  Creates and returns a new `AWFRequestOptions` instance initialized using the given URL path.
 *
 *  @param URLPath URL path to create the instance from
 *
 *  @return The initialized instance from the `URLPath`
 */
+ (instancetype)requestOptionsFromURLPath:(NSString *)URLPath;

/**
 *  Returns a dictionary representation of the options defined in the request object. This is often used when passing the options as
 *  parameters to the actual request.
 */
- (NSDictionary *)optionsAsDictionary;

/**
 *  Returns a formatted URL query string representation of the options defined in the request option.
 *
 *  @return The formatted URL query string from the receiver.
 */
- (NSString *)optionsAsQueryString;

/**
 *  Returns a formatted URL query string representation of the options defined in the request option, but eliminating the place value from the string.
 *
 *  @return The formatted URL query string from the receiver ignoring the place value.
 */
- (NSString *)optionsAsQueryStringIgnoringPlace;

//-----------------------------------------------------------------------------
// @name Filtering Results
//-----------------------------------------------------------------------------

/**
 *  Adds a filter item to the request's filter option.
 *
 *  @param filter The filter item to add.
 *  @see AWFRequestFilter
 */
- (void)addFilter:(AWFRequestFilter *)filter;

/**
 *  Adds an array of filter items to the request's filter option. The array provided should be an array of filter keys as strings.
 *
 *  @param filterNames The array of filter keys to add.
 */
- (void)addFiltersByName:(NSArray *)filterNames;

/**
 *  Removes a filter item from the request's filter option.
 *
 *  @param filter The filter item to remove.
 *  @see AWFRequestFilter
 */
- (void)removeFilter:(AWFRequestFilter *)filter;

/**
 *  Removes an array of filters from the request's filter option. The array provided should be an array of filter keys as strings.
 *
 *  @param filterNames The array of filter keys to remove.
 */
- (void)removeFiltersByName:(NSArray *)filterNames;

/**
 *  Removes all filter items from the request's filter option.
 */
- (void)removeAllFilters;

//-----------------------------------------------------------------------------
// @name Performing Queries
//-----------------------------------------------------------------------------

/**
 *  Adds a query item to the request's query option.
 *
 *  @param query The query item to add.
 *  @see AWFRequestQuery
 */
- (void)addQuery:(AWFRequestQuery *)query;

/**
 *  Removes a query item from the request's query option.
 *
 *  @param query The query item to remove.
 *  @see AWFRequestQuery
 */
- (void)removeQuery:(AWFRequestQuery *)query;

/**
 *  Removes all query items from the request's query option.
 */
- (void)removeAllQueries;

//-----------------------------------------------------------------------------
// @name Comparing Request Options
//-----------------------------------------------------------------------------

/**
 *  Returns a Boolean value that indicates whether a request options instance is equal to the receiver by comparing the values between each instance.
 *
 *  @param options The request options with which to compare the receiver.
 *
 *  @return `YES` if the request options are equal, otherwise `NO`.
 */
- (BOOL)isEqualToRequestOptions:(AWFRequestOptions *)options;

@end