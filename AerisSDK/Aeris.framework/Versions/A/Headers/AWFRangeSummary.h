//
//  AWFDataRange.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/3/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

@interface AWFRangeSummary : AWFObject

/**
 *  Number of records used for the range.
 */
@property (strong, nonatomic) NSNumber *count;

/**
 *  Minimum value for the range.
 */
@property (strong, nonatomic) NSNumber *min;

/**
 *  Maximum value for the range.
 */
@property (strong, nonatomic) NSNumber *max;

/**
 *  Average of all values for the range.
 */
@property (strong, nonatomic) NSNumber *average;

@end
