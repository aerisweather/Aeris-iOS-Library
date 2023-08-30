//
//  AppDelegate.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisDemoSupport/AerisDemoSupport.h>
#if !TARGET_OS_UIKITFORMAC && !TARGET_OS_SIMULATOR
#import <GoogleMaps/GoogleMaps.h>
#import <Mapbox/Mapbox.h>
#endif
#import "AppDelegate.h"
#import "CatalogViewController.h"
#import "DetailedWeatherViewController_iPad.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

#if TARGET_IPHONE_SIMULATOR
#endif
	
	[AerisWeather startWithApiKey:@"__CLIENT_ID__" secret:@"__CLIENT_SECRET__"];
	[AWFLogger setLoggingLevel:AWFLogLevelDebug];
	
#if !TARGET_OS_UIKITFORMAC && !TARGET_OS_SIMULATOR
	if (@available(iOS 14, *)) { // GoogleMaps 8.x.x requires iOS ≥ 14
		// must initialize Google Maps SDK with proper API key before using
		[GMSServices provideAPIKey:@"__GOOGLE_KEY__"];
	}
	// must initialize Mapbox with proper token
	[MGLAccountManager setAccessToken:@"__MAPBOX_KEY__"];
#endif
	
	// set the global style to use for Aeris weather views
	[AWFCascadingStyle setDefaultStyle:[AWFCascadingStyle style]];
	
	[AWFNetworkActivityIndicatorManager sharedManager].enabled = YES;
	[[AWFNetworkActivityIndicatorManager sharedManager] setNetworkingActivityActionWithBlock:^(BOOL networkActivityIndicatorVisible) {
		[[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:networkActivityIndicatorVisible];
	}];
	
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(networkActivityStateDidChange:) name:AWFNetworkActivityStateDidStart object:nil];
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(networkActivityStateDidChange:) name:AWFNetworkActivityStateDidStop object:nil];
	
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
		navController.modalPresentationStyle = UIModalPresentationPopover;
		
		DetailedWeatherViewController_iPad *weatherController = [[DetailedWeatherViewController_iPad alloc] initWithNibName:nil bundle:nil];
		UINavigationController *weatherNavController = [[UINavigationController alloc] initWithRootViewController:weatherController];
		catalogController.masterViewController = weatherNavController;
		catalogController.delegate = weatherController;
		
		UISplitViewController *splitViewController = [[UISplitViewController alloc] initWithNibName:nil bundle:nil];
		splitViewController.presentsWithGesture = NO;
		splitViewController.delegate = weatherController;
		splitViewController.viewControllers = @[navController, weatherNavController];
		
		// handle the translucent status bar in iOS 7
		if (AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
			splitViewController.extendedLayoutIncludesOpaqueBars = YES;
		}
		
		self.window.rootViewController = splitViewController;
	} else {
		CatalogViewController *catalogController = [[CatalogViewController alloc] initWithNibName:nil bundle:nil];
		UINavigationController *rootController = [[UINavigationController alloc] initWithRootViewController:catalogController];
		
		// handle the translucent status bar in iOS 7
		if (AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
			rootController.navigationBar.backgroundColor = UIColor.whiteColor; // needed for iOS ≥14
			rootController.navigationBar.barTintColor = UIColor.whiteColor;
			rootController.navigationBar.translucent = NO;
			rootController.extendedLayoutIncludesOpaqueBars = YES;
		}
		
		self.window.rootViewController = rootController;
	}
	
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    return YES;
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
	NSLog(@"Failed to get device token, error: %@", error);
}

- (void)networkActivityStateDidChange:(NSNotification *)notification {
	[UIApplication sharedApplication].networkActivityIndicatorVisible = [AWFNetworkActivityIndicatorManager sharedManager].isNetworkActivityIndicatorVisible;
}

void uncaughtExceptionHandler(NSException *exception) {
    NSLog(@"CRASH: %@", exception);
    NSLog(@"Stack Trace: %@", [exception callStackSymbols]);
    // Internal error reporting
}

@end
