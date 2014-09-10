//
//  AFStormReportsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

/**
 *  `AWFStormReportsLoader` provides convenience methods for interacting with the
 *  [`stormreports` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/stormreports) of the Aeris API. All requests will
 *  return instances of `AWFStormReport` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFStormReportsLoader : AWFGeographicObjectLoader

@end