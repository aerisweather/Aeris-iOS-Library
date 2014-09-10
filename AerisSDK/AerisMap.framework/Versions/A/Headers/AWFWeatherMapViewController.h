//
//  AWFWeatherMapViewController.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/6/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFWeatherMap.h"

@class AWFWeatherMapConfig, AWFTimelineView, AWFBasicControlView, AWFWeatherMapLegendView;

@interface AWFWeatherMapViewController : UIViewController

@property (nonatomic, assign) AWFWeatherMapType weatherMapType;
@property (nonatomic, strong) AWFWeatherMapConfig *config;

@property (readonly, nonatomic, strong) AWFWeatherMap *weatherMap;

@property (readonly, nonatomic, strong) AWFTimelineView *timelineView;
@property (readonly, nonatomic, strong) AWFBasicControlView *controlView;
@property (readonly, nonatomic, strong) AWFWeatherMapLegendView *legendView;

@property (nonatomic, assign, getter = isAutorefreshEnabled) BOOL autorefreshEnabled;

@end
