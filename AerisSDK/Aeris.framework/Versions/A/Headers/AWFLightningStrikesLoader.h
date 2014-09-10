//
//  AFLightningStrikesLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

/**
 *  `AWFLightningStrikesLoader` provides convenience methods for interacting with the
 *  [`lightning` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/lightning) of the Aeris API. All requests will
 *  return instances of `AWFLightningStrike` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFLightningStrikesLoader : AWFGeographicObjectLoader

@end