//
//  ListingTableViewCell.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "ListingTableViewCell.h"

@implementation ListingTableViewCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:reuseIdentifier];
    if (self) {
		
		self.imageView.contentMode = UIViewContentModeScaleAspectFit;
        
//		CGFloat leftInset = (AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) ? 15.0 : 10.0;
//		CGRect contentFrame = UIEdgeInsetsInsetRect(self.bounds, UIEdgeInsetsMake(5.0, leftInset, 5.0, 10.0));
//		CGRect imageFrame = UIEdgeInsetsInsetRect(contentFrame, UIEdgeInsetsMake(3.0, 0, 3.0, 0));
//		imageFrame.size.width = CGRectGetHeight(imageFrame);
//		
//		self.imageView.frame = imageFrame;
//		self.imageView.contentMode = UIViewContentModeScaleAspectFit;
//		self.imageView.hidden = YES;
//        
//		UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMinX(contentFrame), CGRectGetMinY(contentFrame),
//																		CGRectGetWidth(contentFrame), 18.0)];
//		titleLabel.font = [UIFont systemFontOfSize:16.0];
//		titleLabel.textColor = [UIColor blackColor];
//		titleLabel.backgroundColor = [UIColor clearColor];
//		titleLabel.minimumScaleFactor = 0.8;
//		titleLabel.text = @"";
//		[self addSubview:titleLabel];
//		
//		UILabel *subtitleLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMinX(contentFrame), CGRectGetMaxY(titleLabel.frame),
//																		CGRectGetWidth(contentFrame), 12.0)];
//		subtitleLabel.font = [UIFont systemFontOfSize:10.0];
//		subtitleLabel.textColor = [UIColor grayColor];
//		subtitleLabel.backgroundColor = [UIColor clearColor];
//		subtitleLabel.minimumScaleFactor = 0.8;
//		subtitleLabel.text = @"";
//		[self addSubview:subtitleLabel];
//		
//		self.titleLabel = titleLabel;
//		self.subtitleLabel = subtitleLabel;
    }
    return self;
}

- (void)layoutSubviews {
	[super layoutSubviews];
	
	self.imageView.frame = CGRectInset(self.imageView.frame, 4.0, 4.0);
	
//	CGRect titleRect = self.titleLabel.frame;
//	CGRect subtitleRect = self.subtitleLabel.frame;
//	CGFloat widthAdjustForImage = CGRectGetMaxX(self.imageView.frame) - CGRectGetMinX(self.imageView.frame) + 10.0;
//	
//	if (self.imageView.image) {
//		self.imageView.hidden = NO;
//		titleRect.origin.x = CGRectGetMaxX(self.imageView.frame) + 10.0;
//		titleRect.size.width -= widthAdjustForImage;
//	}
//	else {
//		self.imageView.hidden = YES;
//		titleRect.origin.x = CGRectGetMinX(self.imageView.frame);
//		titleRect.size.width += widthAdjustForImage;
//	}
//	
//	subtitleRect.origin.x = CGRectGetMinX(titleRect);
//	subtitleRect.size.width = CGRectGetWidth(titleRect);
//	
//	self.titleLabel.frame = titleRect;
//	self.subtitleLabel.frame = subtitleRect;
}

@end
