//
//  AWFShapeLayer.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 7/19/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFMapLayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Active severe weather advisories.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerWarnings;

/**
 Current and forecast convective outlooks.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerConvectiveOutlook;

/**
 Current Palmer drought index.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerDroughtIndex;

/**
 Current wildfire outlook.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFireOutlook;

NS_ASSUME_NONNULL_END
