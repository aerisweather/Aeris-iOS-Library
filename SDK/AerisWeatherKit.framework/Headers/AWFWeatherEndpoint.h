//
//  AWFWeatherEndpoint.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 1/24/17.
//  Copyright © 2017 Aeris Weather, LLC. All rights reserved.
//

#import <AerisCore/AerisCore.h>
#import <AerisWeatherKit/AWFWeatherObject.h>
#import <AerisWeatherKit/AWFCoordinateBounds.h>
#import <AerisWeatherKit/AWFGeoPolygon.h>
#import <AerisWeatherKit/AWFWeatherRequestOptions.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSArray<AWFWeatherObject *> * AWFWeatherEndpointArrayResultType;

/**
 An `AWFWeatherEndpointResult` instance is returned by an `AWFWeatherEndpoint` object upon completion of an API request. The returned instance will contain
 an array of results returned by the API for the request, if any, as the respective `AWFWeatherObject` subclass for that endpoint. Any error that occurred
 during the request will also be included with the `AWFWeatherEndpointResult` instance.
 */
@interface AWFWeatherEndpointResult : NSObject

/**
 The array of `AWFWeatherObject` instances as parsed from the API response.
 
 The returned instances will actually be instances of the respective `AWFWeatherObject` subclass that corresponds to the `AWFWeatherEndpoint` class that
 performed the request.
 */
@property (nonatomic, strong) AWFWeatherEndpointArrayResultType results;

/**
 The error, if any, that occurred during the request.
 */
@property (nonatomic, strong) NSError *error;

/**
 Creates and returns an `AWFWeatherEndpointResult` instance initialized with the provided `value` and `error`.

 @param value The response value as an array of `AWFWeatherObject` instances.
 @param error The error that occurred during the request.
 @return An instance initialized with the specified `value` and `error`.
 */
+ (instancetype)resultWithValue:(nullable AWFWeatherEndpointArrayResultType)value error:(nullable NSError *)error;

@end

@class AWFPlace;

/**
 `AWFWeatherEndpoint` is a concrete class that is responsible for handling all requests for a specific API endpoint. This class should not 
 be used as is, but rather should be subclassed to provided the required configuration for interacting with the Aeris Weather API.
 */
@interface AWFWeatherEndpoint : AWFApiEndpoint

//typedef AWFWeatherObject * AWFWeatherEndpointObjectResultType;
typedef void (^AWFWeatherEndpointCompletionBlock)(AWFWeatherEndpointResult * _Nullable result);

//typedef void (^AWFWeatherServiceArrayCompletionBlock)(NSArray<AWFWeatherObject *> * _Nullable results, NSError * _Nullable error);
//typedef void (^AWFWeatherServiceObjectCompletionBlock)(AWFWeatherObject * _Nullable result, NSError * _Nullable error);
//typedef void (^AWFWeatherServicePlacesCompletionBlock)(NSArray<AWFPlace *> * _Nullable results, NSError * _Nullable error);

/**
 The default request options to use for all requests performed by this endpoint. The default is `nil`.
 */
@property (nonatomic, strong, nullable) AWFWeatherRequestOptions *options;

/**
 Returns whether or not the endpoint instance currently has a request in progress.
 */
@property (nonatomic, assign) BOOL isLoading;


/**
 A shared instance of this endpoint class that can be used instead of instantiating individual instances for each request.
 */
+ (instancetype)sharedService;

- (instancetype)initWithPath:(NSString *)path objectClass:(Class)objectClass NS_UNAVAILABLE;

