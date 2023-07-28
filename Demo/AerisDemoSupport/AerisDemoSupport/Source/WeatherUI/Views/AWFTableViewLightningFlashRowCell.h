//
//  LightningFlashRowCell.h
//  AerisDemoSupport
//
//  Created by Slipp Douglas Thompson on 5/24/23.
//  Copyright © 2023 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AerisDemoSupport/AWFStyledView.h>

@class AWFStyledHeaderView;

@interface AWFTableViewLightningFlashRowCell : UITableViewCell <AWFStylableView>

@property (nonatomic, strong) AWFStyledHeaderView *headerView;
@property (nonatomic, strong) UILabel *locationLabel;
@property (nonatomic, strong) UILabel *locationDetailLabel;

@end
