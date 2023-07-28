//
//  AWFLightningSummaryView.m
//  AerisDemoSupport
//
//  Created by Slipp Douglas Thompson on 5/31/23.
//  Copyright © 2023 AerisWeather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFLightningSummaryView.h"
#import "AWFStyledHeaderView.h"
#import "AWFCascadingStyle.h"

#pragma mark - Private Class Interfaces

@class AWFLightningSummaryRowView, AWFLightningSummaryDetailsView, AWFLightningSummaryDetailsItemView;

@interface AWFLightningSummaryView ()
@property (nonatomic, strong) AWFStyledHeaderView *headerView;
@property (nonatomic, strong) UIStackView *rowStackView;
@property (nonatomic, strong) AWFLightningSummaryDetailsView *detailsView;
@end

@interface AWFLightningSummaryRowView : AWFStyledView
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *valueLabel;
@property (nonatomic, strong) UIView *separatorKeyline;
@end

@interface AWFLightningSummaryDetailsView : AWFStyledView
@property (nonatomic, assign) CGFloat labelColumnWidth;
@property (nonatomic, strong) NSDictionary<NSNumber *, AWFLightningSummaryDetailsItemView *> *viewsByType;
- (void)setMinValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
- (void)setMaxValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
- (void)setAverageValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
@end

@interface AWFLightningSummaryDetailsItemView : AWFStyledView
@property (nonatomic, assign, getter=isHeader) BOOL header;
@property (nonatomic, strong) UIView *topKeyline;
@property (nonatomic, strong) UIView *bottomKeyline;
@property (nonatomic, strong) UIView *labelBackgroundView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *minValueLabel;
@property (nonatomic, strong) UILabel *maxValueLabel;
@property (nonatomic, strong) UILabel *avgValueLabel;
@property (nonatomic, assign) CGFloat labelColumnWidth;
@property (nonatomic, strong) NSLayoutConstraint *labelColumnWidthConstraint;
@property (nonatomic, strong) NSArray<NSLayoutConstraint *> *valueColumnWidthConstraints;
@property (nonatomic, assign) CGFloat lastWidth;
@end

#pragma mark - AWFLightningSummaryView Class Implementation

@implementation AWFLightningSummaryView

