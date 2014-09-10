//
//  AFSunMoonLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

/**
 *  `AWFSunMoonLoader` provides convenience methods for interacting with the
 *  [`sunmoon` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/sunmoon) of the Aeris API. All requests will
 *  return instances of `AWFSunMoon` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFSunMoonLoader : AWFGeographicObjectLoader

@end