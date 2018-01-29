//
//  AWFTextLabelAnnotation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 2/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFAnnotation.h>
#import <AerisMapKit/AWFStyledMapItem.h>
#import <AerisMapKit/AWFTextAnnotationStyle.h>

@interface AWFTextLabelAnnotation : NSObject <AWFAnnotation, AWFStyledMapItem>

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, strong) id style;
@property (readonly, nonatomic, strong) AWFWeatherObject *modelObject;
@property (nonatomic, assign, getter = isAnimatable) BOOL animatable;
@property (nonatomic, assign) BOOL belongsToTimelineAnimation;

/**
 The text to display for the annotation.
 */
@property (nonatomic, copy) NSString *labelValue;

/**
 The text style to use when rendering the annotation's text.
 */
@property (nonatomic, strong) AWFTextAnnotationStyle *textStyle;

@end
