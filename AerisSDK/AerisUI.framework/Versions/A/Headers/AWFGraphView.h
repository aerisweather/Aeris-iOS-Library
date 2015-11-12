//
//  AWFGraphView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 12/19/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisUI/AWFGraphRenderer.h>

@protocol AWFGraphViewDelegate;
@class AWFGraphSeries, AWFGraphAxis, AWFGraphCalloutView;

@interface AWFGraphView : UIView

/**
 *  The series of data items in the graph.
 */
@property (nonatomic, strong) AWFGraphSeries *series;

/**
 *  The x-axis instance for handling the horizontal grid and labels.
 */
@property (nonatomic, strong) AWFGraphAxis *xAxis;

/**
 *  The static value range to use for the x-axis. If not provided, the range will be calculated based on the series data.
 */
@property (nonatomic, assign) AWFGraphSeriesRange xAxisRange;

/**
 *  The y-axis instance for handling the vertical grid and labels.
 */
@property (nonatomic, strong) AWFGraphAxis *yAxis;

/**
 *  The static value range to use for the y-axis. If not provided, the range will be calculated based on the series data.
 */
@property (nonatomic, assign) AWFGraphSeriesRange yAxisRange;

/**
 *  The inset values for the series container view relative to the graph view's bounds.
 */
@property (nonatomic, assign) UIEdgeInsets seriesEdgeInsets;

/**
 *  The inset values to use for controlling the padding within the series container view.
 */
@property (nonatomic, assign) UIEdgeInsets seriesInnerEdgeInsets;

/**
 *  The callout view used to display point values on graph gesture events.
 */
@property (nonatomic, strong) AWFGraphCalloutView *calloutView;

/**
 *  The view in which the graph's callout view should be constrained to for positioning. The default value is `[UIApplication sharedApplication].keyWindow`.
 */
@property (nonatomic, strong) UIView *constrainedViewForCallout;

/**
 *  Whether zooming the graph view is enabled. If enabled, double-tapping on the graph's series container view will zoom into the graph one level, 
 *  while tapping with two fingers will zoom the graph back out one level. Pinching to zoom is also permitted when zoom is enabled.
 */
@property (nonatomic, assign) BOOL zoomEnabled;

/**
 *  The current zoom scale of the graph's series container.
 */
@property (nonatomic, assign) CGFloat zoomScale;

/**
 *  The receiver's delegate.
 *
 *  A graph view sends messages to its delegate regarding the status of data requests from its series and when data elements on the graph are selected.
 */
@property (nonatomic, unsafe_unretained) id<AWFGraphViewDelegate> delegate;

/**
 *  Reloads data from the object loaders associated with each series item, if any, and redraws the graph with the current series data.
 */
- (void)reloadData;

- (void)resetGraph;

/**
 *  Determines whether the graph should appear in its loading state. When in a loading state, an activity indicator view is displayed above the graph until
 *  this method is called with a value of `NO`.
 *
 *  @param loading Whether to show the graph in a loading state.
 */
- (void)showLoading:(BOOL)loading;

/**
 *  The view in which each series item is rendered.
 */
- (UIView *)containerViewForSeries;

/**
 *  The view in which each graph axis is rendered. This view will scroll and change with the series container view.
 */
- (UIView *)containerViewForAxis;

/**
 *  The view in which each static graph axis is rendered. A static axis does not scroll or change with the series container view.
 */
- (UIView *)containerViewForStaticAxis;

/**
 *  Returns an array of series items that should be rendered with the specified renderer type.
 *
 *  @param rendererType The renderer type to use
 */
- (NSArray *)seriesItemsForRendererType:(AWFGraphRendererType)rendererType;

/**
 *  Returns the graph renderer instance for the specified `rendererType`. If there is not a renderer instance for the type, `nil` is returned.
 *
 *  @param rendererType The renderer type to return the renderer instance for.
 */
