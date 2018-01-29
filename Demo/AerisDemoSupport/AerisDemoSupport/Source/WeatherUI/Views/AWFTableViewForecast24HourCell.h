//
//  AWFCollectionViewForecast24HourCell.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisDemoSupport/AWFStyledView.h>

@class AWFForecastDetailView;

@interface AWFTableViewForecast24HourCell : UITableViewCell <AWFStylableView>

@property (nonatomic, strong) UILabel *periodLabel;
@property (nonatomic, strong) UILabel *dateLabel;

/**
 The `AWFForecastDetailView` instance for the first period.
 */
@property (nonatomic, strong, readonly) AWFForecastDetailView *firstPeriodView;

/**
 The `AWFForecastDetailView` instance for the second period.
 */
@property (nonatomic, strong, readonly) AWFForecastDetailView *secondPeriodView;

@end
