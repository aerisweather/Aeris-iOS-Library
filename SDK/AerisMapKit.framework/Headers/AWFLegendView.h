//
//  AWFLegendView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/29/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisMapKit/AWFWeatherLayer.h>

typedef NS_ENUM(NSInteger, AWFWeatherMapLegendPosition) {
	AWFWeatherMapLegendPositionTop = 0,
	AWFWeatherMapLegendPositionBottom
};

@class AWFLegendItemView;
@class AWFWeatherMapStyle;
@class AWFMapCoordinateBounds;

/**
 `AWFLegendView` is a container view used for managing and displaying multiple `AWFLegendItemView` instances for a weather map.
 */
@interface AWFLegendView : UIView

/**
 An array of `AWFLegendItemView` instances currently displayed.
 */
@property (readonly, nonatomic, strong) NSArray<AWFLegendItemView *> *legends;

/**
 The text style to apply to the legend row title labels.
 */
@property (nonatomic, strong) AWFTextStyleSpec *titleTextStyle;

/**
 The text style to apply to the legends, which controls legend value labels and titles.
 */
@property (nonatomic, strong) AWFTextStyleSpec *legendTextStyle;

/**
 A Boolean value indicating whether the legend view should display the legends with Metric values when applicable.
 */
@property (nonatomic, assign, getter=isMetric) BOOL metric;

/**
 The padding to use around the legend views relative to the view's bounds.
 */
@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;

/**
 The outer margins for the container view.
 */
@property (nonatomic, assign) UIEdgeInsets outerEdgeInsets;

/**
 The position orientation of the view relative to its superview, which controls where the expand/collapse button and indicator are positioned.
 */
@property (nonatomic, assign) AWFWeatherMapLegendPosition position;

/**
 The button used to toggle the view's visibility and expand/collapse state.
 */
@property (readonly, nonatomic, strong) UIButton *toggleButton;

/**
 A Boolean value indicating whether the view should show the close arrow indicator on the `toggleButton`. Default is `YES`.
 */
@property (nonatomic, assign) BOOL showsCloseIndicator;

/**
 Initializes and returns a newly allocated `AWFWeatherMapLegendView` associated with the specified weather map's `config`.
 
 @param style The weather map style
 @param frame  The initial frame for the view
 @return An initialized `AWFWeatherMapLegendView`, or `nil` if one couldn't be created
 */
- (instancetype)initWithMapStyle:(AWFWeatherMapStyle *)style frame:(CGRect)frame;

/**
 Adds an legend view for the specified layer type.
 
 @param layerType The layer type code to add a legend for
 */
- (void)addLegendForLayerType:(AWFMapLayer)layerType;

/**
 Removes the legend view for the specified layer type.
 
 @param layerType The layer type code to remove the legend for
 */
- (void)removeLegendForLayerType:(AWFMapLayer)layerType;

/**
 A Boolean value indicating whether a legend is currently displayed for the specified layer type.
 
 @param layerType The layer type code to check
 @return `YES` if the legend exists, otherwise `NO`.
 */
- (BOOL)hasLegendForLayerType:(AWFMapLayer)layerType;

/**
 Shows or hides the view, which is either expanded or collapsed respectively.
 
 @param show A Boolean indiciating whether to show the view
 @param animated A Boolean indicating whether the action should be animated
 */
- (void)show:(BOOL)show animated:(BOOL)animated;

/**
 Tells the legend view to update any legend item views that require updating when a map's coordinate bounds have changed, such as updating an advisories
 legend to only show active advisories within a specific region.

 @param bounds The coordinate bounds to use when updating.
 */
- (void)updateItemsForMapBoundsIfNeeded:(AWFMapCoordinateBounds *)bounds;

@end
