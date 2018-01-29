//
//  AWFRiverAnnotationStyle.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 11/14/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFAnnotationStyle.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFRiverAnnotationType NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFRiverAnnotationType const AWFRiverAnnotationTypeMajor;
FOUNDATION_EXPORT AWFRiverAnnotationType const AWFRiverAnnotationTypeModerate;
FOUNDATION_EXPORT AWFRiverAnnotationType const AWFRiverAnnotationTypeMinor;
FOUNDATION_EXPORT AWFRiverAnnotationType const AWFRiverAnnotationTypeNearFlood;
FOUNDATION_EXPORT AWFRiverAnnotationType const AWFRiverAnnotationTypeNoFlood;
FOUNDATION_EXPORT AWFRiverAnnotationType const AWFRiverAnnotationTypeNotDefined;
FOUNDATION_EXPORT AWFRiverAnnotationType const AWFRiverAnnotationTypeLowWater;
FOUNDATION_EXPORT AWFRiverAnnotationType const AWFRiverAnnotationTypeOldData;
FOUNDATION_EXPORT AWFRiverAnnotationType const AWFRiverAnnotationTypeOutOfService;

/**
 An `AWFRiverAnnotationStyle` object provides the style specifications to be used for a river-related annotation's representation on a map.
 */
@interface AWFRiverAnnotationStyle : AWFAnnotationStyle

@end

NS_ASSUME_NONNULL_END
