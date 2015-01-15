//
//  AWFThreatsLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

@interface AWFThreatsLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

- (void)getThreatsForPlace:(AWFPlace *)place
				   options:(AWFRequestOptions *)options
				completion:(AWFObjectLoaderCompletionBlock)completionBlock;

@end
