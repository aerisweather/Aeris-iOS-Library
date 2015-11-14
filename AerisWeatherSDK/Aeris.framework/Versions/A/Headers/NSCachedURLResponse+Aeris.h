//
//  NSCachedURLResponse+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 3/20/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSCachedURLResponse (Aeris)

/**
 *  Returns a new `NSCachedURLResponse` instance whose cached headers have been updated with the specified expiration time interval.
 *
 *  @param interval The time interval after which the request should be expired.
 *
 *  @return The new modified `NSCachedURLResponse` instance.
 */
- (NSCachedURLResponse *)awf_responseWithExpirationInterval:(NSTimeInterval)interval;

@end
