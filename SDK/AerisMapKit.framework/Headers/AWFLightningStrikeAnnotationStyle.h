//
//  AWFLightningStrikeAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/18/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFAnnotationStyle.h>
#import <AerisMapKit/AWFGroupedStyle.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFLightningStrikeAnnotationType NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFLightningStrikeAnnotationType const AWFLightningStrikeAnnotationTypeAge15;
FOUNDATION_EXPORT AWFLightningStrikeAnnotationType const AWFLightningStrikeAnnotationTypeAge15To30;
FOUNDATION_EXPORT AWFLightningStrikeAnnotationType const AWFLightningStrikeAnnotationTypeAge30To45;
FOUNDATION_EXPORT AWFLightningStrikeAnnotationType const AWFLightningStrikeAnnotationTypeAge45To60;
FOUNDATION_EXPORT AWFLightningStrikeAnnotationType const AWFLightningStrikeAnnotationTypeAge60;

/**
 An `AWFLightningStrikeAnnotationStyle` object provides the style specifications to be used for a lightning-related annotation's representation on a map.
 */
@interface AWFLightningStrikeAnnotationStyle : AWFAnnotationStyle <AWFGroupedStyle>

@end

NS_ASSUME_NONNULL_END
