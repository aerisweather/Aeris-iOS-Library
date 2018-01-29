//
//  UIControl+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 1/5/16.
//  Copyright © 2016 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^AWFControlActionBlock)(id sender);

@interface UIControl (AerisCoreUI)

- (void)addEventHandler:(AWFControlActionBlock)handler forControlEvents:(UIControlEvents)controlEvents;

@end

NS_ASSUME_NONNULL_END
