//
//  AWFMapStrategy.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFMapOverlayFactory.h>
#import <AerisMapKit/AWFAnnotation.h>
#import <AerisMapKit/AWFMapCallout.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The supported weather map strategy types.

 - AWFMapStrategyTypeApple: Apple Maps strategy type.
 - AWFMapStrategyTypeGoogle: Google Maps strategy type. This type requires the Google Maps iOS SDK linked with your project.
 - AWFMapStrategyTypeMapBox: Mapbox strategy type. This type requires the Mapbox GL iOS SDK linked with your project.
 */
typedef NS_ENUM(NSUInteger, AWFMapStrategyType){
	AWFMapStrategyTypeApple = 0,
	AWFMapStrategyTypeGoogle,
	AWFMapStrategyTypeMapBox
};

@class AWFWeatherMap, AWFWeatherMapConfig;
@class AWFMapContentSource, AWFTileSource, AWFMapStrategy, AWFMapCoordinateBounds;
@class AWFMapCallout;

@protocol AWFMapStrategyDelegate;

/**
 An `AWFMapStrategy` object provides a common interface between a specific map SDK and the application. This object
 is responsible for determining how to add and remove overlay and annotation objects on the map, as well as providing other
 basic information about the state of its internal map view, such as bounding coordinates, zoom level, etc.
 
 The base implementation of this class doesn't do anything and should be subclassed for each supported map SDK. Subclasses should
 override the methods to manage adding and removing overlays and annotations from the map.
 
 This object must remain the primary delegate of its internal map view regardless of map SDK since it manages all overlays. However,
 the same map delegates for the specific map SDK are also forwarded to the `mapViewDelegate` object when assigned.
 */
@protocol AWFMapStrategy <NSObject>
@required

/**
 The strategy type for the map strategy.
 */
@property (readonly, nonatomic) AWFMapStrategyType strategyType;

/**
 The map view being managed by the strategy.
 
 The object returned by this property will depend on the type of map strategy and map SDK being used. For instance, {@link AWFAppleMapStrategy}
 will always return an instance of {@link MKMapView} for this property.
 */
@property (nonatomic, strong) UIView *mapView;

/**
 The weather map configuration associated with the weather map.
 */
@property (readonly, nonatomic, strong) AWFWeatherMapConfig *config;

/**
 The factory object responsible for generating the map overlays and annotations required by the specific map strategy.
 */
@property (readonly, nonatomic, strong) id<AWFMapOverlayFactory> overlayFactory;

/**
 The map callout used for presenting data for a specific point or region on the map.
 */
@property (readonly, nonatomic, strong) AWFMapCallout *callout;

/**
 Returns an array of overlays currently active on the strategy's map view (read-only).
 */
@property (nonatomic, strong, readonly) NSArray *overlays;

/**
 Returns an array of annotations currently active on the strategy's map view (read-only).
 */
@property (nonatomic, strong, readonly) NSArray *annotations;

/**
 Returns the current visible coordinate bounds of the strategy's map view (read-only).
 */
@property (nonatomic, readonly) AWFMapCoordinateBounds *coordinateBounds;

/**
 Returns the current center coordinate of the strategy's map view (read-only).
 */
@property (nonatomic, readonly) CLLocationCoordinate2D centerCoordinate;

/**
 Returns the current zoom level of the strategy's map view (read-only).
 */
@property (nonatomic, readonly) NSInteger zoomLevel;

/**
 The internal view used for rendering animated tile and image data.
 */
@property (readonly, nonatomic, strong) id animationContainerView;

/**
 The receiver's delegate.
 
 The delegate should implement the methods of the `AWFMapStrategyDelegate` protocol.
 */
@property (nonatomic, unsafe_unretained) id<AWFMapStrategyDelegate> delegate;

/**
 The delegate that receives the standard map view delegate messages called by the specific map SDK.
 */
@property (nonatomic, unsafe_unretained) id mapViewDelegate;

/**
 Initializes and returns a map strategy associated with the specified weather map instance.
 
 @param weatherMap The weather map instance associated with the map strategy.
 @return An initialized map strategy.
 */
- (instancetype)initWithWeatherMap:(AWFWeatherMap *)weatherMap;

/**
 Adds a single overlay object to the map.
 
 @param overlay The overlay object to add. This object can either be a subclass of `AWFOverlay` or a subclass of the
 overlay object expected by the specific map SDK being used.
 */
