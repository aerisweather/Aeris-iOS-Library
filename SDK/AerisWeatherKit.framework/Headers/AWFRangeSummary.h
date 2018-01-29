//
//  AWFDataRange.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/3/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFRangeSummary` object represents a summary of data for a specific range, including the minimum, maximum and average of all values within the
 range.
 */
@interface AWFRangeSummary : AWFWeatherObject

/**
 Number of records used for the range.
 */
@property (nonatomic, assign) NSInteger count;

/**
 Minimum value for the range.
 */
@property (nonatomic, assign) CGFloat min;

/**
 Maximum value for the range.
 */
@property (nonatomic, assign) CGFloat max;

/**
 Average of all values for the range.
 */
@property (nonatomic, assign) CGFloat average;

@end

NS_ASSUME_NONNULL_END
