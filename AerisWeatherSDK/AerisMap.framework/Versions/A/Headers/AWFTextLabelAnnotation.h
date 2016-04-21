//
//  AWFTextLabelAnnotation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 2/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisMap/AWFStyledAnnotation.h>
#import <AerisMap/AWFTextAnnotationStyle.h>

@interface AWFTextLabelAnnotation : AWFStyledAnnotation

/**
 *  The text to display for the annotation.
 */
@property (copy, nonatomic) NSString *labelValue;

/**
 *  The text style to use when rendering the annotation's text.
 */
@property (strong, nonatomic) AWFTextAnnotationStyle *style;

@end
