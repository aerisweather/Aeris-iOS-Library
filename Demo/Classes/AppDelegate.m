//
//  AppDelegate.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AppDelegate.h"
#import "CatalogViewController.h"
#import "DetailedWeatherViewController_iPad.h"


@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

#if TARGET_IPHONE_SIMULATOR
#endif
	
	if ([application respondsToSelector:@selector(isRegisteredForRemoteNotifications)]) {
		UIUserNotificationSettings *notificationSettings = [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil];
		[[UIApplication sharedApplication] registerUserNotificationSettings:notificationSettings];
	} else {
	}
	
	[AerisEngine engineWithKey:@"__CLIENT_ID__" secret:@"__CLIENT_SECRET__"];
	[AerisEngine enableDebug];
	
	// must initialize Google Maps SDK with proper API key before using
	[GMSServices provideAPIKey:@"__GOOGLE_API_KEY__"];
	// must initialize Mapbox with proper token
	[MBXMapKit setAccessToken:@"__MAPBOX_KEY__"];
	
	// set the global style to use for Aeris weather views
	[AWFCascadingStyle setDefaultStyle:[AWFCascadingStyle style]];
	
	// setup preferences
	if (![Preferences sharedInstance].saved) {
		[Preferences sharedInstance].style = NSStringFromClass([[AWFCascadingStyle defaultStyle] class]);
		[Preferences sharedInstance].graphShowPoints = YES;
		[Preferences sharedInstance].graphShowLines = YES;
		[Preferences sharedInstance].saved = YES;
	}
	
	if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
		CatalogViewController *catalogController = [[CatalogViewController alloc] initWithNibName:nil bundle:nil];
		UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:catalogController];
		
		DetailedWeatherViewController_iPad *weatherController = [[DetailedWeatherViewController_iPad alloc] initWithNibName:nil bundle:nil];
		UINavigationController *weatherNavController = [[UINavigationController alloc] initWithRootViewController:weatherController];
		catalogController.masterViewController = weatherNavController;
		catalogController.delegate = weatherController;
		
		UISplitViewController *splitController = [[UISplitViewController alloc] initWithNibName:nil bundle:nil];
		splitController.presentsWithGesture = NO;
		splitController.delegate = weatherController;
		splitController.viewControllers = @[navController, weatherNavController];
		
		// handle the translucent status bar in iOS 7
		if (AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
			splitController.extendedLayoutIncludesOpaqueBars = YES;
		}
		
		self.window.rootViewController = splitController;
	}
	else {
		CatalogViewController *catalogController = [[CatalogViewController alloc] initWithNibName:nil bundle:nil];
		UINavigationController *rootController = [[UINavigationController alloc] initWithRootViewController:catalogController];
		
		// handle the translucent status bar in iOS 7
		if (AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
			//rootController.navigationBar.barTintColor = [UIColor blackColor];
			rootController.navigationBar.translucent = NO;
			rootController.extendedLayoutIncludesOpaqueBars = YES;
		}
		
		self.window.rootViewController = rootController;
	}
	
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    return YES;
}

@end
