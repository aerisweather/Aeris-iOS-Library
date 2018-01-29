//
//  NSSet+AerisCore.h
//  AerisCore
//
//  Created by Nicholas Shipes on 7/14/16.
//  Copyright © 2016 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSSet (AerisCore)

- (NSSet *)awf_filterObjectsUsingBlock:(BOOL (^)(id obj))block;

@end
