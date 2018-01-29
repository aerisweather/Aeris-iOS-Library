//
//  AWFMapboxMapStrategy.h
//  AerisMapboxMap
//
//  Created by Nicholas Shipes on 7/2/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AerisMapKit.h>
#import <Mapbox/Mapbox.h>

@class MBXRasterTileOverlay;

/**
 *  An `AWFAppleMapStrategy` object implements the `AWFMapStrategy` protocol and provides the necessary functionality for managing a `AWFWeatherMap` configured
 *  with an `MKMapView` instance and MapBox base map.
 */
@interface AWFMapboxMapStrategy : NSObject <AWFMapStrategy, MGLMapViewDelegate>

@property (readonly, nonatomic) AWFMapStrategyType strategyType;
@property (nonatomic, strong) MGLMapView *mapView;
@property (readonly, nonatomic, strong) AWFWeatherMapConfig *config;
@property (readonly, nonatomic, strong) id<AWFMapOverlayFactory> overlayFactory;
@property (readonly, nonatomic, strong) NSArray *overlays;
@property (readonly, nonatomic, strong) NSArray *annotations;
@property (readonly, nonatomic) AWFMapCoordinateBounds *coordinateBounds;
@property (readonly, nonatomic) CLLocationCoordinate2D centerCoordinate;
@property (readonly, nonatomic) NSInteger zoomLevel;

@property (readonly, nonatomic, strong) UIView *animationContainerView;
@property (readonly, nonatomic, strong) AWFMapCallout *callout;
@property (readonly, nonatomic, strong) AWFCalloutView *calloutView;

@property (nonatomic, weak) id<MGLMapViewDelegate> mapViewDelegate;

/**
 *  The receiver's delegate.
 *
 *	The delegate should implement the methods of the `AWFMapStrategyDelegate` protocol.
 */
@property (nonatomic, weak) id<AWFMapStrategyDelegate> delegate;

/**
 *  Initializes and returns a map strategy associated with the specified weather map instance while specifying whether to load Mapbox metadata and markers.
 *
 *  @param weatherMap      The weather map instance associated with the map strategy
 *  @param includeMetadata Whether to load the map's metadata including center coordinate and zoom limits
 *  @param includeMarkers  Whether to load the map's markers
 *
 *  @return An initialized map strategy
 */
- (instancetype)initWithWeatherMap:(AWFWeatherMap *)weatherMap includeMetadata:(BOOL)includeMetadata includeMarkers:(BOOL)includeMarkers;

@end
