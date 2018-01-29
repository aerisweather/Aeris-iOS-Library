//
//  AWFRasterMask.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 11/2/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `AWFRasterMask` type defines the supported masks that can be applied to a raster map layer.
 
 @note When using Swift, reference these values as their enumerated types instead of the Objective-C constants:
 `let mask = AWFRasterMask.waterFlat`
 */
typedef NSString *AWFRasterMask NS_TYPED_ENUM;

FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskNone;

/**
 Removes data over land regions by overlaying a land raster image using the flat map style.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskLandFlat;

/**
 Removes data over land regions by overlaying a land raster image using the Blue Marble map style.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskLandBlueMarble;

/**
 Removes data over land regions by overlaying a land raster image using the terrain map style.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskLandTerrain;

/**
 Removes data over water regions by overlaying a water raster image using the flat map style.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskWaterFlat;

/**
 Removes data over water regions by overlaying a water raster image using the water depth style.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskWaterDepth;

/**
 Removes data over the Continental US by overlaying a land raster image using the flat map style.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskLandUSFlat;

/**
 Removes all data except for the Continental US by overlaying a land and water raster image using the flat map style.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskClipUSFlat;

/**
 Removes all data except for the Continental US by overlaying a land and water raster image using the Blue Marble map style.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskClipUSBlueMarble;

/**
 Removes all data except for the Continental US by overlaying a land and water raster image using the terrain map style.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskClipUSTerrain;

/**
 Removes all data over water regions by using an alpha blend method to clip data from the layer not over land. The resulting image will retain its
 transparency.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskRemoveWater;

/**
 Removes all data over land regions by using an alpha blend method to clip data from the layer not over water. The resulting image will retain its
 transparency.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskRemoveLand;

/**
 Removes all data not within the Continental US by using an alpha blend method to clip data from the layer outside of the Continental US. The resulting
 image will retain its transprency.
 */
FOUNDATION_EXPORT AWFRasterMask const AWFRasterMaskRemoveLandNonUS;

NS_ASSUME_NONNULL_END
