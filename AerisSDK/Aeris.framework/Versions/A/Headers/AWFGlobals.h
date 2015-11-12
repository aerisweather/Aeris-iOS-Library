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

#import "AWFWeatherDataType.h"
#import "AWFMeasurement.h"
#import "NSBundle+Aeris.h"

// Testing for specific iOS versions
#define AWF_SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define AWF_SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define AWF_SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define AWF_SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

///-----------------------------
/// @name API Parameters & Codes
///-----------------------------

// Time Helpers
#define AWF_SECOND	1
#define AWF_MINUTE	60
#define AWF_HOUR	(60 * AWF_MINUTE)
#define AWF_DAY		(24 * AWF_HOUR)
#define AWF_WEEK	(7 * AWF_DAY)
#define AWF_MONTH	(30.5 * AWF_DAY)
#define AWF_YEAR	(365 * AWF_DAY)

// default expiration times
#define kAFDefaultCacheExpirationAge	AWF_WEEK
#define kAFMinCacheExpirationAge		AWF_MINUTE

// common symbols
#define AWFDegree	[NSString stringWithUTF8String:"\xC2\xB0"]

#define AWF_DEPRECATED(info) __attribute((deprecated(info)));
#define AWF_NONPREFERRED_INITIALIZER(info) __attribute((unavailable(info)));

///----------------
/// @name Utilities
///----------------

#if !defined(MIN)
	#define MIN(A,B)((A) < (B) ? (A) : (B))
#endif

#if !defined(MAX)
	#define MAX(A,B)((A) > (B) ? (A) : (B))
#endif

#ifndef NS_ENUM
	#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

//#define AWFLocalizedString(key, comment) NSLocalizedStringFromTableInBundle(key, @"Localizable", [NSBundle aerisBundle], comment)

NSString * AWFLocalizedString(NSString *key, NSString *comment);

//-----------------------------------------------------------------------------
// @name Unit Conversions
//-----------------------------------------------------------------------------

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

NSString * AWFUnitForWeatherDataType(AWFWeatherDataType type, BOOL metric);
NSString * AWFUnitForMeasurement(AWFMeasurement type, BOOL metric);

/**
 * Tests if an object is a non-empty string.
 */
BOOL AWFIsNonEmptyString(id object);
BOOL AWFIsEmpty(id object);

BOOL AWFIsValidPlaceString(id object);
BOOL AWFIsValidZipcodeString(id object);
BOOL AWFIsValidCoordinateString(id object);
BOOL AWFIsNumber(id object);
BOOL AWFIsInteger(id object);

/**
 *  Returns a string formatted to contain the data from a map coordinate.
 *
 *  @param coord The map coordinate to format.
 *
 *  @return A string that corresponds to the map coordinate.
 */
NSString *AWFStringFromCLLocationCoordinate2D(CLLocationCoordinate2D coord);

