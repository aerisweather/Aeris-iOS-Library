//
//  AWFTableViewDailySummaryCell.h
//  AerisUI
//
//  Created by Nicholas Shipes on 8/21/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;

@class AWFDailySummaryView;

@interface AWFTableViewDailySummaryCell : UITableViewCell

@property (readonly, nonatomic, strong) AWFDailySummaryView *weatherView;

@end
