//
//  NSBundle+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/9/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Helpers and utilities on `NSBundle` for use within the Aeris SDK.
 */
@interface NSBundle (AerisWeather)

/**
 Returns the resource bundle associated with the library.
 */
+ (NSBundle *)awf_aerisWeatherBundle;

/**
 Returns the bundle containing the language strings files associated with the library.
 */
+ (NSBundle *)awf_aerisWeatherStringsBundle;

@end
