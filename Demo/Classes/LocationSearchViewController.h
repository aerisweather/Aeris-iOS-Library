//
//  LocationSearchViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString * const kAWFDemoDefaultPlaceChanged;

@interface LocationSearchViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UISearchBarDelegate, UISearchDisplayDelegate>

@end
