//
//  AWFTextAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 2/11/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisUI/AerisUI.h>
#import <AerisMap/AWFMapItemStyle.h>

/**
 *  An `AWFTextAnnotationStyle` object provides the style specifications to be used for a text annotation's representation on a map.
 */
@interface AWFTextAnnotationStyle : AWFMapItemStyle

/**
 *  The text style specification.
 */
@property (strong, nonatomic) AWFTextStyleSpec *textStyle;

/**
 *  The corner radius of the annotation view. 
 */
@property (assign, nonatomic) CGFloat cornerRadius;

/**
 *  The padding to apply around the text label relative to the annotation view's bounds.
 */
@property (assign, nonatomic) UIEdgeInsets contentEdgeInsets;

/**
 *  Generates an image representation of the annotation's view based on the style specifications.
 *
 *  @return An image representation of the annotation.
 */
- (UIImage *)imageFromStyleWithText:(NSString *)text;

@end
