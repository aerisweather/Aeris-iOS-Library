//
//  AWFObservationAdvisoriesView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFWeatherView.h"

@interface AWFObservationAdvisoriesView : AWFWeatherView

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) NSArray *advisories;

@end
