//
//  AWFAnnotationLegendStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/2/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFLegendStyle.h>

/**
 *  An `AWFDataLegendStyle` object is an `AWFLegendStyle` subclass that provides the style specifications to be used for a data-type legend, typically for point data on a map.
 */
@interface AWFDataLegendStyle : AWFLegendStyle

/**
 *  The radius of the point.
 */
@property (nonatomic, assign) CGFloat pointRadius;

/**
 *  Total number of columns. This may be adjusted based on the view's total width.
 */
@property (nonatomic, assign) NSInteger numberOfColumns;

/**
 *  Padding around each row's content.
 */
@property (nonatomic, assign) UIEdgeInsets rowEdgeInsets;

/**
 *  A Boolean value indicating whether the points should be filled.
 */
@property (nonatomic, assign) BOOL applyFill;

/**
 *  A Boolean value indicating whether the points should have a stroke.
 */
@property (nonatomic, assign) BOOL applyStroke;

/**
 *  The text labels to display by data identifier.
 */
@property (nonatomic, strong) NSDictionary *labels;

/**
 *  Assigns the text label to display for the specified data `identifier`.
 *
 *  @param labelText  The text for the item's label
 *  @param identifier The data type identifier
 */
- (void)setLabelText:(NSString *)labelText forIdentifier:(NSString *)identifier;

/**
 *  Returns the text to use for the specified `identifier`.
 *
 *  @param identifier The data type identifier
 */
- (NSString *)labelTextForIdentifier:(NSString *)identifier;

@end