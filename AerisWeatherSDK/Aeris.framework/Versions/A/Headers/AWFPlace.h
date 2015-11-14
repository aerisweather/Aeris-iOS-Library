//
//  AWFPlace.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>
#import <Aeris/AWFGeographicObject.h>

@class AWFPlace;

typedef void (^AWFPlaceGeolocateCompletionBlock)(AWFPlace *place, NSError *error);

@interface AWFPlace : AWFGeographicObject

/**
 Latitude position of the location.
 */
@property (nonatomic, strong) NSNumber *latitude;

/**
 Longitude position of the location.
 */
@property (nonatomic, strong) NSNumber *longitude;

/**
 *  The coordinate based on the defined latitude and longitude values.
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 *  A `CLLocation` instance using the assigned coordinate for this object.
 */
@property (nonatomic, strong) CLLocation *location;

/**
 Primary name of the location.
 */
@property (nonatomic, copy) NSString *name;

/**
 Abbreviated state or province for the location, if available.
 */
@property (nonatomic, copy) NSString *state;

/**
 Full state or province name for the location, if available.
 */
@property (nonatomic, copy) NSString *stateFull;

/**
 Abbreviated country for the location.
 */
@property (nonatomic, copy) NSString *country;

/**
 Full country name for the location.
 */
@property (nonatomic, copy) NSString *countryFull;

/**
 *  County name for the location.
 *	@since 2.0.0
 */
@property (nonatomic, copy) NSString *county;

/**
 *  Full place name formatted with the state and country when available.
 */
@property (nonatomic, readonly) NSString *formattedNameFull;

/**
 Zip code associated with the place, if defined.
 */
@property (nonatomic, copy) NSString *zipcode;

/**
 Abbreviated geographical region for the location (US-based locations only).
 */
@property (nonatomic, copy) NSString *region;

/**
 Geographical region for the location (US-based locations only).
 */
@property (nonatomic, copy) NSString *regionFull;

/**
 Abbreviated continent the location belongs to.
 */
@property (nonatomic, copy) NSString *continent;

/**
 Full continent name the location belongs to.
 */
@property (nonatomic, copy) NSString *continentFull;

//-----------------------------------------------------------------------------
// @name Location Timezone
//-----------------------------------------------------------------------------

/**
 Timezone offset from GMT for the location in seconds.
 */
@property (nonatomic, strong) NSNumber *tzoffset;

/**
 Timezone abbreviation for the location.
 */
@property (nonatomic, copy) NSString *tzname;

/**
 Timezone identifier string.
 */
@property (nonatomic, copy) NSString *tz;

/**
 *  Local time zone object for the location.
 *	@since 2.0.0
 */
@property (nonatomic, strong) NSTimeZone *timeZone;

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
@property (nonatomic, strong) NSNumber *elevationM;

/**
 Elevation of the location in feet.
 */
@property (nonatomic, strong) NSNumber *elevationFT;

/**
 Population of the location.
 */
@property (nonatomic, strong) NSNumber *population;

/**
 Creates and returns an autoreleased `AWFPlace` instance with a city, state and country.
 */
+ (AWFPlace *)placeWithCity:(NSString *)city state:(NSString *)state country:(NSString *)country;

/**
 Creates and returns an autoreleased `AWFPlace` instance with a latitude and longitude position.
 */
+ (AWFPlace *)placeWithLatitude:(CGFloat)latitude longitude:(CGFloat)longitude;

/**
 Creates and returns an autoreleased `AWFPlace` instance for the provided coordinate.
 */
+ (AWFPlace *)placeWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 Creates and returns an autoreleased `AWFPlace` instance with a zipcode.
 
 Only US and Canadian zipcodes are currently supported.
 */
+ (AWFPlace *)placeWithZipcode:(NSString *)zipcode;

/**
 *  Instantiates and returns an `AWFPlace` instance with the provided place string. The string can be in the format of `city,state,country`, 
 *  `city,country`, `lat,lon`, or `zipcode`, etc.
 *
 *  @param string The place string
 *
 *  @return A place created from the provided place string
 */
+ (AWFPlace *)placeFromString:(NSString *)string;


+ (void)getCurrentLocationWithCompletion:(AWFPlaceGeolocateCompletionBlock)completionBlock;

- (id)initWithCity:(NSString *)city state:(NSString *)state country:(NSString *)country;
- (id)initWithLatitude:(CGFloat)latitude longitude:(CGFloat)longitude;
- (id)initWithZipcode:(NSString *)zipcode;

/**
 Generates the place string properly formatted for API requests based on this place configuration.
 */
- (NSString *)stringForQuery;

/**
 Generates the string required for direct-queries via the API based on this place configuration.
 */
- (NSString *)stringForSearch;

/**
 Returns whether or not the place is valid based on the resulting string used for API queries.
 */
- (BOOL)isValid;

//-----------------------------------------------------------------------------
// @name Place Comparisons
//-----------------------------------------------------------------------------

/**
 *  Determines whether the receiver is equal to the specified place by comparing the place name.
 *
 *  @param place The place to compare
 *
 *  @return `YES` if the receiver's name is equal to the `place`, otherwise `NO`
 */
- (BOOL)isEqualToPlaceByComparingName:(AWFPlace *)place;

@end
