//
//  AWFMKImageDataLayer.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFImageDataLayer.h>

@class AWFMKImageOverlay;

/**
 *  An `AWFMKImageDataLayer` object is a subclass of `AWFImageDataLayer` that provides the necessary `MKOverlay` instance to use with Apple's MapKit for displaying
 *  a single static image overlay on an `MKMapView` instance.
 */
@interface AWFMKImageDataLayer : AWFImageDataLayer <AWFImageDataLayer>

/**
 *  The `MKOverlay` instance managing the image.
 */
@property (readonly, nonatomic, strong) AWFMKImageOverlay *overlay;

@end
