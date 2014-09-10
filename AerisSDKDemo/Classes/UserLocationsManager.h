//
//  UserLocationsManager.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserLocationsManager : NSObject

@property (nonatomic, strong) NSArray *locations;

+ (UserLocationsManager *)sharedManager;

- (AWFPlace *)defaultLocation;
- (void)setDefaultLocation:(AWFPlace *)place;

- (void)saveLocation:(AWFPlace *)place;
- (void)removeLocation:(AWFPlace *)place;

- (BOOL)containsLocation:(AWFPlace *)place;

@end
