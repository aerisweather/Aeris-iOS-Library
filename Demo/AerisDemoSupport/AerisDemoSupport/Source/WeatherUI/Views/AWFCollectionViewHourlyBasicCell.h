//
//  AWFCollectionViewHourlyBasicCell.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/28/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;

@class AWFHourlyBasicView;
@class AWFForecastPeriod;

@interface AWFCollectionViewHourlyBasicCell : UICollectionViewCell

@property (nonatomic, strong) AWFHourlyBasicView *weatherView;

+ (NSString *)defaultReuseIdentifier;
- (void)configureWithPeriod:(AWFForecastPeriod *)period;

@end
