//
//  AWFIndexPeriod.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>
#import <AerisWeatherKit/AWFIndex.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFIndexPeriod` object represents data returned by the [**indices** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/indices/)
 of the Aeris Weather API.
 */
@interface AWFIndexPeriod : AWFGeographicObject

/**
 The current index item based on the latest observation for the location.
 */
@property (nonatomic, strong, nullable) AWFIndex *current;

/**
 An array of index items for periods in the future. This value will be `nil` by default. In order to obtain forecast indices, you must provide a
 `toDate` with your request options.
 */
@property (nonatomic, strong, nullable) NSArray<AWFIndex *> *forecast;

/**
 Minimum index value allowed for the index type.
 */
@property (nonatomic, assign) CGFloat rangeMin;

/**
 Maximum index value allowed for the index type.
 */
@property (nonatomic, assign) CGFloat rangeMax;

/**
 Index type this period pertains to.
 */
@property (nonatomic, assign, nullable) AWFIndexDataType type;

/**
 Whether or not the index range values are reversed.
 
 By default, the index range is not reversed meaning that the lowest index value corresponds to the lowest risk or severity. When the range is
 reversed, the lowest index value corresponds to the greatest risk or severity.
 */
@property (nonatomic, assign) BOOL isReverse;

@end

NS_ASSUME_NONNULL_END
