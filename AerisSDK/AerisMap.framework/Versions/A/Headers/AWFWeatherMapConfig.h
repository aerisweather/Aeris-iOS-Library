//
//  AFWeatherMapConfig.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMap/AWFLayerType.h>

@class AWFMapItemStyle;
@class AWFStyledAnnotation, AWFPolygon, AWFAnnotationStyle, AWFPolygonStyle, AWFOverlayStyle, AWFLegendStyle;
@protocol AWFPolygon, AWFStyledAnnotation;

/**
 *  An `AWFWeatherMapConfig` object provides all of the configurable settings to a {@link AWFWeatherMap} instance. This object is
 *	usually applied to a weather map object at initialization.
 *
 *	The default implementation of a `AWFWeatherMapConfig` object assigns all of the default values needed by a weather map
 *	instance. In order to override these default settings, you must subclass `AWFWeatherMapConfig` and assign your custom values
 *	in your subclass's implementation.
 */
@interface AWFWeatherMapConfig : NSObject

/**
 *  Initializes and returns a map configuration instance with the default settings.
 *
 *  @return The intialized map configuration instance.
 */
+ (instancetype)config;

//-----------------------------------------------------------------------------
// @name General Options
//-----------------------------------------------------------------------------

/**
 *  Update interval to update active map layers when auto-refresh is enabled for the weather map.
 *
 *  @see AWFWeatherMap
 */
@property (nonatomic, assign) NSTimeInterval refreshInterval;

//-----------------------------------------------------------------------------
// @name Overlays
//-----------------------------------------------------------------------------

/**
 *  The amount of transparency to apply to tile overlays.
 *
 *	The value in this property can be in the range `0.0` to `1.0`, where `0.0` represents total transparency
 *	and `1.0` represents total opacity. The default value is `0.8`.
 */
@property (nonatomic, assign) CGFloat tileOverlayAlpha;

/**
 *  The map level at which to place tile overlays.
 *
 *	The default value for this property is `MKOverlayLevelAboveRoads`.
 */
@property (nonatomic, assign) MKOverlayLevel tileOverlayLevel;

/**
 *  All default request options to be used for each data layer, keyed by their associated `AFLayerType` value.
 */
@property (nonatomic, strong) NSDictionary *dataRequestOptions;

//-----------------------------------------------------------------------------
// @name Annotations
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// @name Animation/Timeline
//-----------------------------------------------------------------------------

/**
 *  A Boolean that determines whether overlays can be animated on the weather map.
 *
 *	The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL animationEnabled;

/**
 *  The length of the animation in seconds.
 *
 *	The default value of this property is `2.0` seconds.
 */
@property (nonatomic, assign) NSTimeInterval animationDuration;

/**
 *  The number of seconds to hold the last frame of the animation before replaying from the beginning.
 *
 *	The default value of this property is `2.0` seconds.
 */
@property (nonatomic, assign) NSTimeInterval animationEndDelay;

/**
 *  A Boolean that determines whether image overlays should crossfade between intervals during animation playback.
 *
 *  The default value of this property is `NO`.
 */
@property (nonatomic, assign) BOOL animationCrossfadeEnabled;

/**
 *  The maximum number of images to request for an animation.
 *
 *	If the total number of images available within the animation's time range is greater than this value, the image intervals will
 *	be adjusted to be evenly spaced so that the total number of images never exceeds this value. Assigning a relative low value to this
 *	property will result in faster animation load times, whereas larger numbers will result in smoother animations for timelines
 *	with larger time ranges.
 *
 *	The default value of this property is `20`.
 */
@property (nonatomic, assign) NSInteger maximumIntervalsForAnimation;

/**
 *  The time interval offset to start the animation timeline relative to the current date and time, in seconds.
 *
 *	This value must be less than the value for `timelineEndOffsetFromNow`. A timeline with the same start and end
 *	time offsets will not animate.
 *
 *	The default value of this property is `-7200`, or `-2 * AWF_HOUR` (2 hours ago).
 */
