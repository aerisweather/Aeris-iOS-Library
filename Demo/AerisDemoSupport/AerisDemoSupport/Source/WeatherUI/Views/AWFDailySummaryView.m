//
//  AWFDailySummaryView.m
//  AerisUI
//
//  Created by Nicholas Shipes on 8/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFDailySummaryView.h"
#import "AWFStyledHeaderView.h"
#import "AWFCascadingStyle.h"
#import "Drawing.h"

@interface AWFDailySummaryDetailsItemView : AWFStyledView
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

@interface AWFDailySummaryDetailsView : AWFStyledView
@property (nonatomic, assign) CGFloat labelColumnWidth;
@property (nonatomic, strong) NSDictionary<NSNumber *, AWFDailySummaryDetailsItemView *> *viewsByType;
- (void)setMinValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
- (void)setMaxValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
- (void)setAverageValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType;
@end

@interface AWFDailySummaryView ()
@property (nonatomic, strong) AWFStyledHeaderView *headerView;
@property (nonatomic, strong) UILabel *periodTextLabel;
@property (nonatomic, strong) UILabel *weatherTextLabel;
@property (nonatomic, strong) UILabel *hightempLabel;
@property (nonatomic, strong) UILabel *lowtempLabel;
@property (nonatomic, strong) UIImageView *iconImageView;
@property (nonatomic, strong) AWFDailySummaryDetailsView *detailsView;
@end

@implementation AWFDailySummaryView

- (void)setMinValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	[self.detailsView setMinValue:value forWeatherType:weatherType];
}

- (void)setMaxValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	[self.detailsView setMaxValue:value forWeatherType:weatherType];
}

- (void)setAverageValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	[self.detailsView setAverageValue:value forWeatherType:weatherType];
}

- (void)setup {
	[super setup];

	AWFStyledHeaderView *headerView = [AWFStyledHeaderView new];
	headerView.translatesAutoresizingMaskIntoConstraints = NO;
	headerView.layout = AWFLayoutHorizontal;
	[self addSubview:headerView];
	self.headerView = headerView;

	// period
	UILabel *periodLabel = [UILabel new];
	periodLabel.translatesAutoresizingMaskIntoConstraints = NO;
	periodLabel.font = [UIFont boldSystemFontOfSize:11.0];
	periodLabel.textColor = [UIColor whiteColor];
	periodLabel.backgroundColor = [UIColor clearColor];
	periodLabel.minimumScaleFactor = 0.9;
	periodLabel.text = @"";
	[self addSubview:periodLabel];

	// weather
	UIImageView *iconView = [UIImageView new];
	iconView.translatesAutoresizingMaskIntoConstraints = NO;
	iconView.contentMode = UIViewContentModeScaleAspectFit;
	[self addSubview:iconView];
	self.iconImageView = iconView;

	UILabel *weatherLabel = [UILabel new];
	weatherLabel.translatesAutoresizingMaskIntoConstraints = NO;
	weatherLabel.font = [UIFont systemFontOfSize:11.0];
	weatherLabel.textColor = [UIColor lightGrayColor];
	weatherLabel.textAlignment = NSTextAlignmentLeft;
	weatherLabel.minimumScaleFactor = 0.8;
	weatherLabel.numberOfLines = 3;
	weatherLabel.lineBreakMode = NSLineBreakByWordWrapping;
	weatherLabel.backgroundColor = [UIColor clearColor];
	weatherLabel.text = @"--";
	[self addSubview:weatherLabel];
	self.weatherTextLabel = weatherLabel;

	UILabel *hightempLabel = [UILabel new];
	hightempLabel.translatesAutoresizingMaskIntoConstraints = NO;
	hightempLabel.font = [UIFont systemFontOfSize:34.0];
	hightempLabel.textColor = [UIColor whiteColor];
	hightempLabel.textAlignment = NSTextAlignmentRight;
	hightempLabel.backgroundColor = [UIColor clearColor];
	hightempLabel.text = @"--";
	[self addSubview:hightempLabel];
	self.hightempLabel = hightempLabel;

	UILabel *lowtempLabel = [UILabel new];
	lowtempLabel.translatesAutoresizingMaskIntoConstraints = NO;
	lowtempLabel.font = [UIFont systemFontOfSize:26.0];
	lowtempLabel.textColor = [UIColor grayColor];
	lowtempLabel.textAlignment = NSTextAlignmentRight;
	lowtempLabel.backgroundColor = [UIColor clearColor];
	lowtempLabel.text = @"--";
	[self addSubview:lowtempLabel];
	self.lowtempLabel = lowtempLabel;
	
	AWFDailySummaryDetailsView *detailsView = [AWFDailySummaryDetailsView new];
	detailsView.translatesAutoresizingMaskIntoConstraints = NO;
	detailsView.labelColumnWidth = 90.0;
	[self addSubview:detailsView];
	self.detailsView = detailsView;
	
	UILayoutGuide *layoutGuide = self.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[[headerView.topAnchor constraintEqualToAnchor:self.topAnchor],
											  [headerView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
											  [headerView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
											  [headerView.heightAnchor constraintEqualToConstant:25.0],
											  [iconView.topAnchor constraintEqualToAnchor:headerView.bottomAnchor constant:6.0],
											  [iconView.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
											  [iconView.widthAnchor constraintEqualToConstant:45.0],
											  [iconView.heightAnchor constraintEqualToConstant:45.0],
											  [weatherLabel.leftAnchor constraintEqualToAnchor:iconView.rightAnchor constant:10.0],
											  [weatherLabel.centerYAnchor constraintEqualToAnchor:iconView.centerYAnchor],
											  [lowtempLabel.rightAnchor constraintEqualToAnchor:layoutGuide.rightAnchor constant:-5.0],
											  [lowtempLabel.centerYAnchor constraintEqualToAnchor:iconView.centerYAnchor],
											  [hightempLabel.rightAnchor constraintEqualToAnchor:lowtempLabel.leftAnchor constant:-10.0],
											  [hightempLabel.centerYAnchor constraintEqualToAnchor:lowtempLabel.centerYAnchor],
//											  [detailsView.topAnchor constraintEqualToAnchor:iconView.bottomAnchor constant:6.0],
											  [detailsView.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
											  [detailsView.rightAnchor constraintEqualToAnchor:layoutGuide.rightAnchor],
											  [detailsView.bottomAnchor constraintEqualToAnchor:layoutGuide.bottomAnchor]]];

	[self applyStyle:self.style];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];

	[style.defaultTextStyle applyToLabel:self.weatherTextLabel withFontSize:self.weatherTextLabel.font.pointSize];
	[style.defaultTextStyle applyToLabel:self.hightempLabel withFontSize:self.hightempLabel.font.pointSize];
	[style.defaultTextStyle applyToLabel:self.lowtempLabel withFontSize:self.lowtempLabel.font.pointSize];
	
	[self.headerView applyStyle:style];
	[self.detailsView applyStyle:style];

	[self setNeedsDisplay];
}

@end


@implementation AWFDailySummaryDetailsView

@synthesize contentEdgeInsets = _contentEdgeInsets;

- (void)setMinValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	AWFDailySummaryDetailsItemView *itemView = self.viewsByType[@(weatherType)];
	if (itemView) {
		itemView.minValueLabel.text = value;
	}
}

- (void)setMaxValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	AWFDailySummaryDetailsItemView *itemView = self.viewsByType[@(weatherType)];
	if (itemView) {
		itemView.maxValueLabel.text = value;
	}
}

