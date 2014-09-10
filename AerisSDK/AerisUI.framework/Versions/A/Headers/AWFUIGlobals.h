//
//  AWFUIGlobals.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/26/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AF_IMAGE(name) [UIImage imageNamed:[NSString stringWithFormat:@"AerisUI.bundle/images/%@", [name stringByReplacingOccurrencesOfString:@"gif" withString:@"png"]]]
#define AF_WXICON(name) [UIImage imageNamed:[NSString stringWithFormat:@"AerisUI.bundle/wxicons/%@", [name stringByReplacingOccurrencesOfString:@"gif" withString:@"png"]]]

#ifndef UIViewAutoresizingFlexibleSize
	#define UIViewAutoresizingFlexibleSize UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight
#endif

#ifndef UIViewAutoresizingFlexibleMargins
	#define UIViewAutoresizingFlexibleMargins UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin
#endif