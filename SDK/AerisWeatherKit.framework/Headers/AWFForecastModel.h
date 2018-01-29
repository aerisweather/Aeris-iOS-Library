//
//  AWFForecastModels.h
//  Aeris
//
//  Created by Nicholas Shipes on 12/2/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFForecastModelType NS_TYPED_ENUM;

FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeNone;

/**
 The default model type.
 */
FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeAeris;

/**
 NDFD (National Digital Forecast Database) model.
 */
FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeNDFD;

/**
 HRRR (High Resolution Rapid Refresh) model.
 */
FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeHRRR;

/**
 HRRR (High Resolution Rapid Refresh) sub-hourly model.
 */
FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeHRRRSub;

/**
 NAM (North Americal Mesoscale) model.
 */
FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeNAM;

/**
 NAM (North Americal Mesoscale) model at a 4km resolution.
 */
FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeNAM4K;

/**
 NAM (North Americal Mesoscale) model at a 12km resolution.
 */
FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeNAM12K;

/**
 GFS (Global Forecast System) model.
 */
FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeGFS;
FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeGFSMOS;
FOUNDATION_EXPORT AWFForecastModelType const AWFForecastModelTypeGEFS;


/**
 `AWFForecastModel` is a static class that contains information about the supported forecast models used throughout the library. 
 */
@interface AWFForecastModel : NSObject

//-----------------------------------------------------------------------------
// @name Class Methods
//-----------------------------------------------------------------------------

/**
 Returns a dictionary that maps each {@link AWFForecastModel} to its display name.
 */
+ (NSDictionary<AWFForecastModelType, NSString *> *)names;

/**
 Returns the time interval between periods covered by a model type.
 
 @param model The model type to return the time interval for
 @return The time interval between periods for the model
 */
+ (NSTimeInterval)intervalForForecastModelType:(AWFForecastModelType)model;

/**
 Returns the maximum time covered by a model type.
 
 @param model The model type to return the maximum time for
 @return The maximum time supported by the model
 */
+ (NSTimeInterval)maxTimeRangeForForecastModelType:(AWFForecastModelType)model;

@end

NS_ASSUME_NONNULL_END
