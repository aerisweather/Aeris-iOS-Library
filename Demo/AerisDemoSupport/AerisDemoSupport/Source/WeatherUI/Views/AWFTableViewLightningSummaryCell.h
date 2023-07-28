//
//  AWFTableViewLightningSummaryCell.h
//  AerisDemoSupport
//
//  Created by Slipp Douglas Thompson on 5/31/23.
//  Copyright © 2023 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class AWFLightningSummaryView;

@interface AWFTableViewLightningSummaryCell : UITableViewCell

@property (readonly, nonatomic, strong) AWFLightningSummaryView *weatherView;

@end
