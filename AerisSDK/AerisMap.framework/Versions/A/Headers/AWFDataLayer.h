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
 *  Initializes and returns the overlay object and associates it with the specified map strategy.
 *
 *  @param manager The map strategy object to use for managing the overlay.
 *
 *  @return An initialized overlay object.
 */
- (id)initWithStrategy:(id<AWFMapStrategy>)manager;

//------------------------
// @name Class Methods
//------------------------

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

+ (AWFLayerType)futureLayerTypeForType:(AWFLayerType)layerType forecastModel:(AWFForecastModelType)modelType;

@end
