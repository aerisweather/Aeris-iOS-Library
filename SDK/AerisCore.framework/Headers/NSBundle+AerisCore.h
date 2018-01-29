//
//  NSBundle+AerisCore.h
//  AerisCore
//
//  Created by Nicholas Shipes on 11/24/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSBundle (AerisCore)

- (NSString *)awf_appVersion;
- (NSString *)awf_appBuild;

+ (NSBundle *)aerisBundle;
+ (NSBundle *)aerisStringsBundle;

@end
