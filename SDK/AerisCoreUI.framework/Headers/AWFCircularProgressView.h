//
//  AWFCircularProgressView.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 12/4/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AWFCircularProgressView : UIView

@property (nonatomic, assign) CGFloat progress;
@property (nonatomic, strong, nullable) UIColor *progressColor;
@property (nonatomic, strong, nullable) UIColor *fillColor;
@property (nonatomic, strong, nullable) UIColor *strokeColor;
@property (nonatomic, assign) CGFloat strokeWidth;

- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
