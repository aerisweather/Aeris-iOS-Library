//
//  AWFGlobals.h
//  Aeris
//	$Id$
//
//  Created by Nicholas Shipes on 4/27/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <AerisWeatherKit/NSBundle+Aeris.h>

// common symbols
#define AWFDegree	[NSString stringWithUTF8String:"\xC2\xB0"]

#define AWF_DEPRECATED(info) __attribute((deprecated(info)));
#define AWF_NONPREFERRED_INITIALIZER(info) __attribute((unavailable(info)));

NS_ASSUME_NONNULL_BEGIN

//#define AWFLocalizedString(key, comment) NSLocalizedStringFromTableInBundle(key, @"Localizable", [NSBundle aerisBundle], comment)

/**
 Returns the localized string for the specified key from the AerisWeather language bundle.
 
 If the specified `key` is not found in the AerisWeather strings lookup table, this function will fall back to `NSLocalizedString()`.
 */
NSString * AWFLocalizedString(NSString *key, NSString * _Nullable comment);

//-----------------------------------------------------------------------------
// @name Unit Conversions
//-----------------------------------------------------------------------------

typedef NSString * AWFUnit NS_TYPED_EXTENSIBLE_ENUM;

/**
 Celsius unit string
 */
extern AWFUnit const AWFUnitCelsius;

/**
 Fahrenheit unit string
 */
extern AWFUnit const AWFUnitFahrenheit;

/**
 Kilometers unit string
 */
extern AWFUnit const AWFUnitKilometers;

/**
 Meters unit string
 */
extern AWFUnit const AWFUnitMeters;

/**
 Centimeters unit string
 */
extern AWFUnit const AWFUnitCentimeters;

/**
 Millimeters unit string
 */
extern AWFUnit const AWFUnitMillimeters;

/**
 Miles unit string
 */
extern AWFUnit const AWFUnitMiles;

/**
 Feet unit string
 */
extern AWFUnit const AWFUnitFeet;

/**
 Inches unit string
 */
extern AWFUnit const AWFUnitInches;

/**
 Kilometers per hour unit string
 */
extern AWFUnit const AWFUnitKilometersPerHour;

/**
 Miles per hour unit string
 */
extern AWFUnit const AWFUnitMilesPerHour;

/**
 Meters per second unit string
 */
extern AWFUnit const AWFUnitMetersPerSecond;

/**
 Knots unit string
 */
extern AWFUnit const AWFUnitKnots;

/**
 Percent unit string
 */
extern AWFUnit const AWFUnitPercent;

/**
 Millibars unit string
 */
extern AWFUnit const AWFUnitMillibars;

/**
 Milligrams per cubic meters unit string
 */
extern AWFUnit const AWFUnitMilligramsPerCubicMeters;

/**
 Decibels (radar) unit string
 */
extern AWFUnit const AWFUnitDbz;


/**
 Returns whether or not the specified `unit` corresponds to a Metric value.

 @param unit The `AWFUnit` value
 @return `YES` if the unit is for Metric values, otherwise `NO`.
 */
BOOL AWFUnitIsMetric(AWFUnit unit);

CGFloat AWFConvertFtoC(CGFloat value);
CGFloat AWFConvertCtoF(CGFloat value);
CGFloat AWFConvertMPHtoKMH(CGFloat value);
CGFloat AWFConvertKMHtoMPH(CGFloat value);
CGFloat AWFConvertMPHtoKTS(CGFloat value);
CGFloat AWFConvertKMHtoKTS(CGFloat value);
CGFloat AWFConvertKTStoMPH(CGFloat value);
CGFloat AWFConvertKTStoKMH(CGFloat value);
CGFloat AWFConvertMItoKM(CGFloat value);
CGFloat AWFConvertKMtoMI(CGFloat value);
CGFloat AWFConvertINtoCM(CGFloat value);
CGFloat AWFConvertCMtoIN(CGFloat value);
CGFloat AWFConvertINtoMB(CGFloat value);
CGFloat AWFConvertMBtoIN(CGFloat value);

/**
 Converts a value from one unit to another. The units must belong to the same measurement type (e.g., temperature, speed, distance, etc).

 @param value The value to convert
 @param from The current units the value is provided in
 @param to The units to convert the specified value to
 @return The converted value
 */
CGFloat AWFConvert(CGFloat value, AWFUnit from, AWFUnit to);

/**
 Tests if an object is a non-empty string.
 */
BOOL AWFIsNonEmptyString(id object);
BOOL AWFIsEmpty(id object);

/**
 Returns whether the specified `object` is a valid place string in the format *city, state*, *city, country* or *city, state, country* (e.g. *seattle,wa* or *paris,france*).

 @param object The object to validate.
 @return `YES` if the object is a valid place string, otherwise `NO`.
 */
BOOL AWFIsValidPlaceString(id object);

/**
 Returns whether the specified `object` is a valid zip code or postal code string (e.g. *55415* or *V5K 1L5*).

 @param object The object to validate.
 @return `YES` if the object is a valid zip code/postal code string, otherwise `NO`.
 */
BOOL AWFIsValidZipcodeString(id object);

/**
 Returns whether the specified `object` is a valid coordinate string in the format *latitude, longitude* (e.g. *30.26715, -97.74306*).

 @param object The object to validate.
 @return `YES` if the object is a valid coordinate string, otherwise `NO`.
 */
BOOL AWFIsValidCoordinateString(id object);

/**
 Returns whether the specified `coordinate` is empty, meaning both its latitude and longitude values are defined as `0.0`.

 @param coordinate The coordinate to validate.
 @return `YES` if the coordinate has its latitude and longitude values defined as `0.0`, otherwise `NO`.
 */
BOOL AWFCLLocationCoordinate2DIsEmpty(CLLocationCoordinate2D coordinate);

NS_ASSUME_NONNULL_END

