//
//  AWFMapStrategy.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

/**
 *  The supported map strategy types.
 */
typedef NS_ENUM(NSUInteger, AWFMapStrategyType){
	/**
	 *  Apple Maps strategy type.
	 */
	AWFMapStrategyTypeApple = 0,
	/**
	 *  Google Maps strategy type. This requies the Google Maps iOS SDK linked with your project.
	 */
	AWFMapStrategyTypeGoogle,
	/**
	 *  MapBox strategy type.
	 */
	AWFMapStrategyTypeMapBox
};

@class AWFWeatherMap, AWFWeatherMapConfig, AWFDataLayer, AWFTileDataLayer, AWFMapStrategy, AWFCoordinateBounds;
@protocol AWFMapStrategyDelegate;

/**
 *  An `AWFMapStrategy` object provides a common interface between a specific map SDK and the application. This object
 *	is responsible for determining how to add and remove overlay and annotation objects on the map, as well as providing other
 *	basic information about the state of its internal map view, such as bounding coordinates, zoom level, etc.
 *
 *	The base implementation of this class doesn't do anything and should be subclassed for each supported map SDK. Subclasses should
 *	override the methods to manage adding and removing overlays and annotations from the map.
 *
 *	This object must remain the primary delegate of its internal map view regardless of map SDK since it manages all overlays. However,
 *	the same map delegates for the specific map SDK are also forwarded to the `mapViewDelegate` object when assigned.
 */
@protocol AWFMapStrategy <NSObject>
@required

/**
 *  The strategy type for the map strategy.
 */
@property (readonly, nonatomic) AWFMapStrategyType strategyType;

/**
 *  The map view being managed by the strategy.
 *
 *	The object returned by this property will depend on the type of map strategy and map SDK being used. For instance, {@link AWFAppleMapStrategy}
 *	will always return an instance of {@link MKMapView} for this property.
 */
@property (nonatomic, strong) id mapView;
@property (readonly, nonatomic, strong) AWFWeatherMapConfig *config;

/**
 *  Returns an array of overlays currently active on the strategy's map view (read-only).
 */
@property (nonatomic, strong, readonly) NSArray *overlays;

/**
 *  Returns an array of annotations currently active on the strategy's map view (read-only).
 */
@property (nonatomic, strong, readonly) NSArray *annotations;

/**
 *  Returns the current visible coordinate bounds of the strategy's map view (read-only).
 */
@property (nonatomic, readonly) AWFCoordinateBounds *coordinateBounds;

/**
 *  Returns the current center coordinate of the strategy's map view (read-only).
 */
@property (nonatomic, readonly) CLLocationCoordinate2D centerCoordinate;

/**
 *  Returns the current zoom level of the strategy's map view (read-only).
 */
@property (nonatomic, readonly) NSInteger zoomLevel;

@property (readonly, nonatomic, strong) id animationContainerView;
@property (readonly, nonatomic, strong) AWFCalloutView *calloutView;

/**
 *  The receiver's delegate.
 *
 *	The delegate should implement the methods of the `AWFMapStrategyDelegate` protocol.
 */
@property (nonatomic, weak) id<AWFMapStrategyDelegate> delegate;

/**
 *  The delegate that receives the standard map view delegate messages called by the specific map SDK.
 */
@property (nonatomic, weak) id mapViewDelegate;

/**
 *  Initializes and returns a map strategy associated with the specified weather map instance.
 *
 *  @param weatherMap The weather map instance associated with the map strategy.
 *
 *  @return An initialized map strategy.
 */
- (instancetype)initWithWeatherMap:(AWFWeatherMap *)weatherMap;

/**
 *  Adds a single overlay object to the map.
 *
 *  @param overlay The overlay object to add. This object can either be a subclass of `AWFOverlay` or a subclass of the
 *	overlay object expected by the specific map SDK being used.
 */
- (void)addOverlay:(id)overlay;

/**
 *  Adds an array of overlay objects to the map.
 *
 *  @param overlays The array of overlay objects to add. These objects can either be a subclass of `AWFOverlay` or a subclass of the
 *	overlay object expected by the specific map SDK being used.
 */
