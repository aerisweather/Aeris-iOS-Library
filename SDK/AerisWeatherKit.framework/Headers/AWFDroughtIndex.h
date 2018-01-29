//
//  AWFDrought.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/5/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

@class AWFGeoPolygon;

/**
 An `AWFDroughtIndex` object that represents data returned by the [**droughts/monitor** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/droughts-monitor/)
 of the Aeris Weather API.
 */
@interface AWFDroughtIndex : AWFWeatherObject

/**
 Unique identifier for the drought index.
 */
@property (nonatomic, copy, nullable) NSString *indexId;

/**
 Product type, normally "usdm".
 */
@property (nonatomic, copy, nullable) NSString *product;

/**
 Drought category type.
 */
@property (nonatomic, copy, nullable) NSString *category;

/**
 Abbreviated risk type indicating the drought severity level.
 */
@property (nonatomic, copy, nullable) NSString *riskType;

/**
 Full risk name for the drought severity level.
 */
@property (nonatomic, copy, nullable) NSString *riskName;

/**
 Risk code for the drought severity level.
 */
@property (nonatomic, assign) NSInteger riskCode;

/**
 Starting date covered by the drought index.
 */
@property (nonatomic, strong, nullable) NSDate *startDate;

/**
 Ending date covered by the drought index.
 */
@property (nonatomic, strong, nullable) NSDate *endDate;

/**
 Date when the drought index was issued.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 An array of `AWFGeoPolygon` instances that define the coverage area(s) for the drought index.
 
 In order to return polygons with your request, you must also include the `geo` filter with your request options. If this filter is not included and/or
 there is no associated risk with this outlook, then this value will be `nil`.
 */
@property (nonatomic, strong, nullable) NSArray<AWFGeoPolygon *> *polygons;

/**
 An array of `AWFGeoPolygon` instances that define the interior, or cutout, regions of the polygon(s), if any.
 
 Interior polygons are primarily used by mapping frameworks to determine where hallow areas should be rendered in the parent polygon.
 */
@property (nonatomic, strong, nullable) NSArray<AWFGeoPolygon *> *interiorPolygons;

@end
