//
//  MultilineTextTableViewCell.m
//  AerisDemo
//
//  Created by Nicholas Shipes on 11/10/15.
//  Copyright © 2015 HAMweather, LLC. All rights reserved.
//

#import "MultilineTextTableViewCell.h"

@implementation MultilineTextTableViewCell

- (UIEdgeInsets)contentEdgeInsets {
	return UIEdgeInsetsMake(10, 10, 10, 10);
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
	self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
	if (self) {
		self.textLabel.font = [UIFont systemFontOfSize:14.0];
		self.textLabel.numberOfLines = 0;
		self.textLabel.lineBreakMode = NSLineBreakByWordWrapping;
	}
	
	return self;
}

- (void)layoutSubviews {
	[super layoutSubviews];
	
	UIEdgeInsets insets = self.contentEdgeInsets;
	self.textLabel.frame = AWFRectSetOrigin(self.textLabel.frame, CGPointMake(insets.left, insets.top));
	self.textLabel.frame = AWFRectSetSize(self.textLabel.frame, CGSizeMake(CGRectGetWidth(self.frame) - insets.left - insets.right, CGRectGetHeight(self.frame) - insets.top - insets.bottom));
}

- (CGSize)sizeThatFits:(CGSize)size {
	
	self.textLabel.frame = AWFRectSetWidth(self.textLabel.frame, CGRectGetWidth(self.contentView.frame) - CGRectGetMinX(self.textLabel.frame) * 2.0);
	[self.textLabel sizeToFit];
	
	size.height = CGRectGetHeight(self.textLabel.frame) + CGRectGetMinY(self.textLabel.frame) * 2.0;
	
	return size;
}

@end