- (void)addOverlays:(NSArray *)overlays;

/**
 *  Inserts an overlay object on the map at the specified index.
 *
 *  @param overlay The overlay object to insert. This object can either be a subclass of `AWFOverlay` or a subclass of the
 *	overlay object expected by the specific map SDK being used.
 *  @param index   The index to which to insert the overlay object. If this value is greater than the number of overlays currently
 *	on the map, this method appends the object to the top of the overlays list.
 */
- (void)insertOverlay:(id)overlay atIndex:(NSUInteger)index;

/**
 *  Removes a single overlay object from the map.
 *
 *  @param overlay The overlay object to remove. This object can either be a subclass of `AWFOverlay` or a subclass of the
 *	overlay object expected by the specific map SDK being used.
 */
- (void)removeOverlay:(id)overlay;

/**
 *  Removes an array of overlay objects from the map.
 *
 *  @param overlays The overlay objects to remove. These objects can either be a subclass of `AWFOverlay` or a subclass of the
 *	overlay object expected by the specific map SDK being used.
 */
- (void)removeOverlays:(NSArray *)overlays;

/**
 *  Returns the index of the overlay object in the overlays list on the map.
 *
 *  @param overlay The overlay object to return the index for. This object can either be a subclass of `AWFOverlay` or a subclass of the
 *	overlay object expected by the specific map SDK being used.
 *
 *  @return The index of the overlay object in the overlays list, or `-1` if the overlay object is not on the map (in the overlays list).
 */
- (NSInteger)indexForOverlay:(id)overlay;

/**
 *  Forces an overlay to be reloaded and displayed.
 *
 *  @param overlay The overlay object whose content you want to draw.
 */
- (void)invalidateOverlay:(id)overlay;

/**
 *  Forces an array of overlays to be reloaded and displayed.
 *
 *  @param overlays An array of overlay objects whose contents you want to draw.
 */
- (void)invalidateOverlays:(NSArray *)overlays;


- (NSArray *)overlaysFromObjects:(NSArray *)objects;

/**
 *  Returns an array of polygon overlay objects for a series of `AWFGeographicObject` instances. These objects must have a valid polygon string or `AWFGeoPolygon` 
 *  instance in order for a polygon to be created for it.
 *
 *  @param objects An array of `AWFGeographicObject` instances to create polygon overlays for
 *
 *  @return An array of polygon objects
 */
- (NSArray *)polygonsFromObjects:(NSArray *)objects;

/**
 *  Returns an array of polygon overlay objects for a series of `AWFGeoPolygon` instances.
 *
 *  @param geoPolygons An array of `AWFGeoPolygon` objects to create polygon overlays for
 *
 *  @return An array of polygon objects
 */
- (NSArray *)polygonsFromGeoPolygons:(NSArray *)geoPolygons;

/**
 *  Returns an array of polyline overlay objects for a series of `AWFGeoPolygon` instances.
 *
 *  @param geoPolygons An array of `AWFGeoPolygon` objects to create polyline overlays for
 *
 *  @return An array of polyline objects
 */
- (NSArray *)polylinesFromGeoPolygons:(NSArray *)geoPolygons;

/**
 *  Returns a single overlay object that conforms to the `AWFMultiShapeOverlay` protocol for managing and rendering multiple polygons and polylines into
 *  a single overlay renderer.
 *
 *  @param polygons  An array of polygons to add to the overlay.
 *  @param polylines An array of polylines to add to the overlay.
 *
 *  @return The multi-shape overlay instance
 */
- (id)combinedOverlayForPolygons:(NSArray *)polygons polylines:(NSArray *)polylines;

/**
 *  Iterates through an array of polygon objects and returns an array of polygon overlays that the strategy's map view requires when adding to the map. This 
 *  method will pull out the overlay instances stored within `AWFPolygon` and `AWFPolyline` objects in order to add them to the map view.
 *
 *  @param polygons An array of polygon objects.
 *
 *  @return An array of polygon overlay instances that can be added to the map view.
 */
- (NSArray *)reducePolygonsToMapPolygons:(NSArray *)polygons;

