//
//  AWFWeatherRequestOptions.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <AerisCore/AerisCore.h>
#import <AerisWeatherKit/AWFWeatherApiClient.h>
#import <AerisWeatherKit/AWFWeatherObject.h>
#import <AerisWeatherKit/AWFPlace.h>
#import <AerisWeatherKit/AWFCoordinateBounds.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFRequestFilter;

/**
 The sorting codes to use for a request's `sort` direction option, such as `sort=field:direction`.

 - AWFRequestSortDescending: Sorts results based on the associated field name in descending order
 - AWFRequestSortDisabled: Disables any specific sorting on the field name
 - AWFRequestSortAscending: Sorts the results based on the associated field name in ascending order
 - AWFRequestSortDefault: The default sorting order
 */
typedef NS_ENUM(NSInteger, AWFRequestSort) {
	AWFRequestSortDescending = -1,
	AWFRequestSortDisabled = 0,
	AWFRequestSortAscending = 1,
	AWFRequestSortDefault = AWFRequestSortAscending
};

/**
 The operators used when combining multiple queries in a request.

 - AWFRequestOperatorOr: Joins queries using an `OR` operator
 - AWFRequestOperatorAnd: Joins queries using an `AND` operator
 */
typedef NS_ENUM(NSUInteger, AWFRequestOperator) {
	AWFRequestOperatorOr = 0,
	AWFRequestOperatorAnd
};

@class AWFRequestQuery;

typedef NSDictionary<AWFWeatherParamKey, NSObject *> *AWFApiParameters;

/**
 An `AWFRequesetOptions` object represents all of the supported options that can be passed to an API request through `AWFWeatherEndpoint` instances. This
 is a convenience class that will properly format parameters as required by the API before the request is actually initiated.
 */
@interface AWFWeatherRequestOptions : AWFApiRequestOptions

/**
 A unique identifier to be used for the request, if any.
 */
@property (nonatomic, copy, nullable) NSString *identifier;

/**
 The place to use for the request. This corresponds to the `AWFWeatherParamKeyPlace`, or `p`, parameter when accessing the API directly.
 */
@property (nonatomic, strong, nullable) AWFPlace *place;

/**
 The coordinate bounds to use for the request. This corresponds to the `AWFWeatherParamKeyPlace`, or `p`, parameter when accessing the API directly 
 and using a coordinate region instead of a single place. 
 
 Coordinate bounds aer typically only used with `within` request actions on endpoints that support it.
 */
@property (nonatomic, strong, nullable) AWFCoordinateBounds *bounds;

/**
 A string of comma-separated latitude/longitude coordinates defining a bounding region. This corresponds to the `AWFWeatherParamKeyPlace`,
 or `p`, parameter when accessing the API directly and using a coordinate region instead of a single place.
 
 Coordinate bounds aer typically only used with `within` request actions on endpoints that support it.
 */
@property (nonatomic, nullable) NSString *boundsString;

/**
 The maximum number of objects to return. This corresponds to the `AWFWeatherParamKeyLimit`, or `limit`, parameter when accessing the API
 directly.
 */
@property (nonatomic, assign) NSUInteger limit;

/**
 The number of items to skip from the expected data set. This corresponds to the `AWFWeatherParamKeySkip`, or `skip`, parameter when
 accessing the API directly.
 */
@property (nonatomic, assign) NSUInteger skip;

/**
 The search radius, in miles, to use when performing a closest request from a single location. If `radiusKM` is defined, this value is
 ignored in the request. This corresponds to the `AWFWeatherParamKeyRadius`, or `radius`, parameter when accessing the API directly.
 */
@property (nonatomic, assign) NSUInteger radiusMI;

/**
 The search radius, in kilometers, to use when performing a closest request from a single location. This value will take precedence over
 `radiusMI` if both values are defined. This corresponds to the `AWFWeatherParamKeyRadius`, or `radius`, parameter when accessing the API
 directly.
 */
