//
//  Preferences.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/7/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "Preferences.h"

NSString * const kMapControlTimeline	= @"timeline";
NSString * const kMapControlBasic		= @"basic";

@implementation Preferences

@dynamic style;
@dynamic mapControl;
@dynamic place;
@dynamic graphShowLines;
@dynamic graphShowPoints;
@dynamic graphSmoothLines;
@dynamic saved;

- (AWFCascadingStyle *)preferredStyle {
	NSString *styleClassName = [Preferences sharedInstance].style;
	if (styleClassName) {
		Class styleClass = NSClassFromString(styleClassName);
		return [styleClass style];
	}
	return nil;
}

- (NSString *)userIdentifier {
	NSString *userId = [[NSUserDefaults standardUserDefaults] stringForKey:@"userid"];
    if (userId == nil || userId.length == 0) {
		CFUUIDRef cfuuid = CFUUIDCreate(kCFAllocatorDefault);
		NSString *cfuuidString = (NSString*)CFBridgingRelease(CFUUIDCreateString(kCFAllocatorDefault, cfuuid));
		userId = [cfuuidString stringByReplacingOccurrencesOfString:@"-" withString:@""];
        [[NSUserDefaults standardUserDefaults] setObject:userId forKey:@"userid"];
		[[NSUserDefaults standardUserDefaults] synchronize];
    }
	
	return userId;
}

@end
