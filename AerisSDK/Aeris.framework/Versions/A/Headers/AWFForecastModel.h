//
//  AWFForecastModels.h
//  Aeris
//
//  Created by Nicholas Shipes on 12/2/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

/**
 *  The model types currently supported.
 */
typedef NS_ENUM(NSInteger, AWFForecastModelType) {
	/**
	 *  An invalid or unknown model type.
	 */
	AWFForecastModelTypeUnknown = 0,
	AWFForecastModelTypeAeris,
	/**
	 *  NDFD (National Digital Forecast Database) model.
	 */
	AWFForecastModelTypeNDFD,
	/**
	 *  HRRR (High Resolution Rapid Refresh) model.
	 */
	AWFForecastModelTypeHRRR,
	/**
	 *  HRRR (High Resolution Rapid Refresh) sub-hourly model.
	 */
	AWFForecastModelTypeHRRRSub,
	
	/**
	 *  NAM (North Americal Mesoscale) model at a 4km resolution.
	 */
	AWFForecastModelTypeNAM4K,
	/**
	 *  NAM (North Americal Mesoscale) model at a 12km resolution.
	 */
	AWFForecastModelTypeNAM12K,
	/**
	 *  GFS (Global Forecast System) model.
	 */
	AWFForecastModelTypeGFS,
	AWFForecastModelTypeGFSMOS,
	AWFForecastModelTypeGEFS
};

@interface AWFForecastModel : NSObject

//-----------------------------------------------------------------------------
// @name Class Methods
//-----------------------------------------------------------------------------

/**
 *  Returns a dictionary that maps each {@link AWFForecastModel} to its corresponding data code.
 */
+ (NSDictionary *)typeMapping;

/**
 *  Returns a dictionary that maps each {@link AWFForecastModel} to its display name.
 */
+ (NSDictionary *)names;

/**
 *  Returns the time interval between periods covered by a model type.
 *
 *  @param model The model type to return the time interval for
 *
 *  @return The time interval between periods for the model
 */
+ (NSTimeInterval)intervalForForecastModelType:(AWFForecastModelType)model;

/**
 *  Returns the maximum time covered by a model type.
 *
 *  @param model The model type to return the maximum time for
 *
 *  @return The maximum time supported by the model
 */
+ (NSTimeInterval)maxTimeRangeForForecastModelType:(AWFForecastModelType)model;

@end