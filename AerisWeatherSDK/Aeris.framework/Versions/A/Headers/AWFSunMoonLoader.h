//
//  AFSunMoonLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFSunMoonFilterSun;
extern NSString * const AWFSunMoonFilterTwilight;
extern NSString * const AWFSunMoonFilterMoon;
extern NSString * const AWFSunMoonFilterMoonPhase;

/**
 *  `AWFSunMoonLoader` provides convenience methods for interacting with the
 *  [`sunmoon` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/sunmoon) of the Aeris API. All requests will
 *  return instances of `AWFSunMoon` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFSunMoonLoader : AWFGeographicObjectLoader

@end