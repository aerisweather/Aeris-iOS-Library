//
//  AerisCore.h
//  AerisCore
//
//  Created by Nicholas Shipes on 5/1/15.
//  Copyright (c) 2015 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for AerisCore.
FOUNDATION_EXPORT double AerisCoreVersionNumber;

//! Project version string for AerisCore.
FOUNDATION_EXPORT const unsigned char AerisCoreVersionString[];

#import <AerisCore/AWFGlobals.h>
#import <AerisCore/AWFCache.h>
#import <AerisCore/AWFMemoryCache.h>
#import <AerisCore/AWFDiskCache.h>
#import <AerisCore/AWFNullCache.h>
#import <AerisCore/AWFURLCache.h>
#import <AerisCore/AWFLogger.h>
#import <AerisCore/AWFMath.h>
#import <AerisCore/AWFNetworkActivityIndicatorManager.h>
#import <AerisCore/AWFKVOController.h>

#import <AerisCore/AWFURLSessionManager.h>
#import <AerisCore/AWFURLSessionTaskDelegate.h>

#import <AerisCore/AWFRequest.h>
#import <AerisCore/AWFResponse.h>
#import <AerisCore/AWFRequestMetrics.h>
#import <AerisCore/AWFApiClient.h>
#import <AerisCore/AWFOAuthApiClient.h>
#import <AerisCore/AWFOAuthCredential.h>
#import <AerisCore/AWFApiEndpoint.h>
#import <AerisCore/AWFApiEndpoint+Private.h>
#import <AerisCore/AWFWritableApiEndpoint.h>
#import <AerisCore/AWFApiObject.h>
#import <AerisCore/AWFApiRequestOptions.h>
#import <AerisCore/AWFApiResponse.h>

#import <AerisCore/AWFPropertyMapper.h>
#import <AerisCore/AWFPropertyDescriptor.h>
#import <AerisCore/AWFPropertyMapperErrors.h>
#import <AerisCore/AWFPropertyMappingOperation.h>
#import <AerisCore/AWFPropertyDescriptor+Validators.h>

#import <AerisCore/CLLocation+AerisCore.h>
#import <AerisCore/CLLocationManager+AerisCore.h>
#import <AerisCore/NSArray+AerisCore.h>
#import <AerisCore/NSBundle+AerisCore.h>
#import <AerisCore/NSCachedURLResponse+AerisCore.h>
#import <AerisCore/NSDate+AerisCore.h>
#import <AerisCore/NSDictionary+AerisCore.h>
#import <AerisCore/NSNumber+AerisCore.h>
#import <AerisCore/NSObject+AerisCore.h>
#import <AerisCore/NSObject+AWFAutoCoding.h>
#import <AerisCore/NSObject+AWFPropertyMapper.h>
#import <AerisCore/NSSet+AerisCore.h>
#import <AerisCore/NSString+AerisCore.h>
#import <AerisCore/NSTimeZone+AerisCore.h>
