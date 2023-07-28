//
//  MapboxMapViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/6/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "MapboxMapViewController.h"
#import "dlfcn.h"

@interface MapboxMapViewController ()
@property (nonatomic, assign) BOOL isMapSetup;
@end

@implementation MapboxMapViewController

@synthesize isMapSetup = _isMapSetup;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
//	dlopen("AerisMapboxMapKit.framework/AerisMapboxMapKit", RTLD_LAZY);
//	NSLog(@"MAPBOX: %@", NSStringFromClass([AWFMapboxMapStrategy class]));
	
//	MGLMapView *mapView = [[MGLMapView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.weatherMapType = AWFWeatherMapTypeMapbox;
//		self.config = [MapboxMapConfig config];
	}
	return self;
}

@end
