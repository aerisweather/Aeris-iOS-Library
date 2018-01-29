//
//  AWFTooltip.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/24/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AWFTooltipArrowDirection) {
	AWFTooltipArrowDirectionUp = 1UL << 0,
	AWFTooltipArrowDirectionDown = 1UL << 1,
	AWFTooltipArrowDirectionLeft = 1 << 2,
	AWFTooltipArrowDirectionRight = 1 << 3,
	AWFTooltipArrowDirectionHorizontal = AWFTooltipArrowDirectionLeft | AWFTooltipArrowDirectionRight,
	AWFTooltipArrowDirectionVertical = AWFTooltipArrowDirectionDown | AWFTooltipArrowDirectionUp,
	AWFTooltipArrowDirectionAny = AWFTooltipArrowDirectionUp | AWFTooltipArrowDirectionDown | AWFTooltipArrowDirectionLeft | AWFTooltipArrowDirectionRight
};

typedef NS_ENUM(NSUInteger, AWFTooltipAnimationType) {
	AWFTooltipAnimationTypeFade = 0
};

@interface AWFTooltip : UIView

@property (copy, nonatomic, nullable) NSString *title;
@property (copy, nonatomic, nullable) NSString *message;

@property (assign, nonatomic) CGFloat maxWidth;
@property (nonatomic, strong) NSDictionary *titleTextAttributes;
@property (nonatomic, strong) NSDictionary *messageTextAttributes;
@property (nonatomic, strong) UIColor *backgroundFillColor;
@property (assign, nonatomic) CGFloat cornerRadius;
@property (assign, nonatomic) UIEdgeInsets contentEdgeInsets;
@property (assign, nonatomic) UIEdgeInsets constrainedInsets;
@property (assign, nonatomic) CGSize anchorSize;
@property (assign, nonatomic) UIOffset anchorOffset;
@property (assign, nonatomic) AWFTooltipArrowDirection preferredArrowDirection;

@property (assign, nonatomic) BOOL tapToDismissEnabled;
@property (assign, nonatomic) BOOL tapAnywhereToDismissEnabled;

- (instancetype)initWithTitle:(nullable NSString *)title message:(nullable NSString *)message;
- (instancetype)initWithMessage:(nullable NSString *)message;
- (instancetype)initWithContentView:(UIView *)contentView;

- (void)presentFromPoint:(CGPoint)point inView:(UIView *)view constrainedToView:(UIView *)constrainedView animated:(BOOL)animated;
- (void)presentFromRect:(CGRect)rect inView:(UIView *)view constrainedToView:(UIView *)constrainedView animated:(BOOL)animated;
- (void)presentFromView:(UIView *)fromView inView:(UIView *)view constrainedToView:(UIView *)constrainedView animated:(BOOL)animated;
- (void)dismiss:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
