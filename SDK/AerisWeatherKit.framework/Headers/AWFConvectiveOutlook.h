//
//  AWFConvectiveOutlook.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/5/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

@class AWFGeoPolygon;

/**
 An `AWFConvectiveOutlook` object represents data returned by the [**convective/outlook** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/convective-outlook/)
 of the Aeris Weather API.
 */
@interface AWFConvectiveOutlook : AWFWeatherObject

/**
 Unique identifier for the outlook.
 */
@property (nonatomic, copy, nullable) NSString *outlookId;

/**
 Product type, normally "convective".
 */
@property (nonatomic, copy, nullable) NSString *product;

/**
 Outlook category type.
 */
@property (nonatomic, copy, nullable) NSString *category;

/**
 Coverage day for the outlook from 1-8.
 */
@property (nonatomic, assign) NSInteger dayIndex;

/**
 Abbreviated risk type.
 */
@property (nonatomic, copy, nullable) NSString *riskType;

/**
 Full risk name as provided by the Storm Prediction Center (SPC).
 */
@property (nonatomic, copy, nullable) NSString *riskName;

/**
 Risk code.
 */
@property (nonatomic, assign) NSInteger riskCode;

/**
 Starting date covered by the outlook.
 */
@property (nonatomic, strong, nullable) NSDate *startDate;

/**
 Ending date covered by the outlook.
 */
@property (nonatomic, strong, nullable) NSDate *endDate;

/**
 Date when the outlook was issued.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 An array of `AWFGeoPolygon` instances that define the coverage area(s) for the outlook. 
 
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
