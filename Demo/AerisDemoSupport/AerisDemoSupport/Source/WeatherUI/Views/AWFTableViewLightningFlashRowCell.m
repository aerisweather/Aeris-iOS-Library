//
//  LightningFlashRowCell.m
//  AerisDemoSupport
//
//  Created by Slipp Douglas Thompson on 5/24/23.
//  Copyright © 2023 AerisWeather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFTableViewLightningFlashRowCell.h"
#import "AWFStyledHeaderView.h"
#import "AWFCascadingStyle.h"

@implementation AWFTableViewLightningFlashRowCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
	self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
	if (self) {
		[self setup];
	}
	return self;
}

- (void)setup {
	self.contentView.preservesSuperviewLayoutMargins = YES;
	
	AWFStyledHeaderView *headerView = [AWFStyledHeaderView new];
	headerView.translatesAutoresizingMaskIntoConstraints = NO;
	headerView.layout = AWFLayoutVertical;
	headerView.preservesSuperviewLayoutMargins = YES;
	[self.contentView addSubview:headerView];
	self.headerView = headerView;
	
	// weather
	UILabel *locationLabel = [UILabel new];
	locationLabel.translatesAutoresizingMaskIntoConstraints = NO;
	locationLabel.font = [UIFont systemFontOfSize:16.0];
	locationLabel.textColor = UIColor.whiteColor;
	locationLabel.textAlignment = NSTextAlignmentLeft;
	locationLabel.minimumScaleFactor = 0.8;
	locationLabel.backgroundColor = UIColor.clearColor;
	locationLabel.text = @"--";
	[self.contentView addSubview:locationLabel];
	self.locationLabel = locationLabel;
	
	UILabel *locationDetailLabel = [UILabel new];
	locationDetailLabel.translatesAutoresizingMaskIntoConstraints = NO;
	locationDetailLabel.font = [UIFont systemFontOfSize:12.0];
	locationDetailLabel.textColor = UIColor.whiteColor;
	locationDetailLabel.textAlignment = NSTextAlignmentLeft;
	locationDetailLabel.backgroundColor = UIColor.clearColor;
	locationDetailLabel.text = @"--";
	[self.contentView addSubview:locationDetailLabel];
	self.locationDetailLabel = locationDetailLabel;
	
	// layout
	UILayoutGuide *layoutGuide = self.contentView.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[
		[headerView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor],
		[headerView.leftAnchor constraintEqualToAnchor:self.contentView.leftAnchor],
		[headerView.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor],
		[headerView.widthAnchor constraintEqualToConstant:100.0],
		[locationLabel.topAnchor constraintEqualToAnchor:layoutGuide.topAnchor],
		[locationLabel.leftAnchor constraintEqualToAnchor:headerView.rightAnchor constant:20.0],
		[locationDetailLabel.leftAnchor constraintEqualToAnchor:locationLabel.leftAnchor],
		[locationDetailLabel.topAnchor constraintEqualToAnchor:locationLabel.bottomAnchor constant:2.0],
	]];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[style.defaultTextStyle applyToLabel:self.locationLabel];
	self.locationLabel.font = [UIFont systemFontOfSize:16.0];
	[style.detailTextStyle applyToLabel:self.locationDetailLabel];
	self.locationDetailLabel.font = [UIFont systemFontOfSize:12.0];
	
	[self.headerView applyStyle:style];
	self.headerView.textLabel.font = [UIFont boldSystemFontOfSize:16.0];
	self.headerView.detailTextLabel.font = [UIFont systemFontOfSize:12.0];
}

- (UIEdgeInsets)layoutMargins {
	return UIEdgeInsetsMake(11, 8, 11, 8);
}

@end
