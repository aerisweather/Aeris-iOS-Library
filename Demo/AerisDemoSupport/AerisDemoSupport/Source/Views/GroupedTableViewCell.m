//
//  GroupedTableViewCell.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCore/AerisCore.h>
#import "GroupedTableViewCell.h"

@interface GroupedTableViewCell ()
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *valueLabel;
@end

@implementation GroupedTableViewCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
	self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
	if (self) {
		UILabel *titleLabel = [UILabel new];
		titleLabel.translatesAutoresizingMaskIntoConstraints = NO;
		titleLabel.font = [UIFont systemFontOfSize:14.0];
		titleLabel.textColor = [UIColor blackColor];
		titleLabel.backgroundColor = [UIColor clearColor];
		titleLabel.minimumScaleFactor = 0.8;
		titleLabel.text = @"";
		[self.contentView addSubview:titleLabel];
		self.titleLabel = titleLabel;

		UILabel *valueLabel = [UILabel new];
		valueLabel.translatesAutoresizingMaskIntoConstraints = NO;
		valueLabel.font = [UIFont boldSystemFontOfSize:14.0];
		valueLabel.textColor = [UIColor blackColor];
		valueLabel.textAlignment = NSTextAlignmentRight;
		valueLabel.backgroundColor = [UIColor clearColor];
		valueLabel.minimumScaleFactor = 0.8;
		valueLabel.text = @"";
		[self.contentView addSubview:valueLabel];
		self.valueLabel = valueLabel;
		
		UILayoutGuide *layoutGuide = self.contentView.layoutMarginsGuide;
		[NSLayoutConstraint activateConstraints:@[[titleLabel.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
												  [titleLabel.centerYAnchor constraintEqualToAnchor:layoutGuide.centerYAnchor],
												  [titleLabel.widthAnchor constraintEqualToAnchor:layoutGuide.widthAnchor multiplier:0.4],
												  [valueLabel.leftAnchor constraintEqualToAnchor:titleLabel.rightAnchor],
												  [valueLabel.rightAnchor constraintEqualToAnchor:layoutGuide.rightAnchor],
												  [valueLabel.centerYAnchor constraintEqualToAnchor:layoutGuide.centerYAnchor]]];
	}

	return self;
}

@end
