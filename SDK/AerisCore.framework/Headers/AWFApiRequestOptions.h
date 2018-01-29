//
//  AWFApiRequestOptions.h
//  AerisApiLibrary
//
//  Created by Nicholas Shipes on 4/27/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AWFApiRequestOptions : NSObject <NSCopying>

@property (copy, nonatomic) NSString *action;

+ (instancetype)options;
+ (instancetype)optionsFromDictionary:(NSDictionary *)dictionary;
+ (instancetype)optionsFromQueryString:(NSString *)queryString;
+ (instancetype)optionsFromURLPath:(NSString *)URLPath;

- (NSDictionary *)optionsAsDictionary;
- (NSString *)optionsAsQueryString;

@end
