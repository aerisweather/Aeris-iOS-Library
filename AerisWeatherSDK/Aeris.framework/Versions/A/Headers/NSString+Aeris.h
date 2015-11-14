//
//  NSString+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/25/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Provides extensions to `NSString` for various common tasks.
 */
@interface NSString (Aeris)

//-----------------------------------------------------------------------------
// @name Checking Contents
//-----------------------------------------------------------------------------

/**
 *  Returns whether or not the receiver contains the given `string`.
 *
 *  @param string A string to test the receiver for.
 *
 *  @return `YES` if the receiver contains the given `string`, otherwise `NO`
 */
- (BOOL)awf_containsString:(NSString *)string;

/**
 *  Returns whether or not the receiver matches the given `pattern`.
 *
 *  @param patternString The pattern string to test the receiver for
 *  @param options       The regular expression options to use when matching, or `0` for none.
 *
 *  @return `YES` if the receiver matches the given `pattern`, otherwise `NO`
 */
- (BOOL)awf_matchesPattern:(NSString *)patternString options:(NSRegularExpressionOptions)options;

//-----------------------------------------------------------------------------
// @name URL Encoding and Decoding
//-----------------------------------------------------------------------------

/**
 *  Returns a new string encoded for a URL.
 *
 *  @return A new string escaped for a URL.
 */
- (NSString *)awf_URLEncodedString;

/**
 *  Returns a new string decoded from a URL.
 *
 *  @return A new string decoded from a URL.
 */
- (NSString *)awf_URLDecodedString;

//-----------------------------------------------------------------------------
// @name Formatting
//-----------------------------------------------------------------------------

/**
 *  Returns a new string with all cardinal direction abbreviations properly formatted to uppercase.
 *
 *  @return A new string with properly formatted cardian direction abbreviations
 */
- (NSString *)awf_stringByFormattingCardinalAbbreviations;

/**
 *  Returns a new string by trimming leading and trailing characters in a given `NSCharacterSet`.
 *
 *  @param characterSet Character set to trim characters
 *
 *  @return A new string by trimming leading and trailing characters in `characterSet`.
 */
- (NSString *)awf_stringByTrimmingLeadingAndTrailingCharactersInSet:(NSCharacterSet *)characterSet;

/**
 *  Returns a new string by trimming leading and trailing whitespace and newline characters.
 *
 *  @return A new string by trimming leading and trailing whitespace and newline characters.
 */
- (NSString *)awf_stringByTrimmingLeadingAndTrailingWhitespaceAndNewlineCharacters;

/**
 *  Returns a new string by trimming leading characters in a given `NSCharacterSet`.
 *
 *  @param characterSet Character set to trim characters
 *
 *  @return A new string by trimming leading characters in `characterSet`
 */
- (NSString *)awf_stringByTrimmingLeadingCharactersInSet:(NSCharacterSet *)characterSet;

/**
 *  Returns a new string by trimming leading whitespace and newline characters.
 *
 *  @return A new string by trimming leading whitespace and newline characters.
 */
- (NSString *)awf_stringByTrimmingLeadingWhitespaceAndNewlineCharacters;

/**
 *  Returns a new string by trimming trailing characters in given `NSCharacterSet`.
 *
 *  @param characterSet Character set to trim characters
 *
 *  @return A new string by trimming trailing characters in `characterSet`
 */
- (NSString *)awf_stringByTrimmingTrailingCharactersInSet:(NSCharacterSet *)characterSet;

/**
 *  Returns a new string by trimming trailing whitespace and newline characters.
 *
 *  @return A new string by trimming trailing whitespace and newline characters.
 */
- (NSString *)awf_stringByTrimmingTrailingWhitespaceAndNewlineCharacters;

- (NSString *)awf_stringByReplacingPattern:(NSString *)pattern withString:(NSString *)replacementString;

//-----------------------------------------------------------------------------
// @name Hashes
//-----------------------------------------------------------------------------

/**
 *  Returns a string of the MD5 digest of the receiver.
 */
- (NSString *)awf_MD5;

/**
 *  Returns a string of the SHA1 digest of the receiver.
 */
- (NSString *)awf_SHA1;

/**
 *  Returns a string of the SHA224 digest of the receiver.
 */
- (NSString *)awf_SHA224;

/**
 *  Returns a string of the SHA256 digest of the receiver.
 */
- (NSString *)awf_SHA256;

/**
 *  Returns a string of the SHA384 digest of the receiver.
 */
- (NSString *)awf_SHA384;

/**
 *  Returns a string of the SHA512 digest of the receiver.
 */
- (NSString *)awf_SHA512;

@end
