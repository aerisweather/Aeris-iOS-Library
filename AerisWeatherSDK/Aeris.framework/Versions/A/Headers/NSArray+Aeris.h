//
//  NSArray+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Provides extensions to `NSArray` for performing common tasks.
 */
@interface NSArray (Aeris)

/**
 *  Returns a reversed version of an array.
 *
 *  @return The reveresed version of the array.
 */
- (NSArray *)awf_reversedArray;

/**
 *  Returns a new array that has been reduced down to a specific property or key of each item within the provided array.
 *
 *  @param block The block that performs the mapping. The mapped object that should be inserted into the final array should be returned from
 *		this block.
 *
 *  @return The reduced array according to the mapping.
 */
- (NSArray *)awf_mapObjectsUsingBlock:(id (^)(id obj, NSUInteger idx))block;

/**
 *  Returns a new array that is filtered according to a specific property or key value.
 *
 *  @param block The block that performs the filter's boolean operation. This block should return a boolean value, where `YES` indicates the
 *		value should be inserted into the resulting array.
 *
 *  @return The filtered array.
 */
- (NSArray *)awf_filterObjectsUsingBlock:(BOOL (^)(id obj, NSUInteger idx))block;

@end


@interface NSMutableArray (Aeris)

/**
 *  Reverses the items in the array.
 */
- (void)awf_reverse;

@end