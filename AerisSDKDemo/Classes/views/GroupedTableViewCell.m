//
//  GroupedTableViewCell.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "GroupedTableViewCell.h"

@implementation GroupedTableViewCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
	self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
	if (self) {
		CGFloat leftInset = (AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) ? 15.0 : 20.0;
		CGFloat rightInset = (AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) ? 10.0 : 20.0;
		CGRect contentFrame = UIEdgeInsetsInsetRect(self.bounds, UIEdgeInsetsMake(0, leftInset, 0, rightInset));

		UILabel *descriptionLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMinX(contentFrame), 0,
		                                                                      CGRectGetWidth(contentFrame) * 0.4 - 5, CGRectGetHeight(self.bounds))];
		descriptionLabel.autoresizingMask = UIViewAutoresizingFlexibleHeight;
		descriptionLabel.font = [UIFont systemFontOfSize:14.0];
		descriptionLabel.textColor = [UIColor blackColor];
		descriptionLabel.backgroundColor = [UIColor clearColor];
		descriptionLabel.minimumScaleFactor = 0.8;
		descriptionLabel.text = @"";
		[self addSubview:descriptionLabel];

		UILabel *valueLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMaxX(descriptionLabel.frame) + 10.0, 0,
		                                                                CGRectGetWidth(contentFrame) * 0.6 - 5, CGRectGetHeight(self.bounds))];
		valueLabel.autoresizingMask = UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleLeftMargin;
		valueLabel.font = [UIFont boldSystemFontOfSize:14.0];
		valueLabel.textColor = [UIColor blackColor];
		valueLabel.textAlignment = NSTextAlignmentRight;
		valueLabel.backgroundColor = [UIColor clearColor];
		valueLabel.minimumScaleFactor = 0.8;
		valueLabel.text = @"";
		[self addSubview:valueLabel];

		self.descriptionLabel = descriptionLabel;
		self.valueLabel = valueLabel;
	}

	return self;
}

@end