- (void)addOverlay:(id)overlay;

/**
 Adds an array of overlay objects to the map.
 
 @param overlays The array of overlay objects to add. These objects can either be a subclass of `AWFOverlay` or a subclass of the
 overlay object expected by the specific map SDK being used.
 */
- (void)addOverlays:(NSArray *)overlays;

/**
 Inserts an overlay object on the map at the specified index.
 
 @param overlay The overlay object to insert. This object can either be a subclass of `AWFOverlay` or a subclass of the
 overlay object expected by the specific map SDK being used.
 @param index   The index to which to insert the overlay object. If this value is greater than the number of overlays currently
 on the map, this method appends the object to the top of the overlays list.
 */
- (void)insertOverlay:(id)overlay atIndex:(NSUInteger)index;

/**
 Removes a single overlay object from the map.
 
 @param overlay The overlay object to remove. This object can either be a subclass of `AWFOverlay` or a subclass of the
 overlay object expected by the specific map SDK being used.
 */
- (void)removeOverlay:(id)overlay;

/**
 Removes an array of overlay objects from the map.
 
 @param overlays The overlay objects to remove. These objects can either be a subclass of `AWFOverlay` or a subclass of the
 overlay object expected by the specific map SDK being used.
 */
- (void)removeOverlays:(NSArray *)overlays;

/**
 Returns the index of the overlay object in the overlays list on the map.
 
 @param overlay The overlay object to return the index for. This object can either be a subclass of `AWFOverlay` or a subclass of the
 overlay object expected by the specific map SDK being used.
 @return The index of the overlay object in the overlays list, or `-1` if the overlay object is not on the map (in the overlays list).
 */
- (NSInteger)indexForOverlay:(id)overlay;

/**
 Forces an overlay to be reloaded and displayed.
 
 @param overlay The overlay object whose content you want to draw.
 */
- (void)invalidateOverlay:(id)overlay;

/**
 Forces an array of overlays to be reloaded and displayed.
 
 @param overlays An array of overlay objects whose contents you want to draw.
 */
- (void)invalidateOverlays:(NSArray *)overlays;

//-----------------------------------------------------------------------------
// @name Managing Annotations
//-----------------------------------------------------------------------------

/**
 Adds an annotation to the map.
 */
- (void)addAnnotation:(id<AWFAnnotation>)annotation;

/**
 Adds an array of annotations to the map.
 
 @param annotations The array of annotations to add. These objects should adopt the `AWFAnnotation` protocol and be a subclass instance of the
 annotation object expected by the specific map SDK being used.
 */
- (void)addAnnotations:(NSArray<id<AWFAnnotation>> *)annotations;

/**
 Removes an annotation from the map.
 */
- (void)removeAnnotation:(id<AWFAnnotation>)annotation;

/**
 Removes an array of annotation from the map.
 
 @param annotations The array of annotations to remove. These objects should adopt the `AWFAnnotation` protocol and be a subclass instance of the
 annotation object expected by the specific map SDK being used.
 */
- (void)removeAnnotations:(NSArray<id<AWFAnnotation>> *)annotations;

/**
 Selects the specified `annotation`.
 
 @param annotation The annotation to select
 */
- (void)selectAnnotation:(id<AWFAnnotation>)annotation;

/**
 Selects the specified `annotation`.

 @param annotation The annotation to select
 @param animated Whether the selection should be animated.
 */
- (void)selectAnnotation:(id<AWFAnnotation>)annotation animated:(BOOL)animated;

/**
 Deselects the specified `annotation`.

 @param annotation The annotation to deselect.
 */
- (void)deselectAnnotation:(id<AWFAnnotation>)annotation;

/**
 Deselects the specified `annotations`

 @param annotation The annotation to deselect.
 @param animated Whether the deselection should be animated.
 */
- (void)deselectAnnotation:(id<AWFAnnotation>)annotation animated:(BOOL)animated;

/**
 Deselects any currently selected annotation, if any.
 */
- (void)deselectCurrentlySelectedAnnotation;

/**
 Adds the annotation on the map for the long press gesture.
 
 @param coordinate The coordinate at which to add the annotation.
 */
- (void)showAnnotationForLongPressAtCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 Removes the annotation for the long press gesture from the map.
 
 @param animated `YES` if the removal should be animated, otherwise `NO` and the annotation will be removed immediately.
 */
