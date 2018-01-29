//
//  AWFPointLayer.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 7/19/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFMapLayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Displays climate records on a weather map.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerRecords;

/**
 Displays river gauge conditions on a weather map.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerRivers;

/**
 Displays wildfires on a weather map.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFires;

/**
 Displays storm cells on a weather map.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerStormCells;

/**
 Displays storm reports on a weather map.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerStormReports;

/**
 Displays earthquakes on a weather map.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerEarthquakes;

/**
 Displays lightning strikes on a weather map.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerLightningStrikes;

NS_ASSUME_NONNULL_END
