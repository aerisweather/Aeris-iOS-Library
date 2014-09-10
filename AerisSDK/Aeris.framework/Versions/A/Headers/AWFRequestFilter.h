//
//  AWFRequestFilter.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/12/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  `AWFRequestFilter` provides a convenience interface for using the supported filter options within a `AWFRequestOptions` instance. These
 *  filter objects are associated with filter names associated with each object loader.
 */
@interface AWFRequestFilter : NSObject

/**
 *  The name of the filter to use.
 */
@property (nonatomic, copy) NSString *name;

/**
 *  Initializes and returns a filter object for the specified filter name.
 *
 *  @param filterName The filter name/key to use for the filter.
 *
 *  @return The initialized filter object.
 */
+ (instancetype)filterWithName:(NSString *)filterName;

@end