//
//  AWFCollectionViewObservationRowCityCell.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFTableViewObservationRowCityCell.h"
#import "AWFStyledHeaderView.h"
#import "AWFCascadingStyle.h"

@implementation AWFTableViewObservationRowCityCell

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
	headerView.layout = AWFLayoutHorizontal;
	[self.contentView addSubview:headerView];
	self.headerView = headerView;
	
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
											  [headerView.rightAnchor constraintEqualToAnchor:self.contentView.rightAnchor],
											  [headerView.heightAnchor constraintEqualToConstant:25.0],
											  [iconView.topAnchor constraintEqualToAnchor:headerView.bottomAnchor constant:5.0],
											  [iconView.leftAnchor constraintEqualToAnchor:layoutGuides.leftAnchor],
											  [iconView.bottomAnchor constraintEqualToAnchor:layoutGuides.bottomAnchor],
											  [iconView.widthAnchor constraintEqualToConstant:45.0],
											  [iconView.heightAnchor constraintEqualToConstant:45.0],
											  [tempLabel.centerYAnchor constraintEqualToAnchor:iconView.centerYAnchor],
											  [tempLabel.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor constant:-10.0],
											  [weatherLabel.centerYAnchor constraintEqualToAnchor:iconView.centerYAnchor],
											  [weatherLabel.leftAnchor constraintEqualToAnchor:iconView.rightAnchor constant:10.0],
											  [weatherLabel.rightAnchor constraintEqualToAnchor:tempLabel.leftAnchor constant:-10.0]]];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[style.detailTextStyle applyToLabel:self.weatherTextLabel withFontSize:self.weatherTextLabel.font.pointSize];
	[style.defaultTextStyle applyToLabel:self.tempTextLabel withFontSize:self.tempTextLabel.font.pointSize];
	
	[self.headerView applyStyle:style];
}


@end
