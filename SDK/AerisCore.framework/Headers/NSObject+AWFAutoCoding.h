//
//  NSObject+AWFAutoCoding.h
//  AerisCore
//
//  Created by Nicholas Shipes on 11/30/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (AWFAutoCoding) <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
// @name Auto Coding
//-----------------------------------------------------------------------------

+ (instancetype)awf_objectWithContentsOfFile:(NSString *)path;
+ (NSDictionary *)awf_codableProperties;
- (void)awf_setWithCoder:(NSCoder *)aDecoder;
- (NSDictionary *)awf_codableProperties;
- (NSDictionary *)awf_dictionaryRepresentation;
- (BOOL)awf_writeToFile:(NSString *)filePath atomically:(BOOL)useAuxiliaryFile;

@end
