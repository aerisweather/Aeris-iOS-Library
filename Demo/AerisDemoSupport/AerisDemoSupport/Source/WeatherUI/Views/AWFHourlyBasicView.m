//
//  AFHourlyBasicView.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/28/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFHourlyBasicView.h"
#import "AWFCascadingStyle.h"
#import "Drawing.h"

@interface AWFHourlyBasicView ()

@end

@implementation AWFHourlyBasicView

- (void)setup {
	[super setup];
	
	UILabel *periodLabel = [UILabel new];
	periodLabel.translatesAutoresizingMaskIntoConstraints = NO;
	periodLabel.font = [UIFont boldSystemFontOfSize:11.0];
	periodLabel.textColor = [UIColor whiteColor];
	periodLabel.textAlignment = NSTextAlignmentCenter;
	periodLabel.backgroundColor = [UIColor clearColor];
	periodLabel.text = @"--";
	[self addSubview:periodLabel];
	self.periodLabel = periodLabel;
	
	UIImageView *iconView = [UIImageView new];
	iconView.translatesAutoresizingMaskIntoConstraints = NO;
	iconView.contentMode = UIViewContentModeScaleAspectFit;
	[self addSubview:iconView];
	self.iconImageView = iconView;
	
	UILabel *tempLabel = [UILabel new];
	tempLabel.translatesAutoresizingMaskIntoConstraints = NO;
	tempLabel.font = [UIFont systemFontOfSize:28.0];
	tempLabel.textColor = [UIColor whiteColor];
	tempLabel.textAlignment = NSTextAlignmentCenter;
	tempLabel.minimumScaleFactor = 0.9;
	tempLabel.backgroundColor = [UIColor clearColor];
	tempLabel.text = @"--";
	[self addSubview:tempLabel];
	self.tempTextLabel = tempLabel;
	
	UILabel *popLabel = [UILabel new];
	popLabel.translatesAutoresizingMaskIntoConstraints = NO;
	popLabel.font = [UIFont systemFontOfSize:12.0];
	popLabel.textColor = [UIColor lightGrayColor];
	popLabel.textAlignment = NSTextAlignmentCenter;
	popLabel.backgroundColor = [UIColor clearColor];
	popLabel.text = @"--";
	[self addSubview:popLabel];
	self.popLabel = popLabel;
	
	UILabel *precipLabel = [UILabel new];
	precipLabel.translatesAutoresizingMaskIntoConstraints = NO;
	precipLabel.font = [UIFont systemFontOfSize:12.0];
	precipLabel.textColor = [UIColor lightGrayColor];
	precipLabel.textAlignment = NSTextAlignmentCenter;
	precipLabel.backgroundColor = [UIColor clearColor];
	precipLabel.text = @"--";
	[self addSubview:precipLabel];
	self.precipLabel = precipLabel;
	
	UILabel *windsLabel = [UILabel new];
	windsLabel.translatesAutoresizingMaskIntoConstraints = NO;
	windsLabel.font = [UIFont systemFontOfSize:12.0];
	windsLabel.textColor = [UIColor lightGrayColor];
	windsLabel.textAlignment = NSTextAlignmentCenter;
	windsLabel.backgroundColor = [UIColor clearColor];
	windsLabel.text = @"--";
	[self addSubview:windsLabel];
	self.windsTextLabel = windsLabel;
	
	// set default colors
	self.periodBackgroundGradientColors = @[[UIColor awf_colorWithHex:@"#080808"], [UIColor awf_colorWithHex:@"#232323"], [UIColor awf_colorWithHex:@"#0f0f0f"]];
	
	UILayoutGuide *layoutGuides = self.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[[periodLabel.topAnchor constraintEqualToAnchor:self.topAnchor constant:4.0],
											  [periodLabel.centerXAnchor constraintEqualToAnchor:layoutGuides.centerXAnchor],
											  [iconView.topAnchor constraintEqualToAnchor:periodLabel.bottomAnchor constant:8.0],
											  [iconView.centerXAnchor constraintEqualToAnchor:layoutGuides.centerXAnchor],
											  [iconView.widthAnchor constraintEqualToConstant:45.0],
											  [iconView.heightAnchor constraintEqualToConstant:45.0],
											  [tempLabel.topAnchor constraintEqualToAnchor:iconView.bottomAnchor constant:1.0],
											  [tempLabel.centerXAnchor constraintEqualToAnchor:layoutGuides.centerXAnchor],
											  [popLabel.topAnchor constraintEqualToAnchor:tempLabel.bottomAnchor constant:8.0],
											  [popLabel.centerXAnchor constraintEqualToAnchor:layoutGuides.centerXAnchor],
											  [precipLabel.topAnchor constraintEqualToAnchor:popLabel.bottomAnchor constant:4.0],
											  [precipLabel.centerXAnchor constraintEqualToAnchor:layoutGuides.centerXAnchor],
											  [windsLabel.topAnchor constraintEqualToAnchor:precipLabel.bottomAnchor constant:4.0],
											  [windsLabel.centerXAnchor constraintEqualToAnchor:layoutGuides.centerXAnchor]]];
	
	[self applyStyle:self.style];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	
	[style.headerTextStyle applyToLabel:self.periodLabel];
	[style.defaultTextStyle applyToLabel:self.tempTextLabel withFontSize:28.0];
	[style.defaultTextStyle applyToLabel:self.popLabel];
	[style.defaultTextStyle applyToLabel:self.precipLabel];
	[style.defaultTextStyle applyToLabel:self.windsTextLabel];
}

