//
//  AWFCollectionViewObservationRowCell.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFTableViewObservationRowCell.h"
#import "AWFStyledHeaderView.h"
#import "AWFCascadingStyle.h"

@implementation AWFTableViewObservationRowCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
	self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        [self setup];
    }
    return self;
}

- (void)setup {
	AWFStyledHeaderView *headerView = [AWFStyledHeaderView new];
	headerView.translatesAutoresizingMaskIntoConstraints = NO;
	headerView.layout = AWFLayoutVertical;
	[self.contentView addSubview:headerView];
	self.headerView = headerView;
	
	// weather
	UIImageView *iconView = [UIImageView new];
	iconView.translatesAutoresizingMaskIntoConstraints = NO;
	iconView.contentMode = UIViewContentModeScaleAspectFit;
	[self.contentView addSubview:iconView];
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
	[self.contentView addSubview:weatherLabel];
	self.weatherTextLabel = weatherLabel;
	
	UILabel *tempLabel = [UILabel new];
	tempLabel.translatesAutoresizingMaskIntoConstraints = NO;
	tempLabel.font = [UIFont systemFontOfSize:34.0];
	tempLabel.textColor = [UIColor whiteColor];
	tempLabel.textAlignment = NSTextAlignmentRight;
	tempLabel.backgroundColor = [UIColor clearColor];
	tempLabel.text = @"--";
	[self.contentView addSubview:tempLabel];
	self.tempTextLabel = tempLabel;
	
	// layout
	UILayoutGuide *layoutGuides = self.contentView.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[[headerView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor],
											  [headerView.leftAnchor constraintEqualToAnchor:self.contentView.leftAnchor],
											  [headerView.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor],
											  [headerView.widthAnchor constraintEqualToConstant:75.0],
											  [iconView.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
											  [iconView.leftAnchor constraintEqualToAnchor:headerView.rightAnchor constant:10.0],
											  [iconView.widthAnchor constraintEqualToConstant:45.0],
											  [iconView.heightAnchor constraintEqualToConstant:45.0],
											  [tempLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
											  [tempLabel.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor constant:-10.0],
											  [weatherLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
											  [weatherLabel.leftAnchor constraintEqualToAnchor:iconView.rightAnchor constant:10.0],
											  [weatherLabel.rightAnchor constraintEqualToAnchor:tempLabel.leftAnchor constant:-10.0]]];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[style.detailTextStyle applyToLabel:self.weatherTextLabel withFontSize:self.weatherTextLabel.font.pointSize];
	[style.defaultTextStyle applyToLabel:self.tempTextLabel withFontSize:self.tempTextLabel.font.pointSize];
	
	[self.headerView applyStyle:style];
}

@end