/**
 Requests objects for the specific place. The place must be a valid `AWFPlace` instance.
 
 @param place           The place to use for the request.
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
     the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getForPlace:(AWFPlace *)place options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(forPlace:options:completion:));

/**
 Requests objects for the specific place. The place must be a valid `AWFPlace` instance.
 
 @param place           The place to use for the request
 @param fromDate		The starting date to request data for, otherwise the endpoint's default will be used
 @param toDate			The ending date to request data for, otherwise the endpoint's default will be used
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getForPlace:(AWFPlace *)place fromDate:(nullable NSDate *)fromDate toDate:(nullable NSDate *)toDate options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(forPlace:from:to:options:completion:));

/**
 Requests objects for the specific place. The place must be a valid `AWFPlace` instance.
 
 @param place           The place to use for the request
 @param fromString		The starting date to request data for as a relative string, e.g. `-2days`, otherwise the endpoint's default will be used
 @param toString		The ending date to request data for as a relative string, e.g. `+5days`, otherwise the endpoint's default will be used
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getForPlace:(AWFPlace *)place from:(nullable NSString *)fromString to:(nullable NSString *)toString options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(forPlace:from:to:options:completion:));

/**
 Requests objects within a circle defined by a center at the specific place's coordinate and a radius. The place must be a valid
 `AWFPlace` instance.
 
 @param place           The place to use for the request.
 @param radius          The radius from the place's coordinate to include results for. Radius should be provided as a valid distance string, 
	(e.g., `@"50mi"` or `@"100km"`). If no radius is provided, the default of `@"25mi"` will be used.
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
     the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getClosestToPlace:(AWFPlace *)place radius:(NSString *)radius options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(closest(toPlace:radius:options:completion:));

/**
 Requests objects using the provided request options.
 
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getWithOptions:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(options:completion:));

/**
 Requests objects for the provided from and to dates.
 
 @param fromDate		The starting date to request data for, otherwise the endpoint's default will be used
 @param toDate			The ending date to request data for, otherwise the endpoint's default will be used
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getFromDate:(nullable NSDate *)fromDate toDate:(nullable NSDate *)toDate options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(from:to:options:completion:));

/**
 Requests objects for the specific place. The place must be a valid `AWFPlace` instance.
 
 @param fromString		The starting date to request data for as a relative string, e.g. `-2days`, otherwise the endpoint's default will be used
 @param toString		The ending date to request data for as a relative string, e.g. `+5days`, otherwise the endpoint's default will be used
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional).
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getFrom:(nullable NSString *)fromString to:(nullable NSString *)toString options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(get(from:to:options:completion:));

/**
 Requests objects within a circle defined by a center coordinate and a radius.

 @param centerCoordinate The center coordinate to use for the request
 @param radius The radius from the center coordinate to include results for. This value should be provided as a valid distance string (e.g. "50mi" or 100km")
 @param options An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional)
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
     the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getWithinCircleAtCoordinate:(CLLocationCoordinate2D)centerCoordinate radius:(nullable NSString *)radius options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(within(circleAt:radius:options:completion:));

/**
 Requests objects within a bounding box defined by top-left and bottom-right coordinates. The specified bounds must be a valid 
 `AWFCoordinateBounds` instance.
 
 @param bounds           The coordinate bounds for the request, defining the northwest and southeast coorners
 @param options          An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional)
 @param completionBlock  The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
     the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getWithinBounds:(AWFCoordinateBounds *)bounds options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(within(bounds:options:completion:));

/**
 Requests objects within an irregular polygon defined by the a series of coordinates. The specified polygon must be a valid
 `AWFGeoPolygon` instance.
 
 @param polygon         The polygon
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional)
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
     the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getWithinPolygon:(AWFGeoPolygon *)polygon options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(within(polygon:options:completion:));

/**
 Requests objects that contain the specified place, if any. This action is normally associated with endpoints that contain polygon data and returns only
 the objects associated with each polygon that contains the place.
 
 @param place           The place that must be contain within an object's polygon
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional)
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
     the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getContainingPlace:(AWFPlace *)place options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(containing(place:options:completion:));

/**
 Requests places currently affected by the object associated with this endpoint. This action is normally associated with endpoints that contain polygon or region-specific data, such as
 storm cells, drought indices or convective outlooks.

 @param object The endpoint object used with the request
 @param options An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional)
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
     the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getPlacesAffectedByObject:(AWFApiObject *)object options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(placesAffectedBy(object:options:completion:));

/**
 Requests places currently affected by an object associated with this endpoint using the specified object identifier. This action is normally associated with
 endpoints that contain polygon or region-specific data, such as storm cells, drought indices or convective outlooks.

 @param identifier The identifier associated with the endpoint object
 @param options An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional)
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
     the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)getPlacesAffectedByObjectWithIdentifier:(NSString *)identifier options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_SWIFT_NAME(placesAffectedBy(identifier:options:completion:));

/**
 Requests data based on a specific search query and request options. This method requires a valid `query` value on the provided
 options instance.
 
 Note: If no objects were returned from the request, but the request did not contain any errors, then the `completionBlock` block will still
 be executed without errors. Your block handler should verify the total number of objects returned before trying to access them.
 
 @param options         An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional)
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
     the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)search:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