- (void)layoutSubviews {
	[super layoutSubviews];
		
	if (CGRectGetHeight(self.frame) > 150.0) {
		self.popLabel.hidden = NO;
		self.precipLabel.hidden = NO;
		self.windsTextLabel.hidden = NO;
	} else {
		self.popLabel.hidden = YES;
		self.precipLabel.hidden = YES;
		self.windsTextLabel.hidden = YES;
	}
}

#pragma mark - Properties

- (NSString *)period {
	return self.periodLabel.text;
}
- (void)setPeriod:(NSString *)period {
	self.periodLabel.text = period;
}

- (NSString *)temp {
	return self.tempTextLabel.text;
}
- (void)setTemp:(NSString *)temp {
	self.tempTextLabel.text = temp;
}

- (NSString *)pop {
	return self.popLabel.text;
}
- (void)setPop:(NSString *)pop {
	self.popLabel.text = pop;
}

- (NSString *)precip {
	return self.precipLabel.text;
}
- (void)setPrecip:(NSString *)precip {
	self.precipLabel.text = precip;
}

- (NSString *)winds {
	return self.windsTextLabel.text;
}
- (void)setWinds:(NSString *)winds {
	self.windsTextLabel.text = winds;
}

- (UIImage *)icon {
	return self.iconImageView.image;
}
- (void)setIcon:(UIImage *)icon {
	self.iconImageView.image = icon;
}

- (void)setPeriodBackgroundColor:(UIColor *)periodBackgroundColor {
	if (_periodBackgroundColor != periodBackgroundColor) {
		_periodBackgroundColor = periodBackgroundColor;
		[self setNeedsDisplay];
	}
}

- (void)setPeriodBackgroundGradientColors:(NSArray *)periodBackgroundGradientColors {
	if (_periodBackgroundGradientColors != periodBackgroundGradientColors) {
		_periodBackgroundGradientColors = periodBackgroundGradientColors;
		[self setNeedsDisplay];
	}
}

- (void)drawRect:(CGRect)rect {
    [super drawRect:rect];
	
	CGContextRef context = UIGraphicsGetCurrentContext();
	CGRect periodRect = AWFRectMakeFromSize(CGRectGetWidth(rect), CGRectGetHeight(self.periodLabel.frame) + CGRectGetMinY(self.periodLabel.frame) * 2.0);
	
	if (self.style.headerBackgroundGradientColors && [self.style.headerBackgroundGradientColors count] >= 2) {
		AWFCGContextDrawGradientRectangle(context, periodRect, self.style.headerBackgroundGradientColors);
	} else {
		AWFCGContextDrawRectangle(context, periodRect, self.style.headerBackgroundColor.CGColor);
	}
}

@end
