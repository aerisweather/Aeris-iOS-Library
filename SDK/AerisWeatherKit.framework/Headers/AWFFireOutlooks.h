//
//  AWFFireOutlooks.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 1/25/17.
//  Copyright © 2017 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>
#import <AerisWeatherKit/AWFFireOutlook.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFFireOutlookFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterFireWeather;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterDryLightning;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterAll;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterElevated;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterCritical;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterExtreme;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterIsolatedDryStorms;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterScatteredDryStorms;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterDay1;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterDay2;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterDay3;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterDay4;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterDay5;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterDay6;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterDay7;
FOUNDATION_EXPORT AWFFireOutlookFilter const AWFFireOutlookFilterDay8;

typedef NSString * AWFFireOutlookField NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFFireOutlookField const AWFFireOutlookFieldId;
FOUNDATION_EXPORT AWFFireOutlookField const AWFFireOutlookFieldCategory;
FOUNDATION_EXPORT AWFFireOutlookField const AWFFireOutlookFieldDay;
FOUNDATION_EXPORT AWFFireOutlookField const AWFFireOutlookFieldRiskType;
FOUNDATION_EXPORT AWFFireOutlookField const AWFFireOutlookFieldRiskName;
FOUNDATION_EXPORT AWFFireOutlookField const AWFFireOutlookFieldRiskCode;
FOUNDATION_EXPORT AWFFireOutlookField const AWFFireOutlookFieldRangeStart;
FOUNDATION_EXPORT AWFFireOutlookField const AWFFireOutlookFieldRangeEnd;
FOUNDATION_EXPORT AWFFireOutlookField const AWFFireOutlookFieldTimestamp;

/**
 `AWFFireOutlooks` provides convenience methods for interacting with the
 [`fires/outlook` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/fires/outlook) of the Aeris API. All requests will
 return instances of `AWFFireOutlook` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFFireOutlooks : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END
