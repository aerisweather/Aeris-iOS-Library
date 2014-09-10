//
//  MapViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/9/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "MapViewController.h"

@interface MapViewController ()

@end

@implementation MapViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // handle the translucent status bar in iOS 7
		if (AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
			self.edgesForExtendedLayout = UIRectEdgeNone;
			self.navigationController.navigationBar.translucent = NO;
		}
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
	self.view.backgroundColor = [UIColor blackColor];
	
//	self.weatherMap.timelineStartDate = [NSDate dateWithTimeIntervalSinceNow:12 * 3600];
//	self.weatherMap.timelineEndDate = [NSDate dateWithTimeIntervalSinceNow:24 * 3600];
	
	// get default location's coordinates to set the map region to
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	if (place) {
		CLLocationCoordinate2D coord = CLLocationCoordinate2DMake([place.latitude floatValue], [place.longitude floatValue]);
		NSInteger zoom = (self.weatherMap.weatherMapType == AWFWeatherMapTypeGoogle) ? 8 : 7;
		[self.weatherMap setMapCenterCoordinate:coord zoomLevel:zoom animated:YES];
	}
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	BOOL useBasicMapControl = [[Preferences sharedInstance].mapControl isEqualToString:kMapControlBasic];
	self.timelineView.hidden = useBasicMapControl;
	self.controlView.hidden = !useBasicMapControl;
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	if (self.weatherMapType == AWFWeatherMapTypeGoogle) {
	}
	else if (self.weatherMapType == AWFWeatherMapTypeMapbox) {
	}
	else {
	}
	
	if (!self.isMapSetup) {
		[self.weatherMap addLayerType:AWFLayerTypeRadar];
		[self.weatherMap addLayerType:AWFLayerTypeSatellite];
		
		self.isMapSetup = YES;
	}
}

@end
