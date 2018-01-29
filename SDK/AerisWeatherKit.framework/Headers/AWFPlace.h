//
//  AWFPlace.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>
#import <AerisWeatherKit/AWFGeographicObject.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFPlace;

typedef void (^AWFPlaceGeolocateCompletionBlock)(AWFPlace * _Nullable place, NSError * _Nullable error);

/**
 An `AWFPlace` object represents data returned by the [**places** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/places/)
 of the Aeris Weather API.
 */
@interface AWFPlace : AWFGeographicObject

/**
 The coordinate based on the defined latitude and longitude values.
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 A `CLLocation` instance using the assigned coordinate for this object.
 */
@property (nonatomic, strong, nullable) CLLocation *location;

/**
 Primary name of the location.
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 Abbreviated state or province for the location, if available.
 */
@property (nonatomic, copy, nullable) NSString *state;

/**
 Full state or province name for the location, if available.
 */
@property (nonatomic, copy, nullable) NSString *stateFull;

/**
 Abbreviated country for the location.
 */
@property (nonatomic, copy, nullable) NSString *country;

/**
 Full country name for the location.
 */
@property (nonatomic, copy, nullable) NSString *countryFull;

/**
 County name for the location.
 */
@property (nonatomic, copy, nullable) NSString *county;

/**
 Full place name formatted with the state and country when available.
 */
@property (nonatomic, readonly, nullable) NSString *formattedNameFull;

/**
 Zip code associated with the place, if defined.
 */
@property (nonatomic, copy, nullable) NSString *zipcode;

/**
 Abbreviated geographical region for the location (US-based locations only).
 */
@property (nonatomic, copy, nullable) NSString *region;

/**
 Geographical region for the location (US-based locations only).
 */
@property (nonatomic, copy, nullable) NSString *regionFull;

/**
 Abbreviated continent the location belongs to.
 */
@property (nonatomic, copy, nullable) NSString *continent;

/**
 Full continent name the location belongs to.
 */
@property (nonatomic, copy, nullable) NSString *continentFull;

//-----------------------------------------------------------------------------
// @name Location Timezone
//-----------------------------------------------------------------------------

/**
 Local time zone object for the location.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

/**
 Whether or not the location is current observing daylight savings time (DST).
 */
@property (nonatomic, assign) BOOL isDst;

//-----------------------------------------------------------------------------
// @name Location Profile Data
//-----------------------------------------------------------------------------

/**
 Elevation of the location in meters.
 */
@property (nonatomic, assign) CGFloat elevationM;

/**
 Elevation of the location in feet.
 */
@property (nonatomic, assign) CGFloat elevationFT;

/**
 Population of the location.
 */
@property (nonatomic, assign) CGFloat population;

/**
 Initializes and returns a newly allocated place object with the specified city, state, and/or country strings.
 
 @return An initialized place object.
 */
- (instancetype)initWithCity:(nonnull NSString *)city state:(nullable NSString *)state country:(nonnull NSString *)country;

/**
 Initializes and returns a newly allocated place object with the specified latitude and longitude values.
 
 @return An initialized place object.
 */
- (instancetype)initWithLatitude:(CGFloat)latitude longitude:(CGFloat)longitude;

/**
 Initializes and returns a newly allocated place object with the specified zip code string.
 
 Only US and Canadian zip codes are currently supported.
 
 @return An initialized place object.
 */
- (instancetype)initWithZipcode:(nonnull NSString *)zipcode;

/**
 Generates the place string properly formatted for API requests based on this place configuration.
 */
- (nullable NSString *)stringForQuery;

/**
 Generates the string required for direct-queries via the API based on this place configuration.
 */
- (nullable NSString *)stringForSearch;

/**
 Returns whether the place is valid based on the resulting string used for API queries.
 */
- (BOOL)isValid;

//-----------------------------------------------------------------------------
// @name Place Comparisons
//-----------------------------------------------------------------------------

/**
 Determines whether the receiver is equal to the specified place by comparing the place name.
 
 @param place The place to compare
 @return `YES` if the receiver's name is equal to the `place`, otherwise `NO`
 */
- (BOOL)isEqualToPlaceByComparingName:(nonnull AWFPlace *)place;

//-----------------------------------------------------------------------------
// @name Class Methods
//-----------------------------------------------------------------------------

/**
 Initializes and returns a newly allocated place object with the specified city, state, and/or country strings.
 
 @return An initialized place object.
 */
+ (instancetype)placeWithCity:(nonnull NSString *)city state:(nullable NSString *)state country:(nonnull NSString *)country;

/**
 Initializes and returns a newly allocated place object with the specified latitude and longitude values.
 
 @return An initialized place object.
 */
+ (instancetype)placeWithLatitude:(CGFloat)latitude longitude:(CGFloat)longitude;

/**
 Initializes and returns a newly allocated place object with the specified coordinate.
 
 @return An initialized place object.
 */
+ (instancetype)placeWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 Initializes and returns a newly allocated place object with the specified zip code string.
 
 Only US and Canadian zip codes are currently supported.
 
 @return An initialized place object.
 */
+ (instancetype)placeWithZipcode:(nonnull NSString *)zipcode;

/**
 Initializes and returns a newly allocated place object with the specified place string. The string can be in the format of `city,state,country`,
 `city,country`, `lat,lon`, or `zipcode`, etc.
 
 @param string The place string
 @return An initializes place object
 */
+ (instancetype)placeFromString:(nonnull NSString *)string;

/**
 Requests and returns a place object corresponding to the device's current location. Location services must be enabled in order for the place to be
 returned.

 @param completionBlock The completion block to execute on the success or failure of the place request. This block has no return value and takes two arguments:
 the `AWFPlace` instance associated with the device's current location, if any, and the error that occurred during the request.
 */
+ (void)getCurrentLocationWithCompletion:(AWFPlaceGeolocateCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
