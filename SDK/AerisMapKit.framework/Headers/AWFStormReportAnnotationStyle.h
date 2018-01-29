//
//  AWFStormReportAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/17/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFAnnotationStyle.h>
#import <AerisMapKit/AWFGroupedStyle.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFStormReportAnnotationType NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeAvalanche;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeBlizzard;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeFire;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeFlood;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeFog;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeIce;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeHail;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeLightning;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeRain;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeSnow;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeTides;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeTornado;
FOUNDATION_EXPORT AWFStormReportAnnotationType const AWFStormReportAnnotationTypeWind;

/**
 An `AWFStormReportAnnotationStyle` object provides the style specifications to be used for a storm report-related annotation's representation on a map.
 */
@interface AWFStormReportAnnotationStyle : AWFAnnotationStyle <AWFGroupedStyle>

@end

NS_ASSUME_NONNULL_END
