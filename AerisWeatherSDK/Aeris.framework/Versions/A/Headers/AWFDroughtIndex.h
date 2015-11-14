//
//  AWFDrought.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/5/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

@interface AWFDroughtIndex : AWFObject

/**
 *  Unique identifier for the drought index.
 */
@property (copy, nonatomic) NSString *indexId;

/**
 *  Product type, normally "usdm".
 */
@property (copy, nonatomic) NSString *product;

/**
 *  Drought category type.
 */
@property (copy, nonatomic) NSString *category;

/**
 *  Abbreviated risk type indicating the drought severity level.
 */
@property (copy, nonatomic) NSString *riskType;

/**
 *  Full risk name for the drought severity level.
 */
@property (copy, nonatomic) NSString *riskName;

/**
 *  Risk code for the drought severity level.
 */
@property (strong, nonatomic) NSNumber *riskCode;

/**
 *  Starting date covered by the drought index.
 */
@property (strong, nonatomic) NSDate *startDate;

/**
 *  Ending date covered by the drought index.
 */
@property (strong, nonatomic) NSDate *endDate;

/**
 *  Date when the drought index was issued.
 */
@property (strong, nonatomic) NSDate *timestamp;

/**
 *  An array of `AWFGeoPolygon` instances that define the coverage area(s) for the drought index.
 *
 *  In order to return polygons with your request, you must also include the `geo` filter with your request options. If this filter is not included and/or
 *  there is no associated risk with this outlook, then this value will be `nil`.
 */
@property (strong, nonatomic) NSArray *polygons;

/**
 *  An array of `AWFGeoPolygon` instances that define the interior, or cutout, regions of the polygon(s), if any.
 *
 *  Interior polygons are primarily used by mapping frameworks to determine where hallow areas should be rendered in the parent polygon.
 */
@property (strong, nonatomic) NSArray *interiorPolygons;

@end
