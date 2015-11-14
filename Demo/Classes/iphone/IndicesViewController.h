//
//  IndicesViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "GroupedListingViewController.h"

@protocol OptionsViewControllerDelegate;

@interface IndicesViewController : GroupedListingViewController

@property (nonatomic, assign) AWFIndexType currentIndexType;

@end
