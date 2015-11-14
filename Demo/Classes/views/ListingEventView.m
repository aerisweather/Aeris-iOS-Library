//
//  LoadingStatusView.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

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
        self.autoresizingMask = UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleWidth;
		
		UIActivityIndicatorView *indicatorView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
		indicatorView.frame = CGRectMake(0, 0, 35.0, 35.0);
		indicatorView.alpha = 0;
		[self addSubview:indicatorView];
		
		UILabel *messageLabel = [[UILabel alloc] initWithFrame:CGRectZero];
		messageLabel.backgroundColor = [UIColor clearColor];
		messageLabel.text = @"";
		messageLabel.textColor = [UIColor darkGrayColor];
		messageLabel.font = [UIFont boldSystemFontOfSize:18.0];
		messageLabel.textAlignment = NSTextAlignmentCenter;
		messageLabel.numberOfLines = 0;
		messageLabel.alpha = 0;
		[self addSubview:messageLabel];
		
		UILabel *detailedMessageLabel = [[UILabel alloc] initWithFrame:CGRectZero];
		detailedMessageLabel.backgroundColor = [UIColor clearColor];
		detailedMessageLabel.text = @"";
		detailedMessageLabel.textColor = [UIColor darkGrayColor];
		detailedMessageLabel.font = [UIFont systemFontOfSize:16.0];
		detailedMessageLabel.textAlignment = NSTextAlignmentCenter;
		detailedMessageLabel.numberOfLines = 0;
		detailedMessageLabel.alpha = 0;
		[self addSubview:detailedMessageLabel];
		
		self.indicatorView = indicatorView;
		self.messageLabel = messageLabel;
		self.detailedMessageLabel = detailedMessageLabel;
		
		self.hidden = YES;
    }
    return self;
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

- (void)layoutSubviews {
	[super layoutSubviews];
	
	CGSize indicatorSize = self.indicatorView.frame.size;
	self.indicatorView.frame = CGRectMake(CGRectGetMidX(self.bounds) - indicatorSize.width / 2.0,
										  CGRectGetMidY(self.bounds) - indicatorSize.height / 2.0,
										  indicatorSize.width, indicatorSize.height);
	
	CGRect contentFrame = UIEdgeInsetsInsetRect(self.bounds, UIEdgeInsetsMake(20.0, 20.0, 20.0, 20.0));
	CGSize messageSize = [self.messageLabel.text boundingRectWithSize:contentFrame.size options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName: self.messageLabel.font} context:nil].size;
	
	if (AWFIsNonEmptyString(self.detailedMessageLabel.text)) {
		CGSize detailsSize = [self.detailedMessageLabel.text boundingRectWithSize:contentFrame.size options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName: self.detailedMessageLabel.font} context:nil].size;
		
		CGFloat totalHeight = messageSize.height + 20.0 + detailsSize.height;
		CGFloat marginY = (CGRectGetHeight(contentFrame) - totalHeight) / 2.0;
		
		self.messageLabel.frame = CGRectMake(CGRectGetMinX(contentFrame), marginY, CGRectGetWidth(contentFrame), messageSize.height);
		self.detailedMessageLabel.frame = CGRectMake(CGRectGetMinX(contentFrame), CGRectGetMaxY(self.messageLabel.frame) + 20.0,
													 CGRectGetWidth(contentFrame), detailsSize.height);
	}
	else {
		self.messageLabel.frame = CGRectMake(CGRectGetMinX(contentFrame), CGRectGetMidY(self.bounds) - messageSize.height / 2.0,
											 CGRectGetWidth(contentFrame), messageSize.height);
	}
}

- (void)setBackgroundColor:(UIColor *)backgroundColor {
	[super setBackgroundColor:backgroundColor];
	
	self.indicatorView.activityIndicatorViewStyle = ([backgroundColor awf_isLightColor]) ? UIActivityIndicatorViewStyleGray : UIActivityIndicatorViewStyleWhite;
}

@end
