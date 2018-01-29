//
//  AWFStyledHeaderView.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFStyledHeaderView.h"
#import "AWFCascadingStyle.h"
#import "Drawing.h"

@interface AWFStyledHeaderView ()
@property (nonatomic, strong) AWFGradientView *backgroundView;
@property (nonatomic, strong) NSArray<NSLayoutConstraint *> *constraints;
@end

@implementation AWFStyledHeaderView

- (void)setup {
	[super setup];

	self.layout = AWFLayoutVertical;
	
	AWFGradientView *backgroundView = [AWFGradientView new];
	backgroundView.translatesAutoresizingMaskIntoConstraints = NO;
	[self addSubview:backgroundView];
	self.backgroundView = backgroundView;

	UILabel *titleLabel = [UILabel new];
	titleLabel.translatesAutoresizingMaskIntoConstraints = NO;
	titleLabel.font = [UIFont boldSystemFontOfSize:12.0];
	titleLabel.textColor = [UIColor whiteColor];
	titleLabel.backgroundColor = [UIColor clearColor];
	[self addSubview:titleLabel];
	self.textLabel = titleLabel;

	UILabel *detailLabel = [UILabel new];
	detailLabel.translatesAutoresizingMaskIntoConstraints = NO;
	detailLabel.font = [UIFont systemFontOfSize:11.0];
	detailLabel.textColor = [UIColor whiteColor];
	detailLabel.backgroundColor = [UIColor clearColor];
	[self addSubview:detailLabel];
	self.detailTextLabel = detailLabel;
	
	[NSLayoutConstraint activateConstraints:@[[backgroundView.topAnchor constraintEqualToAnchor:self.topAnchor],
											  [backgroundView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
											  [backgroundView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
											  [backgroundView.bottomAnchor constraintEqualToAnchor:self.bottomAnchor]]];
}

- (void)updateConstraints {
	[NSLayoutConstraint deactivateConstraints:self.constraints];
	
	UILayoutGuide *layoutGuide = self.layoutMarginsGuide;
	NSMutableArray *constraints = [NSMutableArray new];
	
	[constraints addObject:[self.textLabel.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor]];
	
	if (self.layout == AWFLayoutHorizontal) {
		[constraints addObjectsFromArray:@[[self.textLabel.centerYAnchor constraintEqualToAnchor:layoutGuide.centerYAnchor],
										   [self.detailTextLabel.leftAnchor constraintEqualToAnchor:self.textLabel.rightAnchor constant:10.0],
										   [self.detailTextLabel.centerYAnchor constraintEqualToAnchor:self.textLabel.centerYAnchor]]];
	} else {
		[constraints addObjectsFromArray:@[[self.textLabel.topAnchor constraintEqualToAnchor:layoutGuide.topAnchor],
										   [self.detailTextLabel.leftAnchor constraintEqualToAnchor:self.textLabel.leftAnchor],
										   [self.detailTextLabel.topAnchor constraintEqualToAnchor:self.textLabel.bottomAnchor constant:2.0]]];
	}
	
	self.constraints = constraints;
	[NSLayoutConstraint activateConstraints:self.constraints];
	
	[super updateConstraints];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];

	if (style.headerBackgroundGradientColors && [style.headerBackgroundGradientColors count] >= 2) {
		self.backgroundView.topColor = style.headerBackgroundGradientColors[0];
		self.backgroundView.bottomColor = style.headerBackgroundGradientColors[1];
	} else if (style.headerBackgroundColor) {
		self.backgroundView.backgroundColor = style.headerBackgroundColor;
	}

	[style.headerTextStyle applyToLabel:self.textLabel];
	[style.headerDetailTextStyle applyToLabel:self.detailTextLabel];
}

#pragma mark - Properties

- (void)setLayout:(AWFLayout)layout {
	if (layout != _layout) {
		_layout = layout;
		[self setNeedsUpdateConstraints];
	}
}

@end
