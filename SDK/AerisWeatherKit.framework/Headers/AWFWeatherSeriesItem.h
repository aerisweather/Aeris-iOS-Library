//
//  AWFWeatherSeriesItem.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 12/8/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import <AerisWeatherKit/AWFWeatherEndpoint.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFWeatherSeriesItem` instance is a subclass of `AWFSeriesItem` that supports defining an `AWFWeatherEndpoint` to use when requesting weather data 
 needed for rendering this series item on a graph.
 @see AWFWeatherGraphSeries
 */
@interface AWFWeatherSeriesItem : AWFSeriesItem

/**
 The endpoint to use for loading the data needed for the series item.
 */
@property (nonatomic, strong) AWFWeatherEndpoint *endpoint;

@end

NS_ASSUME_NONNULL_END
