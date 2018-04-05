//
//  AWFObservationAdvisoriesView.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>
#import "AWFObservationAdvisoriesView.h"
#import "AWFStyledHeaderView.h"
#import "AWFAdvisoryStyle.h"

@interface AWFAdvisoryItemView : UIView
@property (nonatomic, strong) UILabel *nameLabel;
@property (nonatomic, strong) UILabel *expiresLabel;
@end

@interface AWFObservationAdvisoriesView ()
@property (nonatomic, strong) NSArray *advisoryViews;
@property (nonatomic, strong) UIView *contentView;
@end

@implementation AWFObservationAdvisoriesView

- (void)setup {
	[super setup];
	
	UIEdgeInsets margins = self.layoutMargins;
	margins.top = 0;
	margins.bottom = 0;
	
	AWFStyledHeaderView *headerView = [AWFStyledHeaderView new];
	headerView.translatesAutoresizingMaskIntoConstraints = NO;
	headerView.layoutMargins = margins;
	headerView.layout = AWFLayoutHorizontal;
	[self addSubview:headerView];
	self.headerView = headerView;
	
	UIScrollView *scrollView = [UIScrollView new];
	scrollView.translatesAutoresizingMaskIntoConstraints = NO;
	[self addSubview:scrollView];
	self.scrollView = scrollView;
	
	UIView *contentView = [UIView new];
	contentView.translatesAutoresizingMaskIntoConstraints = NO;
	[scrollView addSubview:contentView];
	self.contentView = contentView;
	
	[NSLayoutConstraint activateConstraints:@[[headerView.topAnchor constraintEqualToAnchor:self.topAnchor],
											  [headerView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
											  [headerView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
											  [headerView.heightAnchor constraintEqualToConstant:20.0],
											  [scrollView.topAnchor constraintEqualToAnchor:headerView.bottomAnchor],
											  [scrollView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
											  [scrollView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
											  [scrollView.bottomAnchor constraintEqualToAnchor:self.bottomAnchor],
											  [contentView.topAnchor constraintEqualToAnchor:scrollView.topAnchor],
											  [contentView.leftAnchor constraintEqualToAnchor:scrollView.leftAnchor],
											  [contentView.rightAnchor constraintEqualToAnchor:scrollView.rightAnchor],
											  [contentView.bottomAnchor constraintEqualToAnchor:scrollView.bottomAnchor],
											  [contentView.topAnchor constraintEqualToAnchor:headerView.bottomAnchor],
											  [contentView.bottomAnchor constraintEqualToAnchor:self.bottomAnchor]]];
	
	AWFAdvisoryStyle *style = [AWFAdvisoryStyle new];
	//style.backgroundGradientColors = @[[UIColor awf_colorWithHex:@"#7e0101"], [UIColor awf_colorWithHex:@"#aa1212"]];
	style.backgroundColor = [UIColor colorWithRed:0.757 green:0.000 blue:0.000 alpha:1.000];
	style.headerBackgroundColor = [UIColor colorWithRed:0.618 green:0.000 blue:0.000 alpha:1.000];
	style.defaultTextStyle.textColor = [UIColor whiteColor];
	style.headerTextStyle.textColor = [UIColor whiteColor];
	[self applyStyle:style];
	[self.headerView applyStyle:style];
	
	// adjust font size down on header text after styles assigned
	headerView.textLabel.font = [headerView.textLabel.font fontWithSize:12.0];
}

#pragma mark - Properties

- (void)setAdvisories:(NSArray *)advisories {
	if (_advisories != advisories) {
		_advisories = advisories;
		[self updateAdvisories:advisories];
	}
}

#pragma mark - Private Methods

- (void)updateAdvisories:(NSArray<AWFAdvisory *> *)advisories {
	// remove all container views first
	[self.contentView.subviews makeObjectsPerformSelector:@selector(removeFromSuperview)];
	
	NSMutableArray *constraints = [NSMutableArray new];
	NSMutableArray *views = [NSMutableArray new];
	
	UIEdgeInsets margins = self.layoutMargins;
	margins.top = 4.0;
	margins.bottom = 4.0;
	
	__block UIView *lastView = nil;
	[advisories enumerateObjectsUsingBlock:^(AWFAdvisory *advisory, NSUInteger idx, BOOL *stop) {
		AWFAdvisoryItemView *itemView = [AWFAdvisoryItemView new];
		itemView.translatesAutoresizingMaskIntoConstraints = NO;
		itemView.layoutMargins = margins;
		itemView.nameLabel.text = [advisory.name uppercaseString];
		itemView.expiresLabel.text = [advisory.expires awf_formattedDateWithFormat:@"'until' h:mm a 'on' EEEE" timeZone:advisory.place.timeZone];
		[self.contentView addSubview:itemView];
		
		[constraints addObjectsFromArray:@[[itemView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor],
										   [itemView.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor]]];
		
		if (idx == 0) {
			[constraints addObject:[itemView.leftAnchor constraintEqualToAnchor:self.contentView.leftAnchor]];
		} else {
			[constraints addObject:[itemView.leftAnchor constraintEqualToAnchor:lastView.rightAnchor constant:20.0]];
		}
		
		[views addObject:itemView];
		lastView = itemView;
	}];
	
	if (lastView) {
		[constraints addObject:[lastView.rightAnchor constraintEqualToAnchor:self.contentView.rightAnchor]];
	}
	
	self.advisoryViews = views;
	[NSLayoutConstraint activateConstraints:constraints];
}

@end


@implementation AWFAdvisoryItemView

- (instancetype)initWithFrame:(CGRect)frame {
	self = [super initWithFrame:frame];
	if (self) {
		[self setup];
	}
	return self;
}

- (instancetype)init {
	self = [super init];
	if (self) {
		[self setup];
	}
	return self;
}

- (void)setup {
	UILabel *nameLabel = [UILabel new];
	nameLabel.translatesAutoresizingMaskIntoConstraints = NO;
	nameLabel.font = [UIFont boldSystemFontOfSize:11.0];
	nameLabel.textColor = [UIColor whiteColor];
	[self addSubview:nameLabel];
	self.nameLabel = nameLabel;
	
	UILabel *expiresLabel = [UILabel new];
	expiresLabel.translatesAutoresizingMaskIntoConstraints = NO;
	expiresLabel.font = [UIFont systemFontOfSize:10.0];
	expiresLabel.textColor = [UIColor whiteColor];
	[self addSubview:expiresLabel];
	self.expiresLabel = expiresLabel;
	
	UILayoutGuide *layoutGuide = self.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[[nameLabel.topAnchor constraintEqualToAnchor:layoutGuide.topAnchor],
											  [nameLabel.leftAnchor constraintEqualToAnchor:layoutGuide.leftAnchor],
											  [expiresLabel.topAnchor constraintEqualToAnchor:nameLabel.bottomAnchor],
											  [expiresLabel.leftAnchor constraintEqualToAnchor:nameLabel.leftAnchor]]];
}

- (void)layoutSubviews {
	[super layoutSubviews];
	//
}

- (CGSize)intrinsicContentSize {
	[self layoutIfNeeded];
	return CGSizeMake(MAX(CGRectGetWidth(self.nameLabel.frame), CGRectGetWidth(self.expiresLabel.frame)), UIViewNoIntrinsicMetric);
}

@end
