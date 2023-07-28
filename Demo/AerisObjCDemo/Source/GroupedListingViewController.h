//
//  GroupedListingViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisDemoSupport/AerisDemoSupport.h>
#import "ListingViewController.h"

@interface GroupedListingViewController : ListingViewController

- (void)loadDataForPlace:(AWFPlace *)place options:(AWFWeatherRequestOptions *)options;
- (NSString *)cellIdentifierForIndexPath:(NSIndexPath *)indexPath;

@end
