//
//  CATransaction+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/25/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface CATransaction (AerisCoreUI)

/**
 *  Creates and commits a CATransation by disabling actions within the provided block, which will prevent implicit animations from being applied.
 *
 *  This is primarily used as a convenience method when setting animated properties of a layer without the implicit animation.
 *
 *  @param block The block to run within the transaction.
 */
+ (void)awf_transactionByDisablingActions:(void (^)(void))block;

+ (void)awf_beginTransactionWithCompletionBlock:(void (^)(void))block;

@end

NS_ASSUME_NONNULL_END