- (void)setup {
	[super setup];
	
	NSMutableArray<NSLayoutConstraint *> *constraints = [NSMutableArray new];
	
	AWFStyledHeaderView *headerView = [AWFStyledHeaderView new];
	headerView.translatesAutoresizingMaskIntoConstraints = NO;
	headerView.layout = AWFLayoutHorizontal;
	[self addSubview:headerView];
	self.headerView = headerView;
	[constraints addObjectsFromArray:@[
		[headerView.topAnchor constraintEqualToAnchor:self.topAnchor],
		[headerView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
		[headerView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
		[headerView.heightAnchor constraintEqualToConstant:25.0],
	]];
	
	UIStackView *rowStackView = [UIStackView new];
	rowStackView.axis = UILayoutConstraintAxisVertical;
	rowStackView.distribution = UIStackViewDistributionFillEqually;
	rowStackView.alignment = UIStackViewAlignmentFill;
	rowStackView.spacing = 0;
	rowStackView.layoutMarginsRelativeArrangement = NO;
	rowStackView.preservesSuperviewLayoutMargins = YES;
	rowStackView.translatesAutoresizingMaskIntoConstraints = NO;
	[self addSubview:rowStackView];
	self.rowStackView = rowStackView;
	[constraints addObjectsFromArray:@[
		[rowStackView.topAnchor constraintEqualToAnchor:headerView.bottomAnchor constant:4],
		[rowStackView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
		[rowStackView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
	]];
	
	AWFLightningSummaryDetailsView *detailsView = [AWFLightningSummaryDetailsView new];
	detailsView.translatesAutoresizingMaskIntoConstraints = NO;
	detailsView.preservesSuperviewLayoutMargins = YES;
	detailsView.labelColumnWidth = 90.0;
	[self addSubview:detailsView];
	self.detailsView = detailsView;
	[constraints addObjectsFromArray:@[
		[detailsView.topAnchor constraintEqualToAnchor:rowStackView.bottomAnchor constant:4],
		[detailsView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
		[detailsView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
		[detailsView.bottomAnchor constraintEqualToAnchor:self.bottomAnchor],
	]];
	
	[NSLayoutConstraint activateConstraints:constraints];
	
	[self applyStyle:self.style];
}

- (UIEdgeInsets)layoutMargins {
	return UIEdgeInsetsMake(11, 16, 11, 16);
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	
	[self.headerView applyStyle:style];
	for (AWFLightningSummaryRowView *rowView in self.rowStackView.arrangedSubviews) {
		[rowView applyStyle:style];
	}
	[self.detailsView applyStyle:style];
	
	[self setNeedsDisplay];
}

- (void)addRowWithTitle:(NSString *)titleString andValue:(NSString *)valueString {
	AWFLightningSummaryRowView *preexistingLastRowView = self.rowStackView.arrangedSubviews.lastObject;
	if (preexistingLastRowView != nil) {
		preexistingLastRowView.separatorKeyline.hidden = NO;
	}
	
	AWFLightningSummaryRowView *rowView = [AWFLightningSummaryRowView new];
	rowView.titleLabel.text = titleString;
	rowView.valueLabel.text = valueString;
	rowView.preservesSuperviewLayoutMargins = YES;
	
	[rowView applyStyle:self.style];
	rowView.separatorKeyline.hidden = YES;
	
	[self.rowStackView addArrangedSubview:rowView];
}

- (void)removeAllRows {
	for (UIView *rowView in self.rowStackView.arrangedSubviews) {
		[rowView removeFromSuperview];
	}
}

- (void)setMinValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	[self.detailsView setMinValue:value forWeatherType:weatherType];
}

- (void)setMaxValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	[self.detailsView setMaxValue:value forWeatherType:weatherType];
}

- (void)setAverageValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	[self.detailsView setAverageValue:value forWeatherType:weatherType];
}

- (void)setAllValues:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	[self.detailsView setMinValue:value forWeatherType:weatherType];
	[self.detailsView setMaxValue:value forWeatherType:weatherType];
	[self.detailsView setAverageValue:value forWeatherType:weatherType];
}

@end

#pragma mark - AWFLightningSummaryRowView Class Implementation

@implementation AWFLightningSummaryRowView

- (void)setup {
	[super setup];
	
	UILayoutGuide *layoutGuide = self.layoutMarginsGuide;
	
	UILabel *titleLabel = [UILabel new];
	titleLabel.translatesAutoresizingMaskIntoConstraints = NO;
	titleLabel.font = [UIFont systemFontOfSize:13.0];
	titleLabel.textColor = UIColor.whiteColor;
	titleLabel.textAlignment = NSTextAlignmentLeft;
	titleLabel.backgroundColor = UIColor.clearColor;
	[self addSubview:titleLabel];
	self.titleLabel = titleLabel;
	
	UILabel *valueLabel = [UILabel new];
	valueLabel.translatesAutoresizingMaskIntoConstraints = NO;
	valueLabel.font = [UIFont boldSystemFontOfSize:13.0];
	valueLabel.textColor = UIColor.whiteColor;
	valueLabel.textAlignment = NSTextAlignmentRight;
	valueLabel.backgroundColor = UIColor.clearColor;
	[self addSubview:valueLabel];
	self.valueLabel = valueLabel;
	
	UIView *separatorKeyline = [UIView new];
	separatorKeyline.translatesAutoresizingMaskIntoConstraints = NO;
	separatorKeyline.userInteractionEnabled = NO;
	[self addSubview:separatorKeyline];
	self.separatorKeyline = separatorKeyline;
	
	[NSLayoutConstraint activateConstraints:@[
		[titleLabel.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
		[valueLabel.leftAnchor constraintGreaterThanOrEqualToAnchor:titleLabel.rightAnchor constant:8],
		[valueLabel.rightAnchor constraintEqualToAnchor:layoutGuide.rightAnchor],
		[titleLabel.centerYAnchor constraintEqualToAnchor:valueLabel.centerYAnchor],
		[titleLabel.topAnchor constraintEqualToAnchor:layoutGuide.topAnchor],
		[titleLabel.bottomAnchor constraintEqualToAnchor:layoutGuide.bottomAnchor],
		[separatorKeyline.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
		[separatorKeyline.rightAnchor constraintEqualToAnchor:layoutGuide.rightAnchor],
		[separatorKeyline.heightAnchor constraintEqualToConstant:1],
		[separatorKeyline.bottomAnchor constraintEqualToAnchor:self.bottomAnchor],
	]];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	
	[style.defaultTextStyle applyToLabel:self.titleLabel];
	self.titleLabel.font = [UIFont systemFontOfSize:13.0];
	[style.defaultTextStyle applyToLabel:self.valueLabel];
	self.valueLabel.font = [UIFont boldSystemFontOfSize:13.0];
	
	self.separatorKeyline.backgroundColor = [style.keylineColor colorWithAlphaComponent:0.25];
}

@end

#pragma mark - AWFLightningSummaryDetailsView Class Implementation

@implementation AWFLightningSummaryDetailsView

@synthesize contentEdgeInsets = _contentEdgeInsets;

- (void)setMinValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	AWFLightningSummaryDetailsItemView *itemView = self.viewsByType[@(weatherType)];
	if (itemView) {
		itemView.minValueLabel.text = value;
	}
}

- (void)setMaxValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	AWFLightningSummaryDetailsItemView *itemView = self.viewsByType[@(weatherType)];
	if (itemView) {
		itemView.maxValueLabel.text = value;
	}
}

- (void)setAverageValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	AWFLightningSummaryDetailsItemView *itemView = self.viewsByType[@(weatherType)];
	if (itemView) {
		itemView.avgValueLabel.text = value;
	}
}

- (void)setup {
	[super setup];
	
	self.labelColumnWidth = 65.0f;
	
	NSMutableDictionary *viewsByType = [NSMutableDictionary new];
	NSArray *labels = @[
		@{
			@"typeKey": @(AWFWeatherDataTypeLightningPeakAmperage),
			@"labelText": AWFLocalizedString(@"Peak", nil)
		},
		@{
			@"typeKey": @(AWFWeatherDataTypeLightningPeakPositiveAmperage),
			@"labelText": AWFLocalizedString(@"Peak (+)", nil)
		},
		@{
			@"typeKey": @(AWFWeatherDataTypeLightningPeakNegativeAmperage),
			@"labelText": AWFLocalizedString(@"Peak (-)", nil)
		},
		@{
			@"typeKey": @(AWFWeatherDataTypeLightningSensorCount),
			@"labelText": AWFLocalizedString(@"Sensors", nil)
		},
	];
	
	NSMutableArray *constraints = [NSMutableArray new];
	
	AWFLightningSummaryDetailsItemView *headerView = [AWFLightningSummaryDetailsItemView new];
	headerView.header = YES;
	headerView.translatesAutoresizingMaskIntoConstraints = NO;
	headerView.preservesSuperviewLayoutMargins = YES;
	headerView.labelColumnWidth = self.labelColumnWidth;
	headerView.minValueLabel.text = AWFLocalizedString(@"Min", nil);
	headerView.maxValueLabel.text = AWFLocalizedString(@"Max", nil);
	headerView.avgValueLabel.text = AWFLocalizedString(@"Avg", nil);
	[self addSubview:headerView];
	viewsByType[@"header"] = headerView;
	
	[constraints addObjectsFromArray:@[
		[headerView.topAnchor constraintEqualToAnchor:self.topAnchor],
		[headerView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
		[headerView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
		[headerView.heightAnchor constraintEqualToConstant:24.0]
	]];
	
	__block UIView *lastView = headerView;
	[labels enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
		NSNumber *typeKey = obj[@"typeKey"];
		NSString *labelText = obj[@"labelText"];
		
		AWFWeatherDataType weatherType = (AWFWeatherDataType)typeKey.integerValue;
		AWFLightningSummaryDetailsItemView *itemView = [AWFLightningSummaryDetailsItemView new];
		itemView.translatesAutoresizingMaskIntoConstraints = NO;
		itemView.preservesSuperviewLayoutMargins = YES;
		itemView.labelColumnWidth = self.labelColumnWidth;
		itemView.titleLabel.text = labelText;
		[self addSubview:itemView];
		
		[constraints addObjectsFromArray:@[
			[itemView.topAnchor constraintEqualToAnchor:lastView.bottomAnchor constant:-1.0],
			[itemView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
			[itemView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
			[itemView.heightAnchor constraintEqualToConstant:34.0]
		]];
		
		viewsByType[@(weatherType)] = itemView;
		lastView = itemView;
	}];
	
	[constraints addObject:[lastView.bottomAnchor constraintEqualToAnchor:self.bottomAnchor]];
	
	self.viewsByType = viewsByType;
	
	[NSLayoutConstraint activateConstraints:constraints];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	[self.viewsByType enumerateKeysAndObjectsUsingBlock:^(NSNumber * _Nonnull key, AWFLightningSummaryDetailsItemView * _Nonnull view, BOOL * _Nonnull stop) {
		[view applyStyle:style];
	}];
}

@end

#pragma mark - AWFLightningSummaryDetailsItemView Class Implementation

@implementation AWFLightningSummaryDetailsItemView

- (void)setup {
	[super setup];
	
	UIView *labelBackgroundView = [UIView new];
	labelBackgroundView.translatesAutoresizingMaskIntoConstraints = NO;
	labelBackgroundView.userInteractionEnabled = NO;
	[self addSubview:labelBackgroundView];
	self.labelBackgroundView = labelBackgroundView;
	
	UIView *topKeyline = [UIView new];
	topKeyline.translatesAutoresizingMaskIntoConstraints = NO;
	topKeyline.userInteractionEnabled = NO;
	[self addSubview:topKeyline];
	self.topKeyline = topKeyline;
	
	UIView *bottomKeyline = [UIView new];
	bottomKeyline.translatesAutoresizingMaskIntoConstraints = NO;
	bottomKeyline.userInteractionEnabled = NO;
	[self addSubview:bottomKeyline];
	self.bottomKeyline = bottomKeyline;
	
	UILabel *titleLabel = [UILabel new];
	titleLabel.translatesAutoresizingMaskIntoConstraints = NO;
	titleLabel.font = [UIFont systemFontOfSize:13.0];
	titleLabel.textColor = UIColor.whiteColor;
	titleLabel.textAlignment = NSTextAlignmentRight;
	titleLabel.backgroundColor = UIColor.clearColor;
	[self addSubview:titleLabel];
	self.titleLabel = titleLabel;
	
	UILabel *minValueLabel = [UILabel new];
	minValueLabel.translatesAutoresizingMaskIntoConstraints = NO;
	minValueLabel.font = [UIFont boldSystemFontOfSize:13.0];
	minValueLabel.textColor = UIColor.whiteColor;
	minValueLabel.textAlignment = NSTextAlignmentRight;
	minValueLabel.backgroundColor = UIColor.clearColor;
	[self addSubview:minValueLabel];
	self.minValueLabel = minValueLabel;
	
	UILabel *maxValueLabel = [UILabel new];
	maxValueLabel.translatesAutoresizingMaskIntoConstraints = NO;
	maxValueLabel.font = [UIFont boldSystemFontOfSize:13.0];
	maxValueLabel.textColor = UIColor.whiteColor;
	maxValueLabel.textAlignment = NSTextAlignmentRight;
	maxValueLabel.backgroundColor = UIColor.clearColor;
	[self addSubview:maxValueLabel];
	self.maxValueLabel = maxValueLabel;
	
	UILabel *avgValueLabel = [UILabel new];
	avgValueLabel.translatesAutoresizingMaskIntoConstraints = NO;
	avgValueLabel.font = [UIFont boldSystemFontOfSize:13.0];
	avgValueLabel.textColor = UIColor.whiteColor;
	avgValueLabel.textAlignment = NSTextAlignmentRight;
	avgValueLabel.backgroundColor = UIColor.clearColor;
	[self addSubview:avgValueLabel];
	self.avgValueLabel = avgValueLabel;
	
	// layout
	NSMutableArray *constraints = [NSMutableArray new];
	UILayoutGuide *layoutGuides = self.layoutMarginsGuide;
	[constraints addObjectsFromArray:@[
		[topKeyline.topAnchor constraintEqualToAnchor:self.topAnchor],
		[topKeyline.leftAnchor constraintEqualToAnchor:self.leftAnchor],
		[topKeyline.rightAnchor constraintEqualToAnchor:self.rightAnchor],
		[topKeyline.heightAnchor constraintEqualToConstant:1.0],
		[bottomKeyline.bottomAnchor constraintEqualToAnchor:self.bottomAnchor],
		[bottomKeyline.leftAnchor constraintEqualToAnchor:self.leftAnchor],
		[bottomKeyline.rightAnchor constraintEqualToAnchor:self.rightAnchor],
		[bottomKeyline.heightAnchor constraintEqualToConstant:1.0],
		[labelBackgroundView.topAnchor constraintEqualToAnchor:self.topAnchor],
		[labelBackgroundView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
		[labelBackgroundView.bottomAnchor constraintEqualToAnchor:self.bottomAnchor],
		[titleLabel.leftAnchor constraintEqualToAnchor:layoutGuides.leftAnchor],
		[titleLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
		[minValueLabel.rightAnchor constraintEqualToAnchor:maxValueLabel.leftAnchor],
		[minValueLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
		[maxValueLabel.rightAnchor constraintEqualToAnchor:avgValueLabel.leftAnchor],
		[maxValueLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
		[avgValueLabel.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor],
		[avgValueLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor]
	]];
	
	self.labelColumnWidthConstraint = [labelBackgroundView.rightAnchor constraintEqualToAnchor:layoutGuides.leftAnchor constant:110.0];
	[constraints addObject:self.labelColumnWidthConstraint];
	
	NSArray *widthConstraints = @[
		[minValueLabel.widthAnchor constraintEqualToAnchor:self.widthAnchor multiplier:0.25],
		[maxValueLabel.widthAnchor constraintEqualToAnchor:self.widthAnchor multiplier:0.25],
		[avgValueLabel.widthAnchor constraintEqualToAnchor:self.widthAnchor multiplier:0.25]
	];
	self.valueColumnWidthConstraints = widthConstraints;
	[constraints addObjectsFromArray:widthConstraints];
	
	[NSLayoutConstraint activateConstraints:constraints];
}

- (void)layoutSubviews {
	[super layoutSubviews];
	
	if (CGRectGetWidth(self.frame) != self.lastWidth) {
		[self setNeedsUpdateConstraints];
		self.lastWidth = CGRectGetWidth(self.frame);
	}
}

- (void)updateConstraints {
	self.labelColumnWidthConstraint.constant = self.labelColumnWidth;
	
	CGFloat totalWidth = CGRectGetWidth(self.frame);
	if (totalWidth > 0) {
		CGFloat valueWidth = ((totalWidth - self.labelColumnWidth) / 3.0) / totalWidth;
		[self.valueColumnWidthConstraints enumerateObjectsUsingBlock:^(NSLayoutConstraint * _Nonnull constraint, NSUInteger idx, BOOL * _Nonnull stop) {
			constraint.constant = valueWidth;
		}];
	}
	
	[super updateConstraints];
}

- (void)setLabelColumnWidth:(CGFloat)labelColumnWidth {
	if (labelColumnWidth != _labelColumnWidth) {
		_labelColumnWidth = labelColumnWidth;
		[self setNeedsUpdateConstraints];
	}
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	
	[style.detailTextStyle applyToLabel:self.titleLabel];
	self.titleLabel.font = [UIFont systemFontOfSize:13.0];
	[style.defaultTextStyle applyToLabel:self.minValueLabel];
	self.minValueLabel.font = self.isHeader ? [UIFont systemFontOfSize:13.0]: [UIFont boldSystemFontOfSize:13.0];
	[style.defaultTextStyle applyToLabel:self.maxValueLabel];
	self.maxValueLabel.font = self.isHeader ? [UIFont systemFontOfSize:13.0]: [UIFont boldSystemFontOfSize:13.0];
	[style.defaultTextStyle applyToLabel:self.avgValueLabel];
	self.avgValueLabel.font = self.isHeader ? [UIFont systemFontOfSize:13.0]: [UIFont boldSystemFontOfSize:13.0];
	
	UIColor *keylineColor = style.keylineColor;
	UIColor *boxColor = keylineColor.awf_isLightColor ? [style.keylineColor awf_adjustBrightness:1.3] : [style.keylineColor awf_adjustBrightness:0.7];
	self.topKeyline.backgroundColor = keylineColor;
	self.bottomKeyline.backgroundColor = keylineColor;
	self.labelBackgroundView.backgroundColor = boxColor;
}

@end
