//
//  AWFPointSource.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFMapContentSource.h>
#import <AerisMapKit/AWFAnimatableOverlay.h>
#import <AerisMapKit/AWFPointAnimation.h>
#import <AerisMapKit/AWFStylable.h>
#import <AerisMapKit/AWFMapGlobals.h>

@class AWFMapCoordinateBounds, AWFPointAnimation, AWFAnnotationStyle;
@class AWFLegendStyle;

/**
 An `AWFPointSource` object represents a map content source that manages a series of points on the map.
 */
@interface AWFPointSource : AWFMapContentSource <AWFStylable, AWFAnimatableOverlay, AWFPointAnimationDataSource>

/**
 The annotations being managed by the content source (readonly).
 */
@property (readonly, nonatomic, strong) NSArray *annotations;

/**
 The options to use when requesting data for the content source.
 */
@property (nonatomic, strong) AWFWeatherRequestOptions *requestOptions;

/**
 The request action to use when requesting data for the content source.
 */
@property (nonatomic, copy) NSString *requestAction;

/**
 The style to use when rendering annotations for this content source on the weather map.
 */
@property (nonatomic, strong) id style;

/**
 The legend style used when rendering data points for the content source.
 */
@property (nonatomic, strong) AWFLegendStyle *legendStyle;

/**
 The minimum distance, in points, between rendered points for the content source. Default is `0`, meaning all points will be rendered.
 */
@property (nonatomic, assign) CGFloat minimumInteritemDistance;

/**
 The animation object associated with the content source.
 */
@property (nonatomic, strong) AWFPointAnimation *animation;

/**
 Requests data for the content source within the region described by the specified coordinate bounds.
 
 @param bounds  The coordinate bounds to request data for
 @param results The completion block when the request finishes or fails
 */
- (void)loadForMapBounds:(AWFMapCoordinateBounds *)bounds results:(void (^)(NSArray *results, NSError *error))results;

/**
 Requests data for the content source within the region described the the specified coordinate bounds and the date range.
 
 @param bounds   The coordinate bounds to request data for
 @param fromDate The starting date to use for the request, or `nil` to use the current date and time
 @param toDate   The ending date to use for the request, or `nil` to use the current date and time
 @param results  The completion block when the requet finishes or fails
 */
- (void)loadForMapBounds:(AWFMapCoordinateBounds *)bounds fromDate:(NSDate *)fromDate toDate:(NSDate *)toDate results:(void (^)(NSArray *, NSError *))results;

/**
 Cancels any active requests and prepared for a new request.
 */
- (void)reset;

@end
