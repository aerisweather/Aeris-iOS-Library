//
//  AFWeatherMap.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisMapKit/AWFWeatherMapConfig.h>
#import <AerisMapKit/AWFWeatherMapStyle.h>
#import <AerisMapKit/AWFWeatherMapDataSource.h>
#import <AerisMapKit/AWFWeatherMapDelegate.h>
#import <AerisMapKit/AWFWeatherLayer.h>
#import <AerisMapKit/AWFLabelSource.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const AWFWeatherMapWillStartAnimating;
extern NSString * const AWFWeatherMapDidStartAnimating;
extern NSString * const AWFWeatherMapDidStopAnimating;

/**
 Weather map type options to determine which mapping strategy and library to use.

 - AWFWeatherMapTypeApple: Apple's MapKit
 - AWFWeatherMapTypeGoogle: GoogleMaps iOS SDK
 - AWFWeatherMapTypeMapbox: Mapbox iOS SDK
 - AWFWeatherMapTypeDefault: Apple's MapKit
 */
typedef NS_ENUM(NSUInteger, AWFWeatherMapType) {
	AWFWeatherMapTypeApple = 0,
	AWFWeatherMapTypeGoogle,
	AWFWeatherMapTypeMapbox,
	AWFWeatherMapTypeDefault = AWFWeatherMapTypeApple
};

@class AWFMapContentSource, AWFRasterMapLayer, AWFLabelSource;
@class AWFWeatherMapContainerView, AWFAnimationTimeline;
@class AWFAmpTileSourceProvider;

@protocol AWFWeatherMapDelegate;
@protocol AWFWeatherMapDataSource;

/**
 An `AWFWeatherMap` object provides a complete interface for displaying weather-related overlays and data on a map view. You
 use this class to display and control weather information and map contents being displayed from your application.
 
 When you initialize a weather map, you should specify the mapping library to use by using the appropriate {@link AWFWeatherMapType}
 value. Alternatively, you can initialize a weather map with a map view instance and the proper {@link AWFWeatherMapType} will be
 assigned based on the type of map view object provided.
 */
@interface AWFWeatherMap : NSObject <AWFMapContentDelegate, AWFAnimationDelegate, AWFMapStrategyDelegate>

/**
 The mapping strategy provider to use with the weather map.
 */
@property (nonatomic, strong, readonly) id<AWFMapStrategy> strategy;

/**
 The type of mapping library being used with the weather map.
 
 This value indicates the mapping library currently being used with the weather map.
 */
@property (readonly, nonatomic, assign) AWFWeatherMapType weatherMapType;

/**
 The view containing the map view and all related subviews, such as legends and controls.
 */
@property (readonly, nonatomic, strong) AWFWeatherMapContainerView *weatherMapView;

/**
 The map view managed by this weather map instance.
 */
@property (readonly, nonatomic, strong) UIView *mapView;

/**
 An object that needs to receive all delegate messages from the specific mapping SDK being used.
 */
@property (nonatomic, unsafe_unretained) id mapViewDelegate;

/**
 Forecast model type to be used for all active future data layers (when supported).
 */
@property (nonatomic) AWFForecastModelType forecastModelType;

/**
 The view indicating when the map's timeline is in the future.
 */
@property (nonatomic, strong) UIView *futureIndicatorView;

@property (nonatomic, readonly) NSArray<AWFMapContentSource *> *sources;

/**
 Returns an array of layer types currently active on the map.
 */
@property (readonly, nonatomic) NSArray *activeLayerTypes;

/**
 Returns an array of codes corresponding to the active layer types currently active on the map.
 */
@property (readonly, nonatomic) NSArray<AWFMapLayer> *activeLayerTypeCodes;

@property (nonatomic, strong, readonly) AWFAnimationTimeline *timeline;

/**
 The configuration object associated with the weather map.
 */
@property (readonly, nonatomic, strong) AWFWeatherMapConfig *config;

/**
 The map style associated with the weather map that provides style specifications for items rendered to the map.
 */
@property (nonatomic, strong) AWFWeatherMapStyle *style;

/**
 The tile source provider responsible for managing all Aeris Maps (AMP) layers on the map.
 */
@property (nonatomic, readonly) AWFAmpTileSourceProvider *amp;

/**
 The receiver's delegate.
 
 A weather map sends messages to its delegate regarding the addition and removal of weather overlays, animation status changes, and forwards
 respective messages from the interval map view object.
 */
@property (nonatomic, unsafe_unretained) id<AWFWeatherMapDelegate> delegate;

/**
 The receiver's data source.
 
 A weather map requests data from its data source when displaying map elements, such as callouts and annotations.
 */
@property (nonatomic, unsafe_unretained) id<AWFWeatherMapDataSource> dataSource;

/**
 Controls the number of times the map animation should repeat after its initial loop. Setting this value to `-1` will loop the animation endlessly 
 until it is stopped.
 */
@property (nonatomic, assign) NSInteger animationRepeatCount;

/**
 A Boolean value indicating whether the weather map is currently animating.
 */
@property (readonly, nonatomic, getter=isAnimating) BOOL animating;

/**
 A Boolean value indicating whether the weather map is currently loading data for the animation.
 */
@property (readonly, nonatomic, getter=isLoadingAnimation) BOOL loadingAnimation;

/**
 Initializes and returns a newly allocated weather map object with the specified map type.
 
 @param mapType The {@link AWFWeatherMapType} to use with the weather map.
 @return An initialized weather map object or `nil` if the object couldn't be created.
 */
- (instancetype)initWithMapType:(AWFWeatherMapType)mapType;

