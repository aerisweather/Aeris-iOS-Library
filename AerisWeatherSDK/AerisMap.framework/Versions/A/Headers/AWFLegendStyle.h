//
//  AWFLegend.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/29/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AerisUI.h>
#import <AerisMap/AWFLayerType.h>

/**
 *  An `AWFLegendStyle` object provides the style specifications to be used for a data legend on a map.
 */
@interface AWFLegendStyle : NSObject

/**
 *  An array of items associated with the legend, usually an array of dictionary instances containing color stop information.
 */
@property (nonatomic, strong) id items;

/**
 *  The title of the legend.
 */
@property (nonatomic, copy) NSString *name;

/**
 *  If `items` is a dictionary of array elements, specifies the order in which each item group is rendered.
 */
@property (nonatomic, strong) NSArray *displayOrderForItemGroups;

/**
 *  Specifies the order in which the items are rendered.
 */
@property (nonatomic, strong) NSArray *displayOrderForItems;

/**
 *  Content edge insets legend's text labels.
 */
@property (nonatomic, assign) UIEdgeInsets labelEdgeInsets;

/**
 *  Text style spec to use for legend labels.
 */
@property (nonatomic, strong) AWFTextStyleSpec *labelTextSpec;

/**
 *  Initializes and returns a new `AWFLegendStyle` instance with the default configuration.
 *
 *  @return The initialized `AWFLegendStyle` instance or `nil` if one couldn't be created.
 */
+ (instancetype)style;

@end