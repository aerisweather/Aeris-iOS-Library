//
//  AWFWinterLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 4/5/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

/**
 *  `AWFWinterLoader` provides conveninece methods for interacting with the
 *  [`winter/snowdepth` endpoint](http://www.aerisweather.com/support/docs/api/reference/endpoints/winter/snowdepth) of the Aeris API. All requests will return
 *  instances of `AWFSnowDepth` that will be populated with the data returned from the API unless otherwise indicated.
 */
@interface AWFWinterLoader : AWFGeographicObjectLoader

- (void)getSnowDepthForPlace:(AWFPlace *)place
                     options:(AWFRequestOptions *)options
                  completion:(AWFObjectLoaderCompletionBlock)completionBlock;

- (void)getSnowDepthForPlace:(AWFPlace *)place
                    fromDate:(NSDate *)fromDate
                      toDate:(NSDate *)toDate
                     options:(AWFRequestOptions *)options
                  completion:(AWFObjectLoaderCompletionBlock)completionBlock;
@end