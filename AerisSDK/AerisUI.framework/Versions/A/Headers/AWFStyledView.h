//
//  AWFStyledView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/6/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

typedef NS_ENUM (NSUInteger, AWFLayout) {
	AWFLayoutVertical = 0,
	AWFLayoutHorizontal
};

@class AWFCascadingStyle;

@interface AWFStyledView : UIView

@property (nonatomic, strong) NSArray *backgroundGradientColors;
@property (nonatomic, strong, readonly) AWFCascadingStyle *style;

@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;

- (instancetype)initWithStyle:(AWFCascadingStyle *)style frame:(CGRect)frame;
- (void)applyStyle:(AWFCascadingStyle *)style;

- (void)setup;
- (CGRect)contentFrame;

@end