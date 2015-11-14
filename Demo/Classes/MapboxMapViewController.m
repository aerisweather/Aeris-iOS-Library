//
//  MapboxMapViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/6/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "MapboxMapViewController.h"
#import "MapboxMapConfig.h"

@interface MapboxMapViewController ()
@property (nonatomic, assign) BOOL isMapSetup;
@end

@implementation MapboxMapViewController

@synthesize isMapSetup = _isMapSetup;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.weatherMapType = AWFWeatherMapTypeMapbox;
		self.config = [MapboxMapConfig config];
	}

	return self;
}

@end
