//
//  CLLocationManager+AerisCore.h
//  AerisCore
//
//  Created by Nicholas Shipes on 12/22/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

typedef double AWFCLUpdateAccuracyFilter;
typedef NSTimeInterval AWFCLLocationAgeFilter;

extern const AWFCLUpdateAccuracyFilter AWFCLUpdateAccuracyFilterNone;
extern const AWFCLLocationAgeFilter AWFCLLocationAgeFilterNone;

typedef NS_ENUM(NSUInteger, AWFCLLocationUpdateAuthorizationDescription) {
	AWFCLLocationUpdateAuthorizationDescriptionAlways,
	AWFCLLocationUpdateAuthorizationDescriptionWhenInUse,
};

//-----------------------------------------------------------------------------
// @name Blocks
//-----------------------------------------------------------------------------
typedef void (^AWFLocationManagerUpdateBlock)(CLLocationManager *manager, CLLocation *location, NSError *error, BOOL *stopUpdating);
typedef void (^AWFHeadingUpdateBlock)(CLLocationManager *manager, CLHeading *heading, NSError *error, BOOL *stopUpdating);
typedef void (^AWFDidChangeAuthorizationStatusBlock)(CLLocationManager *manager, CLAuthorizationStatus status);
typedef void (^AWFDidEnterRegionBlock)(CLLocationManager *manager, CLRegion *region);
typedef void (^AWFDidExitRegionBlock)(CLLocationManager *manager, CLRegion *region);
typedef void (^AWFMonitoringDidFailForRegionWithBlock)(CLLocationManager *manager, CLRegion *region, NSError *error);
typedef void (^AWFDidStartMonitoringForRegionWithBlock)(CLLocationManager *manager, CLRegion *region);
typedef void (^AWFDidUpdateLocationsBlock)(CLLocationManager *manager, NSArray *locations);
typedef void (^AWFDidUpdateHeadingBlock)(CLLocationManager *manager, CLHeading *heading);
typedef void (^AWFDidFailWithErrorBlock)(CLLocationManager *manager, NSError *error);
typedef BOOL (^AWFShouldDisplayHeadingCalibrationBlock)(CLLocationManager *manager);
typedef void (^AWFDidDetermineStateBlock)(CLLocationManager *manager, CLRegionState state, CLRegion *region);
typedef void (^AWFDidRangeBeaconsBlock)(CLLocationManager *manager, NSArray *beacons, CLBeaconRegion *region);
typedef void (^AWFRangingBeaconsDidFailForRegionBlock)(CLLocationManager *manager, CLBeaconRegion *region, NSError *error);
typedef void (^AWFLocationManagerDidPauseLocationUpdatesBlock)(CLLocationManager *manager);
typedef void (^AWFLocationManagerDidResumeLocationUpdatesBlock)(CLLocationManager *manager);
typedef void (^AWFDidFinishDeferredUpdatesWithErrorBlock)(CLLocationManager *manager, NSError *error);
typedef void (^AWFDidVisitBLock)(CLLocationManager *manager, CLVisit *visit);

@interface CLLocationManager (AerisCore)

@property (readonly, strong, nonatomic) id blocksDelegate;
@property (assign, nonatomic) AWFCLUpdateAccuracyFilter updateAccuracyFilter;
@property (assign, nonatomic) AWFCLLocationAgeFilter updateLocationAgeFilter;

+ (instancetype)updateManager;

+ (instancetype)updateManagerWithAccuracy:(AWFCLUpdateAccuracyFilter)updateAccuracyFilter
							  locationAge:(AWFCLLocationAgeFilter)updateLocationAgeFilter;

+ (instancetype)updateManagerWithAccuracy:(AWFCLUpdateAccuracyFilter)updateAccuracyFilter
							  locationAge:(AWFCLLocationAgeFilter)updateLocationAgeFilter
				  authorizationDesciption:(AWFCLLocationUpdateAuthorizationDescription)authorizationDescription NS_AVAILABLE_IOS(8_0);

+ (BOOL)isLocationUpdatesAvailable;

- (void)startUpdatingLocationWithUpdateBlock:(AWFLocationManagerUpdateBlock)updateBlock;
- (void)startUpdatingHeadingWithUpdateBlock:(AWFHeadingUpdateBlock)updateBlock;

//-----------------------------------------------------------------------------
// @name Delegate Replacements
//-----------------------------------------------------------------------------
- (void)didUpdateLocationsWithBlock:(AWFDidUpdateLocationsBlock)block;
- (void)didUpdateHeadingWithBlock:(AWFDidUpdateHeadingBlock)block;
- (void)shouldDisplayHeadingCalibrationWithBlock:(AWFShouldDisplayHeadingCalibrationBlock)block;
- (void)didDetermineStateWithBlock:(AWFDidDetermineStateBlock)block;
- (void)didRangeBeaconsWithBlock:(AWFDidRangeBeaconsBlock)block;
- (void)rangingBeaconsDidFailForRegionWithBlock:(AWFRangingBeaconsDidFailForRegionBlock)block;
- (void)didEnterRegionWithBlock:(AWFDidEnterRegionBlock)block;
- (void)didExitRegionWithBlock:(AWFDidExitRegionBlock)block;
- (void)didFailWithErrorWithBlock:(AWFDidFailWithErrorBlock)block;
- (void)monitoringDidFailForRegionWithBlock:(AWFMonitoringDidFailForRegionWithBlock)block;
- (void)didChangeAuthorizationStatusWithBlock:(AWFDidChangeAuthorizationStatusBlock)block;
- (void)didStartMonitoringForRegionWithBlock:(AWFDidStartMonitoringForRegionWithBlock)block;
- (void)locationManagerDidPauseLocationUpdatesWithBlock:(AWFLocationManagerDidPauseLocationUpdatesBlock)block;
- (void)locationManagerDidResumeLocationUpdatesWithBlock:(AWFLocationManagerDidResumeLocationUpdatesBlock)block;
- (void)didFinishDeferredUpdatesWithErrorWithBlock:(AWFDidFinishDeferredUpdatesWithErrorBlock)block;

@end
