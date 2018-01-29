//
//  AWFGraphCalloutView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/13/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const AWFGraphCalloutValueKey;
extern NSString * const AWFGraphCalloutNameKey;
extern NSString * const AWFGraphCalloutColorKey;

// options for which directions the callout is allowed to "point" in.
typedef NS_OPTIONS(NSUInteger, AWFGraphCalloutArrowDirection) {
	AWFGraphCalloutArrowDirectionUp = 1 << 0,
	AWFGraphCalloutArrowDirectionDown = 1 << 1,
	AWFGraphCalloutArrowDirectionLeft = 1 << 2,
	AWFGraphCalloutArrowDirectionRight = 1 << 3,
	AWFGraphCalloutArrowDirectionHorizontal = AWFGraphCalloutArrowDirectionLeft | AWFGraphCalloutArrowDirectionRight,
	AWFGraphCalloutArrowDirectionVertical = AWFGraphCalloutArrowDirectionUp | AWFGraphCalloutArrowDirectionDown
};

@interface AWFGraphCalloutView : UIView

@property (readonly, nonatomic, strong, nullable) UILabel *titleLabel;
@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;
@property (nonatomic, assign) AWFGraphCalloutArrowDirection arrowDirection;

- (void)updateWithTitle:(nullable NSString *)title value:(nullable NSString *)value label:(nullable NSString *)label color:(nullable UIColor *)color;
- (void)updateWithTitle:(nullable NSString *)title items:(nullable NSArray *)items;

- (void)presentFromPoint:(CGPoint)point constrainedToView:(UIView *)constrainedView;
- (void)dismiss:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
