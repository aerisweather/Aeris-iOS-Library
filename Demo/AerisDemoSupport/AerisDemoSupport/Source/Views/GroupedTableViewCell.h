//
//  GroupedTableViewCell.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface GroupedTableViewCell : UITableViewCell

@property (nonatomic, strong, readonly) UILabel *titleLabel;
@property (nonatomic, strong, readonly) UILabel *valueLabel;

@end
