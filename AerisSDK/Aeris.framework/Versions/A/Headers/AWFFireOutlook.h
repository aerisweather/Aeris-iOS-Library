//
//  AWFFireOutlook.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/4/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

@interface AWFFireOutlook : AWFObject

/**
 *  Unique identifier for the outlook.
 */
@property (copy, nonatomic) NSString *outlookId;

/**
 *  Product type, normally `firewx`.
 */
@property (copy, nonatomic) NSString *product;

/**
 *  Outlook category type.
 */
@property (copy, nonatomic) NSString *category;

/**
 *  Coverage day for the outlook from 1-8.
 */
@property (strong, nonatomic) NSNumber *dayIndex;

/**
 *  Abbreviated risk type.
 */
@property (copy, nonatomic) NSString *riskType;

/**
 *  Full risk name.
 */
@property (copy, nonatomic) NSString *riskName;

/**
 *  Risk code.
 */
@property (strong, nonatomic) NSNumber *riskCode;

/**
 *  Starting date covered by the outlook.
 */
@property (strong, nonatomic) NSDate *startDate;

/**
 *  Ending date covered by the outlook.
 */
@property (strong, nonatomic) NSDate *endDate;

/**
 *  Date when the outlook was issued.
 */
@property (strong, nonatomic) NSDate *timestamp;

/**
 *  An array of `AWFGeoPolygon` instances that define the coverage area(s) for the outlook.
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
