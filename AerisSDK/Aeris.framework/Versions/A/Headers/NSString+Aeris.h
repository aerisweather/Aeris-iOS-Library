//
//  NSString+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/25/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Aeris)

- (NSString *)awf_URLEncodedString;
- (NSString *)awf_URLDecodedString;
- (NSString *)awf_stringByFormattingCardinalAbbreviations;

- (NSString *)awf_stringByTrimmingLeadingAndTrailingCharactersInSet:(NSCharacterSet *)characterSet;
- (NSString *)awf_stringByTrimmingLeadingAndTrailingWhitespaceAndNewlineCharacters;
- (NSString *)awf_stringByTrimmingLeadingCharactersInSet:(NSCharacterSet *)characterSet;
- (NSString *)awf_stringByTrimmingLeadingWhitespaceAndNewlineCharacters;
- (NSString *)awf_stringByTrimmingTrailingCharactersInSet:(NSCharacterSet *)characterSet;
- (NSString *)awf_stringByTrimmingTrailingWhitespaceAndNewlineCharacters;

@end
