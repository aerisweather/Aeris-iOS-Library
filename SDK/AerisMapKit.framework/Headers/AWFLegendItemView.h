//
//  AWFLegendItemView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/29/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisMapKit/AWFWeatherLayer.h>
#import <AerisMapKit/AWFLegendRenderer.h>
#import <AerisMapKit/AWFLegendConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFLegendStyle;

/**
 An `AWFLegendItemView` object provides the base view class used for rendering data-specific legends based on a `AWFLegendStyle`.
 */
@interface AWFLegendItemView : UIView

/**
 The legend item's key.
 */
@property (nonatomic, copy) NSString *key;

/**
 The legend configuration associated with the view.
 */
@property (nonatomic, strong, readonly) AWFLegendConfig *config;

/**
 The style used when rendering the legend.
 */
@property (nonatomic, strong) AWFLegendStyle *style;

/**
 The renderer that renders the legend image.
 */
@property (nonatomic, strong, readonly) NSObject<AWFLegendRenderer> *legend;

/**
 A Boolean value indicating whether the legend should be rendered using Metric values when applicable.
 */
@property (nonatomic, assign, getter=isMetric) BOOL metric;

/**
 Initializes and returns a newly allocated item view with the specified legend configuration.

 @param config The legend configuration.
 @param frame The initial frame rectangle for the view, measured in points. The view's final height will be calculated automatically based on the
 width and style configuration.
 @return An initialized item view object.
 */
- (instancetype)initWithLegendConfig:(AWFLegendConfig *)config frame:(CGRect)frame;

/**
 Initializes and returns a newly allocated item view with the specified legend configuration and style.

 @param config The legend configuration.
 @param style The style to use when rendering.
 @param frame The initial frame rectangle for the view. measured in points. The view's final height will be calculated automatically based on the
 width and style configuration.
 @return An initialized item view object.
 */
- (instancetype)initWithLegendConfig:(AWFLegendConfig *)config style:(nullable AWFLegendStyle *)style frame:(CGRect)frame;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

/**
 When the legend renderer is an instance of `AWFPointLegend`, this method redraws the legend by only including items in the legend that are associated
 with the specified keys.

 @param keys The array of keys to include.
 */
- (void)updateByFilteringItemKeys:(NSArray<NSString *> *)keys;

@end

NS_ASSUME_NONNULL_END
