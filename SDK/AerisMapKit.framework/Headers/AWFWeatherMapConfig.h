//
//  AFWeatherMapConfig.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFMapItemStyle;
@class AWFStyledAnnotation, AWFPolygon, AWFAnnotationStyle, AWFPolygonStyle, AWFOverlayStyle, AWFLegendStyle;
@protocol AWFPolygon, AWFStyledAnnotation;

/**
 An `AWFWeatherMapConfig` object provides all of the configurable settings to a {@link AWFWeatherMap} instance. This object is
 usually applied to a weather map object at initialization.
 
 The default implementation of a `AWFWeatherMapConfig` object assigns all of the default values needed by a weather map
 instance. In order to override these default settings, you must subclass `AWFWeatherMapConfig` and assign your custom values
 in your subclass's implementation.
 */
@interface AWFWeatherMapConfig : NSObject

/**
 Initializes and returns a map configuration instance with the default settings.
 
 @return The intialized map configuration instance.
 */
+ (instancetype)config;

//-----------------------------------------------------------------------------
// @name General Options
//-----------------------------------------------------------------------------

/**
 Update interval to update active map layers when auto-refresh is enabled for the weather map.
 
 @see AWFWeatherMap
 */
@property (nonatomic, assign) NSTimeInterval refreshInterval;

//-----------------------------------------------------------------------------
// @name Overlays
//-----------------------------------------------------------------------------

/**
 The map level at which to place tile overlays.
 
 The default value for this property is `MKOverlayLevelAboveRoads`.
 */
@property (nonatomic, assign) MKOverlayLevel tileOverlayLevel;

/**
 All default request options to be used for each data layer, keyed by their associated `AWFLayerType` value.
 */
@property (nonatomic, strong) NSDictionary *dataRequestOptions;

/**
 Whether to display state province lines over the weather layers. The default value is `NO`.
 */
@property (nonatomic, assign) BOOL showsStateProvinceLines;

/**
 Whether to display county lines over the weather layers. The default value is `NO`.
 */
@property (nonatomic, assign) BOOL showsCountyLines;

/**
 Whether water should be masked out from surface-based weather layers (e.g. surface temperatures, dew points, etc). The default value is `YES`.
 */
@property (nonatomic, assign) BOOL shouldApplyWaterMaskToSurfaceLayers;

/**
 The Mapbox layer identifier under which Aeris tile overlays will be inserted. If this value is `nil`, then Aeris layers will be added at the
 top of the layer stack.
 */
@property (nonatomic, copy) NSString *mapboxOverlayInsertionLayerIdentifier;

//-----------------------------------------------------------------------------
// @name Annotations
//-----------------------------------------------------------------------------

/**
 Determines whether point and shape data should be reloaded when the visible map region changes.
 */
@property (nonatomic, assign) BOOL shouldReloadDataOnRegionChange;

/**
 The minimum distance required in screen points the map region must change before point and shape data is reloaded.
 */
@property (nonatomic, assign) CGFloat distanceRequiredToReloadData;

//-----------------------------------------------------------------------------
// @name Animation/Timeline
//-----------------------------------------------------------------------------

/**
 A Boolean that determines whether overlays can be animated on the weather map.
 
 The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL animationEnabled;

/**
 The length of the animation in seconds.
 
 The default value of this property is `2.0` seconds.
 */
@property (nonatomic, assign) NSTimeInterval animationDuration;

/**
 The number of seconds to hold the last frame of the animation before replaying from the beginning.
 
 The default value of this property is `2.0` seconds.
 */
@property (nonatomic, assign) NSTimeInterval animationEndDelay;

/**
 A Boolean that determines whether image overlays should crossfade between intervals during animation playback.
 
 The default value of this property is `NO`.
 */
@property (nonatomic, assign) BOOL animationCrossfadeEnabled;

/**
 The maximum number of images to request for an animation.
 
 If the total number of images available within the animation's time range is greater than this value, the image intervals will
 be adjusted to be evenly spaced so that the total number of images never exceeds this value. Assigning a relative low value to this
 property will result in faster animation load times, whereas larger numbers will result in smoother animations for timelines
 with larger time ranges.
 
 The default value of this property is `20`.
 */
@property (nonatomic, assign) NSInteger maximumIntervalsForAnimation;

/**
 The time interval offset to start the animation timeline relative to the current date and time, in seconds.
 
 This value must be less than the value for `timelineEndOffsetFromNow`. A timeline with the same start and end
 time offsets will not animate.
 
 The default value of this property is `-7200`, or `-2 * AWF_HOUR` (2 hours ago).
 */
@property (nonatomic, assign) NSTimeInterval timelineStartOffsetFromNow;

/**
 The time interval offset for the animation timeline to end relative to the current date and time, in seconds.
 
 This value must be greater than the value for `timelineStartOffsetFromNow`. A timeline with the same start and end
 time offsets will not animate.
 
 The default value of this property is `0` (current time).
 */
@property (nonatomic, assign) NSTimeInterval timelineEndOffsetFromNow;

/**
 Determines whether or not scrubbing the timeline also updates the active data layers.
 
 If an animation has successfully loaded all data required for playback, scrubbing the timeline will result in smooth transitions between
 intervals. However, if animation data has not yet been loaded, then scrubbing the timeline will result in a choppy transition between intervals as
 the overlay is invalidated and redrawn at each interval. This applies to image and tile data layers only.
 */
@property (nonatomic, assign) BOOL timelineScrubbingEnabled;
/**

 A Boolean value indicating whether to display text point data on the map while tile data is animating. The default is `NO`.
 */
@property (nonatomic, assign) BOOL showTextDataWhileAnimating;

//-----------------------------------------------------------------------------
// @name Long Press Gesture
//-----------------------------------------------------------------------------

/**
 A Boolean value that indicates whether the weather map should show the animated circle during a long press gesture on the map.
 */
@property (nonatomic, assign) BOOL showsAnnotationDuringLongPress;

/**
 A Boolean value that indicates whether the weather map should show an annotation on the map at the location of a long press gesture.
 */
@property (nonatomic, assign) BOOL showsAnnotationForLongPress;

/**
 The annotation style to use for the long press gesture when enabled.
 */
@property (nonatomic, strong) AWFAnnotationStyle *longPressAnnotationStyle;

/**
 Returns the `AWFMapItemStyle` object to use when rendering the overlay on the map.
 
 @param overlay The overlay to return the style for
 @return The style instance for the overlay
 */
- (AWFMapItemStyle *)styleForOverlay:(id<MKOverlay>)overlay;

/**
 Returns the overlay style configuration for the given `layerType`.
 
 The returned value may be an instance of `AWFMapItemStyle` or an `NSDictionary`. If an `NSDictionary` is returned, then styles are assigned by
 the annotation type they represent.
 
 @param layerType The layer type to return the style configuration for
 @return The overlay style configuration for the `layerType`
 */
- (id)overlayStyleConfigForLayerType:(AWFMapLayer)layerType;

///**
// Returns the request options to use when requesting data for the `layerType`.
// *
// @param layerType The layer type to return request options for
// *
// @return The request options for the layer type
// */
//- (AWFWeatherRequestOptions *)requestOptionsForLayerType:(AWFMapLayer)layerType;
//
///**
// Returns the request action to use when requesting data for the `layerType`.
// *
// @param layerType The layer type to return the request action for
// *
// @return The request action for the layer type, if any
// */
//- (NSString *)requestActionForLayerType:(AWFMapLayer)layerType;

@end

NS_ASSUME_NONNULL_END
