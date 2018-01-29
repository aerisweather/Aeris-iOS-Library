//
//  AWFLegacyStyle.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFLegacyStyle.h"

@implementation AWFLegacyStyle

- (id)init {
	self = [super init];
	if (self) {
		
		self.backgroundGradientColors = @[[UIColor awf_colorWithHex:@"#1d1d1d"], [UIColor awf_colorWithHex:@"#282828"]];
		self.headerBackgroundGradientColors = @[[UIColor awf_colorWithHex:@"#080808"], [UIColor awf_colorWithHex:@"#232323"], [UIColor awf_colorWithHex:@"#0f0f0f"]];
		self.viewControllerBackgroundColor = [UIColor colorWithWhite:0.05 alpha:1.0];
		
		self.keylineColor = [UIColor colorWithWhite:0.3 alpha:1.0];
		
		AWFTextStyleSpec *defaultTextStyle = [[AWFTextStyleSpec alloc] init];
		defaultTextStyle.font = [UIFont systemFontOfSize:12.0];
		defaultTextStyle.textColor = [UIColor whiteColor];
		
		AWFTextStyleSpec *detailTextStyle = [[AWFTextStyleSpec alloc] init];
		detailTextStyle.font = [UIFont systemFontOfSize:10.0];
		detailTextStyle.textColor = [UIColor colorWithWhite:0.85 alpha:1.0];
		
		AWFTextStyleSpec *headerTextStyle = [[AWFTextStyleSpec alloc] init];
		headerTextStyle.font = [UIFont systemFontOfSize:10.0];
		headerTextStyle.textColor = [UIColor whiteColor];
		
		AWFTextStyleSpec *headerDetailTextStyle = [[AWFTextStyleSpec alloc] init];
		headerDetailTextStyle.font = [UIFont systemFontOfSize:10.0];
		headerDetailTextStyle.textColor = [UIColor colorWithWhite:0.85 alpha:1.0];
		
		self.defaultTextStyle = defaultTextStyle;
		self.detailTextStyle = detailTextStyle;
		self.headerTextStyle = headerTextStyle;
		self.headerDetailTextStyle = headerDetailTextStyle;
	}
	return self;
}

@end
