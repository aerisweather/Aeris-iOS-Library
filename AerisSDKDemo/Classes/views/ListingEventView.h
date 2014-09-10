//
//  LoadingStatusView.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ListingEventView : UIView

@property (readonly, nonatomic, strong) UILabel *messageLabel;
@property (readonly, nonatomic, strong) UILabel *detailedMessageLabel;

- (void)showLoading;
- (void)showNoResultsMessage;
- (void)showMessage:(NSString *)message;
- (void)showMessage:(NSString *)message withDetailedMessage:(NSString *)detailedMessage;
- (void)hide;

@end