- (void)removeAnnotationForLongPress:(BOOL)animated;

//-----------------------------------------------------------------------------
// @name Utilities
//-----------------------------------------------------------------------------

/**
 Changes the center coordinate of the map and optionally animates the change.
 
 @param centerCoordinate The new center coordinate for the map.
 @param animated         Specify `YES` if you want the map view to scroll to the new location or `NO` if you want the map to display the new location immediately.
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate animated:(BOOL)animated;

/**
 Changes the center coordinate and zoom level of the map and optionally animates the change.
 
 @param centerCoordinate The new center coordinate for the map.
 @param zoomLevel        The new zoom level for the map.
 @param animated         Specify `YES` if you want the map view to scroll to the new location or `NO` if you want the map to display the new location immediately.
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate zoomLevel:(NSUInteger)zoomLevel animated:(BOOL)animated;

/**
 Converts a map coordinate to a point in the specified view.
 
 @param coord The map coordinate for which you want to find the corresponding point.
 @param view  The view in whose coordinate system you want to locate the specified map coordinate. If this parameter is `nil`, the
 returned point is specified in the window's coordinate system.
 @return The point in the specified view or window coordinate system corresponding to the specified latitude and longitude value.
 */
- (CGPoint)pointForCoordinate:(CLLocationCoordinate2D)coord inView:(nullable UIView *)view;

/**
 Converts a point in the specified view's coordinate system to a map coordinate.
 
 @param point The point you want to convert.
 @param view  The view that serves as the reference coordinate system for the *point* parameter.
 @return The map coordinate at the specified point.
 */
- (CLLocationCoordinate2D)coordinateForPoint:(CGPoint)point inView:(nullable UIView *)view;

/**
 Returns a Boolean value indicating if the specified coordinate falls within the bounds of the `polygon` overlay.
 
 @param coord   The coordinate to test.
 @param polygon The polygon overlay to determine if the coordinate falls within
 @return `YES` if the coordinate is contained within the polygon, otherwise `NO`.
 */
- (BOOL)isCoordinate:(CLLocationCoordinate2D)coord withinPolygon:(id)polygon;

/**
 Forwards a tap gesture to the map strategy in order to determine if an overlay was tapped on the map.
 
 @param touchPoint The point that was tapped on the map.
 @param view       The view in which the tap gesture occurred.
 */
- (void)forwardTouchAtPoint:(CGPoint)touchPoint inView:(UIView *)view;

@end


/**
 The `AWFMapStrategyDelegate` protocol defines a set of optional methods that you can use to receive messages
 related to the internal map view being managed by a map strategy.
 */
@protocol AWFMapStrategyDelegate <NSObject>
@optional

/**
 Tells the delegate that the map view is about to change its visible region.
 
 @param strategy The map strategy managing the map view.
 @param bounds   The visible bounds of the map view before the region change.
 */
- (void)mapStrategy:(id<AWFMapStrategy>)strategy regionWillChangeFromBounds:(AWFMapCoordinateBounds *)bounds;

/**
 Tells the delegate that the map view has changed its visible region.
 
 @param strategy The map strategy managing the map view.
 @param bounds   The visible bounds of the map view after the region change.
 */
- (void)mapStrategy:(id<AWFMapStrategy>)strategy regionDidChangeToBounds:(AWFMapCoordinateBounds *)bounds;

/**
 Tells the delegate that a polygon overlay was tapped on the map.
 
 @param strategy   The map strategy managing the map view.
 @param polygon    The polygon overlay that was tapped.
 @param coordinate The map coordinate at which the tap was detected.
 */
- (void)mapStrategy:(id<AWFMapStrategy>)strategy didTapPolygon:(id)polygon atCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 Tells the delegate that an overlay was added to the map view.
 
 @param strategy The map strategy that added the overlay.
 @param overlay  The overlay that was added.
 */
- (void)mapStrategy:(id<AWFMapStrategy>)strategy didAddOverlay:(id)overlay;

/**
 Tells the delegate that the map's callout is about to be displayed for a selected annotation, allowing the delegate to prepare the map for any map region
 changes that may occur to accomodate the callout's view.

 @param strategy The map strategy that is managing the callout.
 */
- (void)mapStrategyWillDisplayCallout:(id<AWFMapStrategy>)strategy;

@end

NS_ASSUME_NONNULL_END
