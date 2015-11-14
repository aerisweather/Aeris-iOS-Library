//
//  AWFRequestQuery.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/12/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFRequestOptions.h>

/**
 *  `AWFRequestQuery` provides a convenience wrapper for setting up request queries to be used with an `AWFRequestOptions` instance.
 */
@interface AWFRequestQuery : NSObject

/**
 *  The property name to perform the query against.
 */
@property (nonatomic, copy) NSString *propertyName;

/**
 *  The value of `propertyName` to match for the query.
 */
@property (nonatomic, strong) id value;

/**
 *  Determines how this query should be joined with any query that may exist before within an `AWFRequestOptions` instance.
 *  @see AWFRequestOperator
 */
@property (nonatomic, assign) AWFRequestOperator requestOperator;

/**
 *  Initializes and returns a query object for the specified property name, value and joining operation type.
 *
 *  @param propertyName    The property name to perform the query against.
 *  @param value           The value of the property to match.
 *  @param requestOperator The joining operation to use when this query is combined with other queries.
 *
 *  @return The initialized query object.
 */
+ (instancetype)queryForProperty:(NSString *)propertyName withValue:(id)value usingOperator:(AWFRequestOperator)requestOperator;

/**
 *  Returns a string representation of this query object, e.g. `property=value`.
 */
- (NSString *)stringRepresentation;

@end