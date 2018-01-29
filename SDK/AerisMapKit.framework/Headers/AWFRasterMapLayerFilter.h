//
//  AWFRasterMapLayerFilter.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AWFRasterMapLayerFilter : NSObject

@property (nonatomic, readonly) NSString *valueString;

@end


@interface AWFLayerEmbossFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerBlurFilter : AWFRasterMapLayerFilter

@property (nonatomic, assign) CGFloat amount;

@end

@interface AWFLayerGrayFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerSobelFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerEdgeDetectFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerXGradientFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerYGradientFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerInvertFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerSharpenFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerColorBlindProtanopeFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerColorBlindDeuteranopeFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerColorBlindTritanopeFilter : AWFRasterMapLayerFilter
@end

@interface AWFLayerColorizeAlphaFilter : AWFRasterMapLayerFilter

- (instancetype)initWithBlue:(CGFloat)blue yellow:(CGFloat)yellow red:(CGFloat)red;

@end

@interface AWFLayerColorToHueFilter : AWFRasterMapLayerFilter



@end

@interface AWFLayerScaleHSLAFilter : AWFRasterMapLayerFilter

- (instancetype)initWithH0:(CGFloat)h0 h1:(CGFloat)h1 s0:(CGFloat)s0 s1:(CGFloat)s1 l0:(CGFloat)l0 l1:(CGFloat)l1 a0:(CGFloat)a0 a1:(CGFloat)a1;

@end
