//
//  AWFMapContentType.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 2/13/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

/**
 The supported map content types for a weather map.

 - AWFMapContentTypeRaster: Map content type consisting of raster imagery.
 - AWFMapContentTypeTile: Map content type consisting of raster tile imagery.
 - AWFMapContentTypePoint: Map content type consisting of point data (annotations).
 - AWFMapContentTypeShape: Map content type consisting of shapes (polylines and polygons).
 - AWFMapContentTypeLabel: Map content type consisting of text labels.
 */
typedef NS_ENUM(NSUInteger, AWFMapContentType) {
	AWFMapContentTypeRaster = 0,
	AWFMapContentTypeTile,
	AWFMapContentTypePoint,
	AWFMapContentTypeShape,
	AWFMapContentTypeLabel
};
