//
//  AWFCollectionViewForecast24HourCell.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFTableViewForecast24HourCell.h"
#import "AWFForecastDetailView.h"
#import "AWFStyledHeaderView.h"
#import "AWFCascadingStyle.h"

@interface AWFTableViewForecast24HourCell()
@property (nonatomic, strong) AWFStyledHeaderView *headerView;
@property (nonatomic, strong) AWFForecastDetailView *firstPeriodView;
@property (nonatomic, strong) AWFForecastDetailView *secondPeriodView;
@end

@implementation AWFTableViewForecast24HourCell

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
	[self.contentView addSubview:headerView];
	self.headerView = headerView;
	
	UILabel *dayLabel = [UILabel new];
	dayLabel.translatesAutoresizingMaskIntoConstraints = NO;
	dayLabel.font = [UIFont boldSystemFontOfSize:12.0];
	dayLabel.textColor = [UIColor whiteColor];
	dayLabel.backgroundColor = [UIColor clearColor];
	dayLabel.minimumScaleFactor = 0.9;
	dayLabel.text = @"--";
	[self.contentView addSubview:dayLabel];
	self.periodLabel = dayLabel;
	
	UILabel *dateLabel = [UILabel new];
	dateLabel.translatesAutoresizingMaskIntoConstraints = NO;
	dateLabel.font = [UIFont systemFontOfSize:11.0];
	dateLabel.textColor = [UIColor grayColor];
	dateLabel.backgroundColor = [UIColor clearColor];
	dateLabel.minimumScaleFactor = 0.9;
	dateLabel.text = @"";
	[self.contentView addSubview:dateLabel];
	self.dateLabel = dateLabel;
	
	AWFForecastDetailView *firstPeriodView = [AWFForecastDetailView new];
	firstPeriodView.translatesAutoresizingMaskIntoConstraints = NO;
	firstPeriodView.layoutMargins = UIEdgeInsetsZero;
	firstPeriodView.showsPeriod = NO;
	[self.contentView addSubview:firstPeriodView];
	self.firstPeriodView = firstPeriodView;
	
	AWFForecastDetailView *secondPeriodView = [AWFForecastDetailView new];
	secondPeriodView.translatesAutoresizingMaskIntoConstraints = NO;
	secondPeriodView.layoutMargins = UIEdgeInsetsZero;
	secondPeriodView.showsPeriod = NO;
	[self.contentView addSubview:secondPeriodView];
	self.secondPeriodView = secondPeriodView;
	
	UILayoutGuide *layoutGuide = self.contentView.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[[headerView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor],
											  [headerView.leftAnchor constraintEqualToAnchor:self.contentView.leftAnchor],
											  [headerView.rightAnchor constraintEqualToAnchor:self.contentView.rightAnchor],
											  [headerView.heightAnchor constraintEqualToConstant:25.0],
											  [dayLabel.centerYAnchor constraintEqualToAnchor:headerView.centerYAnchor],
											  [dayLabel.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
											  [dateLabel.centerYAnchor constraintEqualToAnchor:dayLabel.centerYAnchor],
											  [dateLabel.leftAnchor constraintEqualToAnchor:dayLabel.rightAnchor constant:8.0],
											  [firstPeriodView.topAnchor constraintEqualToAnchor:headerView.bottomAnchor],
											  [firstPeriodView.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
											  [firstPeriodView.rightAnchor constraintEqualToAnchor:layoutGuide.centerXAnchor constant:-5.0],
											  [firstPeriodView.bottomAnchor constraintEqualToAnchor:layoutGuide.bottomAnchor],
											  [secondPeriodView.topAnchor constraintEqualToAnchor:firstPeriodView.topAnchor],
											  [secondPeriodView.leftAnchor constraintEqualToAnchor:layoutGuide.centerXAnchor constant:5.0],
											  [secondPeriodView.rightAnchor constraintEqualToAnchor:layoutGuide.rightAnchor],
											  [secondPeriodView.bottomAnchor constraintEqualToAnchor:firstPeriodView.bottomAnchor]]];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[style.headerTextStyle applyToLabel:self.periodLabel withFontSize:self.periodLabel.font.pointSize];
	[style.headerDetailTextStyle applyToLabel:self.dateLabel withFontSize:self.dateLabel.font.pointSize];
	
	[self.headerView applyStyle:style];
	[self.firstPeriodView applyStyle:style];
	[self.secondPeriodView applyStyle:style];
}

@end
