//
//  AWFDataLoading.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 11/14/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef void (^AWFDataLoadingCompletion)(void);

/**
 The `AWFDataLoading` protocol defines the required properties and methods for an object that performs the necessary data loading required for map
 elements.
 */
@protocol AWFDataLoading

/**
 A Boolean value that indicates whether the object is currently loading data.
 */
@property (nonatomic, readonly) BOOL isLoading;

/**
 Tells the object to load data for the specified coordinate.

 @param coord The coordinate to request data for.
 */
- (void)loadForCoordinate:(CLLocationCoordinate2D)coord;

/**
 Sets the block to be executed when the object has completed the data loading process.

 @param completionBlock The block to be executed on the completion or failure of a data loading process.
 */
- (void)setCompletionBlock:(AWFDataLoadingCompletion)completionBlock;

@end
