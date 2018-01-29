//
//  AWFGroupedLegendView.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/30/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import <AerisMapKit/AWFLegendRenderer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFGroupedLegendView` is an subclass of `UIView` that displays multiple legends within a single view along with title labels for each.
 */
@interface AWFGroupedLegendView : UIView

/**
 An array of legend renderer instances used for the group.
 */
@property (nonatomic, strong, readonly) NSArray<NSObject<AWFLegendRenderer> *> *renderers;

/**
 The amount of space, in points, between each legend item in the group.
 */
@property (nonatomic, assign) CGFloat interitemSpacing;

/**
 The text style specification to apply to legend title labels.
 */
@property (nonatomic, strong, nullable) AWFTextStyleSpec *labelStyle;

/**
 The edge insets to apply to each legend title label.
 */
@property (nonatomic, assign) UIEdgeInsets legendInsets;

/**
 Initializes and returns a newly allocated grouped legend view with the specified legend renderers and titles.

 @param renderers The legend renderers displayed in the group.
 @param titles The titles that correspond to the legends.
 @param frame The frame rectangle for the view, measured in points.
 @return An initialized grouped legend view object.
 */
- (instancetype)initWithLegendRenderers:(NSArray<NSObject<AWFLegendRenderer> *> *)renderers title:(NSArray<NSString *> *)titles frame:(CGRect)frame;

@end

NS_ASSUME_NONNULL_END
