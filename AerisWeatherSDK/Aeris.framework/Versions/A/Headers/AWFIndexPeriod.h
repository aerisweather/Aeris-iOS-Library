//
//  AWFIndexPeriod.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

typedef NS_ENUM (NSUInteger, AWFIndexType) {
	AWFIndexTypeUnknown = 0,
	AWFIndexTypeArthritis,
	AWFIndexTypeColdFlu,
	AWFIndexTypeMigraine,
	AWFIndexTypeSinus,
	AWFIndexTypeOutdoor
};

@class AWFIndex;

@interface AWFIndexPeriod : AWFGeographicObject

/**
 *  The current index item based on the latest observation for the location.
 */
@property (nonatomic, strong) AWFIndex *current;

/**
 *  An array of index items for periods in the future. This value will be `nil` by default. In order to obtain forecast indices, you must provide a
 *`toDate` with your request options.
 */
@property (nonatomic, strong) NSArray *forecast;

/**
 *  Minimum index value allowed for the index type.
 */
@property (nonatomic, strong) NSNumber *rangeMin;

/**
 *  Maximum index value allowed for the index type.
 */
@property (nonatomic, strong) NSNumber *rangeMax;

/**
 *  Index type this period pertains to.
 */
@property (nonatomic, assign) AWFIndexType indexType;

/**
 *  String representation of the index type.
 */
@property (nonatomic, copy) NSString *indexTypeString;

/**
 *  Whether or not the index range values are reversed.
 *
 *  By default, the index range is not reversed meaning that the lowest index value corresponds to the lowest risk or severity. When the range is
 *  reversed, the lowest index value corresponds to the greatest risk or severity.
 */
@property (nonatomic, assign) BOOL isReverse;

@end