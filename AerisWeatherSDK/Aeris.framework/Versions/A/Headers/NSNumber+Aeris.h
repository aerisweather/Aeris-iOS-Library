//
//  NSNumber+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/**
 *  Provides extensions to `NSNumber` for performing common tasks.
 */
@interface NSNumber (Aeris)

/**
 *  Returns the closest number that is divisible by the specified interval to the receiver.
 *
 *  @param interval The closest interval to round to
 */
- (NSNumber *)awf_roundToNearestInterval:(CGFloat)interval;

@end