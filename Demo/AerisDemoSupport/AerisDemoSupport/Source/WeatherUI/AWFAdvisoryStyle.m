//
//  AWFAdvisoryStyle.m
//  AerisUI
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFAdvisoryStyle.h"

@implementation AWFAdvisoryStyle

- (id)init {
	self = [super init];
	if (self) {
		
		self.backgroundColor = [UIColor whiteColor];
		self.backgroundGradientColors = nil;
		//self.headerBackgroundGradientColors = @[[UIColor awf_colorWithHex:@"#650303"], [UIColor awf_colorWithHex:@"#840202"], [UIColor awf_colorWithHex:@"#5a0000"]];
		self.headerBackgroundColor = [UIColor colorWithRed:0.757 green:0.000 blue:0.000 alpha:1.000];
		self.keylineColor = [UIColor awf_colorWithHex:@"#c80505"];
		
		// text styles
		AWFTextStyleSpec *defaultTextStyle = [[AWFTextStyleSpec alloc] init];
		defaultTextStyle.font = [UIFont systemFontOfSize:11.0];
		defaultTextStyle.textColor = [UIColor colorWithWhite:0.1 alpha:1.000];
		
		AWFTextStyleSpec *headerTextStyle = [[AWFTextStyleSpec alloc] init];
		headerTextStyle.font = [UIFont boldSystemFontOfSize:14.0];
		headerTextStyle.textColor = [UIColor colorWithWhite:1.000 alpha:1.000];
		
		AWFTextStyleSpec *headerDetailTextStyle = [[AWFTextStyleSpec alloc] init];
		headerDetailTextStyle.font = [UIFont systemFontOfSize:11.0];
		headerDetailTextStyle.textColor = [UIColor colorWithWhite:0.9 alpha:1.000];
		
		self.defaultTextStyle = defaultTextStyle;
		self.headerTextStyle = headerTextStyle;
		self.headerDetailTextStyle = headerDetailTextStyle;
		
	}
	return self;
}

@end
