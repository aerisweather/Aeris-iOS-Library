//
//  AWFObservationCalloutContentView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AerisUI.h>

@interface AWFObservationCalloutContentView : AWFCalloutContentView

@property (readonly, nonatomic, strong) UILabel *tempLabel;
@property (readonly, nonatomic, strong) UIImageView *iconView;
@property (nonatomic, assign) BOOL hasData;

@end
