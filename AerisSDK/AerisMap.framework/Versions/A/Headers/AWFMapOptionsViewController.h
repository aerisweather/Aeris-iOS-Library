//
//  AWFMapOptionsViewController.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/9/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFDataLayer.h"

@class AWFMapOptionsViewController, AWFWeatherMap;

@protocol AWFMapOptionsViewControllerDelegate <NSObject>
@optional

- (void)mapOptionsViewController:(AWFMapOptionsViewController *)optionsController didSelectLayerType:(AWFLayerType)layerType;
- (void)mapOptionsViewController:(AWFMapOptionsViewController *)optionsController didDeselectLayerType:(AWFLayerType)layerType;

@end


@interface AWFMapOptionsViewController : UIViewController

- (instancetype)initWithWeatherMap:(AWFWeatherMap *)weatherMap;

@property (readonly, nonatomic, strong) AWFWeatherMap *weatherMap;
@property (nonatomic, weak) id<AWFMapOptionsViewControllerDelegate> delegate;

@end
