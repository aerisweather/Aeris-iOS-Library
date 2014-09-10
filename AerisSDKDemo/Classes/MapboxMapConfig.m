//
//  MapboxMapConfig.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/6/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "MapboxMapConfig.h"

@interface MapboxMapConfig ()
@property (nonatomic, strong) NSString *mapboxMapId;
@end

@implementation MapboxMapConfig

@synthesize mapboxMapId;

- (id)init {
	self = [super init];
	if (self) {
		// sample map set from Mapbox, replace this with your own map id
		self.mapboxMapId = @"justin.map-mf07hryq";
	}

	return self;
}

@end
