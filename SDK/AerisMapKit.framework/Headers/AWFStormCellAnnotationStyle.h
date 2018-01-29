//
//  AWFStormCellAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/17/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFAnnotationStyle.h>
#import <AerisMapKit/AWFGroupedStyle.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFStormCellAnnotationType NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFStormCellAnnotationType const AWFStormCellAnnotationTypeGeneral;
FOUNDATION_EXPORT AWFStormCellAnnotationType const AWFStormCellAnnotationTypeHail;
FOUNDATION_EXPORT AWFStormCellAnnotationType const AWFStormCellAnnotationTypeRotating;
FOUNDATION_EXPORT AWFStormCellAnnotationType const AWFStormCellAnnotationTypeTornadic;

/**
 An `AWFStormCellAnnotationStyle` object provides the style specifications to be used for a storm cell-related annotation's representation on a map.
 */
@interface AWFStormCellAnnotationStyle : AWFAnnotationStyle <AWFGroupedStyle, AWFOverlayStylable>

/**
 The style specifications for map overlays.
 */
@property (nonatomic, strong) AWFMapItemStyle *overlay;

@end

NS_ASSUME_NONNULL_END
