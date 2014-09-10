//
//  AFAccessPermissions.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/26/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AWFAccessPermissions : NSObject

typedef void (^AWFAccessPermissionsCompletionBlock)(AWFAccessPermissions *permissions, NSError *error);

+ (BOOL)permissionsHaveLoaded;
+ (void)getPermissionsWithCompletion:(AWFAccessPermissionsCompletionBlock)completionBlock;
+ (BOOL)hasAccessForCode:(NSString *)code;

@end
