//
//  AWFFireAnnotationStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/18/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFAnnotationStyle.h>
#import <AerisMapKit/AWFGroupedStyle.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFFireAnnotationType NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFFireAnnotationType const AWFFireAnnotationTypeSmall;
FOUNDATION_EXPORT AWFFireAnnotationType const AWFFireAnnotationTypeMedium;
FOUNDATION_EXPORT AWFFireAnnotationType const AWFFireAnnotationTypeLarge;
FOUNDATION_EXPORT AWFFireAnnotationType const AWFFireAnnotationTypeCritical;

/**
 An `AWFFireAnnotationStyle` object provides the style specifications to be used for a fire-related annotation's representation on a map.
 */
@interface AWFFireAnnotationStyle : AWFAnnotationStyle <AWFGroupedStyle>

@end

NS_ASSUME_NONNULL_END
