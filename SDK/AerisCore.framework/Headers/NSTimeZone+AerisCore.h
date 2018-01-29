//
//  NSTimeZone+AerisCore.h
//  AerisCore
//
//  Created by Nicholas Shipes on 11/20/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSTimeZone (AerisCore)

+ (instancetype)awf_timeZoneFromDateString:(NSString *)dateString;

@end
