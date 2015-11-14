//
//  AFAppleMapManager.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisMap/AWFMapStrategy.h>

@class AWFAnimationContainerView, AWFAnnotation;

/**
 *  An `AWFAppleMapStrategy` object implements the `AWFMapStrategy` protocol and provides the necessary functionality for managing a `AWFWeatherMap` configured
 *  with an `MKMapView` instance.
 */
@interface AWFAppleMapStrategy : NSObject <AWFMapStrategy, MKMapViewDelegate>

@property (readonly, nonatomic) AWFMapStrategyType strategyType;
@property (nonatomic, strong) MKMapView *mapView;
@property (readonly, nonatomic, strong) AWFWeatherMapConfig *config;
@property (nonatomic, strong, readonly) NSArray *overlays;
@property (nonatomic, strong, readonly) NSArray *annotations;
@property (nonatomic, readonly) AWFCoordinateBounds *coordinateBounds;
@property (nonatomic, readonly) CLLocationCoordinate2D centerCoordinate;
@property (nonatomic, readonly) NSInteger zoomLevel;

@property (readonly, nonatomic, strong) AWFAnimationContainerView *animationContainerView;
@property (readonly, nonatomic, strong) AWFCalloutView *calloutView;

@property (nonatomic, unsafe_unretained) id<MKMapViewDelegate> mapViewDelegate;

/**
 *  The receiver's delegate.
 *
 *	The delegate should implement the methods of the `AWFMapStrategyDelegate` protocol.
 */
@property (nonatomic, weak) id<AWFMapStrategyDelegate> delegate;

@end
