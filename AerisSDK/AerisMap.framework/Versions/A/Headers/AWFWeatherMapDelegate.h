//
//  AFWeatherMapDelegate.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AWFLayerType.h"

@class AWFWeatherMap;

/**
 *  The `AWFWeatherMapDelegate` protocol defines a set of optional methods that you can use to receive messages related
 *	to updates or changes to the weather map.
 *
 *	This protocol does not receive the standard map view delegate messages that are provided with the specific mapping SDK the 
 *	associated weather map uses (e.g., `MKMapViewDelegate` for Apple's MapKit). To receive these messages specific to the
 *	selected mapping SDK, assign your delegate to the {@link AWFWeatherMap#mapViewDelegate mapViewDelegate} property on 
 *	your `AWFWeatherMap` instance.
 */
@protocol AWFWeatherMapDelegate <NSObject>
@optional

//------------------------
// @name Responding to Overlay Changes
//------------------------

/**
 *  Tells the delegate an layer type was added to the map.
 *
 *  @param weatherMap  The weather map that added the layer type.
 *  @param layerType The {@link AWFLayerType} that was added to the map.
 */
- (void)weatherMap:(AWFWeatherMap *)weatherMap didAddLayerType:(AWFLayerType)layerType;

/**
 *  Tells the delegate an layer type was removed from the map.
 *
 *  @param weatherMap  The weather map that removed the layer type.
 *  @param layerType The {@link AWFLayerType} that was removed from the map.
 */
- (void)weatherMap:(AWFWeatherMap *)weatherMap didRemoveLayerType:(AWFLayerType)layerType;

/**
 *  Tells the delegate the timeline range changed.
 *
 *  @param weatherMap The weather map whose timeline was changed
 *  @param fromDate   The start date of the timeline
 *  @param toDate     The end date of the timeline
 */
- (void)weatherMap:(AWFWeatherMap *)weatherMap didUpdateTimelineRangeFromDate:(NSDate *)fromDate toDate:(NSDate *)toDate;

//------------------------
// @name Responding to Animations
//------------------------

/**
 *  Tells the delegate that the weather map started animating active overlay.
 *
 *  @param weatherMap The weather map that started animating.
 */
- (void)weatherMapDidStartAnimating:(AWFWeatherMap *)weatherMap;

/**
 *  Tells the delegate that the weather map stopped animating active overlays.
 *
 *  @param weatherMap The weather map that stopped animating.
 */
- (void)weatherMapDidStopAnimating:(AWFWeatherMap *)weatherMap;
- (void)weatherMapDidResetAnimation:(AWFWeatherMap *)weatherMap;

/**
 *  Tells the delegate that the weather map did update its animation to the specified date.
 *
 *  @param weatherMap The weather map whose animation updated.
 *  @param date       The date to which the animation updated.
 */
- (void)weatherMap:(AWFWeatherMap *)weatherMap animationDidUpdateToDate:(NSDate *)date;

/**
 *  Tells the delegate the weather map started loading data required for the animation.
 *
 *  @param weatherMap The weather map that started loading data.
 */
- (void)weatherMapDidStartLoadingAnimationData:(AWFWeatherMap *)weatherMap;

/**
 *  Tells the delegate the weather map finished loading all data required for the animation.
 *
 *  @param weatherMap The weather map that finished loading data.
 */
- (void)weatherMapDidFinishLoadingAnimationData:(AWFWeatherMap *)weatherMap;

/**
 *  Tells the delegate the weather map cancelled loading data required for the animation.
 *
 *  @param weatherMap The weather map that cancelled loading data
 */
- (void)weatherMapDidCancelLoadingAnimationData:(AWFWeatherMap *)weatherMap;

/**
 *  Tells the delegate that the loading process for the weather map's animation was updated.
 *
 *  @param weatherMap  The weather map whose loading process changed.
 *  @param totalLoaded The total number of data requests that have completed.
 *  @param total       The total number of data requests required for the animation.
 */
- (void)weatherMap:(AWFWeatherMap *)weatherMap didUpdateAnimationDataLoadingProgress:(NSInteger)totalLoaded total:(NSInteger)total;

//-----------------------------------------------------------------------------
// @name Responding to Gestures
//-----------------------------------------------------------------------------

- (void)weatherMap:(AWFWeatherMap *)weatherMap didStartLongPressGestureAtCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)weatherMap:(AWFWeatherMap *)weatherMap didReceiveLongPressGestureAtCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)weatherMapDidCancelLongPressGesture:(AWFWeatherMap *)weatherMap;
- (void)weatherMap:(AWFWeatherMap *)weatherMap didTapPolygon:(id<AWFPolygon>)polygon atCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)weatherMap:(AWFWeatherMap *)weatherMap willPresentCalloutView:(AWFCalloutView *)calloutView forAnnotation:(id)annotation;
- (void)weatherMap:(AWFWeatherMap *)weatherMap didPresentCalloutView:(AWFCalloutView *)calloutView forAnnotation:(id)annotation;
- (void)weatherMap:(AWFWeatherMap *)weatherMap willDismissCalloutView:(AWFCalloutView *)calloutView forAnnotation:(id)annotation;
- (void)weatherMap:(AWFWeatherMap *)weatherMap didDismissCalloutView:(AWFCalloutView *)calloutView forAnnotation:(id)annotation;
- (void)weatherMap:(AWFWeatherMap *)weatherMap calloutAccessoryControlTapped:(UIControl *)control;

@end


@protocol AWFWeatherMapDataSource <NSObject>
@optional

- (UIView *)weatherMap:(AWFWeatherMap *)weatherMap calloutViewForAnnotation:(id<MKAnnotation>)annotation;

@end
