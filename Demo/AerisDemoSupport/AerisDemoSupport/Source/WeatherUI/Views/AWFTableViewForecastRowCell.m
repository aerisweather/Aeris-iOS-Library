//
//  AWFCollectionViewForecastRowCell.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/28/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFTableViewForecastRowCell.h"
#import "AWFStyledHeaderView.h"
#import "AWFCascadingStyle.h"

@interface AWFTableViewForecastRowCell()
@property (nonatomic, strong) AWFStyledHeaderView *headerView;
@end

@implementation AWFTableViewForecastRowCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
	self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        [self setup];
    }
    return self;
}

- (void)setup {	
	// default height is 60.0px, so assign a scale to the temp font sizes if this instance's height is higher or lower
	CGFloat heightScale = CGRectGetHeight(self.bounds) / 60.0;
	
	AWFStyledHeaderView *headerView = [AWFStyledHeaderView new];
	headerView.translatesAutoresizingMaskIntoConstraints = NO;
	headerView.layout = AWFLayoutVertical;
	[self addSubview:headerView];
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
	
	UILabel *hightempLabel = [UILabel new];
	hightempLabel.translatesAutoresizingMaskIntoConstraints = NO;
	hightempLabel.font = [UIFont systemFontOfSize:34.0 * heightScale];
	hightempLabel.textColor = [UIColor whiteColor];
	hightempLabel.textAlignment = NSTextAlignmentRight;
	hightempLabel.backgroundColor = [UIColor clearColor];
	hightempLabel.text = @"--";
	[self.contentView addSubview:hightempLabel];
	self.hightempLabel = hightempLabel;
	
	UILabel *lowtempLabel = [UILabel new];
	lowtempLabel.translatesAutoresizingMaskIntoConstraints = NO;
	lowtempLabel.font = [UIFont systemFontOfSize:26.0 * heightScale];
	lowtempLabel.textColor = [UIColor grayColor];
	lowtempLabel.textAlignment = NSTextAlignmentRight;
	lowtempLabel.backgroundColor = [UIColor clearColor];
	lowtempLabel.text = @"--";
	[self.contentView addSubview:lowtempLabel];
	self.lowtempLabel = lowtempLabel;
	
	// layout
	UILayoutGuide *layoutGuides = self.contentView.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[[headerView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor],
											  [headerView.leftAnchor constraintEqualToAnchor:self.contentView.leftAnchor],
											  [headerView.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor],
											  [headerView.widthAnchor constraintEqualToConstant:60.0],
											  [iconView.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
											  [iconView.leftAnchor constraintEqualToAnchor:headerView.rightAnchor constant:10.0],
											  [iconView.widthAnchor constraintEqualToConstant:45.0],
											  [iconView.heightAnchor constraintEqualToConstant:45.0],
											  [lowtempLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
											  [lowtempLabel.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor constant:-5.0],
											  [hightempLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
											  [hightempLabel.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor constant:-55.0],
											  [weatherLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
											  [weatherLabel.leftAnchor constraintEqualToAnchor:iconView.rightAnchor constant:10.0],
											  [weatherLabel.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor constant:-105.0]]];
}

- (void)applyStyle:(AWFCascadingStyle *)style {	
	[style.headerTextStyle applyToLabel:self.dayLabel withFontSize:self.dayLabel.font.pointSize];
	[style.headerDetailTextStyle applyToLabel:self.dateLabel withFontSize:self.dateLabel.font.pointSize];
	[style.defaultTextStyle applyToLabel:self.weatherTextLabel withFontSize:self.weatherTextLabel.font.pointSize];
	[style.defaultTextStyle applyToLabel:self.hightempLabel withFontSize:self.hightempLabel.font.pointSize];
	[style.defaultTextStyle applyToLabel:self.lowtempLabel withFontSize:self.lowtempLabel.font.pointSize];
	
	[self.headerView applyStyle:style];
}

#pragma mark - Properties

- (NSString *)day {
	return self.headerView.textLabel.text;
}
- (void)setDay:(NSString *)day {
	self.headerView.textLabel.text = day;
}

- (NSString *)date {
	return self.headerView.detailTextLabel.text;
}
- (void)setDate:(NSString *)date {
	self.headerView.detailTextLabel.text = date;
}

- (NSString *)weather {
	return self.weatherTextLabel.text;
}
- (void)setWeather:(NSString *)weather {
	self.weatherTextLabel.text = weather;
}

- (NSString *)hightemp {
	return self.hightempLabel.text;
}
- (void)setHightemp:(NSString *)hightemp {
	self.hightempLabel.text = hightemp;
}

- (NSString *)lowtemp {
	return self.lowtempLabel.text;
}
- (void)setLowtemp:(NSString *)lowtemp {
	self.lowtempLabel.text = lowtemp;
}

- (UIImage *)icon {
	return self.iconImageView.image;
}
- (void)setIcon:(UIImage *)icon {
	self.iconImageView.image = icon;
}

@end
