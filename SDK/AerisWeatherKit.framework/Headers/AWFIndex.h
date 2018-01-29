//
//  AWFIndex.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>
#import <AerisWeatherKit/AWFIndices.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFIndex` object represents data for a single index value returned by the [**indices** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/indices/)
 of the Aeris Weather API.
 */
@interface AWFIndex : AWFWeatherObject

/**
 The index type this item is associated with.
 */
@property (nonatomic, assign, nullable) AWFIndexDataType type;

/**
 The date for the period.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 The index value for the period. Refer to the `AWFIndexPeriod` instance this index item belongs to for the available range this index value can be.
 @see AWFIndexPeriod
 */
@property (nonatomic, assign) NSInteger index;

/**
 The generic string representation for the index value. This value can vary depending on the range of index values and whether or not the scale is
 reversed.
 */
@property (nonatomic, copy, nullable) NSString *indexString;

@end

NS_ASSUME_NONNULL_END
