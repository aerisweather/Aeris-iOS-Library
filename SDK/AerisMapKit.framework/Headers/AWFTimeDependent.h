//
//  AWFTimeDependent.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/12/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `AWFTimeDependent` protocol defines the properties and methods used by objects whose data is specific to a particular time and/or date.
 */
@protocol AWFTimeDependent <NSObject>

/**
 The date for the object.
 */
@property (nonatomic, strong) NSDate *date;

/**
 The time offset string relative to now (e.g. `-10minutes`, `+1hour`, etc).
 */
@property (nonatomic, strong) NSString *offset;

/**
 Updates the object and its data representation using the specified `date`.

 @param date The date to update the object with
 @param updateOffset Whether or not the object's offset should also be updated using the date
 */
- (void)updateForDateClosestToDate:(NSDate *)date updatingOffset:(BOOL)updateOffset;

@end

NS_ASSUME_NONNULL_END
