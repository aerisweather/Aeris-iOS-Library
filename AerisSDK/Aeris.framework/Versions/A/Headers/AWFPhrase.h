//
//  AWFPhrase.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/12/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFPhrase : AWFGeographicObject

/**
 *  Full phrase using English units.
 */
@property (nonatomic, copy) NSString *phrase;

/**
 *  Full phrase using Metric units.
 */
@property (nonatomic, copy) NSString *phraseMET;

/**
 *  Shorted summary phrase using English units.
 */
@property (nonatomic, copy) NSString *shortPhrase;

/**
 *  Shortened summary phrase using Metric units.
 */
@property (nonatomic, copy) NSString *shortPhraseMET;

@end
