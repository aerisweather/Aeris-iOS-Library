//
//  GoogleMapViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/6/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "GoogleMapViewController.h"

@interface GoogleMapViewController ()
@property (nonatomic, assign) BOOL isMapSetup;
@end

@implementation GoogleMapViewController

@synthesize isMapSetup = _isMapSetup;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.weatherMapType = AWFWeatherMapTypeGoogle;
		self.config = [AWFWeatherMapConfig config];
	}

	return self;
}

@end
