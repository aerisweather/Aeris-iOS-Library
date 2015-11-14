//
//  AFGMImageOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/11/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFImageDataLayer.h>

@class GMSGroundOverlay;

@interface AWFGMImageDataLayer : AWFImageDataLayer <AWFImageDataLayer>

@property (readonly, nonatomic, strong) GMSGroundOverlay *overlay;

@end
