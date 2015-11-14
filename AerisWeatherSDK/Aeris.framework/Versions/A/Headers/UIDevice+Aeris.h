//
//  UIDevice+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 5/8/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

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
	
	AWFDevicePlatformIPad1,
	AWFDevicePlatformIPad2,
	AWFDevicePlatformIPadMini1,
	AWFDevicePlatformIPad3,
	AWFDevicePlatformIPad4,
	AWFDevicePlatformIPadAir,
	AWFDevicePlatformIPadMini2,
	AWFDevicePlatformIPadAir2,
	AWFDevicePlatformIPadMini3,
	
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

/**
 *  Provides extensions to `UIDevice` for retrieving device model and platform information.
 */
@interface UIDevice (Aeris)

/**
 *  Returns a machine-readable model name in the format of "iPhone4,1"
 */
- (NSString *)modelIdentifier;

/**
 *  Returns a human-readable model name in the format of "iPhone 4S". Fallback of the the `modelIdentifier` value.
 */
- (NSString *)modelName;

/**
 *  Returns the device platform as `AWFDevicePlatform`.
 */
- (AWFDevicePlatform)devicePlatform;

/**
 *  Returns the device family as a `AWFDeviceFamily`
 */
- (AWFDeviceFamily)deviceFamily;

/**
 *  Determines whether the current device platform is newer than the specified platform.
 *
 *  @param otherPlatform The other platform to determine if the current platform is newer.
 *
 *  @return `YES` if the current device platform is newer, otherwise `NO`.
 */
- (BOOL)isMoreRecentThanPlatform:(AWFDevicePlatform)otherPlatform;

@end
