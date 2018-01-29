//
//  AWFDroughtLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/5/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFDroughtIndex.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFDroughtIndexFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFDroughtIndexFilter const AWFDroughtIndexFilterAll;
FOUNDATION_EXPORT AWFDroughtIndexFilter const AWFDroughtIndexFilterAbnormallyDry;
FOUNDATION_EXPORT AWFDroughtIndexFilter const AWFDroughtIndexFilterModerateDrought;
FOUNDATION_EXPORT AWFDroughtIndexFilter const AWFDroughtIndexFilterSevereDrought;
FOUNDATION_EXPORT AWFDroughtIndexFilter const AWFDroughtIndexFilterExtremeDrought;
FOUNDATION_EXPORT AWFDroughtIndexFilter const AWFDroughtIndexFilterExceptionalDrought;

typedef NSString * AWFDroughtIndexField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFDroughtIndexField const AWFDroughtIndexFieldId;
FOUNDATION_EXPORT AWFDroughtIndexField const AWFDroughtIndexFieldType;
FOUNDATION_EXPORT AWFDroughtIndexField const AWFDroughtIndexFieldName;
FOUNDATION_EXPORT AWFDroughtIndexField const AWFDroughtIndexFieldCode;

/**
 `AWFDroughtIndices` provides conveninece methods for interacting with the
 [`droughts` endpoint](http://www.aerisweather.com/support/docs/api/reference/endpoints/droughts/monitor) of the Aeris API. All requests will return
 instances of `AWFDroughtIndex` that will be populated with the data returned from the API unless otherwise indicated.
 */
@interface AWFDroughtIndices : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
