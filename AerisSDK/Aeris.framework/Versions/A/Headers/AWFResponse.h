//
//  AWFResponse.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/4/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

/**
 *  An `AWFResponse` object handles the JSON dictionary object returned from the API and performs validation to check for errors and whether or not the
 *  response was successful.
 */
@interface AWFResponse : NSObject

/**
 *  The response object returned by the API.
 */
@property (nonatomic, strong) id response;

/**
 *  The error returned by the API.
 */
@property (nonatomic, strong) NSError *error;

/**
 *  Whether the API request was successful and an error did not occur.
 */
@property (readonly, nonatomic) BOOL isSuccessful;

/**
 *  Creates and returns a new `AWFResponse` instance initialized with the specified dictionary object. The provided dictionary should be the JSON object
 *  returned from the API request.
 *
 *  @param dictionary The dictionary object to use with the response
 *
 *  @return The initialized response instance
 */
- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end
