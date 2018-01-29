//
//  UIViewController+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/24/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (AerisCoreUI)

- (NSLayoutYAxisAnchor *)awf_topSafeAreaLayoutGuideWithFallback;
- (NSLayoutYAxisAnchor *)awf_bottomSafeAreaLayoutGuideWithFallback;
- (BOOL)awf_isModal;

@end

NS_ASSUME_NONNULL_END
