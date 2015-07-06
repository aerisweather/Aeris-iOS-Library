//
//  AWFMKImageDataLayer.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFImageDataLayer.h>

@class AWFImageOverlay;

@interface AWFMKImageDataLayer : AWFImageDataLayer <AWFImageDataLayer>

@property (readonly, nonatomic, strong) AWFImageOverlay *overlay;

@end
