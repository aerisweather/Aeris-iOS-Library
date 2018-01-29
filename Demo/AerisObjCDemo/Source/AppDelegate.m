//
//  AppDelegate.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>
#import <Mapbox/Mapbox.h>
#import "AppDelegate.h"
#import "CatalogViewController.h"
#import "DetailedWeatherViewController_iPad.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

#if TARGET_IPHONE_SIMULATOR
	NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);
#endif
	[Fabric with:@[CrashlyticsKit]];
	
	[AerisWeather startWithApiKey:@"wgE96YE3scTQLKjnqiMsv" secret:@"nmq7XMXlOY7JyfuNZenfVTjsKCFnITbi8WBPbWDz"];
	[AWFLogger setLoggingLevel:AWFLogLevelDebug];
	
	// must initialize Google Maps SDK with proper API key before using
	[GMSServices provideAPIKey:@"AIzaSyBbkmhjf8EBV1YiYLWfybc6BzM0ua8A728"];
	// must initialize Mapbox with proper token
	[MGLAccountManager setAccessToken:@"pk.eyJ1IjoidTEwaW50IiwiYSI6InQtMnZvTkEifQ.c8mhXquPE7_xoB3P4Ag8cA"];
	
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

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
	NSLog(@"Failed to get device token, error: %@", error);
}

void uncaughtExceptionHandler(NSException *exception) {
    NSLog(@"CRASH: %@", exception);
    NSLog(@"Stack Trace: %@", [exception callStackSymbols]);
    // Internal error reporting
}

@end
