//
//  AWFCollectionViewDailySummaryCell.h
//  AerisUI
//
//  Created by Nicholas Shipes on 8/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AWFDailySummaryView;

@interface AWFCollectionViewDailySummaryCell : UICollectionViewCell

@property (readonly, nonatomic, strong) AWFDailySummaryView *weatherView;

@end