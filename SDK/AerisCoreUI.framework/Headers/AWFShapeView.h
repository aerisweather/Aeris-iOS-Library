//
//  AWFShapeView.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 10/2/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AWFShapeView : UIView

@property (nonatomic, copy, nullable) UIBezierPath *path;
@property (nonatomic, nullable) UIColor *fillColor;
@property (nonatomic, copy, nullable) NSString *fillRule;
@property (nonatomic, nullable) UIColor *strokeColor;
@property (nonatomic) CGFloat strokeStart, strokeEnd;
@property (nonatomic) CGFloat lineWidth;
@property (nonatomic) CGFloat miterLimit;
@property (nonatomic, copy, nullable) NSString *lineCap;
@property (nonatomic, copy, nullable) NSString *lineJoin;
@property (nonatomic) CGFloat lineDashPhase;
@property (nonatomic, copy, nullable) NSArray *lineDashPattern;

@property (nonatomic, assign) BOOL hitTestUsingPath;

@end

NS_ASSUME_NONNULL_END
