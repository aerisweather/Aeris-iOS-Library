//
//  AWFRecordAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/17/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFAnnotationStyle.h>
#import <AerisMapKit/AWFGroupedStyle.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFRecordAnnotationType NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFRecordAnnotationType const AWFRecordAnnotationTypePrecip;
FOUNDATION_EXPORT AWFRecordAnnotationType const AWFRecordAnnotationTypeSnow;
FOUNDATION_EXPORT AWFRecordAnnotationType const AWFRecordAnnotationTypeMaxTemp;
FOUNDATION_EXPORT AWFRecordAnnotationType const AWFRecordAnnotationTypeMinTemp;
FOUNDATION_EXPORT AWFRecordAnnotationType const AWFRecordAnnotationTypeHighMinTemp;
FOUNDATION_EXPORT AWFRecordAnnotationType const AWFRecordAnnotationTypeLowMaxTemp;


/**
 An `AWFRecordAnnotationStyle` object provides the style specifications to be used for a record-related annotation's representation on a map.
 */
@interface AWFRecordAnnotationStyle : AWFAnnotationStyle <AWFGroupedStyle>

@end

NS_ASSUME_NONNULL_END
