//
//  AWFMKTextLabelAnnotationView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 2/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFMKAnnotationView.h>
#import <AerisMapKit/AWFTextAnnotationStyle.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFMKTextLabelAnnotationView` object is an `AWFMKAnnotationView` subclass to represent text-related annotations on a weather map
 that is configured to use the `AWFWeatherMapTypeApple` type.
 */
@interface AWFMKTextLabelAnnotationView : AWFMKAnnotationView

/**
 The text to display.
 */
@property (nonatomic, nullable) NSString *labelValue;

/**
 Determines the padding to apply around the text label relative to the view's bounds.
 */
@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;

/**
 Updates the text label with the specified `style`.
 *
 @param style The `AWFTextAnnotationStyle` to use for the text
 */
- (void)applyStyle:(AWFTextAnnotationStyle *)style;

@end

NS_ASSUME_NONNULL_END
