//
//  AWFLayerType.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

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
	 *  Black and white visible satellite tile overlay.
	 */
	AWFLayerTypeSatelliteVisible,
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
	/**
	 *  Estimated snow depth tile overlay.
	 */
	AWFLayerTypeSnowDepth,
	/**
	 *  Current surface temperatures tile overlay.
	 */
	AWFLayerTypeCurrentTemperatures,
	/**
	 *  Current surface wind speeds tile overlay.
	 */
	AWFLayerTypeCurrentWinds,
	/**
	 *  Current surface dew points tile overlay.
	 */
	AWFLayerTypeCurrentDewPoint,
	/**
	 *  Current surface relative humidity tile overlay.
	 */
	AWFLayerTypeCurrentHumidity,
	/**
	 *  Current surface wind chill tile overlay.
	 */
	AWFLayerTypeCurrentWindChill,
	/**
	 *  Current surface heat index tile overlay.
	 */
	AWFLayerTypeCurrentHeatIndex,
	/**
	 *  Current oceanic chlorophyll tile overlay.
	 */
	AWFLayerTypeCurrentChlorophyll,
	/**
	 *  Current sea surface temperatures tile overlay.
	 */
	AWFLayerTypeCurrentSeaSurfaceTemperatures,
	
	AWFLayerTypeFutureRadarNAM,
	AWFLayerTypeFutureRadarRAP,
	AWFLayerTypeFutureRadarHRRR,
	AWFLayerTypeFutureCloudsHRRR,
	AWFLayerTypeFuturePrecipHRRR,
	AWFLayerTypeFutureWindsHRRR,
	
	/**
	 *  Tile overlay combining radar and infrared satellite.
	 */
	AWFLayerTypeRadarSatellite,
	/**
	 *  Tile overlay combining radar and weather advisories.
	 */
	AWFLayerTypeRadarAdvisory,
	
	AWFLayerTypeFutureRadarCloudsHRRR,
	
	
	/**
	 *  Overlay displaying short-fuse warning polygons (tornado, severe thunderstorm, flash flood, etc).
	 */
	AWFLayerTypeWarning,
	
	
	/**
	 *
	 */
	AWFLayerTypeObservation,
	/**
	 *
	 */
	AWFLayerTypeRiver,
	/**
	 *
	 */
	AWFLayerTypeTide,
	/**
	 *
	 */
	AWFLayerTypeBuoy,
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
