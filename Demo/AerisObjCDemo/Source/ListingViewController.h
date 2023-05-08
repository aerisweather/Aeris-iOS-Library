//
//  CommonTableViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ListingEventView;

@interface ListingViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>

@property (readonly, nonatomic, strong) AWFWeatherEndpoint *endpoint;
@property (nonatomic, strong) AWFPlace *place;
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *results;
@property (nonatomic, strong) ListingEventView *eventView;

- (void)loadDataClosestToPlace:(AWFPlace *)place radius:(NSString *)radius options:(AWFWeatherRequestOptions *)options;

- (void)handleConfigurationOfCell:(UITableViewCell *)cell forIndexPath:(NSIndexPath *)indexPath;
- (void)handleCellSelectionForIndexPath:(NSIndexPath *)indexPath;
- (void)dataDidFinishLoading;

@end
