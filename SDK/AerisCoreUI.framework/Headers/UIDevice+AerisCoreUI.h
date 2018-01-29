//
//  UIDevice+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/24/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AWFDevicePlatform) {
	AWFDevicePlatformUnknown = 0,
	
	AWFDevicePlatformIPhone1G,
	AWFDevicePlatformIPhone3G,
	AWFDevicePlatformIPhone3GS,
	AWFDevicePlatformIPhone4,
	AWFDevicePlatformIPhone4S,
	AWFDevicePlatformIPhone5,
	AWFDevicePlatformIPhone5S,
	AWFDevicePlatformIPhone5C,
	AWFDevicePlatformIPhone6,
	AWFDevicePlatformIPhone6Plus,
	AWFDevicePlatformIPhone6S,
	AWFDevicePlatformIPhone6SPlus,
	
	AWFDevicePlatformIPad1,
	AWFDevicePlatformIPad2,
	AWFDevicePlatformIPad3,
	AWFDevicePlatformIPad4,
	AWFDevicePlatformIPadAir,
	AWFDevicePlatformIPadAir2,
	
	AWFDevicePlatformIPadPro,
	
	AWFDevicePlatformIPadMini1,
	AWFDevicePlatformIPadMini2,
	AWFDevicePlatformIPadMini3,
	AWFDevicePlatformiPadMini4,
	
	AWFDevicePlatformIPod1G,
	AWFDevicePlatformIPod2G,
	AWFDevicePlatformIPod3G,
	AWFDevicePlatformIPod4G,
	AWFDevicePlatformIPod5G,
	
	AWFDevicePlatformAppleWatch,
	
	AWFDevicePlatformSimulator
};

typedef NS_ENUM(NSUInteger, AWFDeviceFamily) {
	AWFDeviceFamilyUnknown = 0,
	AWFDeviceFamilyiPhone,
	AWFDeviceFamilyiPod,
	AWFDeviceFamilyiPad,
	AWFDeviceFamilyAppleTV,
	AWFDeviceFamilyAppleWatch
};

@interface UIDevice (AerisCoreUI)

/**
 *  Returns a machine-readable model name in the format of "iPhone4,1"
 */
- (NSString *)awf_modelIdentifier;

/**
 *  Returns a human-readable model name in the format of "iPhone 4S". Fallback of the the `modelIdentifier` value.
 */
- (NSString *)awf_modelName;

/**
 *  Returns the device platform as `AWFDevicePlatform`.
 */
- (AWFDevicePlatform)awf_devicePlatform;

/**
 *  Returns the device family as a `AWFDeviceFamily`
 */
- (AWFDeviceFamily)awf_deviceFamily;

/**
 *  Determines whether the current device platform is newer than the specified platform.
 *
 *  @param otherPlatform The other platform to determine if the current platform is newer.
 *
 *  @return `YES` if the current device platform is newer, otherwise `NO`.
 */
- (BOOL)awf_isMoreRecentThanPlatform:(AWFDevicePlatform)otherPlatform;

@end

NS_ASSUME_NONNULL_END
