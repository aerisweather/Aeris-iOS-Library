//
//  AWFWeatherHeaderView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFStyledView.h"

@interface AWFWeatherHeaderView : AWFStyledView

@property (nonatomic, strong) UILabel *textLabel;
@property (nonatomic, strong) UILabel *detailTextLabel;
@property (nonatomic, assign) AWFLayout layout;

@end