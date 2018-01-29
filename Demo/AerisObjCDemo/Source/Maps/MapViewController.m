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
	
	if (self.splitViewController) {
		self.navigationItem.leftBarButtonItem = [self.splitViewController displayModeButtonItem];
		self.navigationItem.leftItemsSupplementBackButton = YES;
	}
	
//	self.weatherMap.timelineStartDate = [NSDate dateWithTimeIntervalSinceNow:12 * 3600];
//	self.weatherMap.timelineEndDate = [NSDate dateWithTimeIntervalSinceNow:24 * 3600];
	
	// get default location's coordinates to set the map region to
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	if (place) {
		CLLocationCoordinate2D coord = place.coordinate;
		NSInteger zoom = (self.weatherMap.weatherMapType == AWFWeatherMapTypeGoogle) ? 8 : 7;
		[self.weatherMap.strategy setCenterCoordinate:coord zoomLevel:zoom animated:YES];
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
	
	if (!self.isMapSetup) {
		[self.weatherMap addSourcesForLayerTypes:@[AWFMapLayerSatellite, AWFMapLayerRadar]];
		self.isMapSetup = YES;
	}
}

@end
