//
//  AWFForecastDetailView.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFForecastDetailView.h"
#import "AWFCascadingStyle.h"

@interface AWFForecastDetailView ()
@property (nonatomic, strong) UILabel *periodTextLabel;
@property (nonatomic, strong) UILabel *tempTextLabel;
@property (nonatomic, strong) UILabel *weatherTextLabel;
@property (nonatomic, strong) UILabel *windsTextLabel;
@property (nonatomic, strong) UILabel *windsDescriptionTextLabel;
@property (nonatomic, strong) UILabel *precipTextLabel;
@property (nonatomic, strong) UILabel *precipTypeTextLabel;
@property (nonatomic, strong) UIImageView *iconImageView;
@property (nonatomic, strong) UIView *detailsView;
@property (nonatomic, strong) NSArray *keylines;
@property (nonatomic, strong) NSLayoutConstraint *detailsBottomConstraint;
@property (nonatomic, strong) NSLayoutConstraint *weatherBottomConstraint;
@end

@implementation AWFForecastDetailView

- (void)setup {
	[super setup];
	
	self.showsPeriod = YES;
	
	UILabel *periodLabel = [UILabel new];
	periodLabel.translatesAutoresizingMaskIntoConstraints = NO;
	periodLabel.font = [UIFont boldSystemFontOfSize:11.0];
	periodLabel.textColor = [UIColor whiteColor];
	periodLabel.backgroundColor = [UIColor clearColor];
	periodLabel.minimumScaleFactor = 0.9;
	periodLabel.text = @"";
	[self addSubview:periodLabel];
	self.periodTextLabel = periodLabel;
	
	UIImageView *iconView = [UIImageView new];
	iconView.translatesAutoresizingMaskIntoConstraints = NO;
	iconView.contentMode = UIViewContentModeScaleAspectFit;
	[self addSubview:iconView];
	self.iconImageView = iconView;
	
	UILabel *tempLabel = [UILabel new];
	tempLabel.translatesAutoresizingMaskIntoConstraints = NO;
	tempLabel.font = [UIFont systemFontOfSize:36.0];
	tempLabel.textColor = [UIColor whiteColor];
	tempLabel.textAlignment = NSTextAlignmentRight;
	tempLabel.minimumScaleFactor = 0.9;
	tempLabel.backgroundColor = [UIColor clearColor];
	tempLabel.text = @"--";
	[self addSubview:tempLabel];
	self.tempTextLabel = tempLabel;
	
	UILabel *weatherLabel = [UILabel new];
	weatherLabel.translatesAutoresizingMaskIntoConstraints = NO;
	weatherLabel.font = [UIFont systemFontOfSize:11.0];
	weatherLabel.textColor = [UIColor whiteColor];
	weatherLabel.textAlignment = NSTextAlignmentRight;
	weatherLabel.minimumScaleFactor = 0.8;
	weatherLabel.backgroundColor = [UIColor clearColor];
	weatherLabel.text = @"--";
	[self addSubview:weatherLabel];
	self.weatherTextLabel = weatherLabel;
	
	UIView *detailsKeyline = [UIView new];
	detailsKeyline.translatesAutoresizingMaskIntoConstraints = NO;
	detailsKeyline.backgroundColor = [UIColor awf_colorWithHex:@"#444"];
	[self addSubview:detailsKeyline];
	
	UIView *detailView = [UIView new];
	detailView.translatesAutoresizingMaskIntoConstraints = NO;
	[self setupDetailsInView:detailView];
	[self addSubview:detailView];
	self.detailsView = detailView;
	
	self.keylines = @[detailsKeyline];
	
	UILayoutGuide *layoutGuides = self.layoutMarginsGuide;
	
	self.detailsBottomConstraint = [detailView.bottomAnchor constraintEqualToAnchor:layoutGuides.bottomAnchor];
	self.weatherBottomConstraint = [weatherLabel.bottomAnchor constraintEqualToAnchor:layoutGuides.bottomAnchor];
	
	[NSLayoutConstraint activateConstraints:@[[periodLabel.topAnchor constraintEqualToAnchor:layoutGuides.topAnchor],
											  [periodLabel.leftAnchor constraintEqualToAnchor:layoutGuides.leftAnchor],
											  [tempLabel.topAnchor constraintEqualToAnchor:periodLabel.bottomAnchor constant:2.0],
											  [tempLabel.rightAnchor constraintEqualToAnchor:iconView.leftAnchor constant:-5.0],
											  [iconView.topAnchor constraintEqualToAnchor:tempLabel.topAnchor constant:0],
											  [iconView.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor],
											  [iconView.widthAnchor constraintEqualToConstant:53.0],
											  [iconView.heightAnchor constraintEqualToConstant:53.0],
											  [weatherLabel.topAnchor constraintEqualToAnchor:tempLabel.bottomAnchor constant:0],
											  [weatherLabel.leftAnchor constraintEqualToAnchor:layoutGuides.leftAnchor],
											  [weatherLabel.rightAnchor constraintEqualToAnchor:tempLabel.rightAnchor],
											  [detailView.topAnchor constraintEqualToAnchor:iconView.bottomAnchor constant:20.0],
											  [detailView.leftAnchor constraintEqualToAnchor:layoutGuides.leftAnchor],
											  [detailView.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor],
											  [detailsKeyline.bottomAnchor constraintEqualToAnchor:detailView.topAnchor constant:-5.0],
											  [detailsKeyline.leftAnchor constraintEqualToAnchor:layoutGuides.leftAnchor],
											  [detailsKeyline.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor],
											  [detailsKeyline.heightAnchor constraintEqualToConstant:1.0]]];
	
	[self applyStyle:self.style];
}

