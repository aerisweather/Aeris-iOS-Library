//
//  AWFMapItemStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/14/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//


@interface AWFMapItemStyle : NSObject

/**
 *  The color used to fill the shape's path.
 */
@property (nonatomic, strong) UIColor *fillColor;

/**
 *  The color used to stroke the shape's path.
 */
@property (nonatomic, strong) UIColor *strokeColor;

/**
 *  Specifies the line width for the stroke around the shape.
 */
@property (nonatomic, assign) CGFloat strokeWidth;

/**
 *  The default annotation style.
 */
+ (id)defaultStyle;

/**
 *  Initializes and returns an empty style specification object.
 *
 *  @return The initialized style object.
 */
+ (instancetype)style;

@end