/**
 Initializes and returns a newly allocated weather map object with the specified map type and configuration.
 
 @param mapType   The {@link AWFWeatherMapType} to use with the weather map.
 @param mapConfig The configuration object to use with the weather map.
 @return An initialized weather map object or `nil` if the object couldn't be created.
 */
- (instancetype)initWithMapType:(AWFWeatherMapType)mapType config:(nullable AWFWeatherMapConfig *)mapConfig;

/**
 Initializes and returns a newly allocated weather map object using the specified map view.
 
 @param mapView The map view to associate with the weather map.
 @return An initialized weather map object or `nil` if the object couldn't be created.
 */
- (instancetype)initWithMapView:(id)mapView;

/**
 Initializes and returns a newly allocated weather map object with a map configuration using the specified map view.
 
 @param mapView   The map view to associate with the weather map.
 @param mapConfig The configuration object to use with the weather map.
 @return An initialized weather map object or `nil` if the object couldn't be created.
 */
- (instancetype)initWithMapView:(id)mapView config:(nullable AWFWeatherMapConfig *)mapConfig;

//-----------------------------------------------------------------------------
// @name Adding and Removing Data Sources
//-----------------------------------------------------------------------------

/**
 Adds the specified map content source to the map.
 
 The z-index order in which each map content source is rendered on the map will depend on the type of map source (e.g. tile, point, shape, etc). For example,
 point map content sources will always be rendered above raster or shape sources.

 @param source The map source to add.
 */
- (void)addSource:(AWFMapContentSource *)source;

/**
 Adds an array of map content sources to the map.
 
 The z-index order in which each map content source is rendered on the map will depend on the type of map source (e.g. tile, point, shape, etc). For example,
 point map content sources will always be rendered above raster or shape sources.

 @param source The map sources to add.
 */
- (void)addSources:(NSArray<AWFMapContentSource *> *)source;

/**
 Removes a map content source from the map.

 @param source The map source to remove.
 */
- (void)removeSource:(AWFMapContentSource *)source;

/**
 Removes an array of map content sources from the map.

 @param sources The map sources to remove.
 */
- (void)removeSources:(NSArray<AWFMapContentSource *> *)sources;

- (BOOL)containsSource:(AWFMapContentSource *)source;

/**
 Adds a new map content source to the map for the specified layer type.

 @param layerType The layer type to add a new map source for.
 */
- (void)addSourceForLayerType:(AWFMapLayer)layerType;

/**
 Adds a series of new map content sources to the map for the specified array of layer types.

 @param layerTypes The layer types to add map sources for.
 */
- (void)addSourcesForLayerTypes:(NSArray<AWFMapLayer> *)layerTypes;

/**
 Removes the map content source from the map associated with the specified layer type, if any.

 @param layerType The layer type to remove the map source for.
 */
- (void)removeSourceForLayerType:(AWFMapLayer)layerType;

/**
 Removes a series of map content sources from the map for the specified array of layer types.

 @param layerTypes The layer types to remove map sources for, if any.
 */
- (void)removeSourcesForLayerTypes:(NSArray<AWFMapLayer> *)layerTypes;

/**
 Returns whether the map contains a map content source for the specified layer type.

 @param layerType The layer type.
 @return `YES` if the map contains a map source for the layer type, otherwise `NO`.
 */
- (BOOL)containsSourceForLayerType:(AWFMapLayer)layerType;

/**
 Returns the map content source for the specified layer type if it exists on the map.

 @param layerType The layer type.
 @return The map content source, or `nil` if one does not exist.
 */
- (nullable AWFMapContentSource *)sourceForLayerType:(AWFMapLayer)layerType;

//-----------------------------------------------------------------------------
// @name Updating Map Data
//-----------------------------------------------------------------------------

/**
 Updates the existing layer type.
 
 @param layerType The {@link AWFLayerType} to update on the map.
 */
//- (void)refreshLayerType:(AWFLayerType)layerType;

/**
 Updates all existing map content sources on the map.
 */
- (void)refreshAllSources;

/**
 Starts the auto-refresh timer, which will update all active overlays on the map at the specified interval in the weather map's
 configuration.
 */
- (void)enableAutoRefresh;

/**
 Stops the auto-refresh timer that updates all active overlays at regular intervals.
 
 It is recommended that your application call this method when the view containing the weather map disappears so that it no longer
 performs unnecessary processes.
 */
- (void)disableAutoRefresh;

/**
 Updates all point data layers by requesting data for the current map bounds.
 */
- (void)updatePointDataForCurrentMapBounds;

//-----------------------------------------------------------------------------
// @name Animating Map Data
//-----------------------------------------------------------------------------

/**
 Starts animating active overlays from the beginning of the timeline.
 */
- (void)startAnimating;

/**
 Starts animating active overlays from the specified date.
 
 @param time The date from which to begin animating.
 */
- (void)startAnimatingFromTime:(NSDate *)time;

/**
 Stops animating active overlays.
 */
- (void)stopAnimating;

/**
 Pauses all overlay animations if animating.
 */
- (void)pauseAnimation;

/**
 Moves the map timeline to the specified date and updates overlays as needed.
 
 @param time The date and time to move the timeline to.
 */
- (void)goToTime:(NSDate *)time;

//-----------------------------------------------------------------------------
// @name Class Methods
//-----------------------------------------------------------------------------

/**
 Returns an array of all of the supported forecast model types.
 
 The returned array contains one NSDictionary object for each forecast model type and include's the forecast model's type and name:
 
 `{@"type": @(AWFForecastModelTypeHRRR), @"name": @"HRRR"}`
 
 This array of supported forecast model types is often used to dynamically generate menus or listings of the available forecast models 
 `AWFWeatherMap` supports.
 
 @return The array of supported forecast model types.
 */
+ (NSArray *)supportedForecastModels;

@end

NS_ASSUME_NONNULL_END