@property (nonatomic, assign) NSUInteger radiusKM;

/**
 The search radius as a distance string in miles or kilometers (e.g. `@"50mi"`, `@"100km"`).
 */
@property (nonatomic, nullable) NSString *radiusString;

/**
 The query string to use when performing a search request. This corresponds to the `AWFWeatherParamKeyQuery`, or `query`, parameter when
 accessing the API directly.
 */
@property (nonatomic, nullable) NSString *queryString;

/**
 Returns an array of `AWFRequestQuery` instances currently assigned.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<AWFRequestQuery *> *queries;

/**
 A string of comma-separated filter keys to limit the request to. This corresponds to the `AWFWeatherParamKeyFilter`, or `filter`,
 parameter when accessing the API directly.
 */
@property (nonatomic, nullable) NSString *filterString;

/**
 Returns an array of `AWFRequestFilter` instances currently assigned.
 */
@property (readonly, nonatomic, strong, nullable) NSArray<AWFRequestFilter> *filters;

/**
 A string of comma-separate field names to limit the request to. This corresponds to the `AWFWeatherParamKeyFields`, or `fields`, parameter
 when accessing the API directly.
 */
@property (nonatomic, copy, nullable) NSString *fields;

/**
 The order in which to sort the returned objects, either ascending (default) or descending. This corresponds to the
 `AWFWeatherParamKeySort`, or `sort`, parameter when accessing the API directly.
 */
@property (nonatomic, copy, nullable) NSString *sort;

/**
 The starting date from which to request objects for. This corresponds to the `AWFWeatherParamKeyDateFrom`, or `from`, parameter when
 accessing the API directly.
 */
@property (nonatomic, strong, nullable) NSDate *fromDate;

/**
 The starting date string from which to request objects for. This value can be in the format of a relative string, `@"-2 days"`, or an
 actual date, `@"2/7/2014"`. This corresponds to the `AWFWeatherParamKeyDateFrom`, or `from`, parameter when accessing the API directly.
 */
@property (nonatomic, copy, nullable) NSString *fromDateString;

/**
 The ending date to which to request objects for. This corresponds to the `AWFWeatherParamKeyDateTo`, or `to`, parameter when accessing the
 API directly.
 */
@property (nonatomic, strong, nullable) NSDate *toDate;

/**
 The ending date to which to request objects for. This value can be in the format of a relative string, `@"+2 days"`, or an actual date,
 `@"2/7/2015"`. This corresponds to the `AWFWeatherParamKeyDateTo`, or `to`, parameter when accessing the API directly.
 */
@property (nonatomic, copy, nullable) NSString *toDateString;

//-----------------------------------------------------------------------------
// @name Periods
//-----------------------------------------------------------------------------

/**
 The total number of periods to return. This option is only used for objects that contain a `periods` property. This corresponds to the
 `AWFWeatherParamKeyPeriodLimit`, or `plimit`, parameter when accessing the API directly.
 */
@property (nonatomic, assign) NSUInteger periodLimit;

/**
 The total number of periods to skip. This option is only used for objects that contain a `periods` property. This corresponds to the
 `AWFWeatherParamKeyPeriodSkip`, or `pskip`, parameter when accessing the API directly.
 */
@property (nonatomic, assign) NSUInteger periodSkip;

/**
 The order in which to sort the periods. This option is only used for objects that contain a `periods` property. This corresponds to the
 `AWFWeatherParamKeyPeriodSort`, or `psort`, parameter when accessing the API directly.
 */
@property (nonatomic, copy, nullable) NSString *periodSort;

/**
 The default endpoint action to use for a request. This value will be ignored when performing a request with a pre-defined endpoint action requirement. 
 */
@property (nonatomic, copy, nullable) AWFWeatherRequestAction action;

//-----------------------------------------------------------------------------
// @name Output Format
//-----------------------------------------------------------------------------

