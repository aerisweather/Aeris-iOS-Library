//
//  AWFAdvisoryDetailView.m
//  AerisUI
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFAdvisoryDetailView.h"
#import "AWFStyledHeaderView.h"
#import "AWFAdvisoryStyle.h"

@interface AWFAdvisoryHeaderView : AWFStyledHeaderView
@end

@interface AWFAdvisoryDetailView ()
@property (nonatomic, strong) UILabel *bodyTextLabel;
@property (nonatomic, strong) UIView *keyline;
@end

@implementation AWFAdvisoryDetailView

- (void)setup {
	[super setup];
	
	UIView *keyline = [UIView new];
	keyline.translatesAutoresizingMaskIntoConstraints = NO;
	[self addSubview:keyline];
	self.keyline = keyline;
	
	AWFAdvisoryHeaderView *headerView = [AWFAdvisoryHeaderView new];
	headerView.translatesAutoresizingMaskIntoConstraints = NO;
	[self addSubview:headerView];
	self.headerView = headerView;
	
	UILabel *bodyLabel = [UILabel new];
	bodyLabel.translatesAutoresizingMaskIntoConstraints = NO;
	bodyLabel.font = [UIFont systemFontOfSize:11.0];
	bodyLabel.textColor = [UIColor blackColor];
	bodyLabel.backgroundColor = [UIColor clearColor];
	bodyLabel.text = @"--";
	bodyLabel.numberOfLines = 0;
	bodyLabel.lineBreakMode = NSLineBreakByWordWrapping;
	[self addSubview:bodyLabel];
	self.bodyTextLabel = bodyLabel;
	
	UILayoutGuide *layoutGuide = self.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[[keyline.topAnchor constraintEqualToAnchor:self.topAnchor],
											  [keyline.leftAnchor constraintEqualToAnchor:self.leftAnchor],
											  [keyline.rightAnchor constraintEqualToAnchor:self.rightAnchor],
											  [keyline.heightAnchor constraintEqualToConstant:3.0],
											  [headerView.topAnchor constraintEqualToAnchor:self.topAnchor],
											  [headerView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
											  [headerView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
											  [headerView.heightAnchor constraintEqualToConstant:40.0],
											  [bodyLabel.topAnchor constraintEqualToAnchor:headerView.bottomAnchor constant:8.0],
											  [bodyLabel.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
											  [bodyLabel.rightAnchor constraintEqualToAnchor:layoutGuide.rightAnchor],
											  [bodyLabel.bottomAnchor constraintEqualToAnchor:layoutGuide.bottomAnchor]]];
	
	[self applyStyle:[AWFAdvisoryStyle style]];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	
	[style.defaultTextStyle applyToLabel:self.bodyTextLabel];
	[self.headerView applyStyle:style];
	
	if (style.keylineColor) {
		self.keyline.backgroundColor = style.keylineColor;
	}
}

#pragma mark - Properties

- (UILabel *)nameTextLabel {
	return self.headerView.textLabel;
}

- (UILabel *)expiresTextLabel {
	return self.headerView.detailTextLabel;
}

@end


@implementation AWFAdvisoryHeaderView

- (void)layoutSubviews {
	[super layoutSubviews];
	
	CGRect contentFrame = UIEdgeInsetsInsetRect(self.bounds, self.contentEdgeInsets);
	
	[self.textLabel sizeToFit];
	[self.detailTextLabel sizeToFit];
	CGFloat contentHeight = CGRectGetHeight(self.textLabel.frame) + CGRectGetHeight(self.detailTextLabel.frame);
	
	self.textLabel.frame = AWFRectSetOrigin(self.textLabel.frame, CGPointMake(CGRectGetMinX(contentFrame), CGRectGetMidY(self.bounds) - contentHeight / 2.0));
	self.textLabel.frame = AWFRectSetWidth(self.textLabel.frame, CGRectGetWidth(contentFrame));
	
	self.detailTextLabel.frame = AWFRectSetOrigin(self.detailTextLabel.frame, CGPointMake(CGRectGetMinX(contentFrame), CGRectGetMaxY(self.textLabel.frame) - 1.0));
	self.detailTextLabel.frame = AWFRectSetWidth(self.detailTextLabel.frame, CGRectGetWidth(contentFrame));
}

@end
