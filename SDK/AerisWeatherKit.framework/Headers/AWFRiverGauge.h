//
//  AWFRiverGauge.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 10/25/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>
#import <AerisWeatherKit/AWFRiver.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFRiverRecord;
@class AWFRiverImpact;

/**
 An `AWFRiverGauge` object represents data returned by the [**rivers/gauges** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/rivers-gauges/)
 of the Aeris Weather API.
 */
@interface AWFRiverGauge : AWFGeographicObject

/**
 The river gauge identifier.
 */
@property (nonatomic, copy) NSString *stationId;

/**
 The water body that the gauge measures.
 */
@property (nonatomic, copy) NSString *waterbody;

/**
 The different gauge flood categories and the levels.
 */
@property (nonatomic, strong) NSArray<AWFRiverCategory *> *categories;

/**
 The local flood impacts near the gauge.
 */
@property (nonatomic, strong) NSArray<AWFRiverImpact *> *impacts;

/**
 The historic flood crests for the gauge.
 */
@property (nonatomic, strong) NSArray<AWFRiverRecord *> *historicCrests;

/**
 The most recent flood crests for the gauge.
 */
@property (nonatomic, strong) NSArray<AWFRiverRecord *> *recentCrests;

/**
 The low water records for the gauge.
 */
@property (nonatomic, strong) NSArray<AWFRiverRecord *> *lowWaterRecords;

@end


/**
 An `AWFRiverRecord` object is a single record high or low event at a specific river gauge.
 */
@interface AWFRiverRecord : AWFWeatherObject

/**
 The GMT date that the record occurred.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 The water level height in feet when the record occurred.
 */
@property (nonatomic, assign) CGFloat heightFT;

/**
 The water level height in meters when the record occurred.
 */
@property (nonatomic, assign) CGFloat heightM;

@end


/**
 An `AWFRiverImpact` object contains information about the local impacts when a river reaches a particular water level.
 */
@interface AWFRiverImpact : AWFWeatherObject

/**
 The height in feet that the impact begins to occur.
 */
@property (nonatomic, assign) CGFloat heightFT;

/**
 The height in meters that the impact begins to occur.
 */
@property (nonatomic, assign) CGFloat heightM;

/**
 The description of the local impacts at this water level.
 */
@property (nonatomic, copy) NSString *text;

@end

NS_ASSUME_NONNULL_END
