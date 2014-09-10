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
		
		//self.mapboxMapId = @"u10int.map-i2i85ouw";
		self.mapboxMapId = @"justin.map-mf07hryq";
		
	}
	return self;
}

@end
