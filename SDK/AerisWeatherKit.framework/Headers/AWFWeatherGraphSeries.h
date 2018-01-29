//
//  AWFWeatherGraphSeries.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 12/8/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFBatchRequest.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFWeatherSeriesItem;

/**
 `AWFWeatherGraphSeries` is a subclass of `AWFGraphSeries` that provides additional functionality for generating graphs based on requested weather
 data from the API. Instances of `AWFWeatherGraphSeries` must provide one or more `AWFWeatherSeriesItem` objects to use for representing a data 
 element on the graph.
 @see AWFWeatherSeriesItem
 */
@interface AWFWeatherGraphSeries : AWFGraphSeries

/**
 An array of series items belonging to this series.
 */
@property (nonatomic, readonly, nullable) NSArray<AWFWeatherSeriesItem *> *items;

/**
 The default request options to be used when requesting data for the series and is applied to each individual series item unless that item overrides
 the corresponding value. The default is `nil`.
 */
@property (nonatomic, strong, nullable) AWFBatchRequestOptions *dataRequestOptions;

/**
 The time zone to use when formatting graph labels and tooltips for the axis. Defaults to use the system's current time zone.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

/**
 Assigns the endpoint for all series items containied within the series to the specified endpoint.
 
 @param endpoint The endpoint to use for all series items
 */
- (void)setEndpointForAllSeriesItems:(AWFWeatherEndpoint *)endpoint;

/**
 Assigns the place option to use for all endpoints in the series items.
 
 @param place The place to use for all series items
 */
- (void)setPlaceForAllSeriesItemEndpoints:(AWFPlace *)place;

@end

NS_ASSUME_NONNULL_END
