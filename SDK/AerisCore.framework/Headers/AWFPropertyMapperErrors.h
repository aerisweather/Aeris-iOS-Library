//
//  AWFPropertyMapperErrors.h
//  Aeris-API-Library
//
//  Created by Nicholas Shipes on 3/23/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const kAWFPropertyMapperErrorDomain;

typedef NS_ENUM(NSUInteger, AWFPropertyMapperErrorCode) {
	AWFPropertyMapperErrorCodeUnknownProperty		= 60520,
	AWFPropertyMapperErrorCodeInvalidMapperFormat	= 60530,
	AWFPropertyMapperErrorCodeMapperNotFound		= 60540,
	AWFPropertyMapperErrorCodeValidationFailed		= 60550
};

extern NSString * const AWFPropertyMapperErrorDescription[];