/**
 *  Returns a tile data layer initialized with the `URLTemplate` to use for tile URLs.
 *
 *  @param URLTemplate The template for generating tile URLs.
 *
 *  @return An initialized tile data layer object.
 */
- (AWFTileDataLayer *)tileOverlayWithURLTemplate:(NSString *)URLTemplate;

//-----------------------------------------------------------------------------
// @name Managing Annotations
//-----------------------------------------------------------------------------

/**
 *  Adds an array of annotations to the map.
 *
 *  @param annotations The array of annotations to add. These objects can either be a subclass of `AWFAnnotation` or a subclass of the
 *	annotation object expected by the specific map SDK being used.
 */
- (void)addAnnotations:(NSArray *)annotations;

/**
 *  Removes an array of annotation from the map.
 *
 *  @param annotations The array of annotations to remove. These objects can either be a subclass of `AWFAnnotation` or a subclass of the
 *	annotation object expected by the specific map SDK being used.
 */
- (void)removeAnnotations:(NSArray *)annotations;

/**
 *  Returns an array of annotation objects for a series of `AWFGeographicObject` instances. These objects must have a valid coordinate in order for an
 *  annotation to be created for it.
 *
 *  @param objects An array of `AWFGeographicObject` instances to create annotations for
 *
 *  @return An array of annotation objects
 */
- (NSArray *)annotationsFromObjects:(NSArray *)objects;

- (void)selectAnnotation:(id)annotation;
- (void)deselectCurrentlySelectedAnnotation;

/**
 *  Presents the map callout from the `annotation` using the specified `title` and `subtitle`.
 *
 *  @param annotation The annotation from which to present the callout.
 *  @param title      The primary textual content.
 *  @param subtitle   The secondary textual content. If not provided, the title will only be displayed.
 */
- (void)showCalloutFromAnnotation:(id)annotation withTitle:(NSString *)title subtitle:(NSString *)subtitle;

/**
 *  Presents the map callout from the `annotation` using the specified `contentView`.
 *
 *  @param annotation  The annotation from which to present the callout.
 *  @param contentView The view to display within the callout.
 */
- (void)showCalloutFromAnnotation:(id)annotation withContentView:(UIView *)contentView;

/**
 *  Presents the map callout from the `coordinate` using the specified `title` and `subtitle`.
 *
 *  @param coordinate The map coordinate from which to present the callout.
 *  @param title      The primary textual content.
 *  @param subtitle   The secondary textual content. If not provided, the title will only be displayed.
 */
- (void)showCalloutAtCoordinate:(CLLocationCoordinate2D)coordinate withTitle:(NSString *)title subtitle:(NSString *)subtitle;
- (void)showCalloutAtCoordinate:(CLLocationCoordinate2D)coordinate withTitle:(NSString *)title subtitle:(NSString *)subtitle leftAccessoryView:(UIView *)leftAccessoryView rightAccessoryView:(UIView *)rightAccessoryView;

/**
 *  Presents the map callout from the `coordinate` using the specified `contentView`.
 *
 *  @param coordinate  The map coordinate from which to present the callout.
 *  @param contentView The view to display within the callout.
 */
- (void)showCalloutAtCoordinate:(CLLocationCoordinate2D)coordinate withContentView:(UIView *)contentView;
- (void)showCalloutAtCoordinate:(CLLocationCoordinate2D)coordinate withContentView:(UIView *)contentView leftAccessoryView:(UIView *)leftAccessoryView rightAccessoryView:(UIView *)rightAccessoryView;

/**
 *  Adds the annotation on the map for the long press gesture.
 *
 *  @param coordinate The coordinate at which to add the annotation.
 */
- (void)showAnnotationForLongPressAtCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 *  Dismisses the active callout, if any, from the map.
 */
- (void)dismissCalloutAnimated:(BOOL)animated;

/**
 *  Removes the annotation for the long press gesture from the map.
 *
 *  @param animated `YES` if the removal should be animated, otherwise `NO` and the annotation will be removed immediately.
 */
- (void)removeAnnotationForLongPress:(BOOL)animated;