- (void)updateConstraints {
	if (self.detailsView.hidden) {
		self.detailsBottomConstraint.active = NO;
		self.weatherBottomConstraint.active = YES;
	} else {
		self.weatherBottomConstraint.active = NO;
		self.detailsBottomConstraint.active = YES;
	}
	
	[super updateConstraints];
}


- (void)setupDetailsInView:(UIView *)view {
	NSArray *labels = @[AWFLocalizedString(@"Winds", nil), AWFLocalizedString(@"Precip", nil)];
	NSMutableArray *constraints = [NSMutableArray new];
	
	__block UILabel *lastLabel = nil;
	[labels enumerateObjectsUsingBlock:^(NSString *labelText, NSUInteger idx, BOOL *stop) {
		UILabel *label = [UILabel new];
		label.translatesAutoresizingMaskIntoConstraints = NO;
		label.font = [UIFont systemFontOfSize:10.0];
		label.textColor = [UIColor whiteColor];
		label.textAlignment = NSTextAlignmentLeft;
		label.backgroundColor = [UIColor clearColor];
		label.text = labelText;
		[view addSubview:label];
		
		UILabel *valueLabel = [UILabel new];
		valueLabel.translatesAutoresizingMaskIntoConstraints = NO;
		valueLabel.font = [UIFont boldSystemFontOfSize:10.0];
		valueLabel.textColor = [UIColor whiteColor];
		valueLabel.textAlignment = NSTextAlignmentRight;
		valueLabel.backgroundColor = [UIColor clearColor];
		valueLabel.text = @"--";
		[view addSubview:valueLabel];
	
		if (idx == 0) {
			[constraints addObject:[label.topAnchor constraintEqualToAnchor:view.topAnchor]];
		} else {
			[constraints addObject:[label.topAnchor constraintEqualToAnchor:lastLabel.bottomAnchor constant:2.0]];
		}
		
		[constraints addObject:[label.leftAnchor constraintEqualToAnchor:view.leftAnchor]];
		[constraints addObject:[valueLabel.centerYAnchor constraintEqualToAnchor:label.centerYAnchor]];
		[constraints addObject:[valueLabel.rightAnchor constraintEqualToAnchor:view.rightAnchor]];
		
		lastLabel = label;
		
		if (idx == 0) {
			self.windsTextLabel = valueLabel;
			self.windsDescriptionTextLabel = label;
		} else if (idx == 1) {
			self.precipTextLabel = valueLabel;
			self.precipTypeTextLabel = label;
		}
	}];
	
	if (lastLabel) {
		[constraints addObject:[lastLabel.bottomAnchor constraintEqualToAnchor:view.bottomAnchor]];
	}
	
	[NSLayoutConstraint activateConstraints:constraints];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	
	[style.headerTextStyle applyToLabel:self.periodTextLabel withFontSize:11.0];
	[style.defaultTextStyle applyToLabel:self.tempTextLabel withFontSize:36.0];
	[style.defaultTextStyle applyToLabel:self.weatherTextLabel withFontSize:11.0];
	
	[style.defaultTextStyle applyToLabel:self.windsTextLabel withFontSize:10.0];
	[style.defaultTextStyle applyToLabel:self.precipTextLabel withFontSize:10.0];
	[style.detailTextStyle applyToLabel:self.windsDescriptionTextLabel withFontSize:10.0];
	[style.detailTextStyle applyToLabel:self.precipTypeTextLabel withFontSize:10.0];
	
	[self.keylines enumerateObjectsUsingBlock:^(UIView *keyline, NSUInteger idx, BOOL *stop) {
		keyline.backgroundColor = style.keylineColor;
	}];
}

- (void)layoutSubviews {
	[super layoutSubviews];
	
	UIDeviceOrientation orientation = [[UIDevice currentDevice] orientation];
	UIView *keyline = [self.keylines firstObject];
	
	// hide details if in landscape orientation
	if (UIDeviceOrientationIsLandscape(orientation)) {
		self.detailsView.hidden = YES;
		keyline.hidden = YES;
	} else {
		self.detailsView.hidden = NO;
		keyline.hidden = NO;
	}
	
	[self setNeedsUpdateConstraints];
}

#pragma mark - Properties

- (void)setShowsPeriod:(BOOL)showsPeriod {
	if (_showsPeriod != showsPeriod) {
		_showsPeriod = showsPeriod;
		[self setNeedsLayout];
	}
}

@end
