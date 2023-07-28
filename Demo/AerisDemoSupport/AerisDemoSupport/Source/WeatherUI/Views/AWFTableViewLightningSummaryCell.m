//
//  AWFTableViewLightningSummaryCell.m
//  AerisDemoSupport
//
//  Created by Slipp Douglas Thompson on 5/31/23.
//  Copyright © 2023 AerisWeather, LLC. All rights reserved.
//

#import "AWFTableViewLightningSummaryCell.h"
#import "AWFLightningSummaryView.h"

@interface AWFTableViewLightningSummaryCell ()
@property (nonatomic, strong) AWFLightningSummaryView *weatherView;
@end

@implementation AWFTableViewLightningSummaryCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
	self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
	if (self) {
		[self setup];
	}
	return self;
}

- (void)setup {
	AWFLightningSummaryView *weatherView = [AWFLightningSummaryView new];
	weatherView.translatesAutoresizingMaskIntoConstraints = NO;
	[self.contentView addSubview:weatherView];
	self.weatherView = weatherView;
	
	[NSLayoutConstraint activateConstraints:@[
		[weatherView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor],
		[weatherView.leftAnchor constraintEqualToAnchor:self.contentView.leftAnchor],
		[weatherView.rightAnchor constraintEqualToAnchor:self.contentView.rightAnchor],
		[weatherView.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor],
	]];
}

@end
