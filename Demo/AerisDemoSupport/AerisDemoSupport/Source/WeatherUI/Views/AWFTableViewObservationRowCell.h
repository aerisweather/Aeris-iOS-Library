//
//  AWFCollectionViewObservationRowCell.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AerisDemoSupport/AWFStyledView.h>

@class AWFStyledHeaderView;

@interface AWFTableViewObservationRowCell : UITableViewCell <AWFStylableView>

@property (nonatomic, strong) AWFStyledHeaderView *headerView;
@property (nonatomic, strong) UILabel *weatherTextLabel;
@property (nonatomic, strong) UILabel *tempTextLabel;
@property (nonatomic, strong) UIImageView *iconImageView;

@end
