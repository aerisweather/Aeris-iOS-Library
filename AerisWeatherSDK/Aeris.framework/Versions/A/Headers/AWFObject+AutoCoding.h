//
//  AWFObject+AutoCoding.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/31/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

@interface AWFObject (AutoCoding) <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
// @name Coding
//-----------------------------------------------------------------------------
+ (NSDictionary *)codableProperties;
- (void)setWithCoder:(NSCoder *)aDecoder;

//-----------------------------------------------------------------------------
// @name Property Access
//-----------------------------------------------------------------------------
- (NSDictionary *)codableProperties;
- (NSDictionary *)dictionaryRepresentation;

//-----------------------------------------------------------------------------
// @name Loading & Saving
//-----------------------------------------------------------------------------
+ (instancetype)objectWithContentsOfFile:(NSString *)path;
- (BOOL)writeToFile:(NSString *)filePath atomically:(BOOL)useAuxiliaryFile;

@end