- (AWFGraphRenderer *)rendererForType:(AWFGraphRendererType)rendererType;

/**
 *  Returns the current scale for the specified axis.
 *
 *  @param axis The axis to return the scale for
 */
- (CGFloat)scaleForAxis:(AWFGraphAxisType)axis;

/**
 *  Converts the values on the x and y axis to their position within the series view and based on the current zoom scale of the graph.
 *
 *  @param xValue The value along the x-axis to convert
 *  @param yValue The value along the y-axis to convert
 *
 *  @return The position of the value within the series container view.
 */
- (CGPoint)interpolationForValueAtX:(CGFloat)xValue y:(CGFloat)yValue;

/**
 *  Returns the value for a point on the graph series for a specific axis.
 *
 *  @param position The point to return the value for
 *  @param axis     The axis to use when calculating the value
 *
 *  @return The value on the specified axis for the point
 */
- (CGFloat)valueForPosition:(CGPoint)position onAxis:(AWFGraphAxisType)axis;

/**
 *  Returns the size needed to contain the series, including the inner insets specified by `seriesInnerEdgeInsets`.
 *
 *  @return The size needed for the series
 */
- (CGSize)sizeForSeriesRange;

/**
 *  Returns the domain for all items in the graph's series.
 */
- (AWFGraphSeriesDomain)domainForAllSeries;

/**
 *  Returns the domain that is currently visible within the graph's bounds. If the graph has not been zoomed, this value will be equal to `domainForAllSeries`.
 */
- (AWFGraphSeriesDomain)visibleDomain;

/**
 *  Selects the graph item at the `index` of the specified `seriesItem`. If a callout view is available, this method will also display a callout view containing
 *  the value of the item at the selected point and series item.
 *
 *  @param index      The index of the point in the series item to select.
 *  @param seriesItem The series item that contains the point to select.
 */
- (void)selectItemAtIndex:(NSInteger)index inSeriesItem:(AWFSeriesItem *)seriesItem;

/**
 *  Deselects all selected graph items, if any, and dismisses the callout view.
 */
- (void)deselectAllItems;

@end


@protocol AWFGraphViewDelegate <NSObject>
@optional

/**
 *  Tells the delegate that the graph series started requesting data.
 *
 *  @param graphView The graph view whose series started loading
 */
- (void)graphViewDidStartLoading:(AWFGraphView *)graphView;

/**
 *  Tells the delegate that the graph series finished loading data successfully.
 *
 *  @param graphView The graph view whose series successfully loaded data.
 */
- (void)graphViewDidFinishLoading:(AWFGraphView *)graphView;

/**
 *  Tells the delegate that the graph series failed to load its data.
 *
 *  @param graphView The graph view whose series failed to load
 *  @param error     The error that occurred while loading
 */
- (void)graphView:(AWFGraphView *)graphView didFailLoadingWithError:(NSError *)error;

/**
 *  Tells the delegate that a data element, typically a point or bar, was selected on the graph.
 *
 *  @param graphView  The graph view whose data element was selected
 *  @param seriesItem The series item that the selected data element belongs to
 *  @param index      The index of the element in the data points belonging to the series item
 */
- (void)graphView:(AWFGraphView *)graphView didSelectItemForSeries:(AWFSeriesItem *)seriesItem atIndex:(NSInteger)index;

/**
 *  Tells the delegate that a data element, typically a point or bar, was deselected from the graph.
 *
 *  @param graphView  The graph view whose data element was deselected
 *  @param seriesItem The series item that the deselected data element belongs to
 *  @param index      The index of the element in the data points belonging to the series item
 */
- (void)graphView:(AWFGraphView *)graphView didDeselectItemForSeries:(AWFSeriesItem *)seriesItem atIndex:(NSInteger)index;

- (void)graphView:(AWFGraphView *)graphView didPanToValueOnXAxis:(CGFloat)xValue;

@end