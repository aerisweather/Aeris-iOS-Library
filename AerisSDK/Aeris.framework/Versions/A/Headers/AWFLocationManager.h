//
//  AWFLocationManager.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/26/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreGraphics/CoreGraphics.h>

typedef NS_ENUM(NSUInteger, AWFUserTrackingMode) {
	AWFUserTrackingModeNone = 0,
	AWFUserTrackingModeFollow,
	AWFUserTrackingModeFollowWithHeading,
	AWFUserTrackingModeHeading,
	AWFUserTrackingModeSearching
};

typedef NS_ENUM(NSUInteger, AWFLocationAccuracy) {
	AWFLocationAccuracyNone = 0,
	AWFLocationAccuracyPoor,
	AWFLocationAccuracyGood,
	AWFLocationAccuracyBest
};

// notification keys
extern NSString * const AWFLocationManagerDidStartUpdatingHeading;
extern NSString * const AWFLocationManagerDidStartUpdatingServices;
extern NSString * const AWFLocationManagerDidStopUpdatingHeading;
extern NSString * const AWFLocationManagerDidStopUpdatingServices;
extern NSString * const AWFLocationManagerDidUpdateToLocationFromLocation;
extern NSString * const AWFLocationManagerDidUpdateHeading;
extern NSString * const AWFLocationManagerDidFailWithError;
extern NSString * const AWFLocationManagerDidUpdateAccuracy;

typedef void (^AWFLocationManagerCompletionHandler)(CLLocation *location, NSError *error, BOOL locationServicesDisabled);

@interface AWFLocationManager : NSObject <CLLocationManagerDelegate>

@property (readonly, nonatomic, strong) CLLocationManager *locationManger;
@property (nonatomic, strong) CLLocation *lastKnownLocation;
@property (nonatomic, strong) CLHeading *lastKnownHeading;
@property (nonatomic, readonly) BOOL locationServicesEnabled;
@property (nonatomic, assign) BOOL tracking;
@property (nonatomic, assign) BOOL allowInaccurateLocation;
@property (nonatomic, assign) enum AWFUserTrackingMode trackingMode;
@property (nonatomic) CLLocationDistance distanceFilter;
@property (nonatomic) CLLocationAccuracy desiredAccuracy;

@property (nonatomic, readonly) enum AWFLocationAccuracy locationAccuracy;
@property (nonatomic, readonly) CGFloat currentSpeed;
@property (nonatomic, readonly) CLLocationDistance totalDistance;
@property (nonatomic, readonly) NSTimeInterval totalSeconds;

- (void)prepareForLocationUpdates;
- (void)startAllServices;
- (void)stopAllServices;
- (void)invalidateLastKnownLocation;
- (BOOL)canPerformLocationActions:(BOOL)requireValidLocation;

+ (AWFLocationManager *)sharedManager;
+ (void)updateLocationWithCompletionHandler:(AWFLocationManagerCompletionHandler)completion;

@end
