//
//  AWFWeatherMapLegendView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/29/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisMap/AWFLayerType.h>

typedef NS_ENUM(NSInteger, AWFWeatherMapLegendPosition) {
	AWFWeatherMapLegendPositionTop = 0,
	AWFWeatherMapLegendPositionBottom
};

@class AWFWeatherMapConfig;

/**
 *  `AWFWeatherMapLegendView` is a container view used for managing and displaying multiple `AWFLegendView` instances for a weather map.
 */
@interface AWFWeatherMapLegendView : UIView

/**
 *  An array of `AWFLegendView` instances currently displayed.
 */
@property (readonly, nonatomic, strong) NSArray *legends;

/**
 *  The padding to use around the legend views relative to the view's bounds.
 */
@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;

/**
 *  The outer margins for the container view.
 */
@property (nonatomic, assign) UIEdgeInsets outerEdgeInsets;

/**
 *  The position orientation of the view relative to its superview, which controls where the expand/collapse button and indicator are positioned.
 */
@property (nonatomic, assign) AWFWeatherMapLegendPosition position;

/**
 *  The button used to toggle the view's visibility and expand/collapse state.
 */
@property (readonly, nonatomic, strong) UIButton *toggleButton;

/**
 *  A Boolean value indicating whether the view should show the close arrow indicator on the `toggleButton`. Default is `YES`.
 */
@property (nonatomic, assign) BOOL showsCloseIndicator;

/**
 *  Initializes and returns a newly allocated `AWFWeatherMapLegendView` associated with the specified weather map's `config`.
 *
 *  @param config The weather map config
 *  @param frame  The initial frame for the view
 *
 *  @return An initialized `AWFWeatherMapLegendView` or `nil` if one couldn't be created
 */
- (instancetype)initWithMapConfig:(AWFWeatherMapConfig *)config frame:(CGRect)frame;

/**
 *  Adds an `AWFLegendView` for the specified `layerType.
 *
 *  @param layerType The `AWFLayerType` to add a legend for
 */
- (void)addLegendForLayerType:(AWFLayerType)layerType;

/**
 *  Removes the `AWFLegendView` for the specified `layerType`.
 *
 *  @param layerType The `AWFLayerType` to remove the legend for
 */
- (void)removeLegendForLayerType:(AWFLayerType)layerType;

/**
 *  A Boolean value indicating whether a legend is currently displayed for the specified `layerType`.
 *
 *  @param layerType The `AWFLayerType` to check
 *
 *  @return `YES` if the legend exists, otherwise `NO`.
 */
- (BOOL)hasLegendForLayerType:(AWFLayerType)layerType;

/**
 *  Shows or hides the view, which is either expanded or collapsed respectively.
 *
 *  @param show     A Boolean indiciating whether to show the view
 *  @param animated A Boolean indicating whether the action should be animated
 */
- (void)show:(BOOL)show animated:(BOOL)animated;

/**
 *  The frame required for the content, including all visible legend views and content insets.
 */
- (CGRect)contentFrame;

@end