- (void)setAverageValue:(NSString *)value forWeatherType:(AWFWeatherDataType)weatherType {
	AWFDailySummaryDetailsItemView *itemView = self.viewsByType[@(weatherType)];
	if (itemView) {
		itemView.avgValueLabel.text = value;
	}
}

- (void)setup {
	[super setup];
	
	self.labelColumnWidth = 65.0f;
	
	NSMutableDictionary *viewsByType = [NSMutableDictionary new];
	NSDictionary *labels = @{
		@(AWFWeatherDataTypeWindSpeed):		AWFLocalizedString(@"Winds", nil),
		@(AWFWeatherDataTypeDewPoint):		AWFLocalizedString(@"Dew Point", nil),
		@(AWFWeatherDataTypeHumidity):		AWFLocalizedString(@"Humidity", nil),
		@(AWFWeatherDataTypePressure):		AWFLocalizedString(@"Pressure", nil),
		@(AWFWeatherDataTypePrecipitation): AWFLocalizedString(@"Precipitation", nil),
		@(AWFWeatherDataTypeSkyCover):		AWFLocalizedString(@"Sky", nil)
	};
	
	NSMutableArray *constraints = [NSMutableArray new];
	
	AWFDailySummaryDetailsItemView *headerView = [AWFDailySummaryDetailsItemView new];
	headerView.translatesAutoresizingMaskIntoConstraints = NO;
	headerView.labelColumnWidth = self.labelColumnWidth;
	headerView.minValueLabel.text = AWFLocalizedString(@"Min", nil);
	headerView.maxValueLabel.text = AWFLocalizedString(@"Max", nil);
	headerView.avgValueLabel.text = AWFLocalizedString(@"Avg", nil);
	[self addSubview:headerView];
	viewsByType[@"header"] = headerView;
	
	[constraints addObjectsFromArray:@[[headerView.topAnchor constraintEqualToAnchor:self.topAnchor],
									   [headerView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
									   [headerView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
									   [headerView.heightAnchor constraintEqualToConstant:20.0]]];
	
	__block UIView *lastView = headerView;
	[labels enumerateKeysAndObjectsUsingBlock:^(NSNumber *typeKey, NSString *labelText, BOOL *stop) {
		AWFWeatherDataType weatherType = (AWFWeatherDataType)[typeKey integerValue];
		AWFDailySummaryDetailsItemView *itemView = [AWFDailySummaryDetailsItemView new];
		itemView.translatesAutoresizingMaskIntoConstraints = NO;
		itemView.labelColumnWidth = self.labelColumnWidth;
		itemView.titleLabel.text = labelText;
		[self addSubview:itemView];
		
		[constraints addObjectsFromArray:@[[itemView.topAnchor constraintEqualToAnchor:lastView.bottomAnchor constant:-1.0],
										   [itemView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
										   [itemView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
										   [itemView.heightAnchor constraintEqualToConstant:20.0]]];
		
		viewsByType[@(weatherType)] = itemView;
		lastView = itemView;
	}];
	
	[constraints addObject:[lastView.bottomAnchor constraintEqualToAnchor:self.bottomAnchor]];
	
	self.viewsByType = viewsByType;
	
	[NSLayoutConstraint activateConstraints:constraints];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	[self.viewsByType enumerateKeysAndObjectsUsingBlock:^(NSNumber * _Nonnull key, AWFDailySummaryDetailsItemView * _Nonnull view, BOOL * _Nonnull stop) {
		[view applyStyle:style];
	}];
}

@end

@implementation AWFDailySummaryDetailsItemView

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
	titleLabel.font = [UIFont systemFontOfSize:11.0];
	titleLabel.textColor = [UIColor whiteColor];
	titleLabel.textAlignment = NSTextAlignmentRight;
	titleLabel.backgroundColor = [UIColor clearColor];
	[self addSubview:titleLabel];
	self.titleLabel = titleLabel;
	
	UILabel *minValueLabel = [UILabel new];
	minValueLabel.translatesAutoresizingMaskIntoConstraints = NO;
	minValueLabel.font = [UIFont boldSystemFontOfSize:11.0];
	minValueLabel.textColor = [UIColor whiteColor];
	minValueLabel.textAlignment = NSTextAlignmentRight;
	minValueLabel.backgroundColor = [UIColor clearColor];
	[self addSubview:minValueLabel];
	self.minValueLabel = minValueLabel;
	
	UILabel *maxValueLabel = [UILabel new];
	maxValueLabel.translatesAutoresizingMaskIntoConstraints = NO;
	maxValueLabel.font = [UIFont boldSystemFontOfSize:11.0];
	maxValueLabel.textColor = [UIColor whiteColor];
	maxValueLabel.textAlignment = NSTextAlignmentRight;
	maxValueLabel.backgroundColor = [UIColor clearColor];
	[self addSubview:maxValueLabel];
	self.maxValueLabel = maxValueLabel;
	
	UILabel *avgValueLabel = [UILabel new];
	avgValueLabel.translatesAutoresizingMaskIntoConstraints = NO;
	avgValueLabel.font = [UIFont boldSystemFontOfSize:11.0];
	avgValueLabel.textColor = [UIColor whiteColor];
	avgValueLabel.textAlignment = NSTextAlignmentRight;
	avgValueLabel.backgroundColor = [UIColor clearColor];
	[self addSubview:avgValueLabel];
	self.avgValueLabel = avgValueLabel;
	
	// layout
	NSMutableArray *constraints = [NSMutableArray new];
	UILayoutGuide *layoutGuides = self.layoutMarginsGuide;
	[constraints addObjectsFromArray:@[[topKeyline.topAnchor constraintEqualToAnchor:self.topAnchor],
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
									   [avgValueLabel.rightAnchor constraintEqualToAnchor:self.rightAnchor],
									   [avgValueLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor]]];
	
	self.labelColumnWidthConstraint = [labelBackgroundView.widthAnchor constraintEqualToConstant:110.0];
	[constraints addObject:self.labelColumnWidthConstraint];
	
	NSArray *widthConstraints = @[[minValueLabel.widthAnchor constraintEqualToAnchor:self.widthAnchor multiplier:0.25],
								  [maxValueLabel.widthAnchor constraintEqualToAnchor:self.widthAnchor multiplier:0.25],
								  [avgValueLabel.widthAnchor constraintEqualToAnchor:self.widthAnchor multiplier:0.25]];
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
	[style.defaultTextStyle applyToLabel:self.minValueLabel];
	[style.defaultTextStyle applyToLabel:self.maxValueLabel];
	[style.defaultTextStyle applyToLabel:self.avgValueLabel];
	
	UIColor *keylineColor = style.keylineColor;
	UIColor *boxColor = ([keylineColor awf_isLightColor]) ? [style.keylineColor awf_adjustBrightness:1.3] : [style.keylineColor awf_adjustBrightness:0.7];
	self.topKeyline.backgroundColor = keylineColor;
	self.bottomKeyline.backgroundColor = keylineColor;
	self.labelBackgroundView.backgroundColor = boxColor;
}

@end
