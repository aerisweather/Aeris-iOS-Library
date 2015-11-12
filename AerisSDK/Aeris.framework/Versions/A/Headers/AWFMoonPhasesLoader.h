//
//  AFMoonPhasesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFMoonPhaseFilterNew;
extern NSString * const AWFMoonPhaseFilterFirst;
extern NSString * const AWFMoonPhaseFilterFull;
extern NSString * const AWFMoonPhaseFilterThird;

extern NSString * const AWFMoonPhaseFieldDateTime;
extern NSString * const AWFMoonPhaseFieldCode;
extern NSString * const AWFMoonPhaseFieldType;

/**
 *  `AWFMoonPhasesLoader` provides convenience methods for interacting with the
 *  [`moonphases` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/moonphases) of the Aeris API. All requests will
 *  return instances of `AWFMoonPhase` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFMoonPhasesLoader : AWFGeographicObjectLoader

@end