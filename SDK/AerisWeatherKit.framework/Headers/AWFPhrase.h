//
//  AWFPhrase.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/12/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFPhrase` object represents data returned by the [**phrases** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/phrases/)
 of the Aeris Weather API.
 */
@interface AWFPhrase : AWFGeographicObject

/**
 Full phrase using English units.
 */
@property (nonatomic, copy, nullable) NSString *phrase;

/**
 Full phrase using Metric units.
 */
@property (nonatomic, copy, nullable) NSString *phraseMET;

/**
 Shorted summary phrase using English units.
 */
@property (nonatomic, copy, nullable) NSString *shortPhrase;

/**
 Shortened summary phrase using Metric units.
 */
@property (nonatomic, copy, nullable) NSString *shortPhraseMET;

@end

NS_ASSUME_NONNULL_END
