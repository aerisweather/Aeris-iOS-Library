//
//  NSDictionary+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Provides extension to `NSDictionary` for performing common tasks.
 */
@interface NSDictionary (Aeris)

/**
 *  Initializes a new dictionary containing the keys and values from the specified query string.
 *
 *  @param queryString The query parameters to parse
 *
 *  @return A new dictionary containing the specified query parameters.
 */
+ (instancetype)awf_dictionaryWithQueryString:(NSString *)queryString;

/**
 *  Converts the dictionary to a serialized key/value pair string, typically used for query strings.
 *
 *  @return The serialized string from the dictionary.
 */
- (NSString *)awf_serializedString;

@end