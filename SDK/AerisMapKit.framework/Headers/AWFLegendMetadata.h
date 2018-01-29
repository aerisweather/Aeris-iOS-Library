//
//  AWFLegendMetadata.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 7/14/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFMapLayer.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFLegendCode NS_TYPED_EXTENSIBLE_ENUM;

extern AWFLegendCode const AWFLegendCode1HourPrecip;
extern AWFLegendCode const AWFLegendCode1HourRain;
extern AWFLegendCode const AWFLegendCodeAccumulatedPrecipDeparturePercent;
extern AWFLegendCode const AWFLegendCodeAccumulatedPrecipDeparture;
extern AWFLegendCode const AWFLegendCodeAccumulatedPrecipDepartureYear;
extern AWFLegendCode const AWFLegendCodeAccumulatedPrecip;
extern AWFLegendCode const AWFLegendCodeAccumulatedPrecip180Day;
extern AWFLegendCode const AWFLegendCodeAccumulatedPrecipYear;
extern AWFLegendCode const AWFLegendCodeAdvisories;
extern AWFLegendCode const AWFLegendCodeAirQualityIndex;
extern AWFLegendCode const AWFLegendCodeChlorophyll;
extern AWFLegendCode const AWFLegendCodeConvectiveOutlook;
extern AWFLegendCode const AWFLegendCodeConvectiveHail;
extern AWFLegendCode const AWFLegendCodeConvectiveTornadic;
extern AWFLegendCode const AWFLegendCodeConvectiveWind;
extern AWFLegendCode const AWFLegendCodeDewPoints;
extern AWFLegendCode const AWFLegendCodeDroughtMonitor;
extern AWFLegendCode const AWFLegendCodeFireOutlook;
extern AWFLegendCode const AWFLegendCodeFuturePrecip;
extern AWFLegendCode const AWFLegendCodeFutureSnow;
extern AWFLegendCode const AWFLegendCodeHeatIndex;
extern AWFLegendCode const AWFLegendCodeHeatIndexDeparture;
extern AWFLegendCode const AWFLegendCodeHumidity;
extern AWFLegendCode const AWFLegendCodeJetStream;
extern AWFLegendCode const AWFLegendCodeLightningStrikeDensity;
extern AWFLegendCode const AWFLegendCodePOP;
extern AWFLegendCode const AWFLegendCodePrecipOutlook;
extern AWFLegendCode const AWFLegendCodePressure;
extern AWFLegendCode const AWFLegendCodeRadar;
extern AWFLegendCode const AWFLegendCodeRadarIce;
extern AWFLegendCode const AWFLegendCodeRadarRain;
extern AWFLegendCode const AWFLegendCodeRadarSnow;
extern AWFLegendCode const AWFLegendCodeRivers;
extern AWFLegendCode const AWFLegendCodeRoadConditions;
extern AWFLegendCode const AWFLegendCodeRoadConditionsIndex;
extern AWFLegendCode const AWFLegendCodeSatelliteInfrared;
extern AWFLegendCode const AWFLegendCodeSatelliteWaterVapor;
extern AWFLegendCode const AWFLegendCodeSnowDepth;
extern AWFLegendCode const AWFLegendCodeStormCells;
extern AWFLegendCode const AWFLegendCodeStormReports;
extern AWFLegendCode const AWFLegendCodeTempOutlook;
extern AWFLegendCode const AWFLegendCodeTemperatures;
extern AWFLegendCode const AWFLegendCodeTropical;
extern AWFLegendCode const AWFLegendCodeTropicalOutlook;
extern AWFLegendCode const AWFLegendCodeVisibility;
extern AWFLegendCode const AWFLegendCodeWaveHeights;
extern AWFLegendCode const AWFLegendCodeWindChill;
extern AWFLegendCode const AWFLegendCodeWinds;

extern NSString * const AWFLegendMetadataLoaded;

@class AWFLegendConfig;
@class AWFLegendStyle;

/**
 An `AWFLegendMetadata` object is responsible for requesting legend metadata from the Aeris API and setting up and maintaining the necessary legend
 configuration instances for the legends currently supported.
 */
@interface AWFLegendMetadata : NSObject

/**
 The cached legend configurations keyed by identifier. The identifier will be a `AWFLegendCode` string value.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary<NSString *, AWFLegendConfig *> *config;

/**
 A Boolean value indicating whether the required legend metadata has been loaded and configuration objects instantiated.
 */
@property (nonatomic, readonly) BOOL hasLoaded;

/**
 Tells the object to request the legend metadata from the Aeris API and setup the legend configuration instances.

 @param completionBlock The block to execute once all legend configuration instances have been setup.
 */
- (void)getWithCompletion:(void (^)())completionBlock;

/**
 Returns the legend configuration instance associated with the specified key.

 @param key The key to return the configuration for.
 */
- (nullable AWFLegendConfig *)configForKey:(NSString *)key;

/**
 Returns the legend configuration instance associated with the specified layer type.

 @param code The layer type to return the configuration for.
 */
- (nullable AWFLegendConfig *)configForLayerType:(AWFMapLayer)code;

/**
 Returns the default legend style associated with the specified layer type.

 @param code The layer type to return the style for.
 */
- (nullable AWFLegendStyle *)styleForLayerType:(AWFMapLayer)code;

/**
 Returns the title for the legend associated with the specified legend key.

 @param key The legend key to return a title for.
 */
- (nullable NSString *)titleForKey:(NSString *)key;

/**
 The singleton instance.
 */
+ (instancetype)sharedInstance;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
