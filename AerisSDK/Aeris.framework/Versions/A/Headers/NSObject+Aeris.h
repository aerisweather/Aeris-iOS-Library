//
//  NSObject+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 5/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Aeris)

+ (id)awf_performBlock:(dispatch_block_t)block afterDelay:(NSTimeInterval)delay;
+ (void)awf_cancelBlock:(id)block;
+ (void)awf_performBlockOnMainThread:(dispatch_block_t)block;
+ (void)awf_performBlockInBackground:(dispatch_block_t)block;

@end
