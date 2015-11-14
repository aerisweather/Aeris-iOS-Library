//
//  AWFOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>

#import "AWFMapStrategy.h"
#import "AWFLayerType.h"

@protocol AWFDataLayerDelegate;

/**
 *  An `AWFOverlay` object is the base class that represents an layer type on a map. This base class should not be 
 *	used directly. Instead, `AWFOverlay` subclasses should be used to provide the necessary functionality for that
 *	layer type.
 */
@interface AWFDataLayer : NSObject

/**
 *  The {@link AWFLayerType} of the overlay.
 */
@property (nonatomic, assign) AWFLayerType layerType;

/**
 *  The amount of transparency to apply to the overlay.
 */
@property (nonatomic, assign) CGFloat alpha;

/**
 *  The map strategy that is managing the overlay.
 */
@property (readonly, nonatomic, strong) id<AWFMapStrategy> strategy;;

/**
 *	The coordinate bounds currently covered by the overlay.
 */
@property (nonatomic, strong) AWFCoordinateBounds *visibleBounds;

/**
 *  The receiver's delegate.
 */
@property (nonatomic, assign) id<AWFDataLayerDelegate> delegate;

/**
 *  Initializes and returns the overlay object and associates it with the specified map strategy.
 *
 *  @param manager The map strategy object to use for managing the overlay.
 *
 *  @return An initialized overlay object.
 */
- (id)initWithStrategy:(id<AWFMapStrategy>)manager;

//-----------------------------------------------------------------------------
// @name Class Methods
//-----------------------------------------------------------------------------

/**
 *  Returns a dictionary that maps each {@link AWFLayerType} to its corresponding data code.
 */
+ (NSDictionary *)typeMapping;

/**
 *  Returns a dictionary that maps each {@link AWFLayerType} to its display name.
 */
+ (NSDictionary *)names;

/**
 *  Returns a dictionary maps each combined tile {@link AWFLayerType} to an array of individual layer types used in the combined type.
 */
+ (NSDictionary *)combinedLayerTypes;

/**
 *  Returns an array of layer types that the combined layer type contains.
 *
 *  @param layerType The {@link AWFLayerType} that combines multiple individual layer types.
 *
 *  @return The array of individual layer types.
 */
+ (NSArray *)layerTypesForCombinedLayerType:(AWFLayerType)layerType;

/**
 *  A Boolean indicating whether or not the specified `layerType` is included in the `combinedLayerType`.
 *
 *  @param layerType         The layer type to check for
 *  @param combinedLayerType The combined layer type to check
 *
 *  @return `YES` if `layerType` is included in `combinedLayerType`, otherwise `NO`
 */
+ (BOOL)isLayerType:(AWFLayerType)layerType includedInCombinedLayerType:(AWFLayerType)combinedLayerType;

/**
 *  Returns the `AWFLayerType` associated with the specified `layerType` and `modelType`.
 *
 *  @param layerType The layer type to use
 *  @param modelType The model type to use
 *
 *  @return The `AWFLayerType` for the `layerType` and `modelType`
 */
+ (AWFLayerType)futureLayerTypeForType:(AWFLayerType)layerType forecastModel:(AWFForecastModelType)modelType;

@end


@protocol AWFDataLayerDelegate <NSObject>

@optional

/**
 *  Tells the delegate that the data layer will remove an array of annotation from the map. This is called before the `annotations` property on the data layer will be reset with a new value.
 *
 *  @param dataLayer   The data layer that will remove annotations
 *  @param annotations An array of annotations that will be removed
 */
- (void)dataLayer:(AWFDataLayer *)dataLayer willRemoveAnnotations:(NSArray *)annotations;

/**
 *  Tells the delegate that the data layer will remove an array of overlays from the map. This is called before the `overlays` property on the data layer will be reset with a new value.
 *
 *  @param dataLayer The data layer that will remove overlays
 *  @param overlays  An array of overlays that will be removed
 */
- (void)dataLayer:(AWFDataLayer *)dataLayer willRemoveOverlays:(NSArray *)overlays;

@end
