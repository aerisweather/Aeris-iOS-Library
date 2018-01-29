//
//  AWFCascadingStyle.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFCascadingStyle.h"

static AWFCascadingStyle *defaultStyle;

@implementation AWFCascadingStyle

+ (instancetype)style {
//	static AWFCascadingStyle *_sharedStyle = nil;
//	NSLog(@"sharedStyle=%@, class=%@", _sharedStyle, NSStringFromClass([self class]));
//	static dispatch_once_t onceToken;
//	dispatch_once(&onceToken, ^{
//		_sharedStyle = [[[self class] alloc] init];
//	});
//	
//	return _sharedStyle;
	static NSMutableDictionary *styles = nil;
	if (!styles) {
		styles = [NSMutableDictionary dictionary];
	}
	
	NSString *key = NSStringFromClass(self);
	if (!styles[key]) {
		[styles setObject:[[self alloc] init] forKey:key];
	}
	return styles[key];
}

+ (instancetype)defaultStyle {
	if (!defaultStyle) {
		defaultStyle = [AWFCascadingStyle style];
	}
	return defaultStyle;
}

+ (void)setDefaultStyle:(AWFCascadingStyle *)style {
	defaultStyle = style;
}

#pragma mark - Instance Methods

- (id)init {
	self = [super init];
	if (self) {
		
		self.inset = 8.0f;
		
		self.backgroundColor = [UIColor colorWithWhite:0.98 alpha:1.0];
		//self.backgroundGradientColors = @[[UIColor awf_colorWithHex:@"#1d1d1d"], [UIColor awf_colorWithHex:@"#282828"]];
		self.headerBackgroundColor = [UIColor colorWithWhite:0.9 alpha:1.0];
		//self.headerBackgroundGradientColors = @[[UIColor awf_colorWithHex:@"#080808"], [UIColor awf_colorWithHex:@"#232323"], [UIColor awf_colorWithHex:@"#0f0f0f"]];
		self.viewControllerBackgroundColor = [self.backgroundColor awf_adjustBrightness:0.95];
		
		self.keylineColor = [UIColor colorWithWhite:0.7 alpha:1.0];
		
		// text styles
		AWFTextStyleSpec *defaultTextStyle = [[AWFTextStyleSpec alloc] init];
		defaultTextStyle.font = [UIFont systemFontOfSize:12.0];
		defaultTextStyle.textColor = [UIColor colorWithWhite:0.1 alpha:1.000];
		
		AWFTextStyleSpec *detailTextStyle = [[AWFTextStyleSpec alloc] init];
		detailTextStyle.font = [UIFont systemFontOfSize:10.0];
		detailTextStyle.textColor = [UIColor colorWithWhite:0.4 alpha:1.0];
		
		AWFTextStyleSpec *headerTextStyle = [[AWFTextStyleSpec alloc] init];
		headerTextStyle.font = [UIFont systemFontOfSize:14.0];
		headerTextStyle.textColor = [UIColor colorWithWhite:0.1 alpha:1.000];
		
		AWFTextStyleSpec *headerDetailTextStyle = [[AWFTextStyleSpec alloc] init];
		headerDetailTextStyle.font = [UIFont systemFontOfSize:12.0];
		headerDetailTextStyle.textColor = [UIColor colorWithWhite:0.2 alpha:1.0];
		
		self.defaultTextStyle = defaultTextStyle;
		self.detailTextStyle = detailTextStyle;
		self.headerTextStyle = headerTextStyle;
		self.headerDetailTextStyle = headerDetailTextStyle;
	}
	return self;
}

@end