@property (nonatomic, assign) NSTimeInterval timelineStartOffsetFromNow;

/**
 *  The time interval offset for the animation timeline to end relative to the current date and time, in seconds.
 *
 *	This value must be greater than the value for `timelineStartOffsetFromNow`. A timeline with the same start and end
 *	time offsets will not animate.
 *
 *	The default value of this property is `0` (current time).
 */
@property (nonatomic, assign) NSTimeInterval timelineEndOffsetFromNow;

/**
 *  Determines whether or not scrubbing the timeline also updates the active data layers.
 *
 *  If an animation has successfully loaded all data required for playback, scrubbing the timeline will result in smooth transitions between
 *  intervals. However, if animation data has not yet been loaded, then scrubbing the timeline will result in a choppy transition between intervals as
 *  the overlay is invalidated and redrawn at each interval. This applies to image and tile data layers only.
 */
@property (nonatomic, assign) BOOL timelineScrubbingEnabled;

//-----------------------------------------------------------------------------
// @name Long Press Gesture
//-----------------------------------------------------------------------------

/**
 *  A Boolean value that indicates whether the weather map should show the animated circle during a long press gesture on the map.
 */
@property (nonatomic, assign) BOOL showsAnnotationDuringLongPress;

/**
 *  A Boolean value that indicates whether the weather map should show an annotation on the map at the location of a long press gesture.
 */
@property (nonatomic, assign) BOOL showsAnnotationForLongPress;

/**
 *  The annotation style to use for the long press gesture when enabled.
 */
@property (nonatomic, strong) AWFAnnotationStyle *longPressAnnotationStyle;


//-----------------------------------------------------------------------------
// @name Mapbox Support
//-----------------------------------------------------------------------------

/**
 *  Mapbox map identifier to use as the base layer of the map. Only used when a weather map's `mapType` is set to `AWFWeatherMapTypeMapbox`.
 */
@property (nonatomic, strong) NSString *mapboxMapId;

/**
 *  Returns the style object to use when rendering the annotation on the map.
 *
 *  @param annotation The annotation to return the style for. This must be an object that conforms to the `AWFStyledAnnotation` protocol.
 *
 *  @return The style instance for the annotation
 */
- (AWFAnnotationStyle *)styleForAnnotation:(id<AWFStyledAnnotation>)annotation;

/**
 *  Returns the annotation style configuration for the given `layerType`.
 *
 *  The returned value may be an instance of `AWFMapItemStyle` or an `NSDictionary`. If an `NSDictionary` is returned, then styles are assigned by
 *  the annotation type they represent.
 *
 *  @param layerType The layer type to return the style configuration for
 *
 *  @return The annotation style configuration for the `layerType`
 */
- (id)annotationStyleConfigForLayerType:(AWFLayerType)layerType;

/**
 *  Returns the `AWFMapItemStyle` object to use when rendering the polygon on the map.
 *
 *  @param polygon The polygon to return the style for
 *
 *  @return The style instance for the polygon
 */
- (AWFMapItemStyle *)styleForPolygon:(id<AWFPolygon>)polygon;

/**
 *  Returns the polygon style configuration for the given `layerType`.
 *
 *  The returned value may be an instance of `AWFMapItemStyle` or an `NSDictionary`. If an `NSDictionary` is returned, then styles are assigned by
 *  the annotation type they represent.
 *
 *  @param layerType The layer type to return the style configuration for
 *
 *  @return The polygon style configuration for the `layerType`
 */
- (id)polygonStyleConfigForLayerType:(AWFLayerType)layerType;

/**
 *  Returns the `AWFMapItemStyle` object to use when rendering the overlay on the map.
 *
 *  @param overlay The overlay to return the style for
 *
 *  @return The style instance for the overlay
 */
- (AWFMapItemStyle *)styleForOverlay:(id<MKOverlay>)overlay;

