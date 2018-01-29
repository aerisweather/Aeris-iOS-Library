//
//  NSDictionary+AerisCore.h
//  AerisCore
//
//  Created by Nicholas Shipes on 11/20/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (AerisCore)

- (BOOL)awf_isEmpty;

/**
 *  Initializes a new dictionary containing the keys and values from the specified query string.
 *
 *  @param queryString The query parameters to parse
 *
 *  @return A new dictionary containing the specified query parameters.
 */
+ (instancetype)awf_dictionaryWithQueryString:(NSString *)queryString;

- (instancetype)awf_dictionaryByAddingEntriesFromDictionary:(NSDictionary *)dictionary;

/**
 *  Converts the dictionary to a serialized key/value pair string, typically used for query strings.
 *
 *  @return The serialized string from the dictionary.
 */
- (NSString *)awf_serializedString;

@end
