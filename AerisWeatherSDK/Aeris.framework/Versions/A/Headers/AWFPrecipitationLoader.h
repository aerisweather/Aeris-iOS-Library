//
//  AWFPrecipitationLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 4/5/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

/**
 *  `AWFPrecipitationLoader` provides conveninece methods for interacting with the
 *  [`precip` endpoint](http://www.aerisweather.com/support/docs/api/reference/endpoints/precip) of the Aeris API. All requests will return
 *  instances of `AWFPrecipitationPeriod` that will be populated with the data returned from the API unless otherwise indicated.
 */
@interface AWFPrecipitationLoader : AWFGeographicObjectLoader

- (void)getEstimateForPlace:(AWFPlace *)place
					options:(AWFRequestOptions *)options
				 completion:(AWFObjectLoaderCompletionBlock)completionBlock;

- (void)getEstimatesForPlace:(AWFPlace *)place
					fromDate:(NSDate *)fromDate
					  toDate:(NSDate *)toDate
					 options:(AWFRequestOptions *)options
				  completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end
