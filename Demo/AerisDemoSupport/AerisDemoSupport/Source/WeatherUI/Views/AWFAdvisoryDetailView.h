//
//  AWFAdvisoryDetailView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisDemoSupport/AWFStyledView.h>

@class AWFStyledHeaderView;

@interface AWFAdvisoryDetailView : AWFStyledView

@property (nonatomic, strong) AWFStyledHeaderView *headerView;
@property (nonatomic, strong, readonly) UILabel *nameTextLabel;
@property (nonatomic, strong, readonly) UILabel *expiresTextLabel;
@property (nonatomic, strong, readonly) UILabel *bodyTextLabel;

@end
