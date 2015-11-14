//
//  NSObject+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 5/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Provides extensions to `NSObject` or performing common tasks.
 */
@interface NSObject (Aeris)

/**
 *  Performs a block after the specified delay.
 *
 *  @param block The block to execute.
 *  @param delay The time interval in seconds to wait before executing the block.
 *
 *  @return A reference to the block's wrapper for the process, which can be used to cancel with `awf_cancelBlock:`.
 */
+ (id)awf_performBlock:(dispatch_block_t)block afterDelay:(NSTimeInterval)delay;

/**
 *  Cancels a block that was scheduled to run using `awf_performBlock:afterDelay:`.
 *
 *  @param block The block wrapper's reference to cancel.
 */
+ (void)awf_cancelBlock:(id)block;

/**
 *  Executes a block on the main thread.
 *
 *  This is a convenience method for `dispatch_sync(dispatch_get_main_queue(), block);`.
 *
 *  @param block The block to execute on the main thread.
 */
+ (void)awf_performBlockOnMainThread:(dispatch_block_t)block;

/**
 *  Executes a block on a background thread.
 *
 *  This is a convenience method for `dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), block);`.
 *
 *  @param block The block to execute on a background thread.
 */
+ (void)awf_performBlockInBackground:(dispatch_block_t)block;

/**
 *  Returns a description of the object including its class name and a list of its properties (name = value).
 */
- (NSString *)awf_autoDescription;

@end
