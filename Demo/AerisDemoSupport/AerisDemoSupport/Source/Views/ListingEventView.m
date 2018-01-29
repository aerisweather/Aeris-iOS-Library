//
//  LoadingStatusView.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "ListingEventView.h"

@interface ListingEventView ()
@property (nonatomic, strong) UIActivityIndicatorView *indicatorView;
@property (nonatomic, strong) UILabel *messageLabel;
@property (nonatomic, strong) UILabel *detailedMessageLabel;
@end

@implementation ListingEventView

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
		
		self.backgroundColor = [UIColor whiteColor];
		
		UIActivityIndicatorView *indicatorView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
		indicatorView.translatesAutoresizingMaskIntoConstraints = NO;
		indicatorView.frame = CGRectMake(0, 0, 35.0, 35.0);
		indicatorView.alpha = 0;
		[self addSubview:indicatorView];
		self.indicatorView = indicatorView;
		
		UILabel *messageLabel = [UILabel new];
		messageLabel.translatesAutoresizingMaskIntoConstraints = NO;
		messageLabel.backgroundColor = [UIColor clearColor];
		messageLabel.text = @"";
		messageLabel.textColor = [UIColor darkGrayColor];
		messageLabel.font = [UIFont boldSystemFontOfSize:18.0];
		messageLabel.textAlignment = NSTextAlignmentCenter;
		messageLabel.numberOfLines = 0;
		messageLabel.alpha = 0;
		[self addSubview:messageLabel];
		self.messageLabel = messageLabel;
		
		UILabel *detailedMessageLabel = [UILabel new];
		detailedMessageLabel.translatesAutoresizingMaskIntoConstraints = NO;
		detailedMessageLabel.backgroundColor = [UIColor clearColor];
		detailedMessageLabel.text = @"";
		detailedMessageLabel.textColor = [UIColor darkGrayColor];
		detailedMessageLabel.font = [UIFont systemFontOfSize:16.0];
		detailedMessageLabel.textAlignment = NSTextAlignmentCenter;
		detailedMessageLabel.numberOfLines = 0;
		detailedMessageLabel.alpha = 0;
		[self addSubview:detailedMessageLabel];
		self.detailedMessageLabel = detailedMessageLabel;
		
		// layout
		[NSLayoutConstraint activateConstraints:@[[indicatorView.centerXAnchor constraintEqualToAnchor:self.centerXAnchor],
												  [indicatorView.centerYAnchor constraintEqualToAnchor:self.centerYAnchor],
												  [indicatorView.widthAnchor constraintEqualToConstant:35.0],
												  [indicatorView.heightAnchor constraintEqualToConstant:35.0],
												  [messageLabel.centerXAnchor constraintEqualToAnchor:self.centerXAnchor],
												  [messageLabel.bottomAnchor constraintEqualToAnchor:self.centerYAnchor],
												  [detailedMessageLabel.topAnchor constraintLessThanOrEqualToAnchor:messageLabel.bottomAnchor constant:10.0],
												  [detailedMessageLabel.centerXAnchor constraintEqualToAnchor:messageLabel.centerXAnchor]]];
		
		self.hidden = YES;
    }
    return self;
}

- (void)layoutSubviews {
	[super layoutSubviews];
	
	self.messageLabel.preferredMaxLayoutWidth = CGRectGetWidth(self.frame) - 40.0;
	self.detailedMessageLabel.preferredMaxLayoutWidth = self.messageLabel.preferredMaxLayoutWidth;
}

- (void)showLoading {
	self.messageLabel.alpha = 0;
	self.indicatorView.alpha = 1;
	self.alpha = 1;
	[self.indicatorView startAnimating];
	self.hidden = NO;
}

- (void)showNoResultsMessage {
	[self showMessage:NSLocalizedString(@"No results found.", nil)];
}

- (void)showMessage:(NSString *)message {
	self.hidden = NO;
	self.alpha = 1;
	self.messageLabel.text = message;
	self.detailedMessageLabel.text = nil;
	self.detailedMessageLabel.alpha = 0;
	
	[self setNeedsLayout];
	
	[self.indicatorView stopAnimating];
	[UIView animateWithDuration:0.15 animations:^{
		self.messageLabel.alpha = 1;
		self.indicatorView.alpha = 0;
	} completion:^(BOOL finished) {
		// stub
	}];
}

- (void)showMessage:(NSString *)message withDetailedMessage:(NSString *)detailedMessage {
	self.hidden = NO;
	self.alpha = 1;
	self.messageLabel.text = message;
	self.detailedMessageLabel.text = detailedMessage;
	
	[self setNeedsLayout];
	
	[self.indicatorView stopAnimating];
	[UIView animateWithDuration:0.15 animations:^{
		self.messageLabel.alpha = 1;
		self.detailedMessageLabel.alpha = 1;
		self.indicatorView.alpha = 0;
	} completion:^(BOOL finished) {
		// stub
	}];
}

- (void)hide {
	[UIView animateWithDuration:0.15 animations:^{
		self.alpha = 0;
	}];
}

- (void)setBackgroundColor:(UIColor *)backgroundColor {
	[super setBackgroundColor:backgroundColor];
	self.indicatorView.activityIndicatorViewStyle = ([backgroundColor awf_isLightColor]) ? UIActivityIndicatorViewStyleGray : UIActivityIndicatorViewStyleWhite;
}

@end
