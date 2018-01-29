//
//  AWFMKRasterSource.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFRasterSource.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFMKImageOverlay;

/**
 An `AWFMKRasterSource` object is a subclass of `AWFRasterSource` that provides the necessary `MKOverlay` instance to use with Apple's MapKit for displaying
 a single static image overlay on an `MKMapView` instance.
 */
@interface AWFMKRasterSource : AWFRasterSource

/**
 The `MKOverlay` instance managing the image.
 */
@property (readonly, nonatomic, strong) AWFMKImageOverlay *overlay;

@end

NS_ASSUME_NONNULL_END
