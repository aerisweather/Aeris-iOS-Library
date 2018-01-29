//
//  AWFMapLayerOptionsViewController.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 11/2/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFMapLayerOptionsViewController;

@protocol AWFMapLayerOptionsViewControllerDelegate <NSObject>

- (void)optionsController:(AWFMapLayerOptionsViewController *)optionsController didSelectLayerForType:(AWFMapLayer)layerType;
- (void)optionsController:(AWFMapLayerOptionsViewController *)optionsController didDeselectLayerForType:(AWFMapLayer)layerType;

@end

@interface AWFMapLayerOptionsViewController : UIViewController

/**
 The table view used to display the layer options.
 */
@property (readonly, nonatomic, strong) UITableView *tableView;

@property (readonly, nonatomic, strong) AWFMapLayer layerType;
@property (nonatomic, strong) AWFMapLayer selectedLayerType;

@property (nullable, nonatomic, unsafe_unretained) id<AWFMapLayerOptionsViewControllerDelegate> delegate;

- (instancetype)initWithLayerType:(AWFMapLayer)layerType NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
