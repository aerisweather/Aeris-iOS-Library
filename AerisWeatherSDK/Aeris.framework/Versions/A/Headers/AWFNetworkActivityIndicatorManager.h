//
//  AWFNetworkActivityIndicatorManager.h
//  Aeris
//
//  Created by Nicholas Shipes on 5/1/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  `AWFNetworkActivityIndicatorManager` is a simple interface around AFNetworking's `AFNetworkActivityIndicatorManager` to mange the state
 *  of the activity indicator in the status bar.
 */
@interface AWFNetworkActivityIndicatorManager : NSObject

/**
 *  Returns the shared network activity indicator manager object for the system.
 *
 *  @return The systemwide network activity indicator manager.
 */
+ (instancetype)sharedManager;

/**
 *  Increments the number of active network requests. If this number was zero before incrementing, this will start animating the status bar
 *  network activity indicator.
 */
- (void)incrementActivityCount;

/**
 *  Decrements the number of active network requests. If this number becomes zero after decrementing, this will stop animating the status
 *  bar network activity indicator.
 */
- (void)decrementActivityCount;

@end