//
//  AWFLayerType.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Options for weather layer types.
 */
typedef NS_ENUM(NSUInteger, AWFLayerType) {
	/**
	 *  The option indicating no layer type.
	 */
	AWFLayerTypeNone = 0,
	
	/**
	 *  Radar tile overlay.
	 */
	AWFLayerTypeRadar,
	
	/**
	 *  NEXRAD radar overlay (NIDs).
	 */
	AWFLayerTypeNexradRadar,
	/**
	 *  Black and white infrared satellite tile overlay.
	 */
	AWFLayerTypeSatellite,

	/**
	 *  High-resolution black and white visible satellite tile overlay.
	 */
	AWFLayerTypeSatelliteVisibleHiRes,
	/**
	 *  Global infrared satellite tile overlay.
	 */
	AWFLayerTypeSatelliteGlobal,
	/**
	 *  Weather advisories and alerts tile overlay.
	 */
	AWFLayerTypeAdvisory,
	
	AWFLayerTypeLightningStrikeDensity,
	
	/**
	 *  Estimated snow depth tile overlay.
	 */
	AWFLayerTypeSnowDepth,
	AWFLayerTypeSnowDepthGlobal,
	
	AWFLayerTypeQpf,
	/**
	 *  Current surface temperatures tile overlay.
	 */
	AWFLayerTypeTemperature,
	/**
	 *  Current surface wind speeds tile overlay.
	 */
	AWFLayerTypeWind,
	/**
	 *  Current surface dew points tile overlay.
	 */
	AWFLayerTypeDewPoint,
	/**
	 *  Current surface relative humidity tile overlay.
	 */
	AWFLayerTypeHumidity,
	/**
	 *  Current surface wind chill tile overlay.
	 */
	AWFLayerTypeWindChill,
	/**
	 *  Current surface heat index tile overlay.
	 */
	AWFLayerTypeHeatIndex,
	
	AWFLayerType1HourPrecip,
	
	/**
	 *  Current oceanic chlorophyll tile overlay.
	 */
	AWFLayerTypeCurrentChlorophyll,
	/**
	 *  Current sea surface temperatures tile overlay.
	 */
	AWFLayerTypeCurrentSeaSurfaceTemperature,
	
	AWFLayerTypeRoadCondition,
	
	AWFLayerTypeFutureRadarHRRR,
	AWFLayerTypeFutureRadarNAM4K,
	AWFLayerTypeFutureRadarNAM12K,
	AWFLayerTypeFutureCloudsNAM4K,
	AWFLayerTypeFuturePrecip,
	AWFLayerTypeFuturePrecipNAM4K,
	AWFLayerTypeFuturePrecipNAM12K,
	AWFLayerTypeFutureRain,
	AWFLayerTypeFutureRainHRRR,
	AWFLayerTypeFutureRainNAM4K,
	AWFLayerTypeFutureRainNAM12K,
	AWFLayerTypeFutureRainGFS,
	AWFLayerTypeFutureSnow,
	AWFLayerTypeFutureSnowNAM4K,
	AWFLayerTypeFutureSnowNAM12K,
	AWFLayerTypeFutureSnowGFS,
	AWFLayerTypeFutureWindsHRRR,
	AWFLayerTypeFutureWindsNAM4K,
	AWFLayerTypeFutureWindsNAM12K,
	AWFLayerTypeFutureTemperaturesHRRR,
	AWFLayerTypeFutureTemperaturesNAM4K,
	AWFLayerTypeFutureTemperaturesNAM12K,
	AWFLayerTypeFutureTemperaturesGFS,
	AWFLayerTypeFutureRoadCondition,
	AWFLayerTypeFutureRoadConditionIndex,
	
	/**
	 *  Overlay displaying short-fuse warning polygons (tornado, severe thunderstorm, flash flood, etc).
	 */
	AWFLayerTypeWarning,
	
	/**
	 *  Overlay displaying daily convective outlook polygons for the supported risk levels.
	 */
	AWFLayerTypeConvectiveOutlook,
	
	/**
	 *  Overlay displaying daily fire weather outlook polygons.
	 */
	AWFLayerTypeFireOutlook,
	
	/**
	 *  Overlay displaying daily drought index polygons for the supported drought severities.
	 */
	AWFLayerTypeDroughtIndex,
	
	
	/**
	 *
	 */
	AWFLayerTypeObservation,

	/**
	 *  Overlay displaying storm cell data, including current and forecast positions.
	 */
	AWFLayerTypeStormCell,
	/**
	 *  Overlay displaying observed storm reports of various types.
	 */
	AWFLayerTypeStormReport,
	/**
	 *  Overlay displaying position of wildfires.
	 */
	AWFLayerTypeFire,
	/**
	 *  Overlay displaying location, age and/or amperage of lightning strikes.
	 */
	AWFLayerTypeLightningStrike,
	/**
	 *  Overlay displaying temperature and precipitation climate records.
	 */
	AWFLayerTypeRecord,
	/**
	 *  Overlay displaying position and intensity of earthquakes.
	 */
	AWFLayerTypeEarthquake
};
