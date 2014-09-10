//
//  AWFMapStrategy.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

typedef NS_ENUM(NSUInteger, AWFMapStrategyType) {
	AWFMapStrategyTypeApple = 0,
	AWFMapStrategyTypeGoogle,
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

@property (readonly, nonatomic) AWFMapStrategyType strategyType;

/**
 *  The map view being managed by the strategy.
 *
 *	The object returned by this property will depend on the type of map strategy and map SDK being used. For instance, {@link AWFAppleMapStrategy}
 *	will always return an instance of {@link MKMapView} for this property.
 */
@property (nonatomic, strong) id mapView;
@property (readonly, nonatomic, strong) AWFWeatherMapConfig *config;
@property (nonatomic, strong, readonly) NSArray *overlays;
@property (nonatomic, strong, readonly) NSArray *annotations;
@property (nonatomic, readonly) AWFCoordinateBounds *coordinateBounds;
@property (nonatomic, readonly) CLLocationCoordinate2D centerCoordinate;

@property (readonly, nonatomic, strong) id animationContainerView;

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

- (void)invalidateOverlay:(id)overlay;
- (void)invalidateOverlays:(NSArray *)overlays;

- (NSArray *)overlaysFromObjects:(NSArray *)objects;
- (NSArray *)polygonsFromObjects:(NSArray *)objects;
- (NSArray *)polygonsFromGeoPolygons:(NSArray *)geoPolygons;
- (NSArray *)polylinesFromGeoPolygons:(NSArray *)geoPolygons;
- (id)combinedOverlayForPolygons:(NSArray *)polygons polylines:(NSArray *)polylines;
- (NSArray *)reducePolygonsToMapPolygons:(NSArray *)polygons;
- (AWFTileDataLayer *)tileOverlayWithURLTemplate:(NSString *)URLTemplate;

//-----------------------------------------------------------------------------
// @name Managing Annotations
//-----------------------------------------------------------------------------
- (void)addAnnotations:(NSArray *)annotations;
- (void)removeAnnotations:(NSArray *)annotations;
- (NSArray *)annotationsFromObjects:(NSArray *)objects;


- (void)showCalloutFromAnnotation:(id)annotation withTitle:(NSString *)title subtitle:(NSString *)subtitle;
- (void)showCalloutFromAnnotation:(id)annotation withContentView:(UIView *)contentView;
- (void)showCalloutAtCoordinate:(CLLocationCoordinate2D)coordinate withTitle:(NSString *)title subtitle:(NSString *)subtitle;
- (void)showCalloutAtCoordinate:(CLLocationCoordinate2D)coordinate withContentView:(UIView *)contentView;
- (void)showAnnotationForLongPressAtCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)removeAnnotationForLongPress:(BOOL)animated;

//-----------------------
// @name Utilities
//-----------------------

- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate animated:(BOOL)animated;
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

- (BOOL)isCoordinate:(CLLocationCoordinate2D)coord withinPolygon:(id)polygon;
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

- (void)mapStrategy:(id<AWFMapStrategy>)strategy didTapPolygon:(id)polygon atCoordinate:(CLLocationCoordinate2D)coordinate;

- (void)mapStrategy:(id<AWFMapStrategy>)strategy didAddOverlay:(id)overlay;

@end
