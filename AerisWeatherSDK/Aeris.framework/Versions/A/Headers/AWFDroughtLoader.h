//
//  AWFDroughtLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/5/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFDroughtIndexFilterAll;
extern NSString * const AWFDroughtIndexFilterAbnormallyDry;
extern NSString * const AWFDroughtIndexFilterModerateDrought;
extern NSString * const AWFDroughtIndexFilterSevereDrought;
extern NSString * const AWFDroughtIndexFilterExtremeDrought;
extern NSString * const AWFDroughtIndexFilterExceptionalDrought;

extern NSString * const AWFDroughtIndexFieldId;
extern NSString * const AWFDroughtIndexFieldType;
extern NSString * const AWFDroughtIndexFieldName;
extern NSString * const AWFDroughtIndexFieldCode;

/**
 *  `AWFDroughtIndicesLoader` provides conveninece methods for interacting with the
 *  [`droughts` endpoint](http://www.aerisweather.com/support/docs/api/reference/endpoints/droughts/monitor) of the Aeris API. All requests will return
 *  instances of `AWFDroughtIndex` that will be populated with the data returned from the API unless otherwise indicated.
 */
@interface AWFDroughtIndicesLoader : AWFGeographicObjectLoader

@end