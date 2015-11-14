//
//  AWFIndex.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>
#import <Aeris/AWFIndexPeriod.h>

@interface AWFIndex : AWFObject

/**
 *  The index type this item is associated with.
 */
@property (readonly, nonatomic) AWFIndexType indexType;

/**
 *  The date for the period.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  The index value for the period. Refer to the parent `AWFIndexPeriod` this index item belongs to for the available range this index value can be.
 *  @see AWFIndexPeriod
 */
@property (nonatomic, strong) NSNumber *index;

/**
 *  The generic string representation for the index value. This value can vary depending on the range of index values and whether or not the scale is
 *  reversed.
 */
@property (nonatomic, copy) NSString *indexString;

@end