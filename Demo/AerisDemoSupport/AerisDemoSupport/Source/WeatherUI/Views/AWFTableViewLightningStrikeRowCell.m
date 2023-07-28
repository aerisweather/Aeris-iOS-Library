//
//  AWFTableViewLightningStrikeRowCell.m
//  AerisDemoSupport
//
//  Created by Slipp Douglas Thompson on 5/26/23.
//  Copyright © 2023 AerisWeather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFTableViewLightningStrikeRowCell.h"
#import "AWFStyledHeaderView.h"
#import "AWFCascadingStyle.h"

@implementation AWFTableViewLightningStrikeRowCell

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
	
	// location
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
	
	// pulse
	UILabel *peakAmperageLabel = [UILabel new];
	peakAmperageLabel.translatesAutoresizingMaskIntoConstraints = NO;
	peakAmperageLabel.font = [UIFont systemFontOfSize:12.0];
	peakAmperageLabel.textColor = UIColor.whiteColor;
	peakAmperageLabel.textAlignment = NSTextAlignmentRight;
	peakAmperageLabel.minimumScaleFactor = 0.8;
	peakAmperageLabel.backgroundColor = UIColor.clearColor;
	peakAmperageLabel.text = @"--";
	[self.contentView addSubview:peakAmperageLabel];
	self.peakAmperageLabel = peakAmperageLabel;
	
	UILabel *pulseTypeLabel = [UILabel new];
	pulseTypeLabel.translatesAutoresizingMaskIntoConstraints = NO;
	pulseTypeLabel.font = [UIFont systemFontOfSize:12.0];
	pulseTypeLabel.textColor = UIColor.whiteColor;
	pulseTypeLabel.textAlignment = NSTextAlignmentRight;
	pulseTypeLabel.backgroundColor = UIColor.clearColor;
	pulseTypeLabel.text = @"--";
	[self.contentView addSubview:pulseTypeLabel];
	self.pulseTypeLabel = pulseTypeLabel;
	
	UILabel *sensorCountLabel = [UILabel new];
	sensorCountLabel.translatesAutoresizingMaskIntoConstraints = NO;
	sensorCountLabel.font = [UIFont systemFontOfSize:12.0];
	sensorCountLabel.textColor = UIColor.whiteColor;
	sensorCountLabel.textAlignment = NSTextAlignmentRight;
	sensorCountLabel.backgroundColor = UIColor.clearColor;
	sensorCountLabel.text = @"--";
	[self.contentView addSubview:sensorCountLabel];
	self.sensorCountLabel = sensorCountLabel;
	
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
		[peakAmperageLabel.rightAnchor constraintEqualToAnchor:layoutGuide.rightAnchor],
		[pulseTypeLabel.topAnchor constraintEqualToAnchor:peakAmperageLabel.firstBaselineAnchor constant:1.0],
		[pulseTypeLabel.rightAnchor constraintEqualToAnchor:peakAmperageLabel.rightAnchor],
		[sensorCountLabel.topAnchor constraintEqualToAnchor:pulseTypeLabel.firstBaselineAnchor constant:1.0],
		[sensorCountLabel.bottomAnchor constraintEqualToAnchor:locationDetailLabel.bottomAnchor],
		[sensorCountLabel.rightAnchor constraintEqualToAnchor:layoutGuide.rightAnchor],
	]];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[style.defaultTextStyle applyToLabel:self.locationLabel];
	self.locationLabel.font = [UIFont systemFontOfSize:16.0];
	[style.detailTextStyle applyToLabel:self.locationDetailLabel];
	self.locationDetailLabel.font = [UIFont systemFontOfSize:12.0];
	
	[style.headerTextStyle applyToLabel:self.peakAmperageLabel];
	self.peakAmperageLabel.font = [UIFont systemFontOfSize:12.0];
	[style.headerTextStyle applyToLabel:self.pulseTypeLabel];
	self.pulseTypeLabel.font = [UIFont systemFontOfSize:12.0];
	[style.headerTextStyle applyToLabel:self.sensorCountLabel];
	self.sensorCountLabel.font = [UIFont systemFontOfSize:12.0];
	
	[self.headerView applyStyle:style];
	self.headerView.textLabel.font = [UIFont boldSystemFontOfSize:16.0];
	self.headerView.detailTextLabel.font = [UIFont systemFontOfSize:12.0];
}

- (UIEdgeInsets)layoutMargins {
	return UIEdgeInsetsMake(11, 8, 11, 8);
}

@end
