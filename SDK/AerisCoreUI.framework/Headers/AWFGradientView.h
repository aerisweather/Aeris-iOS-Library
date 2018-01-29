//
//  AWFGradientView.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/23/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AWFGradientView : UIView

@property (nonatomic, nullable) UIColor *topColor;
@property (nonatomic, nullable) UIColor *bottomColor;
@property (nonatomic, nullable) NSArray *colors;
@property (nonatomic, nullable) NSArray *locations;

@end

NS_ASSUME_NONNULL_END
