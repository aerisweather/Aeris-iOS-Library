//
//  AWFAdvisoryDetailView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "AWFWeatherView.h"

@class AWFWeatherHeaderView;

@interface AWFAdvisoryDetailView : AWFWeatherView

@property (nonatomic, strong, readonly) UILabel *nameTextLabel;
@property (nonatomic, strong, readonly) UILabel *expiresTextLabel;
@property (nonatomic, strong, readonly) UILabel *bodyTextLabel;

@end
