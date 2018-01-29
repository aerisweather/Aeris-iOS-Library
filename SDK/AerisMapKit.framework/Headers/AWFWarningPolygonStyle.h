//
//  AWFWarningPolygonStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/28/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFPolygonStyle.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFWarningPolygonType NS_TYPED_EXTENSIBLE_ENUM;
extern AWFWarningPolygonType const AWFWarningPolygonTypeFlood;
extern AWFWarningPolygonType const AWFWarningPolygonTypeSevereStorm;
extern AWFWarningPolygonType const AWFWarningPolygonTypeTornado;

/**
 An `AWFWarningPolygonStyle` object provides the style specifications to be used for a warning polygon's representation on a map.
 */
@interface AWFWarningPolygonStyle : AWFPolygonStyle

@end

NS_ASSUME_NONNULL_END
