//
//  AWFWeatherMapLegendView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/29/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFLayerType.h"

@class AWFWeatherMapConfig;

@interface AWFWeatherMapLegendView : UIView

@property (readonly, nonatomic, strong) NSArray *legends;
@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;
@property (readonly, nonatomic, strong) UIButton *toggleButton;
@property (nonatomic, assign) BOOL showsCloseIndicator;

- (instancetype)initWithMapConfig:(AWFWeatherMapConfig *)config frame:(CGRect)frame;

- (void)addLegendForLayerType:(AWFLayerType)layerType;
- (void)removeLegendForLayerType:(AWFLayerType)layerType;
- (void)show:(BOOL)show;

@end
