//
//  AWFTableViewDailySummaryCell.m
//  AerisUI
//
//  Created by Nicholas Shipes on 8/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFTableViewDailySummaryCell.h"
#import "AWFDailySummaryView.h"

@interface AWFTableViewDailySummaryCell ()
@property (nonatomic, strong) AWFDailySummaryView *weatherView;
@end

@implementation AWFTableViewDailySummaryCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
	self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
	if (self) {
		[self setup];
	}
	return self;
}

- (void)setup {
	AWFDailySummaryView *weatherView = [AWFDailySummaryView new];
	weatherView.translatesAutoresizingMaskIntoConstraints = NO;
	[self.contentView addSubview:weatherView];
	self.weatherView = weatherView;
	
	[NSLayoutConstraint activateConstraints:@[[weatherView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor],
											  [weatherView.leftAnchor constraintEqualToAnchor:self.contentView.leftAnchor],
											  [weatherView.rightAnchor constraintEqualToAnchor:self.contentView.rightAnchor],
											  [weatherView.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor]]];
}

@end
