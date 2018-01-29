//
//  NSCachedURLResponse+AerisCore.h
//  AerisCore
//
//  Created by Nicholas Shipes on 11/20/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSCachedURLResponse (AerisCore)

/**
 *  Returns a new `NSCachedURLResponse` instance whose cached headers have been updated with the specified expiration time interval.
 *
 *  @param interval The time interval after which the request should be expired.
 *
 *  @return The new modified `NSCachedURLResponse` instance.
 */
- (NSCachedURLResponse *)awf_responseWithExpirationInterval:(NSTimeInterval)interval;

@end
