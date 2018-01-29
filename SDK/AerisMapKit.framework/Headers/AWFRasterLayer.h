//
//  AWFMapLayer.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 7/19/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFMapLayer.h>

NS_ASSUME_NONNULL_BEGIN

//-----------------------------------------------------------------------------
// @name Radar & Satellite
//-----------------------------------------------------------------------------

/**
 Current and past preciptiation-type radar.
 
 Use `AWFMapLayerFutureRadar` for the future/forecast layer associated with this type.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerRadar;

/**
 High-resolution current and past preciptiation-type radar.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerRadar2m;

/**
 Black and white visible satellite. This layer uses a non-transparent black background.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteVisible;

/**
 Black and white infrared satellite.
 
 Use `AWFMapLayerFutureSatellite` for the future/forecast layer associated with this type.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatellite;

/**
 Color-enhanced infrared satellite for the Continental US region.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteInfraredColorUS;

/**
 Color-enhanced infrared satellite.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteInfraredColor;

/**
 Color-enhanced water vapor satellite.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteWaterVapor;

/**
 Global black and white infrared satellite.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteGlobal;

/**
 Black and white visible satellite.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteVisibleTransparent;

//-----------------------------------------------------------------------------
// @name Forecasts
//-----------------------------------------------------------------------------

FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureRadar;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSatellite;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureTemperatures;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFuturePrecip;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFuturePrecipIntervals;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureDewPoints;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureHumidity;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureWindSpeeds;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureJetStream;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureWindGusts;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureFeelsLike;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureHeatIndex;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureWindChill;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSnow;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureTemperaturesMax;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureTemperaturesMin;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureVisibility;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureRoadConditions;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureRoadConditionsMidterm;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureRoadConditionsIndex;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureRoadConditionsIndexMidterm;

//-----------------------------------------------------------------------------
// @name Severe Weather
//-----------------------------------------------------------------------------

FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerLightningStrikeDensity;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropical;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerAdvisories;

//-----------------------------------------------------------------------------
// @name Observations
//-----------------------------------------------------------------------------

FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTemperatures;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerDewPoints;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerHumidity;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerWindSpeeds;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerWindDirection;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerWindGusts;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerWindChill;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerHeatIndex;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFeelsLike;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip1Hour;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip1Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip7Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip14Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip30Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip60Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip90Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip180Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipMTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipYTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipWYTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals1Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals7Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals14Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals30Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals60Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals90Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals180Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormalsMTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormalsYTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormalsWYTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart1Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart7Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart14Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart30Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart60Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart90Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart180Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartMTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartYTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartWYTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent1Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent7Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent14Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent30Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent60Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent90Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent180Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercentMTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercentYTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercentWYTD;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerCloudCover;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSnowDepth;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSnowDepthGlobal;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerVisibility;

//-----------------------------------------------------------------------------
// @name Outlooks
//-----------------------------------------------------------------------------

FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFiresDryLightningOutlook;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTempOutlook6To10Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipOutlook6To10Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTempOutlook8To14Day;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipOutlook8To14Day;

//-----------------------------------------------------------------------------
// @name Ocean Data
//-----------------------------------------------------------------------------

FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerChlorophyll;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSeaSurfaceTemps;

//-----------------------------------------------------------------------------
// @name Road Conditions
//-----------------------------------------------------------------------------

FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerRoadConditions;

//-----------------------------------------------------------------------------
// @name Base Map
//-----------------------------------------------------------------------------

FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerBaseFlat;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerBaseBlueMarble;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerBaseTerrain;

//-----------------------------------------------------------------------------
// @name Overlays
//-----------------------------------------------------------------------------

FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayAdmin;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayAdminCities;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayStatesOutlines;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayStates;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayCounties;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayInterstates;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayRoads;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayRivers;

//-----------------------------------------------------------------------------
// @name Layer Masks
//-----------------------------------------------------------------------------

FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskLandFlat;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskLandBlueMarble;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskLandTerrain;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskWaterFlat;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskWaterDepth;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskLandUSFlat;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskClipUSFlat;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskClipUSBlueMarble;
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskClipUSTerrain;

FOUNDATION_EXPORT NSString const *AWFFutureLayerPrefix;

NS_ASSUME_NONNULL_END