//-----------------------
// @name Utilities
//-----------------------

/**
 *  Changes the center coordinate of the map and optionally animates the change.
 *
 *  @param centerCoordinate The new center coordinate for the map.
 *  @param animated         Specify `YES` if you want the map view to scroll to the new location or `NO` if you want the map to display the new location immediately.
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate animated:(BOOL)animated;

/**
 *  Changes the center coordinate and zoom level of the map and optionally animates the change.
 *
 *  @param centerCoordinate The new center coordinate for the map.
 *  @param zoomLevel        The new zoom level for the map.
 *  @param animated         Specify `YES` if you want the map view to scroll to the new location or `NO` if you want the map to display the new location immediately.
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate zoomLevel:(NSUInteger)zoomLevel animated:(BOOL)animated;

/**
 *  Converts a map coordinate to a point in the specified view.
 *
 *  @param coord The map coordinate for which you want to find the corresponding point.
 *  @param view  The view in whose coordinate system you want to locate the specified map coordinate. If this parameter is `nil`, the
 *	returned point is specified in the window's coordinate system.
 *
 *  @return The point in the specified view or window coordinate system corresponding to the specified latitude and longitude value.
 */
- (CGPoint)pointForCoordinate:(CLLocationCoordinate2D)coord inView:(UIView *)view;

/**
 *  Converts a point in the specified view's coordinate system to a map coordinate.
 *
 *  @param point The point you want to convert.
 *  @param view  The view that serves as the reference coordinate system for the <i>point</i> parameter.
 *
 *  @return The map coordinate at the specified point.
 */
- (CLLocationCoordinate2D)coordinateForPoint:(CGPoint)point inView:(UIView *)view;

/**
 *  Returns a Boolean value indicating if the specified coordinate falls within the bounds of the `polygon` overlay.
 *
 *  @param coord   The coordinate to test.
 *  @param polygon The polygon overlay to determine if the coordinate falls within
 *
 *  @return `YES` if the coordinate is contained within the polygon, otherwise `NO`.
 */
- (BOOL)isCoordinate:(CLLocationCoordinate2D)coord withinPolygon:(id)polygon;

/**
 *  Forwards a tap gesture to the map strategy in order to determine if an overlay was tapped on the map.
 *
 *  @param touchPoint The point that was tapped on the map.
 *  @param view       The view in which the tap gesture occurred.
 */
- (void)forwardTouchAtPoint:(CGPoint)touchPoint inView:(UIView *)view;

@end


/**
 *  The `AWFMapStrategyDelegate` protocol defines a set of optional methods that you can use to receive messages
 *	related to the internal map view being managed by a map strategy.
 */
@protocol AWFMapStrategyDelegate <NSObject>
@optional

/**
 *  Tells the delegate that the map view is about to change its visible region.
 *
 *  @param strategy The map strategy managing the map view.
 *  @param bounds   The visible bounds of the map view before the region change.
 */
- (void)mapStrategy:(id<AWFMapStrategy>)strategy regionWillChangeFromBounds:(AWFCoordinateBounds *)bounds;

/**
 *  Tells the delegate that the map view has changed its visible region.
 *
 *  @param strategy The map strategy managing the map view.
 *  @param bounds   The visible bounds of the map view after the region change.
 */
- (void)mapStrategy:(id<AWFMapStrategy>)strategy regionDidChangeToBounds:(AWFCoordinateBounds *)bounds;

/**
 *  Tells the delegate that a polygon overlay was tapped on the map.
 *
 *  @param strategy   The map strategy managing the map view.
 *  @param polygon    The polygon overlay that was tapped.
 *  @param coordinate The map coordinate at which the tap was detected.
 */
- (void)mapStrategy:(id<AWFMapStrategy>)strategy didTapPolygon:(id)polygon atCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 *  Tells the delegate that an overlay was added to the map view.
 *
 *  @param strategy The map strategy that added the overlay.
 *  @param overlay  The overlay that was added.
 */
- (void)mapStrategy:(id<AWFMapStrategy>)strategy didAddOverlay:(id)overlay;

@end
