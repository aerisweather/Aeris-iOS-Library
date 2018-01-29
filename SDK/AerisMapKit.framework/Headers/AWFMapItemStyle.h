//
//  AWFMapItemStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/14/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AWFStyleProvider <NSObject>
@end

/**
 The `AWFMapItemStyle` provides style information that is used for overlays and annotations when rendered on a map.
 */
@interface AWFMapItemStyle : NSObject <AWFStyleProvider>

/**
 The identifier for the style.
 */
@property (nonatomic, copy, nullable) NSString *identifier;

/**
 The text label for the style, usually displayed in annotation callouts or info windows.
 */
@property (nonatomic, copy, nullable) NSString *label;

/**
 The color used to fill the shape's path.
 */
@property (nonatomic, strong, nullable) UIColor *fillColor;

/**
 The color used to stroke the shape's path.
 */
@property (nonatomic, strong, nullable) UIColor *strokeColor;

/**
 Specifies the line width for the stroke around the shape.
 */
@property (nonatomic, assign) CGFloat strokeWidth;

/**
 The default annotation style.
 
 This value may be a single `AWFMapItemStyle` instance or a collection of styles as an instance of `AWFGroupedStyle`.
 */
+ (nullable id)defaultStyle;

/**
 Initializes and returns an empty style specification object.
 
 @return The initialized style object.
 */
+ (instancetype)style;

/**
 Returns a dictionary of legend view labels associated with their style/group identifiers.
 */
+ (nullable NSDictionary<NSString *, NSString *> *)labelsByIdentifier;

@end

NS_ASSUME_NONNULL_END
