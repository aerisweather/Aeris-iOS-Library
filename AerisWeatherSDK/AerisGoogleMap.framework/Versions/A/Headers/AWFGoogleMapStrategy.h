//
//  AFGoogleMapManager.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>

@interface AWFGoogleMapStrategy : NSObject <AWFMapStrategy, GMSMapViewDelegate>

@property (readonly, nonatomic) AWFMapStrategyType strategyType;
@property (nonatomic, strong) GMSMapView *mapView;
@property (readonly, nonatomic, strong) AWFWeatherMapConfig *config;
@property (readonly, nonatomic, strong) NSArray *overlays;
@property (readonly, nonatomic, strong) NSArray *annotations;
@property (readonly, nonatomic) AWFCoordinateBounds *coordinateBounds;
@property (readonly, nonatomic) CLLocationCoordinate2D centerCoordinate;
@property (readonly, nonatomic) NSInteger zoomLevel;

@property (readonly, nonatomic, strong) UIView *animationContainerView;
@property (readonly, nonatomic, strong) AWFCalloutView *calloutView;

@property (nonatomic, weak) id<GMSMapViewDelegate> mapViewDelegate;

/**
 *  The receiver's delegate.
 *
 *	The delegate should implement the methods of the `AWFMapStrategyDelegate` protocol.
 */
@property (nonatomic, weak) id<AWFMapStrategyDelegate> delegate;

@end
