//
//  AFGMImageOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/11/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AerisMapKit.h>

@class GMSGroundOverlay;

@interface AWFGMImageDataLayer : AWFRasterSource

@property (readonly, nonatomic, strong) GMSGroundOverlay *overlay;

@end
