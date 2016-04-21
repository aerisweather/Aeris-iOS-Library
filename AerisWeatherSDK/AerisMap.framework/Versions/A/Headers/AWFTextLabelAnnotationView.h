//
//  AWFTextLabelAnnotationView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 2/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisMap/AWFMKAnnotationView.h>
#import <AerisMap/AWFTextAnnotationStyle.h>

/**
 *  An `AWFTextLabelAnnotationView` object is an `AWFMKAnnotationView` subclass to represent text-related annotations on a weather map.
 */
@interface AWFTextLabelAnnotationView : AWFMKAnnotationView

/**
 *  The text to display.
 */
@property (nonatomic) NSString *labelValue;

/**
 *  Determines the padding to apply around the text label relative to the view's bounds.
 */
@property (assign, nonatomic) UIEdgeInsets contentEdgeInsets;

/**
 *  Updates the text label with the specified `style`.
 *
 *  @param style The `AWFTextAnnotationStyle` to use for the text
 */
- (void)applyStyle:(AWFTextAnnotationStyle *)style;

@end
