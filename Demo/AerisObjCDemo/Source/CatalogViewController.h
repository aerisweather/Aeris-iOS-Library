//
//  CatalogViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CatalogViewControllerDelegate;

@interface CatalogViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) UIViewController *masterViewController;
@property (nonatomic, unsafe_unretained) id<CatalogViewControllerDelegate> delegate;

@end


@protocol CatalogViewControllerDelegate <NSObject>
@optional

- (void)catalogViewControllerDidSelectDetailItem:(CatalogViewController *)cvc;

@end
