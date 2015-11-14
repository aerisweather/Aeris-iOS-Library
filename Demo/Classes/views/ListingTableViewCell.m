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
    }
    return self;
}

- (void)layoutSubviews {
	[super layoutSubviews];
	
	self.imageView.frame = CGRectInset(self.imageView.frame, 4.0, 4.0);
}

@end