/**
 The format type for the request response. The default is the standard Aeris API response as a JSON object.
 */
@property (nonatomic, copy, nullable) NSString *format;

/**
 Creates and returns a new `AWFWeatherRequestOptions` instance using the provided dictionary values.
 
 @param dictionary A dictionary of values to assign to the instance. These must be valid API parameter keys.
 @return The instantiated instance from the `dictionary`
 */
+ (instancetype)optionsFromDictionary:(nullable NSDictionary<NSString *, id> *)dictionary;

/**
 Creates and returns a new `AWFWeatherRequestOptions` instance initialized with the specified query string.
 
 @param queryString The query string to populate the new instance with.
 @return The initialized instance from the `queryString`
 */
+ (instancetype)optionsFromQueryString:(nullable NSString *)queryString;

/**
 Creates and returns a new `AWFWeatherRequestOptions` instance initialized using the given URL path.
 
 @param URLPath URL path to create the instance from
 @return The initialized instance from the `URLPath`
 */
+ (instancetype)optionsFromURLPath:(nullable NSString *)URLPath;

/**
 Returns a dictionary representation of the options defined in the request object. This is often used when passing the options as
 parameters to the actual request.
 */
- (NSDictionary<NSString *, id> *)optionsAsDictionary;

/**
 Returns a formatted URL query string representation of the options defined in the request option.
 
 @return The formatted URL query string from the receiver.
 */
- (NSString *)optionsAsQueryString;

/**
 Returns a formatted URL query string representation of the options defined in the request option, but eliminating the place value from the string.
 
 @return The formatted URL query string from the receiver ignoring the place value.
 */
- (NSString *)optionsAsQueryStringIgnoringPlace;

//-----------------------------------------------------------------------------
// @name Filtering Results
//-----------------------------------------------------------------------------

/**
 Adds a filter item to the request's filter option.
 
 @param filter The filter item to add.
 @see AWFRequestFilter
 */
- (void)addFilter:(AWFRequestFilter)filter;

/**
 Removes a filter item from the request's filter option.
 
 @param filter The filter item to remove.
 @see AWFRequestFilter
 */
- (void)removeFilter:(AWFRequestFilter)filter;

/**
 Removes all filter items from the request's filter option.
 */
- (void)removeAllFilters;

//-----------------------------------------------------------------------------
// @name Performing Queries
//-----------------------------------------------------------------------------

/**
 Adds a query item to the request's query option.
 
 @param query The query item to add.
 @see AWFRequestQuery
 */
- (void)addQuery:(AWFRequestQuery *)query;

/**
 Removes a query item from the request's query option.
 
 @param query The query item to remove.
 @see AWFRequestQuery
 */
- (void)removeQuery:(AWFRequestQuery *)query;

/**
 Removes all query items from the request's query option.
 */
- (void)removeAllQueries;

//-----------------------------------------------------------------------------
// @name Comparing Request Options
//-----------------------------------------------------------------------------

/**
 Returns a Boolean value that indicates whether a request options instance is equal to the receiver by comparing the values between each instance.
 
 @param options The request options with which to compare the receiver.
 @return `YES` if the request options are equal, otherwise `NO`.
 */
- (BOOL)isEqualToRequestOptions:(AWFWeatherRequestOptions *)options;

/**
 Overrides an existing `AWFWeatherRequestOptions` instance's options with those from another instance.

 @param otherOptions The options instance to apply to the existing instance
 */
- (void)applyOptions:(AWFWeatherRequestOptions *)otherOptions;

/**
 Initializes and returns a new `AWFWeatherRequestOptions` instance by copying the instance and then overriding the values from another instance provided
 by `otherOptions`.

 @param otherOptions The options instance to apply to the copy
 */
- (AWFWeatherRequestOptions *)optionsByApplyingOptions:(AWFWeatherRequestOptions *)otherOptions;

@end

NS_ASSUME_NONNULL_END
