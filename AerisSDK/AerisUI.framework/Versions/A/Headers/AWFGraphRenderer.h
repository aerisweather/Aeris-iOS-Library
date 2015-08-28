//
//  AWFGraphRenderer.h
//  AerisUI
//
//  Created by Nicholas Shipes on 12/19/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisUI/AWFGraphSeries.h>

typedef NS_ENUM(NSInteger, AWFGraphRendererType) {
	AWFGraphRendererTypeLine = 0,
	AWFGraphRendererTypeBar
};

@protocol AWFGraphRendererDelegate;
@class AWFGraphView;

/**
 *  `AWFGraphRenderer` is the base class used to render series data onto a graph view. This class should not be used alone and must be subclassed to provide
 *  all drawing based on the desired result and renderer type.
 */
@interface AWFGraphRenderer : NSObject

/**
 *  The graph view this renderer instance belongs to.
 */
@property (nonatomic, strong) AWFGraphView *graphView;

/**
 *  The receiver's delegate.
 *
 *  A graph renderer sends messages to its delegate regarding the selection and deselecton of series item data points.
 */
@property (nonatomic, assign) id<AWFGraphRendererDelegate> delegate;

/**
 *  Renders a series item in the graph.
 *
 *  @param seriesItem The series item to render
 */
- (void)drawSeriesItem:(AWFSeriesItem *)seriesItem;

/**
 *  Updates all series items managed by this renderer.
 */
- (void)update;
- (void)reset;

/**
 *  Updates all series items managed by this renderer for the specified zoom scale.
 *
 *  This is called automatically by the parent graph view when its zoom scale changes and should not be called directly.
 *
 *  @param zoomScale The zoom scale to use
 */
- (void)adjustForZoomScale:(CGFloat)zoomScale;

/**
 *  Returns the layer that was hit at the specified point, if any.
 *
 *  This is used to determine if a series item data element was tapped from the parent graph view.
 *
 *  @param point The point to test against
 *  @param view  The view in which to test
 *
 *  @return The layer that was hit, otherwise `nil` if none were hit.
 */
- (CALayer *)hitTest:(CGPoint)point inView:(UIView *)view;

/**
 *  Selects the graph renderer item at the `index` of the specified `seriesItem`. If a callout view is available, this method will also display a callout 
 *  view containing the value of the item at the selected point and series item.
 *
 *  Note: The provided `seriesItem` must use this renderer type in order for the item to be selected.
 *
 *  @param index      The index of the point in the series item to select.
 *  @param seriesItem The series item that contains the point to select.
 */
- (void)selectItemAtIndex:(NSInteger)index inSeriesItem:(AWFSeriesItem *)seriesItem;

/**
 *  Deselects all selected graph renderer items, if any, and dismisses the callout view.
 */
- (void)deselectAllItems;

@end


@protocol AWFGraphRendererDelegate <NSObject>
@optional

/**
 *  Tells the delegate that a data element, typically a point or bar, was selected in the renderer's view.
 *
 *  @param renderer   The graph renderer whose data element was selected
 *  @param seriesItem The series item that the selected data element belongs to
 *  @param index      The index of the element in the data points belonging to the series item
 */
- (void)graphRenderer:(AWFGraphRenderer *)renderer didSelectItemForSeries:(AWFSeriesItem *)seriesItem atIndex:(NSInteger)index;

/**
 *  Tells the delegate that a data element, typically a point or bar, was deselected in the renderer's view.
 *
 *  @param renderer   The graph renderer whose data element was deselected
 *  @param seriesItem The series item that the deselected data element belongs to
 *  @param index      The index of the element in the data points belonging to the series item
 */
- (void)graphRenderer:(AWFGraphRenderer *)renderer didDeselectItemForSeries:(AWFSeriesItem *)seriesItem atIndex:(NSInteger)index;

@end