/**
 *  Returns the overlay style configuration for the given `layerType`.
 *
 *  The returned value may be an instance of `AWFMapItemStyle` or an `NSDictionary`. If an `NSDictionary` is returned, then styles are assigned by
 *  the annotation type they represent.
 *
 *  @param layerType The layer type to return the style configuration for
 *
 *  @return The overlay style configuration for the `layerType`
 */
- (id)overlayStyleConfigForLayerType:(AWFLayerType)layerType;

/**
 *  Returns the request options to use when requesting data for the `layerType`.
 *
 *  @param layerType The layer type to return request options for
 *
 *  @return The request options for the layer type
 */
- (AWFRequestOptions *)requestOptionsForLayerType:(AWFLayerType)layerType;

- (NSString *)requestActionForLayerType:(AWFLayerType)layerType;

/**
 *  Returns the `AWFLegendStyle` object to use when drawing the legend for the `layerType`.
 *
 *  @param layerType The layer type to return the legend style for
 *
 *  @return The style instance for the layer type
 */
- (AWFLegendStyle *)legendStyleForLayerType:(AWFLayerType)layerType;


//-----------------------------------------------------------------------------
// @name Setting Layer Styles and Options
//-----------------------------------------------------------------------------

/**
 *  Sets the annotation style configuration for the given `layerType`.
 *
 *  The provided `style` value may either be an instance of `AWFMapItemStyle` or `NSDictionary`. If an `AWFMapItemStyle` is given, then all annotations
 *  for the layer type will be styled using the same configuration regardless of type or group. If an `NSDictionary` is given, then the dictionary must
 *  provide `AWFMapItemStyle` instances for the desired annotation type or group.
 *
 *  @param style     The style configuration as an `AWFMapItemStyle` or `NSDictionary`
 *  @param layerType The layer type to assign the style to
 */
- (void)setAnnotationStyle:(id)style forLayerType:(AWFLayerType)layerType;

/**
 *  Sets the overlay style configuration for the given 'layerType'.
 *
 *  The provided `style` value may either be an instance of `AWFMapItemStyle` or `NSDictionary`. If an `AWFMapItemStyle` is given, then all overlays
 *  for the layer type will be styled using the same configuration regardless of type or group. If an `NSDictionary` is given, then the dictionary must
 *  provide `AWFMapItemStyle` instances for the desired overlay type or group.
 *
 *  @param style     The style configuration as an `AWFMapItemStyle` or `NSDictionary`
 *  @param layerType The layer type to assign the style to
 */
- (void)setOverlayStyle:(id)style forLayerType:(AWFLayerType)layerType;

/**
 *  Sets the polygon style configuration for the given 'layerType`.
 *
 *  The provided `style` value may either be an instance of `AWFMapItemStyle` or `NSDictionary`. If an `AWFMapItemStyle` is given, then all polygons
 *  for the layer type will be styled using the same configuration regardless of type or group. If an `NSDictionary` is given, then the dictionary must
 *  provide `AWFMapItemStyle` instances for the desired polygon type or group.
 *
 *  @param style     The style configuration as an `AWFMapItemStyle` or `NSDictionary`
 *  @param layerType The layer type to assign the style to
 */
- (void)setPolygonStyle:(id)style forLayerType:(AWFLayerType)layerType;

/**
 *  Sets the legend style for the given `layerType`.
 *
 *  @param style     The `AWFLegendStyle` instance
 *  @param layerType The layer type to assign the legend style to
 */
- (void)setLegendStyle:(AWFLegendStyle *)style forLayerType:(AWFLayerType)layerType;

/**
 *  Sets the request options to use when requesting data for the given `layerType`. 
 *
 *  Request options are currently only supported for point and polygon data layers. Image and tile layers do not use request options when loading data.
 *
 *  @param options   The `AWFRequestOptions` instance
 *  @param layerType The layer type to assign the request options to
 */
- (void)setRequestOptions:(AWFRequestOptions *)options forLayerType:(AWFLayerType)layerType;

- (void)setRequestAction:(NSString *)action forLayerType:(AWFLayerType)layerType;

@end