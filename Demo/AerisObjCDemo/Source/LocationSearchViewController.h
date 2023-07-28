//
//  LocationSearchViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisDemoSupport/AerisDemoSupport.h>

extern NSString * const kAWFDemoDefaultPlaceChanged;

@interface LocationSearchViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UISearchBarDelegate, UISearchDisplayDelegate>

@end
