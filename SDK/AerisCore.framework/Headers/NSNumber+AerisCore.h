//
//  NSNumber+AerisCore.h
//  AerisCore
//
//  Created by Nicholas Shipes on 11/20/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface NSNumber (AerisCore)

/**
 *  Returns the closest number that is divisible by the specified interval to the receiver.
 *
 *  @param interval The closest interval to round to
 */
- (NSNumber *)awf_roundToNearestInterval:(CGFloat)interval;

@end
